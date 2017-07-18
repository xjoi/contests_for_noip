[比赛链接]https://vjudge.net/contest/168929#problem)

# 比赛中解决的问题
## A
### Problem description
> 给你四个正整数a,b,c,d,问你存不存在时刻，使得(a+k1 * b)与 (c+k2 * s d)相等？k1，k2为正整数。

### Data Limit：a,b,c,d<=100  Time Limit: 1s

### Solution
> 1、直接暴枚到30000000  O(30000000)*小常数</br>
2、枚举k1到10000 O(10000)*小常数</br>
3、扩展欧几里德算法
### Code
```cpp
#include<bits/stdc++.h>
using namespace std;
int a, b, c, d;
int main() {
	cin >> a >> b >> c >> d;
	for (int i = max(b, d); i <= 100000000; i ++) {
		if (!((i - b) % a) && !((i - d) % c)) {
			return printf("%d", i), 0;
		}
	}
	return puts("-1");
}
```
*****


## B
### Problem description
> 每个宇宙来两个人，这两个人一叛徒一忠臣，他们报了一些组，当某一组全为叛徒时，机会取消，问是否有这样的可能性。

### Data Limit：n <= 1e4  Time Limit: 2s
### Solution
> 直接模拟即可。每次每组若出现两个来自同一个平行宇宙的，说明该组没危险。

### Code
```cpp
#include<bits/stdc++.h>
int n, m;
int main() {
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= m; i ++) {
		bool flag1[10004], flag2[10004]; int x; scanf("%d", &x); memset(flag1, 0, sizeof(flag1)); memset(flag2, 0, sizeof(flag2));
		for (int k = 1; k <= x; k ++) { int y; scanf("%d", &y); if (y > 0) flag1[y] = 1; if (y < 0) flag2[-y] = 1;}
		bool flag = 1; for (int i = 1; i <= n; i ++) if (flag1[i] && flag2[i]) flag = 0; if (flag) return puts("YES");
	} return puts("NO");
}
```
*****

## C
### Problem description
> 两个人玩游戏，每个人有一个集合，两人轮流游戏，每次他们能让怪兽顺时针走他们选出的自己集合中的数步（可以多次使用），某人走完后怪兽到了结束点就赢了，问对于怪兽在每个位置（不在
游戏结束点）某人先手是否必胜/必输或有策略无限循环？
### Data Limit：n <= 7e3  Time Limit: 4s

### Solution
> 这种博弈问题看到题目就两种思路：</br>
1、SG函数，这道题很难用</br>
2、广搜的赢点输点DP，一方不能再走为输</br>
对于一个赢点，那么所有对方能转移到他的点都为输点。</br>
对于一个点，如果所有他能够出发到达的点都是对手的赢点，那么该点为输点</br>
这是一大类套路DP，我要多做这方面的题。
### Code
```cpp
#include<bits/stdc++.h>
#define ll long long
#define inf 0x3f3f3f3f
using namespace std;

int n, m, f[7005][2];
int s[2][7005], k[2];
int deg[7005][2];

bool vis[7005][2];

queue<pair<pair<int, int>, int> > Q;
void bfs() {
    while (!Q.empty()) {
        pair<pair<int, int>, int> cnt = Q.front(); Q.pop();
        vis[cnt.first.first][cnt.first.second] = 1;
        int turn = !cnt.first.second;
        if (cnt.second == 2) {
            for (int i = 0; i < k[turn]; i++) {
                int next = (cnt.first.first + n - s[turn][i])%n;
                if (!vis[next][turn]) { f[next][turn] = 1; Q.push(make_pair(make_pair(next, turn), 1)); }
            }
        }
        else {
            for (int i = 0; i < k[turn]; i++) {
                int next = (cnt.first.first + n - s[turn][i]) % n;
                deg[next][turn]--;
                if (deg[next][turn] == 0&&!vis[next][turn]) {
                    f[next][turn] = 2;
                    Q.push(make_pair(make_pair(next, turn), 2));
                }
            }
        }
    }
}

int main() {
    scanf("%d", &n);
    scanf("%d", &k[0]);
    for (int i = 0; i < k[0]; i++) {
        scanf("%d", &s[0][i]);
    }
    scanf("%d", &k[1]);
    for (int i = 0; i < k[1]; i++) {
        scanf("%d", &s[1][i]);
    }
    for (int i = 0; i < n; i++) {
        deg[i][0] = k[0];
        deg[i][1] = k[1];
    }
    f[0][0] = f[0][1] = 2;
    vis[0][0] = vis[0][1] = 1;
    Q.push(make_pair(make_pair(0, 0), 2));
    Q.push(make_pair(make_pair(0, 1), 2));
    bfs();
    for (int k = 0; k <= 1; k++) {
	    for (int i = 1; i < n; i++) {
	        if (!vis[i][k])printf("Loop ");
	        else if (f[i][k] == 1) printf("Win ");
	        else printf("Lose ");
	    }
   		printf("\n");
    }
    return 0;
}
```
*****



## E
### Problem description
> 一个有n个颜色的排列，对于特定的k，求将原序列分成最少的连续的段数，使每段的颜色数小于等于k。输出k=1~n的答案。

### Data Limit：n <= 1e5  Time Limit: 2s

### Solution
> 1、如果k=l的个数等于k=r的个数那么k=l~r这么多数答案均相同，这样就每次二分+模拟就可以了。因为 div k == t,t的个数最多为n^(1/2),所以最多二分n^(1/2)次。复杂度上界为n^(3/2)logn

# ##Code1
```
#include<bits/stdc++.h>
using namespace std;
int c[100007];
int vis[100007];
int ans[100007];
int n;
int get_cnt(int k) {
    int res = 0, cnt = 0;
    memset(vis,-1,sizeof(vis));
    for(int i = 1; i <= n; i++) {
        if(vis[c[i]]==res) continue;
        vis[c[i]]=res;
        cnt++;
        if(cnt>k) {
            res++;
            cnt=1;
            vis[c[i]] = res;
        }
    }
    return res + 1;
}

void solve(int l,int r) {
    if(l > r) return;
    int cntl = get_cnt(l);
    int cntr = get_cnt(r);
    if(cntl == cntr) {
        for(int i = l; i <= r; i ++)
            ans[i] = cntl;
        return ;
    }
    ans[l] = cntl;
    ans[r] = cntr;
    int mid = (l + r) >> 1;
    solve(l + 1, mid);
    solve(mid + 1, r - 1);
}
int main() {
    scanf("%d", &n);
    for(int i = 1; i <= n; i ++)
        scanf("%d", &c[i]);
    solve(1, n);
    for(int i = 1; i <= n; i ++)
        printf("%d ", ans[i]);
    return 0;
}
```


#比赛后通过的题
## D
### Problem description
> 
有三种类型的道路，1.花费x，从u->v.</br>
2、花费x，从u->[L,R]中任意一点。</br>
3、花费x，从[L,R]中任意一点->u;</br>
求s，到所有点的最少花费
### Data Limit：n <= 1e5  Time Limit: 2s
### Solution
> 这题是虚拟建建节点的方法，利用类似线段树的构造，把边数优化到nlogn</br>
这种题用单项边汇。
### Code
```cpp
#include<bits/stdc++.h>
#define maxn 2000007 
#define ll long long
using namespace std;
struct E {
	int w, to;
	bool operator () (E a, E b) {
        return a.w > b.w;
    }
};
vector<E> v[maxn];
ll dis[maxn], sav[2][maxn];
int n, q, s, cnt;
int build(int l, int r, int rt, int x) {
	if (l == r) return sav[x][rt] = 1;
	sav[x][rt] = ++ cnt;
	int mid = (l + r) >> 1;
    int S1 = build(l, mid, rt << 1, x);
    int S2 = build(mid + 1, r, rt << 1 | 1, x);
    if (x == 0) {
        v[sav[x][rt]].push_back((E){S1, 0});
        v[sav[x][rt]].push_back((E){S1, 0});
    }
    else {
        v[S1].push_back((E){sav[x][rt], 0});
        v[S2].push_back((E){sav[x][rt], 0});
    }
    return sav[x][rt];
}
void update(int rt, int l, int r, int x, int y, int from, int w, int z) {
    if (l > y || r < x) return;
    if (x <= l && y >= r) {
        if (z == 0) v[from].push_back((E){sav[z][rt], w});
        else v[sav[z][rt]].push_back((E){from, w});
        return;
    }
    int mid = (l + r) >> 1;
    update(rt << 1, l, mid, x, y, from, w, z);
    update(rt << 1 | 1, mid + 1, r, x, y, from, w, z);
}
int main() {
    scanf("%d %d %d", &n, &q, &s);
    memset(dis, -1, sizeof(dis));
    cnt = n;
    build(1, n, 1, 0);
    build(1, n, 1, 1);
    for(int i = 0; i < q; i ++) {
        int t, a, b, c, d;
        scanf("%d %d %d %d", &t, &a, &b, &c);
        if (!(t - 1)) v[a].push_back((E){b, c}); 
		else {
            scanf("%d", &d);
            update(1, 1, n, b, c, a, d, t - 2);
        }
    }
    dis[s] = 0;
    priority_queue<E, vector<E>, E> Q;
    Q.push((E){0, s});
    while(!Q.empty()) {
        int now = Q.top().to;
        Q.pop();
        for(int i = 0; i < v[now].size(); i ++) {
            int nxt = v[now][i].w;
            int weight = v[now][i].to;
            if (dis[nxt] == -1 || dis[now] + weight < dis[nxt]) {
                dis[nxt] = dis[now] + weight;
                Q.push((E){dis[nxt], nxt});
            }
        }
    }
    for (int i = 1; i <= n; i ++) printf("%lld ", dis[i]);
    printf("\n");
    return 0;
}

```
*****
