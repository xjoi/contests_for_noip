#include<cstdio>
#include<cstring>
#define N 50010
#define mem(a) memset(a,0,sizeof(a))
#define Mid(a,b) (a+b)>>1
#define left u<<1,ll,rr
#define right u<<1|1,ll,rr
using namespace std;
int l[N],r[N],cnt=0,root=0;
int s[N<<2],e[N<<2],v[N<<2];
int head[N],nxt[N<<1],to[N<<1],lst=0;
int n,m;
bool used[N]; char ch[10];
inline void clear() {mem(used); mem(s); mem(e); mem(l); mem(r); mem(v); mem(head); mem(nxt); mem(to); root=lst=cnt=0;}
inline void adde(int x,int y) {nxt[++lst]=head[x]; to[lst]=y; head[x]=lst;}
void dfs(int u,int from)
{
	l[u]=++cnt;
	for(int i=head[u]; i ; i=nxt[i]) if(to[i]!=from) dfs(to[i],u);
	r[u]=cnt;
}
void build_tre(int u,int ll,int rr)
{
	s[u]=ll; e[u]=rr; v[u]=-1;
	if(ll==rr) return;
	int mid=Mid(ll,rr);
	build_tre(u<<1,ll,mid); build_tre(u<<1|1,mid+1,rr);
}
void pd(int u)
{
	if(v[u]>0)
	{
		v[u<<1]=v[u];
		v[u<<1|1]=v[u];
		v[u]=0;
	}
}
void update(int u,int ll,int rr,int c)
{
	if(ll<=s[u] && e[u]<=rr) {v[u]=c; return;}
	pd(u);
	int mid=Mid(s[u],e[u]);
	if(mid>=ll) update(left,c);
	if(mid< rr) update(right,c);
}
int query(int u,int ll,int rr)
{
	if(s[u]==e[u] && s[u]==ll) return v[u];
	pd(u);
	int mid=Mid(s[u],e[u]);
	if(mid>=ll) return query(left);
	if(mid< rr) return query(right);
	return -2;
}
int main()
{
	int T,i,x,y;
	scanf("%d",&T);
	for(int t=1;t<=T;t++)
	{
		clear();
		printf("Case #%d:\n",t);
		scanf("%d",&n);
		for(i=1;i<n;i++)
		{
			scanf("%d %d",&x,&y);
			adde(y,x); used[x]=1;
		}
		for(i=1;i<=n;i++) if(!used[i]) {root=i; break;}
		dfs(root,0);//get l,r
		//for(i=1;i<=n;i++) printf("%d %d\n",l[i],r[i]);
		build_tre(1,1,n);//get s,e init v
		scanf("%d",&m);
		for(i=1;i<=m;i++)
		{
			scanf("%s",ch);
			if(ch[0]=='C')
			{
				scanf("%d",&x);
				printf("%d\n",query(1,l[x],l[x]));
				//for(i=1;i<=9;i++) printf("%d ",;[i]); puts("");
			}
			else if(ch[0]=='T')
			{
				scanf("%d %d",&x,&y);
				update(1,l[x],r[x],y);
			}
		}
	}
	
	return 0;
}
