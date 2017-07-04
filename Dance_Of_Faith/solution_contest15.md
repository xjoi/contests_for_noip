# Solution Of Contest15


[比赛链接 VJ](https://vjudge.net/contest/168929)

[Origin](http://codeforces.com/contest/787)

------------------------------

## A -The Monster
### Problem Description
> 有俩人一边跑一边尖叫，一个人在b,b+a,b+2a...的时刻尖叫，另一人在d,d+c,d+2c...的时刻尖叫，问何时两人能同时尖叫，无解输出-1。

* Data Limit: 1<=N<=100
* Time Limit: 1s
* Memory Limit: 256MB
* Main Solution: 模拟/ExtGcd

### Solution
> 简单的方法：模拟与暴力。每次枚举一个人叫的时间判断此时另一个人是否在叫。
> 正解：扩展欧几里得。

### Code

```cpp
#define int long long
using namespace std;
main(){
	int a,b,c,d;cin >>a>>b>>c>>d;
	if (b<d) swap(b,d),swap(a,c);
	for (int i=0;i<=20000000;++i)
		if ((b+a*i-d)%c==0) return 0*printf("%d\n",b+a*i);
	return 0*puts("-1");
}
```

-----------------------

## B -Not Afraid
### Problem Description
> 有n个平行宇宙，每个宇宙都有一个Rick和一个Morty，其中一个是叛徒，另一个是忠诚的，每个宇宙的情况不相同而且都未知。现在有m个横跨这些宇宙存在的小组，每个小组由来自各个宇宙的Rick和Morty组成，其中可能有重复。问有没有可能有至少一个小组的成员全部是叛徒。数据中负数代表Rick，正数代表Morty，其绝对值代表来源宇宙的编号。

* Data Limit: 1<=N<=10000
* Time Limit: 2s
* Memory Limit: 256MB
* Main Solution: 模拟


### Solution
> 其最终目的在于找出一场party中是否存在一组相反数。如果存在，可以保证此party是安全的，否则就要取消了。
> 用f记录一个数的出现，负数可以用+N来变正。如果存在了f[j]&&f[2*N-j]，则表示正负数都出现了。

### Code
```cpp
int main(){
	int n,m,k,x;cin >>n>>m;
	for (int i=1;i<=m;++i){
		scanf("%d",&k);bool ff=0;memset(f,0,sizeof(f));
		for (int j=1;j<=k;++j) scanf("%d",&x),f[N+x]=1;
		for (int j=1;j<=N;++j)
			if (f[j]&&f[2*N-j]) {ff=1;break;}
		if (!ff) return puts("YES")*0;
	}return puts("NO")*0;
}
```

-------------------------------

## C -Berzerk
### Problem Description
> 一个博弈的小游戏，有n-1个星球和1个黑洞排成一个圈，黑洞编号为1，其他星球顺时针从小到大编号。有一只怪兽（可以理解为棋子），初始时停留在编号不为1的位置上（即不在黑洞上）。两位玩家各含有一个由正整数组成的集合（大小分别为k1,k2），每个玩家轮流游戏，每轮可以选择一个自己集合中的数字x，使得怪兽顺时针（即按数字增大方向）移动x个位置。当某个人操作后怪兽停留在了黑洞（编号为1）处，则这个人可以赢得游戏。
> 最后要求的是，当怪兽处于2~n位置时、两位玩家分别先手时，先手有必胜策略（输出Win）、必输（输出Lose）还是可以陷入无限循环（输出Loop）。如果先手面临输和循环两种结局，那么输出循环Loop。

* Data Limit: 1<=N<=7000
* Time Limit: 4s
* Memory Limit: 256MB
* Main Solution: 博弈/广搜


### Solution
> 可以定义f[i][j]表示第i个人且怪兽在j位置时第i人的输赢情况。
> 而通过一些确定的定局能推出其他的定局：
> 1. 如果某个局势对于一人是必败的，那另一人对于能够一部走到该局势的状态都是必胜的。
> 2. 如果存在某一局势，是得此人怎么走到达的都是对方的必胜局势，则该局势是必败的。（至于这是怎么实现的，可以从某个对方必胜局势推到的自己输的时候，就将自己输时的状态的度加一，当度达到自己能走的方案数是就是必输无疑了）
> 
> 首先知道了两个必败结局：第一个人先手且怪物在1位置、第二个人先手且怪物在1位置。由此局势可以推出所有能确定的局势。

### Code
```cpp
#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
using namespace std;
const int N=8000;
int d[N][5],f[N][5],k[5],s[5][N];
struct XY{int p;bool d;};

int main(){
	int n;cin >>n;
	scanf("%d",&k[0]);for (int i=1;i<=k[0];++i) scanf("%d",&s[0][i]);
	scanf("%d",&k[1]);for (int i=1;i<=k[1];++i) scanf("%d",&s[1][i]);
	
	queue<XY> Q;f[1][0]=f[1][1]=-2;
	Q.push(XY{1,0});Q.push(XY{1,1});
	while (!Q.empty()){
		XY now=Q.front(),nxt;Q.pop();
		nxt.d=now.d^1;
		for (int i=1;i<=k[nxt.d];++i){
			nxt.p=now.p-s[nxt.d][i];
			if (nxt.p<1) nxt.p+=n;
			if (f[now.p][now.d]==-2){
				if (f[nxt.p][nxt.d]!=-1) f[nxt.p][nxt.d]=-1,Q.push(nxt);
			}else
			if (f[now.p][now.d]==-1){
				if (f[nxt.p][nxt.d]<0) continue;
				++d[nxt.p][nxt.d];
				if (d[nxt.p][nxt.d]==k[nxt.d]) f[nxt.p][nxt.d]=-2,Q.push(nxt);
			}
		}
	}
	
	for (int i=2;i<=n;++i)
		if (f[i][0]==-1)printf("Win ");else if (f[i][0]==-2)printf("Lose ");else printf("Loop ");
	printf("\n");
	for (int i=2;i<=n;++i)
		if (f[i][1]==-1)printf("Win ");else if (f[i][1]==-2)printf("Lose ");else printf("Loop ");
	printf("\n");return 0;
}
```

-------------------

## D -Legacy
### Problem Description
> 给出一个n个节点的有向图，求某点到其他各个点的最短路。
> 边的类型有三种：
> 1. u v w：从点u到点v有一条权值为w的边 
> 2. u x y w：从点u到区间[x,y]内的点都有一条权值为w的边 
> 3. u x y w：从区间[x,y]内的点到点u都有一条权值为w的边 
> 这些“边”共有q个。

* Data Limit: 1<=N<=100000
* Time Limit: 2s
* Memory Limit: 256MB
* Main Solution: 线段树/最短路


### Solution
> 由线段树可以维护区间的性质想到：可以用线段树来解决区间与点的边。
> 考虑建立两棵线段树，上面的那棵正立，下面的那棵倒立，将两棵线段树底层的N个点重叠，表示每一个“点”。而在线段树上将所需要的区间分成线段树上的点，表示“区间”。线段树从上顶点到下顶点的所有路径都是从上到下有向边且边权为0；从点到区间的边，应该是从“点”到上线段树的；从区间到点的边，应该是从下线段树到“点”的。最后只要跑一遍dijkstra求出最短路即可。

### Code
```cpp
#include<cstdio>
#include<queue>
#define lson rt<<1
#define rson rt<<1|1
#define int long long
using namespace std;
const int INF=1e15,N=1e5+10;
int vis[N*4],las[N*4],L[N*4],R[N*4],sz=0,tot,S,n,x,y,z,w,flag,q;
struct Edge{int to,w,pre;}e[2000000];
struct Dic{int dis,id;}d[2000000];
struct cmp{bool operator()(Dic &a,Dic &b){return a.dis>b.dis;}};
void add(int a,int b,int c){e[++sz].to=b;e[sz].w=c;e[sz].pre=las[a];las[a]=sz;}

void build(int l,int r,int rt){
	if (l==r){L[rt]=R[rt]=l;return;}
	L[rt]=++tot;R[rt]=++tot; //上下两棵树 
	int mid=(l+r)>>1;
	build(l,mid,lson);build(mid+1,r,rson);
	add(L[rt],L[lson],0);add(L[rt],L[rson],0);
	add(R[lson],R[rt],0);add(R[rson],R[rt],0);
}

void updata(int l,int r,int rt,int v,int Ll,int Rr,int w,int ff){
	if (Ll<=l && r<=Rr){if (ff==2) add(v,L[rt],w);else add(R[rt],v,w);return;}
	int mid=(l+r)>>1;
	if (Ll<=mid) updata(l,mid,lson,v,Ll,Rr,w,ff);
	if (Rr >mid) updata(mid+1,r,rson,v,Ll,Rr,w,ff);
}

void dijkstra(){
	priority_queue<Dic,vector<Dic>,cmp> Q;
	for (int i=0;i<=500000;++i) d[i].dis=INF,d[i].id=i;
	d[S].dis=0;Q.push(d[S]);
	while (!Q.empty()){
		Dic u=Q.top();Q.pop();if (vis[u.id]) continue;
		vis[u.id]=true;
		for (int i=las[u.id];i;i=e[i].pre)
			if (d[e[i].to].dis>u.dis+e[i].w)
				d[e[i].to].dis=u.dis+e[i].w,Q.push(d[e[i].to]);
	}
}

main(){
	scanf("%lld%lld%lld",&n,&q,&S);tot=n;build(1,n,1);
	for (int i=1;i<=q;++i){
		scanf("%lld",&flag);
		if (flag==1){scanf("%lld%lld%lld",&x,&y,&w);add(x,y,w);}
		else{scanf("%lld%lld%lld%lld",&z,&x,&y,&w);updata(1,n,1,z,x,y,w,flag);}
	}
	dijkstra();
	for (int i=1;i<=n;++i) printf("%lld ",d[i].dis==INF? -1:d[i].dis);
	return 0;
}
```

-------------------------

## E -Till I Collapse
### Problem Description
> 给出一个n个正整数组成的数列，需要将其分割为尽量少个区间，使每个区间内的不同的数字个数不超过k。
> 求当k取1~n内每个值时可分割的最少区间数。


* Data Limit: 1<=N<=100000
* Time Limit: 2s
* Memory Limit: 256MB
* Main Solution: 二分/贪心


### Solution
> 事实上，对于很多的K，其答案是相同的。对于一个连续的区间[l,r]，如果在l和r时的答案是一样的，则所有区间内的数的答案都是一样的。对于一个K，可以在O(N)的时间内用贪心求出答案。而可以用二分来枚举区间。

### Code
```cpp
int get(int k){
	int cnt=1,num=0;
	int f[300000];memset(f,0,sizeof(f));
	for (int i=1;i<=n;++i){
		if (f[a[i]]==cnt) continue;
		++num;f[a[i]]=cnt;
		if (num>k) ++cnt,f[a[i]]=cnt,num=1;
	}
	return cnt;
}

void work(int l,int r){
	if (l>r) return;
	int ans1=get(l),ans2=get(r),mid=(l+r)>>1;
	if (ans1==ans2){for (int i=l;i<=r;++i) ans[i]=ans1;return;}
	work(l,mid);work(mid+1,r);
}

int main(){
	scanf("%d",&n);for (int i=1;i<=n;++i) scanf("%d",&a[i]);
	work(1,n);
	for (int i=1;i<=n;++i) printf("%d ",ans[i]);return 0;
}
```

-------------------------------------

