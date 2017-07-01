# C题[Shaass and Lights:CF294C](http://codeforces.com/problemset/problem/294/C)
### 题意
有N(N<=1000)盏灯，一开始都是暗的，只有其中M盏是亮的。Shaass想要点亮所有的灯，但是每次只能点亮已经点亮的灯的相邻的两盏灯中的一盏。现在Shaass想知道总共有多少种方法点亮所有的灯。结果mod 1e9+7。
### 思路
把这些灯看做线段的话，亮着的灯将线段切分成一个一个小线段。用样例3举例"...#...#..."，被分割成3个线段，不妨命名为ABC。那么AAABBBCCC就是一种开灯方式。这种排列组合总数为$\frac{9!}{3!3!3!}$，对于B线段本身来说总共有$2^{3-1}$种选法。A和C特殊一点，因为是边界线段，有只有一种方案。所以总方案数为$\frac{9!}{3!3!3!}*2^{3-1}*1*1$
### 代码
```c++
#include<cstdio>
#include<algorithm>
#define M 1010
#define MOD 1000000007
using namespace std;
int n,m,a[M],s;
long long pw[M],c[M][M],ans=1;
int main()
{
	pw[0]=pw[1]=1;for(int i=2;i<M;i++) pw[i]=2*pw[i-1]%MOD;
	for(int i=0;i<M;i++) 
  	for(int j=0;j<=i;j++) 
	c[i][j]=((!i||!j||i==j)?1:c[i-1][j]+c[i-1][j-1])%MOD;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++)scanf("%d",&a[i]);
	sort(a+1,a+m+1);s=n-m;
	for(int i=2;i<=m;i++){
		int w=a[i]-a[i-1]-1;
		ans=ans*c[s][w]%MOD*pw[w]%MOD;
		s-=w;
	}
	ans=ans*c[s][a[1]-1]%MOD;
	printf("%lld",ans);
}
```
# D题[Shaass and Painter Robot:CF294D](http://codeforces.com/problemset/problem/294/D)
### 代码
```c++
#include<cstdio>
#include<algorithm>
using namespace std;
int n,m,x,y,tot,a,b,w,f[4][100010],dx,dy;
long long ans;
char ch[10];
void doit(int x,int y){
    if(x==1)a=0,b=y;else if(x==n)a=1,b=y;else if(y==1)a=2,b=x;else a=3,b=x;
	if(!f[a][b])f[a][b]=1,tot++;
	if(x==1)dx=1;if(x==n)dx=-1;if(y==1)dy=1;if(y==m)dy=-1;
}
int main(){
	scanf("%d%d%d%d%s",&n,&m,&x,&y,ch);
	ch[0]=='D'?dx=1:dx=-1;ch[1]=='R'?dy=1:dy=-1;ans=1;
	for(int i=1;i<=2*(n+m-2);i++){
		doit(x,y);
		if(tot>=n+m-2)return printf("%I64d",ans),0;
		w=min(dx>0?n-x:x-1,dy>0?m-y:y-1);
		ans+=w;x+=w*dx;y+=dy*w;
	}
	return printf("-1"),0;
}
```
# E题[Shaass the Great:CF294E](http://codeforces.com/problemset/problem/294/E)
### 代码
```c++
#include <bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)
using namespace std;

const int MAX_N = 5000 + 3;

struct Node{
	int u,w;
	bool f;//0输入的边 1反向边 
//	bool d;//0存在 1已删除 
};
vector<Node> tree[MAX_N];
int size[MAX_N],fa[MAX_N];
long long s[MAX_N];
int N,r1,r2,rt;
long long ANS,sum1,sum2,sx,sy;

void dfs(int u,long long sr)
{
	size[u] = 1;
	s[u] = sr;
	
	int si=tree[u].size();
	rep(i,0,si-1){
		int v = tree[u][i].u;
		int w = tree[u][i].w;
		if (v!=fa[u] && !(u==r1 && v==r2 || u==r2 && v==r1)){
			fa[v] = u;
			dfs(v,sr+w);
			size[u]+=size[v];
			s[u] += s[v];
		}
	}
}

void dfs1(int u,long long& sum,long long& sx)
{
	int si=tree[u].size();
	sum+=s[u];
	sx = min(sx,s[u]);
	rep(i,0,si-1){
		int v = tree[u][i].u;
		int w = tree[u][i].w;
		if (v!=fa[u] && !(u==r1 && v==r2 || u==r2 && v==r1)){
			s[v] = s[u] + (long long)w*(size[rt]-2*size[v]);
			dfs1(v,sum,sx);
		}
	}
}

void task(int w)
{
	fa[r1] = 0;
	dfs(r1,0);
	fa[r2]=0;
	dfs(r2,0);
	rt=r1;
	sum1=0;
	sx=0x7fffffffffffffff;
	dfs1(r1,sum1,sx);
	rt=r2;
	sum2=0;
	sy=0x7fffffffffffffff;
	dfs1(r2,sum2,sy);
	long long tmp = (sum1>>1)+(sum2>>1)+sx*size[r2]+sy*size[r1]+(long long)w*size[r1]*size[r2];
	ANS = min(ANS,tmp);
}

int main() 
{
	scanf("%d",&N);
	rep(i,1,N-1){
		int a,b,w;
		scanf("%d%d%d",&a,&b,&w);
		Node tmp;
		tmp.u = b; tmp.w = w; tmp.f = false;
		tree[a].push_back(tmp);
		tmp.u = a; tmp.f = true;
		tree[b].push_back(tmp);
	}
	ANS=0x7fffffffffffffff;
	rep(i,1,N){
		int si = tree[i].size();
		for(int j=0; j<si; ++j){
			Node tmp = tree[i][j];
			if (!tmp.f){
				r1 = i;
				r2 = tmp.u;
				task(tmp.w);
			}
		}
	}
	printf("%lld",ANS);
	return 0;
}
```
```c++
#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
#define LL long long
#define forw(i,x) for(int i=fir[x];i;i=ne[i])
#define M 20001
#define N M
LL C[M];
int cnt=1,ne[M],fir[M],to[M],from[M];
int n;
LL f[N];
int S[N];
LL ans =1e18;
int x,y;
LL z;
void dfs(int x,int fa)
{
	f[x]=0;S[x]=1;
	forw(i,x)
	{
		int V=to[i];
		if(V!=fa)
		{
			dfs(V,x);
			S[x]+=S[V];
			f[x]+=f[V]+C[i]*S[V];
		}
	}
}
void add(int x,int y,LL z)
{
	to[++cnt]=y;C[cnt]=z;ne[cnt]=fir[x];fir[x]=cnt;from[cnt]=x;
}
void DFS(int x,int fa,LL &p,int sum)
{
	p=min(p,f[x]);
	forw(i,x)
	{
		int V=to[i];
		if(V!=fa)
		{
			f[to[i]]=f[x]+C[i]*(sum-S[V]*2);
			DFS(V,x,p,sum);
		}
	}
}
int main()
{
	cin>>n;
	for(int i=1;i<n;i++)
	{
		cin>>x>>y>>z;
		add(x,y,z);
		add(y,x,z);
	}
	for(int i=2;i<=cnt;i+=2)
	{
		int U=from[i];int V=to[i];
		dfs(U,V);
		dfs(V,U);
		LL p1=1e18,p2=1e18;
		DFS(U,V,p1,S[U]);DFS(V,U,p2,S[V]);
		long long dance=0;
		for(int j=1;j<=n;j++) dance+=f[j];
		long long it;
		it=dance+2*(S[U]*S[V]*C[i]+p1*S[V]+p2*S[U]);
		ans=min(ans,it);
	}
	cout<<ans/2;
	return 0;
}
```
```c++
#include<cstdio>
#include<algorithm>
#define M 20000
using namespace std;
long long f[6666],si[6666],g[6666],ans;
int a[M],c[M],fi[M],ne[M],la[M],n,x,y,z,tot;
void add(int x,int y,int z){
	a[++tot]=y;c[tot]=z;
	!fi[x]?fi[x]=tot:ne[la[x]]=tot;la[x]=tot;
}
void dfs(int x,int fa){
	f[x]=0;si[x]=1;
	for(int i=fi[x];i;i=ne[i])if(a[i]!=fa){
		dfs(a[i],x);
		si[x]+=si[a[i]];
		f[x]+=si[a[i]]*c[i]+f[a[i]];
	}
}
void find(int x,int fa,long long &p,int num){
	p=min(p,f[x]);
//	printf("f[%d]=%lld\n",x,f[x]);
	for(int i=fi[x];i;i=ne[i])if(a[i]!=fa){
		
		f[a[i]]=f[x]+(num-2*si[a[i]])*c[i];
		find(a[i],x,p,num);
	}
}
int main(){
	scanf("%d",&n);
	tot=1;
	for(int i=1;i<=n-1;i++){
		scanf("%d%d%d",&x,&y,&z);
		add(x,y,z);
		add(y,x,z);
	}
	int i=0;ans=1e18;
	while(i<=tot){
		i+=2;
		if(i>tot)break;
		dfs(a[i],a[i^1]);
		dfs(a[i^1],a[i]);
	    long long p1=1e18,p2=1e18;
		find(a[i],a[i^1],p1,si[a[i]]);
		find(a[i^1],a[i],p2,si[a[i^1]]);
	//	printf("%d %d %lld %lld\n",a[i],a[i^1],p1,p2);
		long long sum=0;
		for(int j=1;j<=n;j++)sum+=f[j];
	//	printf("%lld\n",sum);
		ans=min(ans,sum+2*(si[a[i]]*si[a[i^1]]*c[i]+p1*si[a[i^1]]+p2*si[a[i]]));
	}
	printf("%I64d",ans/2);
}
```
