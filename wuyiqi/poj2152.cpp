#include <cstdio>
#include <queue>
#include <cstring>
#include <functional>
#include <algorithm>
#include <vector>
using std::pair;
#define foreach(it, E) for(__typeof(E.begin()) it = E.begin(); it != E.end(); it++)
const int N = 1010;
std::vector<pair<int,int> > edge[N];
int D[N], Cost[N];
int n;
int dp[N][N], dis[N][N], opt[N];
void dfs(int u,int f) {
  std::vector<int> children;
  for(std::vector<pair<int,int> >::iterator it = edge[u].begin(); it != edge[u].end(); it++) {
    if(it->first != f) {
      dfs(it->first, u);
      children.push_back(it->first);
    }
  }
  for(int w = 0; w < n; w++) {
    dp[u][w] = (int)1e9;
    if(dis[u][w] > D[u]) continue;
    dp[u][w] = 0;
    foreach(it, children){
      int v = *it;
      dp[u][w] += std::min(dp[v][w], opt[v]);
    }
  }
  opt[u] = (int)1e9;
  for(int w = 0; w < n; w++) {
    opt[u] = std::min(opt[u], dp[u][w] + Cost[w]);
  }
}
void bfs(int s) {
  std::queue<int> Q;
  static bool vis[N]; memset(vis, false, sizeof(vis));
  vis[s] = true;
  Q.push(s); dis[s][s] = 0;
  while(!Q.empty()) {
    int fr = Q.front(); Q.pop();
    foreach(it, edge[fr]){
      int to = it->first;
      int w = it->second;
      if(!vis[to]) {
        vis[to] = true;
        dis[s][to] = dis[s][fr] + w;
        Q.push(to);
      }
    }
  }
}
int main() {
  int t;
  scanf("%d",&t);
  while(t--) {
    scanf("%d",&n);
    for(int i = 0; i < n; i++) scanf("%d",&Cost[i]), edge[i].clear();
    for(int i = 0; i < n; i++) scanf("%d",&D[i]);
    for(int i = 1, a, b, c; i < n; i++) {
      scanf("%d%d%d",&a,&b,&c); a --, b --;
      edge[a].push_back(std::make_pair(b,c));
      edge[b].push_back(std::make_pair(a,c));
    }
    for(int i = 0; i < n; i++) {
      bfs(i);
    }
    dfs(0, -1);
    printf("%d\n",opt[0]);
  }
  return 0;
}
