### 比赛征程

  \# |  A  |  B  |  C  |  D  |  E  
---|---|---|---|---|---|---|---
| contest19 |Y|  A     | Y | A | A 


[比赛链接](codeforces.com/contest/260/problems)

---
## A - Adding Digits
>### Problem Description
> 给出a和b，要求给a右端加一位数字n次且次次是b的倍数。
>### Time Limit: 2s
>### Solution
> 第一次扩展如果成功，那么之后的扩展全部是0就能除得尽。

## B - Ancient Prophesy 
> 注意要认真审题.

## C - Balls and Boxes
>### Problem Description
>编号1-n个桶，每个桶里有ai个球，现在从下标为i的桶里，拿出所有的球，一直往右边放，放到n了，就再从0开始放，告诉你最后一个球放下的下标，要你输出所有桶的最初状态。
>### Time Limit: 2s
>### Solution
> 强行模拟, 用前缀后缀优化时间


## D - Black and White Tree 
> ### Problem Description
> 有n个点的一个树，同一条边的两个点涂成不同的颜色(black & white)，每条边有一个权值，题目给出n ， 和每个点的颜色 和 与每个点相连的边的权值和。
> ### Time Limit: 2s
> ### Solution
> 按s从小到大排序贪心地建边，并消耗完s。由于黑点和白点的权值和相同,就可以不断的贪心消除.
> ### Code
	#include <cstdio>
	#include <iostream>
	#include <algorithm>
	using namespace std;
	const int N = 100005;
	struct node{
		int s, c, id;
	}tree[N];
	int cw, cb;
	inline bool cmp(node a, node b) {
		return a.c < b.c;
	}
	int main() {
		int n, c, s, pw = 1, pb = 1, t;
		scanf("%d", &n);
		for (int i = 1; i <= n; i ++) scanf("%d%d", &tree[i].c, &tree[i].s), tree[i].id = i;
		sort(tree + 1, tree + n + 1, cmp);
		for (pb = 1; pb <= n && !tree[pb].c; pb ++);
		for (int i = 1; i < n; i ++) {
			t = min(tree[pb].s, tree[pw].s);
			printf("%d %d %d\n", tree[pb].id, tree[pw].id, t);
			tree[pb].s -= t;
			tree[pw].s -= t;
			if (pb < n && !tree[pb].s) pb ++;
			else pw ++;
		}
		return 0;
	}

## E - Dividing Kingdom 
> ### Problem Description
> 给出一些点，要求给出4条线，两条平行x轴，两条平等y轴，不经过任何 点，把平面分为9块，每块包含的点数，正数可以满足每个人的需要
> ### Time Limit: 2s
> ### Solution
> 用主席树判断每个区间是否存在符合要求的方案, 然后看每个区间方案是否能有交集
>### Code
	#include <cstdio>
	#include <iostream>
	#include <algorithm>
	using namespace std;
	typedef double db;
	typedef pair<int, int> P;
	const int N = 100005;
	const int M = 15000000;
	P p[N];
	int tab[N];
	int lc[M], rc[M], key[M], cnt = 0;
	int root[N], rtab[N], tt[N];
	int pos;
	bool ft;
	inline void add(int x, int y, int l, int r, int pos) {
		key[x] = key[y] + 1;
		if (l == r) return;
		int mid = (l + r) >> 1;
		if (pos <= mid) {
			if (!lc[x]) lc[x] = ++ cnt;
			rc[x] = rc[y];
			add(lc[x], lc[y], l, mid, pos);
		}
		else {
			if (!rc[x]) rc[x] = ++ cnt;
			lc[x] = lc[y];
			add(rc[x], rc[y], mid + 1, r, pos);
		}
	}
	inline void dfs(int x, int y, int l, int r, int len) {
		if (l == r) {
			pos = l;
			if (len == key[x] - key[y]) ft = 1;
			return;
		}
		int mid = (l + r) >> 1;
		if (len <= key[lc[x]] - key[lc[y]]) dfs(lc[x], lc[y], l, mid, len);
		else dfs(rc[x], rc[y], mid + 1, r, len - (key[lc[x]] - key[lc[y]]));
	}
	int main() {
		int n, x, y;
		scanf("%d", &n);
		for (int i = 1; i <= n; i ++) {
			scanf("%d%d", &x, &y);
			p[i] = make_pair(x, y);
			tab[i] = y;
		}
		sort(p + 1, p + n + 1);
		sort(tab + 1, tab + n + 1);
		int tot = unique(tab + 1, tab + n + 1) - tab - 1, t = 0, cur, lst;
		for (int i = 1, j = 1; i <= n; i = j + 1) {
			j = i;
			while (j < n && p[j + 1].first == p[i].first) j ++;
			lst = root[t ++];
			tt[t] = p[i].first;
			for (int k = i; k <= j; k ++) {
				p[k].second = lower_bound(tab + 1, tab + tot + 1, p[k].second) - tab;
				cur = ++ cnt;
				add(cur, lst, 1, tot, p[k].second);
				lst = cur;
			}
			root[t] = cur;
			rtab[t] = key[cur];
		}
		int a[11], tmp[11];
		for (int i = 1; i <= 9; i ++) scanf("%d", &a[i]);
		sort(a + 1, a + 10);
		int p, q, rd, sd, ru, su;
		bool flag;
		while (true) {
			flag = 1;
			tmp[0] = 0;
			for (int i = 1; i <= 9; i ++) tmp[i] = tmp[i - 1] + a[i];
			p = lower_bound(rtab + 1, rtab + t + 1, tmp[3]) - rtab;
			flag = (flag && rtab[p] == tmp[3]);
			q = lower_bound(rtab + 1, rtab + t + 1, tmp[6]) - rtab;
			flag = (flag && rtab[q] == tmp[6]);
			ft = 0;
			dfs(root[p], 0, 1, tot, a[1]);
			rd = pos;
			flag = (flag && ft);
			dfs(root[p], 0, 1, tot, a[1] + 1);
			ru = pos;
			ft = 0;
			dfs(root[p], 0, 1, tot, a[1] + a[2]);
			sd = pos;
			flag = (flag && ft);
			dfs(root[p], 0, 1, tot, a[1] + a[2] + 1);
			su = pos;
			ft = 0;
			dfs(root[q], root[p], 1, tot, a[4]);
			rd = max(rd, pos);
			flag = (flag && ft);
			dfs(root[q], root[p], 1, tot, a[4] + 1);
			ru = min(ru, pos);
			ft = 0;
			dfs(root[q], root[p], 1, tot, a[4] + a[5]);
			sd = max(sd, pos);
			flag = (flag && ft);
			dfs(root[q], root[p], 1, tot, a[4] + a[5] + 1);
			su = min(su, pos);
			ft = 0;
			dfs(root[t], root[q], 1, tot, a[7]);
			rd = max(rd, pos);
			flag = (flag && ft);
			dfs(root[t], root[q], 1, tot, a[7] + 1);
			ru = min(ru, pos);
			ft = 0;
			dfs(root[t], root[q], 1, tot, a[7] + a[8]);
			sd = max(sd, pos);
			flag = (flag && ft);
			dfs(root[t], root[q], 1, tot, a[7] + a[8] + 1);
			su = min(su, pos);
			if (flag && sd < su && rd < ru) {
				printf("%.10lf %.10lf\n%.10lf %.10lf\n", (db)tt[p] + 0.5, (db)tt[q] + 0.5, (db)tab[rd] + 0.5, (db)tab[sd] + 0.5);
				return 0;
			}
			if (!next_permutation(a + 1, a + 10)) break;
		}
		puts("-1");
		return 0;
	}
