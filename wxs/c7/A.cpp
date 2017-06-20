#include<bits/stdc++.h>
using namespace std;
int n,m,k;
int a[100005],b[100005],c[30],d[100005];
bool judge(int v){
	memset(c,0,sizeof c);
	for(int i=1;i<=m;i++)c[a[i+v-1]]=1;
	for(int i=2;i<=29;i++)c[i]+=c[i-1];
	for(int i=1;i<=m;i++)d[i]=c[a[i+v-1]];
	for(int i=1;i<=m;i++)if(b[i]!=d[i])return 0;
	return 1;
}
int main(){
	while(scanf("%d%d%d",&n,&m,&k)!=EOF){
		for(int i=1;i<=n;i++){
			scanf("%d",&a[i]);
		}
		memset(c,0,sizeof c);
		for(int i=1;i<=m;i++){
			scanf("%d",&b[i]);
			c[b[i]]=1;
		}
		for(int i=2;i<=29;i++)c[i]+=c[i-1];
		for(int i=1;i<=m;i++){
			b[i]=c[b[i]];
		}
		int ans=0;
		for(int i=1;i<=n-m+1;i++){
			if(judge(i)){
				ans+=1;
				i+=m-1;
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}
