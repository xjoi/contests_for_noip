[比赛链接](https://cn.vjudge.net/contest/172423)

# 比赛中解决的问题
## A
### Problem description
> 给出整数a，b，n，我们在a后面添数0~9，总共添n次，问是否每次添数都能使改变后的a被b整除，若能输出最终改变的数，否则输出-1。

### Data Limit:1≤a,b,n≤1e5  Time Limit:2s

### Solution
> 数学分析题。我们只需要考虑加第一位时，改变后的数能否被b整除，若能，根据数的整除性，我们后面只需要全部添0即可。否则输出-1。

### Code
```cpp
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
int a,b,n;
bool flag=0;
int main()
{
	scanf("%d%d%d",&a,&b,&n);
	for (int i=0;i<=9;++i)
	{
		if ((a*10+i)%b==0)
		{
			printf("%d",a*10+i);
			flag=1;
			break;
		}
	}
	if (!flag)
	{
		printf("-1\n");
		return 0;
	}
	for (int i=1;i<n;++i)
	printf("0");
	return 0;
}
```
*****


## B
### Problem description
> 在字符串中若有dd-mm-yyyy的形式，可视为存在日期的格式，当然日期必须正确，即存在这个真实的日期。在字符串s中找出出现次数最多的日期并输出。保证年份在2013~2015的范围内。

### Data Limit:字符串长度<=1e5  Time Limit:1s

### Solution
> 按题意模拟。枚举日期字符串的头，向后搜十位，若符合日期格式，再判断该日期是否合法，由于2013~2015年都是平年，所以容易判断，再记录该日期的出现次数，若该日期出现的次数最大，标记该开头位置即可。

### Code
```cpp
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
int f[5][15][35],a[13]={0,31,28,31,30,31,30,31,31,30,31,30,31},ans=0,id=0;
char s[100005];
bool check(char x)
{
	if (x>='0'&&x<='9') return true;
	return false;
}
int main()
{
	scanf("%s",s);
	memset(f,0,sizeof(f));
	int len=strlen(s);
	for (int i=0;i<len-9;++i)
	{
		bool flag=1;
		if (!check(s[i])) flag=0;
		if (!check(s[i+1])) flag=0;
		if (s[i+2]!='-') flag=0;
		if (!check(s[i+3])) flag=0;
		if (!check(s[i+4])) flag=0;
		if (s[i+5]!='-') flag=0;
		if (!check(s[i+6])) flag=0;
		if (!check(s[i+7])) flag=0;
		if (!check(s[i+8])) flag=0;
		if (!check(s[i+9])) flag=0;
		if (flag)
		{
			int d=(s[i]-48)*10+s[i+1]-48;
			int m=(s[i+3]-48)*10+s[i+4]-48;
			int y=(s[i+6]-48)*1000+(s[i+7]-48)*100+(s[i+8]-48)*10+s[i+9]-48;
			if (y<2013||y>2015) flag=0;
			if (m<1||m>12) flag=0;
			if (d<1||d>a[m]) flag=0;
			if (flag)
			{
				++f[y-2013][m][d];
				if (f[y-2013][m][d]>ans)
				{
					ans=f[y-2013][m][d];
					id=i;
				}
			}
		}
	}
	for (int i=id;i<id+10;++i)
	printf("%c",s[i]);
	return 0;
}
```
*****


## C
### Problem description
> 给出整数n，x，即有n个盒子。这些盒子按1~n的顺序环形排好。我们从一个盒子里取出所有球，然后往后开始一个盒子放一个球直至结束。最后一个放球的盒子是x。给定盒子里的球的放完后的序列，求放之前的序列。

### Data Limit:2≤n≤1e5,1≤x≤n  Time Limit:1s

### Solution
> 贪心。分析易知，放完后装有最少的球的盒子是起先被取出所有球的盒子。先找出这个最小值，然后将盒子x的球减一个，再向前找，重复此操作，直到遇到这个最小值，然后除此盒子外其他所有盒子都减去该盒子的数值，该盒子的值改为球的总数减去其他盒子里的球的数量即可。

### Code
```cpp
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
long long n,x,a[100005],Min=1e9,tot=0;
int main()
{
	scanf("%I64d%I64d",&n,&x);
	for (int i=1;i<=n;++i)
	{
		scanf("%I64d",&a[i]);;
		Min=min(Min,a[i]);
		tot+=a[i];
	}
	while (a[x]!=Min)
	{
		a[x]--;
		x--;
		if (x==0) x=n;
	}
	for (int i=1;i<=n;++i)
	if (i!=x) tot-=a[i]-Min;
	for (int i=1;i<=n;++i)
	if (i==x) printf("%I64d ",tot);
	else printf("%I64d ",a[i]-Min);
	return 0;
}
```
*****


## D
### Problem description
> 树的节点有不同的颜色，且已知每个节点与自己相连边的总权值。要求相同颜色的点不能连边。求构造这棵树，输出它的边，输出顺序可任意。

### Data Limit:2≤n≤1e5  Time Limit:1s

### Solution
> 贪心。先将颜色不同的点分开放，然后从小到大排序，每次取出最小的两条边然后构树。

### Code
```cpp
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
using namespace std;
int n,a,b;
int main()
{
	vector< pair<int,int> > u,v;
	scanf("%d",&n);
	for (int i=1;i<=n;++i)
	{
		scanf("%d%d",&a,&b);
		if (a==0) u.push_back({b,i});
		if (a==1) v.push_back({b,i});
	}
	sort(u.begin(),u.end());
	sort(v.begin(),v.end());
	for (int i=0,j=0;i<u.size(),j<v.size();)
	{
		int Min=min(u[i].first,v[j].first);
		printf("%d %d %d\n",u[i].second,v[j].second,Min);
		u[i].first-=Min;
		v[j].first-=Min;
		if (u[i].first) ++j;
		else if (v[j].first) ++i;
		else if (i+1<u.size()) ++i;
		else ++j;
	}
	return 0;
}
```
*****

# 赛后补题

## E
### Problem description
> 给出n个点的坐标，再给出9个整数组成的序列。要求求出两条铅垂线和两条水平线，使平面被分为9块，每一块里点的数量满足给定的序列，相应满足的个数的顺序可任意。

### Data Limit:9≤n≤1e5  Time Limit:2s

### Solution
> 全排列+log级别的搜索。

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
int x[maxn],y[maxn],symx[maxn],symy[maxn],tmp[maxn],a[10];
int n,cnt=0,h[maxn],xx[maxn],yx[maxn],t[maxn],tx[205][maxn];
bool cmpx(int u,int v)
{
    return x[u]<x[v];
}
bool cmpy(int u,int v)
{
    return y[u]<y[v];
}
int check(int u,int v,int goal)
{
    if (xx[u]==-1||yx[v]==-1) return 0;
    int r=h[u],s=yx[v];
    for (int i=s;i;i-=i&(-i))
	goal-=tx[r][i];
    return goal==0;
}
int main()
{
    scanf("%d",&n);
    for (int i=1;i<=n;i++)
	scanf("%d%d",&x[i],&y[i]);
    for (int i=1;i<=9;i++)
	scanf("%d",&a[i]);
    sort(a+1,a+10);
    for (int i=1;i<=9;i++)
    for (int j=i+1;j<=9;j++)
    for (int k=j+1;k<=9;k++)
	{
        int p=a[i]+a[j]+a[k];
        if (!h[p]) h[p]=++cnt;
        if (!h[n-p]) h[n-p]=++cnt;
    }
    for (int i=1;i<=n;i++)
	tmp[i]=i;
    sort(tmp+1,tmp+n+1,cmpy);
    for (int i=1,opt=1;i<=n;i++)
	{
        symy[opt]=y[tmp[i]];
        if (y[tmp[i]]==y[tmp[i+1]])
		{
			yx[i]=-1;
			y[tmp[i]]=opt;
		}
        else
		{
			yx[i]=opt;
			y[tmp[i]]=opt++;
		}
    }
    for (int i=1;i<=n;i++)
	tmp[i]=i;
    sort(tmp+1,tmp+n+1,cmpx);
    for (int i=1,opt=1;i<=n;i++)
    {
        symx[opt]=x[tmp[i]];
        if (x[tmp[i]]==x[tmp[i+1]])
		{
			xx[i]=-1;
			x[tmp[i]]=opt;
		}
        else
		{
			xx[i]=opt;
			x[tmp[i]]=opt++;
		}
    }
    for (int i=1;i<=n;i++)
	{
        for (int j=y[tmp[i]];j<=n;j+=j&(-j))
		t[j]++;
		if (h[i]&&xx[i]!=-1) memcpy(tx[h[i]],t,sizeof(t));
	}
	while (1)
	{
	    int a1=a[1]+a[2]+a[3],a2=a1+a[4]+a[5]+a[6],a3=a[1]+a[4]+a[7],a4=a3+a[2]+a[5]+a[8];
		if (check(a3,a1,a[1])&&check(a4,a1,a[1]+a[2])&&check(a3,a2,a[1]+a[4])&&check(a4,a2,a[1]+a[2]+a[4]+a[5]))
		{
			printf("%0.10lf %0.10lf\n%0.10lf %0.10lf\n",symx[xx[a3]]+0.5,symx[xx[a4]]+0.5,symy[yx[a1]]+0.5,symy[yx[a2]]+0.5);
			return 0;
		}
		if (!next_permutation(a+1,a+10))
		{
			printf("-1\n");
			return 0;
		}
	}
	return 0;
}
```
