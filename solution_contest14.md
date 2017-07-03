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
#include<bits/stdc++.h>
using namespace std;
int read() {
	int x = 0, f = 1; char ch = getchar();
	while (!isdigit(ch)) {
		if (ch == '-') f = -1; ch = getchar();
	}
	while (isdigit(ch)) {
		x = x * 10 + ch - '0';
		ch = getchar();
	}
	return x * f;
}
int n, m, now, last;
vector<int> Vec;
int main() {
	n = read(); m = read();
	for (int i = 1; i <= n; i ++) {
		last = now; now = read();
		if (i != 1) {
			if (now - last > m) {
				vector <int>().swap(Vec);
				Vec.push_back(now);
			} else {
				Vec.push_back(now);
			}
		} else {
			Vec.push_back(now);
		}
	}
	printf("%d", Vec.size());
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
#include<bits/stdc++.h>
using namespace std;

char s[50010];
int b[27];

int main() {
    scanf("%s", s);
    int flag = 1;
    int len = strlen(s);
    if(len < 26) {
        return puts("-1");
    }
    memset(b,0,sizeof(b));
    for(int i = 0; i <= len - 26 && flag; i ++) {
        memset(b, 0, sizeof(b));
        int sum = 0, tot = 0;
        for(int j = i; j < i + 26; j ++) {
            if(s[j] != '?') b[s[j] - 'A'] ++;
            else tot ++;
        }
        for(int j = 0; j < 26; j ++) if(b[j]) sum++;
        if(tot + sum == 26) {
            int t = 0;
            for(int j = i; j < i + 26; j ++) {
                if(s[j] == '?') {
                    for(; t < 26; t ++) {
                        if(!b[t]) {
                            s[j] = 'A' + t; t ++; break;
                        }
                    }
                }
            }
            flag = 0;
        }
    }
    for(int i = 0; i < len; i ++) {
        if(s[i] == '?') s[i] = 'X';
    }
    if(flag) puts("-1");
    else printf("%s\n",s);
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
#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n, now;
ll a[100001];
int main() {
	cin >> n;
	for (ll i = n; i >= 1; i --) {
		a[i] = (i + 1) * (i + 1) * i - i + 1;
	}
	a[1] -= 2;
	for (int i = 1; i <= n; i ++) {
		cout << a[i] << endl;
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
#include <bits/stdc++.h>
#define LL long long
#define INF (1LL << 60)
#define N 10005
using namespace std;
LL n, m, s, t, L;
LL dis[N], w[N];
LL vis[N], xx[N], yy[N], none[N], pe[N], px[N];
queue<LL> Q;
vector<LL> v[N], p[N];
void read(LL &x) {
	LL f = 1; x = 0;
	char ch = getchar();
	while (!isdigit(ch))   {if (ch == '-') f = -1; ch = getchar();}
	while (isdigit(ch)) {x = x * 10 + ch - '0'; ch = getchar();}
	x *= f;
}
void SPFA() {
	for (LL i = 0; i < n; i++) dis[i] = INF;
	dis[s] = 0; Q.push(s); vis[s] = 1;
	while (!Q.empty()) {
		LL x = Q.front(); Q.pop(); vis[x] = 0;
		for (LL i = 0; i < v[x].size(); i++) {
			LL y = v[x][i]; LL z = w[p[x][i]];
			if (dis[x] + z < dis[y]) {
				dis[y] = dis[x] + z; pe[y] = p[x][i]; px[y] = x;
				if (!vis[y]) { vis[y] = 1; Q.push(y); }
			}
		}
	}
}

int main() {
	read(n), read(m), read(L), read(s), read(t);
	for (LL i = 1; i <= m; i++) {
		read(xx[i]), read(yy[i]), read(w[i]); if (w[i] == 0) none[i] = 1;
		v[xx[i]].push_back(yy[i]);
		v[yy[i]].push_back(xx[i]);
		p[xx[i]].push_back(i);
		p[yy[i]].push_back(i);
	}
	for (LL i = 1; i <= m; i++) if (none[i]) w[i] = INF;
	SPFA(); if (dis[t] < L) return puts("NO");
	for (LL i = 1; i <= m; i++) if (none[i]) w[i] = 1;
	SPFA(); if (dis[t] > L) return puts("NO");
	while (1) {
		LL x = t, c;
		while (x != s) {
			LL edge = pe[x];
			if (none[edge]) { c = edge; break; }
			x = px[x];
		}
		if (dis[t] == L) break;
		w[c] += L - dis[t];
		SPFA();
	}
	puts("YES");
	for (int i = 1; i <= m; i++) printf("%lld %lld %lld\n", xx[i], yy[i], w[i]);
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
#include<bits/stdc++.h>
#define MX 100100
#define inf 0x3f3f3f3f
#define LL long long

using namespace std;

LL n, M, Mn, P10[MX], Pn10[MX];
LL ans; LL root = 0;
LL d[500001], minBalance = 0x7fffffff, minNode = 0, minNodeParent = 0;
LL f[500001], g[500001], maxsz[500001] = {0}, size;
bool vis[500001];

map<LL, LL> mp;
int sta1[100010], sta2[100010], top;

struct Edge{ LL to, nxt, w; } e[MX << 1]; LL head[500001], cnt = 0;

inline int read() {
	int x=0; char ch = getchar();
	while(!isdigit(ch)) ch = getchar();
	while(isdigit(ch)) { x = x * 10 + ch - '0'; ch = getchar(); }
	return x;
}
inline void addedge (LL f, LL t, LL w) { e[++ cnt].to = t; e[cnt].nxt = head[f]; head[f] = cnt; e[cnt].w = w;}

void exgcd(LL &x,LL &y,LL a,LL b) {
	if (b == 0) { x = 1, y = 0; return; }
	exgcd(y, x, b, a % b);
	y -= (a / b) * x;
}

void dfs(LL node, LL parent) {
    d[node] = 1; maxsz[node] = 0;
    for (LL i = head[node]; i; i = e[i].nxt) {
        int son = e[i].to;
        if (son != parent && !vis[son]) {
            dfs(son, node);
            d[node] += d[son];
            maxsz[node] = max(maxsz[node], d[son]);
        }
    }
	maxsz[node] = max(maxsz[node], size - d[node]);
	if (maxsz[node] < maxsz[root]) root = node;
}

void GetNum(LL u, LL fa, LL wa, LL wb, LL dep) {
    LL v;
    if (dep) mp[wa] ++ , top ++ , sta1[top] = wb, sta2[top] = dep;
    for (LL p = head[u]; p; p = e[p].nxt) if (v = e[p].to, v != fa && !vis[v])
        GetNum(v, u, (1LL * e[p].w * P10[dep] % M + wa) % M, (wb * 10LL % M + e[p].w) % M, dep + 1);
}

LL calc(LL u, LL init) {
    LL i; LL ret = 0;
    mp.clear();
    top = 0;
    GetNum(u, 0, init % M, init % M, (bool)init);
	for (int i = 1; i <= top; i ++){
        LL now = -1LL * sta1[i] * Pn10[sta2[i]] % M;
        if (now < 0) now += M;
        if (mp.find(now) != mp.end()) ret += mp[now];
        if (!init) ret += (sta1[i] == 0);
    }
    if (!init) ret += mp[0];
    return ret;
}

void work(LL u) {
    LL v , p ;
    ans += calc(u,0), vis[u] = 1;
    for (LL p = head[u]; p; p = e[p].nxt) if (v = e[p].to, !vis[v]) {
        ans -= calc(v, e[p].w), maxsz[0] = size = d[v];
        dfs(v, root = 0); work(root);
    }
}

int main() {
	n = read(); M = read();
	LL y;
	if(10 > M) exgcd(Mn, y, 10, M);
	else exgcd(y, Mn, M, 10);
	if (Mn < 0) Mn = (M - (-Mn) % M) % M;
	P10[0] = 1; Pn10[0] = 1;
	for(LL i = 1; i <= n; i ++) {
		P10[i] = (P10[i - 1] * 10) % M;
		Pn10[i] = (Pn10[i - 1] * Mn) % M;
	}
	for(LL i = 1; i < n; i ++) {
		LL a, b, x;
		a = read(); b = read(); x = read();
		a ++; b ++;
		addedge(a, b, x);
		addedge(b, a, x);
	}
	size = n; maxsz[0] = n;
	dfs(1, 0); work(root);
	printf("%lld", ans);
	return 0;
}
```

### Tag
> Divide-and-Conquer, Inverse, Tree
