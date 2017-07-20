[比赛链接](https://cn.vjudge.net/contest/171409)

# 比赛中解决的问题
## A
### Problem description
> 给定整数l，r，k，求出闭区间[l,r]内k的幂次方的个数。

### Data Limit:1≤l≤r≤1e18,2≤k≤1e9  Time Limit:2s

### Solution
> 按题意模拟。设定一个数t=1，每次乘上k，判断得到的新数是否在[l,r]内，若是则输出，当t>r时退出计算。若无满足的数，输出-1即可。

### Code
```cpp
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
long long l,r,x,t=1;
int main()
{
	scanf("%lld%lld%lld",&l,&r,&x);
	while (t<l)
	{
		if (t>r/x)
		{
			printf("-1");
			return 0;
		}
		t*=x;
	}
	if (t>r)
	{
		printf("-1");
		return 0;
	}
	while (t<=r)
	{
		printf("%lld ",t);
		if (t>r/x) break;
		t*=x;
	}
	return 0;
}
```
*****


## B
### Problem description
> 输入一个数n，再输入n个整数a[i]，数列a[i]满足性质至少有(n-1)个美丽数。美丽数的定义是只含有数字0或1且数字1的个数不超过1个的数。求n个数的积。题目保证每个数不含前导0。

### Data Limit:1≤n≤1e5,所有数的长度总和不超过1e5  Time Limit:0.5s

### Solution
> 按题意模拟。根据美丽数的定义我们可以快速解决此题。用check函数判断该数的性质。若数为0，check返回值为0。若数为美丽数，check返回值为1。若数为可能存在的非美丽数，check返回值为2。首先定义一个字符串为t=“1”，再枚举每一个数进行check。判断过程中若遇到0，则break，直接输出0。若遇到非美丽数，则t=美丽数。若遇到美丽数，则将美丽数除了第一位1以外后面的后缀串0复制给ans。最后输出t和ans即为答案。

### Code
```cpp
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
#define maxn 1000005
using namespace std;
char ans[maxn],s[maxn];
int check(char *s)
{
    int len=strlen(s);
    if (len==1&&s[0]=='0')return 0;
    int i,cnt=0;
    for (i=0;i<len;i++)
    {
        if (s[i]=='1')cnt++;
        if (cnt>=2)break;
        if (s[i]!='1'&&s[i]!='0')break;
    }
    if (i==len)return 1;
    else return 2;
}
int main()
{
    int n,i;
    string start="1";
    scanf("%d",&n);
    for (i=0;i<n;i++)
    {
        scanf("%s",s);
        int t=check(s);
        if (t==0) break;
        else if(t==1) strcat(ans,s+1);
        else start=s;
    }
    if (i<n) puts("0");
    else cout<<start<<ans<<endl;
    return 0;
}
```
*****


## C
### Problem description
> 给定整数n和旋转中心的坐标。再给出n个点的坐标，保证这些点按顺时针或按逆时针排列，且不存在三点共线。这些点则能围成一个凸n边形。将这个凸n边形绕旋转中心旋转一周，求旋转时覆盖到坐标轴上的面积。

### Data Limit:3<=n<=1e5  Time Limit:2s

### Solution
> 计算几何。此题需要计算旋转中心到凸n边形的最远距离Max和最近距离Min，然后根据圆面积公式得覆盖的面积公式为S=pi×(Max×Max-Min×Min)。最远距离显然在凸多边形的某个定点上，但是最近距离可能在凸多边形的某条边上。根据点积叉积可算出最大距离和最小距离，再套用公式即可。

### Code
```cpp
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
#define pi acos(-1.0)
using namespace std;
struct point{
	double x,y;
}p[100005],t;
int n;
double dis(point a,point b)
{
	return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}
double dot(point a,point b)
{
	return a.x*b.x+a.y*b.y;
}
double len(point a)
{
	return sqrt(dot(a,a));
}
double point_to_segment(point a,point b,point c)
{
	point v1,v2,v3;
	v1.x=c.x-b.x;
	v1.y=c.y-b.y;
	v2.x=a.x-b.x;
    v2.y=a.y-b.y;
    v3.x=a.x-c.x;
    v3.y=a.y-c.y;
    if (dot(v1,v2)<0) return len(v2);
    else if (dot(v1,v3)>0) return len(v3);
    else return fabs((v1.x*v2.y-v2.x*v1.y)/len(v1));
}
int main()
{
    scanf("%d",&n);
    scanf("%lf%lf",&t.x,&t.y);
    for(int i=0;i<n;i++)
    scanf("%lf%lf",&p[i].x,&p[i].y);
    p[n].x=p[0].x;
	p[n].y=p[0].y;
    double Max=0;
    double Min=1000000000.0;
    for(int i=0;i<n;i++)
    {
        Max=max(Max,dis(t,p[i]));
        Min=min(Min,point_to_segment(t,p[i],p[i+1]));
    }
    printf("%0.10f\n",Max*Max*pi-Min*Min*pi);
    return 0;
}
```
*****


## D
### Problem description
> 给定整数n，A，cf，cm，m，再给出n个数a[i]，表示i的等级，等级可升级，但不能超过A，每升一级需要花费1，花费不能超过m，得到的最后数列中我们统计数列的价值，价值的计算公式是value=等级为A的数的个数×cf+最低的等级值×cm。

### Data Limit:1≤n≤1e5,1≤A≤1e9,0≤cf,cm≤1000,0≤m≤1e15  Time Limit:2s

### Solution
> 二分答案。先把数列记录位置，再排序，维护排好序的数列的前缀和。枚举后面一些数全部升为A级，再二分前面的数的等级，将低于二分出的等级的数加成二分出的等级，判断该方案的花费是否可行。若可行，更新value，并记录需要改的临界位置和需要改成的等级。最后修改序列并输出即可。

### Code
```cpp
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
#define maxn 100010
using namespace std;
long long A,cf,cm,n,w,a[maxn],b[maxn],s[maxn],ans,tmp1,tmp2;
bool cmp(long long x,long long y)
{
    return a[x]<a[y];
}
long long find(long long x,long long y)
{
    long long l,r,mid;
	l=0;
	r=y;
    while (l!=r)
    {
        mid=(l+r+1)/2;
        if (a[b[mid]]<x) l=mid;
        else r=mid-1;
    }
    return l;
}
int main()
{
    scanf("%I64d%I64d%I64d%I64d%I64d",&n,&A,&cf,&cm,&w);
    long long i;
    for (i=1;i<=n;i++)
	scanf("%I64d",&a[i]);
    for (i=1;i<=n;i++)
	b[i]=i;
    sort(b+1,b+1+n,cmp);
    for (i=1;i<=n;i++)
	s[i]=s[i-1]+a[b[i]];
    w+=s[n];
	ans=-1;
	for (i=1;i<=n+1;i++)
	{
	    if (A*(n-i+1)+s[i-1]>w) continue;
	    if (i==1)
		{
			ans=cf*n+cm*A;
			tmp1=1;
		}
	    if (i==1) break;
	    long long l=a[b[1]],r=A,mid,t;
		while(l!=r)
		{
		    mid=(l+r+1)/2;
		    t=find(mid,i-1);
		    if (A*(n+1-i)+mid*t+s[i-1]-s[t]<=w) l=mid;
		    else r=mid-1;
		}
		if (ans<cf*(n+1-i)+l*cm)
		{
			ans=cf*(n+1-i)+l*cm;
			tmp1=i;
			tmp2=l;
		}
    }
	printf("%I64d\n",ans);
    for (i=1;i<tmp1;i++)
	if (a[b[i]]<tmp2) a[b[i]]=tmp2;
	for (i=tmp1;i<=n;i++)
	a[b[i]]=A;
	for (i=1;i<=n;i++) printf("%I64d ",a[i]);
    return 0;
}
```
*****

# 赛后补题

## E
### Problem description
> 给出一个整数n，再给出n个整数a[i]，分别表示颜色为i的珠子有a[i]个。求构造一串项链，使项链从某处剖开后对称，并使能剖开处的数量最大。输出时，先输出一个整数表示可剖开处的个数，然后输出项链。相应的数字用对应的字母表示，如第一种颜色对a，第二种颜色对b...。

### Data Limit:1≤n≤26  Time Limit:2s

### Solution
> 求最大公因数。若数列中奇数的个数超过2个，可以判断不存在对称，直接输出0和所有珠子即可。若数列中只有1个奇数，那么答案就是所有数字的gcd，然后构造答案就是输出gcd个回文串，个数为奇数的颜色放在回文串的中间。如果数列中没有奇数，那么答案就是所有数字的gcd，然后构造答案就是输出gcd/2个回文串。

### Code
```cpp
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
int n,c=0,x,a[30];
int gcd(int x,int y)
{
	if (y==0) return x;
	return gcd(y,x%y);
}
int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;++i)
	scanf("%d",&a[i]);
	for (int i=1;i<=n;++i)
	if (a[i]&1)
	{
		++c;
		x=i;
	}
	if (c>1)
	{
		printf("0\n");
		for (int i=1;i<=n;++i)
		while (a[i]--)
		printf("%c",'a'-1+i);
	}
	else if (c==1)
	{
		c=a[1];
		for (int i=2;i<=n;++i)
		c=gcd(c,a[i]);
		printf("%d\n",c);
		for (int i=1;i<=c;++i)
		{
			for (int j=1;j<=n;++j)
			if (j!=x)
			for (int k=1;k<=a[j]/c/2;++k)
			printf("%c",'a'-1+j);
			for (int j=1;j<=a[x]/c;++j)
			printf("%c",'a'-1+x);
			for (int j=n;j>=1;--j)
			if (j!=x)
			for (int k=1;k<=a[j]/c/2;++k)
			printf("%c",'a'-1+j);
		}
	}
	else if (c==0)
	{
		c=a[1];
		for (int i=2;i<=n;++i)
		c=gcd(c,a[i]);
		printf("%d\n",c);
		for (int i=1;i<=c/2;++i)
		{
			for (int j=1;j<=n;++j)
			for (int k=1;k<=a[j]/c;++k)
			printf("%c",'a'-1+j);
			for (int j=n;j>=1;--j)
			for (int k=1;k<=a[j]/c;++k)
			printf("%c",'a'-1+j);
		}
	}
	return 0;
}
```
