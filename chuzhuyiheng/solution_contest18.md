[比赛链接](https://vjudge.net/contest/172100)

# 比赛中解决的问题
## A
### Problem description
>在一个n*m的矩形上,两个人先后放半径为r的圆盘,圆盘不能相叠,但边缘可以相交.
若有人放盘后没有多余的位置放下一个盘,则此人胜利.
若第一个人有必胜方案,则输出First,若第二个人有必胜方案,则输出Second.

### Data Limit：1 ≤ a, b, r ≤ 100 Time Limit: 2s

### Solution
>不要想太多,可以O(1)出解.
开局若可以放盘子,则放正中间.由于神奇的中心对称,总还剩下4n(n为自然数)个可放盘子的位置
这时第一个人只要放和第二个人对称的地方就能胜利.
所以,只要一开始有地方放,第一个人就赢了,否则第二个人才会赢.

### Code
```cpp
#include<cstdio>
int n,i,j,m,r;
int main()
{
	scanf("%d%d%d",&n,&m,&r);
	r=r*2;
	n=n/r;m=m/r;
	if (n==0||m==0)puts("Second");else puts("First");
	return 0;
}
```
*****


## B
### Problem description
> 给出两个多项式,
P(x) = a0·x^n + a1·x^n - 1 + ... + an - 1·x + an 
Q(x) = b0·x^m + b1·x^m - 1 + ... + bm - 1·x + bm.
求出P(x)/Q(x)的极限值.
### Data Limit：0 ≤ n, m ≤ 100 - 100 ≤ ai ≤ 100, a0 ≠ 0 - 100 ≤ bi ≤ 100, b0 ≠ 0  Time Limit: 2s
### Solution
>分类讨论
1.若m>n,则当x无限大时,P(x)/Q(x)为0.
2.若m<n,则当x无限大时,P(x)/Q(x)为正或负无限大,其正负与a0和b0有关.
3.若m=n,则当x无限大时,P(x)/Q(x)为a0/b0,化简后输出即可.

### Code
```cpp
#include<cstdio>
int n,i,j,m,r,t;
int a[10000],b[10000];
bool bo=false;
int gcd(int a,int b)
{
	if (a%b==0)return b;
	return gcd(b,a%b);
}
int main()
{
	scanf("%d%d",&n,&m);
	for (i=0;i<=n;i++)scanf("%d",&a[i]);
	for (i=0;i<=m;i++)scanf("%d",&b[i]);
	if (a[0]<0)
	{
		a[0]=-a[0];
		bo=true;
	}
	if (b[0]<0)
	{
		b[0]=-b[0];
		bo=!bo;
	}
	if (n>m)
	{
		if (bo)puts("-Infinity");else puts("Infinity");
		return 0;
	}
	if (n<m)
	{
		puts("0/1");
		return 0;
	}
	
	if (a[0]>b[0])t=gcd(a[0],b[0]);else t=gcd(b[0],a[0]);
	if (bo)printf("%s","-");
	printf("%d/%d",a[0]/t,b[0]/t);
	return 0;
}
```
*****

## C
### Problem description
>求一个字符串s的最大字典序子序列.

### Data Limit：length(s) <= 1e5  Time Limit: 1s

### Solution
>乱搞即可,先取光所有字典序最大的字符,然后取剩下的所有字典序最大的字符直至取光.

### Code
```pas
var
  s:ansistring;
  n,i,j:longint;
  hz:array[1..200000,'a'..'z']of longint;
  top:char;
begin
  readln(s);
  for i:=length(s) downto 1 do
  begin
    hz[i]:=hz[i+1];
    inc(hz[i,s[i]]);
  end;
  top:='z';
  for i:=1 to length(s) do
  begin
    while (hz[i,top]=0) do dec(top);
    if top=s[i] then write(s[i]);
  end;
end.

```
*****

# 赛后补题
## D
### Problem description
> 有一个迷宫由路和墙组成,且次迷宫无限,但每个n*m的矩阵是相同的.
若可以从给定的一个起点走到无限远处,则输出Yes,否则输出No

### Data Limit：1 ≤ n, m ≤ 1500  Time Limit: 1s
### Solution
>dfs,如果能从一个点,走到另一个矩阵的同一个点,则输出Yes,否则输出No

### Code
```cpp
#include <iostream>  
#include <cstdio>  
#include <cstring>  
#include <algorithm>  
  
using namespace std;  
  
const int maxn=2000;  
char mp[maxn][maxn];  
int n,m;  
  
typedef pair<int,int> pII;  
const int dir_x[4]={1,-1,0,0};  
const int dir_y[4]={0,0,1,-1};  
  
pII last[maxn][maxn];  
bool ret=false;  
  
void dfs(int x,int y)  
{  
    int mx=x%n,my=y%m;  
    if(mp[mx][my]=='#'||ret||last[mx][my]==pII(x,y)) return;  
    if(last[mx][my]!=pII(0,0))  
    {  
        ret=true; return ;  
    }  
    last[mx][my]=pII(x,y);  
    for(int i=0;i<4;i++)  
    {  
        dfs(x+dir_x[i],y+dir_y[i]);  
    }  
}  
  
int main()  
{  
    scanf("%d%d",&n,&m);  
    for(int i=0;i<n;i++)  
        scanf("%s",mp[i]);  
    int sx,sy;  
    for(int i=0;i<n;i++)  
    {  
        for(int j=0;j<m;j++)  
        {  
            if(mp[i][j]=='S')  
                sx=i,sy=j;  
        }  
    }  
    dfs(sx+n*m,sy+n*m);  
    if(ret) puts("Yes");  
    else puts("No");  
    return 0;  
}  

```
*****

## E
### Problem description
>给出一个n个点的树与在平面上的n个点,使这些点一一对应,并且节点之间的连线不相交.

### Data Limit：1 ≤ n ≤ 1500  Time Limit: 1s

### Solution
>由于没有3点共线的情况，所以解总是存在的。
 我们考虑以当前平面左下角的点p作为树根，对平面上的点以p做基准进行极角排序，则所有点与p点的连线都不会有除了p以外的交点。
 现在我们已经会填树根处的点了，对于树根的每个子节点，我们都可以递归的处理以其为根的子树，
 假设该子树包含x个节点，我们考虑以一根从p出发，长度不限的射线，从p的正下方开始按逆时针扫过去，
 直到扫过的平面包含x个节点即可停止。此时扫过的平面即为该子树应当处理的平面。
 每次处理需要先找到左下角的点，然后对当前平面的所有点进行排序，共需要处理n次，所以复杂度O(n^2*logn)。

### Code
```cpp
#include <cstdio>
#include <algorithm>
#include <vector>
#define inf 0x3f3f3f3f
#define met(a,b) memset(a,b,sizeof a)
#define pb push_back
typedef long long ll;
using namespace std;
const int N = 2005;
const int M = 24005;
pair<ll,ll>ori;
vector<ll>edg[N];
ll n,m,k;
ll sz[N],ans[N];
struct man{
    ll x,y,id;
    bool operator < (const man & b) const {
        return (x-ori.first)*(b.y-ori.second) - (y-ori.second)*(b.x-ori.first) > 0;
    }
}p[N];
void dfs1(ll u,ll fa){
    sz[u]=1;
    for(int i=0;i<edg[u].size();i++){
        ll v=edg[u][i];
        if(v==fa)continue;
        dfs1(v,u);
        sz[u]+=sz[v];
    }
}
void dfs2(ll u,ll fa,ll s,ll e){
    int pos;
    ll x,y;
    x=y=1e10;
    for(int i=s;i<=e;i++){
        if(p[i].x<x||((p[i].x==x)&&p[i].y<y)){
            x=p[i].x;y=p[i].y;pos=i;
        }
    }
    ori.first=x;ori.second=y;
    swap(p[s],p[pos]);
    sort(p+s+1,p+e+1);
    ans[p[s].id]=u;
    int cnt=0;
    for(int i=0;i<edg[u].size();i++){
        ll v=edg[u][i];
        if(v==fa)continue;
        dfs2(v,u,s+1+cnt,s+1+cnt+sz[v]-1);
        cnt+=sz[v];
    }
}
int main()
{
    ll T,u,v;
    scanf("%lld",&n);
    for(int i=1;i<n;i++){
        scanf("%lld%lld",&u,&v);
        edg[u].pb(v);edg[v].pb(u);
    }
    for(int i=0;i<n;i++){
        scanf("%lld%lld",&p[i].x,&p[i].y);
        p[i].id=i;
    }
    dfs1(1,0);
    dfs2(1,0,0,n-1);
    for(int i=0;i<n;i++)printf("%lld ",ans[i]);printf("\n");
    return 0;
}
```
