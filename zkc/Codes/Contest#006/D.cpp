#include <bits/stdc++.h>
using namespace std;

int n,m,d[3010][3010],s1,t1,l1,s2,t2,l2,ans=1e9;
vector<int> G[3010];

void solve() {
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=n;j++) {
            int dis1=d[s1][i]+d[i][j]+d[j][t1];
            int dis2=d[s2][i]+d[i][j]+d[j][t2];
            if(dis1<=l1&&dis2<=l2) {
                ans=min(ans,dis1+dis2-d[i][j]);
            }
        }
    }
}

int main() {
    scanf("%d%d",&n,&m);
    for(int j,k,i=1;i<=m;i++) {
        scanf("%d%d",&j,&k);
        G[j].push_back(k);
        G[k].push_back(j);
    }
    scanf("%d%d%d%d%d%d",&s1,&t1,&l1,&s2,&t2,&l2);
    memset(d,0,sizeof d);
    for(int i=1;i<=n;i++) {
        queue<int> Q;
        Q.push(i);
        while(!Q.empty()) {
            int now=Q.front();
            Q.pop();
            for(int j=0;j<(int)G[now].size();j++) {
                int next=G[now][j];
                if(now!=next&&i!=next&&d[i][next]==0) {
                    d[i][next]=d[i][now]+1;
                    Q.push(next);
                }
            }
        }
    }
    if(d[s1][t1]<=l1&&d[s2][t2]<=l2) ans=d[s1][t1]+d[s2][t2];
    solve();
    swap(s1,t1);
    solve();
    if(ans>m) {
        puts("-1");
    } else {
        printf("%d\n",m-ans);
    }
    return 0;
}