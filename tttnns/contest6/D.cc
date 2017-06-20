#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
int dis[3001][3001];
vector<int> G[3001];
static void bfs(const int s){
    queue<int> q;
    q.push(s);
    memset(dis[s], -1, sizeof(dis[s]));
    dis[s][s] = 0;
    while(not q.empty()){
        const int u = q.front(); q.pop();
        for(int v : G[u])
            if(dis[s][v] == -1){
                dis[s][v] = dis[s][u] + 1;
                q.push(v);
            }
    }
}
static void awd(){
    int n, m;
    scanf("%d%d", &n, &m);
    for(int i = 0; i < m; ++i){
        int a, b;
        scanf("%d%d", &a, &b);
        G[a].push_back(b);
        G[b].push_back(a);
    }
    for(int i = 1; i <= n; ++i)
        bfs(i);
    int s1, t1, l1, s2, t2, l2;
    scanf("%d%d%d%d%d%d", &s1, &t1, &l1, &s2, &t2, &l2);
    if(dis[s1][t1] > l1 or dis[s2][t2] > l2)
        puts("-1");
    else{
        int ans = m - dis[s1][t1] - dis[s2][t2];
        for(int x = 1; x <= n; ++x)
            for(int y = 1, r1, r2; y <= n; ++y)
                if((r1 = min(dis[s1][x] + dis[x][y] + dis[y][t1],
                             dis[s1][y] + dis[y][x] + dis[x][t1])) <= l1 and
                   (r2 = min(dis[s2][x] + dis[x][y] + dis[y][t2],
                             dis[s2][y] + dis[y][x] + dis[x][t2])) <= l2)
                    ans = max(ans, m - r1 - r2 + dis[x][y]);
        ans = max(ans, 0);
        printf("%d\n", ans);
    }
}
int main(){
    return awd(), 0;
}
