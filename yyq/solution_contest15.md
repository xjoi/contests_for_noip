[比赛链接](https://cn.vjudge.net/contest/168929)

# 比赛中解决的问题

> 由于太久没补题被逐出了Group，无法进比赛交题目...惨啊。于是这次所有题都在赛后补题里了。

*****

# 赛后补题
## #A The Monster
### Problem description
> 给出a,b,c,d。其中第一个人尖叫的时间分别是b,b+a,b+2a...……第二个人尖叫的时间为d,d+c,d+2c...求两人第一次同时尖叫的时间

### Data Limit: a,b,c,d<=100  Time Limit: 1s

### Solution
> 第一种方法，直接暴力，因为a,b,c,d均小于等于100，所以可以用一个book数组开到大约1e7左右存第一个人尖叫的时间，然后从小到大枚举第二个人尖叫的时间，找到第一个被标记的时间直接输出然后退出程序。

> 第二种方法，用扩展欧几里得，其实这题跟xjoi上的[青蛙的约会](http://www.hzxjhs.com:83/problem/2407)差不多。具体我就不细讲了，看代码吧。

### Code
> 暴力
```cpp
cin>>a>>b>>c>>d;
memset(book,0,sizeof book);
for(int i=0;i<=1000;i++)
	book[b+i*a]=true;
for(int i=0;i<=1000;i++)
	if(book[d+i*c])
	{
		cout<<d+i*c<<endl;
		return 0;
	}
cout<<"-1"<<endl;
```

> 扩欧（exgcd）
```cpp
int exgcd(int a,int b,int &x,int &y)
{
	int r,temp;
	if (b==0)
	{
		x=1;
		y=0;
		return a;
	}
	r=exgcd(b,a%b,x,y);
	temp=x;
	x=y;
	y=temp-a/b*y;
	return r;
}
int main()
{
	scanf("%d%d%d%d",&a,&b,&c,&d);
	q=d-b;
	min=exgcd(a,c,x,y);
	if (q%min!=0)
		cout<<"-1"<<endl;
	else
	{
		x=x*(q/min);
		x=(x%(c/min)+(c/min))%(c/min);
		y=(b-d+x*a)/c;
		while (y<0)
		{
			x=x+c/min;
			y=(b-d+x*a)/c;
		}
		printf("%d\n",b+a*x);
	}
}
```
*****


## #B Not Afraid
### Problem description
> 输入n,m,接下来m行先输入一个k,后面跟着k个数，若每行中都有一对相反数，就输出"NO"，否则输出"YES"。

### Data Limit: n<=1e4  Time Limit: 2s

### Solution
> 直接在每行数字输入前用一个map，在数字读完后遍历一遍，若该数字的相反数已经记录在map中，则他们是一对相反数。若遍历完还没有出现一对相反数，则该行不存在一对相反数，可以直接输出"YES"。

### Code
```cpp
int solve(int n)
{
	map<int,int> maple;
	for(int i=0;i<n;i++)
	{
		if(maple.find(-a[i])!=maple.end())
			return 0;
        maple[a[i]]=1;
	}
	return 1;
}
```
*****


## #C Berzerk
### Problem description
> 一个环形路径编号为1-n，1号点为黑洞，玩家轮流让怪物前进若干步（从自己的操作集合里随便选），若该轮怪物走到黑洞，则该轮的玩家胜利。要求求出所有怪物初始位置（即2~n-1）和玩家a，b各自先手的游戏结果。

### Data Limit: n<=7000  Time Limit: 4s

### Solution
> 这题可以用DP+BFS。设状态```dp[x][y]```表示当前怪物在x点，轮到玩家y操作的游戏结果。所以```dp[1][0]```和```dp[1][1]```的结果都是失败，若在```dp[x][y]```的情况下，玩家的任意操作到达的```dp[x’][y’]```的状态是y’玩家失败，则```dp[x][y]```为胜利（玩家选择该操作即可胜利），反之，若玩家的所有选择到达的下一个状态```dp[x’][y’]```都是另一个玩家y’胜利,则```dp[x][y]```为失败的，搜索就行。不过因为会有陷入循环的结果，所以可以使用逆向bfs的方法，有点像拓扑排序（先初始化所有点的度数为可操作数），先让点```x=0,y=0```和```x=0,y=1```入队，对于任意当前队列头的点，如果这个点的状态是失败，则逆推出能从哪些点到这一点，那些点的状态都是胜利并且入队；如果这个点的状态是失败，则让所有逆推出来的上一步的点的度数减一，如果该点的度数为0，则该点的状态是失败并且入队。最后那些始终没有入队过的就是陷入循环的点了。

### Code
```cpp
void bfs()
{
	while(!que.empty())
	{
		point cnt=que.front();
		que.pop();
		vis[cnt.p][cnt.turn]=1;
		int turn=!cnt.turn;
		if(cnt.ans==2)
		{
			for(int i=0;i<k[turn];i++)
			{
				int nex=(cnt.p+n-sta[turn][i])%n;
				if(!vis[nex][turn])
				{
					dp[nex][turn]=1;
					que.push((point){nex,turn,1});
				}
			}
		}
		else
		{
			for(int i=0;i<k[turn];i++)
			{
				int nex=(cnt.p+n-sta[turn][i])%n;
				deg[nex][turn]--;
				if(deg[nex][turn]==0&&!vis[nex][turn])
				{
					dp[nex][turn]=2;
					que.push((point){nex,turn,2});
				}
			}
		}
	}
}
```
*****

## #D Legacy
### Problem description
> 有n个点，q个询问，每次询问有一种操作。操作1：u到v的距离为w；操作2：u→[l,r]（即u到l，l+1，l+2，...，r距离均为w）的距离为w；操作3：[l,r]→u的距离为w；求起点到其他点的最短距离，到达不了输出-1。

### Data Limit: n, q<=1e5  Time Limit: 2s

### Solution
> 线段树+Dijkstra最短路。具体见代码。

### Code
```cpp
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN=5000005;
const ll INF=1e17+10;
struct node
{
	int to,next;
	ll w;
}edge[MAXN];
int tot,head[MAXN],ma;
bool vis[MAXN];
ll ans[MAXN];
void init()
{
	tot=0;
	ma=0;
	memset(vis,0,sizeof(vis));
	memset(head,-1,sizeof(head));
}
void add(int u,int v,ll w)
{
	tot++;
	edge[tot].to=v;
	edge[tot].w=w;
	edge[tot].next=head[u];
	head[u]=tot;
}
void build(int l,int r,int pos,int flag,int t)
{
	if(t==2)
		ma=max(ma,pos+flag);
	if(l==r)
	{
		if(t==2)
			add(pos+flag,l,0LL);
		else
			add(l,pos+flag,0LL);
		return;
	}
	if(t==2)
	{
		add(pos+flag,(pos<<1)+flag,0LL);
		add(pos+flag,(pos<<1|1)+flag,0LL);
	}
	else
	{
		add((pos<<1)+flag,pos+flag,0LL);
		add((pos<<1|1)+flag,pos+flag,0LL);
	}
	int mid=(l+r)>>1;
	build(l,mid,pos<<1,flag,t);
	build(mid+1,r,pos<<1|1,flag,t);
}
void update(int L,int R,ll w,int l,int r,int pos,int flag,int u,int t)
{
	if(L<=l&&r<=R)
	{
		if(t==2)
			add(u,pos+flag,w);
		else
			add(pos+flag,u,w);
		return;
	}
	int mid=(l+r)>>1;
	if(L<=mid)
		update(L,R,w,l,mid,pos<<1,flag,u,t);
	if(R>mid)
		update(L,R,w,mid+1,r,pos<<1|1,flag,u,t);
}
struct dijk
{
	int s;
	ll dis;
	dijk() {}
	dijk(ll ss,ll d)
	{
		s=ss,dis=d;
	}
	bool operator <(const dijk &x)const
	{
		return dis>x.dis;
	}
};
priority_queue<dijk>q;
void dij(int s)
{
	ans[s]=0LL;
	q.push(dijk(s,0LL));
	while(!q.empty())
	{
		dijk now=q.top();
		q.pop();
		int u=now.s;
		if(vis[u])
			continue;
		vis[u]=1;
		for(int i=head[u];i!=-1;i=edge[i].next)
		{
			int v=edge[i].to;
			ll w=edge[i].w;
			if(ans[v]>now.dis+w)
			{
				q.push(dijk(v,now.dis+w));
				ans[v]=now.dis+w;
//				cout<<u<<"->"<<v<<":"<<ans[v];
			}
		}
	}
}
int main()
{
	int n,q,s;
	cin>>n>>q>>s;
	init();
	build(1,n,1,n+1,2);
	build(1,n,1,ma+1,3);
	for(int i=1;i<=q;i++)
	{
		int t;
		cin>>t;
		if(t==1)
		{
			int u,v;
			ll w;
			cin>>u>>v>>w;
			add(u,v,w);
		}
		else
		{
			int u,l,r;
			ll w;
			cin>>u>>l>>r>>w;
			if(t==2)
				update(l,r,w,1,n,1,n+1,u,t);
			else
				update(l,r,w,1,n,1,ma+1,u,t);
		}
	}
	for(int i=0;i<MAXN;i++)
		ans[i]=INF;
	dij(s);
	for(int i=1;i<=n;i++)
	{
		if(ans[i]>=INF)
			cout<<"-1";
		else
			cout<<ans[i];
		if(i!=n)
			cout<<" ";
	}
	cout<<endl;
	return 0;
}
```
*****

## #E Till I Collapse
### Problem description
> 暂无

### Data Limit: n<=1e5  Time Limit: 2s

### Solution
> 一种高级数据结构：主席树，暂时不会，就先放着吧。

### Code
> 暂无
*****
