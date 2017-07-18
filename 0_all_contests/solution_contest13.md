# Contest13 solution


[比赛链接](https://vjudge.net/contest/168406)

[Origin](http://codeforces.com/contest/375)
## A
### Problem description
> 给出杠杆判断是否平衡。

### Solution
> 判断力臂L×力L是否等于力臂R×力R 或者，力矩L是否等于力矩R

### Code

```cpp
int main()
{
	int p;
	long long int r=0LL;
	scanf("%s",s);
	for(p=0; s[p]!='^'; p++);
	for(int i=0; s[i]; i++)
	{
		if(s[i]=='=' || s[i]=='^') continue;
		r+=(long long int)((s[i]-'0')*(p-i));
	}
	printf("%s\n",r?(r>0LL?"left":"right"):"balance");
	return 0;
}
```

***** 

## B
### Problem description
> 告诉你很多如下的关系：A欠B x元，然后让你找到一种替代方案使得每个人应得的钱没有变。该方案钱流通的最少

### Solution
> 这道题是一道贪心题，只要计算每个人的入账和出账，因为只要每个人应得或应付的钱不变就可以了，所以我们就直接把每个人结算完后应得多少，应付多少算出，应得的人 应得钱的总和即为答案，这样做一定不能再优化，且一定最优。

### Code
```cpp
#include<iostream>
using namespace std;
int a[101],n,m,x,y,j,sum;
int main(){
	cin>>n>>m;
	for(int i=0;i<m;i++){
		cin>>x>>y>>j;
		a[x]-=j;
		a[y]+=j;
	}
	for(int i=1;i<=n;i++)if(a[i]>0)sum+=a[i];
	cout<<sum;
}
```
*****
## C
### Problem description
> 给你一个数，你可以任意调换数字的顺序且这个数一定含有1, 6, 8, 9，使最后的数为7的倍数，输出最后的数，若没有就输出0。

### Solution
> 把1、6、8、9放在数列的最前端，因为1689的全排列能构成7的剩余系，所以先是利用一位位mod 7取得系数，全排列一发如果可行就输出。 以后遇到这种构造题要观察数据的性质，先尝试暴力一发，再做。

### Code
```cpp
char ss[8][5] = {"1869", "1968", "1689", "6198", "1698", "1986",
"1896"};
char s[1000010];
int cnt[10];
int main() {
  scanf("%s",s);
  int n = strlen(s);
  for(int i = 0; i < n; i++)  {
    cnt[s[i] - '0'] ++;
  }
  cnt[1] --;
  cnt[6] --;
  cnt[9] --;
  cnt[8] --;
  bool flag = false;
  int sum = 0;
  for(int i = 9; i >= 1; i--) if(cnt[i]){
    flag = true;
    for(int j = 0; j < cnt[i]; j++) 
      printf("%d",i),sum = (sum * 10 + i) % 7;
  }
  if(!flag) {
    printf("%s",ss[0]);
  } else {
    sum = sum * 10000 % 7;
    printf("%s",ss[(7-sum)%7]);
  }
  for(int j = 0; j < cnt[0]; j++) printf("0");
  puts("");
  return 0;
}

```
*****

## D
### Problem description
> 给你一个有一些黑格的矩阵，你可以任意换矩阵的行和列，然后求这个矩阵中能存在的最大全黑子矩阵的面积

### Solution
> 因为只能交换行，所以可以预处理出每一个1向右最远能延伸的长度。这样我们枚举每一列，在这一列中枚举延伸长度i，那么可行的子矩阵面积为延伸长度大于等于i的位置数量乘以长度i，同时处理出最大值即可。

### Code
```cpp
    for(int i=1;i<=n;i++) {
        for(int j=m;j>=1;j--) {
            if(j<m&&f[i][j]) f[i][j]+=f[i][j+1];  //f[i][j]保存i,j位置的延伸距离
            g[j][f[i][j]]++;  //g[i][j]保存第i列延伸长度为j的位置数量
        }
    }
    int ans=0,cnt=0;
    for(int i=1;i<=m;i++) {
        cnt=0;  //cnt表示当前可行位置
        for(int j=m;j>0;j--) {  //倒序便于累计
            if(g[i][j]) {
                cnt+=g[i][j];
                ans=max(ans,j*cnt);
            }
        }
    }

```
*****
## E
### Problem description
> 就是给你一个矩阵，给你一个开始点，你每次只能走到相邻的可行格。
不可行格有：
1、宝藏
2、炸弹
3、墙
要求你走可行格，最后回到出发点，围成的图形内部不包含炸弹且宝藏权值和减路径长度最大（可以不动）

### Solution
> bfs, 状态为f[i][j][mask],表示走到了i j位置，所包围的宝藏的状态为mask的最短路,判断一个点是不是在包围圈内只需从这个点出发任意一个方向拉一条射线，看下射线与bfs的路径相交了几次，下面代码是往下面射出一条射线，每次bfs扩展节点的时候重新更新宝藏们是不是被包围的状态。

### Code
```cpp
struct node {
  int x, y, st;
  node(int x = 0, int y = 0, int st = 0)\
  :x(x),y(y),st(st){}
};
int f[20][20][1<<8]; //x y bomb treasure
int n, m, object[8][2], cntOfobject, value[8], number[8];
char mp[21][21];
bool valid(int x,int y) {
  return x >= 0 && x < n && y >= 0 && y < m && \
  mp[x][y] == '.' || mp[x][y] == 'S';
}
int get(int x,int y,int ny,int st) {
  for(int i = 0; i < cntOfobject; i++) {
    if(x > object[i][0] && (y == object[i][1] && \
      ny > object[i][1] || ny == object[i][1]\
      && y > object[i][1])) st ^= 1 << i;
  }
  return st;
}
int dx[] = {1,0,0,-1};
int dy[] = {0,1,-1,0};
int bfs(int sx,int sy) {
  std::queue<node> Q;
  memset(f,-1,sizeof(f));
  Q.push(node(sx, sy, 0));
  f[sx][sy][0] = 0;
  while(!Q.empty()) {
    node fr = Q.front(); Q.pop();
    for(int i = 0; i < 4; i++) {
      int tx = fr.x + dx[i];
      int ty = fr.y + dy[i];
      if(valid(tx, ty)) {
        int newst = get(tx, ty, fr.y, fr.st);
        if(f[tx][ty][newst] == -1) {
          f[tx][ty][newst] = f[fr.x][fr.y][fr.st] + 1;
          Q.push(node(tx, ty, newst));
        }
      }
    }
  }
  int ans = 0;
  for(int i = 0; i < (1<<cntOfobject); i++) if(f[sx][sy][i] != -1){
    bool bomb = false;
    int sum = 0;
    for(int j = 0; j < cntOfobject; j++) if(i >> j & 1){
      if(number[j] != -1) sum += value[number[j]];
      else bomb = true;
    }
    if(bomb) continue;
    ans = std::max(ans, sum - f[sx][sy][i]);
  }
  return ans;
}
int main() {
  scanf("%d%d",&n,&m);
  int sx, sy, mx = 0;
  for(int i = 0; i < n; i++) {
    scanf("%s",mp[i]);
    for(int j = 0; j < m; j++) {
      if(mp[i][j] >= '1' && mp[i][j] <= '8' || mp[i][j] == 'B') {
        object[cntOfobject][0] = i;
        object[cntOfobject][1] = j;
        if(mp[i][j] == 'B') {
          number[cntOfobject] = -1;
        } else
        number[cntOfobject] = mp[i][j] - '1',\
                     mx = std::max(mx,mp[i][j]-'0');
        cntOfobject++;
      }
      if(mp[i][j] == 'S') {
        sx = i;
        sy = j;
      }
    }
  }
  for(int i = 0; i < mx; i++) scanf("%d",&value[i]);
  printf("%d\n",bfs(sx, sy));
  return 0;
}

```
*****

## F
### Problem description
> 给你一棵树，每个节点有一个颜色，再给你几个询问，求以v为根的子树中有多少种颜色出现次数大于等于k。

### Solution
>
- 通过dfs序将每个询问转化为区间询问，再用莫队，维护每个颜色的出现次数和出现次数大于等于k的颜色种类数。
- 启发式合并,每个节点用一个平衡树保存每个颜色出现了几次，再用一个平衡树保存出现次数为为i的节点有多少个,合并子树信息的时候暴力的把小的往大的上面并,每个点最多被合并log次（极限情况，每次两个块大小都是相同的，每次总大小会扩大两倍）复杂度nlogn^2

### Code
```cpp
int n, m, i, j, a, b, pos[100005], color[100005];
int e[200005], succ[200005], last[200005], sum;
int Left[200005], Right[200005], s[200005], val[200005], ans[200005], Ans[200005], tot;

struct Query
{
	int l, r, v, tag;
	
	friend bool operator < (Query a, Query b)
	{
		return (pos[a.l] < pos[b.l] || (pos[a.l] == pos[b.l] && a.r < b.r));
	}
}Q[100005];

void dfs(int i, int f);
void add(int val);
void del(int val);

int main()
{
	scanf("%d %d", &n, &m);
	for (i = 1; i <= n; i++)
		scanf("%d", &color[i]);
	for (i = 1; i < n; i++)
	{
		scanf("%d %d", &a, &b);
		e[++sum] = b, succ[sum] = last[a], last[a] = sum;
		e[++sum] = a, succ[sum] = last[b], last[b] = sum;
	}
	
	for (i = 1; i <= n; i++)
		pos[i] = pos[i - 1] + (i % Size == 1);
	dfs(1, 0);
	for (i = 1; i <= m; i++)
		scanf("%d %d", &a, &b), Q[i].l = Left[a], Q[i].r = Right[a], Q[i].v = b, Q[i].tag = i;
	sort(Q + 1, Q + m + 1);
	for (i = Q[1].l; i <= Q[1].r; i++)
		add(val[i]);
	for (i = 1; i <= m; i++)
	{
		if (i != 1)
		{
			int l1 = Q[i - 1].l, r1 = Q[i - 1].r, l2 = Q[i].l, r2 = Q[i].r;
			if (l1 < l2)
			{
				for (j = l1; j < l2; j++)
					del(val[j]);
			}
			
			else
			{
				for (j = l2; j < l1; j++)
					add(val[j]);
			}
			
			if (r1 < r2)
			{
				for (j = r1 + 1; j <= r2; j++)
					add(val[j]);
			}
			
			else
			{
				for (j = r2 + 1; j <= r1; j++)
					del(val[j]);
			}
		}
		
		ans[Q[i].tag] = Ans[Q[i].v];
	}
	
	for (i = 1; i <= m; i++)
		printf("%d\n", ans[i]);
	return 0;
}

void dfs(int i, int f)
{
	int x;
	Left[i] = ++tot;
	val[tot] = color[i];
	for (x = last[i]; x != 0; x = succ[x])
		if (e[x] != f)
			dfs(e[x], i);
	Right[i] = tot;
}

void add(int val)
{
	s[val]++, Ans[s[val]]++;
}

void del(int val)
{
	Ans[s[val]]--, s[val]--;
}
```
```cpp
#define _sz(x) (int)x.size()

int const N = 1e5+20;
int n, q, c[N], x[N], y[N], res[N];
vector <int> g[N], vec[N];
map <int, int> mp[N], cnt[N];

void dfs (int v, int par = -1){
  	mp[v][c[v]] = 1, cnt[v][1] = 1;
	for (int u: g[v]){
		if (u == par) continue;
		dfs(u, v);
		if (_sz(mp[u]) > _sz(mp[v])) mp[u].swap(mp[v]), cnt[u].swap(cnt[v]);
		for (map<int, int>::iterator it = mp[u].begin(); it != mp[u].end(); it ++){
		  	int C = it->first;
			while (mp[u][C]--){
				mp[v][C]++;
				cnt[v][mp[v][C]]++;
			}
		}
	}

	for (int x: vec[v]) res[x] = cnt[v][y[x]];
}


int main(){
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n >> q;
	for (int i = 0; i < n; i ++) cin >> c[i];
	for (int i = 0, u, v; i < n-1; i ++)
	  	cin >> u >> v, u--, v--, g[u].push_back(v), g[v].push_back(u);
	for (int i = 0; i < q; i++) cin >> x[i] >> y[i], x[i]--, vec[x[i]].push_back(i);

	dfs(0);

	for (int i = 0; i < q; i ++) cout << res[i] << '\n';
}
```
*****

## G
### Problem description
> 给你500个点的树，每个点的颜色要么红，要么黑，一次交换可以互换两个节点的颜色，现在问你最少交换多少次，使得每个点距离范围x以内都至少有一个黑点

### Solution
> 转换一下题意就是用所有的黑点控制整棵树所有的点，一个黑点能控制一个点的条件是他们的距离<= x，考虑树dp f[i][j][k]：i子树内的所有点都被控制好了，有j个黑点，i这个点被k控制的最小代价，转移的时候枚举子节点是不是跟自己共用一个控制点，类似于背包合并去转移即可 复杂度O (n ^ 3)

### Code
```cpp
const int N = 505;
int firstEdge[N], nextEdge[N*2], pointTo[N*2], weight[N*2];
short f[N][N][N];
int tmp[N][N], best[N][N], totEdge;
void addEdge(int from,int to,int wi) {
    weight[totEdge] = wi;
    pointTo[totEdge] = to;
    nextEdge[totEdge] = firstEdge[from];
    firstEdge[from] = totEdge++;
}
int n, son[N], x;
int totBlack, dis[N][N], col[N];
inline void checkmin(int &x,int y) {
    if(x == -1 || y < x) x = y;
}
void dfs(int u,int fa) {
    son[u] = 1; std::vector<int> children;
    for(int e = firstEdge[u]; e != -1; e = nextEdge[e]) {
        if(pointTo[e] != fa) {
            dfs(pointTo[e], u);
            son[u] += son[pointTo[e]];
            children.push_back(pointTo[e]);
        }
    }
    int sz = (int)children.size();
    for(int who = 0; who < n; who++) {
        if(dis[u][who] > x) continue;
        for(int i = 0; i <= sz; i++)  {
            for(int j = 0; j <= son[u]; j++) {
                tmp[i][j] = -1;
            }
        }
        tmp[0][0] = 0; tmp[0][1] = 0;
        int totSon = 1;
        for(int i = 0; i < sz; i++) {
            int child = children[i];
            for(int j = 0; j <= totSon && j <= totBlack; j++) {
                for(int k = 0; k <= son[child] && k + j <= totBlack; k++) {
                    if(tmp[i][j] != -1) {
                        if(f[child][k][who] != -1) {
                            checkmin(tmp[i + 1][j + k], tmp[i][j] + f[child][k][who]);
                        }
                        if(best[child][k] != -1) {
                            checkmin(tmp[i + 1][j + k], tmp[i][j] + best[child][k]);
                        }
                    }
                }
            }
            totSon += son[child];
        }
        for(int i = 0; i <= son[u]; i++) {
            f[u][i][who] = tmp[sz][i];
        }
    }
    for(int i = 0; i <= son[u] && i < totBlack; i++) {
        best[u][i+1] = -1;
        for(int who = 0; who < n; who++) {
            if(f[u][i][who] != -1) checkmin(best[u][i+1], f[u][i][who] + (col[who] != 1));
        }
    }
}
void bfs(int s) {
    std::queue<int> Q; 
    static bool vis[N]; memset(vis, false, sizeof(vis));
    static int d[N];
    Q.push(s);
    vis[s] = true; d[s] = 0;
    while(!Q.empty()) {
        int fr = Q.front(); Q.pop(); 
        for(int e = firstEdge[fr]; e != -1; e = nextEdge[e]) {
            if(!vis[pointTo[e]]) {
                vis[pointTo[e]] = true;
                d[pointTo[e]] = dis[s][pointTo[e]] = std::min(d[fr] + weight[e], x + 1);
                Q.push(pointTo[e]);
            }
        }
    }
}
int main() {
    scanf("%d%d",&n,&x);
    for(int i = 0; i < n; i++) {
        scanf("%d",&col[i]);
        totBlack += col[i];
    }
    memset(firstEdge,-1,sizeof(firstEdge));
    memset(best, -1, sizeof(best));
    memset(f, -1, sizeof(f));
    for(int i = 1, a, b, c; i < n; i++)  {
        scanf("%d%d%d",&a,&b,&c);
        a--; b--;
        addEdge(a, b, c);
        addEdge(b, a, c);
    }
    for(int i = 0; i < n; i++) {
        bfs(i);
    }
    dfs(0, -1);
    // printf("%d\n",f[8][0][5]);
    printf("%d\n",best[0][totBlack]);
    return 0;
}

```