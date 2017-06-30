[比赛链接](https://www.codeforces.com)

# 比赛中解决的问题
## A
### Problem description
> 一个长为n的单调递增的数列，若有两个相邻的数a,b，且b-a>c，则包括a之前的数字全部消失。求最后剩下几个数字。

### Solution
> 暴力模拟一发。。

### Code
```cpp
#include<cstdio>
#include<iostream>
using namespace std;
int n,m,i,x,last,ans=1;
int main()
{
	scanf("%d%d",&n,&m);
	scanf("%d",&last);
	for(i=2;i<=n;i++)
	{
		scanf("%d",&x);
		if(x-last>m)ans=1;else ans++;
		last=x;
	}
	printf("%d\n",ans);
}
```
*****


## B
### Problem description
> 一个长为n的仅含大写字母或"?"的字符串，其中"?"能表示所有的大写字母。若"?"改动后存在连续的互不重复的26个字符，则输出改动后的字符串，否则输出"NO".

### Solution
> 因为时间充裕，所以可以暴力一点。先枚举起点，如果接下来的26个字母互不重复，则成立并输出结果（多出来的"?"可以为任意大写字母），否则无解。

### Code
```cpp
#include<cstdio>
#include<iostream>
#include<cstring>
#define maxn 50010
using namespace std;
char s[maxn];
int i,j,n,b[26],m,p,num,right;
int main()
{
	scanf("%s",s);
	n=strlen(s);
	for(i=0;i<=n-26;i++)
	{
		m=0,p=0;
		memset(b,0,sizeof(b));
		for(j=0;j<26;j++)
			if(s[i+j]=='?')m++;else b[s[i+j]-65]=1;
		for(j=0;j<26;j++)
			if(!b[j])p++;
		if(p<=m)
		{
			for(j=0;j<=25;j++)
				if(!b[j])
				{
					num=j;
					break;
				}
			for(j=0;j<i;j++)
				if(s[j]=='?')printf("A");else printf("%c",s[j]);
			for(j=i;j<i+26;j++)
				if(s[j]=='?')
				{
					printf("%c",char(num+65));
					if(num<25)num++;
					while(num<25&&b[num])num++;
				}else printf("%c",s[j]);
			for(j=i+26;j<n;j++)
				if(s[j]=='?')printf("A");else printf("%c",s[j]);
			return 0;
		}
	}
	printf("-1\n");
}
```
*****

# 赛后补题

## C
### Problem description
> 设当前等级为i，数字为n。若sqrt(n+xi)是(i+1)的倍数，则等级升为i+1，当前数字改为sqrt(n+xi)。若初始数字为2，求从1级升到n+1级时每一等级的x。

### Solution
> 因为只需输出任意一组解，所以我们不一定要输出最小的x。因为sqrt(n+x(i-1))为i的倍数，那么可知n是i的倍数，sqrt(n+xi)可以表示为sqrt((n/i+x)i)，设(n/i+x)i=k(i+1)^2。因为n+xi为完全平方数，可以让k取i^2，那么原式变为n/i+x=i(i+1)^2，那么x就等于i(i+1)^2-n/i，且当前n为(i-1)i。特殊条件：i=1时n=2。

### Code
```cpp
#include<cstdio>
#include<iostream>
#define ll long long
using namespace std;
ll now,i,n,j;
int main()
{
	scanf("%lld",&n);
	cout<<2<<endl;
	for(i=3;i<=n+1;i++)
		printf("%lld\n",i*i*(i-1)-i+2);
}
```
*****

## D
### Problem description
> 有一个部分边可为任意权值(但∈[1,1e18])的无向图，已知其中两个节点的最短路L，求任意一种无向图。

### Solution
> (暴力版)先判断是否有解。如果当前最短路小于L，那么明显无解。如果相等，那么可以让所有可更改的权值均赋值为INF。如果大于，那么就枚举每一条可更改的边，首先把它赋值为1，如果此时最短路依然大于L，那么这要么是量变要么完全没用。如果此时最短路小于等于L，那么就是质变，设之前最短路为l1，当前最短路为l2。说明只要当前权值小于等于l2-l1，那么最短路一定经过该边。因为l1>L，那么可知让该边赋值为L-l2+1，那么当前最短路就一定是L。之后可更改的边均赋值为INF。因为该图为稀疏图，所以求最短路时可用SPFA，时间复杂度为O(nkm)，4000ms可以接受。

### Code
```cpp
#include<cstdio>
#include<iostream>
#include<cstring>
#define int long long
#define maxn 20010
using namespace std;
int i,j,n,m,sum,s,t,x,y,z,f[maxn],next[maxn],first[maxn],end[maxn],a[maxn],cnt,head,tail,d[maxn],p[maxn],q[maxn],r[maxn];
bool b[maxn];
void add(int x,int y,int z)
{
	next[++cnt]=first[x];
	first[x]=cnt;
	end[cnt]=y;
	a[cnt]=z;
}
int dis(int s,int t)
{
	int i,u,v;
	memset(b,0,sizeof(b));
	f[1]=s;
	for(i=0;i<n;i++)
		d[i]=1e15;
	d[s]=0;
	b[s]=1;
	head=0,tail=1;
	while(head!=tail)
	{
		head=head%1005+1;
		u=f[head];
		for(i=first[u];i!=-1;i=next[i])
		{
			v=end[i];
			if(d[v]>d[u]+a[i])
			{
				d[v]=d[u]+a[i];
				if(!b[v])
				{
					tail=tail%1005+1;
					f[tail]=v;
					b[v]=1;
				}
			}
		}
		b[u]=0;
	}
	return d[t];
}
signed main()
{
	freopen("d.in","r",stdin);
	freopen("wrong.out","w",stdout);
	scanf("%lld%lld%lld%lld%lld",&n,&m,&sum,&s,&t);
	for(i=0;i<=20000;i++)
		next[i]=first[i]=-1;
	for(i=1;i<=m;i++)
	{
		scanf("%lld%lld%lld",&x,&y,&z);
		p[i]=x;
		q[i]=y;
		r[i]=z;
		if(z)
		{
			add(x,y,z);
			add(y,x,z);
		}
	}
	if(dis(s,t)<sum)
	{
		printf("NO\n");
		return 0;
	}
	if(dis(s,t)==sum)
	{
		printf("YES\n");
		for(i=1;i<=m;i++)
		{
			printf("%lld %lld ",p[i],q[i]);
			if(r[i])printf("%lld\n",r[i]);else printf("1000000000000000\n");
		}
		return 0;
	}
	for(i=1;i<=m;i++)
	{
		if(r[i])continue;
		r[i]=1;
		add(p[i],q[i],1);
		add(q[i],p[i],1);
		if(dis(s,t)<=sum)
		{
			printf("YES\n");
			for(j=1;j<i;j++)
				printf("%lld %lld %lld\n",p[j],q[j],r[j]);
			printf("%lld %lld %lld\n",p[i],q[i],sum-dis(s,t)+1);
			for(j=i+1;j<=m;j++)
			{
				printf("%lld %lld ",p[j],q[j]);
				if(r[j])printf("%lld\n",r[j]);else printf("%lld\n",1000000000000000);
			}
			return 0;
		}
	}
	printf("NO\n");
}
```
*****

## E
### Problem description
> 

### Solution
> 

### Code
```cpp
```
