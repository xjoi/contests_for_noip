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

### Data Limit：1 ≤ n, m ≤ 10^3; 1 ≤ k ≤ 10^6; 1 ≤ p ≤ 100  1 ≤ aij ≤ 10^3 Time Limit: 1s
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

