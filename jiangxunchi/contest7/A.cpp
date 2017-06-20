#include<cstdio>
#include<vector>
using namespace std;
const int N=100001;
int a[N],b[N],n,m,k;
vector<int> G[26],D[26];
bool check() {
    int p=0;
    for(int i=1; i<=25; ++i) if(!G[i].empty()) {
            for(++p; p<=25&&D[p].empty(); ++p);
            if(p>25) return 0;
            if(D[p].size()!=G[i].size()) return 0;
            for(int j=0; j<G[i].size(); ++j) if(D[p][j]!=G[i][j]) return 0;
        }
    return 1;
}
int main() {
    for(; scanf("%d%d%d",&n,&m,&k)!=EOF;) {
        for(int i=1; i<=n; ++i) scanf("%d",&a[i]);
        for(int i=1; i<=25; ++i) D[i].clear();
        for(int i=1; i<=m; ++i) {
            int x;
            scanf("%d",&x);
            D[x].push_back(i);
        }
        int ans=0;
        for(int i=1; i<=n-m+1; ++i) {
            for(int j=1; j<=25; ++j) G[j].clear();
            for(int j=i; j<=i+m-1; ++j) G[a[j]].push_back(j-i+1);
            if(check()) {
                ++ans;
                i+=m-1;
                continue;
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
