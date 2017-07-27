[比赛链接](https://cn.vjudge.net/contest/172463#overview)

# 比赛中解决的问题
## A
### Problem description
>有k个物品和v个隔板,每个箱子最多分成b个空格,每个空格里最多放a个物品,求放下所有物品最少要多少箱子.

### Data Limit2 ≤ k ≤ 1000; 1 ≤ a, b, v ≤ 1000 Time Limit: 1s

### Solution
>虽说可以O(1)出解,但比较麻烦容易错,反正数据小,为了正确性就模拟一下,考虑每个箱子,隔成最多的空格然后放最多的物品.

### Code
```cpp
#include<cstdio>
int n,k,t,a,b,v,ans=0;
int min(int x,int y)
{
	if (x>y)return y;else return x;
}
int main()
{
	scanf("%d%d%d%d",&k,&a,&b,&v);
	while (a>0)
	{
		ans++;
		t=min(b,k-1);b-=t;
		if(a<=(t+1)*v)
		{
			printf("%d",ans);
			return 0;
		}
		a-=(t+1)*v;
	}
	return 0;
}
```
*****


## B
### Problem description
>给出n和n棵树的高度a以及等差k,修建最少的树使n棵树的高度为等差为k的等差数列(修建可以使树增高,但不能修成负数)

### Data Limit：1 ≤ n, k ≤ 1000 1 ≤ ai ≤ 1000 Time Limit: 1s
### Solution
>由于是等差数列,所以枚举第一棵树的高度就可以啦,还可以避免出现负数.

### Code
```cpp
#include<cstdio>
int n,i,j,a[10000],k,t=0,min=1e8,mini;
int main()
{
	scanf("%d%d",&n,&k);
	for (i=1;i<=n;i++)scanf("%d",&a[i]);
	for (i=1;i<=10000;i++)
	{
		t=0;
		for (j=1;j<=n;j++)
		if (i+(j-1)*k!=a[j])t++;
		if (t<min)
		{
			min=t;mini=i;
		}
		
	}
	printf("%d\n",min);
	for (i=1;i<=n;i++)
	if (a[i]!=mini+(i-1)*k)
	{
		if (a[i]>mini+(i-1)*k)printf("- %d %d\n",i,a[i]-mini-(i-1)*k);
		if (a[i]<mini+(i-1)*k)printf("+ %d %d\n",i,-a[i]+mini+(i-1)*k);
	}
	return 0;
}
```
*****
## F
### Problem description
>给出n和p,构造一个无向图,它有2n+p条边,n个点,无重边自环,且每个有k个点的字图中最多有2k+p个点.

### Data Limit：5 ≤ n ≤ 24; p ≥ 0 Time Limit: 1s

### Solution
>比赛时面向样例编程,然后过了......
那怎么证明这是对的呢?
暂时不知道...

### Code
```cpp
#include<cstdio>
int n,i,j,p,a,b,T;
int main()
{
	scanf("%d",&T);
	while (T--)
	{
	scanf("%d%d",&n,&p);a=1;b=2;
	for (i=1;i<=2*n+p;i++)
	{
		printf("%d %d\n",a,b);
		if (b<n)b++;else 
		{
			a++;b=a+1;
		}
	}
}
	return 0;
}
```
# 赛后补题

## C
### Problem description
>给出一个只有正数和0的边长为n的方形矩阵a,若有a^k全是正数,则打yes,否则打出no(k为任意自然数)

### Data Limit：n <=2000  Time Limit: 1s

### Solution
>由题意,可以把原矩阵看做邻接矩阵,然后只要判断原图是否联通就好了.

### Code
```cpp
```
*****


## D
### Problem description
> 

### Data Limit：n <= 1e5  Time Limit: 1s
### Solution
> 

### Code
```cpp
```
*****

## E
### Problem description
> 

### Data Limit：n <= 1e5  Time Limit: 1s

### Solution
> 

### Code
```cpp
```
