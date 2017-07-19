[比赛链接](https://vjudge.net/contest/171671#problem)

# 比赛中解决的问题
## A
### Problem description
>模拟一个哈希表,打出第一个冲突的位置
若不冲突,打出-1
### Data Limit：2 ≤ p, n ≤ 300  Time Limit: 1s

### Solution
> 纯模拟,还有不要忘了打-1,没了.

### Code
```cpp
#include<cstdio>
int n,i,j,p,x;
bool h[10001];
int main()
{
	scanf("%d%d",&p,&n);
	for (i=0;i<=10000;i++)h[i]=false;
	for (i=1;i<=n;i++)
	{
		scanf("%d",&x);
		if (h[x%p])
		{
			printf("%d",i);
			return 0;
		}else h[x%p]=true;
	}
		printf("%d",-1);
		return 0;
}
```
*****


## B
### Problem description
> 给出一个字符串(只有小写字母),在其中插入k个小写字母使字符串的价值最大
价值:每个字母有自己的价值,所有字母的价值与其位置乘积的总和为字符串的价值

### Data Limit：s (1 ≤ |s| ≤ 10^3)k (0 ≤ k ≤ 10^3)..  Time Limit: 1s
### Solution
> 很容易发现只要把价值最大的字符放k个在末尾即可,没有坑.

### Code
```pas
var
  n,i,j,max,ans:longint;
  s:ansistring;
  ch:char;
  m:array['a'..'z']of longint;
begin
  readln(s);
  readln(n);max:=-100000;
  for ch:='a' to 'z' do
  begin
    read(m[ch]);
    if max<m[ch] then max:=m[ch];
  end;
  for i:=1 to length(s) do
  ans:=ans+m[s[i]]*i;
  for i:=length(s)+1 to length(s)+n do
  ans:=ans+i*max;
  writeln(ans);
end.

```
*****



## C
### Problem description
> 给出n个数,求最长连续上升字段长,可以有一次修改一个数的机会

### Data Limit：1 ≤ n ≤ 10^5  Time Limit: 1s

### Solution
> 贪心一下,有许多情况比较麻烦,详见代码

### Code
```cpp
#include<cstdio>
int n,i,j,used,ans=1,t,l,last;
int a[1000000];
bool bo,b[1000000];
int main()
{
	scanf("%d",&n);
	for (i=1;i<=n;i++)scanf("%d",&a[i]);a[n+1]=-10000000;
	t=1;l=1;last=a[1];bo=false;
	while (t<n)
	if (!bo)
	{
		if (a[t+1]>last)
		{
			t++;l++;last=a[t];
		}else
		{
			t++;l++;last+=1;bo=true;
			used=t;
		}
	}else
	{
		if (a[t+1]>last)
		{
			t++;l++;last=a[t];
		}else
		{
			t=used;
			if (ans<l)ans=l;l=1;last=a[t];bo=false;
			used=0;
		}
	}
    if (ans<=l){
		ans=l;if (!bo&&l<n)ans++;
	}
	t=1;l=1;last=-10000;bo=true;used=1;
	while (t<n)
	if (!bo)
	{
		if (a[t+1]>last)
		{
			t++;l++;last=a[t];
		}else
		{
			t++;l++;last+=1;bo=true;
			used=t;
		}
	}else
	{
		if (a[t+1]>last)
		{
			t++;l++;last=a[t];
		}else
		{
			t=used;
			if (ans<l)ans=l;l=1;last=a[t];bo=false;
			used=0;
		}
	}
	if (ans<=l){
		ans=l;if (!bo&&l<n)ans++;
	}
	t=1;l=1;last=a[1];bo=false;
	while (t<n)
	if (!bo)
	{
		if (a[t+1]>last)
		{
			t++;l++;last=a[t];
		}else
		{
		
		if (a[t+1]-a[t-1]>=2&&!b[t])
		{
			b[t]=true;t++;l++;last=a[t];bo=true;
			used=t-1;
		}
		else
		{
			t++;l++;last+=1;bo=true;
			used=t;
		}
	    }
	}else
	{
		if (a[t+1]>last)
		{
			t++;l++;last=a[t];
		}else
		{
			t=used;
			if (ans<l)ans=l;l=1;last=a[t];bo=false;
			used=0;
		}
	}
	if (ans<=l)
	{
		ans=l;if (!bo&&l<n)ans++;
	}
	printf("%d",ans);
}
```
*****
# 赛后补题

## D
### Problem description
> n*m的数字矩阵，要刚好操作k次，以及系数p。每次操作可以获得一行或一列的数的和的价值，然后把该行或该列的每个数减p
求获得的价值最大为多少？

### Data Limit：1 ≤ n, m ≤ 10^3; 1 ≤ k ≤ 10^6; 1 ≤ p ≤ 100  1 ≤ aij ≤ 10^3 Time Limit: 2s
### Solution
> 枚举0到k,求出在列和行上分别操作i次的最大价值
可以用优先队列优化(刚刚才知到)
然后枚举i表示在行上操作i次,此时在列上操作k-i次
此时答案为r[i]*c[k-i]-q*i*(k-i)
求最大值即可

### Code
```cpp
#include<cstdio>
#include<algorithm>
#include<queue>

using namespace std;
priority_queue<long long>sr,sc;
long long n,i,j,m,p,jianr,jianc,k,kk;
long long  a[2000][2000],row[2000],column[2000],r[2000000],c[2000000];
long long ans=0;
int main()
{
	scanf("%lld%lld%lld%lld",&n,&m,&k,&p);
	ans=-1e18;
	for (i=1;i<=n;i++)
	  for (j=1;j<=m;j++)
	  {
	  	scanf("%lld",&a[i][j]);
	  	row[i]=row[i]+a[i][j];
	  	column[j]=column[j]+a[i][j];
	  }
	sort(row,row+n+1);
	sort(column,column+m+1);
	for (i=1;i<=n;i++)
	sr.push(row[i]);
	for (i=1;i<=m;i++)
	sc.push(column[i]);
	int topc=m,topr=n;kk=k;
	for (i=1;i<=k;i++)
	{
		long long  mx=sr.top();sr.pop();
		r[i]=r[i-1]+mx;
        sr.push(mx-p*m);  
        
        
	    mx=sc.top();sc.pop();
		c[i]=c[i-1]+mx;
        sc.push(mx-p*n); 
	}
	
	for (i=0;i<=k;i++)
	if (r[i]+c[k-i]-i*(k-i)*p>ans)ans=r[i]+c[k-i]-i*(k-i)*p;
	printf("%lld",ans);
}
```
*****
## E
### Problem description
> 维护一个数组,支持两种操作
1,区间加斐波那契数列
2,区间求和
### Data Limit：1 ≤ n, m ≤ 300000 Time Limit: 4s
### Solution
> 用线段数做可以用前两个数标记加的斐波那契数列
可以预处理出每个数由几个第一个数+几个第二个数组成
再前缀和,就能O(1)求出一段斐波那契数列和了

### Code
```cpp
#include <iostream>
#include <cstring>
#include <algorithm>
#include <cstdio>
#define MAX 300007

using namespace std;

typedef long long LL;

int n,m,a[MAX];
const LL mod = 1e9+9;
LL fib[MAX];

struct Tree
{
    int l,r;
    LL sum,f1,f2; 
}tree[MAX<<2];

void push_up ( int u )
{
    tree[u].sum = tree[u<<1].sum + tree[u<<1|1].sum;
    tree[u].sum %= mod;
}

void build ( int u , int l , int r )
{
    tree[u].l = l;
    tree[u].r = r;
    tree[u].f1 = tree[u].f2 = 0;
    if ( l == r )
    {
        tree[u].sum = a[l];
        return;
    }
    int mid = l+r>>1;
    build ( u<<1 , l , mid );
    build ( u<<1|1 , mid+1 , r );
    push_up ( u );
}

void init ( )
{
    fib[1] = fib[2] = 1;
    for ( int i = 3 ; i < MAX ; i++ )
    {
        fib[i] = fib[i-1] + fib[i-2];
        fib[i] %= mod;
    }
}

LL get ( LL a , LL b , int n )
{
    if ( n == 1 ) return a%mod;
    if ( n == 2 ) return b%mod;
    return (a*fib[n-2]%mod+b*fib[n-1]%mod)%mod;
}

LL sum ( LL a , LL b , int n )
{
    if ( n == 1 ) return a;
    if ( n == 2 ) return (a+b)%mod;
    return ((get ( a , b , n+2 )-b)%mod+mod)%mod;
}

void push_down ( int u )
{
    int f1 = tree[u].f1;
    int f2 = tree[u].f2;
    int l = tree[u].l;
    int r = tree[u].r;
    int ll = (l+r)/2-l+1;
    int rr = r-(l+r)/2;
    if ( f1 )
    {
        if ( l != r )
        {
            tree[u<<1].f1 += f1;
            tree[u<<1].f1 %= mod;
            tree[u<<1].f2 += f2;
            tree[u<<1].f2 %= mod;
            tree[u<<1].sum += sum ( f1 , f2 , ll );
            tree[u<<1].sum %= mod;
            int x = f1 , y = f2;
            f2 = get ( x , y , ll+2 );
            f1 = get ( x , y , ll+1 );
            tree[u<<1|1].f2 += f2;
            tree[u<<1|1].f2 %= mod;
            tree[u<<1|1].f1 += f1;
            tree[u<<1|1].f1 %= mod;
            tree[u<<1|1].sum += sum ( f1 , f2 , rr );
            tree[u<<1|1].sum %= mod;
        }
        tree[u].f1 = tree[u].f2 = 0;
    }
}

void update ( int u , int left , int right )
{
    int l = tree[u].l;
    int r = tree[u].r;
    int mid = l+r>>1;
    if ( left <= l && r <= right )
    {
        tree[u].f1 += fib[l-left+1];
        tree[u].f1 %= mod;
        tree[u].f2 += fib[l-left+2];
        tree[u].f2 %= mod;
        int f1 = fib[l-left+1], f2 = fib[l-left+2];
        tree[u].sum += sum ( f1 , f2 , r-l+1 );
        tree[u].sum %= mod;
        return;
    }
    push_down ( u);
    if ( left <= mid && right >= l )
        update ( u<<1 , left , right );
    if ( left <= r && right > mid )
        update ( u<<1|1 , left , right );
    push_up ( u );
}

LL query ( int u , int left , int right )
{
    int l = tree[u].l;
    int r = tree[u].r;
    int mid = l+r>>1;
    if ( left <= l && r <= right )
        return tree[u].sum;
    push_down ( u );
    LL ret = 0;
    if ( left <= mid && right >= l ) 
    {
        ret += query ( u<<1 , left , right );
        ret %= mod;
    }
    if ( left <= r && right > mid )
    {
        ret += query ( u<<1|1 , left , right );
        ret %= mod;
    }
    return ret;
}

int main ( )
{
    init ( );
    scanf ( "%d%d" , &n , &m ) ;
        for ( int i = 1; i <= n ; i++ )
            scanf ( "%d" , &a[i] );
        build ( 1 , 1 , n );
        while ( m-- )
        {
            int x,l,r;
            scanf ( "%d%d%d" , &x , &l , &r );
            if ( x == 1 )
                update ( 1 , l , r );
            else
                printf ( "%lld\n" , query ( 1 , l , r ) );
        }
    return 0;
}
```
*****
