#include<cstdio>
#include<set>
#include<algorithm>
using namespace std;
int n,p;
set<int>st;
struct node{
	int x,pos;
}a[500000];
bool cmp(node a,node b){
	return a.x<b.x;
}
bool cmp2(node a,node b){
	return a.pos<b.pos;
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i].x);
	    a[i].pos=i;
	}	
	sort(a+1,a+n+1,cmp);
	for(int i=1;i<=n;i++){
		a[i].x=max(p+1,a[i].x);
		while(st.count(a[i].x))a[i].x++;
		p=a[i].x;
		st.insert(a[i].x);
	}
	sort(a+1,a+n+1,cmp2);
	for(int i=1;i<=n;i++)printf("%d ",a[i].x);
}
