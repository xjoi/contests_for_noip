#include<cstdio>
#include<cstring>
#define N 100010
using namespace std;
int s[N<<2],e[N<<2],v[N<<2],ans=0;
void clear(){memset(s,0,sizeof(s)); memset(e,0,sizeof(e)); memset(v,0,sizeof(v)); ans=0;}
/*void test(int u)
{
	printf("%d %d %d\n",s[u],e[u],v[u]);
	if(s[u]==e[u]) return;
	test(u<<1); test(u<<1|1);
}*/
void build_tre(int u,int l,int r)
{
	s[u]=l,e[u]=r;
	if(l==r) {v[u]=1; return;}
	int mid=(l+r)/2;
	build_tre(u<<1,l,mid);
	build_tre(u<<1|1,mid+1,r);
}
void pd(int u)
{
	if(v[u])
	{
		v[u<<1]=v[u];
		v[u<<1|1]=v[u];
		v[u]=0;
	}
	return;
}
void update(int u,int x,int y,int c)
{
	if(s[u]>y || e[u]<x) return;
	if(x<=s[u] && e[u]<=y) {v[u]=c; return;}
	pd(u);
	update(u<<1,x,y,c);
	update(u<<1|1,x,y,c);
}
void query(int u)
{
	if(s[u]==e[u]) {ans+=v[u]; return;}
	pd(u);
	query(u<<1); query(u<<1|1);
}
int main()
{
	int n,m,x,y,c,T;
	scanf("%d",&T);
	for(int t=1;t<=T;t++)
	{
		clear();
		scanf("%d",&n);
		build_tre(1,1,n);
		scanf("%d",&m);
		for(int i=1;i<=m;i++)
		{
			scanf("%d %d %d",&x,&y,&c);
			update(1,x,y,c);
		}
		query(1);
		//test(1);
		printf("Case %d: The total value of the hook is %d.\n",t,ans);
	}
	return 0;
}
