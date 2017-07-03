[比赛链接](https://cn.vjudge.net/contest/168929)

# 比赛中解决的问题
## A
### Problem description
> 输入整数a,b,c,d，即同时给出两个等差数列。第一个等差数列为b,b+a,b+2a,b+3a...，第二个等差数列为d,d+c,d+2c,d+3c...，问数列中是否可能存在相同的两个数，若有，输出最小的相同的数，否则输出-1。

### Data Limit：a，b，c，d<=100  Time Limit:1s

### Solution
>按题意模拟。暴力枚举，若初始b小于d，则让b加上a，否则让d加上c，设一个计数器，每做一步，计数器的值加1，由于a,b,c,d范围较小，均在[1,100]的区间内，所以求得答案的操作数不会过大。若计数器的值超过10000，则可认为不存在相同的数，直接输出-1即可。

### Code
```cpp
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
int main()
{
	int a,b,c,d,i=0;
	scanf("%d%d",&a,&b);
	scanf("%d%d",&c,&d);
    while (i<=10000)
    {
    	++i;
    	if (b<d)
    	{
    		b+=a;
		}
		else if (b>d)
		{
			d+=c;
		}
		else if (b==d)
		{
			printf("%d\n",b);
			return 0;
		}
		else
		{
			break;
		}
	}
	printf("-1\n");
	return 0;
}
```
*****


## B
### Problem description
> 输入整数n,m，再给出m个小组，每个小组有k人，k<=n，k个人的编号的绝对值在[1,n]之间且为整数。每个组里若出现了一对相反数，则认为其中一个数代表叛徒，另一个数不是。没有出现成对相反数的其他数则可认为全部是叛徒。问是否有一个分组全是叛徒，若有输出“YES”，若全部分组都不可能全为叛徒，输出“NO”。

### Data Limit：n，m<=1e4  Time Limit:2s

### Solution
>按题意模拟。 用数组a记录出现的正整数编号k相应的个数a[k]++，用数组b记录出现的负整数编号k相应的个数b[-k]++，然后从1枚举到n，如果存在a[i]和b[i]同时不为0，则该分组不全是叛徒。若该分组中未出现该情况，直接输出“YES”，否则到最后输出“NO”。

### Code
```cpp
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
int main()
{
	int n,m,t,x;
	int a[10005],b[10005];
	bool flag;
	scanf("%d%d",&n,&m);
	for (int i=1;i<=m;++i)
	{
		scanf("%d",&t);
		if (t==1)
		{
			printf("YES\n");
			return 0;
		}
		memset(a,0,sizeof(a));
		memset(b,0,sizeof(b));
		flag=0;
		for (int j=1;j<=t;++j)
	    {
	    	scanf("%d",&x);
	    	if (x>0) ++a[x];
			if (x<0) ++b[-x];
		}
		for (int j=1;j<=n;++j)
		if (a[j]&&b[j])
		{
			flag=1;
			break;
		}
		if (!flag)
		{
			printf("YES\n");
			return 0;
		}
	}
	printf("NO\n");
	return 0;
}
```
*****


## C
### Problem description
> 两个人玩游戏，环形棋盘上共有n个格子。1号是黑洞，有一个怪物刚开始可以在棋盘上除了位置1外的任意一个位置处。第一个人有k1张牌，第二个人有k2张牌，牌上的数字在[1,n-1]的范围内，每个人可以任意使用自己的卡片。谁先让怪物进入位置1，谁就赢。问两个人分别先手，且怪物在分别[2,n]的位置上是否能赢。对于每个先手的玩家，每个怪物所在的格子，尽量让先手的玩家其赢，若赢不了，则尽量使其陷入无限循环，再者为输。赢输出“Win”，无限循环输出“Loop”，输输出“Lose”。

### Data Limit：n<=7000  Time Limit:4s

### Solution
> 记忆化搜索。将位置1视为起点。用flag[x][y]的值表示是否能赢。x表示谁在走棋，x用0或1表示玩家。y表示在第几格，其值-1表示输，0表示陷入无限循环，1表示赢。赋初值flag[0][0]=-1，flag[1][0]=-1，用dfs解决，dfs(x,y,v)表示玩家x在y步的胜负情况v。如果当前v为-1，即当前状态为必败，则对手就必胜，于是枚举对手的卡片，倒推回去走，即if (!flag[!x][(y-Move[!x][i]+n)%n])，那么执行操作dfs(!x,(y-Move[!x][i]+n)%n,1)继续递归下去。如果当前v不为-1，则枚举对方的卡片，倒推回去走，如果倒推回去的格子对于对手已经有了必胜或必败态，则continue跳过，如果那个格子对于对手还没有必胜或必败态，则计算对手已经往该格子走了几次，如果那个格子对手走的次数不少于他的卡片数量，则说明该格子对手没有必胜态，则对手在此格上必败。最后根据两者的flag数组值输出游戏结果即可。

### Code
```cpp
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
#define maxn 7005
using namespace std;
string ans[3]={"Lose","Loop","Win"};
int cnt[2],flag[2][maxn],time[2][maxn];
int n,x;
vector<int>Move[2];
void dfs(int x,int y,int v)
{
	flag[x][y]=v;
	if (v==-1)
	{
		for (int i=0;i<Move[!x].size();++i)
		if (!flag[!x][(y-Move[!x][i]+n)%n])
		dfs(!x,(y-Move[!x][i]+n)%n,1);
	}
	else
	{
		for (int i=0;i<Move[!x].size();++i)
		{
			if (flag[!x][(y-Move[!x][i]+n)%n]) continue;
			if (time[!x][(y-Move[!x][i]+n)%n]<Move[!x].size())
			++time[!x][(y-Move[!x][i]+n)%n];
			if (time[!x][(y-Move[!x][i]+n)%n]==Move[!x].size())
			dfs(!x,(y-Move[!x][i]+n)%n,-1);
		}
	}
}
int main()
{
	scanf("%d",&n);
	for (int i=0;i<2;++i)
	{
		scanf("%d",&cnt[i]);
		for (int j=0;j<cnt[i];++j)
		{
			scanf("%d",&x);
			Move[i].push_back(x);
		}
	}
	flag[1][0]=-1;
	dfs(0,0,-1);
	dfs(1,0,-1);
	for (int i=0;i<2;++i)
	{
		for (int j=1;j<n;++j)
		cout<<ans[flag[i][j]+1]<<' ';
		printf("\n");
	}
	return 0;
}
```
*****

# 赛后补题

## D
### Problem description
> 输入n,q,s，表示有n个点，q个操作，起点为s。接下来q行，每行先输入一个整数t，如果t=1，则输入a,b,c，表示从a到b连一条长度为c的边，如果t=2，则输入
a,b,c,d，表示从a到[b,c]区间内的每一个点都连一条长度为d的边，如果t=3，则输入a,b,c,d，表示从[a,b]区间内的每一个点都连一条长度为d的边。然后计算从起点s到每一个点（包括自己）的最短路。

### Data Limit：n，q<=1e5，1<=s<=n  Time Limit:2s

### Solution
> 线段树，迪杰斯特拉求最短路。考虑到建边有区间操作，如果暴力建边一条一条建过去必然会超时，于是我们用线段树维护建边，再用迪杰斯特拉求最短路。用一个vector，其first值表示边的终点，second值表示边的长度。t=1时操作比较简单，直接建一条边，t=2或t=3时区间操作维护，在线段树上操作，将完全覆盖的区间建一条边即可。建完边以后将vector放入优先队列，再迪杰斯特拉求最短路，最后输出结果即可。

### Code
```cpp
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;
typedef pair<long long,int>p;
const int maxn=2e6+7;
vector<p> v[maxn];
long long dist[maxn],ver[2][maxn];
int n,q,start,time;
struct cmp{
    bool operator ()(p a,p b)
    {
        return a.first>b.first;
    }
};
int build(int l,int r,int rt,int x)
{
    if (l==r) return ver[x][rt]=l;
    ver[x][rt]=++time;
    int mid=(r+l)>>1;
    int c1=build(l,mid,rt<<1,x);
    int c2=build(mid+1,r,rt<<1|1,x);
    if (x==0)
    {
        v[ver[x][rt]].push_back(make_pair(c1,0));
        v[ver[x][rt]].push_back(make_pair(c2,0));
    }
    else
    {
        v[c1].push_back(make_pair(ver[x][rt],0));
        v[c2].push_back(make_pair(ver[x][rt],0));
    }
    return ver[x][rt];
}
void update(int rt,int l,int r,int ll,int rr,int xx,int w,int z)
{
    if (l>rr||r<ll) return;
    if (ll<=l&&rr>=r)
	{
        if (z==0) v[xx].push_back(make_pair(ver[z][rt],w));
        else v[ver[z][rt]].push_back(make_pair(xx,w));
        return;
    }
    int mid=(l+r)>>1;
    update(rt<<1,l,mid,ll,rr,xx,w,z);
    update(rt<<1|1,mid+1,r,ll,rr,xx,w,z);
}
int main()
{
    scanf("%d%d%d",&n,&q,&start);
    memset(dist,-1,sizeof(dist));
    time=n;
    build(1,n,1,0);
    build(1,n,1,1);
    for(int i=0;i<q;i++)
	{
        int t,a,b,c,d;
        scanf("%d%d%d%d",&t,&a,&b,&c);
        if (t==1)
		{
            v[a].push_back(make_pair(b,c));
        }
		else
		{
            scanf("%d",&d);
            update(1,1,n,b,c,a,d,t-2);
        }
    }
    dist[start]=0;
    priority_queue<p,vector<p>,cmp> Q;
    Q.push(make_pair(0,start));
    while(!Q.empty())
	{
        int now=Q.top().second;
        Q.pop();
        for(int i=0;i<v[now].size();i++)
		{
            int ve=v[now][i].first;
            int co=v[now][i].second;
            if (dist[ve]==-1||dist[now]+co<dist[ve])
			{
                dist[ve]=dist[now]+co;
                Q.push(make_pair(dist[ve],ve));
            }
        }
    }
    for(int i=1;i<=n;i++)
    printf("%I64d ",dist[i]);
    printf("\n");
    return 0;
}
```
*****

## E
### Problem description
> 第一行输入一个整数n，第二行给出n个整数，即给出了n个人的编号，要求同一组中编号不能超过k样，求当k为分别为[1,n]中的正整数时的最小分组数，要求分组连续。

### Data Limit：n<=1e5  Time Limit:2s

### Solution
>二分求答案。二分寻找两个端点数的分组个数。如果两个端点的分组数相同，则区间内的也与端点相同，直接赋为同一个数即可。

### Code
```cpp
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
#define maxn 100005
using namespace std;
int n,c[maxn],vis[maxn],ans[maxn];
int get_cnt(int k)
{
	int res=0,cnt=0;
	memset(vis,-1,sizeof(vis));
	for (int i=1;i<=n;++i)
	{
		if (vis[c[i]]==res) continue;
		vis[c[i]]=res;
		cnt++;
		if (cnt>k)
		{
			res++;
			cnt=1;
			vis[c[i]]=res;
		}
	}
	return res+1;
}
void solve(int l,int r)
{
	if (l>r) return;
	int cntl=get_cnt(l);
	int cntr=get_cnt(r);
	if (cntl==cntr)
	{
		for (int i=l;i<=r;++i)
		ans[i]=cntl;
		return;
	}
	ans[l]=cntl;
	ans[r]=cntr;
	int mid=(l+r)>>1;
	solve(l+1,mid);
	solve(mid+1,r-1);
}
int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;++i)
	scanf("%d",&c[i]);
	solve(1,n);
	for (int i=1;i<=n;++i)
	printf("%d ",ans[i]);
	return 0;
}
```
