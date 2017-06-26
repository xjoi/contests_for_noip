#include<bits/stdc++.h>
#define reutrn return
using namespace std;
int n,k,s,t,v,tot=0;
char z;
struct Node{
	int v,f,ans;
	Node(int q=0,int w=0,int e=0):v(q),f(w),ans(e){}
};
map<int,Node> c;
set<int> S;
set<int>::iterator it;
int main(){
	scanf("%d%d",&n,&k);
	for(int i=1;i<=k;i++){
		scanf("%d%*d",&s);
		cin>>z;
		if(S.count(s)){
			puts("0");
			continue;
		}
		if(z=='U'){
			if((it=S.upper_bound(s))==S.end()){
				c[s]=Node(s,1,n-s+1);
				S.insert(s);
				printf("%d\n",n-s+1);
			}else{
				if(c[*it].f==1){
					c[s]=Node(s,1,c[*it].ans+(*it)-s);
					S.insert(s);
					printf("%d\n",c[*it].ans+(*it)-s);
				}else{
					c[s]=Node(s,1,(*it)-s);
					S.insert(s);
					printf("%d\n",(*it)-s);
				}
			}
		}else{
			it=S.lower_bound(s);
			if(it==S.begin()){
				c[s]=Node(s,0,s);
				S.insert(s);
				printf("%d\n",s);
			}else{
				--it;
				if(c[*it].f==1){
					c[s]=Node(s,0,s-(*it));
					S.insert(s);
					printf("%d\n",s-(*it));
				}else{
					c[s]=Node(s,0,s-(*it)+c[*it].ans);
					S.insert(s);
					printf("%d\n",s-(*it)+c[*it].ans);
				}
			}
		}
	}
	return 0;
}
