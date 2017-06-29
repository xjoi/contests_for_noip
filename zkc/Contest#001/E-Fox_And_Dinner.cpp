#include <bits/stdc++.h>
using namespace std;
struct Edge{
    int x,y,c,v;
};
vector<int> G[300],path[300];
vector<Edge> E;
map<int,int> at;
int n,m,k,tot=0,tmp,numOdd=0,numEven=0,ans=0;
int a[300],depth[300],cur[300],que[300][300];
bool prime[20010],vis[300];

void wrong(int x) {
    printf("Impossible\n");
    exit(0);
}

void initPrime() {
    memset(prime,1,sizeof prime);
    prime[1]=0;
    for(int i=2;i<20000;i++) {
        if(!prime[i]) continue;
        int j=i*2;
        while(j<20000) {
            prime[j]=0;
            j+=i;
        }
    }
}

void AddEdge(int x,int y,int c) {
    E.push_back((Edge){x,y,c,0});
    G[x].push_back(E.size()-1);
    E.push_back((Edge){y,x,0,0});
    G[y].push_back(E.size()-1);
}

bool BFS() {
    memset(vis,0,sizeof vis);
    queue<int> Q;
    Q.push(0);
    vis[0]=1;
    depth[0]=0;
    while(!Q.empty()) {
        int now=Q.front();
        Q.pop();
        for(int i=0;i<G[now].size();i++) {
            Edge& next=E[G[now][i]];
            if(!vis[next.y]&&next.c>next.v) {
                vis[next.y]=1;
                depth[next.y]=depth[now]+1;
                Q.push(next.y);
            }
        }
    }
    return vis[n];
}

int DFS(int now,int flow) {
    if(now==n||flow<=0) return flow;
    int res=0,f;
    for(int& i=cur[now];i<G[now].size();i++) {
        Edge& next=E[G[now][i]];
        if(depth[next.y]==depth[now]+1) {
            f=DFS(next.y,min(next.c-next.v,flow));
            if(f<=0) continue;
            next.v+=f;
            E[G[now][i]^1].v-=f;
            res+=f;
            flow-=f;
            if(flow<=0) break;
        }
    }
    return res;
}

void find(int x) {
    tmp++;
    int top=0;
    while(x!=-1&&!vis[x]) {
        vis[x]=1;
        top++;
        que[tmp][top]=x;
        x=path[x][2];
    }
    que[tmp][0]=top;
}

void findpath(int now) {
    vis[now]=1;
    path[tmp].push_back(now);
    for(int i=0;i<G[now].size();i++) {
        Edge next=E[G[now][i]];
        int to=next.y;
        if(to!=0&&to!=n&&!vis[to]) {
            if((a[now]&1&&next.v==next.c)||((a[now]%2==0)&&E[G[now][i]^1].c==E[G[now][i]^1].v)) {
                findpath(to);
            }
        }
    }
}

int main() {
    scanf("%d",&n);
    if(n&1) wrong(1);
    for(int i=1;i<=n;i++) {
        scanf("%d",&tmp);
        if(tmp&1) {
            numOdd++;
            a[numOdd]=tmp;
            at[numOdd]=i;
        } else {
            numEven++;
            a[(n/2)+numEven]=tmp;
            at[(n/2)+numEven]=i;
        }
    }
    if(numEven!=numOdd) wrong(2);
    initPrime();
    for(int i=1;i<=numOdd;i++) {
        AddEdge(0,i,2);
        for(int j=n/2+1;j<=n;j++) {
            if(prime[a[i]+a[j]]) AddEdge(i,j,1);
        }
        AddEdge(n/2+i,n+1,2);
    }

    n++;
    while(BFS()) {
        memset(cur,0,sizeof cur);
        ans+=DFS(0,0x7fffff);
    }

    if(ans!=2*numEven) wrong(3);

    tmp=0;
    memset(vis,0,sizeof vis);
    for(int i=1;i<n;i++) {
        if(!vis[i]) {
            tmp++;
            findpath(i);
        }
    }
    printf("%d\n",tmp);
    for(int i=1;i<=tmp;i++) {
        printf("%d ",path[i].size());
        for(int j=0;j<path[i].size();j++) {
            printf("%d ",at[path[i][j]]);
        }
        printf("\n");
    }
    return 0;
}