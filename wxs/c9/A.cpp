#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,k;
int fa[1000000],a[1000000],h[1000000];
int ml[1000000],mr[1000000],mv[1000000];
main(){
	scanf("%lld%lld%lld",&n,&m,&k);
	for(int i=1;i<=n;i++){
		scanf("%lld",&h[i]);
	}
	for(int i=1;i<=m;i++){
		scanf("%lld%lld%lld",&ml[i],&mr[i],&mv[i]);
	}
	for(int i=1;i<=k;i++){
		int x,y;
		scanf("%lld%lld",&x,&y);
		a[x]+=1;a[y+1]-=1;
	}
	int u=0;
	for(int i=1;i<=m;i++){
		u+=a[i];
		fa[ml[i]]+=u*mv[i];
		fa[mr[i]+1]-=u*mv[i]; 
	}
	u=0;
	for(int i=1;i<=n;i++){
		u+=fa[i];
		printf("%lld ",u+h[i]);
	}
	return 0;
}
