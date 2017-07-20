[比赛链接](https://vjudge.net/contest/168929)

[Origin](http://codeforces.com/contest/787)

# 比赛中解决的问题
## A
### Problem description
给出两个数列：b, b + a, b + 2a, b + 3a, ...和d, d + c, d + 2c, d + 3c, ....。要求求出他们的最小公共项。
### Data Limit：1<=A,B,C,D<=100 Time Limit: 1s
### Solution
题意即是求b+xa=d+yc的最小碰撞正整数.我们将问题转化为ax-cy=d-b=k\*gcd(a,c) k为正整数，否则无解。

根据gcd可知，`|x|<=K*max(|a|,|c|)`,而这题a,b,c,d的范围都很小所以可以用暴力法.

+ 法一：暴力枚举，用一个布尔数组记录一下就好了。
+ 法二：**exgcd**\
已知方程ax+by=1,若gcd(a,b)=1,则原方程可写成\
 *ax+by=gcd(a,b)*.\
 而 gcd(a,b)=gcd(b,a mod b)\
 所以 ax+by=gcd(a,b)=gcd(b,a mod b)=bx'+(a mod b)y'\
 即 ax+by=bx'+(a mod b)y'=bx'+(a-[a/b]\*b)y'\
 移项得 ax+by=ay'+b(x'-[a/b]\*b)\
 根据恒等定理有 x=y',y=x'-[a/b]\*b\
 由于欧几里德算法最后一步为gcd(d,0)=d,此时对应的等式的解为x=1,y=0,因此只要如上述代码,从gcd(d,0)往前处理,在进行欧几里德算法的递归的时候根据相邻两次调用间x,y和x’,y’的关系计算即可求出ax+by=gcd(a,b)的解.\
 **回到原题**\
 本题相当于求 *ax+b=cy+d* x,y的自然数解。\
 即*ax+(-c)y=d-b*.\
 设gcd(a,-c)=g\
 所以可以求出ax-cy=g的解，再扩大(d-b)/g倍（若(d-b)/g不为整数，则无解），再调整解，使其为最小整数解。 \
 实际上在之前的计算和证明中我们得到的只是不定方程的一组解,那么怎样得到所有解呢?\
 对于一般形式ax+by=g有通解(x,y),则x′=x+b/g,y′=y−a/g.(证明略,只要代入一下就知道为什么通解是这个了)
### Code
```cpp
方法一：
bool map[500000];
int main()
{
	int a,b,c,d,t1,t2;
	scanf("%d%d",&a,&b);
	scanf("%d%d",&c,&d);
	for (int i=0; i<=1000; i++) map[b+i*a] = true;
	for (int i=0; i<=1000; i++) if (map[d+c*i]) {printf("%d",d+c*i); return 0;}
	printf("-1");
	return 0;
}

方法二：
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
给你n个人，m个组，判断每个组中是否含有一对相反数，如果任意一组中一个都没有就输出YES，否则输出NO

### Data Limit：fabs(n），fabs(m) <= 1e4  Time Limit: 2s
### Solution
只需要扫描每个序列，用set/map/bool数组 记录每一个数的出现情况，读入一个数时判断它的相反数是否存在即可。

但是，在扫描到存在相反数时，不能够直接break，否则会将没读进的数误认为是下一个序列的数。（注意把没用的数据从输入流里读取掉）
### Code
```cpp
#include<map>
#include<iostream>
#include<map>
using namespace std;
int q,w,l,e,o=1,c=1;
map<int, int> mt;
int main()
{
    for(cin>>q>>w; c<=w && o; c++)
        for(o=0,cin>>l; l--; o|=(mt[-e]==c),mt[e]=c) cin>>e;
    cout<<(o?"NO":"YES");
}
```
*****

## C
### Problem description
有n个位置1,2,3……n，围成1个圈，某个物体最开始的位置不在1，两个人轮流操作，每个人操作时可以让这个物体顺时针运动一些位置，使物体最终到达1号位置的人胜。

求：物体初始在每个位置（不包括1），两个人分别先手的胜负情况。
### Data Limit：n <=7000 Time Limit: 4s

### Solution
> 每个人每个状态无非就是三种情况：必胜（Win），必败（Lose），无法到达（Loop）。这其实是博弈论。</P>
  由于必败状态必定由所有必胜状态可推得，必胜状态只要1个必败状态就可以推出，那我们可以通过BFS/DFS的方式实现。</P>
  设状态(x,y)表示当前是编号为y的人操作，物体位置在x。那么(1,0)和(1,1)必然是必败状态。</P>
  我们可以先由着必败状态（1,0）和（1,1）来推出第一波必胜状态，开始DFS。</P>
  考虑一个状态（X,Y），如果这个状态可以转移到的所有状态对于!Y都是必胜状态，那么很明显，这个状态（x,y）对于y来说是没有活路的，是必败的</P>
  因为必胜状态的推出要依赖于必败状态，所以我们有必要找到高效地从必胜状态转移出必败状态的方法。</P>
  由上面我们考虑过的必败状态的得出方法有点慢，所以我们要换个方向看。</P>
  对于一个必胜的状态，我们可以把所有可以一步到这个必胜状态的状态的计数器+1，当一个状态的计数器到达了tot[y]时（tot[y]表示Y这个人的集合里的数字数目）</P>
  就说明这个状态可以到达的所有状态都是对手必胜，那么我们就知道这个状态是必败状态了。把这个状态可以到达的必胜状态进行新的一轮DFS就可以了。</P>
### Code
```cpp
#include<bits/stdc++.h>
using namespace std;
int n,k[2],v[2][7003];
int dp[2][7003],cnt[2][7005];
void f(int x,int j)
{
	if (dp[j][x]) return;
	dp[j][x] = 2;
	if (!x) return;
	for (int i=0; i<k[!j]; i++) 
	{
		cnt[!j][(x-v[!j][i]+n)%n]++; 
		if (cnt[!j][(x-v[!j][i]+n)% n]==k[!j]) 
		{
			dp[!j][(x-v[!j][i]+n)%n] = 1;
			int s=(x-v[!j][i]+n)%n;
			for (int l=0; l<k[j]; l++)  f((s-v[j][l]+n)%n,j);
		}
	}
}
int main()
{
	scanf("%d",&n);
	scanf("%d",&k[0]); for (int i=0; i<k[0]; i++) scanf("%d",&v[0][i]);
	scanf("%d",&k[1]); for (int i=0; i<k[1]; i++) scanf("%d",&v[1][i]);
	for (int j=0; j<2; j++) 
			for (int i=0; i<k[j]; i++) f(n-v[j][i],j);
	for (int j=0; j<2; j++)
	{
			for (int i=1; i<n; i++) 
			printf("%s ",dp[j][i]==2?"Win":dp[j][i]==1?"Lose":"Loop");
			printf("\n");
	}
 } 
```
*****

## D
### Problem description
给你一个图，以及三种类型的边
1. 普通的u->v;   
2. u->range[l,r]中任意一点都可以
3. range[l,r]->u 

求出s到每个点的最短路
### Data Limit：n <= 1e5 ， s <=1e5 ， M<=1E5  Time Limit: 2s
### Solution
如果我们暴力建边，那么建边的过程中可能就超时了.

对于1操作，并无大碍；

对于2操作，考虑一种数据结构，使连边时可以直接连到某几个区间而不需要暴力连接每一个点。可以想到线段树是比较适合的。建树的时候从每个父节点到其子节点连一条权值为0的边。这样在处理加边操作时就可以直接连到覆盖的区间节点；

对于3操作，和2操作相同，需要另建一颗线段树，从子节点向父节点连边。 在两棵线段树中，对应叶子结点应该相连。1操作可以直接在这些叶子节点中连边。 

于是我们顺利地把边数变成了O(log(q))的级别

![](http://images2015.cnblogs.com/blog/1099411/201707/1099411-20170703181254628-1790707444.png)

最后跑一遍dijkstra出答案。

### Code
```cpp
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pii;
#define FILE "read"
#define MAXN (ll)2e6+10
struct node{ll y,next,v;}e[MAXN];
ll n,m,S,cnt,len,root[5],Link[MAXN],dis[MAXN],vis[MAXN],tr[MAXN][2];
priority_queue<pii,vector<pii >,greater<pii> > q;
inline ll read(){
	ll x=0,f=1;  char ch=getchar();
	while(!isdigit(ch))  {if(ch=='-')  f=-1;  ch=getchar();}
	while(isdigit(ch))  {x=x*10+ch-'0';  ch=getchar();}
	return x*f;
}
void insert(ll x,ll y,ll v){e[++len].next=Link[x];Link[x]=len;e[len].y=y;e[len].v=v;}
void build(ll &p,ll l,ll r,ll opt){
	if(l==r) {p=l; return;}
	p=++cnt;  ll mid=(l+r)>>1;
	build(tr[p][0],l,mid,opt);  build(tr[p][1],mid+1,r,opt);
	if(!opt) insert(p,tr[p][0],0),insert(p,tr[p][1],0);
	else insert(tr[p][0],p,0),insert(tr[p][1],p,0);
}
void updata(ll p,ll l,ll r,ll x,ll y,ll pos,ll v,ll opt){
	if(x>r||y<l)  return;
	if(x<=l&&y>=r){
		if(opt==2)  insert(pos,p,v);
		else insert(p,pos,v);
		return;
	}
	ll mid=(l+r)>>1;
	updata(tr[p][0],l,mid,x,y,pos,v,opt); 
	updata(tr[p][1],mid+1,r,x,y,pos,v,opt);
}
void dijkstra(){
	memset(dis,10,sizeof(dis));
	ll oo=dis[0];  dis[S]=0;
	q.push(make_pair(dis[S],S));
	while(!q.empty()){
		ll v=q.top().first,x=q.top().second; q.pop();
		if(v>dis[x])  continue;
		for(ll i=Link[x];i;i=e[i].next)if(dis[x]+e[i].v<dis[e[i].y]){
			dis[e[i].y]=dis[x]+e[i].v;
			q.push(make_pair(dis[e[i].y],e[i].y));
		}
	}
	for(ll i=1;i<=n;++i){
		if(dis[i]==oo)  printf("-1 ");
		else printf("%I64d ",dis[i]);
	}
}
int main(){
	n=cnt=read();  m=read();  S=read();
	build(root[1],1,n,0);  build(root[2],1,n,1);
	for(ll i=1;i<=m;++i){
		ll opt=read();
		if(opt==1)  {ll x=read(),y=read(),v=read();insert(x,y,v);}
		else  {ll x=read(),l=read(),r=read(),v=read();updata(root[opt-1],1,n,l,r,x,v,opt);}
	}
	dijkstra();
	return 0;
}
```
*****
## E TODO:
### Problem description
给你n个数，问在不破坏序列的情况下,最少能把这n个数分成几段，且每段中不同的个数小于等于k个，输出k从1到n的答案。
### Data Limit： 1<=n<=1e5  Time Limit: 2s
### Solution
#### 解法一:
首先考虑暴力的方法，每次询问k，暴力扫一遍区间，一直到一段连续的区间充满了k个不同的数后，又要加入一个新的数的时候，再划分出一个新的区间。

这样是O(n^2)的。

但是呢，答案相对于k来讲是有单调性的，而且在很多情况下，一段连续的k对应着同一个答案。

所以就可以二分了，对于l,r，如果k=l以及k=r时的答案相等，l<=k<=r的答案就都相等。
#### 解法二:
枚举 + 线段树
假设位置为0->n-1, 每个位置i保存一个i到n - 1的线段树,线段树的叶子表示某个位置是否有数,每个数只保存最左边的一个出现位置，每次查询从P位置往后找len个不同的数
的时候只需要在P->n的线段树上二分找最远的一个位置就好了。
由于对于某个len，答案是不超过n / len 的，所以总次数是n/1 + n/2 + .. n/n,这是个调和级数，总量为nlogn 所以如下的枚举Query次数最多只有nlogn次，复杂度为nlogn^2
### Code
#### 解法一:
```c++
inline int get(int x)
{
	memset(col,0,sizeof(col));
	int cnt=0,ans=1;
	for(int i=1;i<=n;i++)
	{
		if(col[a[i]]==ans) continue;
		cnt++;
		col[a[i]]=ans;
		if(cnt>x) {ans++;cnt=1;col[a[i]]=ans;}
	}
	return ans;
}

void solve(int l,int r)
{
	if(l>r) return ;
	ans[l]=get(l),ans[r]=get(r);
	if(ans[l]==ans[r])
	{
		for(int i=l+1;i<=r-1;i++)
			ans[i]=ans[l];
		return ; 
	}
	int mid=l+(r-l)/2;
	solve(l+1,mid),solve(mid,r-1);
	return ;
}
```
#### 解法二: 
```c++
	for (int len = 1; len <= n; len++) {
		int pos = 0, ret = 0;
		while(pos < n) {
			int next_pos = root[pos]->Query(len, 0, n - 1);
			ret ++;
			pos = next_pos + 1;
		}
	    printf("%d ", ret);
	}
```
```c++
#include <bits/stdc++.h>
using namespace std;
const int N = 100010;

struct Tree *C;
struct Tree {
	Tree *lc, *rc;
	int cnt;
	bool left_end;
	Tree(int l = 0, int r = 0): cnt(0),left_end(false) {
		if(l == r) {
			return ;
		}
		int m = l + r >> 1;
		lc = new (C++) Tree(l, m);
		rc = new (C++) Tree(m + 1, r);
	}
	Tree *Insert(int position, int value, int l, int r)  {
		Tree *ta = new (C++)Tree();
		ta->lc = lc;
		ta->rc = rc;
		ta->left_end = left_end;
		ta->cnt = cnt;
		
		if (l == r) {
			ta->cnt += value;
			if(ta->cnt == 1) {
				ta->left_end = true;
			} else {
				ta->left_end = false;
			}
			return ta;
		}
		int m = l + r >> 1;
		if (position <= m) {
			ta->lc = lc->Insert(position, value, l, m);
		} else {
			ta->rc = rc->Insert(position, value, m + 1, r);
		}
		ta->left_end = ta->lc->left_end;
		ta->cnt = ta->lc->cnt + ta->rc->cnt;
		return ta;
	}
	int Query(int k, int l, int r) {
		if (cnt <= k) {
			return r;
		}
		if (l == r) {
			return l;
		}
		int m = l + r >> 1;
		if (lc->cnt > k) {
			return lc->Query(k, l, m);
		} else if (lc->cnt == k){
			if (!rc->left_end) {
				return rc->Query(k - lc->cnt, m + 1, r);
			} else {
				return lc->Query(k, l, m);
			}
		} else {
			return rc->Query(k - lc->cnt, m + 1, r);
		}
	}
}pool[N * 40], *root[N];
int mp[N], ret[N], a[N];

int main () {
	C = pool;
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
	root[n] = new (C++)Tree(0, n - 1);
	memset (mp, -1, sizeof(mp));
	for (int i = n - 1; i >= 0; i--) {
		if (mp[a[i]] != -1) {
			root[i] = root[i + 1]->Insert(mp[a[i]], -1, 0, n - 1);
			root[i] = root[i]->Insert(i, 1, 0, n - 1);
		} else {
			root[i] = root[i + 1]->Insert(i, 1, 0, n - 1);
		}
		mp[a[i]] = i;
	}
	for (int len = 1; len <= n; len++) {
		int pos = 0, ret = 0;
		while(pos < n) {
			int next_pos = root[pos]->Query(len, 0, n - 1);
			ret ++;
			pos = next_pos + 1;
		}
	    printf("%d ", ret);
	}
	return 0;
}

```
