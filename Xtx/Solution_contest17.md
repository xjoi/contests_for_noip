[比赛链接](https://cn.vjudge.net/contest/171671)

# 比赛中解决的问题
## A
### Problem description
> 给出整数p，n，再给出n个数a[i]，建立一个哈希表，哈希函数为(a[i]%p)，问哈希表在哪个数上出现了冲突，输出该数所在位置。若整个哈希表未发生冲突，则输出-1。

### Data Limit:2≤p,n≤300  Time Limit:1s

### Solution
> 按题意模拟。建立一个数组记录(a[i]%p)出现的次数，若次数大于1则出现冲突，输出数所在的位置。若整个过程中未出现冲突，则输出-1。

## B
### Problem description
> 先给出一个字符串，然后可在这个字符串后添k个字符，26个字母都有相应的价值。问怎样添加字符可使所有字符权值和最大。单个字符的权值计算方式为该字符位置i×该字符的价值a[i]。

### Data Limit:字符串长度1≤|s|≤1000,0≤k≤1000  Time Limit:1s

### Solution
> 按题意模拟。先算原字符串所有字符的权值和，然后将价值最大的字符添在原字符串后面，计算权值即可。

## C
### Problem description
> 给出整数n，再给出n个整数，我们可以最多改变一个整数的值。求数列中连续严格递增的子序列的长度。

### Data Limit:1≤n≤1e5  Time Limit:1s

### Solution
> DP。首先找到所有严格上升连续子序列,然后判断两两能不能合并,或者还可以在任一原串添加一个其前面的数或者其后面的数.

### Code
```cpp
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<cstdio>
using namespace std;
const int MAXN=100000;
const int INF=0x3f3f3f3f;
int n;
int a[MAXN+10];
int lft[MAXN+10],riht[MAXN+10],tot;
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;++i)scanf("%d",a+i);
	tot=1;lft[1]=riht[1]=1;
	for(int i=2;i<=n;++i)
	{
		if(a[i]<=a[i-1])
		{
			++tot;
			lft[tot]=riht[tot]=i;
		}
		else ++riht[tot];
	}
	if(tot==1)return printf("%d",riht[1]-lft[1]+1),0;
	int ans=0;
	for(int i=1;i<=tot;++i)ans=max(ans,riht[i]-lft[i]+2);
	for(int i=1;i<tot;++i)
	{
		if(lft[i+1]==riht[i+1])continue;
		if(a[riht[i]]+1<a[lft[i+1]+1])ans=max(ans,riht[i+1]-lft[i]+1);
	}
	for(int i=2;i<=tot;++i)
	{
		if(lft[i-1]==riht[i-1])continue;
		if(a[riht[i-1]-1]+1<a[lft[i]])ans=max(ans,riht[i]-lft[i-1]+1);
	}
	printf("%d",ans);
	return 0;
}
```
*****

# 赛后补题

## D
### Problem description
> 给你一个n*m的矩阵,你可以进行k次操作，操作1是把一行的每个元素都减去p,你可以获得该行所有元素和(操作之前)的pleasure，操作2是把一列的每个元素都减去p,你可以获得该列所有元素和(操作之前)的pleasure，问你最大可以获得的pleasure是多少。

### Data Limit:1≤n,m≤1000;1≤k≤1e6;1≤p≤100  Time Limit:2s

### Solution
> 首先发现要么是整行减少,要么是整列减少,所以所有行或列的相对大小不会改变,可以看做是独立的.所以预处理选i个行或列的最大贡献,然后枚举选几个行几个列,需要注意个是要处理少减掉的p.

### Code
```cpp
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<cmath>
#include<queue>
using namespace std;
#define ll long long
const int MAXN=1000;
const int MAXK=1000000;
const ll INF=1e18;
priority_queue<ll> Qrow,Qcol;
ll delrow,delcol;
ll n,m,k,p;
ll a[MAXN+10][MAXN+10];
ll sumrow[MAXN+10],sumcol[MAXN+10];
ll krow[MAXK+10],kcol[MAXK+10];
int main()
{
	scanf("%I64d%I64d%I64d%I64d",&n,&m,&k,&p);
	for(int i=1;i<=n;++i)
	{
		for(int j=1;j<=m;++j)
		{
			scanf("%I64d",&a[i][j]);
			sumrow[i]+=a[i][j];
			sumcol[j]+=a[i][j];
		}
	}
	for(int i=1;i<=n;++i)Qrow.push(sumrow[i]);
	for(int i=1;i<=m;++i)Qcol.push(sumcol[i]);
	for(int i=1;i<=k;++i)
	{
		ll toprow=Qrow.top();Qrow.pop();
		krow[i]=krow[i-1]+toprow;Qrow.push(toprow-m*p);
		ll topcol=Qcol.top();Qcol.pop();
		kcol[i]=kcol[i-1]+topcol;Qcol.push(topcol-n*p);
	}
	ll ans=-INF;
	for(int i=0;i<=k;++i)ans=max(ans,krow[i]+kcol[k-i]-(ll)i*(k-i)*p);
	printf("%I64d",ans);
	return 0;
}
```
*****

## E
### Problem description
> 定义斐波那契数列前两项F[1]=1，F[2]=1。给出整数n，m，再给出n个数和m项操作。每个操作包含三个数op，l，r，若op=1，就在[l,r]的区间相应加上F[1,r-l+1]斐波那契数列，若op=2，就将[l,r]中所有数统计和并输出。

### Data Limit:1≤n,m≤300000  Time Limit:4s

### Solution
> 大家打的都是线段树啊,,,但是我看到了一种妙妙的分块方法,,,就这样打了.首先我们引入斐波那契打标记,比如说我们要在[l,r]都加上Fi[1,r-l+1],那么就在l处加1,r+1处加上Fi[r-l+2],r+2处加上Fi[r-l+1].

> 然后,总不可能每次修改都更新一遍吧,那么flag的意义就没有了.设block=sqrt(n),当累计的修改到达block了后,一起下放标记,,,如果修改数还没有到达block,就有了询问,那就取之前所有修改的交,一起统计,反正也没有超过sqrt(n).

> 所以总的时间复杂度就是O(n*sqrt(n))的/

### Code
```cpp
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<cmath>
using namespace std;
#define ll long long
const int MOD=1e9+9;
const int MAXN=300000;
const int MAXK=1000;
int n,m;
int k,block;
int a[MAXN+10],sum[MAXN+10];
int l[MAXK+10],r[MAXK+10];
int fi[MAXN+10],prefi[MAXN+10];
int flag[MAXN+10];
inline int AddMod(int a,int b){int c=a+b;return c>=MOD?c-MOD:c;}
inline int MulMod(int a,int b){return (ll)a*b%MOD;}
inline int MinusMod(int a,int b){return ((a-b)%MOD+MOD)%MOD;}
inline int GetFiSum(int a,int b){return a>b?0:MinusMod(prefi[b],prefi[a-1]);}
inline int GetSum(int a,int b){return MinusMod(sum[b],sum[a-1]);}
void InitFi()
{
	prefi[1]=fi[1]=fi[2]=1;prefi[2]=2;
	for(int i=3;i<=MAXN;++i)
	{
		fi[i]=AddMod(fi[i-1],fi[i-2]);
		prefi[i]=AddMod(prefi[i-1],fi[i]);
	}
}
int main()
{
	InitFi();
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;++i)scanf("%d",a+i),sum[i]=AddMod(sum[i-1],a[i]);
	block=sqrt(n);
	int q,from,to;
	for(int i=1;i<=m;++i)
	{
		scanf("%d%d%d",&q,&from,&to);
		if(q&1)
		{
			++k;
			l[k]=from;r[k]=to;
			flag[from]=AddMod(flag[from],1);
			flag[to+1]=MinusMod(flag[to+1],fi[to-from+2]);
			flag[to+2]=MinusMod(flag[to+2],fi[to-from+1]);
			if(k==block)
			{
				sum[1]=a[1]=AddMod(a[1],flag[1]);
				for(int j=2;j<=n;++j)
				{
					flag[j]=AddMod(flag[j],AddMod(flag[j-1],flag[j-2]));
					a[j]=AddMod(a[j],flag[j]);
					sum[j]=AddMod(sum[j-1],a[j]);
				}
				for(int j=1;j<=n;++j)flag[j]=0;
				k=0;
			}
		}
		else
		{
			int res=GetSum(from,to);
			for(int i=1;i<=k;++i)res=AddMod(res,GetFiSum(max(from,l[i])-l[i]+1,min(to,r[i])-l[i]+1));
			printf("%d\n",res);
		}
	}
	return 0;
}
```
