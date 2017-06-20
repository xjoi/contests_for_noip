#include <cstdio>
#include <cstring>
#include <algorithm>
const int N = 100010;
int ch[N*20][2];
int val[N*20];
int root[N*20], LOG[2*N];
int sz;
void build() {
    root[0] = 0;
    ch[0][0] = 1;
    ch[0][1] = 2;
    val[0] = 0;
    for(int i = 1; i <= 65534; i++) {
        ch[i][0]=2*i+1,ch[i][1]=2*i+2;
        val[i] = 0;
    }
    for(int i = 65535; i <= 65534*2+2; i++) {
        val[i] = 0;
        ch[i][0] = ch[i][1] = 0;
    }
    sz = 65534*2+3;
    LOG[0] = -1;
    for(int i = 1; i < 2*N; i++) LOG[i] = LOG[i>>1] + 1;
}
namespace M {
void newnode(int &tnode,int ori) { // 复制一份
    tnode = sz ++;
    ch[tnode][0] = ch[ori][0];
    ch[tnode][1] = ch[ori][1];
    val[tnode] = val[ori];
}
void Insert(int &new_rt,int rt,int v) {
    newnode(new_rt,rt);
    int pre = new_rt;
    int p = rt, now = new_rt;
    for(int i = 0; i < 16; i++) {
        int c = v>>(15-i)&1;
        p = ch[p][c];
        now = ch[now][c];
        newnode(now,p);
        ch[pre][c] = now;
        val[now]++;
        pre = now;
    }
}
int a[N];
int find(int a,int b,int lca,int v) {
    int ra = root[a], rb = root[b], rc = root[lca];
    int lv=M::a[lca];
    int ans = 0, flag = 1;
    for(int i = 0; i < 16; i++) {
        int c = v>>(15-i)&1;
        int c1 = lv>>(15-i)&1;
        int ta = ch[ra][!c],tb = ch[rb][!c], tc = ch[rc][!c];
        int v = val[ta] + val[tb] - 2*val[tc] + (flag&&c!=c1);
        if(v) {
            ra = ta, rb = tb, rc = tc;
            ans |= 1<<(15-i);
            if(c1==c) flag = 0;
        } else {
            ra = ch[ra][c], rb = ch[rb][c], rc = ch[rc][c];
            if(c1!=c) flag = 0;
        }
    }
    return ans;
}
int head[N],E,nxt[N*2],pnt[N*2];
int F[N];  //第一次到达一个点时的时间戳对应的点的编号
int pos[N];// 某个点第一次出现时对应的B数组中的下标
int B[2*N];//遍历过程中的时间戳
int dfn,tot;
int dp[18][2*N];

int n;
void init() {
    E = 0;
    dfn = 0;
    tot = 0;
    std::fill(head,head+n+1,-1);
}
void add(int a,int b) {
    pnt[E] = b;
    nxt[E] = head[a];
    head[a] = E++;
}

void dfs(int u,int f) {
    Insert(root[u],root[f],a[u]);
    int now = ++dfn;
    B[++tot] = now;
    F[now] = u;
    pos[u] = tot;
    for(int i = head[u]; ~i; i = nxt[i]) if(pnt[i]-f) {
            dfs(pnt[i],u);
            B[++tot] = now;
        }
}
void rmq_init(int *num,int n) {
    for(int i = 1; i <= n; i++) dp[0][i] = num[i];
    for(int i = 1; i < 18; i++) {
        int lim = n - (1<<i) + 1;
        for(int j = 1; j <= lim; j++) {
            dp[i][j] = std::min(dp[i-1][j],dp[i-1][j+(1<<i>>1)]);
        }
    }
}
//    Log[i] : <=i的最大的j (2^j <= i)
int LCA(int a,int b) {
    if(pos[a] > pos[b])  std::swap(a,b);
    int m = LOG[pos[b]-pos[a]+1];
    return F[std::min(dp[m][pos[a]],dp[m][pos[b]-(1<<m)+1])];
}
void build_tree(int n) {
    M::n = n;
    int u, v;
    for(int i = 1; i <= n; i++) scanf("%d",&a[i]);
    init();
    build();
    for(int i = 1; i < n; i++)  {
        scanf("%d%d",&u,&v);
        add(u,v);
        add(v,u);
    }
    dfs(1,0);
    rmq_init(B,tot);
}
void solve(int n,int m) {
    build_tree(n);
    for(int i = 0,u,v,c; i < m; i++) {
        scanf("%d%d%d",&u,&v,&c);
        int ans = 0;
        printf("%d\n",find(u,v,LCA(u,v),c));
    }
}
};
int main() {
    build();
    int n, m;
    while(scanf("%d%d",&n,&m)!=EOF) {
        M::solve(n,m);
    }
    return 0;
}
