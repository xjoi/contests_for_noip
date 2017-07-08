[比赛链接](http://www.hzxjhs.com:83/contest/753)

# 比赛中解决的问题
## A 四面楚歌
### Problem description
> 给出n条直线，n条直线共有m个交点，且保证不存在三条及三条以上的直线交于同一点。问平面被直线分成了几个部分。

### Data Limit:0<=n,m<=10^10000  Time Limit:1s

### Solution
>高精度。画图分析可得答案为n+m+1，高精度加法即可。

### Code
```cpp
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
char a[10005],b[10005];
int len1,len2,maxlen,c[10005],d[10005],e[10005];
bool flag=0;
int main()
{
	scanf("%s%s",a,b);
	len1=strlen(a);
	len2=strlen(b);
	memset(c,0,sizeof(0));
	for (int i=0;i<len1;++i)
	d[i]=a[len1-1-i]-'0';
	for (int i=0;i<len2;++i)
	e[i]=b[len2-1-i]-'0';
	maxlen=max(len1,len2);
	for (int i=0;i<=maxlen;++i)
	{
		if (i==0) c[i]+=d[i]+e[i]+1;
		else c[i]+=d[i]+e[i];
		if (c[i]>=10)
		{
			c[i]-=10;
			++c[i+1];
		}
	}
	for (int i=10004;i>=0;--i)
	{
		if (c[i]!=0) flag=1;
		if ((c[i]==0&&flag)||c[i]!=0) printf("%d",c[i]);
	}
	return 0;
}
```
*****


## B 蒲公英的约定
### Problem description
> 输入n，m，计算n^m分别对19941023和19950814取模的值。

### Data Limit:保证0<=n,m<=10^9  Time Limit:1s

### Solution
> 快速幂。快速幂求值注意中途对两个数取模即可。

### Code
```cpp
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
#define mod1 19941023
#define mod2 19950814
using namespace std;
long long n1,n2,n,m,p,ans1,ans2;
int main()
{
	scanf("%lld%lld",&n,&m);
	n1=n%mod1;
	n2=n%mod2;
	ans1=ans2=1;
	p=m;
	while (p>0)
	{
		if (p&1==1)
		{
			ans1=ans1*n1%mod1;
			ans2=ans2*n2%mod2;
		}
		n1=n1*n1%mod1;
		n2=n2*n2%mod2;
		p=p>>1;
	}
	printf("%lld %lld\n",ans1,ans2);
	return 0;
}
```
*****

# 赛后补题

## C 跨时代
### Problem description
> 给出n根围栏及其长度l[i]，问是否能选出一些围栏，围成一个面积最大的矩形。能输出面积，否则输出“No Solution”。

### Data Limit:1<=n<=16,1<=l[i]<=15  Time Limit:1s

### Solution
> DFS。先用dfs分出两组围栏（不一定包含全部围栏），使两组的总长度相等。这两组围栏分别为矩形的一组邻边。再把两组的总长度用来分这组邻边的每条边的长度。
如果可分，则计算是否大于ans，如果是，ans=长×宽即可。

### Code
```cpp
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>
#include<algorithm>
using namespace std;
int n,ans;
bool f1[300],f2[300];
int a[100],b[100];
void work(int sum)
{
    if (sum*sum/4<=ans) return;
    memset(f1,0,sizeof(f1));
    memset(f2,0,sizeof(f2));
    f1[0]=1;
    f2[0]=1;
    for (int i=1;i<=n;i++)
    for (int j=sum;j>=b[i];j--)
	{
        if (a[i]==1&&f1[j-b[i]]) f1[j]=1;
        if (a[i]==2&&f2[j-b[i]]) f2[j]=1;
    }
    for (int i=1;i<=sum-1;i++)
	if (f1[i]&&f2[i]) ans=max(ans,i*(sum-i));
}
void dfs(int x,int sum1,int sum2)
{
    if (x==n+1)
	{
        if (sum1==sum2) work(sum1);
        return;
    }
    a[x]=1;
    dfs(x+1,sum1+b[x],sum2);
    a[x]=2;
    dfs(x+1,sum1,sum2+b[x]);
    a[x]=0;
    dfs(x+1,sum1,sum2);
}
int main()
{
    ans=-1e9;
    scanf("%d",&n);
    for (int i=1;i<=n;i++)
	scanf("%d",&b[i]);
    dfs(1,0,0);
    if (ans==-1e9) printf("No Solution\n");
    else printf("%d\n",ans);
    return 0;
}
```
*****
