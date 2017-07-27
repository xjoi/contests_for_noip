[比赛链接](https://www.codeforces.com)

# 比赛中解决的问题
## A
### Problem description
> 求r到l间的是k的幂的数

### Data Limit：1 ≤ l ≤ r ≤ 10e18, 2 ≤ k ≤ 10e9  Time Limit: 1s

### Solution
>暴力求,注意要用long long
为防止前一个数*k后爆long long,可以判一下1e18/k是否大于前一个数

### Code
```cpp
#include<cstdio>
long long r,l,k,n,i,j,t,t1;
int main()
{
	bool bo=false;
	scanf("%lld%lld%lld",&l,&r,&k);
	t=1;
	while (t<=r)
	{
		if (t>=l&&t<=r)
		{
			printf("%lld ",t);
			//if (t==r)break;
			bo=true;
		}
		t1=t;					
		t=t*k;					
		if (t/k!=t1)break;
	}
	long long tt=-1;
	if (!bo)printf("%lld",tt);
	return 0;
}
```
*****


## B
### Problem description
> 求n个数的乘积,但n个数中至少有n-1个美丽数
美丽数是最多有一个1,其他是0的数

### Data Limit: 1 ≤ n ≤ 100 000Time Limit: 1s
### Solution
> 首先,由于数可能很大,不能用long long读,要用字符串
然后通过找空格挑出n个数,判断末尾共有几个0,再找出那个普通数,在后面加0即可.
注意特判没有普通数的情况

### Code
```pas
var s,t,ans:ansistring;
    i,j,n,tt,l:longint;
begin
  readln(n);
  readln(t);
  t:=t+' ';
  for l:=1 to n do
  begin
    s:=copy(t,1,pos(' ',t)-1);
    if s[1]='0' then
    begin
      write(0);
      halt;
    end;
    while s[length(s)]='0' do
    begin
      inc(tt);
      delete(s,length(s),1);
    end;
    if (length(s)<>1)or(s[1]<>'1')then
    ans:=s;
    delete(t,1,pos(' ',t));
    if l<>n then while (t[1]=' ') do delete(t,1,1);
  end;
  write(ans);
  if ans='' then write(1);
  for i:=1 to tt do write(0);
end.
```
*****

# 赛后补题

## C
### Problem description
> 给一个多边形的n个点与旋转中心,求多边形经过的路径面积

### Data Limit：3<=n <= 1e5  Time Limit: 1s

### Solution
> 易得路径是一个环,求最大半径和最小半径然后套公式
注意:最大半径一定是顶点到旋转中心的距离,但最小半径可能是点到边的垂线段长

### Code
```cpp
#include<cstdio>
#include<cmath>
using namespace std;
long long px,py,x[1000000],y[1000000],n,i,j,ans1[10000],pi,lp,lans,hh,p[1000000],lll[10000],ll;
double l1[100][10],d;
double max,min,ans;
double PointToSegDist(double x, double y, double x1, double y1, double x2, double y2)
{
double cross = (x2 - x1) * (x - x1) + (y2 - y1) * (y - y1);
if (cross <= 0) return sqrt((x - x1) * (x - x1) + (y - y1) * (y - y1));

double d2 = (x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1);
if (cross >= d2) return sqrt((x - x2) * (x - x2) + (y - y2) * (y - y2));
 
l1[i][1]=y1-y2;
l1[i][2]=x2-x1;
l1[i][3]=-l1[i][1]*x1-l1[i][2]*y1;
d=(abs(l1[i][1]*px+l1[i][2]*py+l1[i][3]))/sqrt(l1[i][1]*l1[i][1]+l1[i][2]*l1[i][2]);
return(d);
}
int main()
{
	scanf("%lld%lld%lld",&n,&px,&py);max=-10000;min=10000000000000;
	for (i=1;i<=n;i++)
	{
		scanf("%lld%lld",&x[i],&y[i]);
		d=(px-x[i])*(px-x[i])+(py-y[i])*(py-y[i]);
		if (d>=max)max=d;
		if (d<=min)min=d;
	}
	for (i=2;i<=n;i++)
	{
		
		
		/*l1[i][1]=y[i]-y[i-1];
		l1[i][2]=x[i-1]-x[i];
		l1[i][3]=-l1[i][1]*x[i]-l1[i][2]*y[i];
		d=(abs(l1[i][1]*px+l1[i][2]*py+l1[i][3]))/sqrt(l1[i][1]*l1[i][1]+l1[i][2]*l1[i][2]);
		d=d*d;*/
		d=PointToSegDist(px,py,x[i],y[i], x[i-1], y[i-1]);
		d=d*d;
		if (d>=max)max=d;
		if (d<=min)min=d;
	}
	d=PointToSegDist(px,py,x[1],y[1], x[n], y[n]);
	d=d*d;
	if (d>=max)max=d;
	if (d<=min)min=d;
	ans=(max-min)*3.1415926535897932384626433;
	printf("%.18f",ans);
	
	return 0;
}
```
*****

## D
### Problem description
>有n个技能,给出初始等级和金币m(一金可以给一个技能升一级),求出最大威力.
威力:满级技能的个数(每个技能满级相同为A)乘mp(给出)+最低等级的技能等级乘mc(给出).

### Data Limit：1 ≤ n ≤ 100 000, 1 ≤ A ≤ 109, 0 ≤ cf, cm ≤ 1000, 0 ≤ m ≤ 1015 Time Limit: 1s

### Solution
>按等级排序,从后向前枚举升满的技能数,然后二分求出剩下的金币可以做到的最低技能等级的最大值,然后求出此时威力.

### Code
```cpp
#include<cstdio>   
#include<iostream>  
#include<algorithm>  
using namespace std;  
#define MS(x,y) memset(x,y,sizeof(x))  
#define MC(x,y) memcpy(x,y,sizeof(x))  
#define MP(x,y) make_pair(x,y)  
#define ls o<<1  
#define rs o<<1|1  
typedef long long LL;  
typedef unsigned long long UL;  
typedef unsigned int UI;  
template <class T1, class T2>inline void gmax(T1 &a, T2 b) { if (b > a)a = b; }  
template <class T1, class T2>inline void gmin(T1 &a, T2 b) { if (b < a)a = b; }  
const int N = 1e5 + 10, M = 0, Z = 1e9 + 7, ms63 = 0x3f3f3f3f;  
int n; LL m;  
int A; LL cf, cm;  
LL sum[N];  
struct Skill  
{  
    int v, o;  
}a[N];  
bool cmp1(Skill a, Skill b)  
{  
    return a.v < b.v;  
}  
bool cmp2(Skill a, Skill b)  
{  
    return a.o < b.o;  
}  
int solve(int R, LL now)  
{  
    if (R == 0)return A;  
    int l = 1;  
    int r = R;  
    while (l < r)  
    {  
        int mid = (l + r + 1) >> 1;  
        LL need = (LL)a[mid].v * mid - sum[mid];//»¹ÐèÒª»¨·ÑÕâÃ´¶à²ÅÄÜ´ïµ½µÚmid¸öÈËµÄË®Æ½  
        if (need > now)r = mid - 1;  
        else l = mid;  
    }  
    LL need = (LL)a[l].v*l - sum[l];  
    LL more = (now - need) / l;  
    return min((LL)A, a[l].v + more);  
}  
int main()  
{  
    while (~scanf("%d%d%lld%lld%lld", &n, &A, &cf, &cm, &m))  
    {  
        //µÚÒ»²½£ºÅÅÐò£¬Ê¹µÃ¼¼ÄÜµÈ¼¶ÑÏ¸ñÉýÐò£¬ÒòÎªÊä³ö¸ñÊ½ÐèÒª£¬ÎÒÃÇ»¹Òª¶ÔÓ¦µ½Ã¿¸ö¼¼ÄÜµÄ±àºÅ  
        for (int i = 1; i <= n; ++i) { scanf("%d", &a[i].v); a[i].o = i; }  
        sort(a + 1, a + n + 1, cmp1); a[n + 1].v = A;  
  
        //µÚ¶þ²¿£ºÎ¬»¤¼¼ÄÜµÈ¼¶Ö®ºÍµÄÇ°×ººÍ£¬ÓÃÓÚºóÀ´¿ìËÙ¼ÆËã¿ÉÌáÉýµÈ¼¶  
        for (int i = 1; i <= n; ++i)sum[i] = sum[i - 1] + a[i].v;  
  
        //µÚÈý²½£¬Ã¶¾ÙÎÒÃÇÊ¹µÃ¶àÉÙÈËµÄ¼¼ÄÜ¼ÓÂú  
        LL ans = -1;  
        LL cost = 0;  
        int v, p;  
        //Ã¶¾Ù[i+1,n]¼¼ÄÜ¶¼±»ÎÒÃÇÉýµ½¶¥¼¶ÁË,[1,i]±»ÎÒÃÇÎ¬»¤Ò»¸ö¾¡¿ÉÄÜ´óµÄ×îµÍ¼¼ÄÜµÈ¼¶  
        for (int i = n; i >= 0; --i)  
        {  
            cost += A - a[i + 1].v;  
            if (cost > m)break;  
            int minv = solve(i, m - cost);  
            LL tmp = minv*cm + (n - i)*cf;  
            if (tmp > ans)  
            {  
                ans = tmp;  
                p = i;  
                v = minv;  
            }  
        }  
  
        printf("%lld\n", ans);  
        for (int i = n; i > p; --i)a[i].v = A;  
        for (int i = 1; i <= p; ++i)gmax(a[i].v, v);  
        sort(a + 1, a + n + 1, cmp2);  
        for (int i = 1; i <= n; ++i)printf("%d ", a[i].v); puts("");  
    }  
    return 0;  
} 
```
*****



