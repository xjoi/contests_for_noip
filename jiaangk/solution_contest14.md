# 比赛记录

[比赛链接](https://www.codeforces.com)
## A
### Problem description
> 给你一串数字，如果a[i]-a[i-1]<=c的话就保留，反之则只保留a[i]-a[i-1]
### Solution
模拟模拟！因为只跟前一个数和现在一个数有关系，所以储存数字用a[2]足矣
```cpp
#include<cstdio>
using namespace std;
int cache[100000],c,n,a[2];
int main()
{
	scanf("%d%d",&n,&c);
	int jis=1;
	scanf("%d",&a[0]);
	cache[jis]=a[0];
	for(int i=1;i<n;i++)
	{
		scanf("%d",&a[i%2]);
		if (a[i%2]-a[(i+1)%2]<=c) cache[++jis]=a[i%2];
		else cache[jis=1]=a[i%2];
	}
	printf("%d",jis);
	return 0;
}
```
## B
### Problem description
> 求是否有正好26个字符出现一次的子串，其中?可以替换为任意字符，输出替换后的字符串（简单模拟即可）
### Solution
```cpp
#include<cstdio>
#include<string.h>
#include<stdlib.h>
using namespace std;
char s[50010];
int longn,cc[27],jis,jis1;
void work(int left)
{
	bool pd[27];
	for(int i=1;i<=26;i++) pd[i]=true;
	char cache[27];
	int biao=0;
	for(int i=left;i<=left+25;i++) if (s[i]!='?') pd[s[i]-64]=false;
	for(int i=1;i<=26;i++) if(pd[i]) cache[++biao]=i+64;
	for(int i=left;i<=left+25;i++) if(s[i]=='?') s[i]=cache[biao--];
	return;
}
void bb()
{
	for(int i=0;i<longn;i++) if(s[i]=='?') s[i]='B';
	return;
}
int main()
{
	scanf("%s",s);
	longn=strlen(s);
	if(longn<26)
	{
		printf("-1");
		return 0;
	}
	for(int iop=0;iop<=longn-26;iop++)
	{
		jis=0; jis1=0;
		for(int i=1;i<=26;i++) cc[i]=0;
		for(int j=iop;j<=iop+25;j++) if(s[j]=='?') jis++;
		else cc[s[j]-64]++;
		for(int i=1;i<=26;i++) if (cc[i]>1) continue; else if(cc[i]==0) jis1++;
		if(jis1!=jis) continue;
		work(iop);
		bb();
		printf("%s",s);
		return 0;
	}
	printf("-1");
	return 0;
}
```
***** 
# 赛后补题

## C
### Problem description
> 初始2，第i次操作时，可以连续加好多次i，当到达某一个完全平方数时，开根，开根后必须满足Mod(i+1)==0，求每次操作需要加多少次i
### Solution
数学问题，使用构造法解决
```cpp
#include<stdio.h>
#include<iostream>
using namespace std;
int main()
{
	long long n;
	cin>>n;
	printf("2\n");
	for(long long i=2;i<=n;i+=1) cout<<i*(1+i)*(1+i)-i+1<<endl;
}
```
## D
### Problem description
> 给你一张图，有些边不知道权值，但是知道某两点的最短路，求每条边的权值
### Solution
先Dijkstra求出不算这些边的最短路，然后给每条边赋值1，然后再来一边Dijkstra直到符合条件，输出。
代码太长了偷懒。。。 注：Dijkstra必须用堆优化，否则TLE
*****
