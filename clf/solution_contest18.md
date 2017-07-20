### 比赛征程

  \# |  A  |  B  |  C  |  D  |  E  |  F    
---|---|---|---|---|---|---|---
| contest18 |Y|  Y     | Y | A | Y | A


[比赛链接](codeforces.com/contest/197/problems)

---
>## A - Plate Game
>### Problem Description
> 往N*M的矩阵放置 半径为R的圆，再也不能放则输。
>### Time Limit: 2s
>### Solution
> 显然当且仅当初次就无法放下圆时先手败, 若圆能放在桌子上,那先手就一定能放在桌子的正中间, 不论对手怎么放,先手总能通过与之中心对称放置得到可行解.
>### Code
	#include <cstdio>
	#include <iostream>
	using namespace std;
	int main() {
		int a, b, r;
		scanf("%d%d%d", &a, &b, &r);
		if (a > b) swap(a, b);
		if (r * 2 > a) puts("Second");
		else puts("First");
		return 0;
	}

## B - Limit
>### Problem Description
> 题意：第一行给出两个数字m,n，每个数字代表两个表达式的最高次项，接下来两行数据分别有表示从x^n-x^0的系数,求当x趋向于正无穷时，这两个表达式比值的极限.
>### Time Limit: 2s
>### Solution
> 很简单的极限判断,若次数相同, 在x 趋向无限大 大时只有最高位有效.
>### Code
	#include <cstdio>
	#include <iostream>
	using namespace std;
	int x[3000], y[3000];
	inline int gcd(int x, int y) {
		return y == 0 ? x : gcd(y, x % y);
	}
	inline int mabs(int x) {
		if (x < 0) return -x;
		return x;
	}
	int main() {
		int a, b;
		scanf("%d%d", &a, &b);
		a ++;
		b ++;
		for (int i = 1; i <= a; i ++) scanf("%d", &x[i]);
		for (int i = 1; i <= b; i ++) scanf("%d", &y[i]);
		if (a > b) {
			if (x[1] * y[1] > 0) puts("Infinity");
			else puts("-Infinity");
		}
		else if (b > a)	puts("0/1");
		else {
			int tmp = gcd(mabs(x[1]), mabs(y[1]));
			x[1] /= tmp;
			y[1] /= tmp;
			if (x[1] * y[1] > 0) printf("%d/%d\n", mabs(x[1]), mabs(y[1]));
			else printf("-%d/%d\n", mabs(x[1]), mabs(y[1]));
		}
		return 0;
	}

## C - Lexicographically Maximum Subsequence
>### Problem Description
> 给出一个字符串，输出子串中字典序最大的一个
>### Time Limit: 2s
>### Solution
> 先排序, 不断的取掉字典序大的字符.
>### Code
	#include <cstdio>
	#include <iostream>
	#include <algorithm>
	#include <cstring>
	using namespace std;
	struct node {
		char c;
		int id;
	}q[100005];
	char s[100005];
	inline bool cmp(node a, node b) {
		if (a.c != b.c) return a.c > b.c;
		return a.id < b.id;
	}
	int main() {
		scanf("%s", s);
		int l = strlen(s);
		for (int i = 0; i < l; i ++) q[i + 1].c = s[i], q[i + 1].id = i + 1;
		sort(q + 1, q + l + 1, cmp);
		int p = 1, mx = 0;
		while (p <= l) {
			while (p <= l && q[p].id < mx) p ++;
			if (p > l) break;
			mx = q[p].id;
			printf("%c", q[p].c);
			p ++;
		}
		printf("\n");
		return 0;
	}


## D - Infinite Maze
> ### Problem Description
> 给出无限大的循环迷宫, 问从出发点开始是否能走到无限远.
> ### Time Limit: 2s
> ### Solution
> 首先此题必然是广搜, 然后重点就是判断的条件了.我们在单位迷宫上走,如果越界就走到另一个单位迷宫上,ppx[x%n][y%m]=x 与 ppy[x%n][y%m]=y记忆化, 若能在不同的单位迷宫上走到同一个相对位置,那么必然可以走到无限远.
> ### Code
	#include <cstdio>
	#include <iostream>
	#include <cstring>
	#include <queue>
	using namespace std;
	const int N = 1510;
	struct node {
		int x, y, px, py;
	};
	char G[N][N];
	int ppx[N][N], ppy[N][N];
	int n, m, x, y, nx, ny, px, py;
	int dx[4] = {0, 0, 1, -1};
	int dy[4] = {1, -1, 0, 0};
	queue<node> Q;
	int main() {
		scanf("%d%d", &n, &m);
		for (int i = 0; i < n; i ++) {
			scanf("%s", G[i]);
			for (int j = 0; j < m; j ++) if (G[i][j] == 'S') {
				x = i;
				y = j;
				G[i][j] = '.';
			}
		}
		memset(ppx, 127, sizeof(ppx));
		memset(ppy, 127, sizeof(ppy));
		ppx[x][y] = ppy[x][y] = 0;
		Q.push((node){x, y, 0, 0});
		node cur;
		while (!Q.empty()) {
			cur = Q.front();
			Q.pop();
			for (int i = 0; i < 4; i ++) {
				nx = cur.x + dx[i];
				ny = cur.y + dy[i];
				px = cur.px;
				py = cur.py;
				if (nx < 0) {
					nx = n - 1;
					px --;
				}
				else if (nx >= n) {
					nx = 0;
					px ++;
				}
				if (ny < 0) {
					ny = m - 1;
					py --;
				}
				else if (ny >= m) {
					ny = 0;
					py ++;
				}
				if (G[nx][ny] == '.') {
					if (ppx[nx][ny] == ppx[1500][1500]) {
						ppx[nx][ny] = px;
						ppy[nx][ny] = py;
						Q.push((node){nx, ny, px, py});
					}
					else if (ppx[nx][ny] != px || ppy[nx][ny] != py) {
						puts("Yes");
						return 0;
					}
				}
			}
		}
		puts("No");
		return 0;
	}

## E - Paint Tree
> ### Problem Description
> 给出一棵树和平面直角坐标系上的点, 求一个树上节点到平面上点的映射, 使得映射后平面上的这棵树上的边不相交,平面上没有三点共线.
> ### Time Limit: 2s
> ### Solution
> 贪心题,贪心的直接目的是使得对于一个节点, 它的子树之间互不相交.那么我们可以递归处理,先初始化得到每个节点的子树大小, 对于一棵子树和一些选定的点的映射, 可以取点中最下方的点与子树的根映射, 然后将剩下的点按照极角排序, 然后根据该点每个子节点的子树的大小分配每个子树的点的区间, 这样根据极角排序可以使每个子树分开,这样就能保证得到可行解.
>### Code
	#include <cstdio>
	#include <iostream>
	#include <cmath>
	#include <algorithm>
	using namespace std;
	typedef long long LL;
	struct edge{
		LL nxt, to;
	}e[3005];
	int cnt = 0, fir[1505], size[1505];
	struct point{
		LL x;
		LL y;
		int id;
	}P[1505], bb;
	int ans[1505];
	inline bool cmp(point a, point b) {
		return ((a.x - bb.x) * (b.y - bb.y) - (a.y - bb.y) * (b.x - bb.x)) > 0;
	}
	inline void add(int x, int y) {
		e[++ cnt].to = y;
		e[cnt].nxt = fir[x];
		fir[x] = cnt;
	}
	inline void getsize(int x, int pa) {
		size[x] = 1;
		for (LL i = fir[x]; i; i = e[i].nxt) if (e[i].to != pa) {
			getsize(e[i].to, x);
			size[x] += size[e[i].to];
		}
	}
	inline void solve(int l, int r, int rt, int pa) {
		if (l > r) return;
		if (l == r) {
			ans[P[l].id] = rt;
			return;
		}
		LL mx = 2e9, my = 2e9;
		int rec = 0;
		for (LL i = l; i <= r; i ++) if (P[i].y < my || (P[i].y == my && P[i].x < mx)) {
			mx = P[i].x; my = P[i].y; rec = i;
		}
		swap(P[rec], P[l]);
		ans[P[l].id] = rt;
		bb = P[l];
		sort(P + l + 1, P + r + 1, cmp);
		int pp = l + 1, np;
		for (int i = fir[rt]; i; i = e[i].nxt) if (e[i].to != pa) {
			np = pp + size[e[i].to];
			solve(pp, np - 1, e[i].to, rt);
			pp = np;
		}
	}
	int main() {
		int n, x, y;
		scanf("%d", &n);
		for (int i = 1; i < n; i ++) {
			scanf("%d%d", &x, &y);
			add(x, y); add(y, x);
		}
		getsize(1, 0);
		for (int i = 1; i <= n; i ++)
			scanf("%I64d%I64d", &P[i].x, &P[i].y),
			P[i].id = i;
		solve(1, n, 1, 0);
		for (int i = 1; i <= n; i ++) printf("%d%s", ans[i], i == n ? "\n" : " ");
	}


## F - Opening Portals
> ### Problem Description
> 给一张图,从一号点出发,  图上有一些点初始状态为0,若某两个点状态都为1则可以瞬间转移,到达一个点时若它有状态且为0则瞬间改为1,求把所有状态为0的点变成1所经过的最小路程.
> ### Time Limit: 2s
> ### Solution
> 如果1号点没有状态, 那么首先必定是走到一个最近的有状态的点上, 然后利用瞬间转移的性质,题目就变成了求所有有状态点之间的最小生成树,我们把所有的有状态点推入队列中同时跑SPFA并记录每个点由哪个有状态的点(记为fro)转移来,那么我们得到的就是每个点到最近的有状态节点的距离(dis), 对于原树上的连接i, j的权为wei的边就相当于有长度为dis[i]+dis[j]+wei的边连接fro[i]与fro[j], 以此进行kruskal即可.
> ### Code
	#include <cstdio>
	#include <iostream>
	#include <queue>
	#include <cstring>
	#include <algorithm>
	using namespace std;
	typedef long long LL;
	const int N = 100005;
	struct edge{
		int fro, to, nxt;
		LL c;
	}e[N * 2];
	int cnt = 0, fir[N];
	int n, m, x, y, k;
	int port[N], back[N];
	int fro[N];
	int fa[N];
	LL dis[N];
	bool inq[N];
	queue<int> Q;
	inline void add(int x, int y, LL l) {
		e[++ cnt].to = y;
		e[cnt].fro = x;
		e[cnt].nxt = fir[x];
		e[cnt].c = l;
		fir[x] = cnt;
	}
	inline bool cmp(edge a, edge b) {
		return a.c + dis[a.fro] + dis[a.to] < b.c + dis[b.fro] + dis[b.to];
	}
	inline int getf(int x) {
		if (fa[x] == x) return x;
		return fa[x] = getf(fa[x]);
	}
	int main() {
		LL l;
		scanf("%d%d", &n, &m);
		for (int i = 1; i <= m; i ++) {
			scanf("%d%d%I64d", &x, &y, &l);
			add(x, y, l); add(y, x, l);
		}
		scanf("%d", &k);
		for (int i = 1; i <= k; i ++) scanf("%d", &port[i]);
		memset(dis, 127, sizeof(dis));
		for (int i = 1; i <= k; i ++) {
			Q.push(port[i]);
			dis[port[i]] = 0;
			fro[port[i]] = port[i];
		}
		while (!Q.empty()) {
			x = Q.front();
			inq[x] = 0;
			Q.pop();
			for (int i = fir[x]; i; i = e[i].nxt) {
				if (dis[x] + e[i].c < dis[e[i].to]) {
					dis[e[i].to] = dis[x] + e[i].c;
					fro[e[i].to] = fro[x];
					if (!inq[e[i].to]) {
						inq[e[i].to] = 1;
						Q.push(e[i].to);
					}
				}
			}
		}
		LL ans = dis[1];
		for (int i = 1; i <= n; i ++) fa[i] = i;
		int u, v;
		sort(e + 1, e + cnt + 1, cmp);
		for (int i = 1; i <= cnt; i ++) {
			u = getf(fro[e[i].fro]);
			v = getf(fro[e[i].to]);
			if (u == v) continue;
			fa[u] = v;
			ans += dis[e[i].fro] + dis[e[i].to] + e[i].c;
		}
		printf("%I64d\n", ans);
		return 0;
	}
