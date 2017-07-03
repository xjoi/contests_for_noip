# 比赛记录
---
## A - The Monster
### Problem Description
> $求i，使得x = i\times a + b 且 x = j\times c + d$
### Data Limit
> a, b, c, d < 100
### Solution
> 强行模拟、exgcd均可做
### Code
```cpp
#include<cstdio>
#include<iostream>
using namespace std;
int main() {
	int a, b, c, d;
	scanf("%d%d%d%d", &a, &b, &c, &d);
	for(int i = 0; i <= 10000; i ++) {
		while(b < d) b += a;
		while(b > d) d += c;
		if(b == d) {
			printf("%d\n", b);
			return 0;
		}
	}
	printf("-1\n");
	return 0;
}
```

## B - Not Afraid
### Problem Description
> 给m个数列，若每个数列中均同时有一个数及其相反数，则输出YES
### Data Limit
> $\sum _{i = 1}^m k_i ≤ 10^4 $
### Solution
> 模拟
### Code
```cpp
#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;
bool tab[50005];
int main() {
	int n, m, k, x;
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= m; i ++) {
		memset(tab, 0, sizeof(tab));
		scanf("%d", &k);
		bool flag = 0;
		while (k --) {
			scanf("%d", &x);
			if (tab[20000 - x]) flag = 1;
			tab[20000 + x] = 1;
		}
		if (!flag) {
			printf("YES\n");
			return 0;
		}
	}
	printf("NO\n");
	return 0;
}
```

# 赛后补题
---

## C - Berzerk
### Problem Description
> 两个人博弈，棋盘是一个n个点的环，每人有序列s，可以使棋子顺时针移动s[i][j]个单位，使棋子移
> 动到第一格的人获胜，求对于棋子的每一个起始位置，两个人分别作为先手，是否必胜
### Data Limit
> n <= 7000
### Solution
> 考虑每个状态f[i][j]表示走到第i个位置，先手是j时先手的是否必胜，f[i][j]可以转移到
> f[(i + s[k][j])][!\ j]，若它可以转移到的每一个状态都是对手必胜，则该状态为必败，若
> 该状态可以转移到任何一个对手必败的局面，则该局面必胜，否则可以导致循环
### Code
```cpp
#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
const int N = 7005;
int s[N][2], f[N][2], n, k[2];
int vis[N][2];
inline int work(int pos, int fir) {
	if (vis[pos][fir] || f[pos][fir]) return f[pos][fir];
	vis[pos][fir] = 1;
	int nxt, val;
	for (int i = 1; i <= k[fir]; i ++) {
		nxt = (pos + s[i][fir]) % n;
		if (!nxt) nxt = n;
		if (nxt == 1) {
			f[pos][fir] = 1;
			return 1;
		}
	}
	int cnt = 0;
	for (int i = 1; i <= k[fir]; i ++) {
		nxt = (pos + s[i][fir]) % n;
		val = work(nxt, 1 - fir);
		if (val == -1) {
			f[pos][fir] = 1;
			return 1;
		}
		else if(val == 1) cnt ++;
	}
	if (cnt == k[fir]) f[pos][fir] = -1;
	return f[pos][fir];
}
int main() {
	scanf("%d", &n);
	for (int j = 0; j <= 1;j ++) {
		scanf("%d", &k[j]);
		for (int i = 1; i <= k[j]; i ++) scanf("%d", &s[i][j]);
	}
	for (int j = 0; j <= 1; j ++) {
		memset(vis, 0, sizeof(vis));
		for (int i = n; i >= 1; i --) {
			work(i, 0);
			work(i, 1);
		}
	}
	for(int j = 0; j <= 1; j ++) {
		for(int i = 2; i <= n; i ++) {
			if (f[i][j] == -1) printf("Lose ");
			else if (f[i][j] == 0) printf("Loop ");
			else printf("Win ");
		}
		printf("\n");
	}
	return 0;
}
```

## D - Legacy
### Problem Description
> 单源最短路，允许u->v 或u->[l,r]或[l,r]->u
### Data Limit
>  1 ≤ n, q ≤ 10^5, \ 1 ≤ s ≤ n
### Solution
> 我们试图用一些点代表一些区间，于是我们得到了线段树
>![Alt text](http://images2015.cnblogs.com/blog/1099411/201707/1099411-20170703181254628-1790707444.png)
> 于是我们顺利地把边数变成了O(log(q))的级别
### Code
```cpp
#include <cstdio>
#include <iostream>
#include <queue>
#include <cstring>
using namespace std;
typedef long long LL;
const int N = 100005;
struct node{int nxt, to, w;} edge[3100000];
int que[N], cnt = 0, tot;
int fir[N * 8], back[N * 8];
LL dis[N * 8];
bool inq[N * 8];
inline void add(int x, int y, int l) {
	edge[++ cnt].to = y;
	edge[cnt].nxt = fir[x];
	edge[cnt].w = l;
	fir[x] = cnt;
}
inline void build(int x, int l, int r) {
	if (l == r) {
		back[l] = x;
		add(x, x + N * 4, 0);
		add(x + N * 4, x, 0);
		return;
	}
	int mid = (l + r) >> 1, lc = x << 1, rc = lc + 1;
	build(lc, l, mid);
	build(rc, mid + 1, r);
	add(x, lc, 0);
	add(x, rc, 0);
	add(lc + N * 4, x + N * 4, 0);
	add(rc + N * 4, x + N * 4, 0);
}
inline void Query(int x, int l, int r, int a, int b) {
	if (l == a && r == b) {
		que[++ tot] = x;
		return;
	}
	int mid = (l + r) >> 1;
	if (b <= mid) Query(x << 1, l, mid, a, b);
	else if (a > mid) Query(x << 1 | 1, mid + 1, r, a, b);
	else Query(x << 1, l, mid , a, mid), Query(x << 1 | 1, mid + 1, r, mid + 1, b);
}
int main() {
	int n, q, s, opt, v, l, r, u, w;
	scanf("%d%d%d", &n, &q, &s);
	build(1, 1, n);
	while (q --) {
		scanf("%d", &opt);
		if (opt == 1) {
			scanf("%d%d%d", &u, &v, &w);
			add(back[u], back[v], w);
		} else {
			scanf("%d%d%d%d", &v, &l, &r, &w);
			tot = 0;
			Query(1, 1, n, l, r);
			if (opt == 2) {
				for (int i = 1; i <= tot; i ++) add(back[v], que[i], w);
			} else {
				for (int i = 1; i <= tot; i ++) add(que[i] + N * 4, back[v], w);
			}
		}
	}
	memset(dis, 127, sizeof(dis));
	LL un = dis[0];
	queue<int> Q;
	Q.push(back[s]);
	dis[back[s]] = 0;
	while (!Q.empty()) {
		int x = Q.front();
		Q.pop();
		inq[x] = 0;
		for (int i = fir[x]; i; i = edge[i].nxt) {
			v = edge[i].to;
			if(dis[v] > dis[x] + (LL)edge[i].w) {
				dis[v] = dis[x] + (LL)edge[i].w;
				if (!inq[v]) {
					inq[v] = 1;
					Q.push(v);
				}
			}
		}
	}
	for (int i = 1; i <= n; i ++) {
		if(dis[back[i]] != un) printf("%I64d ", dis[back[i]]);
		else printf("-1 ");
	}
	printf("\n");
	return 0;
}
```

## E - Till I Collapse
### Problem Description
> 对于一个序列，求k∈[1,n]，至少将序列分成几块，使每块内不同的数总数不超过k
### Data Limit
> n ≤ 10^5
### Solution
> 经过观察发现答案数组是非严格递减的，那么可以知道如果对于一个区间 [l,r] 中，如果
> ans[l]==ans[r] 那么整个区间 ans 应该是一样的。所以把这种情况剪枝一下，然后就过了
> 标算是可持久化数据结构
### Code
```cpp
#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;
const int N = 100005;
int ans[N], col[N], tab[N], n;
inline int count(int x) {
	memset(tab, 0, sizeof(tab));
	int ret = 1, cnt = 0;
	for (int i = 1; i <= n; i ++) {
		if (tab[col[i]] == ret) continue;
		tab[col[i]] = ret;
		cnt ++;
		if (cnt > x) {
			cnt = 1;
			tab[col[i]] = ++ ret;
		}
	}
	return ret;
}
inline void work(int l, int r) {
	if (l > r) return;
	int cl = count(l);
	if (l == r) {
		ans[l] = cl;
		return;
	}
	int cr = count(r);
	if (cl == cr) {
		for (int i = l; i <= r; i ++) ans[i] = cl;
		return;
	}
	ans[l] = cl;
	ans[r] = cr;
	int mid = (l + r) >> 1;
	work(l + 1, mid);
	work(mid + 1, r - 1);
}
int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i ++) scanf("%d", &col[i]);
	work(1, n);
	for (int i = 1; i <= n; i ++) printf("%d ",ans[i]);
	printf("\n");
	return 0;
}
```
