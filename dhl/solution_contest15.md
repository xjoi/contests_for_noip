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
> 我的是暴力做法，我们通过实践可以发现，如果存在一个l,r，他们的答案是相同的，那么他们之间的答案也是相同的，我们就可以进行二分区间然后暴力求解啦
>正解貌似是主席树（？？？）

### Code
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
