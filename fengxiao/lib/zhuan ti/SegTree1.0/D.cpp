#include<cstdio>
#include<cstring>
#define N 400010
#define M 10000000
using namespace std;
int v[N<<2],lc[N<<2],rc[N<<2],root=1,cnt=1,ans=0;
bool used[N>>2];
void clear() {memset(lc,0,sizeof(lc)); memset(rc,0,sizeof(rc)); memset(v,0,sizeof(v)); memset(used,0,sizeof(used)); used[0]=1; ans=0; cnt=1;}
/*void test(int u)
{
	printf("%d %d %d\n",s[u],e[u],v[u]);
	if(s[u]==e[u]) return;
	test(u<<1); test(u<<1|1);
}*/
void pd(int u)
{
	if(v[u])
	{
		v[lc[u]]=v[u];
		v[rc[u]]=v[u];
		v[u]=0;
	}
	return;
}
void update(int u,int l,int r,int x,int y,int c)
{
	if(x<=l && r<=y) {v[u]=c; return;}
	if(lc[u]==0) lc[u]=++cnt; if(rc[u]==0) rc[u]=++cnt;
	pd(u);
	int mid=(l+r)/2;
	if(mid>=x) update(lc[u],l,mid,x,y,c);
	if(mid< y) update(rc[u],mid+1,r,x,y,c);
}
void query(int u,int l,int r)
{
	if(lc[u]==rc[u] && lc[u]==0) {if(!used[v[u]]) {used[v[u]]=1; ans++;} return;}
	pd(u);
	int mid=(l+r)/2;
	if(lc[u]!=0) query(lc[u],l,mid);
	if(rc[u]!=0) query(rc[u],mid+1,r);
}
int main()
{
	int n,x,y,T;
	scanf("%d",&T);
	while(T--)
	{
		clear();
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
		{
			scanf("%d %d",&x,&y);
			update(root,1,M,x,y,i);
		}
		query(root,1,M);
		//test(1);
		printf("%d\n",ans);
	}
	return 0;
}
