[比赛链接](https://www.codeforces.com)

# 比赛中解决的问题
## A
### Problem description
> 已知正整数a、b、c、d，若存在正整数x、y，满足ax+b=cy+d，则输出最小的ax+b，否则输出-1。

### Data Limit：a,b,c,d<=100  Time Limit: 1s

### Solution
> 本题暴力是可以过的，但我们要用exgcd。。ax+b=cy+d => ax-cy=d-b 于是我们使用exgcd，得 ax'+cy'=gcd(a,c)，那么 x=x'\*(d-b)/gcd(a,c)， y=-y'\*(d-b)/gcd(a,c)。根据这个式子无解的情况就非常好判断了，即(d-b)%gcd(a,c)!=0。因为x和y都必须为正整数，因此再做一些处理。

### Code
```cpp
#include<cstdio>
#include<iostream>
using namespace std;
int a,b,c,d,x,y,ans,t;
int exgcd(int a,int b,int &x,int &y)
{
	int ans;
	if(b==0)
	{
		x=1,y=0;
		return a;
	}
	ans=exgcd(b,a%b,y,x);
	y-=a/b*x;
	return ans;
}
int main()
{
	scanf("%d%d%d%d",&a,&b,&c,&d);
	if(b>d)
	{
		swap(a,c);
		swap(b,d);
	}
	ans=exgcd(a,c,x,y);
	t=d-b;
	if(t%ans)
	{
		cout<<-1<<endl;
		return 0;
	}
	y=-y*t/ans;
	x=x*t/ans;
	while(x<0)
	{
		x+=c/ans;
		y-=a/ans;
	}
	while(y<0)
	{
		x-=c/ans;
		y+=a/ans;
	}
	while(x>c/ans&&y>a/ans)
	{
		x-=c/ans;
		y-=a/ans;
	}
	cout<<c*y+d;
}
```
*****


## B
### Problem description
> 有n对相反数，每一对中一个数是好的，另一个是坏的。他们可重复的出现在m组数字中，且总人次为k。若存在一组数字中有可能均为坏数，则输出YES，否则输出NO。

### Data Limit：n,m,k <= 1e4  Time Limit: 1s
### Solution
> 根据分析，一组数字有可能均为坏数当且仅当这组数字不存在相反数。因此可以直接模拟。

### Code
```cpp
#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;
int n,m,t,x;
bool b[10010],c[10010],bo;
int main()
{
	scanf("%d%d",&n,&m);
	while(m--)
	{
		bo=1;
		scanf("%d",&t);
		memset(b,0,sizeof(b));
		memset(c,0,sizeof(c));
		while(t--)
		{
			scanf("%d",&x);
			if(x>0)b[x]=1;else c[-x]=1;
			if(x>0)if(b[x]&&c[x])bo=0;
			if(x<0)if(b[-x]&&c[-x])bo=0;
		}
		if(bo)
		{
			cout<<"YES"<<endl;
			return 0;
		}
	}
	cout<<"NO"<<endl;
}
```
*****

# 赛后补题

## C
### Problem description
> 一个顺时针位置为1-n的环，有2人分别存在k1、k2种移动点的方式（顺时针）。两人轮流移动同一个点，若一人将点走到1号位置，则获胜。求两人分别先手，点初始位置分别为2~n时必输、可获胜还是可以无限走下去？

### Data Limit： k1,k2 <= n <= 7000  Time Limit: 4s

### Solution
> 这貌似是一道博弈论题目，很明显可以用记忆化搜索做。f[x][y]表示当前第x个人移动，点在y位置上时的胜负状态。其中1表示可获胜，-1表示必输，0表示可无限循环或状态尚未完成。因为一个点搜索时可能会再次搜到自己，所以要使用一个visit数组来判断是否已经访问过，否则会死循环。设l为可移动到的位置。f[x][y]=1:存在l=1或存在f[1-x][l]=-1;f[x][y]=-1:所有的f[1-x][l]都是1;否则f[x][y]均为0。因为f[x][y]的状态可能没有表示出来，所以要多做几遍（我是正两遍反两遍才过。。这题坑爹啊。。差评！！）

### Code
```cpp
#include<cstdio>
#include<iostream>
#include<memory.h>
#define maxn 7010
using namespace std;
int n,i,j,a[2][maxn],f[2][maxn];
bool v[2][maxn];
void search(int x,int y)
{
	int i,bo=1,p;
	v[x][y]=1;
	for(i=1;i<=a[x][0];i++)
	{
		p=(y+a[x][i])%n;
		if(!v[1-x][p]&&p&&f[1-x][p]==0)search(1-x,p);
		if(f[1-x][p]==-1||!p)
		{
			f[x][y]=1;
			return;
		}
		if(f[1-x][p]!=1)bo=0;
	}
	if(bo)f[x][y]=-1;
}
int main()
{
	scanf("%d",&n);
	scanf("%d",&a[0][0]);
	for(i=1;i<=a[0][0];i++)
		scanf("%d",&a[0][i]);
	scanf("%d",&a[1][0]);
	for(i=1;i<=a[1][0];i++)
		scanf("%d",&a[1][i]);
	for(j=0;j<2;j++)
	{
		memset(v,0,sizeof(v));
		for(i=1;i<n;i++)
		{
			search(0,i);
			search(1,i);
		}
		for(i=n-1;i;i--)
		{
			search(0,i);
			search(1,i);
		}
	}
	for(j=0;j<2;j++)
	{
		for(i=1;i<n;i++)
			if(f[j][i]==1)printf("Win ");else
			if(f[j][i]==-1)printf("Lose ");else
			printf("Loop ");
		printf("\n");
	}
}
```
*****


## D
### Problem description
> 有n个点，m种连边方法。方法一：从v走到u，距离为w；方法二：从v走到[l,r]中任意一个点，距离为w；方法三：从[l,r]任意一个点走到v，距离为w。求起点s到所有点的最短路径。若无法到达某点，则输出-1。

### Data Limit： n,m <= 1e5 ， 1 <= u,v,s <= n ， w <= 1e9 Time Limit: 2s
### Solution
> 如果把方法二和三拆分成多个方法一的话铁定超时。想到方法二或三都与线段有关。因此想到用线段树优化建图（然而考试时根本想不到）。建立一正一反两棵线段树，正的线段树大的线段走到小的线段距离为0，反的线段树小的线段走到大的线段距离为0。对于方法二，可以将线段树中的v点指向正线段树中正好包括[l,r]中的所有大线段，因为大线段连向小线段的距离为0，那么连向这些线段就一定连向[l,r]中的所有点，且最短距离不变。方法三则类似的，将反线段树中的大线段连向v在线段树中的点。注意v点在两棵线段树中是共用的。因为一个[l,r]最多可以被分为大约2logn个大线段，那么边的总数大约为4n+2mlogn条，因此，线段树上的点最多为大约400000条，边最多为大约3500000条(虽然数据貌似比较水，最多只有2000000条边= =)。然后有信仰的使用SPFA跑最短路就行了。

### Code
```cpp
#include<cstdio>
#include<iostream>
#define int long long
#define maxn 400010
#define maxm 3500010
using namespace std;
int first[maxn],next[maxm],a[maxm],end[maxm],i,s,n,m,cnt,sum,opt,u,v,x,y,l,r,z,head,tail,f[maxn],c[maxn],t[maxn];
bool b[maxn];
void add(int x,int y,int z)
{
	next[++cnt]=first[x];
	first[x]=cnt;
	end[cnt]=y;
	a[cnt]=z;
}
void build1(int i,int l,int r)
{
	int mid=(l+r)/2;
	sum=max(sum,i);
	if(l==r)
	{
		t[l]=i;
		return;
	}
	add(i,i*2,0);
	build1(i*2,l,mid);
	add(i,i*2+1,0);
	build1(i*2+1,mid+1,r);
}
void build2(int i,int l,int r)
{
	int mid=(l+r)/2;
	if(l==r)return;
	if(l!=mid)add(i*2+sum,i+sum,0);else add(i*2,i+sum,0);
	build2(i*2,l,mid);
	if(mid+1!=r)add(i*2+1+sum,i+sum,0);else add(i*2+1,i+sum,0);
	build2(i*2+1,mid+1,r);
}
void solve(int i,int l,int r,int x,int y,int p)
{
	int mid=(l+r)/2;
	if(x<=l&&r<=y)
	{
		if(!p)add(t[v],i,z);
		if(p)
			if(l==r)add(i,t[v],z);else add(i+sum,t[v],z);
		return;
	}
	if(x<=mid)solve(i*2,l,mid,x,y,p);
	if(y>mid)solve(i*2+1,mid+1,r,x,y,p);
}
signed main()
{
	scanf("%lld%lld%lld",&n,&m,&s);
	build1(1,1,n);
	build2(1,1,n);
	while(m--)
	{
		scanf("%lld",&opt);
		if(opt==1)
		{
			scanf("%lld%lld%lld",&u,&v,&z);
			add(t[u],t[v],z);
		}
		if(opt==2)
		{
			scanf("%lld%lld%lld%lld",&v,&l,&r,&z);
			solve(1,1,n,l,r,0);
		}
		if(opt==3)
		{
			scanf("%lld%lld%lld%lld",&v,&l,&r,&z);
			solve(1,1,n,l,r,1);
		}
	}
	tail=1;
	f[1]=t[s];
	for(i=1;i<=400000;i++)
		c[i]=1e18;
	c[t[s]]=0;
	while(head!=tail)
	{
		head=head%400000+1;
		u=f[head];
		for(i=first[u];i;i=next[i])
		{
			v=end[i];
			if(c[v]>c[u]+a[i])
			{
				c[v]=c[u]+a[i];
				if(!b[v])
				{
					b[v]=1;
					tail=tail%400000+1;
					f[tail]=v;
				}
			}
		}
		b[u]=0;
	}
	for(i=1;i<=n;i++)
		if(c[t[i]]!=1e18)printf("%lld ",c[t[i]]);else printf("-1 ");
}
```
*****

## E
### Problem description
> 将n个数字连续的分到许多组中，每个组中最多有k个不同的颜色。对于每一个k∈[1,n]，求最少分为几组。

### Data Limit：n <= 1e5  Time Limit: 2s

### Solution
> 可以发现对于部分连续的k，答案是相同的。那么我们可以使用分治，对于一组l和r，如果ans(l)=ans(r)，那么对于每一个k∈[l,r]的答案一定均为ans(l)。如果不相同继续分治寻找。证明时间复杂度：最坏情况下每种颜色均不相同。可以发现对于每一个k∈[n/2,n-1]的答案是相同的，对于每一个k∈[n/3,n/2-1]的答案是相同的...那么能分为大约2√n组相同的答案。然后暴力算出答案需要O(n)的时间，总时间复杂度为O(n√n),再算上一些常数后还是可以过的。

### Code
```cpp
#include<cstdio>
#include<iostream>
#define maxn 100010
using namespace std;
int i,n,a[maxn],ans[maxn];
bool b[maxn];
void clear(int l,int r)
{
	int i;
	for(i=l;i<=r;i++)
		b[a[i]]=0;
}
int cal(int x)
{
	int i,last=1,now=0,sum=0;
	for(i=1;i<=n;i++)
		if(!b[a[i]])
		{
			if(now==x)
			{
				clear(last,i-1);
				last=i;
				sum++;
				now=0;
			}
			b[a[i]]=1;
			now++;
		}
	clear(last,n);
	return sum+1;
}
void solve(int l,int r)
{
	if(l>r)return;
	int i,mid=(l+r)/2,ansl,ansr;
	ansl=cal(l);
	ansr=cal(r);
	if(ansl==ansr)
	{
		for(i=l;i<=r;i++)
			ans[i]=ansl;
		return;
	}
	ans[l]=ansl;
	ans[r]=ansr;
	solve(l+1,mid);
	solve(mid+1,r-1);
}
int main()
{
	scanf("%d",&n);
	for(i=1;i<=n;i++)
		scanf("%d",&a[i]);
	solve(1,n);
	for(i=1;i<=n;i++)
		printf("%d ",ans[i]);
}
```
