[比赛链接](http://www.hzxjhs.com:83/contest/749)

# 比赛中解决的问题
## A 数列
### Problem description
> 输入整数T表示数据组数。每组数据中输入两个整数k，n，再输入n个数，找到一段连续的区间，使得该区间内所有数的和能被k整除，问有多少这样的区间。

### Data Limit:100%数据满足:1<=T<=20,1<=N<=50000,1<=K<=1000000,序列的每个数<=1000000000; 30%数据满足:1<=T<=10,1<=N,K<=1000  Time Limit:1s

### Solution
> 按题意模拟。计算所有数的前缀和对k取模的值，用这些值组成一个新的含有n个数的序列，在序列的开头添上0，构成含有(n+1)个元素的序列。仔细分析我们可以知道若数列中存在两个相同的数，则ans++，所以我们只要找出所有的相同的数的组数即可。

### Code
```cpp
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm> 
using namespace std;
long long t,n,k,ans;
long long a[50010],s[50010],c[1000010];
int main()
{
	scanf("%d",&t);
	while (t--)
	{
		memset(c,0,sizeof(c));
		c[0]=1; ans=0;
		scanf("%d%d",&k,&n);
		for (long long i=1;i<=n;++i)
		{
			scanf("%d",&a[i]);
			s[i]=s[i-1]+a[i];
		    s[i]%=k;
		    ++c[s[i]];
		}
		for (long long i=0;i<k;++i)
		ans+=(c[i]-1)*c[i]/2;
		printf("%d\n",ans);
	}
	return 0;
}
```
*****


## B 钓鱼
### Problem description
> 有一个人在河面上钓鱼。我们把钓鱼的过程放在坐标系里来考虑。船初始时的坐标记为(Ax,y)。河深为y，河宽为x。某个时刻会从左边界或右边界游出来一条鱼(左边的往右边游，右边的往左边游)，即鱼游出来时的横坐标为0或x，这条鱼每秒会游D个单位长度，鱼的长度为L。初始时刻为0，对于每个时刻x，船可以选择花费1s向左或向右移动最多Q个单位长度，或者选择在当前位置进行钓鱼，钓鱼的动作是瞬间的，且发生在时刻x，鱼还来不及移动就被钓上了。如果选择钓鱼，那么在时刻x就不能动(x+1时刻可以选择移动)。设当前位置为z，将鱼看成一条线段，当线段与直线x=z相交时就认为鱼上钩了，所以一次钓鱼动作可能会钓多条鱼。聪明的你告诉钓鱼者，在T时刻前最多能钓多少鱼。

### Data Limit:100%的数据满足:1<=T,time<=10,1<=Ax,Ay,Q,x,y,D,L<=10,1<=N<=14; 30%的数据满足:1<=N<=5  Time Limit:1s
### Solution
> 状压DP。用can记录在i时刻j位置处能抓到哪些鱼（二进制法记录）。然后dfs中状压求每个时刻能到达的位置上最多能抓到多少条鱼。

### Code
```cpp
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
int T,maxx,maxy,ax,q,n,ans=0;
int x[15],y[15],d[15],l[15],t[15];
int can[15][15];
int f[15][15][1<<15];
void dfs(int x,int t,int now,int tot)
{
    if (t>T)
	{
	    ans=max(tot,ans);
		return;
	}
    if (f[x][t][now]>tot) return;
    f[x][t][now]=tot;
    for (int i=max(0,x-q);i<=min(maxx,x+q);++i)
	dfs(i,t+1,now,tot);
    int cnt=0,next=now|can[t][x];
    for (int i=0;i<n;++i)
	if (next&(1<<i)) ++cnt;
    dfs(x,t+1,next,cnt);
}
int main()
{
	scanf("%d",&T);
	scanf("%d%d",&maxx,&maxy);
	scanf("%d%d",&ax,&q);
	scanf("%d",&n);
	for (int i=0;i<n;++i)
	scanf("%d%d%d%d%d",&x[i],&y[i],&d[i],&l[i],&t[i]);
	for (int i=0;i<=T;++i)
    for (int j=0;j<=maxx;++j)
    for (int k=0;k<n;++k)
	{
        if (x[k]==0&&(i-t[k])*d[k]>=j&&(i-t[k])*d[k]-l[k]<=j) can[i][j]|=(1<<k);
        if (x[k]==maxx&&maxx-(i-t[k])*d[k]<=j&&maxx-(i-t[k])*d[k]+l[k]>=j) can[i][j]|=(1<<k);
    }
    dfs(ax,0,0,0);
    cout<<ans<<endl;
    return 0;
}
```
*****


## D 键盘
### Problem description
> 我们的每根手指打字时都有疲劳度。每按一次键，拇指的疲劳度为a，食指的疲劳度为b，中指的疲劳度为c，无名指的疲劳度为d，小指的疲劳度为e。现在让你来设计键盘，即对于一个字符，安排一个键，一个键只拥有一个字符。使得打印给定的文章的疲劳度最小。规定：键盘只包括原键盘第2行'`'到'\',第三行'Q'到']',第四行'A'到''',第五行'Z'到'/'，第六行的空格键。字符只包括键盘上的字符，对于一个键有2个字符的，只考虑下面那个字符，即对于一个键X，它代表的字符是按一下X所打印的字符，而不是SHIFT+X打印出来的字符。输入不会出现其他字符。(英文字母为大写)

### Data Limit:100%数据满足:0<=a,b,c,d,e<=100,1<=N<=1000000; 30%数据满足:1<=N<=100  Time Limit:1s
### Solution
> 贪心。打的越多的字母，我们要使其对应越小的疲劳度，这样才能使总疲劳度最小。于是我们先读入每根手指的疲劳度，拇指管理1个键，食指管理16个键，中指管理8个键，无名指管理8个键，小指管理15个键。我们将手指的记录数组按疲劳度从小到大排序。统计给定的文章中各字符的出现次数(先按各字符的ASCII码存)，然后从大到小sort，最后相应位置的字符出现数乘以手指的疲劳度即可。

### Code
```cpp
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<string>
using namespace std;
struct node{
	int cnt,val;
}a[5];
bool cmp(node a,node b){
	return a.val<b.val;
}
bool maxx(int a,int b){
	return a>b;
}
int b[500],n,m,ans=0;
string s;
int main()
{
	for (int i=0;i<5;++i)
	scanf("%d",&a[i].val);
	a[0].cnt=1;
	a[1].cnt=16;
	a[2].cnt=8;
	a[3].cnt=8;
	a[4].cnt=15;
	sort(a,a+5,cmp);
	scanf("%d",&n);
	getline(cin,s);
	getline(cin,s);
	memset(b,0,sizeof(b));
	for (int i=0;i<n;++i)
	{
		if (s[i]>='A'&&s[i]<='Z')
		{
			s[i]+=32;
		}
		++b[s[i]];
	}
	sort(b,b+500,maxx);
	for (int i=0;i<500;++i)
	if (b[i]==0)
	{
		m=i;
		break;
	}
	int j=0,k,tot=0;
	while (tot<m)
	{
		k=0;
		for (int i=tot;i<min(tot+a[j].cnt,m);++i)
		k+=b[i];
		ans+=a[j].val*k;
		tot+=a[j].cnt;
		++j;
	}
	printf("%d\n",ans);
	return 0;
}
```
*****

# 赛后补题

## C 雪
### Problem description
> 有一棵树。树是由N个等腰三角形构成的，每个三角形的对称轴在y轴上，且每个三角形与上面和下面的三角形有接触。雪以与x轴成a角(0<a<pi)下落，问雪与三角形有接触的长度是多少?(也可以理解为成a角的平行光源射向树，问被照亮的长度)(输入数据时，三角形从上向下输入)

### Data Limit:100%的数据满足:0<a<pi,0<A<1000,A为实数,0<B<pi,1<=N<=1000000; 30%的数据满足:1<=N<=100,且a=pi/2.  Time Limit:2s

### Solution
> 三角函数法求解。刚开始a角如果大于pi/2，那么将a转化为其互补的角求解，结果应该是一样的。于是树右边的最上方的三角形的右腰一定能整段被雪覆盖，加入答案。将第一个三角形的右端点设为雪向下的边界点。接下来根据a角和下一个等腰三角形的顶角的一半的余角联立方程计算出下一个三角形不被雪覆盖的长度。若长度小于下一个三角形的腰，则三角形有一段被雪覆盖，加入答案，并将该三角形的右端点设为雪向下的边界点。处理树的左边时方法类似。于是最终得到了树上被雪覆盖的总长度。（注：据说该题卡精度，加上0.001防卡）

### Code
```cpp
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>
#include<algorithm>
#define pi 3.14159265358
using namespace std;
struct node{
	double di,jiao,l,h;
}a[1000010];
double b,x,y,ans,d;
int n;
using namespace std;
int main()
{
	scanf("%lf",&b);
	scanf("%d",&n);
	if (b>pi/2) b=pi-b;
	for (int i=1;i<=n;++i)
	{
		scanf("%lf%lf",&x,&y);
		a[i].di=x/2;
		a[i].jiao=y/2;
		a[i].l=a[i].di/sin(y/2);
		a[i].h=a[i].di/tan(y/2);
	}
	ans=a[1].l;
	d=a[1].di;
	for (int i=2;i<=n;++i)
	{
		double x=d*tan(b)/(tan(b)+tan(pi/2-a[i].jiao));
		double y=x/cos(pi/2-a[i].jiao);
		if (y<a[i].l)
		{
			ans+=a[i].l-y;
			d=a[i].di;
		}
		else d-=a[i].h/tan(b);
	}
	if (pi/2-a[1].jiao<b)
	{
		ans+=a[1].l;
		d=a[1].di;
	}
	else d=a[1].h/tan(b);
	for (int i=2;i<=n;++i)
	{
		if (pi/2-a[i].jiao>b)
		{
			d+=a[i].h/tan(b);
			continue;
		}
		double x=d*tan(pi/2-b)/(tan(a[i].jiao)-tan(pi/2-b));
		double y=(x+d)/cos(pi/2-a[i].jiao);
		if (y<a[i].l)
		{
			ans+=a[i].l-y;
			d=a[i].di;
		}
		else d+=a[i].h/tan(b);
	}
	printf("%0.1lf\n",ans+0.001);
	return 0;
}
```
*****
