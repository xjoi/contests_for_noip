# 比赛记录contest13

[比赛链接](https://vjudge.net/contest/168406#problem/)
## 比赛征程
> * YES : solved in the contest
> * Accepted : solved after contest
> * Waiting : solving


  \# |  A  |  B  |  C  |  D  |  E  |  F  |  G  
---|---|---|---|---|---|---|---
|contest13|YES|  YES     | YES | YES | AC | AC|Waiting

## A
### Problem description
> 就是说给你一个字符串，描述了一个天平，然后要求输出这个天平的平衡情况。
### Solution
仔细分析一下，这个题就是强行枚举，先从左往右扫，找到支点，然后左右两边分别计算力矩，比下大小，恶心的是要开long long，因此WA了一发，可见数据范围的重要性
```cpp
using namespace std;
#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
char s[20000001];
int l;
int it;
long long le=0,ri=0;
long long ll=0,rl=0;
int main()
{
	scanf("%s",s);
	int l=strlen(s);
	for(int i=0;i<l;i++){if(s[i]=='^') {it=i;break;}}
	ll=0;rl=0;le=ri=0;
	for(int i=it-1;i>=0;i--)
	{
		ll++;
		if(s[i]>='0'&&s[i]<='9')
		{
			le+=(s[i]-'0')*ll;
		}
	}
	for(int i=it+1;i<l;i++)
	{
		rl++;
		if(s[i]>='0'&&s[i]<='9')
		{
			ri+=(s[i]-'0')*rl;
		}
	}
	if(le==ri){puts("balance");return 0;}
	if(le<ri){puts("right");return 0;}puts("left");
}
```
## B
### Problem description
> 就是说给告诉你很多如下的关系：A欠B x元，然后让你找到一种替代方案使得每个人应得的钱没有变。该方案钱流通的最少
### Solution
这道题是一道贪心题，只要计算每个人的入账和出账，因为只要每个人应得或应付的钱不变就可以了，所以我们就直接把每个人结算完后应得多少，应付多少算出，应得的人
应得钱的总和即为答案，这样做一定不能再优化，且一定最优。
```cpp
using namespace std;
#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#define N 101
#define ll long long
ll A[201];
ll n,m,a,b,c;
long long res;
int main()
{
	cin>>n>>m;
	memset(A,0,sizeof(A));
	for(int i=1;i<=m;i++)
	{
		cin>>a>>b>>c;
		A[a]-=c;A[b]+=c;
	}
	for(int i=1;i<=n;i++)
	{
		if(A[i]>0) res+=A[i];
	}
	cout<<res;
}
```
## C
### Problem description
> 给你一个数，你可以任意调换数字的顺序且这个数一定含有1, 6, 8, 9，使最后的数为7的倍数，输出最后的数，若没有就输出0。
### Solution
把1、6、8、9放在数列的最前端，因为1689的全排列能构成7的剩余系，所以先是利用一位位mod 7取得系数，全排列一发如果可行就输出。
以后遇到这种构造题要观察数据的性质，先尝试暴力一发，再做。
```cpp
using namespace std;
#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<cstdlib>
int mod[1000001];
char s[2000001];
int it[2000001];
int yu[7];
int num[7];
int res;
bool vis[10];
int ans;
bool cmp(int x,int y) 
{
	return x>y;
}
int main()
{
	mod[1]=1;
	for(int i=2;i<=1000000;i++) mod[i]=(mod[i-1]*10)%7;
	scanf("%s",s);
	int l=strlen(s);
	for(int i=0;i<l;i++)it[i+1]=s[i]-'0';
	sort(it+1,it+l+1);
//	cout<<l<<endl;
	for(int i=1;i<=l-4;i++)
	{
		if(!vis[1]&&it[i]==1) {swap(it[l-3],it[i]);vis[1]=1;}
		if(!vis[6]&&it[i]==6) {swap(it[l-2],it[i]);vis[6]=1;}
		if(!vis[8]&&it[i]==8) {swap(it[l-1],it[i]);vis[8]=1;}
		if(!vis[9]&&it[i]==9) {swap(it[l],it[i]);vis[9]=1;}
	}
	for(int i=1;i<=l-4;i++) res=(res+it[i]*mod[i])%7;
	ans=res;
	while(next_permutation(it+l-3,it+l+1))
	{
		ans=res;
		for(int i=l-3;i<=l;i++) ans=(ans+it[i]*mod[i])%7;
		if(ans==0)
		{for(int i=l;i>=1;i--)printf("%d",it[i]);return 0;} 
	}
	puts("0");
}
```

## D
### Problem description
> 给你一个有一些黑格的矩阵，你可以任意换矩阵的行和列，然后求这个矩阵中能存在的最大全黑子矩阵的面积
### Solution
这道题用到了常用的矩阵中枚举开始点，再+贪心\DP的方法，然后顺序枚举加hash 这么做可以利用前面节点的信息转移方便
具体实现：倒序枚举起始格，计算该格开始，最长长度为x的个数，这样子每次可以O(n)转移，O(m)计算，这种可以快速前推后的可以用这种方法。
```cpp
using namespace std;
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdlib>
#define N 5002
int a[N][N];
int hash[N];
int k[N];
int n,m;
int ans=0;
char s[N];
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	{
		scanf("%s",s);
		for(int j=1;j<=m;j++) a[i][j]=s[j-1]-'0';
	}
	for(int i=m;i>=1;i--)
	{
		for(int j=1;j<=n;j++)
		{
			if(a[j][i]==1) {k[j]++;hash[k[j]-1]--;hash[k[j]]++;}
			else{hash[k[j]]--;k[j]=0;hash[0]++;}
		}
		int cnt=0;
		for(int j=m;j>=1;j--)
		{
			cnt+=hash[j];
			ans=max(ans,cnt*j);
		}
	}
	cout<<ans<<endl;
}
```


***** 
# 赛后补题

## E
### Problem description
> 就是给你一个矩阵，给你一个开始点，你每次只能走到相邻的可行格。</br>
不可行格有：</br>
1、宝藏</br>
2、炸弹</br>
3、墙</br>
要求你走可行格，最后回到出发点，围成的图形内部不包含炸弹且宝藏权值和减路径长度最大（可以不动）
### Solution
> 围豆豆加强版，炸弹只需要当成一个权值负无限大的豆豆就可以了。
主要思想：判断一个点在一个平面图形内的方法：从这个点射出一条射线，交这个图形如果奇数次则在内部否则在外部，很好证：每穿一次，都会从内、外两种状态
调换，最后是外，利用奇偶性可知原本图形内外。
这道围豆豆利用这个思想，但为了防止特殊情况，必须规定单一的射线穿的方向，具体实现是取min。每次预处理就是给一列上的都打上标记。
```cpp
using namespace std;
#include<bits/stdc++.h>
#define N 22
char ma[N][N];
int n,m;
int dp[N][N][1<<9];
bool vis[N][N][1<<9];
int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};
int val[N];
char s[N];
int cnt;
int ans;
int en[N][N];
int x,y;
bool can[N][N];
struct NODE{
	int x,y,ty;
}tmp;
queue<NODE>q;
void dodp()
{ 
	for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) for(int k=1;k<=(1<<9);k++) {vis[i][j][k]=0;dp[i][j][k]=-2000000;}
	dp[x][y][0]=0;
	tmp.x=x;tmp.y=y;tmp.ty=0;
	q.push(tmp);
	while(!q.empty())
	{
		NODE ind=q.front();q.pop();
		int xx=ind.x,yy=ind.y,t=ind.ty;
		for(int i=0;i<4;i++)
		{
			int ty=t;
			int xc=xx+dx[i],yc=yy+dy[i];
			if(xc<=0||yc<=0||xc>n||yc>m)continue;
			if(can[xc][yc])continue;
			if(i<=1){ty=ty^(en[xx][min(yy,yc)]);}
			if(vis[xc][yc][ty]) continue;
			vis[xc][yc][ty]=1;
			int res=dp[xx][yy][t];
			for(int i=1;i<=9;i++){if(t&(1<<i))res-=val[i];}
			for(int i=1;i<=9;i++){if(ty&(1<<i))res+=val[i];}
			dp[xc][yc][ty]=res-1;
			tmp.ty=ty;tmp.x=xc;tmp.y=yc;
			q.push(tmp);
		}
	}
}
int main()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		scanf("%s",s);
		for(int j=1;j<=m;j++) ma[i][j]=s[j-1];
		for(int j=1;j<=m;j++)
		{
			if(ma[i][j]>='1'&&ma[i][j]<='9')
			{
				cnt=max(cnt,ma[i][j]-'0');
				can[i][j]=1;
				for(int k=i;k>=1;k--)en[k][j]|=(1<<(ma[i][j]-'0'));
			}
			if(ma[i][j]=='S'){x=i;y=j;}
			if(ma[i][j]=='#')can[i][j]=1;
		}
	}
	for(int i=1;i<=cnt;i++) scanf("%d",&val[i]);
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			if(ma[i][j]=='B')
			{
				cnt++;
				can[i][j]=1;
				for(int k=i;k>=1;k--)en[k][j]|=(1<<(cnt));
				val[cnt]=-2000000;
			}
		}
	}
	dodp();
	for(int i=0;i<=(1<<9);i++)
	{
		ans=max(ans,dp[x][y][i]);
	}
	cout<<ans<<endl;
}
```
## F
### Problem description
> 给你一棵有根树，每个节点有一个颜色，m次询问，询问以x为根的子树中，有多少种节点个数超过k个的颜色？
### Solution
> 这题可以用dfs序转区间+莫队算法实现，维护后缀和，第一次打莫队，其分块复杂度正确的原因：是
1、块内操作，显然是O(根号n)的。
2、块与块之间之间的操作，以后的块一定不包括中间的块了，所以最后还是O(n根号n）的复杂度。
排序是按左端点块号第一关键字，右端点第二关键字排序。
dfs序转区间这是常用方法，就是搜子树前和搜子树后这段区间，显然是对的。
nlogn^2的算法就是启发式合并，两个map还没来得及写，找到重儿子然后一个个并给他就可以了。
```cpp
using namespace std;
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdlib>
#define N 5002
int a[N][N];
int hash[N];
int k[N];
int n,m;
int ans=0;
char s[N];
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	{
		scanf("%s",s);
		for(int j=1;j<=m;j++) a[i][j]=s[j-1]-'0';
	}
	for(int i=m;i>=1;i--)
	{
		for(int j=1;j<=n;j++)
		{
			if(a[j][i]==1) {k[j]++;hash[k[j]-1]--;hash[k[j]]++;}
			else{hash[k[j]]--;k[j]=0;hash[0]++;}
		}
		int cnt=0;
		for(int j=m;j>=1;j--)
		{
			cnt+=hash[j];
			ans=max(ans,cnt*j);
		}
	}
	cout<<ans<<endl;
}
```
## G
### Problem description
> 一颗有黑白染色的树，若任意一个节点总有在k距离内有一个黑色节点则称该树美丽，你每次可以换任意两个节点的颜色，求满足要求的最小次数，否则输-1.
### Solution
> 待补
```cpp

```

