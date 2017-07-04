# Solution of Contest14
[VJudge链接](https://cn.vjudge.net/contest/168561)\
[CodeForces链接](http://codeforces.com/contest/716)
## #A Crazy Computer
### Description & Solution
给出一串数，按顺序处理每个数，用计数器累计个数，当两个数之间的间隔大于一个给定的数c时，计数器清零。求最后计数器记录的个数。
### Code
```Cpp
ans=0;
lst=0;
scanf("%d%d",&n,&c);
for(int i=1,j;i<=n;i++) {
    scanf("%d",&j);
    if(j-lst>c) ans=0;
    ans+=1;
    lst=j;
}
printf("%d\n",ans);
```
***
## #B Complete the Word
### Description
输入一个缺失部分信息的字符串，仅由大写英文字母和代表缺失的`?`号构成，要求填满其中的缺失部分，使其存在一个长度26位的连续子串，其中26个字母刚好各出现一次。
### Solution
字串长度在50000以内，大可以暴力修改。
### Code
```Cpp
void check(int x) { //判断字串中从第x位开始的子串是否满足要求
    int f[30];
    for(int i=0;i<=30;i++) f[i]=0;
    for(int i=x;i<=x+25;i++) {
        if(s[i]!='?') {
            f[s[i]-'A']++;
            if(f[s[i]-'A']>1) return;
        }
    }
    int j=0;
    for(int i=x;i<=x+25;i++) {
        if(s[i]=='?') {
            while(f[j]>0) j++;
            s[i]=(char)(j+'A');
            f[j]++;
        }
    }
    print(); //输出
}
```
***
## #C Plus and Square Root
### Description
一个等级制的小游戏，初始等级为1，有一个初始值为2的数字K。现在有两种操作，一是给数字K加上当前等级数；二是给数字K开方，并使等级上升一级。但操作二有两个要求，一个是当前的K是一个完全平方数，另一个是平方之后得到的数必须是下一等级数的倍数。现在给出一个等级数N，求使其达到N+1级的操作方法。只需输出每个等级中在对K开方之前做加法的次数。
### Solution
一道典型的数论题（结论题），理清楚题意后可以得到两个关系 ```①a[i]+ans[i]*i = a[i+1]^2 ②a[i] mod i = 0```
因为第i个答案为ans[i],因此将第一个式子变形为 ```ans[i] = (a[i+1]^2 - a[i]) / i```
这个式子说明只要能满足```a[i] mod i = 0```和```a[i+1]^2 mod i = 0```的数列a[i]都能用来构造答案数列，我们可以令```a[i] = i * (i-1)```
因此答案```ans[i] = (i+1)^2*i-i+1```, 同时要注意按照这种方式构造的数列ans[1]并不满足，因此特判后进行计算即可
### Code
```Cpp
cout << 2 << endl;
for (long long i=2;i<=n;++i){
  cout << i*(i+1)*(i+1) - i + 1 << endl; 
}
```
***
## #D Complete The Graph
### Description
给出一个边权为整数的无向图，其中一些边的权值被擦除了（边权以0表示）。再给出起点S和终点T，要求给所有的被擦除的边赋上大于0的权值，使得S到T的最短路总权值恰好为L。
### Solution   
#### NO的判断方法   
如果把所有边的权值设为1仍然大于L或者所有边都为INF仍然小于L，那就是不存在的，道理细细琢磨  
#### 判断YES的办法   
##### ● 解法一(最暴力的方法)
初始可变边边权都设为1，跑一遍最短路，记最短路长度为D。枚举每一条可变边，将其权指改为L-D-1，再跑一遍最短路更新D，若D=L则出解。O(MMlogM）
##### ● 解法二(比较巧妙的二分)
先将所有可变边从图中删除(设为INF)，若最短路小于L则无解。接下去如果一条一条地添加可变边（边权为1）并更新最短路，则总会出现一条特殊的边，当你添加的它的时候会使得最短路<L，我们称其为关建边。记添加后最短路为dis,则只需修改该边边权为L-dis-1。即可出解，否则若找不到该边，则无解。
添加边的过程我们应该用二分来。O(MlogMLogM）
##### ● 解法三(更为巧妙的办法)
初始可变边边权都设为1，我们先跑一次从终点到各个顶点的最短路，求出终点到各个点的距离，设为d[x,t]  
然后再从出发点跑一边最短路，过程中更新可变边权值，设这边的两个端点为x/y,让他等于L-d[s,x]-d[y,t]。于是我们在增大边权的时候，就构造了一条权值始终大于等于L的路。
当所有可变边更新完毕后若d[s,t]=L则出解,否则无解。(MlogM)
***
## #E Digit Tree
### Description
给你一颗树，求有序点对(x,y)的个数，使得x->y的路径上的数字连起来的数是m的倍数, gcd(10, m) = 1
### Data Limit: n <= 1e5 m <= 1e9

### Solution
树分治知识介绍参考[分治算法在树的路径中的应用](https://wenku.baidu.com/view/1bc2e4ea172ded630b1cb602.html)。

重心是一颗树的这样一个点，他的最大的儿子的数量小于总点数的一半，之后我们再去递归每一个儿子，规模都减小了至少一半,层数最多为log

树分治的核心在于合理的暴力枚举了所有的路径，类似于莫队算法调整询问顺序，树分治则是合理的枚举了所有点对的LCA（即重心），枚举完以当前重心为LCA的路径后就递归去进行LCA在各个子树的枚举。下层的重心与上层的重心之间形成了一颗有向的重心树。无向之中有有向！
这个题考虑计算经过当前重心的路径，算从前面子树的点到当前子树的点构成的路径，假设当前根到当前子树的某个点的数字连起来对m取模为val,那么假设前面的点到根的数字为x那么(x * 10 ^ L + val ) % m = 0, x = -val * inv(10^L), L为当前子树某个点的深度, 预处理逆元，可以算出这个x只有唯一一个正整数解，那么就统计一下前面出现了几个x就行了，但是这样做会漏掉后面子树到当前子树的路径，所以还要反着做一遍，从最后一个子树到第一个子树。
```cpp
#include <bits/stdc++.h>
const int N = 100010;

//#define wuyiqi
int mx[N], n, solved[N], queue[N], parent[N], size[N];

int MOD;
std::vector <std::pair<int, int> > edge[N];
int val[N];
std::vector <int> num, all_num;
int inv[N];
long long ret;
int ten[N];

struct HashTable {
    static const int P = 1111117;
    int head[P], nxt[P], pnt[P], E, cnt[P];
    void Init () {
        E = 0;
        memset(head, -1, sizeof(head));
    }
    int Insert(int num) {
        int p = num % P;
        for (int i = head[p];~i ; i = nxt[i]) {
            if(pnt[i] == num) {
                cnt[i]++;
                return p;
            }
        }
        cnt[E] = 1;
        pnt[E] = num;
        nxt[E] = head[p];
        head[p] = E++;
        return p;
    }
    int Find(int num) {
        int p = num % P;
        for (int i = head[p]; ~i; i = nxt[i]) {
            if(pnt[i] == num) {
                return cnt[i];
            }
        }
        return 0;
    }
}hash_table;

int Bfs(int root, int fa) {
    int head = 0, tail = 0;
    queue[tail++] = root;
    parent[root] = fa;
    while(head < tail) {
        int u = queue[head++];
        for(auto to : edge[u]) {
            int v = to.first;
            if(v != parent[u] && !solved[v]) {
                queue[tail++] = v;
                parent[v] = u;
            }
        }
    }
    return tail;
}

int GetRoot(int root, int &sz) {
    int tail = Bfs(root, -1);
    for(int i = 0; i < tail; i++) {
        int u = queue[i];
        size[u] = mx[u] = 1;
    }
    for(int i = tail - 1; i >= 1; i--) {
        int u = queue[i];
        size[parent[u]] += size[u];
        mx[parent[u]] = std::max(mx[parent[u]], size[u]);
    }
    for(int i = 0; i < tail; i++) {
        int u = queue[i];
        mx[u] = std::max(mx[u], tail - size[u]);
        if(mx[u] < mx[root]) {
            root = u;
        }
    }
    sz = tail;
    return root;
}

void Go (bool first, int u, int fa, int val, int val_up, std::vector<int> &num, int depth) {
    int x = (1LL * (MOD - val) * inv[depth] % MOD);
#ifdef wuyiqi 
    printf ("u=%d val=%d mp[%d] = %d\n", u, val, x, mp[x]);
#endif
    ret += hash_table.Find(x);
    if(val == 0 && first) {
        ret++;
    }
    num.emplace_back(val_up);
    for (auto to : edge[u]) {
        int v = to.first;
        int w = to.second;
        if (solved[v] || v == fa) {
            continue;
        }
        Go (first, v, u, (1LL * val * 10 % MOD + w) % MOD, (val_up + 1LL * ten[depth] * w % MOD) % MOD ,num, depth + 1);
    }
}

void Solve(int u) {
    int sz = -1;
    int root = GetRoot(u, sz);
    solved[root] = 1;
    for (auto to: edge[root]) {
        int v = to.first;
        int w = to.second;
        if (solved[v]) {
            continue;
        }
        num.clear();
        Go (1, v, root, w%MOD, w%MOD, num, 1);
        for (int value : num) {
            int t = hash_table.Insert(value);
            
            all_num.emplace_back(t);
        }
    }
    for (int value : all_num) {
        hash_table.head[value] = -1;
    }
    hash_table.E = 0;
    all_num.clear();
    for (int i = edge[root].size() - 1; i >= 0; i--) {
        int v = edge[root][i].first;
        int w = edge[root][i].second;
        if(solved[v]) {
            continue;
        }
        num.clear();
        Go (0, v, root, w%MOD, w%MOD, num, 1);
        for (int value : num) {
            int t = hash_table.Insert(value);
            all_num.emplace_back(t);
            if (value == 0) {
                ret++;
            }
        }
    }
    for (int value : all_num) {
        hash_table.head[value] = -1;
    }
    hash_table.E = 0;
    all_num.clear();
#ifdef wuyiqi 
    printf("root=%d ret=%d\n", root, ret);
#endif
    for (auto to : edge[root]) if(!solved[to.first]){
        Solve(to.first);
    }
}

void ExtendGcd(int a, int b, int &x, int &y) {
    if (b) {
        ExtendGcd(b, a % b, x, y);
        x -= (a / b) * y;
        std::swap(x, y);
    } else {
        x = 1; y = 0;
    }
}

int main () {
    hash_table.Init();
    int x, y;
    int u, v, w;
    scanf("%d%d", &n, &MOD);
    ExtendGcd(10, MOD, inv[1], y);
    inv[1] = (inv[1] % MOD + MOD) % MOD;
    for (int L = 2; L <= n; L++) {
        inv[L] = 1LL * inv[L - 1] * inv[1] % MOD;
    }
    ten[0] = 1;
    for (int i = 1; i <= n; i++) {
        ten[i] = 1LL * ten[i - 1] * 10 % MOD;
    }
    for (int i = 1; i < n; i++) {
        scanf("%d%d%d", &u, &v, &w);
        edge[u].emplace_back(v, w);
        edge[v].emplace_back(u, w);
    }
    Solve(0);
    printf("%lld\n", ret);
    return 0;
}

```
