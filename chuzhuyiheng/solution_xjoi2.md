[比赛链接](http://210.33.19.101/contest/753)

# 比赛中解决的问题
## A
### Problem description
> 在一个平面内，有n条线，m个交点，问此平面被分成了几块
### Data Limit：0<=n,m<=10^10000  Time Limit: 1s

### Solution
> 如果一条直线，与其他直线没有交点，那它就把一个区域分为了两块（多了一块）
如果与其他直线有一个交点，那它就把两个区域分为了四块（多了两块）
.......
又因为原本有一个区域，
所以答案为n+m+1（加上高精度）

### Code
```pas
type gjd=record
     x:array[1..100000] of longint;
     lx:longint;
     end;
var s,t:ansistring;
    i,max,n,j:longint;
    a,b,c:gjd;

operator +(a,b:gjd)cc:gjd;
var max,i:longint;
begin
if a.lx>b.lx then max:=a.lx else max:=b.lx;
fillchar(cc,sizeof(cc),0);
for i:=1 to max do
begin
  cc.x[i]:=cc.x[i]+a.x[i]+b.x[i];
  cc.x[i+1]:=cc.x[i] div 10;
  cc.x[i]:=cc.x[i] mod 10;
end;
if cc.x[max+1]>0 then cc.lx:=max+1 else cc.lx:=max;
end;

begin
  c.lx:=1;
  c.x[1]:=0;
  for j:=1 to 3 do
  if j<>3 then
  begin
    readln(s);
    fillchar(a,sizeof(a),0);
    for i:=1 to length(s) do
    a.x[length(s)+1-i]:=ord(s[i])-48;
    a.lx:=length(s);
    c:=c+a;
  end else
  begin
    s:='1';
    fillchar(a,sizeof(a),0);
    for i:=1 to length(s) do
    a.x[length(s)+1-i]:=ord(s[i])-48;
    a.lx:=length(s);
    c:=c+a;
  end;

    for i:=c.lx downto 1 do
     write(c.x[i]);
end.
```
*****


## B
### Problem description
> 输入n和m，求n^m mod 19941023和n^m mod 19950814

### Data Limit：0<=n,m<=10^9  Time Limit: 1s
### Solution
> 两遍快速幂即可，记得开long long

### Code
```cpp
#include<cstdio>
int main()
{
	long long  n,m,ans1,ans2,nn,mm;
	ans1=1;ans2=1;
	scanf("%lld%lld",&n,&m);
	long long  m1=19941023;
	long long  m2=19950814;
	nn=n;mm=m;
	while (m>1)
	{
		if (m%2==0){
			m=m/2;
			n=((n%m1)*(n%m1))%m1;
		} else
		{
			ans1=(ans1%m1)*(n%m1)%m1;
			m--;
		}
		
	}
	while (mm>1)
	{
		if (mm%2==0){
			mm=mm/2;
			nn=((nn%m2)*(nn%m2))%m2;
		} else
		{
			ans2=(ans2%m2)*(nn%m2)%m2;
			mm--;
		}
		
	}
	ans1=(ans1%m1)*(n%m1)%m1;
	ans2=(ans2%m2)*(nn%m2)%m2;
	printf("%lld %lld",ans1,ans2);
}
```
*****

# 赛后补题

## C
### Problem description
> 输入n，再输入n个数l[i]（表示每个栅栏的长度）
输出由栅栏围成的矩形的最大面积（可以不全部用所以栅栏）
如果无法围成，输出No solution
### Data Limit：1<=n<=16,1<=l[i]<=15.  Time Limit: 1s

### Solution
> 使用dp
f[i][j][k][1,2]分别表示用前i个栅栏，两条长边差为j，两条宽边差为k的较长长边和宽边
转移方式为：考虑f[i][j][k]，如果j>a[i]则说明f[i][j][k]可以从f[i][j-a[i]][k]转移而来
否则说明f[i][j][k]可以从f[i][a[i]-j][k]转移而来
如果(240-j>=a[i])则说明f[i][j][k]可以从f[i][j+a[i]][k]转移而来
对另一维同理
最后输出f[n][0][0]
### Code
```cpp
#include<bits/stdc++.h>
using namespace std;

int  f[20][500][500][3];
int main()
{
	int n,i,j,k,a[100];
	scanf("%d",&n);
	for (i=1;i<=n;i++)scanf("%d",&a[i]);
	for (i=0;i<=19;i++)
	  for (j=0;j<=499;j++)
	  for (k=0;k<=499;k++)
	  {
	  	f[i][j][k][1]=-10000;
	  	f[i][j][k][2]=10000;
	  }
	f[0][0][0][1]=0;
	f[0][0][0][2]=0;
	for (i=1;i<=n;i++)
	  for (j=0;j<=120;j++)
	    for (k=0;k<=120;k++)
	    {
	    	f[i][j][k][1]=f[i-1][j][k][1];f[i][j][k][2]=f[i-1][j][k][2];
	    	if (j>=a[i])
	    	{
	    		if (f[i][j][k][1]*f[i][j][k][2]<(f[i-1][j-a[i]][k][1]+a[i])*(f[i-1][j-a[i]][k][2]))
	    		{
	    			f[i][j][k][1]=f[i-1][j-a[i]][k][1]+a[i];
	    			f[i][j][k][2]=f[i-1][j-a[i]][k][2];
				}
				
			} else
			{
				if (f[i][j][k][1]*f[i][j][k][2]<(f[i-1][a[i]-j][k][1]+j)*f[i-1][a[i]-j][k][2])
				{
					f[i][j][k][1]=f[i-1][a[i]-j][k][1]+j;
					f[i][j][k][2]=f[i-1][a[i]-j][k][2];
				}
				
			}
			if (240-j>=a[i])
			{
				if (f[i][j][k][1]*f[i][j][k][2]<(f[i-1][j+a[i]][k][1])*f[i-1][j+a[i]][k][2])
				{
					f[i][j][k][1]=f[i-1][j+a[i]][k][1];
					f[i][j][k][2]=f[i-1][j+a[i]][k][2];
				}
			}
			
			
			if (k>=a[i])
	    	{
	    		if (f[i][j][k][1]*f[i][j][k][2]<(f[i-1][j][k-a[i]][1])*(f[i-1][j][k-a[i]][2]+a[i]))
	    		{
	    			f[i][j][k][1]=f[i-1][j][k-a[i]][1];
	    			f[i][j][k][2]=f[i-1][j][k-a[i]][2]+a[i];
				}
				
			} else
			{
				if (f[i][j][k][1]*f[i][j][k][2]<(f[i-1][j][a[i]-k][1])*f[i-1][j][a[i]-k][2]+k)
				{
					f[i][j][k][1]=f[i-1][j][a[i]-k][1];
					f[i][j][k][2]=f[i-1][j][a[i]-k][2]+k;
				}
				
			}
			if (240-k>=a[i])
			{
				if (f[i][j][k][1]*f[i][j][k][2]<(f[i-1][j][k+a[i]][1])*f[i-1][j][k+a[i]][2])
				{
					f[i][j][k][1]=f[i-1][j][k+a[i]][1];
					f[i][j][k][2]=f[i-1][j][k+a[i]][2];
				}
			}
		}
	if (f[n][0][0][1]*f[n][0][0][2]<=0) printf("No Solution");else printf("%d",f[n][0][0][1]*f[n][0][0][2]);
	return 0;
}
```
*****


