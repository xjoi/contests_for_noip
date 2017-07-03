# Contest15 solution


[比赛链接](https://cn.vjudge.net/contest/168929)

## A
### Problem description
> 给出a,b,c,d,求满足k1*a+b=k2*c+d的最小k1。

### Data Limit：a,b,c,d<=100 Time Limit: 1s

### Solution
> 方法一：extgcd。方法二：由于本题数据较小，暴力判断即可。

### Code

```cpp
#include<iostream>
#include<cstdio>
using namespace std;
int a,b,c,d,bo[5000000];
int main(){
    scanf("%d%d%d%d",&a,&b,&c,&d);
    for (int i=b;i<5000000;i+=a) bo[i]=1;
	for (int i=d;i<5000000;i+=c) if (bo[i]) return printf("%d",i),0;
	puts("-1");
	return 0;
}
```

***** 

## B
### Problem description
> 给出一串数，询问其中是否有相反数。

### Solution
> 由于题意较模糊，注意这串数字中可能包含相同的数，所以不可以用绝对值判断。其实开一个bool判断即可。

### Data Limit：n<=10000 Time Limit: 2s

### Code
```cpp
#include<iostream>
#include<cstdio>
using namespace std;
int n,m,k,flag,*b,te[200100],a[200010];
int main(){
    scanf("%d%d",&n,&m);
	b=te+100000;
	for (int i=1;i<=m;++i){
		scanf("%d",&k);
		for (int j=1;j<=k;++j) scanf("%d",&a[j]);
		for (int j=1;j<=k;++j) {if (b[-a[j]]) goto cxt;b[a[j]]=1;}
		puts("YES");return 0;
		cxt:for (int j=1;j<=k;++j) b[a[j]]=0;
	}
	puts("NO");
	return 0;
}
```
*****
### 以下考后补题
*****
## C
### Problem description
> 有一圈星球标号为1-n，1号是黑洞，给出每人的可行的旋转集合，两人轮流旋转，把i转到黑洞者胜利，问对于每个i是必胜，必败还是无限循环。

### Solution
> 考虑三维dp,f[i][j][2]表示走i步，在j号点是否必胜。容易得出dp方程。然而经过大量减枝仍然tle在最后一个点。容易发现当某个点被判定为必胜或必败后不会改变，于是考虑用bfs优化dp把复杂度加为N^2。

### Data Limit：n<=7000 Time Limit: 4s

### Code
```cpp
#include<iostream>
#include<cstdio>
using namespace std;
const int N=7010;
int n,m,clt,f[2][N],s[2][N],nu[N][2],q[N<<1],ty[N<<1];
int main(){
    scanf("%d",&n);
	for (int wh=0;wh<=1;++wh){
		scanf("%d",&s[wh][0]);
		for (int i=1;i<=s[wh][0];++i) scanf("%d",&s[wh][i]);
	}
	for (int i=1;i<=n;++i) nu[i][0]=s[0][0],nu[i][1]=s[1][0];
	int h=0,t=0;
	f[0][1]=f[1][1]=-1;
	ty[t]=0;q[++t]=1;
	ty[t]=1;q[++t]=1;
	while (++h<=t){
		int lt=ty[h],lx=q[h],nt=lt^1;
		for (int i=1;i<=s[nt][0];++i){
			int nx=(lx+n-s[nt][i]-1)%n+1;
			if (f[nt][nx]) continue;
			if (f[lt][lx]==-1) f[nt][nx]=1,q[++t]=nx,ty[t]=nt;
			else{
				--nu[nx][nt];
				if (!nu[nx][nt]) f[nt][nx]=-1,q[++t]=nx,ty[t]=nt;
			}
		}
	}
	for (int i=2;i<=n;++i) printf(f[0][i]?f[0][i]>0?"Win ":"Lose ":"Loop ");puts("");
	for (int i=2;i<=n;++i) printf(f[1][i]?f[1][i]>0?"Win ":"Lose ":"Loop ");
	return 0;
}
```
*****
## D
### Problem description
> 给出若干个点以及若干条边，边有可能为一个点到标号在[l,r]之间的所有点连边。求单源最短路径。

### Solution
> 显然需要建虚拟点，这里可以想到用线段树思想，把每个区间转换为不超过log个节点。

> 于是我们可以构建两棵线段树，每棵线段树上每对父子连边，这样就可以在最多3*N个节点，30*N条边以内建完图，spfa即可。

### Data Limit：n<=100000 Time Limit: 2s

### Code
```cpp
#include<iostream>
#include<cstdio>
#include<queue> 
using namespace std;
#define int long long
const int N=1e5+10,M=N*50;
int n,m,s,x,y,z,xx,yy,size,rt[2],ch[N*10][2],d,tot,fi[N*10],ne[M],a[M],c[M],f[N*10],b[N*10];
queue<int>q;
inline void add(int x,int y,int z){
    a[++tot]=y;c[tot]=z;ne[tot]=fi[x];fi[x]=tot;
}
inline void build(int &v,int l,int r,int ty){
	if (!v) v=++size;
	if (l==r) {ty?add(l,v,0):add(v,l,0);return;}
	int mid=(l+r>>1);
	build(ch[v][0],l,mid,ty);ty?add(ch[v][0],v,0):add(v,ch[v][0],0);
	build(ch[v][1],mid+1,r,ty);ty?add(ch[v][1],v,0):add(v,ch[v][1],0);
}
inline void addline(int x,int y,int po,int va,int ty,int v,int l=1,int r=n){
	if (x<=l&&r<=y) {ty?add(v,po,va):add(po,v,va);return;}
	int mid=(l+r)>>1;
	if (x<=mid) addline(x,y,po,va,ty,ch[v][0],l,mid);
	if (mid<y) addline(x,y,po,va,ty,ch[v][1],mid+1,r);
}
main(){
	scanf("%lld%lld%lld",&n,&m,&s);
	size=n;
	build(rt[0],1,n,0);build(rt[1],1,n,1);
	for (int i=1;i<=m;++i){
		scanf("%lld",&d);
		if (d==1) scanf("%lld%lld%lld",&x,&y,&z),add(x,y,z);
			else if (d==2) scanf("%lld%lld%lld%lld",&x,&xx,&yy,&z),addline(xx,yy,x,z,0,rt[0]);
				else scanf("%lld%lld%lld%lld",&x,&xx,&yy,&z),addline(xx,yy,x,z,1,rt[1]);
	}
	for (int i=1;i<=size;++i) f[i]=1e15;f[s]=0;q.push(s);
	while (!q.empty()){
		int v=q.front();q.pop();b[v]=0;
		for (int i=fi[v];i;i=ne[i])
		if (f[v]+c[i]<f[a[i]]){
			f[a[i]]=f[v]+c[i];
			if (!b[a[i]]) b[a[i]]=1,q.push(a[i]);
		}
	}
	for (int i=1;i<=n;++i) printf("%lld ",f[i]==1e15?-1:f[i]);
	return 0;
}
```
*****
## E
### Problem description
> 给出N个数，要求分成若干连续的组，并计算当每个组中最多K个不同的数时，最少要分多少个组。k∈[1,n]。

### Solution
> 首先贪心做法极好想，即从头开始不停的分在一直至某组超过K个数。详见代码中calc函数。 然而直接处理N^2,TLE。

> 方法1：主席树记录区间不同数的个数，可以通过数学（<del>程序暴力计算</del>）方法得出，（1/1+1/2+1/3...1/n）≈log n
> 所以可知总共不超过log个区间。于是直接主席树处理即可在nlog n^2时间内岀解。

> 方法2：设对于K=i时的答案组数为ans[i]可知当ans[l]=ans[r]时，ans[l,r]答案都一样。故直接分治即可。

### Data Limit：n<=100000 Time Limit: 2s

### Code
```cpp
//方法一
#include<iostream>
#include<cstdio>
using namespace std;
const int N=1e5+10,M=40*N;
int n,m,x,y,rt[N],size,a[N],su[M],c[M][2],la[N];
inline void add(int pos,int val,int &v,int v2,int l=1,int r=n){
	su[v=++size]=su[v2];
	su[v]+=val;
	if (l==r) return;
	int mid=(l+r)>>1;
	if (pos<=mid) add(pos,val,c[v][0],c[v2][0],l,mid),c[v][1]=c[v2][1];
		else add(pos,val,c[v][1],c[v2][1],mid+1,r),c[v][0]=c[v2][0];
}
inline int ask(int y,int v,int l=1,int r=n){
	if (l==r) return l;
	int mid=(l+r)>>1,t=su[c[v][0]];
	return y<=t?ask(y,c[v][0],l,mid):ask(y-t,c[v][1],mid+1,r);
}
int main(){
	scanf("%d",&n);
	for (int i=1;i<=n;++i) scanf("%d",&a[i]);
	for (int i=n;i;--i){
		add(i,1,rt[i],rt[i+1]);
		if (la[a[i]]) add(la[a[i]],-1,rt[i],rt[i]);
		la[a[i]]=i;
	}
	for (int i=1;i<=n;++i){
		int tot=1;
		for (int pos=1;su[rt[pos]]>i;pos=ask(i+1,rt[pos]),++tot);
		printf("%d ",tot);
	}
	return 0;
}
```
```cpp
//方法2
#include<iostream>
#include<cstdio>
using namespace std;
const int N=1e5+10;
int n,m,a[N],ans[N],bo[N];
inline int calc(int x){
    ans[x]=0;
	for (int i=1,la=1,num=0;i<=n;++i){
		num+=bo[a[i]]==0;bo[a[i]]=1;
		if (num>x){num=1;++ans[x];for (int j=la;j<i;++j) bo[a[j]]=0;la=i;}
		if (i==n) {++ans[x];for (int j=la;j<=i;++j) bo[a[j]]=0;la=i;}
	}
}
inline void solve(int l,int r){
	if (r-l<=1) return;
	int mid=(l+r)>>1;calc(mid);
	if (ans[l]==ans[mid]) for (int i=l+1;i<mid;++i) ans[i]=ans[l];else solve(l,mid);
	if (ans[mid]==ans[r]) for (int i=mid+1;i<r;++i) ans[i]=ans[r];else solve(mid,r);
}
int main(){
	scanf("%d",&n);
	for (int i=1;i<=n;++i) scanf("%d",&a[i]);
	calc(1);calc(n);solve(1,n);
	for (int i=1;i<=n;++i) printf("%d ",ans[i]);
	return 0;
}
```
