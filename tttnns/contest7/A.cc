#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxn = 102400;
static inline void qexit(){
    fflush(stdout);
    _Exit(0);
}
static void lsh(int *bg, int *ed){
    static int bk[maxn];
    memcpy(bk, bg, (ed - bg) * sizeof(int));
    sort(bk, bk + (ed - bg));
    const int *ued = unique(bk, bk + (ed - bg));
    static int mp[maxn];
    for(const int *it(bk); it != ued; ++it)
        mp[*it] = it - bk;
    for(; bg != ed; ++bg)
        *bg = mp[*bg];
}
static inline bool isgood(const int *it, const int *bg, const int *ed){
    static int bk[maxn];
    memcpy(bk, it, (ed - bg) * sizeof(int));
    lsh(bk, bk + (ed - bg));
    return equal(bg, ed, bk);
}
static void awd(){
    int n, m;
    if(scanf("%d%d%*d", &n, &m) != 2)
        qexit();
    static int stu[maxn];
    for(int i = 0; i < n; ++i)
        scanf("%d", stu + i);
    static int a[maxn];
    for(int i = 0; i < m; ++i)
        scanf("%d", a + i);
    lsh(a, a + m);
    int ans = 0;
    for(const int *it(stu); it + m <= stu + n; ++it){
        if(isgood(it, a, a + m)){
            ++ans;
            it += m - 1;
        }
    }
    printf("%d\n", ans);
}
int main(){
    while(true) awd();
}
