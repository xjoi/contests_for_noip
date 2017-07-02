# Contest14 solution


[比赛链接](https://cn.vjudge.net/contest/168561)

## A
### Problem description
> 给出一串递增的数和c，只有当相邻两数相差<=c时才能归为一块，问最后一个数所在块有几个数。

### Solution
> 暴力从前往后扫，一旦相差超过c就把tot清为1，否则++tot。最终输出tot即可。

### Code

```cpp
#include<iostream>
#include<cstdio>
using namespace std;
int n,m,c,tot,x,lx=-1e9;
int main(){
    scanf("%d%d",&n,&c);
    for (int i=1;i<=n;++i){
    	scanf("%d",&x);
		if (x-lx<=c) ++tot;else tot=1;
		lx=x;
	}
	printf("%d",tot);
}
```

***** 

## B
### Problem description
> 给出一个仅包含大写字母和通配符‘？’的字符串，询问是否有某子串包含了26个大写字母，如果是，同时输出不带通配符的最终串。

### Solution
> 用两个指针维护一个闭区间[l,r]表示当左指针指向l时，右指针最多可以指向r，使得该区间没有重复字母。处理中不用维护通配符的个数，只要当区间大小在某一时刻等于26即可输出答案。

> 然而需要注意的是，首先子串要求连续，然后多余的通配符需要都输出A。然后就可以AC了。

### Code
```cpp
#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int n,m,ti[27],tp;
char s[60100];
int main(){
    scanf("%s",s);
	int n=strlen(s),l=0,r=-1;
	while (r<n){
		while (++r,r<n&&r-l<26&&(s[r]=='?'||!ti[s[r]-'A'])) ++ti[s[r]-'A'];
		if (r-l==26){
			for (int i=0;i<l;++i) putchar(s[i]=='?'?'A':s[i]);
			for (int i=l;i<min(l+26,r);++i)
				if (s[i]=='?'){
					int pos=0;
					while (ti[pos]&&pos<'Z') ++pos;
					ti[pos]=1;putchar(pos+'A');
				}else putchar(s[i]);
				for (int i=min(l+26,r);s[i];++i) putchar(s[i]=='?'?'A':s[i]);
			return 0;
		}
		if (r==n) break;
		++ti[s[r]-'A'];
		while (ti[s[r]-'A']>1) s[l]!='?'?--ti[s[l]-'A']:0,++l;
	}
	puts("-1");
}

```
*****
## C
### Problem description
> 最开始，你在level 1，屏幕上有一个数2。你有两种操作：把屏幕上的数加上你的level。把屏幕上的数开根，同时你level++。

> 但你需要保持这样的性质：屏幕上的数是你的level的倍数，操作二时该数必须为完全平方数。

> 问升到n+1级过程中每次升级前执行操作1的次数。

### Solution
> 吐槽一下代码居然比B题还短。

> 容易发现执行操作1对性质1不会造成影响，所以我们仅考虑操作2。

> 设当前level=k，则设开根的时候屏幕上为x*k，则开根后屏幕上为sqrt（x*k），由于性质1、2，可知x*k为完全平方数且（k+1）|sqrt（x*k）。当x=（k+1）*（k+1）*k时满足这两个条件，故由此直接计算出解。

### Code
```cpp
#include<iostream>
#include<cstdio>
using namespace std;
#define int long long
int n,m;
main(){
    scanf("%lld",&n);
	for (int x=2,le=1;le<=n;++le){
		printf("%lld\n",(le+1)*(le+1)*le-x/le);
		x=(le+1)*le;
	}
	return 0;
}
```
*****
### 以下考后补题
*****
## D
### Problem description
> 给出一张带有可变边的图，终点和起点以及期望的最短路，请你通过对可变边赋值使最短路变成期望值，并输出方案。

### Solution
> 有两遍spfa的优秀做法，即先把可变边设为1，并从终点计算出到每个点的最短路，然后再从起点出发，每当遇到一条可变边就把它的长度设置为（L - 起点到它的最短路 - 它到终点的最短路）。易证此为满足题意的充分必要条件。

### Code
```cpp
#include<iostream>
#include<cstdio>
using namespace std;
#define int long long
const int N=1010,M=20010;
int n,m,L,s,e,x,y,z,tot=1,a[M],c[M],fi[N],ne[M],q[N*N],f[N][2],b[N],rmp[M];
inline void add(int x,int y,int z){
    if (!z) rmp[tot+1]=z=1;
	a[++tot]=y;c[tot]=z;ne[tot]=fi[x];fi[x]=tot;
}
inline void spfa(int s,int o){
	for (int i=0;i<n;++i) f[i][o]=1e15;f[s][o]=0;q[1]=s;
	for (int h=0,t=1;b[q[++h]]=0,h<=t;)
		for (int i=fi[q[h]];i;i=ne[i]){
			if (o&&rmp[i]) c[i]=c[i^1]=max(c[i],L-f[a[i]][0]-f[q[h]][1]);
			if (f[a[i]][o]>f[q[h]][o]+c[i]){
				f[a[i]][o]=f[q[h]][o]+c[i];
				if (!b[a[i]]) q[++t]=a[i],b[a[i]]=1;
			}
		}
}
main(){
	scanf("%lld%lld%lld%lld%lld",&n,&m,&L,&s,&e);
	for (int i=1;i<=m;++i) scanf("%lld%lld%lld",&x,&y,&z),add(x,y,z),add(y,x,z);
	spfa(e,0);spfa(s,1);
	if (f[e][1]!=L) return puts("NO"),0;puts("YES");
	for (int i=3;i<=tot;++i) if (i&1) printf("%lld %lld %lld\n",a[i],a[i^1],c[i]);
	return 0;
}
```
*****
## E
### Problem description
> 给出一颗带边权的无根树，询问有多少点对之间唯一的通路上的边权所组成的数（合并写在一起）为p的倍数。

### Solution
> 考虑树分治，那么问题就在于如何计算有多少经过x点的路径组成的数为M的倍数。记d1表示每个点到x的路径组成的数，用map存，则当扫到深度为deep的点d2表示x到该点组成的数时，满足条件的d1有(d1*(10^deep)+d2)%p=0。
> 即d1=d2/(10^deep)。求逆元即可。

### Code
```cpp
#include<iostream>
#include<cstdio>
#include<map>
using namespace std;
#define int long long
const int N=1e5+10;
int n,m,p,x,y,z,tot=1,_temp,ans,fi[N],ne[N<<1],va[N<<1],ar[N<<1],inv[N],root,rmn,si[N];
map<int,int> mp;
inline void extgcd(int x,int y,int &a,int &b){
    if (!y) {a=1;b=0;return;}
	extgcd(y,x%y,b,a);
	b-=x/y*a;
}
inline int adde(int x,int y,int z){
	ar[++tot]=y;va[tot]=z;ne[tot]=fi[x];fi[x]=tot;
}
inline void get_size(int x,int fa){
	si[x]=1;
	for (int i=fi[x];i;i=ne[i]) if (ar[i]&&ar[i]!=fa) get_size(ar[i],x),si[x]+=si[ar[i]];
}
inline void get_root(int x,int fa,int susi){
	int mx=susi-si[x];
	for (int i=fi[x];i;i=ne[i]) if (ar[i]&&ar[i]!=fa) get_root(ar[i],x,susi),mx=max(mx,si[ar[i]]);
	if (mx<rmn) rmn=mx,root=x;
}
inline void get_d1(int x,int fa,int no,int qu){
	++mp[no];
	for (int i=fi[x];i;i=ne[i]) if (ar[i]&&ar[i]!=fa) get_d1(ar[i],x,(no+va[i]*qu)%p,qu*10%p);
}
inline int get_d2(int x,int fa,int no,int de){
	int sum=mp[(-no*inv[de]%p+p)%p];
	for (int i=fi[x];i;i=ne[i]) if (ar[i]&&ar[i]!=fa) sum+=get_d2(ar[i],x,(no*10+va[i])%p,de+1);
	return sum;
}
inline int cal(int x,int v){
	mp.clear();
	get_d1(x,0,v%p,v?10:1);
	return get_d2(x,0,v%p,v?2:1)-(v==0);
}
inline void solve(int x){
	get_size(x,0);rmn=1e9;get_root(x,0,si[x]);
	ans+=cal(root,0);
	for (int i=fi[root];i;i=ne[i]) if (ar[i]) ar[i^1]=0,ans-=cal(ar[i],va[i]),solve(ar[i]);
}
main(){
	scanf("%lld%lld",&n,&p);
	int _temp,inv10;
	extgcd(10,p,inv10,_temp);
	inv[1]=1;for (int i=2;i<=n;++i) inv[i]=(inv[i-1]*inv10)%p;
	for (int i=1;i<n;++i) scanf("%lld%lld%lld",&x,&y,&z),adde(x+1,y+1,z),adde(y+1,x+1,z);
	solve(1);
	printf("%lld",ans);
	return 0;
}
```
