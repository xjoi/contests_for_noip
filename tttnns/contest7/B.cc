#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;
const int maxn = 10240;
struct Edge{
    int u, v, w;
    Edge(const int u, const int v, const int w):
        u(u),
        v(v),
        w(w){}
};
static bool ltEdge(const Edge &l, const Edge &r){
    return l.w < r.w;
}
static inline void qexit(){
    fflush(stdout);
    _Exit(0);
}
static int fa[maxn];
static int s[maxn];
int value;
static void init(const int n){
    for(int i = 0; i < n; ++i){
        fa[i] = i;
        s[i] = 1;
    }
    value = n * (n - 1);
}
static int getp(const int x){
    return fa[x] == x ? x : fa[x] = getp(fa[x]);
}
static inline int cv(const int x){
    return x * (x - 1);
}
static inline void link(const Edge &e){
    int pa = getp(e.u), pb = getp(e.v);
    if(pa != pb){
        value = value + cv(s[pa]) + cv(s[pb]);
        fa[pa] = pb;
        s[pb] += s[pa];
        value -= cv(s[pb]);
    }
}
static void awd(){
    int n, m;
    if(scanf("%d%d", &n, &m) != 2)
        qexit();
    vector<Edge> es;
    es.reserve(m);
    for(int i = 0; i < m; ++i){
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        es.push_back(Edge(a, b, c));
    }
    sort(es.begin(), es.end(), ltEdge);
    int p;
    scanf("%d", &p);
    vector<pair<int, int> > ps;
    ps.reserve(p);
    for(int i = 0; i < p; ++i){
        int t;
        scanf("%d", &t);
        ps.push_back(make_pair(t, i));
    }
    sort(ps.begin(), ps.end());
    vector<int> anss;
    anss.reserve(ps.size());
    init(n);
    vector<Edge>::const_iterator pt(es.begin());
    for(vector<pair<int, int> >::const_iterator it(ps.begin()); it != ps.end(); ++it){
        while(it -> first > pt -> w and pt != es.end())
            link(*pt++);
        anss.push_back(value);
    }
    vector<int> out(p);
    for(int i = 0; i < p; ++i)
        out[ps[i].second] = anss[i];
    for(int i = 0; i < p; ++i)
        printf("%d\n", out[i]);
}
int main(){
    while(true) awd();
}
