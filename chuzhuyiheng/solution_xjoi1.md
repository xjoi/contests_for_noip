[比赛链接](https://www.codeforces.com)

# 比赛中解决的问题
## A
### Problem description
> 给你一个长度为N的正整数序列，如果一个连续的子序列，子序列的和能够被K整
除，那么就视此子序列合法，求原序列包括多少个合法的连续子序列？

### Data Limit：1<=N<=50000 1<=K<=1000000  Time Limit: 1s

### Solution
> 前缀和一遍，记得取模，记为a[i]。
若a[i],a[j]相同，则i到j为符合题意的字串，统计一下即可。

### Code
```cpp
#include<cstdio>
long long a[10000000],b[500000],q[500000];
long long n,i,j,k,T,ans;
int main()
{
	scanf("%lld",&T);
	while (T--)
	{
		//a[0]=0;
		
		scanf("%lld%lld",&k,&n);
		for (i=0;i<=k;i++) a[i]=0;
		ans=0;
	    for (i=1;i<=n;i++) 
	    {
	    	scanf("%lld",&b[i]);
	    	b[i]=b[i]%k;
	    	q[i+1]=(q[i]+b[i])%k;
	    	ans+=a[q[i+1]];
	    	a[q[i+1]]++;
	    	
		}
		ans+=a[0];
		printf("%lld\n",ans);
	}
	
}
```
*****


## B
### Problem description
> 船初始时它的坐标记为(Ax,y)。河深为y，河宽为x。某个时刻会从左边界或右边界游
出来一条鱼(左边的往右边游，右边的往左边游)，即鱼游出来时的横坐标为0或x，这条鱼
每秒会游D个单位长度，鱼的长度为L。初始时刻为0，对于每个时刻x，船可以选择花费1s
向左或向右移动最多Q个单位长度，或者选择在当前位置进行钓鱼，鱼的动作是瞬间的，且
发生在时刻x，鱼还来不及移动就被钓上了。如果选择钓鱼，那么在时刻x就不能动。{x+1
时刻可以选择移动}设当前位置为z，将鱼看成一条线段，当线段与直线x=z相交时就认为鱼
上钩了，所以一次钓鱼动作可能会钓多条鱼。
问在T时刻前最多能钓多少鱼?
注：在鱼出现的时刻，钓鱼时只有河两端有鱼头，但钓鱼后鱼就动了（这里wa掉了好几次）
### Data Limit：1<=T,time<=10 1<=Ax,Ay,Q,x,y,D,L<=10 1<=N<=14  Time Limit: 1s
### Solution
> 用dp：f[i][j][k]表示i时刻，船在j位置，钓鱼状态为k的这个状态能否达到
k转为二进制时第i+1为若为1，则表示i鱼已被抓
还有注意Problem description的注即可
### Code
```cpp
#include<cstdio>
int T,maxx,maxy,ax,q,n,i,j,ans,k,l,anst;
int x[200],t[200],d[200],ll[200],time[200],y[200],tou[200],wei[200];
int f[20][20][50000];
int ttt(int x)
{
	return x;
}
int main()
{
	scanf("%d",&T);
	scanf("%d%d",&maxx,&maxy);
    scanf("%d%d",&ax,&q);
    scanf("%d",&n);
    for (i=1;i<=n;i++)
    {
      scanf("%d%d%d%d%d",&x[i],&y[i],&d[i],&ll[i],&time[i]);
      tou[i]=x[i];
      if (x[i]==0) 
	  {
	  	//tou[i]=tou[i]+d[i];
	  	wei[i]=tou[i]-ll[i];
	  } else
      {
      	//tou[i]=tou[i]-d[i];
      	wei[i]=tou[i]+ll[i];
      	d[i]=-d[i];
	  }
	}
	f[0][ax][0]=1;
	ans=-1;
	for (i=0;i<=T;i++)
	  for (j=0;j<=maxx;j++)
	    for (k=0;k<(1<<(1+n));k++)
	    if (f[i][j][k]==1)
	    {
	    	//f[i+1][j][k]=1;
	    	int tt=k;
	    	for (l=1;l<=n;l++)
	    	if (i>=time[l] && (((tou[l]+ttt(i-time[l])*d[l]>=j)&&(wei[l]+ttt(i-time[l])*d[l]<=j)) ||(tou[l]+ttt(i-time[l])*d[l]<=j)&&(wei[l]+ttt(i-time[l])*d[l]>=j)))
	    	{
	    		//f[i+1][j][k|(1<<l)]=1;
	    		//for (int kk=1;kk<=n;kk++)
	    		tt|=(1<<l);
			}
			f[i+1][j][tt]=1;
			//printf("%d %d %d %d %d %d\n",i,j,k,i+1,j,tt);
			for (l=-q;l<=q;l++)
			if (j+l<=maxx && j+l>=0) f[i+1][j+l][k]=1;
		}
	//ans=0;
	for (i=0;i<=maxx;i++)
	  for (j=1;j<(1<<(1+n));j++)
	  if (f[T+1][i][j]==1)
	  {
	  	anst=0;
	  	for (k=1;k<=n;k++)
	    if ((1<<k)&j) anst++;
	    if (anst>ans) ans=anst;
	  }
	printf("%d",ans);
	  
}
```
*****

## D
### Problem description
> 打字时每按一次键，拇指的疲劳度为a，食指的疲劳度为
b，中指的疲劳度为c，无名指的疲劳度为d，小指的疲劳度为e。现在让你来设计键盘，即
对于一个字符，安排一个键，一个键只拥有一个字符。使得打印给定的文章的疲劳度最小。
规定：键盘只包括图中第2行'`'到'\',第三行'Q'到']',第四行'A'到''',第五行'Z'到'/'，第六行
的空格键。
输入abced与n个字符 求最小疲劳值
### Data Limit：0<=a,b,c,d,e<=100 1<=N<=1000000  Time Limit: 1s
### Solution
> 由图可知拇指，食指，中指，无名指，小指分别可按1,16,8,8,15个键
然后统计每个字符出现次数，排序。
再把abcde排序
把每个字符一一与手指对应即可

### Code
```cpp
#include<cstdio>
#include <algorithm>
using namespace std;
long long  a[100],i,j,n,b[100],te,ans;
long long h[1000];
char hh[1000],ch;
bool bo;
int main()
{
	scanf("%lld%lld%lld%lld%lld\n",&a[1],&a[2],&a[3],&a[4],&a[5]);
	b[1]=1;
	b[2]=16;
	b[3]=8;
	b[4]=8;
	b[5]=15;
	scanf("%lld\n",&n);
	long long t=0;
	for (i=1;i<=n;i++)
	{
		scanf("%c",&ch);bo=false;
		for (j=1;j<=t;j++)
		if (hh[j]==ch) 
		{
			h[j]++;bo=true;
			break;
		}
		if (!bo)
		{
			t++;
			hh[t]=ch;
			h[t]=1;
		}
		
		
	}
	for (i=1;i<=t;i++)
	  for (j=i+1;j<=t;j++)
	  	if (h[i]>h[j])
	  	{
	  		
	  		te=h[i];
	  		h[i]=h[j];
	  		h[j]=te;
		}
	for (i=1;i<=5;i++)
	  for (j=i+1;j<=5;j++)
	  	if (a[i]>a[j])
	  	{
	  		
	  		te=a[i];
	  		a[i]=a[j];
	  		a[j]=te;
	  		te=b[i];
	  		b[i]=b[j];
	  		b[j]=te;
		}
	ans=0;long long kk=1;
	while (t>0)
	{
		if (b[kk]==0)
		{
			kk++;
			continue;
		}
		b[kk]--;
		ans=ans+h[t]*a[kk];
		t--;
	}
	printf("%lld",ans);
	return 0;
}
```
*****

# 赛后补题

## C
### Problem description
> 树是由N个等腰三角形构成的，每个三角形的对称轴在y轴上，且每个三角形与上面和下
面的三角形有接触。雪以与x轴成a角(0<a<pi)下落,问雪与三角形有接触的长度是多少?
(也可以理解为成a角的平行光源射向树，问被照亮的长度)

### Data Limit：0<a<pi 0<A<1000,A为实数 0<B<pi Time Limit: 1s

### Solution
> 三角函数处理出每个三角形被照亮的长度，加一下即可，注意迎光面和背光面要分别处理。
### Code
```cpp
%:pragma GCC optimize(3)
#include<bits/stdc++.h>
using namespace std;
long double l[1000001],b[1000001],h[1000001],x[1000001],a,ans;
int n;
int main(){
    scanf("%Lf%d",&a,&n);
    long double pi=3.141592653589;
    if (a>pi/2) a=pi-a;
    for (int i=1; i<=n; i++){
        scanf("%Lf%Lf",&l[i],&b[i]);
        b[i]=b[i]/2;//半角
        l[i]=l[i]/2;//半底
        h[i]=l[i]/tan(b[i]);//高
        x[i]=l[i]/sin(b[i]);//弦长
    }
    long double s=0,maxpre=0;
    for (int i=1; i<=n; i++){
        long double ll=(maxpre-s*cos(a))/sin(pi/2+b[i]-a);//遮住的长度
        if (ll<x[i]) ans+=x[i]-ll;
        maxpre=max(maxpre,x[i]*sin(pi/2+b[i]-a)+s*cos(a));
        s+=h[i];
    }
    if (n<=1000){
    s=0,maxpre=0;
    for (int i=1; i<=n; i++){
        long double ll=(maxpre+s*cos(a))/sin(b[i]+a-pi/2);
        if (ll<x[i]&&ll>=0) ans+=x[i]-ll;
        maxpre=max(maxpre,x[i]*sin(b[i]+a-pi/2)-s*cos(a));
        s+=h[i];
    }
    printf("%.1Lf",ans+0.001);
    return 0;
    }
    s=0,maxpre=0;
    for (int i=1; i<=n; i++){
        long double ll=(maxpre+s*cos(a))/sin(b[i]+a-pi/2);
        if (ll<x[i]&&ll>0) ans+=x[i]-ll;
        maxpre=max(maxpre,x[i]*sin(b[i]+a-pi/2)-s*cos(a));
        s+=h[i];
    }
    printf("%.1Lf",ans+0.001);
    return 0;
}
```
*****


