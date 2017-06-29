#include <bits/stdc++.h>
using namespace std;

const int INF=0x7ffffff;
int n,m,dest,orig,k;
bool litd=false;
pair<int,int> a[10010];

int getdis(int x,int y) {
    int dx=abs(a[x].first-a[y].first),dy=abs(a[x].second-a[y].second);
    if(y!=dest||(y==dest&&litd)) {
        if(dx+dy==1) return 0;
        if(min(dx,dy)<=2) {
            return 1;
        }
        return INF;
    } else {
        if(dx<=1||dy<=1) {
            return 1;
        }
        return INF;
    }
}

int dijkstra(int s,int t) {
    int dis[10010];
    bool vis[10010];
    memset(vis,0,sizeof vis);
    vis[s]=1;
    for(int i=1;i<=k;i++) {
        if(i!=s) dis[i]=getdis(s,i);
    }
    dis[s]=0;
    for(int i=1;i<=k;i++) {
        int nxt=0,val=INF;
        for(int j=1;j<=k;j++) {
            if(!vis[j]&&dis[j]<val) {
                val=dis[j];
                nxt=j;
            }
        }
        if(nxt==0) break;
        vis[nxt]=1;
        for(int j=1;j<=k;j++) {
            if(!vis[j]) {
                //printf("[%d](%d,%d) -> [%d](%d,%d) = %d\n",nxt,a[nxt].first,a[nxt].second,j,a[j].first,a[j].second,1);
                dis[j]=min(dis[j],dis[nxt]+getdis(nxt,j));
            }
        }
        /*for(int j=1;j<=k;j++) {
            printf("[%d]%d ",j,dis[j]);
        }
        puts("");*/
    }
    return dis[t];
}

int main() {
    scanf("%d%d%d",&n,&m,&k);
    for(int i=1,j,l;i<=k;i++) {
        scanf("%d%d",&j,&l);
        a[i]=make_pair(j,l);
        if(j==n&&l==m) {
            dest=i;
            litd=1;
        } else if(j==1&&l==1) {
            orig=i;
        }
    }
    if(!litd) {
        k++;
        a[k]=make_pair(n,m);
        dest=k;
    }
    int ans=dijkstra(orig,dest);
    if(ans!=INF) printf("%d\n",ans);
    else puts("-1");
    return 0;
}
