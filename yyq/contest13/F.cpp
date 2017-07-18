#include<bits/stdc++.h>
using namespace std;
const int maxn=200005;
int n,m,block,num=0,co,k;
int c[maxn],color[maxn],sum[maxn],l[maxn],r[maxn],res[maxn],cnt[maxn];
vector<int> G[maxn];
struct Query{
	int l,r,k,id;
}q[maxn];
void dfs(int x,int v)
{
	color[++num]=c[x];
	l[x]=num;
	for(int i=0;i<G[x].size();i++)
		if(G[x][i]!=v)
			dfs(G[x][i],x);
	r[x]=num;
}
bool cmp(Query a,Query b)
{
	return a.l/block==b.l/block?a.r<b.r:a.l/block<b.l/block;
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%d",&c[i]);
	for(int i=1;i<=n-1;i++)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		G[u].push_back(v);
		G[v].push_back(u);
	}
	dfs(1,-1);
	block=sqrt(1.0*n);
	for(int i=1;i<=m;i++)
	{
		scanf("%d%d",&co,&k);
		q[i].id=i;
		q[i].k=k;
		q[i].l=l[co];
		q[i].r=r[co];
	}
	sort(q+1,q+m+1,cmp);
	int pl=1,pr=0;
	int id;
	for(int i=1;i<=m;i++)
	{
		int j;
		id=q[i].id;
		if(q[i].l==q[i].r)
		{
			res[id]=q[i].k>1?0:1;
			continue;
		}
		if(pr<q[i].r)
			for(j=pr+1;j<=q[i].r;j++)
				sum[++cnt[color[j]]]++;
		else
			for(j=pr;j>q[i].r;j--)
				sum[cnt[color[j]]--]--;
		pr=q[i].r;
		if(pl<q[i].l)
			for(j=pl;j<q[i].l;j++)
				sum[cnt[color[j]]--]--;
		else
			for(j=pl-1;j>=q[i].l;j--)
				sum[++cnt[color[j]]]++;
		pl=q[i].l;
		res[id]=sum[q[i].k];
	}
	for(int i=1;i<=m;i++)
		printf("%d\n",res[i]);
	return 0;
}
