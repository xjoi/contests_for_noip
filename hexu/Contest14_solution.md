[比赛链接](https://cn.vjudge.net/contest/168561#overview)

# 比赛中解决的问题
## A
### Problem description
>给你一个N和一个C（1<=N<=100000,1<=K<=10^9），接下来再给你N个数字t1,t2,t3...tn(1<=T1<t2<t3<...<tn<=10^9)。</P>
找到一个序列L,R，使得tl到tR这R-L+1的数字都满足本数字减去前一个数字的差都小于等于K。输出R-L+1的值。

### Solution
> 我们从头到尾扫一遍，如果当前数t(i)-t(i-1)的差大于K，那么就把L指针移至i这个位置。最后输出R-L+1；

### Code
```cpp
#include<iostream>
#include<cstdio>
#define MAXN 100005
using namespace std;
int a[MAXN],k,n;
int main()
{
	scanf("%d%d",&n,&k);
	for (int i=0; i<n; i++) scanf("%d",&a[i]) ;
	int p=1;
	for (int i=1; i<n; i++) 
	if ((a[i]-a[i-1])<=k) p++;
	else p=1;
	printf("%d",p);
	return 0;	
}
```
*****


## B
### Problem description
> 给出字符串，如果字符串中有长度为26的子串，且子串中的‘？’经过替换可以刚刚好包含26个字母，就输出整个替换后的字符串
### Solutio
> 首先如果字符串的长度小于26的直接输出-1，然后我们依次截取26长度的字符串进行测试。</P>
  如果这26个字符中的？可以替换成功，则说明我们已经成功地找到了解。</P>
  输出时将另外的‘？’一并改成A（反正有一个子串已经满足要求了），然后输出整个字符串。

### Code
```cpp
#include <cstdio>  
#include <stack>  
#include <queue>  
#include <cmath>  
#include <vector>  
#include <cstring>  
#include <algorithm>  
using namespace std;  
#define INF 0x3f3f3f3f  
char str[100011];  
int l;  
int ant[30];  
bool flag;  
int main()  
{  
    scanf ("%s",str);  
    l = strlen(str);  
    if (l < 26)  
    {  
        printf ("-1\n");  
        return 0;  
    }  
    bool ans = false;  
    for (int i = 0 ; i < l-25 ; i++)  
    {  
        memset(ant,0,sizeof(ant)) ;
        flag = true;  
        for (int j = i ; j < i + 26 ; j++)  
        {  
            if (str[j] == '?')    continue;  
            ant[str[j]-'A']++;  
            if (ant[str[j]-'A'] >= 2)  
            {  
                flag = false;  
                break;  
            }  
        }  
        if (flag)  
        {  
            ans = true;  
            for (int j = i ; j < i + 26 ; j++)  
            {  
                if (str[j] == '?')  
                {  
                    for (int k = 0 ; k < 26 ; k++)  
                    {  
                        if (ant[k] == 0)  
                        {  
                            ant[k] = 1;  
                            str[j] = 'A' + k;  
                            break;  
                        }  
                    }  
                }  
            }  
            if (ans)   break;  
        }  
    }  
    if (ans)  
    {  
        for (int i = 0 ; i < l ; i++)  
            if (str[i] == '?')     str[i] = 'A';  
        printf ("%s\n",str);  
    }  
    else  
        puts("-1");  
    return 0;  
}  

```
*****

## C
### Problem description
>：最开始给你一个数字x = 2，有两种操作：</P>
    1. 第一种是 + 操作， 每操作一次可以让x + k，可以操作无数次，k为当前等级，k的等级最开始为1。</p>
    2. 第二种操作是开方，即把x开方，开方成功之后，你的等级k就会上升一个等级，即k++；想要成功开方你开方后得到的数字必须是k+1的倍数。</P>
    问要让自己的等级k成为 n + 1，问你每上升一级，要按多少次 +；

### Solution
> 仔细分析一下，我们可以整理得下列式子：</P>
  1. a(i)+ans(i)xi = a(i+1)^2;</P>
  2. a(i) mod i = 0;</P>
  因为第i个答案为ans(i), 因此把第一个式子变形得：</P>
  3. ans(i) = (a(i+1)^2 - a(i) )/i;</P>
  这个式子说明只要满足a(i) mod i=0和a(i+1)^2 mod i=0的都可以拿来构造答案序列，我们让a(i)=ix(i-1),就得到ans(i)=ix(i+1)^2-i+1。</P>

### Code
```cpp
#include<iostream>
#include<cstring>
#include<cmath>
#include<cstdio>
#define ll long long
using namespace std;
int main()
{
     int n;
     scanf("%d",&n);
     cout<<"2"<<endl;
    for(ll i=2; i<=n; i++)
     {
         printf("%I64d\n",(i+1)*(i+1)*i-i+1);
     }
    return 0;
 }
```
*****


# 赛后补题

## D
### Problem description
> 有N个点m条边组成了一张图（1<=N<=1000，1<=M<=10000），有些相连的边的权值未知（输入时权值是0就代表这条边是未知的）。</p>
  给你起点s、终点t以及起点和终点之间的期望最短路的长度L，问给这些权值未知的点赋值之后st之间的最短路能否等于L。</P>
  如果等于就输出赋值方案，否则就输出NO

### Solution
> 把权值为0的边全赋值为1后，我们先以T为起点大力SPFA一波，求出每个点到终点T的最短路的长度dis1[i],然后再以S为起点SPFA一次，与第一次不同，这次SPFA会带着更改边的长度的操作。</P>
   刚开始时一切都会与第一次SPFA差不多，但是当我们的SPFA经过一条原本权值为0的边时，我们就可以发现一个奇妙的东西：</P>
     1.我们假设这条边是从U到V的,dis2[u]表示U这个点到S的距离（这个值已经在第二次SPFA中得到了），dis1[v]表示v这个点到T的距离。</P>
     2.那么我们就可以更改这边值为0的边，使得：dis1[v]+dis2[u]+这条边的值=L。 </P>
     3.因为边不可为负数，所以很显然：这条边的值为max(L-dis1[v]-dis2[u],0)。</P>
   好了，这样我们就在2次SPFA中得到了我们想要的dis2[t](表示经过对边赋值后，T到S的最短距离）。</P>
    如果dis2[t]<>L，就说明这是无解的数据，输出NO即可。</p>
    如果dis2[t]=L，那么就输出所有边的答案。
### Code
```cpp
#include<bits/stdc++.h>
using namespace std;
struct node{long long  toit,next,from;long long cap;}road[200010];
long long  q[3000010],n,m,s,t,cnt = 1;
long long l;
long long dis1[20010],dis2[20010];
long long listt[20010],vis[20010],in[20010];
inline void add(long long  u,long long  v,long long  w)
{
	road[++cnt].toit=v; 
	road[cnt].next=listt[u]; 
	listt[u] = cnt; 
	road[cnt].cap =w;
	road[cnt].from=u;
}
inline void spfa(int s)
{
	dis1[s] = 0; 	long long  head=0,tail=1;	q[tail] = s; in[s] = 1;
	while (head<tail) 
	{
		int u = q[++head] ;
		for (int w=listt[u]; w>0; w=road[w].next ) 
		{
			int v=road[w].toit;			
			if (dis1[v]<=dis1[u]+road[w].cap)  continue;
			dis1[v] = dis1[u] + road[w].cap;
			if (in[v]) continue;
			in[v] = 1; 	q[++tail] = v;	
	 	}
		in[u] = 0;
	}
}
inline void SPFA(long long  s)
{	dis2[s] = 0; 	long long head=0,tail=1;	q[tail] = s; in[s] = 1;
	while (head<tail) 
	{
		int u = q[++head] ;
		for (int w=listt[u]; w>0; w=road[w].next ) 
		{
			int v=road[w].toit;			
			if (vis[w]) road[w xor 1].cap=road[w].cap=max(road[w].cap,l-dis1[v]-dis2[u]);
			if (dis2[v]<=dis2[u]+road[w].cap)  continue;
			dis2[v] = dis2[u] + road[w].cap;
			if (in[v]==1) continue;
			in[v] = 1; 	q[++tail] = v;			
		}
		in[u] = 0;
	}	
}
int main()
{
	//memset(dis1,127/3,sizeof(dis1));
	//memset(dis2,127/3,sizeof(dis2));
	//memset(vis,0,sizeof(vis));
	scanf("%lld%lld%lld%lld%lld",&n,&m,&l,&s,&t);
	for (long long i=0; i<=n; i++) vis[i] = 0;
	for (long long i=0; i<=n; i++) dis1[i] = 1e15;
	for (long long i=0; i<=n; i++) dis2[i] = 1e15;
	long long  a,b,c;
	for (long long  i=1; i<=m; i++) 
	{
		scanf("%lld%lld%lld",&a,&b,&c);
		if (c==0) vis[cnt+1] = 1, vis[cnt+2] = 1, c= 1;
		add(a,b,c); add(b,a,c);		
	}
	for (long long i=0; i<=n; i++) in[i]=0;	   spfa(t); 
	for (long long i=0; i<=n; i++) in[i]=0;    SPFA(s);
//	printf("%d",dis2[t]);
	if (dis2[t]!=l)
	{
		printf("NO");
		return 0;
	}
	printf("YES\n");
	for (int i=2; i<=m*2; i++) if (!(i&1)) printf("%lld %lld %lld\n",road[i].from,road[i].toit,road[i].cap) ;	
	return 0;
}
```
*****


## E
### Problem description
> 给你一棵树,每条边有一个权值[0,9],让你找出所有点对(u,v)使得u到v路径组成的数能被m整除(像字符串一样组成)

### Solution
> waiting

### Code
```cpp
```
