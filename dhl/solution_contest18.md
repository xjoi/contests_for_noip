[比赛链接](https://cn.vjudge.net/contest/172100)

# 比赛中解决的问题
## A
### Problem description
> 给定ab的矩阵以及半径为r的圆，甲乙博弈，圆不能放在别人的上面求谁赢


### Solution
> 脑筋急转弯，先放中间，然后对着别人的放，

### Code
```cpp
r*=2;
	r<=a&&r<=b?puts("First"):puts("Second");
```
*****


## B
### Problem description
> 求函数的极值

### Data Limit：n <= 100  Time Limit: 2s
### Solution
> 暴力，判断最高位，注意符号

### Code
```cpp
#include<bits/stdc++.h>
using namespace std;
int a[20000],b[20000],n,m;
int gcd(int a,int b){
	if(!b) return a;
	else return gcd(b,a%b);
}

int main()
{
	cin>>n>>m;
	n++,m++;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=1;i<=m;i++)
		cin>>b[i];
	if(n<m)
		puts("0/1");
	else if(n>m)
		(a[1]*b[1])>0?puts("Infinity"):puts("-Infinity");
	else
	{
		int k1=a[1],k2=b[1];
		int fu=(k1*k2)>0?1:-1;
		k1=abs(k1),k2=abs(k2);
		int k=gcd(k1,k2);
		k1/=k,k2/=k;
		if(fu==-1) cout<<"-";
		printf("%d/%d\n",k1,k2);
	}
	
	return 0;
}
```
*****



## C
### Problem description
> 求一个串最大的不上升子序列（最大指字典序）

### Data Limit：n <= 1e5  Time Limit: 2s

### Solution
> 从后往前扫一遍，扫一遍，一遍。

### Code
```cpp
scanf("%s",s);int len=strlen(s);
	int Min='a'-1;
	for(int i=len-1;i>=0;i--)
		if(s[i]>=Min) v.push_back(s[i]),Min=s[i];
	for(int i=v.size()-1;i>=0;i--)
		cout<<char(v[i]);
```
*****


## D
### Problem description
> 给定一个迷宫，迷宫的边界可以互相到达，求是否存在循环。

### Data Limit：n <= 1500  Time Limit: 2s
### Solution
> dfs每一次记录父节点，如果与上次dfs的不同那么就存在循环

### Code
```cpp
// XX->YY 
#include<bits/stdc++.h>
#define P pair<int,int>
#define N 2333
using namespace std;
P book[N][N];int n,m,s[N][N],sx,sy;
char ss[N][N];
int xx[4]={1,-1,0,0};
int yy[4]={0,0,1,-1};
int dfs(int fx,int fy)
{
	int x=(fx%n+n)%n,y=(fy%m+m)%m;
	if(ss[x][y]=='#') return 0;
	if(book[x][y]!=P(-N*N,-N*N))return book[x][y]!=P(fx,fy);
	book[x][y]=P(fx,fy);
	for(int i=0;i<4;i++) if(dfs(fx+xx[i],fy+yy[i])) return 1;
	return 0;
}
main()
{
	cin>>n>>m;
	for(int i=0;i<n;i++)
		scanf("%s",ss[i]);
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
		{
			book[i][j]=P(-N*N,-N*N);
			if(ss[i][j]=='S') sx=i,sy=j;
		}
	dfs(sx,sy)?puts("Yes"):puts("No");
	return 0;
}
```
*****
>PS:上面都写的很~~简单~~了，下面就写的详细一些吧。
# 赛后补题
## E
### Problem description
> 给你一颗树，以及若干个点的左边，求一种方案（一定存在）使得给定坐标的点满足树的结构，并且树的边不能交叉

### Data Limit：n <= 1500  Time Limit: 2s

### Solution
> 首先是一颗树，根据常识，用一个vector存边，然后dfs预处理每一个节点size。然后就是极角排序啦。首先我们可以发现一件事情，我们选了y最小中的x最小的点，那么
>这个点向其他点引申出来的边是不会交叉的，于是我们找到y最小中的x最小的点，并且对其他点进行排序，然后对他的子节点也进行同样的操作一直递归下去就可以了。

### Code
####dfs
```cpp

void dfs(int x,int fa)
{
	sz[x]=1;
	for(int i=0,v;i<g[x].size();i++) if((v=g[x][i])!=fa)
		dfs(v,x),sz[x]+=sz[v];
}
```
#### 排序
```cpp
void solve(int x,int l,int r)
{
	book[x]=1;
	for(int i=l+1;i<=r;i++)
		if(p[i].y<p[l].y||(p[i].y==p[l].y&&p[i].x<p[l].x)) swap(p[i],p[l]);
	ans[p[l].id]=x;
	now=p[l];sort(p+l+1,p+r+1,cmp);
	for(int i=0,v;i<g[x].size();i++)
	{
		if(book[v=g[x][i]]) continue;
		solve(v,l+1,l+sz[v]);
		l+=sz[v];
	}
}
```
>其他代码自己写吧，加油骚年。
~~我不会告诉你我是懒得复制的~~

## 附加题 F div1E
>我就不按规范写了。。
### 题意
给定好多个传送门（1e5），以及好多好多边(1e5),以及到达的传送门之间飞跃的代价为0（我穿越了时间虫洞233~），求传送门互相可以到达的最小代价（从1号节点出发）。
### 题解
>看到这个范围好恐怖啊，一点思路都没有，然后问了同学才知道。
直接说正解吧。我们抓住飞跃代价为0的条件，以站台为源点，跑一边多源最短路（超级神奇可以一起跑），这样我们就可以预处理站台到所有其他点的距离。
我们可以发现一个神奇的性$♂$质，传送门可以互相到达的最小代价就是他们的最小生成树。那么这是为什么呢，我们来翻译一下~~517~~老师的原话。
>由于最小生成树是若干个点可以到达的最小代价，我们把传送门hash到最小生成树的点上，就发现是一个道理了。
然后根据我们预处理的数据，我们可以构造一个新的G，对于每一条原图上的边w，他在新图上的权值就是w+dis[u]+dis[v],uv为边的端点，dis为到达传送门的最小的距离（预处理得出）
然后愉快的跑最小生成树就行啦，就行啦。~~好像好简单~~
放上代码 只贴部分，~~不要打我~~
## dij
```cpp

void dij()
{
	while(!q.empty())
	{
		Node x=q.top();q.pop();
		if(book[x.u]) continue;book[x.u]=1;
		for(int i=head[x.u];i;i=e[i].nxt)
			if(dis[e[i].v]>x.dis+e[i].w)
			{
				dis[e[i].v]=x.dis+e[i].w,pre[e[i].v]=pre[x.u];
				q.push(Node{e[i].v,dis[e[i].v]});
			}
	}
}
```
## 生成树
```cpp
for(int i=1;i<=n;i++)
		b[i].w+=dis[b[i].u]+dis[b[i].v],b[i].u=pre[b[i].u],b[i].v=pre[b[i].v];
	sort(b+1,b+n+1,cmp);ans=dis[1];
	for(int i=1,cnt=0;i<=n;i++)
	{
		int fx=find(b[i].u),fy=find(b[i].v);
		if(fx!=fy) {fa[fx]=fy,ans+=b[i].w;if(++cnt==m-1) break;}
	}
  ```
  其他自己写吧。
