

[Contest 15-比赛链接](https://cn.vjudge.net/contest/168929)

# 比赛中解决的问题
## A The Monster
### Problem description
> 给出两个数列：b, b + a, b + 2a, b + 3a, ...和d, d + c, d + 2c, d + 3c, ....。要求求出他们的最小公共项。

### Data Limit：a,b,c,d <= 100  Time Limit: 1s
### Solution
> + 法1 暴力解决
> 
> 枚举一定范围内其中一个数列的所有值，存到set中；再求出另一个数列中是否存在相同的数。
> 
> + 法2 扩展欧几里得
> 
> **exgcd:**
> 
> 已知方程*ax+by=1*,若gcd(a,b)=1,则原方程可写成
> *ax+by=gcd(a,b)*.
> 
> 设 *bx'+(a%b)y'=gcd(b,a%b)*（由辗转相除法得)

> 因为 *a%b=a-[a/b]\*b* (`[]`为取整符号）

> 则 *bx'+(a-[a/b]\*b)y'=gcd(b,a%b)*

> 即 *ay'+b(x'-[a/b]\*b)=gcd(b,a%b)=gcd(a,b)=ax*by*

> 所以 x=y',y=x'-[a/b]\*b

> **回到原题**

> 本题相当于求 *ax+b=cy+d* x,y的自然数解。
> 即*ax+(-c)y=d-b*.
> 设gcd(a,-c)=g
> 所以可以求出(a/g)x+(-c/g)y=1的解，再扩大(d-b)/g倍（若(d-b)/g不为整数，则无解），再调整解，使其为最小整数解。 

### Code
```cpp
#include<cstdio>
#include<iostream>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;

int exgcd(int a,int b,int &x,int &y){
	int d=a;
	if (b!=0){
		d=exgcd(b,a%b,x,y);
		x-=(int(a/b))*y;
		swap(x,y);
	}else{
		x=a*1;y=0;
	}
	return d;
}
int gcd(int a,int b){
	return b==0?a:gcd(b,a%b);
}
int main(){
	int a,b,c,d;
	scanf("%d%d%d%d",&a,&b,&c,&d);
	int x,y;
	if (b==d) {
		printf("%d",b);
		return 0;
	}
	int k=gcd(a,c);
	int g=d-b;
	int A=a,C=c;
	if (g%k==0){
		A/=k;C/=k;g/=k;
	}
	if ((abs(exgcd(A,-C,x,y)))==1){
		//printf("%d  %d  ",x,y);
		x*=g;y*=g;
		while (x<0||y<0){
			x+=C;y+=A;
		}
		while (x-C>=0&&y-A>=0){
			x-=C;y-=A;
		}
		//printf("%d  %d  ",x,y);
		printf("%d",b+a*x);
	}else printf("-1");  
}
```
*****


## B
### Problem description
> 给出m个大小为k，数字可以重复的序列，每个数字的绝对值在[1..n]之间，问是否存在一个序列，不存在一对相反数。

### Data Limit：n,m,∑k <= 1e4  Time Limit: 2s
### Solution
> 只需要扫描每个序列，用set/map/bool数组 记录每一个数的出现情况，读入一个数时判断它的相反数是否存在即可。

> **但是**，在扫描到存在相反数时，**不能够直接break**，否则会将没读进的数误认为是下一个序列的数。（居然样例不存在这个bug。。。）

### Code
```cpp
#include<cstdio>
#include<iostream>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;

bool A[10005];
bool B[10005];
int main(){
	int n,m;
	scanf("%d%d",&n,&m);
	for (int i=1;i<=m;i++){
		int k;
		memset(A,0,sizeof A);
		memset(B,0,sizeof B);
		scanf("%d",&k);
		bool flag=1;
		for (int j=1;j<=k;j++){
			int a;
			scanf("%d",&a);
			//if (!flag) continue;
			if ((a<0&&B[-a])||(a>0&&A[a])) {
				flag=0;
			}
			if (a<0)A[-a]=1;else B[a]=1;
		}
		if (flag) {
			printf("YES");
			return 0;
		}
	}
	printf("NO");
}
```
*****

# 赛后补题

## C
### Problem description
> 有一个游戏，棋盘是在圆上顺时针排列的[1..n]数。其中1号位置为“黑洞”，将“怪物”移动到1号位置的人获胜。
> A、B两人手上分别有k1，k2个[1..n-1]的数，数k可以将"怪物"顺时针移动k位。
> 要求分别求出A、B先开始游戏，“怪物”在[2..n-1]的初始位置，先手必胜(Win)、必败(Lose)，或游戏可以无限进行下去(Loop)。

### Data Limit：n <= 7000  Time Limit: 4s

### Solution
> 如果正向搜索，会因为Loop死循环处理变得较为困难（但也可以做）。

> 考虑反向搜索(dp)，设f(i,j)为玩家i(i=0,1)，当前位置为j时的获胜可能(1=必胜，0=必败）

> 初始结点f(0,1)=f(1,1)=0（因为是另一个人将它移到1号位置的）

> 对于任意已求出解的结点f(i,j)

> + 若f(i,j)=0,扩展前一次操作f(i^1,k)，因为只需将棋子移到j点就可以保证对手必败，所以自己必胜，f(i^1,k)=1;
> + 若f(i,j)=1,扩展前一次操作f(i^1,k),则说明这一种操作会使自己败，可以维护一个计数器`lose[i^1][k]`，统计会让自己败的操作数，若`lose[i^1][k]`等于所有操作数总和，说明无论什么操作都会使自己败，则f(i^1,k)=0;

> 另外，维护一个visit数组，记录某个结点是否被扩展过，如果没有，说明它既不能达到必胜，也不能达到必败，则一定是死循环。

### Code
```cpp
#include<cstdio>
#include<iostream>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;

bool visit[2][7001];
bool win[2][7001];
int lost[2][7001];
int S[2][7001],k[2];
int n;
const char *ans[]={"Lose ","Win "};
void f(int q,int x){
	visit[q][x]=1;
	for (int i=1;i<=k[q^1];i++){
		int tmp=(x+n-S[q^1][i]-1)%n+1;
		if (tmp==1) continue;
		if (visit[q^1][tmp]) continue;
		if (x==0||!win[q][x]) {
			win[q^1][tmp]=1;
			f(q^1,tmp);
		}else{
			if (++lost[q^1][tmp]==k[q^1]){
				win[q^1][tmp]=0;
				f(q^1,tmp);	
			}
			
		}
	}
}
int main(){
	scanf("%d",&n);
	for (int i=0;i<=1;i++){
		scanf("%d",&k[i]);
		for (int j=1;j<=k[i];j++) scanf("%d",&S[i][j]);
	}
	f(1,1);f(0,1);
	for (int i=0;i<=1;i++){
		for (int j=2;j<=n;j++){
			if (!visit[i][j]) printf("Loop ");
			else printf("%s",ans[win[i][j]]);
		}
		printf("\n");
	}
}
```
*****


## D
### Problem description
> 有n个结点，q个操作，这q个操作属于以下3种操作的一种：
> 
> 1. 从v向u连一条权为w的边
> 2. 从v到[l..r]范围内所有点连一条权为w的边
> 3. 从[l..r]范围内所有点向v连一条权为w的边

> 求出从s点到所有点(包括自己)的最短路。

### Data Limit：n,q <= 1e5  Time Limit: 2s
### Solution
> 维护两棵线段树（共用叶结点），其中一棵从父结点向子结点连权为0的边，记为T1。
> 另一棵从子结点向父结点连权为0的边，记为T2。
> 
> 对于1操作，只需要在对应的叶结点连边。
> 
> 对于2操作，只需要从叶结点v向T1中的区间[l,r]连w的边，则v经由T1到[l..r]各点的权值和为w
> 
> 对于3操作，类似于2，只需要从T2中的区间[l..r]向v连w的边。

> 最后跑一遍最短路即可。

### Code
```cpp
#include <cstdio>
#include <iostream>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <queue>
#include <utility>
#include <vector>
#define mp(a,b) make_pair(a,b)
#define ll long long
using namespace std;
const long long inf=4611686018427387903;
typedef pair<ll,int> pir;

struct edge{
	int v,next;
	ll w;
}map[3000000];
int head[500000],m_tail=0;
void add(int u,int v,ll w){
	map[++m_tail].v=v;map[m_tail].w=w;map[m_tail].next=head[u];head[u]=m_tail;
}
struct node{
	int l,r,Lson,Rson;
	node(int l=0,int r=0,int ls=0,int rs=0){
		this->l=l;this->r=r;this->Lson=ls;this->Rson=rs;
	}
}point[500000];
int rootA,rootB,p_tail=0;
int pos[100001];
void make(int l,int r,int father){
	if (l==r) {
		pos[l]=father;
		return;
	}
	int mid=(l+r)/2;
	point[++p_tail]=node(l,mid);point[father].Lson=p_tail;
	add(father,p_tail,0);
	make(l,mid,p_tail);
	point[++p_tail]=node(mid+1,r);point[father].Rson=p_tail;
	add(father,p_tail,0);
	make(mid+1,r,p_tail);
}
void make_rev(int l,int r,int father){
	int mid=(l+r)/2;
	if (l!=mid){
		point[++p_tail]=node(l,mid);point[father].Lson=p_tail;
		add(p_tail,father,0);
		make_rev(l,mid,p_tail);
	}else{
		add(pos[l],father,0);
		point[father].Lson=pos[l];
	}
	if (mid+1!=r){
		point[++p_tail]=node(mid+1,r);point[father].Rson=p_tail;
		add(p_tail,father,0);
		make_rev(mid+1,r,p_tail);
	}else{
		add(pos[r],father,0);
		point[father].Rson=pos[r];
	}

}
void insert(int l,int r,int idx,int v,ll w,int t){
	if (idx==0) return;
	int L=point[idx].l,R=point[idx].r;
	if (l==L&&r==R){
		if (t==2) add(pos[v],idx,w);
		if (t==3) add(idx,pos[v],w);
	}else{
		int mid=(L+R)/2;
		if (l<=mid){
			insert(l,min(mid,r),point[idx].Lson,v,w,t);
		}
		if (r>=mid+1){
			insert(max(mid+1,l),r,point[idx].Rson,v,w,t);
		}
	}
}
int m,n,q,s;
priority_queue <pir,vector<pir>,greater<pir> > Q;
ll dist[500000];
void print_tree(){
	for (int i=1;i<=p_tail;i++){
		printf("tree[%d]:l=%d,r=%d,Lson=%d,Rson=%d\n",i,point[i].l,point[i].r,point[i].Lson,point[i].Rson);
	}
} 
void print_map(){
	for (int i=1;i<=m_tail;i++){
		printf("map[%d]:v=%d,w=%d,next=%d\n",i,map[i].v,map[i].w,map[i].next);
	}
}
int main(){
	cin>>n>>q>>s;
	point[rootA=++p_tail]=node(1,n);
	make(1,n,p_tail);
	if (n!=1){
		point[rootB=++p_tail]=node(1,n);
		make_rev(1,n,p_tail);		
	}
	for (int i=1;i<=q;i++){
		int t;
		//scanf("%d",&t);
		cin>>t;
		if (t==1){
			int u,v,w;
			cin>>v>>u>>w;
			add(pos[v],pos[u],w);
		}else{
			int v,l,r,w;
			cin>>v>>l>>r>>w;
			if (t==2) insert(l,r,rootA,v,w,t);
			if (t==3) insert(l,r,rootB,v,w,t);
		}
	}
	for (int i=1;i<500000;i++) dist[i]=inf;
	dist[pos[s]]=0;
	Q.push(mp(0,pos[s]));
	while(!Q.empty()){
		pir x=Q.top();Q.pop();
		if (x.first!=dist[x.second]) continue;
		for (int i=head[x.second];i;i=map[i].next){
			int to=map[i].v,w=map[i].w;
			if (x.first+w<dist[to]){
				dist[to]=x.first+w;
				Q.push(mp(dist[to],to));
			}
		}
	}
	for (int i=1;i<=n;i++){
		cout<<((dist[pos[i]]>=inf)?-1:dist[pos[i]])<<" ";
	}
	return 0;
}
```
*****

## E
### Problem description
> 

### Data Limit：n <= 1e5  Time Limit: 1s

### Solution
> 

### Code
```cpp
```