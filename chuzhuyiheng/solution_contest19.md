[比赛链接](https://vjudge.net/contest/172423#overview)

# 比赛中解决的问题
## A
### Problem description
>给出数a,b,n,在a后加上1个数,并使加后的数是b的倍数.输出操作n次后的数.

### Data Limit：1 ≤ a, b, n ≤ 105  Time Limit: 1s

### Solution
>易得只要第一次成功,剩下加0,就可以了

### Code
```cpp
#include<cstdio>
long long a,b,n,i,j;
long long ans[500000];bool bo=false;
int main()
{
	scanf("%lld%lld%lld",&a,&b,&n);//a=a%b;
	for (i=0;i<=9;i++)
	{
		if ((a*10+i)%b==0)
		{
			a=a*10+i;bo=true;
			break;
		}
	}
	if (bo)
	{
		printf("%lld",a);
	for (i=1;i<=n-1;i++)printf("%d",0);
	}else printf("%d",-1);
	return 0;
}
```
*****


## B
### Problem description
> 输入=一个字符串,输出出现最多的合法日期.

### Data Limit：|s|<=10e5  Time Limit: 1s
### Solution
>暴力枚举每10个连续字符,判断是否是合法日期并计数即可.

### Code
```pas
var
  s,t:ansistring;
  n,i,j,d,m,y,k,max:longint;
  a:array[1..31,1..12,2013..2015]of longint;
  day:array[1..12] of longint;
begin
  readln(s);
  day[1]:=31;
  day[2]:=28;
  day[3]:=31;
  day[4]:=30;
  day[5]:=31;
  day[6]:=30;
  day[7]:=31;
  day[8]:=31;
  day[9]:=30;
  day[10]:=31;
  day[11]:=30;
  day[12]:=31;
  max:=-10;
  for i:=1 to length(s) do
  if (s[i]='-')and(s[i+3]='-')and((s[i-2]<='9')and(s[i-2]>='0'))
  and((s[i-1]<='9')and(s[i-1]>='0'))and((s[i+1]<='9')and(s[i+1]>='0'))
  and((s[i+2]<='9')and(s[i+2]>='0'))and((s[i+4]<='9')and(s[i+4]>='0'))
  and((s[i+5]<='9')and(s[i+5]>='0'))and((s[i+6]<='9')and(s[i+6]>='0'))
  and((s[i+7]<='9')and(s[i+7]>='0'))then
  begin
    d:=(ord(s[i-2])-48)*10+ord(s[i-1])-48;
    m:=(ord(s[i+1])-48)*10+ord(s[i+2])-48;
    y:=(ord(s[i+4])-48)*1000+(ord(s[i+5])-48)*100+(ord(s[i+6])-48)*10+ord(s[i+7])-48;
    if (y<=2015)and(y>=2013)and(m<=12)and(m>=1) then
    if (d>=1)and(d<=day[m]) then
    begin
      inc(a[d,m,y]);
    end;
  end;
  for i:=1 to 31 do
    for j:=1 to 12 do
      for k:=2013 to 2015 do
      if a[i,j,k]>max then
      begin
        max:=a[i,j,k];
        d:=i;m:=j;y:=k;
      end;
  if d<10 then write('0',d) else write(d);
   write('-');
  if m<10 then write('0',m) else write(m);
  write('-');
  writeln(y);
end.
```
*****
## C
### Problem description
>有n个箱子,进行一次操作,把一个箱子的球拿出来,然后放到后面的箱子里,每个箱子放一个,直到取的球放完.
若放到了第n个箱子,下一个放第1个箱子.给出操作后的情况和最后放球的箱子,求出原来的情况.

### Data Limit：2 ≤ n ≤ 105  Time Limit: 1s

### Solution
>现在球数最少的的箱子,这就是原来选的箱子,然后就可以求出原来的样子啦.

### Code
```cpp
#include<cstdio>
long long n,i,j,x,min=1e18,ans=0;
long long a[500000];
int main()
{
	scanf("%lld%lld",&n,&x);
	for (i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]);
		if (a[i]<min)min=a[i];
	}
	if (min>0)min--;
	for (i=1;i<=n;i++)a[i]=a[i]-min;
	while (a[x]>0)
	{
		ans++;a[x]--;x--;
		if (x==0)x=n;
	}
	a[x]=min*n+ans;
	for (i=1;i<=n;i++)printf("%lld ",a[i]);
	return 0;
}
```
*****


## D
### Problem description
>给出n个点的颜色(黑或白)和权值(所有与其相连的边的权值和)求出原来的树.

### Data Limit：n <= 1e5  Time Limit: 1s
### Solution
>贪心,每次枚举两个点,连权值最大的边即可.

### Code
```cpp
#include<cstdio>
#include<algorithm>
using namespace std;
long long  n,i,j,t,topb,topw,ans[2000000][4],topa;
bool bo=false;
struct point
{
	long long a,sum;
};
bool bbb(point x,point y)
{
	return x.sum>y.sum;
}
point black[2000000],white[2000000];
int main()
{
	scanf("%lld",&n);
	for (i=1;i<=n;i++)
	{
		scanf("%lld",&t);
		if (t==0)
		{
			topw++;
			scanf("%lld",&white[topw].sum);
			white[topw].a=i;
		}else
		{
			topb++;
			scanf("%lld",&black[topb].sum);
			black[topb].a=i;
		}
	}
	i=1;j=1;topa=0;
	while ((i<=topb)&&(j<=topw))
	{
		topa++;
		ans[topa][1]=black[i].a;
		ans[topa][2]=white[j].a;
		
		t=min(white[j].sum,black[i].sum);
		ans[topa][3]=t;
		white[j].sum-=t;black[i].sum-=t;
		if (black[i].sum) j++;  
        else if(white[j].sum) i++;  
        else if(i<topb) i++;  
        else j++;  
	}
	for (i=1;i<=n-1;i++)
	printf("%lld %lld %lld\n",ans[i][1],ans[i][2],ans[i][3]);
	return 0;
}
```
*****

# 赛后补题

## E
### Problem description
>给出一个平面上的n个点,用两条平行于x轴的直线和两条平行于y轴的直线把平面分成9块
使每个块中的点符合给出的要求.

### Data Limit：9 ≤ n ≤ 10^5 Time Limit:2s

### Solution
>先全排列出每个块的点数然后用线段树求出能否满足题意

### Code
```cpp
#include<iostream>    
#include<cstdio>    
#include<map>    
#include<cstring>    
#include<cmath>    
#include<vector>    
#include<algorithm>    
#include<set>    
#include<string>    
#include<queue>    
#define inf 1000000005    
#define M 40    
#define N 100005  
#define maxn 300005    
#define eps 1e-12  
#define zero(a) fabs(a)<eps    
#define Min(a,b) ((a)<(b)?(a):(b))    
#define Max(a,b) ((a)>(b)?(a):(b))    
#define pb(a) push_back(a)    
#define mp(a,b) make_pair(a,b)    
#define mem(a,b) memset(a,b,sizeof(a))    
#define LL long long    
#define MOD 1000000007  
#define lson step<<1  
#define rson step<<1|1  
#define sqr(a) ((a)*(a))    
#define Key_value ch[ch[root][1]][0]    
#define test puts("OK");    
#define pi acos(-1.0)  
#define lowbit(x) ((-(x))&(x))  
#define HASH1 1331  
#define HASH2 10001  
#pragma comment(linker, "/STACK:1024000000,1024000000")    
using namespace std;  
struct Set_tree{  
    int left,right;  
    vector<int>v;  
}L[N*4];  
struct Point{  
    int x,y;  
    bool operator<(const Point n)const{  
        return x!=n.x?x<n.x:y<n.y;  
    }  
}p[N];  
int n,x[N],y[N];  
int a[9],b[9];  
double ret_x1,ret_x2,ret_y1,ret_y2;  
void Bulid(int step,int l,int r){  
    L[step].left=l;  
    L[step].right=r;  
    L[step].v.clear();  
    for(int i=l;i<=r;i++)  
        L[step].v.pb(p[i].y);  
    sort(L[step].v.begin(),L[step].v.end());  
    if(l==r)  
        return;  
    int m=(l+r)>>1;  
    Bulid(lson,l,m);  
    Bulid(rson,m+1,r);  
}  
int Query(int step,int l,int r,int val){  
    if(L[step].left==l&&r==L[step].right){  
        if(L[step].v.size()==0) return 0;  
        if(L[step].v[0]>val) return 0;  
        if(L[step].v.back()<=val) return L[step].v.size();  
        return (upper_bound(L[step].v.begin(),L[step].v.end(),val)-L[step].v.begin());  
    }  
    int m=(L[step].left+L[step].right)>>1;  
    if(r<=m) return Query(lson,l,r,val);  
    else if(l>m) return Query(rson,l,r,val);  
    else return Query(lson,l,m,val)+Query(rson,m+1,r,val);  
}  
bool ok(){  
    int x1=b[a[0]]+b[a[1]]+b[a[2]]-1;  
    int x2=x1+b[a[3]]+b[a[4]]+b[a[5]];  
    int y1=b[a[0]]+b[a[3]]+b[a[6]]-1;  
    int y2=y1+b[a[1]]+b[a[4]]+b[a[7]];  
    if(x1+1>=n||x[x1]==x[x1+1]) return false;  
    if(x2+1>=n||x[x2]==x[x2+1]) return false;  
    if(y1+1>=n||y[y1]==y[y1+1]) return false;  
    if(y2+1>=n||y[y2]==y[y2+1]) return false;  
    if(Query(1,0,x1,y[y1])!=b[a[0]]) return false;  
    if(Query(1,0,x1,y[y2])!=b[a[0]]+b[a[1]]) return false;  
    if(Query(1,x1+1,x2,y[y1])!=b[a[3]]) return false;  
    if(Query(1,x1+1,x2,y[y2])!=b[a[3]]+b[a[4]]) return false;  
    ret_x1=(x[x1]+x[x1+1])/2.0;  
    ret_x2=(x[x2]+x[x2+1])/2.0;  
    ret_y1=(y[y1]+y[y1+1])/2.0;  
    ret_y2=(y[y2]+y[y2+1])/2.0;  
    return true;   
}  
int main(){  
    //freopen("input.txt","r",stdin);  
    while(scanf("%d",&n)!=EOF){  
        for(int i=0;i<n;i++){  
            scanf("%d%d",&p[i].x,&p[i].y);  
            x[i]=p[i].x;y[i]=p[i].y;  
        }  
        sort(p,p+n);  
        sort(x,x+n);  
        sort(y,y+n);  
        Bulid(1,0,n-1);  
        for(int i=0;i<9;i++) scanf("%d",&b[i]);  
        for(int i=0;i<9;i++) a[i]=i;  
        int t=362880;  
        while(t--){  
            if(ok()){  
                printf("%.1f %.1f\n%.1f %.1f\n",ret_x1,ret_x2,ret_y1,ret_y2);  
                break;  
            }  
            next_permutation(a,a+9);  
        }  
        if(t<=0) puts("-1");  
    }  
    return 0;  
}  
```
