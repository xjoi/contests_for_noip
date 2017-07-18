[Contest Link](https://cn.vjudge.net/contest/168561)

# Solved during contest
## A
### Description
> 给定n个从小到大排序的数。相邻两数在同一段内当且仅当它们之差不大于c。求最后一段的长度。
#### Data Limit
> 1 <= n <= 100000, 1 <= c <= 10^9.

### Solution
> 直接模拟。

### Code
```cpp
#include <iostream>
using namespace std;
int n, c, a[1000001], p;
int main()
{
    cin >> n >> c;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    p = 1;
    for (int i = 2; i <= n; ++i) {
        if (a[i] - a[i - 1] > c) {
            p = i;
        }
    }
    cout << n - p + 1 << endl;
    return 0;
}
```

### Tag
> Simulation
*****

## B
### Description
> 给定一个由大写字母和问号组成的字符串s。要求将问号都替换成某个大写字母，使得存在长度为26的s的子串包含了所有大写字母。
#### Data Limit
> 1 <= |s| <= 50000.

### Solution
> 枚举起点，判断接下来的26个字母是否可以做到包含所有大写字母。如果可以则将这段子串填充完整，并将不属于这段子串的问号任意填充即可。

### Code
```cpp
#include <iostream>
#include <cstring>
using namespace std;
string s;
bool flag;
int a[26], len, t, c;
int main()
{
    cin >> s;
    if (s.length() < 26) {
        cout << -1 << endl;
        return 0;
    }
    len = s.length();
    for (int k = 0; k < len - 25; k++) {
        memset(a, 0, sizeof(a));
        c = t = 0;
        for (int i = 0; i < 26; ++i) {
            if (s[k + i] != '?') ++a[s[k + i] - 'A'];
            else c++;
        }
        for (int i = 0; i < 26; ++i) {
            if (!a[i]) t++;
        }
        if (t <= c) {
            flag = true;
            for (int i = 0; i < 26; ++i) {
                if (!a[i]) {
                    for (int j = k; j < k + 26; ++j) {
                        if (s[j] == '?') {
                            s[j] = i + 'A';
                            break;
                        }
                    }
                }
            }
            for (int i = 0; i < 26; ++i) {
                if (s[k + i] == '?') s[k + i] = 'A';
            }
            break;
        }
    }
    for (int i = 0; i < len; ++i) {
        if (s[i] == '?') s[i] = 'A';
    }
    if (flag) cout << s << endl;
    else cout << -1 << endl;
    return 0;
}
```

### Tag
> Simulation
*****

## C
### Description
> 一个游戏的初始等级为1，初始数字为2。设当前等级为i，数字为n，有两种操作：①n+=i;②++i, n=sqrt(n)。执行②操作的前提是sqrt(n)能被(i+1)整除。求每两个②操作之间①操作的次数。
#### Data Limit
> 1 <= n <= 100000.

### Solution
> 设第k次开方后的数为k*(k+1)，则上一次开方后的数为(k-1)*k。易知(k-1)*k+xk=(k*(k+1))^2，于是得到x=(k-1)*k*k-(k-2)。

### Code
```cpp
#include <iostream>
using namespace std;
long long n;
int main()
{
    cin >> n;
    cout << 2 << endl;
    for (long long i = 2; i <= n; i++) {
        cout << i * (i + 1) * (i + 1) - i + 1 << endl;
    }
    return 0;
}
```

### Tag
> Math
*****

# Solved after contest
## D
### Description
> 给定一张连通无向图，其中所有边的权值均为自然数。要求将所有权值为0的边的权值变成任意一个不大于10^18的正整数，使得从s到t的最短路径的长度为L。
#### Data Limit
> 2 <= n <= 1000, 1 <= m <= 10000, 1 <= L <= 10^9, 0 <= s, t <= n - 1.

### Solution
> 首先将权值为0的边的权值变成无穷大，求一次最短路，若s和t之间的距离dist<L则无解。若dist==L，则已得到可行解。若dist>L，枚举初始权值为0的边，将它的权值变成1，求一次最短路，若dist≤L则说明已有可行解，把这条边的权值增加L−dist，即得到可行解。若所有初始权值为0的边都已枚举且dist>L，则说明无解。

### Code
```cpp
#include <iostream>
#include <queue>
#include <cstring>
using namespace std;
long long n, m, L, s, t, dist[1001], line[1001][1001];
bool flag, in[1001], sign[1001][1001];
void spfa(int p = -1, int q = -1) {
    queue<int> que;
    while (!que.empty()) que.pop();
    memset(in, false, sizeof(in));
    if (p == -1) {
        memset(dist, 0x1f, sizeof(dist));
        que.push(s), dist[s] = 0, in[s] = true;
    } else {
        if (dist[p] > dist[q]) p ^= q ^= p ^= q;
        que.push(p), in[p] = true;
    }
    while (!que.empty()) {
        long long u = que.front();
        que.pop();
        in[u] = false;
        for (int i = 0; i < n; ++i) {
            if (line[u][i] && dist[i] > dist[u] + line[u][i]) {
                dist[i] = dist[u] + line[u][i];
                if (!in[i]) que.push(i), in[i] = true;
            }
        }
    }
}
int main()
{
    cin >> n >> m >> L >> s >> t;
    for (int i = 1; i <= m; ++i) {
        long long x, y, w;
        cin >> x >> y >> w;
        line[x][y] = line[y][x] = w;
        if (!w) sign[x][y] = sign[y][x] = true;
    }
    spfa();
    if (dist[t] < L) {
        cout << "NO" << endl;
        return 0;
    } else if (dist[t] > L) {
        for (int i = 0; i < n - 1; ++i) {
            for (int j = i + 1; j < n; ++j) {
                if (sign[i][j]) {
                    line[i][j] = line[j][i] = 1;
                    sign[i][j] = sign[j][i] = false;
                    spfa(i, j);
                    if (dist[t] <= L) {
                        line[i][j] = line[j][i] = L - dist[t] + 1;
                        flag = true; break;
                    }
                }
            }
            if (flag) break;
        }
    } else flag = true;
    if (!flag) cout << "NO" << endl;
    else {
        cout << "YES" << endl;
        for (int i = 0; i < n - 1; ++i) {
            for (int j = i + 1; j < n; ++j) {
                if (line[i][j] || sign[i][j]) {
                    cout << i << ' ' << j << ' ';
                    if (line[i][j]) cout << line[i][j];
                    if (sign[i][j]) cout << (long long) 1e18;
                    cout << endl;
                }
            }
        }
    }
    return 0;
}
```

### Tag
> Shortest Path
*****

## E
### Description
> 给定一棵有n个节点的树和一个与10互质的数M，树上每条边的权值都是小于10的正整数。定义dist(u,v)为依次写下从u到v路径上每条边的权值所得到的数字。求满足M|dist(u,v)的点对个数。
#### Data Limit
> 2 <= n <= 100000, 1 <= M <= 10^9.

### Solution
> 设当前枚举到的节点为x。令depthu表示u在x及它子树中的深度。对于在x第(i+1)棵子树中的节点u和在前i棵子树中的节点v，有：
M|dist(u,v)⇔10^depth(v)*dist(u,x)+dist(x,v) ≡0 (mod M) (1).
M|dist(v,u)⇔10^depth(u)*dist(v,x)+dist(x,u)≡0 (mod M) (2).
对于(1)式，化简得dist(u,x)≡−10^(−depth(v))*dist(x,v) (mod M)；对于(2)式，化简得10^(−depth(u))*dist(x,u)≡−dist(v,x) (mod M)。用两个map分别存下前i棵子树中10^(−depth(v))*dist(x,v)和dist(v,x)的值，在处理第(i+1)棵子树时直接加上可行的方案数。

### Code
```cpp
#include <cstdio>
#include <map>
#include <algorithm>
using namespace std;
struct edge {
    int v, w, nxt;
} e[200001];
long long n, m, ans, nume, tot, root, h[100001], size[100001], f[100001];
long long val1[100001], val2[100001], power[100001], inv[100001];
bool vis[100001];
map<long long, int> id1, id2;
void extend_gcd(int a, int b, int &x, int &y) {
    if (!b) { x = 1, y = 0; return; }
    extend_gcd(b, a % b, y, x);
    y -= a / b * x;
}
void add_edge(int u, int v, int w) {
    e[++nume].v = v, e[nume].w = w, e[nume].nxt = h[u], h[u] = nume;
    e[++nume].v = u, e[nume].w = w, e[nume].nxt = h[v], h[v] = nume;
}
void get_root(int t, int fa) {
    size[t] = 1, f[t] = 0;
    for (int i = h[t]; i; i = e[i].nxt) {
        if (!vis[e[i].v] && e[i].v != fa) {
            get_root(e[i].v, t);
            size[t] += size[e[i].v];
            f[t] = max(f[t], size[e[i].v]);
        }
    }
    f[t] = max(f[t], tot - size[t]);
    if (f[t] < f[root]) root = t;
}
void get_dist(int t, int fa, int flag, int depth) {
    if (!flag) ++id1[val1[t]], ++id2[val2[t] * inv[depth] % m];
    else {
        ans += !val1[t] + !val2[t];
        ans += id1[(val2[t] ? m - val2[t] : 0) * inv[depth] % m];
        ans += id2[val1[t] ? m - val1[t] : 0];
    }
    for (int i = h[t]; i; i = e[i].nxt) {
        if (!vis[e[i].v] && e[i].v != fa) {
            if (flag) {
                val1[e[i].v] = (val1[t] + e[i].w * power[depth]) % m;
                val2[e[i].v] = (val2[t] * 10 + e[i].w) % m;
            }
            get_dist(e[i].v, t, flag, depth + 1);
        }
    }
}
void solve(int t) {
    vis[t] = true, id1.clear(), id2.clear();
    for (int i = h[t]; i; i = e[i].nxt) {
        if (!vis[e[i].v]) {
            val1[e[i].v] = val2[e[i].v] = e[i].w % m;
            get_dist(e[i].v, t, 1, 1);
            get_dist(e[i].v, t, 0, 1);
        }
    }
    for (int i = h[t]; i; i = e[i].nxt) {
        if (!vis[e[i].v]) {
            root = n, tot = size[e[i].v];
            get_root(e[i].v, t);
            solve(root);
        }
    }
}
int main()
{
    scanf("%lld%lld", &n, &m);
    power[0] = 1;
    for (int i = 1; i <= n; ++i) power[i] = power[i - 1] * 10 % m;
    for (int i = 0; i <= n; ++i) {
        int x, y;
        extend_gcd(power[i], m, x, y);
        inv[i] = (x % m + m) % m;
    }
    for (int i = 1; i < n; ++i) {
        int u, v, w;
        scanf("%d%d%d", &u, &v, &w);
        add_edge(u, v, w);
    }
    tot = f[n] = n, root = n;
    get_root(0, n);
    solve(root);
    printf("%lld\n", ans);
    return 0;
}
```

### Tag
> Divide-and-Conquer, Inverse, Tree
