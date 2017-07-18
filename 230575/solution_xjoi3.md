[比赛链接](http://www.hzxjhs.com:83/contest/755)

# 比赛中解决的问题

# 赛后补题

## A 棋子
### Problem description
> 一种跳棋游戏，有一个N×1的棋盘，N是无限的。棋盘上放着一些棋子，对于每个棋子，你可以做如下操作：1．将一个棋子移动到它左边或右边第4个格子（如果那个格子为空）。2．将一个棋子移动到它右边第3个格子（如果右边第1和3个格子为空，且它右边第2个格子不为空），移动之后，原先它右边第1个格子将会放上一个棋子，右边第2个格子上的棋子将会被拿走。3．将一个棋子移动到它右边第2个格子（如果右边第1个格子不为空，且它右边第2个格子为空），移动之后，原先它右边第1个格子上的棋子将会被拿走。给出棋盘左端的前30个格子的状态，其余的格子都为空。问能否通过使用上述操作将第一个棋盘转换为第二个棋盘。本题包含多组数据T，每组数据两个字符串长度均为30。

### Data Limit:T<=10  Time Limit:1s

### Solution
> 记忆化搜索。因为棋盘无限，所以不用考虑每个棋子具体位置，用f[k1][k2][k3][k4]表示在4n+0位有k1个，在4n+1位有k2个…的状态是否达到。通过BFS搜索出所有可以达到的状态，最后判断。

### Code
```cpp
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
int T,sum1[4],sum2[4];
bool f[35][35][35][35],judge;
char c1[35],c2[35];
void dfs(int x1,int x2,int x3,int x4)
{
	if (f[x1][x2][x3][x4]) return;
	if (x1==sum2[0]&&x2==sum2[1]&&x3==sum2[2]&&x4==sum2[3])
	{
		printf("YES\n");
		judge=1;
		return;
	}
	if (x1+x2+x3+x4<sum2[0]+sum2[1]+sum2[2]+sum2[3]) return;
	f[x1][x2][x3][x4]=1;
	if (x1&&x3) dfs(x1-1,x2+1,x3-1,x4+1);
	if (judge) return;
	if (x2&&x4) dfs(x1+1,x2-1,x3+1,x4-1);
	if (judge) return;
	if (x1&&x2) dfs(x1-1,x2-1,x3+1,x4);
	if (judge) return;
	if (x2&&x3) dfs(x1,x2-1,x3-1,x4+1);
	if (judge) return;
	if (x3&&x4) dfs(x1+1,x2,x3-1,x4-1);
	if (judge) return;
	if (x4&&x1) dfs(x1-1,x2+1,x3,x4-1);
	if (judge) return;
}
int main()
{
	scanf("%d",&T);
	while (T--)
	{
		memset(f,0,sizeof(f));
		memset(sum1,0,sizeof(sum1));
		memset(sum2,0,sizeof(sum2));
		scanf("%s%s",c1,c2);
		for (int i=0;i<30;++i)
		{
			if (c1[i]=='*') ++sum1[i%4];
			if (c2[i]=='*') ++sum2[i%4];
		}
		judge=0;
		dfs(sum1[0],sum1[1],sum1[2],sum1[3]);
		if (!judge) printf("NO\n");
    }
    return 0;
}
```
*****


## B 路线
### Problem description
> 在一个N×M的区域中存在有若干个景点（不超过10个），且每一小区域的海拔高度是高低不一的。假设相临两1×1区域的高度差为x，则从其中一个区域移到另一区域将耗费x^2+1分钟的时间。我们要求得到一条由区域（1，1）出发，经过所有景点的路线，并保证花费的时间最短。

### Data Limit:1<=N，M<=100，1<=P<=10  Time Limit:1s

### Solution
> SPFA求最短路。先计算每相邻两点的时间花费，然后再用SPFA计算任意两景点（包括起点）之间所用最小的时间花费，最后DFS求经过所有景点时间花费最小值。

### Code
```cpp
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<queue>
using namespace std;
queue <int> q;
struct node{
	int next,to,w;
}edge[100010];
int n,m,tot=0,ans,t;
int head[100010],x[10010],y[10010],dis[20][100010],d[110][110];
bool exist[100010],vis[100010];
void add(int u,int v,int w)
{
	edge[++tot].next=head[u];
	edge[tot].to=v;
	edge[tot].w=w;
	head[u]=tot;
	return;
}
void spfa(int x,int s)
{
	dis[x][s]=0;
	exist[s]=1;
	q.push(s);
	while (!q.empty())
	{
		int u=q.front();
		q.pop();
		exist[u]=0;
		for (int i=head[u];i!=-1;i=edge[i].next)
		{
			int v=edge[i].to;
			if (dis[x][u]+edge[i].w<dis[x][v])
			{
				dis[x][v]=dis[x][u]+edge[i].w;
				if (!exist[v])
				{
					exist[v]=1;
					q.push(v);
				}
			}
		}
	}
}
void dfs(int now,int fa,int sum)
{
	if (now==t+1)
	{
		ans=min(ans,sum);
		return;
	}
	for (int i=1;i<=t;++i)
	{
		if (vis[i]) continue;
		vis[i]=1;
		dfs(now+1,i,sum+dis[fa][(x[i]-1)*m+y[i]]);
		vis[i]=0;
	}
}
int main()
{
	memset(head,-1,sizeof(head));
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;++i)
	for (int j=1;j<=m;++j)
	scanf("%d",&d[i][j]);
	scanf("%d",&t);
	for (int i=1;i<=t;++i)
	scanf("%d%d",&x[i],&y[i]);
	for (int i=1;i<=n;++i)
	for (int j=1;j<=m;++j)
	{
		add((i-1)*m+j,(i-1)*m+j,0);
		int nownum=(i-1)*m+j;
		if (i!=1)
		{
			int cost=(d[i][j]-d[i-1][j])*(d[i][j]-d[i-1][j])+1;
			add(nownum,(i-2)*m+j,cost);
		}
		if (i!=n)
		{
			int cost=(d[i][j]-d[i+1][j])*(d[i][j]-d[i+1][j])+1;
			add(nownum,i*m+j,cost);
		}
		if (j!=1)
		{
			int cost=(d[i][j]-d[i][j-1])*(d[i][j]-d[i][j-1])+1;
			add(nownum,(i-1)*m+j-1,cost);
		}
		if (j!=m)
		{
			int cost=(d[i][j]-d[i][j+1])*(d[i][j]-d[i][j+1])+1;
			add(nownum,(i-1)*m+j+1,cost);
		}
	}
	memset(dis,0x7f,sizeof(dis));
	x[t+1]=1;
	y[t+1]=1;
	for (int i=1;i<=t+1;++i)
	spfa(i,(x[i]-1)*m+y[i]);
	ans=0x7f7f7f7f;
	memset(vis,0,sizeof(vis));
	dfs(1,t+1,0);
	printf("%d\n",ans);
	return 0;
}
```
*****


## C 方程
### Problem description
> 给定一个正整数N，找到符合下面方程的正整数解（X，Y）的数量（N!=1*2*…*N）：1/N! = 1/X + 1/Y。本题输入有多组数据。

### Data Limit:N<=10000，数据组数<=30  Time Limit:1s

### Solution
> 一道数学题。因为1/n!=1/x+1/y，所以x>n!且y>n!，则设a=n!，x=a+b，y=a+c，所以1/a=1/(a+b)+1/(a+c)，则1/a=(2a+b+c)/((a+b)*(a+c))，交叉相乘得a^2=b*c，所以这道题目便是求n!平方的约数个数的问题了。求n!的约数个数可以使用分解质因数去解决。

### Code
```cpp
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std; 
bool bo[10010];
int pri[10010],num[10010],a[10010],n,cnt; 
void mul(long long b)
{
    long long k=0;
    for (long long i=1;i<=a[0]+6;++i)
	{
        a[i]=k+a[i]*b;
		k=a[i]/10;
		a[i]%=10;
    }
    for (long long i=a[0]+6;i>=1;--i)
	{
        if(a[i]!=0)
		{
		    a[0]=i;
			break;
		}
    }
}
int main()
{
    memset(bo,1,sizeof(bo));
    int j;
    for (int i=2;i<=10000;i++)
	{
        if (bo[i])
		{
            j=i;
			cnt++;
			pri[cnt]=i; 
            while (j+i<=10000)
			{
			    j+=i;
				bo[j]=0;
			}
        }
    }
    scanf("%d",&n);
    while (n)
	{
        if (n==0) break;
        for (int i=0;i<=10000;i++)
		num[i]=0;
        for (int i=1;i<=cnt&&pri[i]<=n;i++)
		{
            int tmp=n;
            while (1)
			{
                if(tmp==0||pri[i]>n) break;
                num[i]+=tmp/pri[i];
                tmp/=pri[i];
            }
        }
        memset(a,0,sizeof(a));
        a[1]=1;
		a[0]=1;
        for (int i=1;i<=cnt&&pri[i]<=n;i++)
		if (num[i]>=1) mul(2*num[i]+1);
        for (int i=a[0];i>=1;--i)
		printf("%d",a[i]);
        printf("\n");
        scanf("%d",&n);
    }
    return 0;
}
```
*****
