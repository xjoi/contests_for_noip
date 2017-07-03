# Solution of Contest#015
```
    VJudge链接：  https://cn.vjudge.net/contest/168929
CodeForces链接：  http://codeforces.com/contest/787

题目按CF顺序排序
```
## #A The Monster
```
    VJudge链接：  https://cn.vjudge.net/contest/168929#problem/A
CodeForces链接：  http://codeforces.com/contest/787/problem/A

      时间限制：  1000ms
      空间限制：  256MB
      主要算法：  模拟
      数据范围：  1≤a,b,c,d≤100
      完成时间：  赛时
```
### Description
有俩人一边跑一边**尖叫**，一个人在`b`,`b+a`,`b+2a`...的时刻尖叫，另一人在`d`,`d+c`,`d+2c`...的时刻尖叫，问何时两人能同时尖叫，无解输出-1。
### Solution
数据小嘛，而且又是A题，果断暴力。

正常一点的解法就是扩展欧几里得了。

这个问题可以转化为求两个未知数![](http://chart.googleapis.com/chart?cht=tx&chl=x)和![](http://chart.googleapis.com/chart?cht=tx&chl=y)，使得方程![](https://ooo.0o0.ooo/2017/07/03/595a2667c0087.png)成立。上述方程又可化为![](http://chart.googleapis.com/chart?cht=tx&chl=ax-cy=d-b)，就可以直接用扩欧做了，最后的答案就是![](https://ooo.0o0.ooo/2017/07/03/595a26af5d243.png)的值。
### Code
```Cpp
while(n!=m&&ans<2e7) {
    if(n<m) n+=a;
    else m+=b;
    ans++;
}
//最后n即为答案
```
***
## #B Not Afraid
```
    VJudge链接：  https://cn.vjudge.net/contest/168929#problem/B
CodeForces链接：  http://codeforces.com/contest/787/problem/B

      时间限制：  2000ms
      空间限制：  256MB
      主要算法：  暴力
      数据范围：  1≤n,m≤1e4
      完成时间：  赛时
```
### Description
有n个平行宇宙，每个宇宙都有一个Rick和一个Morty，其中一个是叛徒，另一个是忠诚的，每个宇宙的情况不相同而且都未知。现在有m个横跨这些宇宙存在的小组，每个小组由来自各个宇宙的Rick和Morty组成，其中可能有重复。问有没有可能有至少一个小组的成员全部是叛徒。

数据中负数代表Rick，正数代表Morty，其绝对值代表来源宇宙的编号。
### Solution
其实很简单，如果要使一个小组全部是叛徒，那么可以发现同一个宇宙中的Rick和Morty不能待在同一个小组里，因为他们中必定有一个忠诚的人。所以我们只要对每一个小组判断是否存在一对相反数即可，如果存在那么这个小组一定不会全是叛徒。
### Code
```Cpp
//check函数，判断小组有没有可能全是叛徒
bool check(int x,int y) {
    int f[40010];
    for(int i=0;i<=2*n;i++) f[i]=0;
    for(int i=x;i<=y;i++) {
        f[a[i]+n]++;
        if(f[n-a[i]]>0) return false;
    }
    return true;
}
```
***
## #C Berzerk
```
    VJudge链接：  https://cn.vjudge.net/contest/168929#problem/C
CodeForces链接：  http://codeforces.com/contest/787/problem/C

      时间限制：  4000ms
      空间限制：  256MB
      主要算法：  博弈论 DP
      数据范围：  2≤n≤7000，1≤k≤n-1，1≤x≤n-1
      完成时间：  赛后
```
### Description
一个博弈的小游戏，有n-1个星球和1个黑洞排成一个圈，黑洞编号为1，其他星球顺时针从小到大编号。有一只怪兽（可以理解为棋子），初始时停留在编号不为1的位置上（即不在黑洞上）。两位玩家各含有一个由正整数组成的集合（大小分别为k1,k2），每个玩家轮流游戏，每轮可以选择一个自己集合中的数字x，使得怪兽顺时针（即按数字增大方向）移动x个位置。当某个人操作后怪兽**停留**在了黑洞（编号为1）处，则这个人可以赢得游戏。

最后要求的是，当怪兽处于2~n位置时、两位玩家分别先手时，先手有必胜策略（输出`Win`）、必输（输出`Lose`）还是可以陷入无限循环（输出`Loop`）。如果先手面临输和循环两种结局，那么输出循环`Loop`。
### Solution
考虑一种局面，当由该轮玩家操作后，可以引出另k个局面。可以发现如果这k个局面中存在至少一个局面对手必输，那么这个局面就有必胜策略；反之，如果这k个局面对手全部存在必胜策略，那么这个局面是必输的。

那么对每一个新产生的有定论的局面跑一边判断所牵连局面是否有必胜策略或是必输即可。跑完全部过程后，仍未下定论的局面就会陷入循环。
### Code
```Cpp
//局面(i,j)表示在位置i，此时轮到j操作的局面
//f[i][j]表示局面(i,j)的结论。1表示有必胜策略，-1表示必输，0表示未定

void work2(int x,int y) { //局面(x,y)必输
    f[x][y]=-1;
    int op=1-y;
    for(int i=1;i<=m[op];i++) {
        int u=(x-a[i][op]+n)%n;
        if(f[u][op]!=1) {
            f[u][op]=1;
            if(u!=0) work1(u,op);
        }
    }
}

void work1(int x,int y) { //局面(x,y)有必胜策略
    int op=1-y;
    for(int i=1;i<=m[op];i++) {
        int u=(x-a[i][op]+n)%n;
        g[u][op]++; //g[i][j]表示局面(i,j)所引申出的局面中对手存在必胜策略的局面个数
        if(g[u][op]==m[op]&&f[u][op]==0&&u!=0) work2(u,op);
    }
}
```
***
## #D Legacy
```
    VJudge链接：  https://cn.vjudge.net/contest/168929#problem/D
CodeForces链接：  http://codeforces.com/contest/787/problem/D

      时间限制：  2000ms
      空间限制：  256MB
      主要算法：  最短路 数据结构
      数据范围：  1≤n,q≤1e5
      完成时间：  赛后
```
### Description
给出一个n个节点的**有向图**，求某点到其他各个点的最短路。

边的类型有三种：

> `1 u v w`：从点u到点v有一条权值为w的边 <br>
> `2 u x y w`：从点u到区间[x,y]内的点都有一条权值为w的边 <br>
> `3 u x y w`：从区间[x,y]内的点到点u都有一条权值为w的边 <br>

这些“边”共有q个。

### Solution
对于1操作，并无大碍；

对于2操作，考虑一种数据结构，使连边时可以直接连到某几个区间而不需要暴力连接每一个点。可以想到线段树是比较适合的。建树的时候从每个父节点到其子节点连一条权值为0的边。这样在处理加边操作时就可以直接连到覆盖的区间节点；

对于3操作，和2操作相同，需要另建一颗线段树，从子节点向父节点连边。
在两棵线段树中，对应叶子结点应该相连。1操作可以直接在这些叶子节点中连边。
最后跑一遍dijkstra出答案。

### Code
```Cpp
int find(int rt,int l,int r,int x) { //找到第i个节点在线段树中的位置
    if(l==r) return rt;
    int mid=(l+r)/2;
    if(x<=mid) return find(rt*2,l,mid,x);
    if(mid<x) return find(rt*2+1,mid+1,r,x);
}

void work(int rt,int l,int r,int x,int y,int s,ll w,int ty) {
    if(x<=l&&r<=y) {  //如果覆盖直接连边
        if(ty==1||ty==2) addE(s,rt,w);
        else addE(rt+sht,s+sht,w);
        return;
    }
    int mid=(l+r)/2;
    if(x<=mid) work(rt*2,l,mid,x,y,s,w,ty);
    if(mid<y) work(rt*2+1,mid+1,r,x,y,s,w,ty);
}
```
***
## #E Till I Collapse
```
    VJudge链接：  https://cn.vjudge.net/contest/168929#problem/D
CodeForces链接：  http://codeforces.com/contest/787/problem/D

      时间限制：  2000ms
      空间限制：  256MB
      主要算法：  数据结构（主席树） 二分
      数据范围：  1≤n≤1e5
      完成时间：  赛后
```
### Description
给出一个n个正整数组成的数列，需要将其分割为尽量少个区间，使每个区间内的不同的数字个数不超过k。

求当k取1~n内每个值时可分割的最少区间数。
### Solution
**解法1：玄学二分**

直接对k的取值区间进行二分。每次计算k取两个端点值时的答案，如果两答案相同，那个这段区间答案全部相同；否则递归计算这段区间的左右两部分。居然不会T啊233。

**解法2：标算主席树**

主席树，又叫可持久化线段树。
然后等我深入理解了再来补充【逃
### Code
解法一：

```Cpp
int check(int k) { //check当k取某值时可分割的最少区间数。贪心即可
    int f[100010],tmp=1,x=0;
    memset(f,0,sizeof f);
    for(int i=1;i<=n;i++) {
        if(f[a[i]]==tmp) continue;
        f[a[i]]=tmp;
        x++;
        if(x>k) {
            x=1;
            tmp++;
            f[a[i]]=tmp;
        }
    }
    return tmp;
}
```