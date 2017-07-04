#include<cstdio>
#include<cstring>
#include<queue>
#define int long long
#define N 300010
#define pb push_back
#define pii pair<int,int>
#define mp make_pair
#define F first
#define S second
#define left lc[u],l,r
#define right rc[u],l,r
#define mid ((s[u]+e[u])>>1)
using namespace std;
int n,m,S,K;
int s[N<<3],e[N<<3],lc[N<<3],rc[N<<3],cnt=1;
int dis[N<<3],key[N];
int head[N<<3],nxt[N<<3],to[N<<3],v[N<<3],lst=0;
bool used[N<<3];
inline void adde(int x,int y,int c) {nxt[++lst]=head[x]; to[lst]=y; v[lst]=c; head[x]=lst;}
void build_tre(int u,int l,int r,int t)
{
    s[u]=l; e[u]=r;
    if(s[u]==e[u]) {if(t) key[s[u]]=u; else adde(u,u-K,0),adde(u-K,u,0); return;}
	lc[u]=++cnt; rc[u]=++cnt;
    if(t) adde(u,lc[u],0),adde(u,rc[u],0);  else adde(lc[u],u,0),adde(rc[u],u,0);
    build_tre(lc[u],l,mid,t); build_tre(rc[u],mid+1,r,t);
}
void update(int u,int l,int r,int v,int c,int t)
{
    if(l<=s[u] && e[u]<=r) { t ? adde(v,u,c) : adde(u+K,v,c); return;}
    if(mid>=l) update(left,v,c,t);
    if(mid< r) update(right,v,c,t);
}
void SPFA()
{
    queue<int> que; memset(dis,63,sizeof(dis));
    que.push(key[S]); used[key[S]]=1; dis[key[S]]=0;
    while(!que.empty())
    {
        int p=que.front(); que.pop();
        for(int i=head[p];i;i=nxt[i])
        {
        //printf("?%d?",p);
            if(dis[to[i]]>dis[p]+v[i])
            {
                dis[to[i]]=dis[p]+v[i];
                if(!used[to[i]]) {used[to[i]]=1; que.push(to[i]);}
            }
        }
        used[p]=0;
    }
}
void test()
{
    for(int i=1;i<=14;i++)
    {
        printf("%I64d: ",i);
        for(int j=head[i]; j;j=nxt[j]) printf("(%I64d %I64d) ",to[j],v[j]);
        puts("");
    }
}
main()
{
    int i;
    scanf("%I64d %I64d %I64d",&n,&m,&S);
    build_tre(1,1,n,1); K=cnt++; build_tre(cnt,1,n,0);
	//for(i=1;i<=n;i++) printf("%I64d ",key[i]);
    for(i=1;i<=m;i++)
    {
        int type,x,y,v,l,r,c;
        scanf("%I64d",&type);
        if(type==1)
        {
            scanf("%I64d %I64d %I64d",&x,&y,&c);
            //printf("%I64d %I64d\n",key[x],key[y]);
			update(1,y,y,key[x],c,1);
        }
        else if(type==2)
        {
            scanf("%I64d %I64d %I64d %I64d",&v,&l,&r,&c);
            update(1,l,r,key[v],c,1);
        }
        else if(type==3)
        {
            scanf("%I64d %I64d %I64d %I64d",&v,&l,&r,&c);
            update(1,l,r,key[v],c,0);
        }
    }
    //test();
    SPFA();
    for(i=1;i<=n;i++) printf("%I64d ",dis[key[i]]==dis[0] ? -1 : dis[key[i]]);
    return 0;
}
