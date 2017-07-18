# 比赛记录

[比赛链接](https://cn.vjudge.net/contest/168929)
## A
### Problem description
解b+k1a=d+k2c(k1>=0,k2>=0)
### Data Limit:1<=a,b,c,d<=100  Time Limit:1s
### Solution
暴力求解，每次选b和d之中较小的那个加上a或c。
```cpp
#include<cstdio>
bool vis[10001];
int main(){
  int a,b,c,d; scanf("%d%d%d%d",&a,&b,&c,&d);
  for(;b!=d;){
	if(vis[b-d+5000]){
	  printf("-1"); return 0;
	}
	vis[b-d+5000]=1;
	if(b<d) b+=a;else d+=c;
  }
  printf("%d",b); return 0;
}
```
## B
### Problem description
给你几个集合，如果存在一个集合中没有互为相反数的数，输出YES，否则输出NO。
### Data Limit:所有数的数量<=10000 Time Limit:2s
### Solution
都丢掉set里面暴力判断就行了。

```cpp
#include<cstdio>
#include<set>
using namespace std;
int main(){
  int n,m; scanf("%d%d",&n,&m); set<int> a;
  bool ans=0;
  for(int i=1;i<=m;++i){
	a.clear(); int k; scanf("%d",&k);
	bool ffind=0;
	for(int i=1;i<=k;++i){
	  int x; scanf("%d",&x);
	  if(a.count(-x)){
		ffind=1;
	  }
	  a.insert(x);
	}
	if(!ffind){
	  ans=1; break;
	}
  }
  if(ans) printf("YES"); else printf("NO"); return 0;
}
```
## C
### Problem description
有两个人玩游戏。1到n这些点按顺时针围成一个圈，每个人有几个数，每次行动可以选一个数，将一个东西顺时针走一个数步。两个人轮流行动，求这个东西一开始放在i的位置，第j个人先行动的胜负性。
### Data Limit:n<=7000 Time Limit:4s
### Solution
如果一个状态能走到必败状态，就是必胜状态。如果一个状态只能走到必胜状态，就是必败状态，其他都是平局。这样从每个确定的状态开始bfs一下就行了。
```cpp
#include<cstdio>
#include<queue>
using namespace std;
const int N=7000;
struct node{int p; bool d;};
int d[N+1][2],k[2],s[2][N+1],f[N+1][2];
int main(){
  int n; scanf("%d",&n);
  for(int i=0;i<=1;++i){
	scanf("%d",&k[i]);
	for(int j=1;j<=k[i];++j) scanf("%d",&s[i][j]);
  }
  for(int i=1;i<=n;++i) d[i][0]=k[0],d[i][1]=k[1];
  queue<node> Q; f[1][0]=f[1][1]=2;
  Q.push({1,0}); Q.push({1,1});
  for(;!Q.empty();Q.pop()){
	node x=Q.front(),y; y.d=x.d^1;
	for(int i=1;i<=k[y.d];++i){
	  y.p=x.p-s[y.d][i]; if(y.p<1) y.p+=n;
	  if(f[y.p][y.d]) continue;
	  if(f[x.p][x.d]==2){
		f[y.p][y.d]=1; Q.push(y);
	  }else{
		--d[y.p][y.d]; if(!d[y.p][y.d]){
		  f[y.p][y.d]=2; Q.push(y);
		}
	  }
	}
  }
  for(int i=0;i<=1;++i){
	for(int j=2;j<=n;++j) if(f[j][i]==0) printf("Loop ");
	  else if(f[j][i]==1) printf("Win "); else printf("Lose ");
	printf("\n");
  }
  return 0;
}
```
***** 
# 赛后补题
## D
### Problem description
给你一个有向图，可以给两个点连边，也可以给一个点的区间和一个点连边，求单源最短路。
### Data Limit:点数,连边数<=100000 Time Limit:2s
### Solution
建2棵线段树，第一棵从下往上连边，如果从区间到点连边，就把线段树中对应的节点向点连边。另一棵线段树从上往下连边，如果从点到区间连边，就把点和线段树中对应的区间连边。最后跑最短路就好了。
```cpp
#include<cstdio>
#include<queue>
#include<cstring>
using namespace std;
typedef long long ll;
const int N=100000;
struct edge{int to,len;}; vector<edge> G[N*5+1];
struct{int l,r,ls,rs;}a[N*5+1]; int cnt;
int n,m,s,rt1,rt2;
ll dis[N*5+1]; bool vis[N*5+1];
void build_down_tree(int &p,int l,int r){
  p=++cnt; a[p].l=l; a[p].r=r;
  if(l==r){
	G[p].push_back({l,0});
  }
  else{
	int mid=(l+r)/2;
	build_down_tree(a[p].ls,l,mid);
	build_down_tree(a[p].rs,mid+1,r);
	G[p].push_back({a[p].ls,0}); G[p].push_back({a[p].rs,0});
  }
}
void build_up_tree(int &p,int l,int r){
  p=++cnt; a[p].l=l; a[p].r=r;
  if(l==r){
	G[l].push_back({p,0});
  }
  else{
	int mid=(l+r)/2;
	build_up_tree(a[p].ls,l,mid);
	build_up_tree(a[p].rs,mid+1,r);
	G[a[p].ls].push_back({p,0}); G[a[p].rs].push_back({p,0});
  }
}
void add_edge_1(int l,int r,int len){
  G[l].push_back({r,len});
}
void add_edge_2(int p,int l,int r,int v,int len){
  if(a[p].l==l&&a[p].r==r){
	G[v].push_back({p,len}); return;
  }
  int mid=(a[p].l+a[p].r)/2;
  if(r<=mid) add_edge_2(a[p].ls,l,r,v,len);
  else if(l>mid) add_edge_2(a[p].rs,l,r,v,len);
  else add_edge_2(a[p].ls,l,mid,v,len),add_edge_2(a[p].rs,mid+1,r,v,len);
}
void add_edge_3(int p,int l,int r,int v,int len){
  if(a[p].l==l&&a[p].r==r){
	G[p].push_back({v,len}); return;
  }
  int mid=(a[p].l+a[p].r)/2;
  if(r<=mid) add_edge_3(a[p].ls,l,r,v,len);
  else if(l>mid) add_edge_3(a[p].rs,l,r,v,len);
  else add_edge_3(a[p].ls,l,mid,v,len),add_edge_3(a[p].rs,mid+1,r,v,len);
}
void spfa(int s){
  memset(dis,0x3f,sizeof dis); dis[s]=0; queue<int> Q;
  for(Q.push(s);!Q.empty();Q.pop()){
	int x=Q.front(); vis[x]=0;
	for(int i=0;i<G[x].size();++i){
	  edge e=G[x][i];
	  if(dis[x]+e.len<dis[e.to]){
		dis[e.to]=dis[x]+e.len;
		if(!vis[e.to]) vis[e.to]=1,Q.push(e.to);
	  }
	}
  }
}
int main(){
  scanf("%d%d%d",&n,&m,&s); cnt=n;
  build_down_tree(rt1,1,n); build_up_tree(rt2,1,n);
  for(int i=1;i<=m;++i){
	int p,x,y,z,l; scanf("%d%d%d%d",&p,&x,&y,&z);
	if(p==1) add_edge_1(x,y,z);
	else if(p==2){
	  scanf("%d",&l); add_edge_2(rt1,y,z,x,l);
	}else if(p==3){
	  scanf("%d",&l); add_edge_3(rt2,y,z,x,l);
	}
  }
  spfa(s);
  for(int i=1;i<=n;++i) printf("%lld ",dis[i]==dis[0]?-1:dis[i]); return 0;
}
```
## E
### Problem description
给你一个长为n的数列。f(k)表示把数列划分成一些区间，每个区间的不同数字个数不能超过k的情况下，区间数量的最大值。求f(1)到f(n)所有数。
### Data Limit:n,k<=100000 Time Limit:2s
### Solution
显然答案是一个递减数列。我们可以用一个玄学的方法，先二分，对于每一个区间[l,r],若f[l]=f[r]，则l到r所有数都相等，可以直接退出。否则二分求解。
```cpp
#include<cstdio>
#include<cstring>
const int N=100000;
int val[N+1],cnt,a[N+1],ans[N+1],n;
void insert(int x){
  if(++val[x]==1) ++cnt;
}
void erase(int x){
  if(--val[x]==0) --cnt;
}
int count(int x){
  memset(val,0,sizeof val); cnt=0; int L=1,ans=0;
  for(int i=1;i<=n;++i){
	insert(a[i]);
	if(cnt>x){
	  for(int j=L;j<i;++j) erase(a[j]);
	  L=i; ++ans;
	}
   }
  return ans+1;
}
void getans(int l,int r){
  if(l>r) return; ans[l]=count(l);
  ans[r]=count(r);
  if(ans[l]==ans[r]){
	for(int i=l+1;i<=r-1;++i) ans[i]=ans[l];
	return;
  }
  int mid=(l+r)/2;
  getans(l+1,mid); getans(mid+1,r-1);
}
int main(){
  scanf("%d",&n);
  for(int i=1;i<=n;++i) scanf("%d",&a[i]);
  getans(1,n);
  for(int i=1;i<=n;++i) printf("%d ",ans[i]);
  return 0;
}
```
