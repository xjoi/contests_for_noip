# 比赛记录

## A
### Problem description
> 给一个杠杆 如 8==^==2，求会向哪边倾斜或者平衡
### Solution
暴力暴力
```cpp
#include<cstdio>
#include<string.h>
using namespace std;
long long cache,longn,left,right;
char s[1005000];
int main()
{
	scanf("%s",s);
	longn=strlen(s);
	for(int i=0;i<=longn-1;i++) if (s[i]=='^')
	{
		cache=i;
		break;
	}
	left=0;
	right=0;
	for(int i=0;i<cache;i++) if(s[i]-48<10) left+=(s[i]-48)*(cache-i);
	for(int i=cache+1;i<=longn-1;i++) if(s[i]-48<10) right+=(s[i]-48)*(i-cache);
	if(left==right)
	{
		printf("balance");
	}
	if(left>right)
	{
		printf("left");
	}
	if(right>left)
	{
		printf("right");
	}
	return 0;
}
```
## B
### Problem description
> 几个人互相借钱，求最简化（5 3    1 2 10     2 3 1      2 4 1）
### Solution
暴力暴力
```cpp
#include<cstdio>
#include<iostream>
using namespace std;
int ans,cache[120],a,n,s1,s2,s3;
int main()
{
	for(int i=0;i<=119;i++) cache[i]=0;
	scanf("%d%d",&a,&n);
	for(int i=1;i<=n;i++) 
	{
	scanf("%d%d%d",&s1,&s2,&s3);
	cache[s1]=cache[s1]-s3;
	cache[s2]=cache[s2]+s3;
    }
    ans=0;
    for(int i=1;i<=a;i++)
    if(cache[i]>0) ans=ans+cache[i];
    cout<<ans;
	return 0;
}
```
***** 
# 赛后补题

## D
### Problem description
> 给一个01矩阵，可以自由调换每行，求最大子矩阵（1）
### Solution
首先进行排序，然后用最大01矩阵的算法即可求解
```cpp
#include<stdio.h>
#include<iostream>
#include<algorithm>
#define maxn 5010
int cache[maxn][maxn]={0},n,m;
char data[maxn][maxn];
using namespace std;
int main()
{
	int ans=0;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++) scanf("%s",data[i]+1);
	for(int i=1;i<=n;i++)
	for(int j=1;j<=m;j++) {if(data[i][j]=='1') cache[j][i]=cache[j-1][i]+1; else cache[j][i]=0;}
	for(int i=1;i<=m;i++)
	{
		sort(cache[i]+1,cache[i]+n+1);
		for(int j=1;j<=n;j++) ans=max(ans,cache[i][j]*(n-j+1));
	}
	printf("%d",ans);
	return 0;
}
```
