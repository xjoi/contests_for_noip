# Contest15 Solution

[比赛链接](https://cn.vjudge.net/contest/168929)

# A

## Problem description

> 一个怪物正在追赶另一个星球上的Rick和Morty。 他们很害怕，有时他们尖叫。 更精确地，Rick在时间b，b + a，b + 2a，b + 3a，...，以及Morty在时间d，d + c，d + 2c，d + 3c，...尖叫。

> 问其何时会同时尖叫。

## Solution

> 暴力枚举b+a,b+2a,...,b+xa,当枚举到w时，若(w-d)%c==0，则w时同时尖叫，x枚举到差不多大点的地方就可以了

# B

## Problem description

> 问一堆序列中是否有某个序列同时存在一对相反数。

## Solution

> 扫一遍过去，遇到的打下标记就好了。

# C

## Problem description

> 有两个人在玩游戏，每次可以将初始位置为1的小恐龙以顺时针方向移动k部，k源自于玩家独特的数字集合。当某个玩家将小恐龙移动到0的时候，Ta赢了。

## Solution

> B(oy)F(riend)S(earch)，设状态为f[i][j]，i表示是哪一个玩家，j表示小恐龙的位置。一个状态能够被加入队列（去更新别人），当且仅当它稳赢了，或者稳输了（他后向的所有边都是对手赢）。

> 所以最后怎么判断一个状态是赢是输呢？如果该状态稳赢，那就是赢了。如果该状态的所有后继都是对手赢，那就是输。否则有可能是某些后继根本就没有加入到队列中去，那就是无限循环。

```cpp

#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<cmath>
#include<queue>
using namespace std;
#define pii pair<int,int>
const int MAXN=7000;
const int INF=0x3f3f3f3f;
int n,k[2],s[2][MAXN+10],cnt[2][MAXN+10],vis[2][MAXN+10];
bool dp[2][MAXN+10];
void print(int a,int b)
{
	if(dp[a][b])printf("Win ");
	else if(cnt[a][b]<k[a])printf("Loop ");
	else printf("Lose ");
}
int main()
{
	scanf("%d",&n);
	scanf("%d",k);
	for(int i=1;i<=k[0];++i)scanf("%d",&s[0][i]);
	scanf("%d",k+1);
	for(int i=1;i<=k[1];++i)scanf("%d",&s[1][i]);
	queue<pii> Q;
	Q.push(make_pair(0,0));
	Q.push(make_pair(1,0));
	vis[0][0]=vis[1][0]=1;
	while(!Q.empty())
	{
		pii u=Q.front();Q.pop();
		int ua=u.first,up=u.second,va=!ua,vp;
		for(int i=k[va];i;--i)
		{
			vp=(up-s[va][i]+n)%n;
			if(vis[va][vp])continue;
			++cnt[va][vp];
			dp[va][vp]|=!dp[ua][up];
			if(dp[va][vp]||cnt[va][vp]==k[va])vis[va][vp]=1,Q.push(make_pair(va,vp));
		}
	}
	for(int i=1;i<n;++i)print(0,i);
	puts("");
	for(int i=1;i<n;++i)print(1,i);
	return 0;
}

```

# D

## Problem description

> 给一张图和所有节点的标号。

> 然后有3种连边的方式:

> 1->从u连向v

> 2->从u连向标号为[l,r]的所有节点

> 3->从标号为[l,r]的所有节点连向u

> 最后求单源最短路

## Solution

> 首先有n个节点，然后，建两棵线段树，其一连边从上到下，其二连边自下而上。

> 然后如果是1，正常连边。如果是2，将u连向从上到下连边的那棵线段树。如果是3，与2相反。

> 这样边数就是O(n+m)级别的，可以用SPFA。

# E

## Problem description

> 询问一段序列最少能够被分成几段连续的序列使得每一段序列内最多有k个不同的数，1<=k<=n。

## Solution

> 首先考虑暴力的方法，每次询问k，暴力扫一遍区间，一直到一段连续的区间充满了k个不同的数后，又要加入一个新的数的时候，再划分出一个新的区间。

> 这样是O(n^2)的。

> 但是呢，答案相对于k来讲是有单调性的，而且在很多情况下，一段连续的k对应着同一个答案。

> 所以就可以二分了，对于l,r，如果k=l以及k=r时的答案相等，l<=k<=r的答案就都相等。

```cpp

#include<iostream>
#include<cstring>
#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
const int MAXN=100000;
int n;
int a[MAXN+10];
int vis[MAXN+10];
int ans[MAXN+10];
int get(int k)
{
	memset(vis,0,sizeof vis);
	int cnt=0,m=1;
	for(int i=1;i<=n;++i)
	{
		if(vis[a[i]]!=m)
		{
			++cnt;
			if(cnt>k)
			{
				cnt=1;
				++m;
			}
			vis[a[i]]=m;
		}
	}
	return m;
}
void work(int l,int r)
{
	if(l>r)return;
	int mid=(l+r)>>1;
	ans[l]=get(l);
	ans[mid]=get(mid);
	ans[r]=get(r);
	if(ans[l]==ans[mid])
	{
		for(int i=l+1;i<mid;++i)ans[i]=ans[l];
	}
	else work(l+1,mid-1);
	if(ans[mid]==ans[r])
	{
		for(int i=mid+1;i<r;++i)ans[i]=ans[r];
	}
	else work(mid+1,r-1);
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;++i)scanf("%d",a+i);
	work(1,n);
	for(int i=1;i<=n;++i)printf("%d ",ans[i]);
	return 0;
}

```














































