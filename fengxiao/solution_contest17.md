# Solution
```
/******************
    VJudge链接：  https://cn.vjudge.net/contest/171671
CodeForces链接：  http://codeforces.com/contest/447

题目按CF顺序排序
******************/
```
# #A DZY Loves Hash
```
/******************
     主要算法：模拟
     Data limit:p and n (2 ≤ p, n ≤ 300) xi (0 ≤ xi ≤ 109).
******************/
```
### 题意
给你p,n和若干个数,找到第一个在模p意义下重复出现的数,若没有则输出-1  
### 题解
由于懒得看数据范围于是我直接开了map来维护,如果出现过就标记,遇到标记就输出
### 核心代码
```
/******************
for(i=1;i<=n;i++) {scanf("%d",&a); if(!key[a%p]) key[a%p]=1; else {printf("%d\n",i); return 0;}}
******************/
```
### 错题记录
1A
***
# #B DZY Loves Strings
```
/******************
    主要算法： 简单贪心+模拟
     Data limit:s (1 ≤ |s| ≤ 103).k (0 ≤ k ≤ 103).
******************/
```
### 题意
给你一串字符以及K表示可以再加多少字符,每种字符有自己的价值,字符串的价值计算公式为i*v[]s[i]]  
求如何选择这K个字符使价值最大,输出最大价值  

### 题解
先处理好给你的串,根据贪心发现在整个串的后面一直加价值最大的那个字符一定是最优的,然后就如此模拟便可
### 核心代码
```
/******************
	int i,j,ls,n,ans=0;
	scanf("%s",s); ls=strlen(s);
	scanf("%d",&n);
	for(i=1;i<=26;i++) scanf("%d",&v[i]);
	int maxn=0,pos;
	for(i=1;i<=26;i++) if(v[i]>maxn) {maxn=v[i]; pos=i;}
	for(i=0;i<ls;i++) { ans+=v[s[i]-'a'+1]*(i+1);}
	for(i=1;i<=n;i++) ans+=(ls+i)*maxn;
	printf("%d",ans);
******************/
```
### 错题记录
1A
***
# #C DZY Loves Sequences
```
/******************
      主要算法：模拟
     Data limit:n (1 ≤ n ≤ 105) a[i] (1 ≤ ai ≤ 109)
******************/
```
### 题意
给你一串数,让你修改其中任意一个数,使数列中最长上升子串的长度最长
### 题解
现将该序列分解成若干块,每个块都是严格上升的  
那么可以发现只能改每个快的开头或结尾才能增加答案  
按此模拟即可  
### 核心代码
```
/******************
	for(i=1;i<=n;i++) scanf("%d",&a[i]);
	for(i=1;i<=n;i++) {if(a[i]>a[i-1]) sum[i]=sum[i-1]+1;else {sum[i]=1;for(int j=pos;j<=i-1;j++) nxt[j]=i-1; pos=i;}} for(i=pos;i<=n;i++)nxt[i]=n;
	for(i=1;i<=n;i++)
	{
		msum=max(msum,sum[i]);
		if(sum[i]==1&& a[i+1]-a[i-1]>1) ans=max(ans,sum[i-1]+sum[nxt[i+1]]+(a[i]>=a[i+1] ? 1 : 0));
		if(nxt[i]==i&& a[i+1]-a[i-1]>1) { ans=max(ans,sum[i-1]+1+sum[nxt[i+1]]);}
	}
	printf("%d",max(msum+(msum==n ? 0 : 1),ans));
******************/
```
### 错题记录
若干次由于不用改但我却强改了而WA,若干次由于边界+-1WA...
***
# #D DZY Loves Modification
```
/******************
      主要算法：贪心+堆
     Data limit:n, m, k and p (1 ≤ n, m ≤ 103; 1 ≤ k ≤ 106; 1 ≤ p ≤ 100).
******************/
```
### 题意
给你个矩阵,给你k次操作机会,每次操作可以选择1行/列,价值+=行/列的数字和,之后这行/列的值全部-p
### 题解
经过分析发现当确定要取多少行多少列时,可以计算出它们之间互相影响的值:p*i*(k-i)  
那么我们只需要处理出只取若干行获得的最高价值和支取若干列的最高价值便可以枚举取多少行列  
上述步骤可以用堆来完成  
### 核心代码
```
/******************
	for(i=1;i<=n;i++)
		for(j=1;j<=m;j++)
		{
			scanf("%I64d",&map[i][j]);
			rs[i]+=map[i][j]; cs[j]+=map[i][j];
		}
	for(i=1;i<=n;i++) rq.push(rs[i]);
	for(i=1;i<=K;i++)
	{
		int u=rq.top(); rq.pop();
		sumr[i]=sumr[i-1]+u;
		u-=p*m; rq.push(u);
	}
	for(i=1;i<=m;i++) cq.push(cs[i]);
	for(i=1;i<=K;i++)
	{
		int u=cq.top(); cq.pop();
		sumc[i]=sumc[i-1]+u;
		u-=p*n; cq.push(u);
	}
	for(i=0;i<=K;i++) ans=max(sumr[i]+sumc[K-i]-p*i*(K-i),ans);
	printf("%I64d",ans);
******************/
```
### 错题记录
刚开始没有枚举不取行的状态

***
# #E DZY Loves Fibonacci Numbers
```
/******************
      主要算法：线段树or分块(maybe T)
     Data limit:n and m (1 ≤ n, m ≤ 300000)
******************/
```
### 题意
给你一个数列和两种操作  
1.1 l r :让你在区间l,r中的每个数+Fib[i-l+1]
2.2 l r :让你输出区间l,r的和
### 题解
此题需要深度理解标记的可重叠性以及pushdown操作的意义  
如果简化操作1那么便是简单的线段树  
然而操作1却让我们的标记很难合并  
经过分析可以发现若干个斐波那契数列的和还是满足斐波那契数列的性质,于是便可以利用这点性质记录序列前两个数推出整个数列  
然后就可以愉(ku)快(bi)地push_down了  
PS:听说好像分块也可以过,实现原理跟线段树大相径庭  
### 核心代码
```
/******************
void init_fib()
{
	f[1][0]=f[2][1]=1;
	for(int i=3;i<=300000;i++) {f[i][0]=(f[i-1][0]+f[i-2][0])%P; f[i][1]=(f[i-1][1]+f[i-2][1])%P;}
	for(int i=1;i<=300000;i++) {fs[i][0]=(fs[i-1][0]+f[i][0])%P; fs[i][1]=(fs[i-1][1]+f[i][1])%P;}
}
inline void build_tre(int u,int l,int r)
{
	s[u]=l,e[u]=r;
	if(l==r) {sum[u]=a[l]; return;}
	build_tre(lc,l,mid); build_tre(rc,mid+1,r);
	sum[u]=sum[lc]+sum[rc]; return ;
}
inline int calc(int f1,int f2,int len) {return (f1*f[len][0]+f2*f[len][1])%P;}
void pd(int u)
{
	if(laz[u][0] && laz[u][1] && s[u]!=e[u])
	{
		int lenl=mid-s[u]+1,lenr=e[u]-mid;
		int tmp1=calc(laz[u][0],laz[u][1],lenl+1),tmp2=calc(laz[u][0],laz[u][1],lenl+2);
		sum[lc]=(sum[lc]+(laz[u][0]*fs[lenl][0])%P+(laz[u][1]*fs[lenl][1])%P)%P;
		sum[rc]=(sum[rc]+(tmp1*fs[lenr][0])%P+(tmp2*fs[lenr][1])%P)%P;
		laz[lc][0]=(laz[lc][0]+laz[u][0])%P;laz[lc][1]=(laz[lc][1]+laz[u][1])%P;
		laz[rc][0]=(laz[rc][0]+tmp1)%P;     laz[rc][1]=(laz[rc][1]+tmp2)%P;
		laz[u][0]=laz[u][1]=0;
		return;
	}
	return;
}
void update(int u,int l,int r)
{
	if(l<=s[u] && e[u]<=r)
	{
		int tmp1=calc(1,1,s[u]-l+1),tmp2=calc(1,1,s[u]-l+2),len=e[u]-s[u]+1;
		laz[u][0]=(laz[u][0]+tmp1)%P;laz[u][1]=(laz[u][1]+tmp2)%P; 
		sum[u]=(sum[u]+(tmp1*fs[len][0])%P+(tmp2*fs[len][1])%P)%P;
		return;
	}
	pd(u);
	if(l<=mid) update(left); if(r> mid) update(right);
	sum[u]=(sum[lc]+sum[rc])%P;
}
int query(int u,int l,int r)
{
	if(l<=s[u] && e[u]<=r) return sum[u];
	pd(u); int ans=0;
	if(l<=mid) ans=(ans+query(left))%P;
	if(r> mid) ans=(ans+query(right))%P;
	return ans;
}
******************/
```
###错题记录
pushdown中几个变量写错了..调了一年
***
