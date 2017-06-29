#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
const int N=200005;
int n,m,x,y,S,D,e;
int a[N],ed[N],next[N],son[N],l[N],r[N],L[N],R[N],k[N],id[N],v[N],c[N],s[N],ans[N];
void dfs(int x,int fa)
{
	v[L[x]=++D]=a[x];
	for (int p=son[x];p!=0;p=next[p])
	if (ed[p]!=fa) dfs(ed[p],x);
	R[x]=D;
}
bool cmp(const int i,const int j)
{
	return l[i]/S==l[j]/S?(l[i]/S&1)?r[i]<r[j]:r[i]>r[j]:l[i]<l[j];
}
int main()
{
	scanf("%d%d",&n,&m);
	S=int(sqrt(n+0.0));
	for (int i=1;i<=n;++i)
	scanf("%d",&a[i]);
	for (int i=1;i<=n-1;++i)
	{
		scanf("%d%d",&x,&y);
		ed[++e]=y;
		next[e]=son[x];
		son[x]=e;
		ed[++e]=x;
		next[e]=son[y];
		son[y]=e;
	}
	dfs(1,-1);
	for (int i=1;i<=m;++i)
	{
		scanf("%d%d",&x,&y);
		l[i]=L[x];
		r[i]=R[x];
		k[i]=y;
		id[i]=i;
	}
	sort(id+1,id+m+1,cmp);
	int left=1,right=0;
	for (int j=1;j<=m;++j)
	{
		int i=id[j];
		while (left>l[i]) ++c[++s[v[--left]]];
		while (right<r[i]) ++c[++s[v[++right]]];
		while (left<l[i]) --c[s[v[left++]]--];
		while (right>r[i])  --c[s[v[right--]]--];
		ans[i]=c[k[i]];
	}
	for (int i=1;i<=m;++i)
	printf("%d\n",ans[i]);
	return 0;
}
