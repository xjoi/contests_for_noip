#include<cstdio>
#include<cstring>
#include<algorithm>
#define N 2010
#define int long long
using namespace std;
int n,ans[N];
int head[N],nxt[N<<1],to[N<<1],lst=0;
int sz[N];
struct P {int x,y,pos;} p[N];
inline void swap(P &a,P &b) {P t=a;a=b;b=t;}
inline void adde(int x,int y) {nxt[++lst]=head[x]; to[lst]=y; head[x]=lst;}
inline int cj(P a,P b) {return a.x*b.y-a.y*b.x;}
bool cmp(P a,P b) {int tmp=cj(a,b); return tmp==0 ?  : tmp>0;}
void build_tre(int u,int f)
{
    sz[u]=1;
    for(int i=head[u];i;i=nxt[i]) if(to[i]!=f) {build_tre(to[i],u); sz[u]+=sz[to[i]];}
}
void dfs(int u,int f,int l,int r)
{
    if(l>r) return;
    int pos=l;
    for(int i=l+1;i<=r;i++) if(p[i].y<p[pos].y || (p[i].y==p[pos].y && p[i].x<p[pos].x)) pos=i;
	swap(p[pos],p[l]);
    ans[p[l].pos]=u;
    if(l==r) return;
    for(int i=l+1;i<=r;i++)
    {
        p[i].x-=p[l].x;
        p[i].y-=p[l].y;
    }
    sort(p+l+1,p+r+1,cmp);
    int now=l+1;
    for(int i=head[u];i;i=nxt[i])
	    if(to[i]!=f)
	    {
	        dfs(to[i],u,now,now+sz[to[i]]-1);
	        now+=sz[to[i]];
	    }
}
main()
{
    int i,x,y;
    scanf("%I64d",&n);
    for(i=1;i<n;i++) {scanf("%I64d %I64d",&x,&y); adde(x,y),adde(y,x);}
    for(i=1;i<=n;i++){scanf("%I64d %I64d",&p[i].x,&p[i].y); p[i].pos=i;}
    build_tre(1,0);
    dfs(1,0,1,n);
    for(i=1;i<=n;i++) printf("%I64d ",ans[i]);
    return 0;
}
