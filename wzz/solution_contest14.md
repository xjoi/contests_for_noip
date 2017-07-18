# 比赛记录contest14

[比赛链接](https://vjudge.net/contest/168561#problem/)
## 比赛征程
> * YES : solved in the contest
> * Accepted : solved after contest
> * Waiting : solving


  \# |  A  |  B  |  C  |  D  |  E  
---|---|---|---|---|---|
|contest13|YES|  YES  | YES | AC |Waiting|

## A
### Problem description
> 一台电脑c秒不打，屏幕清空，告诉你打各个单词的时间，让你求最后屏幕上有几个单词
### Solution
这道题强行枚举即可
```cpp
using namespace std;
#include<bits/stdc++.h>
#define ll long long
int n,c;
int t[1000001];
int main()
{
	cin>>n>>c;
	int cnt=0;
	for(int i=1;i<=n;i++) cin>>t[i];
	cnt=1;
	for(int i=2;i<=n;i++)
	{
		if(t[i]-t[i-1]<=c) cnt++;else cnt=1;
	}
	cout<<cnt;
}
```
## B
### Problem description
> 一个仅有大写字母构成的字符串，有一些位置不确定，让你补全这个字符串使其至少出现一个26个字符的子串其包含所有26个字母
### Solution
这道题也是强行模拟，就是一个hash记录一下除位置外26个字母各有几个，记录种数和总字母个数，相等时输出即可。还是左端点暴枚的方法。
代码的简洁性不够，要多看别人的代码以锻炼。
```cpp
using namespace std;
#include<cstdio>
#include<iostream>
#include<cstring>
#define N 600001
char s[N];
int hash[26];
int cnt;
int it[N];
int sum;
int l;
void print(int ll,int r)
{
//	cout<<ll<<" "<<r<<endl;
	for(int i=1;i<=ll-1;i++)
	{
		if(!~it[i])putchar('W');else putchar(it[i]+'A');
	}
	for(int i=ll;i<=r;i++)
	{
		if(~it[i]) {char hh=it[i]+'A';putchar(hh);}
		else
		{
			for(int j=0;j<26;j++) if(!hash[j]){char hh=j+'A';putchar(hh);hash[j]++;break;}
		}
	}
	for(int i=r+1;i<=l;i++)
	{
		if(!~it[i])putchar('W');else putchar(it[i]+'A');
	}
}
int main()
{
	scanf("%s",s);
	l=strlen(s);
	for(int i=0;i<l;i++) 
	{
		if(s[i]=='?') it[i+1]=-1;
		else it[i+1]=s[i]-'A';
	}
	if(l<26){puts("-1");return 0;}
	for(int i=1;i<=26;i++) if(~it[i])
	{
		sum++;
		if(!hash[it[i]]) cnt++;hash[it[i]]++;
	}
	if(sum==cnt) {print(1,26);return 0;}
	for(int i=2;i<=l-25;i++)
	{
		if(~it[i-1])  sum--;
		if(~it[i+25]) sum++;
		if(~it[i-1])
		{
			if(hash[it[i-1]]==1) cnt--;hash[it[i-1]]--;
		}
		if(~it[i+25])
		{
			if(hash[it[i+25]]);else cnt++;hash[it[i+25]]++;
		} 
		if(sum==cnt) {print(i,i+25);return 0;}
	}
	puts("-1");
}
```
## C
### Problem description
> 你初始在level 1，有数字2.在第k级你可以执行多次使该数+k的操作。如果该数是一个完全平方数且完全平方根是(k+1)的倍数你可以将该数开方然后晋极到levelk+1
你想到第n+1层，输出每层你加的次数。
### Solution
每次让他取到(n*(n+1))\^2然后晋极即可，经计算不会暴long long。构造题强制加条件或者最值法。
```cpp
	for(long long i=1;i<=n;i++)
	{
		if(i==1){printf("%d\n",2);continue;}
		ans=i*((i+1)*(i+1))-i+1;
		printf("%lld\n",ans);
	}
```



***** 
# 赛后补题

## D
### Problem description
> 给你一个图，一些便不确定，要求给这些边赋正整数值，使得s->t的最短路恰好为l
### Solution
错解：两遍SPFA，一遍不加确定边，如果dis[t]过大直接输NO,另一遍加确定边设其权值为1，跑一遍SPFA，在最短路上更新不确定边使最短距离为l，然后把其他不确定边改为
1e18。这道题就是典型的没有考虑更改前后的可行性，以及更改的影响，所以不难举出反例，一条边改了以后他两端的边权值比其更小，就走他两边的路，导致最短路偏小。
</br>
解决方案一：一直更改直到最短路为l。每次跑一个SPFA检验。
解决方案二：把可变边赋值为1.两遍SPFA第一遍求出所有点到t的最短路，第二遍最短路，当遇到一个可变边就直接将其更新使得
dis2[from]（第二遍SPFA）+边权+dis[to]（第一遍SPFA）大于等于l，原本小于就改为一样，原来大于就不变。如此可以保证经过每条可变边答案大于等于l,如果原问题可解
则一定存在一种改变方案，其改变后搜剩下的点最短路一直恰好等于l，所有可变边不变。这种思想是一种动态维护的思想，保证一定有解如果原题有解，这是构造题巧妙的思路
解决方案三：标算，可变边先设为1。二分所有边增加的权值和。然后从第一条边开始，依次赋权每一条边，赋值INF，就转下一条，这样做一定保证了最短值不减所以可以二分。
这样做的本质就是一条边上要是改不到，那不用这条边就达到了所能增加的最大值，这样子如果有可行路径，一定在而分到某一状态时可行，即可构造。

</br>可以直接说最短值的区间是1单位修改的，所以权值一定连续，如果能到l就一定能到。下次构造某一特定状态时也可以采用像这样子构造连续权值范围的构造然后二分解决。
给出解法二程序46ms
```cpp
void SPFA(int ss,int tt)
{
	dis[ss]=0;inq[ss]=1;q.push(ss);
	while(!q.empty())
	{
		int it=q.front();q.pop();inq[it]=0;
		forw(i,it)
		{
			if(dis[it]+C[i]<dis[to[i]])
			{
				dis[to[i]]=dis[it]+C[i];
				if(!inq[to[i]])
				{
					inq[to[i]]=1;
					q.push(to[i]);
				}
			}
		}
	}
}
int l,s,t;
void spfa(int ss,int tt)
{
	dis2[ss]=0;inq[ss]=1;q.push(ss);
	while(!q.empty())
	{
		int it=q.front();
		q.pop();
		inq[it]=0;
		forw(i,it)
		{
			if(vis[i])
			{
				C[i^1]=C[i]=max((int)C[i],(int)(l-dis[to[i]]-dis2[it]));
			}
			if(dis2[it]+C[i]<dis2[to[i]])
			{
				dis2[to[i]]=dis2[it]+C[i];
				if(!inq[to[i]])
				{
					inq[to[i]]=1;
					q.push(to[i]);
				}
			}
		}
	}
}

void add(int x,int y,int z)
{
	ne[++cnt]=fir[x];fir[x]=cnt;to[cnt]=y;C[cnt]=z;if(z==0){vis[cnt]=1;C[cnt]++;}
}
int main()
{
	r(n);r(m);r(l);r(s);r(t);
	for(int i=1;i<=m;i++) 
	{
		r(x);r(y);r(z);
		add(x,y,z);
		add(y,x,z);
	}
	memset(dis,63,sizeof(dis));
	memset(dis2,63,sizeof(dis2));
	SPFA(t,s);
	spfa(s,t);
//	cout<<dis2[t]<<endl;
	if(dis2[t]!=l) puts("NO");
	else
	{
		puts("YES");
		for(int i=2;i<=cnt;i+=2) printf("%d %d %d\n",to[i^1],to[i],C[i]);
	}
}
```

## E
### Problem description
> 给你一颗树，求有序点对(x,y)的个数，使得x->y的路径上的数字连起来的数是m的倍数
### Solution
> 待补
```cpp

```
