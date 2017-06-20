#include <cstdio>
#include <cstring>
#include <algorithm>
typedef long long lld;
const int N = 111111;
const int M = 550010;
struct Edge {
    int a,b,c;
    lld cnt;
    void in() {
        scanf("%d%d%d",&a,&b,&c);
    }
    bool operator < (const Edge& cmp) const {
        return c < cmp.c;
    }
} edge[M];
int fa[N],cnt[N];
int first[N];
lld second[N];
int find(int x) {
    return fa[x] == x ? x : fa[x] = find(fa[x]);
}
lld sum[N];
int main() {
    int n, m;
    while(scanf("%d%d",&n,&m)!=EOF) {
        for(int i = 0; i < n; i++) cnt[i] = 1,fa[i] = i;
        for(int i = 0; i < m; i++) {
            edge[i].in();
        }
        std::sort(edge,edge+m);
        int tot = 0;
        for(int i = 0; i < m; i++) {
            int a = edge[i].a;
            int b = edge[i].b;
            int c = edge[i].c;
            int ta = find(a);
            int tb = find(b);
            if(ta != tb) {
                first[tot] = edge[i].c;
                edge[i].cnt = (lld)cnt[ta] * cnt[tb] * 2;
                second[tot++] = edge[i].cnt;
                cnt[ta] += cnt[tb];
                fa[tb] = ta;
            }
        }
        sum[tot] = 0;
        for(int i = tot-1; i >= 0; i--) sum[i] = second[i] + sum[i+1] ;
        int Q,t;
        scanf("%d",&Q);
        while(Q--) {
            scanf("%d",&t);
            int l = 0, r = tot-1,best = -1;
            while(l <= r) {
                int mid = l + r >> 1;
                if(first[mid]>=t) {
                    best = mid;
                    r = mid -1;
                } else {
                    l = mid + 1;
                }
            }
            if(best == -1) puts("0");
            else printf("%I64d\n",sum[best]);
        }
    }
    return 0;
}
