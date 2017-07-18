[比赛链接](https://cn.vjudge.net/contest/168561#overview)

# 比赛中解决的问题
## A
### Problem description
>在n个数中，从第二个数开始计算每一个数与其前一个数的差，保证数列是递增的。如果有差值超过给定的m，则把该差值对应的两个数及其前面所有数删去。问最后剩下几个数。

### Data Limit：n<=1e5  Time Limit:2s

### Solution
> 按题意模拟。如果a[i]-a[i-1]<=m，则cnt++，否则cnt=1。最后输出cnt即可。

### Code
```cpp
#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<algorithm>
using namespace std;
int main()
{
	int a[100005],n,m,cnt=1;
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;++i)
	scanf("%d",&a[i]);
	for (int i=2;i<=n;++i)
	{
    	if (a[i]-a[i-1]<=m) cnt++;
    	else cnt=1;
	}
	printf("%d\n",cnt);
	return 0;
}
```
*****


## B
### Problem description
> 给出一个字符串，字符串只含有大写字母或问号。问号可以被任意大写字母替代。若字符串的长度小于26，则输出-1。否则在字符串中寻找一段长度为26的连续的子串，若能找到一个子串，子串中的26个大写字母互不相同，则输出所有问号被替代为大写字母的改变后的字符串。否则输出-1。

### Data Limit：n<=5e4  Time Limit:2s

### Solution
> 按题意模拟。刚开始记flag=true。枚举每一个子串的开头，搜索以该字母位置为开头的子串，计算里面出现的每个字母的个数和问号的个数。问号的个数直接加入cnt2，而若子串中字母出现的次数为一次，则加入cnt1。如果cnt1+cnt2==26，则说明该子串可行，将flag改为false，并将子串中的问号相应改为大写字母，使得这些字母互不重复。改完后其他问号只要改为随便一个大写字母即可（此处用字母Z）。最后若flag为true，则输出-1，否则输出修改完的字符串。

### Code
```cpp
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
using namespace std;
char s[50010];
int b[27];
int main()
{
    while(scanf("%s",s)!=EOF)
    {
        int flag=true;
        int len=strlen(s);
        if(len<26)
        {
            printf("-1\n");
            continue;
        }
        memset(b,0,sizeof(b));
        for(int i=0;i<=len-26 && flag==true;i++)
		{
            memset(b,0,sizeof(b));
            int cnt1=0,cnt2=0;
            for(int j=i;j<i+26;j++)
			{
                if(s[j]>='A' && s[j]<='Z')
			    {
                    b[s[j]-'A']++;
                }
                else cnt2++;
            }
            for(int j=0;j<26;j++)
            if(b[j]==1) cnt1++;
            if(cnt2+cnt1 == 26)
            {
                int t=0;
                for(int j=i;j<i+26;j++)
			    {
                    if(s[j]=='?')
                    {
                        for(;t<26;t++)
				    	{
                            if(b[t]==0)
					    	{
                                s[j]='A'+t;
                                t++;
                                break;
                            }
                        }
                    }
                }
                flag=false;
            }
        }
        for(int i=0;i<len;i++)
    	{
            if(s[i]=='?')
            s[i]='Z';
        }
        if(flag==true) printf("-1\n");
        else printf("%s\n",s);
    }
    return 0;
}
```
*****


## C
### Problem description
> 输入整数n。我们要玩一个游戏，使得等级达到(n+1)级。游戏机上有两个操作，加和根号。按一下加可使屏幕上的数加上自己的等级，若屏幕上的数变为一个完全平方数，则可以开根号，若开出的数可以被(当前的等级+1)整除，则可以升一级。问每次升级需要点击加号的次数为多少（所以输出n个数）。输出任意一种可行解即可。

### Data Limit：n<=1e5  Time Limit:2s

### Solution
>数学法求解。我们可以设每一次开根号出来的数为(n+1)×n，则相对上一次开出来的数n×(n-1)，需要加上数的总和为(n+1)^2×n^2-n×(n-1)，则次数为总和除以n，化简得n^3+2×n^2+1,所以第一个数输出2，接下来的数输出i^3+2×i^2+1即可。

### Code
```cpp
#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<algorithm>
using namespace std;
long long i,j,n,k,now=2;
long long a[100005];
int main()
{
	scanf("%I64d",&n);
	printf("2\n");
	for (i=2;i<=n;++i)
	printf("%I64d\n",i*i*i+i*i*2+1);
	return 0;
}
```
*****

# 赛后补题

## D
### Problem description
> 给出整数n，m，l，s，t。有n个节点，m条边，要使得从s到t的最短路为l。当然，给出的m条边可能并不会使s到t的最短路为l。给出的边中会有一些边的边权为0。可修改边权为0的边权，使得构成长度为l的，从s到t的最短路。若无法构成长度为l的最短路，则输出NO。否则输出YES，再输出修改后的边（所有边都要输出）。

### Data Limit：n<=1e3，m<=1e4，l<=1e9  Time Limit:4s

### Solution
> 迪杰斯特拉求最短路。先计算从t到其他所有点的最短路ret[i]，若从t到s的最短路已小于给定的l，则肯定无解，输出NO。否则再从s到t搜最短路dis[i]，搜的过程中，若节点u，v之间的边权为0，则可改变，改变的值为(l-ret[u]-dis[v])，则恰可使s到t的最短路为l。当然改变过程中若(l-ret[u]-dis[v])的值小于等于0，则可将该边权改为1。最后判断若最短路的长度不等于l，输出NO。否则输出YES和所有边。

### Code
```cpp
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
int n,m,i,j,k,S,T,cnt;
int head[1005],U[10005],V[10005];
long long L,dis[1005],ret[1005],len[10005],ans;
bool vis[1005];
struct node{
	int to,next;
	long long len;
}e[20010];
void add(int u,int v,int len)
{
	e[++cnt]=(node){v,head[u],len};
	head[u]=cnt;
}
int main()
{
	scanf("%d%d%I64d%d%d",&n,&m,&L,&S,&T);
	cnt=1;
	for (i=1;i<=m;++i)
	{
		scanf("%d%d%I64d",&U[i],&V[i],&len[i]);
		add(U[i],V[i],len[i]);
		add(V[i],U[i],len[i]);
	}
	memset(ret,60,sizeof(ret));
	memset(vis,0,sizeof(vis));
	ret[T]=0;
	for (i=1;i<=n;++i)
	{
		k=-1;
		for (j=0;j<n;++j)
		if (!vis[j]&&(k==-1||ret[j]<ret[k])) k=j;
		vis[k]=1;
		for (j=head[k];j!=0;j=e[j].next)
		{
			int v=e[j].to;
			if (e[j].len&&ret[k]+e[j].len<ret[v]) ret[v]=ret[k]+e[j].len;
		}
	}
	if (ret[S]<L)
	{
		printf("NO\n");
		return 0;
	}
	memset(dis,60,sizeof(dis));
	memset(vis,0,sizeof(vis));
	dis[S]=0;
	for (i=1;i<=n;++i)
	{
		k=-1;
		for (j=0;j<n;++j)
		if (!vis[j]&&(k==-1||dis[j]<dis[k])) k=j;
		vis[k]=1;
		for (j=head[k];j!=0;j=e[j].next)
		{
			int v=e[j].to;
			if (!e[j].len)
			{
				if (ret[v]<ret[n]) e[j].len=L-ret[v]-dis[k];
				else e[j].len=1;
				if (e[j].len<=0) e[j].len=1;
				e[j^1].len=len[j/2]=e[j].len;
			}
			if (dis[k]+e[j].len<dis[v]) dis[v]=dis[k]+e[j].len;
		}
	}
	if (dis[T]!=L)
	{
		printf("NO\n");
		return 0;
	}
	printf("YES\n");
	for (i=1;i<=m;++i)
	printf("%d %d %I64d\n",U[i],V[i],len[i]);
	return 0;
}
```
*****

## E
### Problem description
> 给出一棵有n个节点的树，每条边都有权值，若点对(u,v)之间的边按顺序组成的十进制码能整除m，则该点对被我们选中。问有多少点对被我们选中。

### Data Limit：n<=1e5，m<=1e9  Time Limit:3s

### Solution
> 点分治，树的重心，邻接表存边。

### Code
```cpp
#include<iostream>
#include<cstdlib>
#include<cstring>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<map>
#define int long long
using namespace std;
const int N=100010;
int n,m,p,x,y,z,tot=1,ans,root,rmn;
int fi[N],ne[N<<1],va[N<<1],ar[N<<1],inv[N],si[N];
map<int,int> mp;
inline void extgcd(int x,int y,int &a,int &b)
{
	if (!y)
	{
	    a=1;
		b=0;
		return;
	}
	extgcd(y,x%y,b,a);
	b-=x/y*a;
}
inline int adde(int x,int y,int z)
{
	ar[++tot]=y;
	va[tot]=z;
	ne[tot]=fi[x];
	fi[x]=tot;
}
inline void get_size(int x,int fa)
{
	si[x]=1;
	for (int i=fi[x];i;i=ne[i])
	if (ar[i]&&ar[i]!=fa)
	{
		get_size(ar[i],x);
		si[x]+=si[ar[i]];
	}
}
inline void get_root(int x,int fa,int susi)
{
	int mx=susi-si[x];
	for (int i=fi[x];i;i=ne[i])
	if (ar[i]&&ar[i]!=fa)
	{
		get_root(ar[i],x,susi);
		mx=max(mx,si[ar[i]]);
	}
	if (mx<rmn)
	{
		rmn=mx;
		root=x;
	}
}
inline void get_d1(int x,int fa,int no,int qu)
{
	++mp[no];
	for (int i=fi[x];i;i=ne[i])
	if (ar[i]&&ar[i]!=fa) get_d1(ar[i],x,(no+va[i]*qu)%p,qu*10%p);
}
inline int get_d2(int x,int fa,int no,int de)
{
	int sum=mp[(-no*inv[de]%p+p)%p];
	for (int i=fi[x];i;i=ne[i])
	if (ar[i]&&ar[i]!=fa) sum+=get_d2(ar[i],x,(no*10+va[i])%p,de+1);
	return sum;
}
inline int cal(int x,int v)
{
	mp.clear();
	get_d1(x,0,v%p,v?10:1);
	return get_d2(x,0,v%p,v?2:1)-(v==0);
}
inline void solve(int x)
{
	get_size(x,0);
	rmn=1e9;
	get_root(x,0,si[x]);
	ans+=cal(root,0);
	for (int i=fi[root];i;i=ne[i])
	if (ar[i])
	{
		ar[i^1]=0;
		ans-=cal(ar[i],va[i]);
		solve(ar[i]);
	}
}
main()
{
	scanf("%lld%lld",&n,&p);
	int _temp,inv10;
	extgcd(10,p,inv10,_temp);
	inv[1]=1;
	for (int i=2;i<=n;++i)
	inv[i]=(inv[i-1]*inv10)%p;
	for (int i=1;i<n;++i)
	{
		scanf("%lld%lld%lld",&x,&y,&z);
		adde(x+1,y+1,z);
		adde(y+1,x+1,z);
	}
	solve(1);
	printf("%lld",ans);
	return 0;
}
```
