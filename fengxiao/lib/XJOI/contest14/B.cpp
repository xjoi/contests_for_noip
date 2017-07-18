#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<cmath>
#include<queue>
//#define int long long
#define pii pair<int,int>
#define mp make_pair
#define F first
#define S second
#define N 110
using namespace std;
int dx[]={0,1,-1,0,0},dy[]={0,0,0,1,-1};
int n,m,s,ans;
int map[N][N],dis[20][N][N],Dis[20][20],dist[20];
int head[N*N],nxt[N*N*4],to[N*N];
pii p[20];
bool used[N][N],vis[20];
inline int pow(int a) {return a*a;}
inline int calc(int x1,int y1,int x2,int y2) {return pow(map[x1][y1]-map[x2][y2])+1;}
void SPFA(int X)
{
    memset(dis[X],63,sizeof(dis[X])); memset(used,0,sizeof(used));
    queue<pii> que;
    dis[X][p[X].F][p[X].S]=0; used[p[X].F][p[X].S]=1; que.push(p[X]);
    while(!que.empty())
    {
        pii p=que.front(); que.pop();
        for(int i=1;i<=4;i++)
        {
            int x=p.F+dx[i],y=p.S+dy[i];
            if(x>=1 && x<=n && y>=1 && y<=m && dis[X][x][y]>dis[X][p.F][p.S]+calc(p.F,p.S,x,y))
            {
                dis[X][x][y]=dis[X][p.F][p.S]+calc(p.F,p.S,x,y);
                if(!used[x][y]) {used[x][y]=1; que.push(mp(x,y));}
            }
        }
        used[p.F][p.S]=0;
    }
    for(int i=1;i<=s;i++) Dis[X][i]=dis[X][p[i].F][p[i].S];
}
inline bool ok() {for(int i=1;i<=s;i++) if(!vis[i]) return false; return true;}
void dfs(int pos,int u)
{
    if(ok()) {if(u<ans) ans=u; return;}
    if(u>=ans) return;
    for(int i=1;i<=s;i++)
        if(!vis[i])
        {
            vis[i]=1;
            dfs(i,Dis[pos][i]+u);
            vis[i]=0;
        }
    return;
}
main()
{
    int i,j,k;
    scanf("%d %d",&n,&m);
    for(i=1;i<=n;i++)
        for(j=1;j<=m;j++)
            scanf("%d",&map[i][j]);
    scanf("%d",&s);
    for(i=1;i<=s;i++) scanf("%d %d",&p[i].F,&p[i].S); p[++s].F=1;p[s].S=1;
    for(i=1;i<=s;i++) SPFA(i);
    memset(vis,0,sizeof(vis));ans=1000000000;
    dfs(s,0);
    printf("%d",ans);
    return 0;
}
