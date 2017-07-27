[比赛链接](http://210.33.19.101/contest/755)

# 比赛中解决的问题



## B
### Problem description
> 在一个N×M的区域中存在有若干个景点（不超过10个），且每一小区域的海拔高度是高低不一的。假设相临两1×1区域的高度差为x，
则从其中一个区域移到另一区域将耗费x^2+1分钟的时间。我们要求得到一条由区域（1，1）出发，经过所有景点的路线，并保证花费的时间最短。


### Data Limit：n <= 100，m<=100,p<=10  Time Limit: 1s
### Solution
> 先spfa出每个景点到各个位置的最短路，然后暴力枚举到各个景点的次序，算出答案。

### Code
```cpp
%:pragma GCC optimize(3)
#include<bits/stdc++.h>
long long n,m,i,j,a[500][500],p,x[100],y[100],h,t,cx[100],ans,last;
long long f[11][1000001],q[10000001][3],b[10000];
bool bo[10000001];
void cxt()
{
	
	long long i;
	long long tot=0;
	tot=f[cx[1]][1];
	for (i=2;i<=p;i++) 
		tot+=f[cx[i]][(x[cx[i-1]]-1)*n+y[cx[i-1]]];
	if (ans>tot) ans=tot;

}
void dfs(long long x)
{
	if (x>p) 
	{
		cxt();
		return;
	}
	for (long long i=1;i<=p;i++)
	if (b[i]==0)
	{
		b[i]++;
		cx[x]=i;
		dfs(x+1);
		b[i]--;
	}
}
void push(long long x,long long y,int fa)
{
	if (f[fa][(x-1)*n+y]>f[fa][(q[t][1]-1)*n+q[t][2]]+(a[x][y]-a[q[t][1]][q[t][2]])*(a[x][y]-a[q[t][1]][q[t][2]])+1)
	{
		f[fa][(x-1)*n+y]=f[fa][(q[t][1]-1)*n+q[t][2]]+(a[x][y]-a[q[t][1]][q[t][2]])*(a[x][y]-a[q[t][1]][q[t][2]])+1;
		if (!bo[(x-1)*n+y])
		{
			h++;
			q[h][1]=x;
			q[h][2]=y;
			bo[(x-1)*n+y]=true;
		}
	}
}
int main()
{
	scanf("%lld%lld",&n,&m);
	for (i=1;i<=n;i++)
	for (j=1;j<=m;j++)
	scanf("%lld",&a[i][j]);

	scanf("%lld",&p);
	for (i=1;i<=p;i++) scanf("%lld%lld",&x[i],&y[i]);
	for (i=0;i<=p;i++)
	{
		h=0;t=0;
		for (j=0;j<=100000;j++) bo[j]=false;
		for (j=0;j<=100000;j++) f[i][j]=1000000000000000;
		f[i][(x[i]-1)*n+y[i]]=0;
		//push(x[i],y[i]);
		h++;
		q[h][1]=x[i];
		q[h][2]=y[i];
		bo[(x[i]-1)*n+y[i]]=true;
		while (h>t)
		{
		  t++; bo[(q[t][1]-1)*n+q[t][2]]=false;
		  if (q[t][1]+1<=n) push(q[t][1]+1,q[t][2],i);
		  if (q[t][2]+1<=m) push(q[t][1],q[t][2]+1,i);
		  if (q[t][1]-1>=1) push(q[t][1]-1,q[t][2],i);
		  if (q[t][2]-1>=1) push(q[t][1],q[t][2]-1,i);
		}
	}
	ans=1000000000000000;
	for (i=1;i<=p;i++)b[i]=0;
	dfs(1);
	printf("%lld",ans);
	return 0;

}
```
*****

# 赛后补题
## A
### Problem description
> 输入两个棋盘，问前一个能否变为第二个
变化方法
1.把一个棋子向左或右移动四格
2.将一个棋子移动到它右边第3个格子（如果右边第1和3个格子为空，且它右边第2个格子不为空），
移动之后，原先它右边第1个格子将会放上一个棋子，右边第2个格子上的棋子将会被拿走。
3.将一个棋子移动到它右边第2个格子（如果右边第1个格子不为空，且它右边第2个格子为空），移动之后，原先它右边第1个格子上的棋子将会被拿走。
### Data Limit：T<=30 n=30 Time Limit: 1s

### Solution
> 因为把一个棋子向左或右移动四格，所以可以把棋子分为四类
所处位置mod 4余0.1.2.3
然后用剩下两个变化dfs一下即可

### Code
```cpp
#include<bits/stdc++.h>
using namespace std;
int n,T,a[5],b[5],f[31][31][31][31];
char s[50],t[50];
inline void dfs(int a,int b,int c,int d){
    if (f[a][b][c][d]) return;
    f[a][b][c][d]=1;
    if (a&&c) dfs(a-1,b+1,c-1,d+1);
    if (b&&d) dfs(a+1,b-1,c+1,d-1);
    if (a&&b) dfs(a-1,b-1,c+1,d);
    if (b&&c) dfs(a,b-1,c-1,d+1);
    if (c&&d) dfs(a+1,b,c-1,d-1);
    if (d&&a) dfs(a-1,b+1,c,d-1);
}
int main(){
    scanf("%d",&T);
    while (T--){
        scanf("%s%s",s,t);
        memset(f,0,sizeof f);
        memset(a,0,sizeof a);
        memset(b,0,sizeof b);
        for (int i=0;s[i];++i) a[i%4]+=s[i]=='*';
        for (int i=0;t[i];++i) b[i%4]+=t[i]=='*';
        dfs(a[0],a[1],a[2],a[3]);
        printf(f[b[0]][b[1]][b[2]][b[3]]?"YES\n":"NO\n");
    }
    return 0;
}

```
*****
## C
### Problem description
> 给定一个正整数N，找到符合下面方程的正整数解（X，Y）的数量（N!=1*2*…*N）：
1/N! = 1/X + 1/Y

### Data Limit：n <= 10000  Time Limit: 1s

### Solution
> 由题意，x，y都大于n！
设n！=m，x=m+k所以原式可写成1/m=1/(m+k)+1/y
所以y=m^2/k+m
所以答案就是m^2的因数个数
若m的质因数分解为p1^e1 * p2^e2 * p3^e3 *...*pk^ek
则ans=(2*e1+1)*(2*e2+1)*...*(2*ek+1)
还要高精度。

### Code
```cpp
#include<bits/stdc++.h>
int n,i,j;
int top,p[10000],a[10000],ans[100000],len,T;
bool b[100000];
int main()
{
	top=0;
	for (i=1;i<=10000;i++){
		b[i]=false;
		a[i]=0;
	}
	for (i=2;i<=10000;i++)
	if (!b[i])
	{
		
		top++;
		p[top]=i;
		for (j=2;j*i<=10000;j++)b[j*i]=true;
	}
	
	//scanf("%d",&T);
	while (scanf("%d",&n)==1&&n>0)
	{
		
	    for (i=1;i<=10000;i++)a[i]=0;
	    for (i=2;i<=n;i++)
	    {
	    	int t=i;
	    	int h=0;
	    	while (t>1)
	    	{
	    		h++;
	    		while (t%p[h]==0) 
	    		{
	    			t=t/p[h];
	    			a[h]++;
	    		}
	    	}
    	}
    	
    	for (i=1;i<=100000;i++)ans[i]=0;
    	ans[1]=1;len=1;
	    for (i=1;i<=top;i++)
	    {
		    int c=a[i]*2+1;
		    for (j=1;j<=len;j++)
		    {
		    	ans[j]*=c;
		    	//ans[j+1]+=ans[j]/10;
		    	//ans[j]=ans[j]%10;
			}
			for (j=1;j<=len;j++)
		    {
		    	//ans[j]*=c;
		    	ans[j+1]+=ans[j]/10;
		    	ans[j]=ans[j]%10;
			}
			while (ans[len+1]>0) 
			{
				len++;
				ans[len+1]+=ans[len]/10;
		    	ans[len]=ans[len]%10;
			}
      	}
      	for (i=len;i>=1;i--)printf("%d",ans[i]);
      	printf("\n");
    }
	
	
	
	return 0;
}
```
*****



