#include<bits/stdc++.h>
using namespace std;
vector<int> a;
int ans=0,n,t=0,o=0;
char s[7];
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n*2;i++){
		scanf("%s",s);
		if(s[0]=='a'){
			int v;
			scanf("%d",&v);
			a.push_back(v);
		}else{
			if(t<a.size()){
				if(a.back()==o+1){a.pop_back();o++;continue;}
				ans++;
				t=a.size();
			}
			t--;
			a.pop_back();
			o++;
		}
	}
	printf("%d",ans);
	return 0;
}
