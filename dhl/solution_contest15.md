[比赛链接](http://codeforces.com/problemset/problem/787/A)

# 比赛中解决的问题
## A
### Problem description
> 给定两个一次函数，求相等时最小的值

### Data Limit：n <= 100  Time Limit: 1s

### Solution
> 暴力求出所有符合的数，或者用数学整除直接算出，注意小于的情况

### Code
```cpp
if(d>b){swap(b,d),swap(a,c);}
	for(int i=0;i<=500000;i++)
		if((a*i+b-d==0)||(a*i+b-d)%c==0)
		{cout<<a*i+b<<"\n";return 0;}
		cout<<"-1\n";
```
*****


## B
### Problem description
> 给定一个数列，求之中是否存在至少一对相反数

### Data Limit：n <= 1e4  Time Limit: 2s
### Solution
> 我们用两个数组分别记录positive 和negative ，注意要两个数组，一个会出乱子，然后看这个位置对应的数组是不是1。注意memset

### Code
```cpp
for(int i=1;i<=m;i++)
	{
		int ok=0,k,t1;
		memset(book1,0,sizeof(book1));
		memset(book2,0,sizeof(book2));
		cin>>k;
		for(int i=1;i<=k;i++)
		{
			cin>>t1;
			if(t1<0) book1[0-t1]=1;
			else book2[t1]=1;
		}
		for(int i=1;i<=20000;i++)
			if(book1[i]&book2[i])ok=1;
		if(!ok) {puts("YES");return 0;}
	}
	puts("NO");
```
*****

# 赛后补题

## C
### Problem description
> 给定两个集合，每一个集合对应的是该人可以移动的步数，怪物起始可以在任意点，到达1就获胜，两个人都足够聪明，求怪物起始以及谁先手的胜负情况

### Data Limit：n <= 1e4  Time Limit: 4s

### Solution
> 我们用记忆化搜索，当且仅当一个点的所有情况是必败态，他的后继是必胜态，于是我们枚举所有的情况就可以了

### Code
```cpp
void dfs(int now,int p)
{
	if(f[p][now]) return ;
	f[p][now]=2;
	if(now==0) return ;
	for(int i=0;i<k[!p];i++)
	{
		int lat=(now-v[!p][i]+n)%n;
		Orz_He_Xv[!p][lat]++;
		if(Orz_He_Xv[!p][lat]==k[!p])
		{
			f[!p][lat]=1;
			for(int kk=0;kk<k[p];kk++)
				dfs((lat-v[p][kk]+n)%n,p);
		}
	}
}
```
*****


## D
### Problem description
> 给定一个图，有三类边 u->v u->[l,r],[l,r]->v每一条边都有权值，求单源最短路

### Data Limit：n <= 1e5  Time Limit: 2s
### Solution
> 首先我们要处理区间边的情况，我们建造两颗线段树（有shenben说一颗也可以），然后对应线段树上的区间连边，比如你要连的区间为[1,3]那么你分别向[1,2] [3,3]连边，然后跑一边dij+堆的最短路就可以了

### Code
```cpp
void build(int l,int r,int rt)
{
	if(l==r)
	{
		tr[rt][0]=tr[rt][1]=l;
		return ;
	}
	tr[rt][0]=++tot;
	tr[rt][1]=++tot;
	build(l,mid,ls),build(mid+1,r,rs);
	add(tr[rt][0],tr[ls][0],0),add(tr[rt][0],tr[rs][0],0);
	add(tr[ls][1],tr[rt][1],0),add(tr[rs][1],tr[rt][1],0);
}

void update(int l,int r,int rt,int from,int L,int R,int W,int t)
{
	if(L<=l&&r<=R)
	{
		if(t==2) add(from,tr[rt][0],W);
		else if(t==3) add(tr[rt][1],from,W);
		return ;
	}
	if(L<=mid) update(l,mid,ls,from,L,R,W,t);
	if(R>mid) update(mid+1,r,rs,from,L,R,W,t);
	return ;
}

void dij()
{
	priority_queue<Node> q;
	memset(dis,38,sizeof(dis));
	inf =dis[0];
	dis[s]=0;
	q.push((Node){s,0});
	while(!q.empty())
	{
		Node x=q.top();q.pop();
		if(book[x.p]) continue;
		book[x.p]=1;
		for(int i=head[x.p];i;i=e[i].nxt)
		{
			if(dis[e[i].to]>x.w+e[i].w)
			{
				dis[e[i].to]=x.w+e[i].w;
				q.push((Node){e[i].to,dis[e[i].to]});
			}
		}
	}
}

```
*****
>Ps: dij的continue的部分我写成了return 然后被坑了好久

## E
### Problem description
> 给定颜色序列，求分成最小的连续区间，使得区间内的元素的颜色的种类小于k(1<=k<=n)

### Data Limit：n <= 1e5  Time Limit: 2s

### Solution
> 我的是暴力做法，我们通过实践可以发现，如果存在一个l,r，他们的答案是相同的，那么他们之间的答案也是相同的，我们就可以进行二分区间然后暴力求解啦//
>正解貌似是主席树（？？？）//
-----------------------------
## update
>这里再说一种线段树的方法，我们用线段树的叶节点维护一段1~n的区间，表示这里的颜色的数目，然后我们在树上二分//
>初始化：我们用一个vector数组记录这个节点可以用的k的值//
>二分每一次贪心，如果可以走右边尽量走右边//
>建树：存最小值，至于为什么下面会证明//
------------
>反证法，如果存最大值得话，当一个值等于左子树的时候我们是不能区分到底是向左还是向右的，因为有可能右边的最左边也有可能和他相等，//
 但是我们用贪心的思想的话这样值不满足的。//
>证毕
### 在Code的下面会有第二个代码的完整实现
------
## update 
>好像还有一种树状数组的方法？？
## update
>线段树的做法其实和树状数组的思想是一样的，但是树状数组常数比较小，并且空间小，所以比较优//
简单分析一下，就是把线段树的部分替换成了树状数组。//
不同之处：二分的时候不同，线段树是建立一些虚拟的节点以便于树上二分，而树状数组的定义就是一部分的前缀和，所以可以直接二分。//
更新不同，用拆分的思想更新//
>注意点，二分是二分二进制上的0和1，然后每一次二分的点是右区间的左端点。//
>总而言之，线段树的思想还是非常巧妙的啦//
--------
#### 由于不能换行，于是我用//表示换行了，这样思路清晰一些
### Code
#### 暴力出奇迹
```cpp
inline int get(int x)
{
	memset(col,0,sizeof(col));
	int cnt=0,ans=1;
	for(int i=1;i<=n;i++)
	{
		if(col[a[i]]==ans) continue;
		cnt++;
		col[a[i]]=ans;
		if(cnt>x) {ans++;cnt=1;col[a[i]]=ans;}
	}
	return ans;
}

void solve(int l,int r)
{
	if(l>r) return ;
	ans[l]=get(l),ans[r]=get(r);
	if(ans[l]==ans[r])
	{
		for(int i=l+1;i<=r-1;i++)
			ans[i]=ans[l];
		return ; 
	}
	int mid=l+(r-l)/2;
	solve(l+1,mid),solve(mid,r-1);
	return ;
}

```
#### 线段树
```cpp
#include<bits/stdc++.h>
#define next NxTe
#define ls (rt<<1)
#define rs (rt<<1|1)
#define mid (l+(r-l)/2)
#define maxn 200000
using namespace std;

int tag[maxn<<4],tr[maxn<<4],a[maxn],head[maxn],next[maxn],ans[maxn];
int n,m;
vector<int> v[maxn];

void pushdown(int rt)
{
	tag[ls]+=tag[rt],tag[rs]+=tag[rt];
	tr[ls]+=tag[rt],tr[rs]+=tag[rt];
	tag[rt]=0;
	return ;
}

void update(int l,int r,int rt,int L,int R,int C)
{
	if(L<=l&&r<=R)
		{tr[rt]+=C,tag[rt]+=C;return ;}
	if(tag[rt]) pushdown(rt);
	if(L<=mid) update(l,mid,ls,L,R,C);
	if(R>mid) update(mid+1,r,rs,L,R,C);
	tr[rt]=min(tr[ls],tr[rs]);
	return ;
}

int find(int l,int r,int rt,int x)
{
	if(l==r) return l;//返回的是地址 
	if(tag[rt]) pushdown(rt);
	if(tr[rs]<=x) return find(mid+1,r,rs,x);//右子树满足先选右子树咯 
	else return find(l,mid,ls,x);
}

int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]),head[i]=next[i]=n+1,v[1].push_back(i);
	for(int i=n;i>=1;i--)
		next[i]=head[a[i]],head[a[i]]=i;
	for(int i=1;i<=n;i++)
		if(head[i]<=n)
			update(1,n,1,head[i],n,1);
	int x,y;
	for(int i=1;i<=n;i++)
	{
		for(int j=0;j<v[i].size();j++)
		{
			x=v[i][j];
			y=find(1,n,1,x)+1;
			v[y].push_back(x);
			ans[x]++;
		}
		update(1,n,1,i,next[i]-1,-1);
	}
	for(int i=1;i<=n;i++)
		printf("%d ",ans[i]);
	
	return 0;
}
```
#### 树状数组 
```cpp
#include<bits/stdc++.h>
#define lowbit(k) (k&(-k))
#define maxn 200000
using namespace std;
int tr[maxn],next[maxn],head[maxn],ans[maxn],a[maxn];
vector<int> v[maxn];
int n;

void update(int x,int up)
{
	while(x<=n)
	{
		tr[x]+=up;
		x+=lowbit(x);
	}
	return ;
}

int find(int x)
{
	int u=0;
	for(int i=16;i>=0;i--)
	{
		if((u|(1<<i))>n) continue;
		if(tr[u|(1<<i)]<=x)
			u|=(1<<i),x-=tr[u];
	}
	return u;
}

int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]),next[i]=head[i]=n+1;
	for(int i=n;i>=1;i--)
		next[i]=head[a[i]],head[a[i]]=i;
	for(int i=1;i<=n;i++)
		if(head[i]<=n)
			update(head[i],1);
	for(int i=1;i<=n;i++)
		v[1].push_back(i);
	
	for(int i=1;i<=n;i++)
	{
		for(int j=0;j<v[i].size();j++)
		{
			int x=v[i][j];
			v[find(x)+1].push_back(x);
			ans[x]++;
		}
		update(i,-1),update(next[i],1);
	}
	for(int i=1;i<=n;i++)
		printf("%d ",ans[i]);
	return 0;
}
```
