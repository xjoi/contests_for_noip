#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
struct data {
	int u,v,w;
}e[600006];
int fa[10001],ra[10001];
int n,m,p;
bool cmp1(data p,data q) {
	if (p.w==q.w) return p.u<q.u;
	return p.w<q.w;
}
bool cmp2(data p,data q) {
	return p.u<q.u;
}
int getf(int x) {
	if (fa[x]==x) return x;
	fa[x]=getf(fa[x]);
	return fa[x];
}
void kruskal() {
	for (int i=0;i<n;i++) {
		fa[i]=i;
		ra[i]=1;
	}
	int nowans=n*(n-1);
	for (int i=1;i<=m+p;i++) {
		if (e[i].u<0) {
			e[i].v=nowans;
			continue;
		}
		int fu=getf(e[i].u),fv=getf(e[i].v);
		if (fu!=fv) {
			fa[fu]=fv;
			nowans-=ra[fu]*ra[fv]*2;
			ra[fv]+=ra[fu];
		}
	}
}
int main() {
	while (scanf("%d%d",&n,&m)!=-1) {
		for (int i=1;i<=m;i++) scanf("%d%d%d",&e[i].u,&e[i].v,&e[i].w);
		scanf("%d",&p);
		for (int i=1;i<=p;i++) {
			e[m+i].u=-i;
			scanf("%d",&e[m+i].w);
		}
		sort(e+1,e+m+p+1,cmp1);
		kruskal();
		sort(e+1,e+m+p+1,cmp2);
		for (int i=p;i>=1;i--) printf("%d\n",e[i].v);
	}
	return 0;
}
