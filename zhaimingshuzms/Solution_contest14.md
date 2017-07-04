[比赛链接](https://www.codeforces/contest/787.com)

# 比赛中解决的问题
## A
### Problem description
> 给定四个数a，b，c，d，求最小的i，j，使a*i+b=c*j+d；

### Data Limit：(1 ≤ a, b ≤ 100)，(1 ≤ c, d ≤ 100)；  Time Limit: 1s

### Solution
> 先开一个bool数组标记i从0至10000的a*i+b,再将j从0至10000扫，找到最小的符合的值跳出c*j+d即为答案，如果扫变了找不到答案输出-1；

### Code
```cpp
#include<cstdio>
using namespace std;
bool bb[1500010];
int main(){
	int a,b,c,d;
	scanf("%d%d",&a,&b);
	scanf("%d%d",&c,&d);
	for (int i=0; i<=10000; i++) bb[b+i*a]=1;
	for (int i=0; i<=10000; i++) if (bb[d+i*c]) {printf("%d",d+i*c); return 0;}
	printf("-1");
	return 0;
}
```
*****


## B
### Problem description
> 给定m组范围在n之内的数，每组大小为k，若有一组中无互为相反数的两个数，则为YES，否则为NO；

### Data Limit：(1 ≤ n, m ≤ 10^4) Sum of k for all groups does not exceed 10^4. Time Limit: 2s
### Solution
> 按照题意暴力

### Code
```cpp
#include<bits/stdc++.h>
using namespace std;
const int L=10000;
bool b[2*L+1];
int a[L+1];
int main(){
	int n,m;
	scanf("%d%d",&n,&m);
	bool t=0;
	for (int i=1; i<=m; i++){
		int k;
		scanf("%d",&k);
		memset(b,0,sizeof(b));
		for (int i=1; i<=k; i++) scanf("%d",&a[i]),b[L+a[i]]=1;
		bool flag=0;
		for (int i=1; i<=k; i++){
			//printf("%d %d\n",L-a[i],b[L-a[i]]);
			if (b[L-a[i]]) flag=1;
		}
		if (!flag) t=1;
	}
	if (t) printf("YES"); else printf("NO");
	return 0;
}
```
*****

## C
### Problem description
> 有一个有n个元素的环，1为黑洞，给定两个集合a，b，玩家一只能按a中的数顺时针移动怪物，同理玩家二只能按b，将怪物移动到黑洞则胜利，对于每个怪物位置和先手情况，输出游戏结果

### Data Limit：(2 ≤ n ≤ 7000)1 ≤ ki ≤ n - 1 and 1 ≤ si, 1, si, 2, ..., si, ki ≤ n - 1 for 1 ≤ i ≤ 2.  Time Limit: 4s

### Solution
> 记忆化搜索，按dfs顺序递推，对手有可能输则为赢，对手全赢则为输，否则为循环。

### Code
```cpp
#include<cstdio>
#include<algorithm>
using namespace std;
const int Win=3,Loop=2,Lose=1,N=7001;
int n,k[3],a[3][N],f[3][N],sum[3][N];
bool b[3][N];
void dfs(int x,int y){
	//printf("%d %d\n",x,y);
	if (b[x][y]) return;
	b[x][y]=1;
	int pre=3-x;
	for (int i=1; i<=k[pre]; i++){
		int nxt=y-a[pre][i];
		if (nxt<=0) nxt+=n;
		if (nxt==1) continue;
		f[pre][nxt]=max(f[pre][nxt],4-f[x][y]);
		//printf("%d %d %d\n",pre,nxt,f[pre][nxt]);
		if (++sum[pre][nxt]==k[pre]||f[pre][nxt]==Win) dfs(pre,nxt);
	}
}
int main(){
	scanf("%d",&n);
	scanf("%d",&k[1]);
	for (int i=1; i<=k[1]; i++) scanf("%d",&a[1][i]);
	scanf("%d",&k[2]);
	for (int i=1; i<=k[2]; i++) scanf("%d",&a[2][i]);
	f[1][1]=f[2][1]=Lose;
	dfs(1,1);
	dfs(2,1);
	for (int i=1; i<=2; i++){
		for (int j=2; j<=n; j++){
			if (!b[i][j]) f[i][j]=Loop;
			printf(f[i][j]==Win?"Win ":f[i][j]==Loop?"Loop ":"Lose ");
		}
		printf("\n");
	}
	return 0;
}
```
*****

# 赛后补题

## D
### Problem description
> 从n出发，给出点到范围，范围到点，点到点的距离，求单源最短路径

### Data Limit：(1 ≤ n, q ≤ 105, 1 ≤ s ≤ n)(1 ≤ v, u ≤ n, 1 ≤ w ≤ 109)(1 ≤ v ≤ n, 1 ≤ l ≤ r ≤ n, 1 ≤ w ≤ 109)  Time Limit: 2s
### Solution
> 两棵线段树，一棵从区间连向点，一棵从点联向区间，边权为0，再在线段树的节点中连边，跑最短路

### Code
```cpp
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=100001,INF=1e15;
struct Node{
	ll l,r;
}st[N*50];
ll b[N*50],c[N*50],ne[N*50],fi[N*6],k,tot,a[N],l,r,x,y,w,n,q,s,root[3],f,ff[N*50];
bool g[N*10];
void add(ll x,ll y,ll z){
	b[++k]=y; c[k]=z; ne[k]=fi[x]; fi[x]=k;
}
ll build(ll be,ll en){
	ll ind=++tot;
	if (be==en) return a[be]=ind;
	ll mid=(be+en)>>1;
	st[ind].l=build(be,mid);
	st[ind].r=build(mid+1,en);
	add(ind,st[ind].l,0);
	add(ind,st[ind].r,0);
	return ind;
}
ll build2(ll be,ll en){
	ll ind=++tot;
	if (be==en) return a[be];
	ll mid=(be+en)>>1;
	st[ind].l=build2(be,mid);
	st[ind].r=build2(mid+1,en);
	add(st[ind].l,ind,0);
	add(st[ind].r,ind,0);
	return ind;
}
void updata(ll ind,ll be,ll en){
	if (l<=be&&en<=r) {add(x,ind,w); return;}
	ll mid=(be+en)>>1;
	if (l<=mid) updata(st[ind].l,be,mid);
	if (r>=mid+1) updata(st[ind].r,mid+1,en);
}
void updata2(ll ind,ll be,ll en){
	if (l<=be&&en<=r) {add(ind,x,w); return;}
	ll mid=(be+en)>>1;
	if (l<=mid) updata2(st[ind].l,be,mid);
	if (r>=mid+1) updata2(st[ind].r,mid+1,en);
}
void spfa(){
	for (ll i=1; i<=tot; i++) ff[i]=INF;
	ff[a[s]]=0;
	queue<ll>q;
	q.push(a[s]);
	while (!q.empty()){
		x=q.front(); q.pop(); g[x]=0;
		for (ll j=fi[x]; j; j=ne[j])
		if (ff[b[j]]>ff[x]+c[j]){
			ff[b[j]]=ff[x]+c[j];
			if (!g[x]) q.push(b[j]),g[b[j]]=1;
		}
	}
}
int main(){
	scanf("%lld%lld%lld",&n,&q,&s);
	root[1]=build(1,n);
	root[2]=build2(1,n);
	for (ll i=1; i<=q; i++){
		scanf("%lld",&f);
		switch (f){
			case 1:{
				scanf("%lld%lld%lld",&x,&y,&w);
				add(a[x],a[y],w);
				break;
			}
			case 2:{
				scanf("%lld%lld%lld%lld",&x,&l,&r,&w);
				x=a[x];
				updata(root[1],1,n);
				break;
			}
			case 3:{
				scanf("%lld%lld%lld%lld",&x,&l,&r,&w);
				x=a[x];
				updata2(root[2],1,n);
				break;
			}
		}
		printf("\n");
	}
	spfa();
	for (ll i=1; i<=n; i++) printf("%lld ",ff[a[i]]==INF?-1:ff[a[i]]);
	return 0;
}
```
*****

## E
### Problem description
> 给定一个序列，求每段最多为k时，最少分为几段，k从1-n；

### Data Limit：(1 ≤ n ≤ 105)(1 ≤ ai ≤ n) Time Limit: 2s

### Solution
> 主席树维护一个区间有几种不同的颜色，对于每个klogn跳；

### Code
```cpp
#include<cstdio>
using namespace std;
const int N=100001;
struct Tnode{
	int l,r,sum;
}st[N*40];
int root[N],rec[N],tot,n,a[N];
int update(int pos,int r1,int be,int en,int v){
	int ind=++tot;
	st[ind]=st[r1];
	st[ind].sum+=v;
	if (be==en) return ind;
	int mid=(be+en)>>1;
	if (pos<=mid) st[ind].l=update(pos,st[ind].l,be,mid,v);
	else st[ind].r=update(pos,st[ind].r,mid+1,en,v);
	return ind;
}
int query(int ind,int be,int en,int k){
	if (be==en) return be;
	int mid=(be+en)>>1;
	if (st[st[ind].l].sum>=k) return query(st[ind].l,be,mid,k);
	else return query(st[ind].r,mid+1,en,k-st[st[ind].l].sum);
}
int main(){
	scanf("%d",&n);
	for (int i=1; i<=n; i++) scanf("%d",&a[i]);
	for (int i=n; i>=1; i--){
		int tmp=root[i+1];
		if (rec[a[i]]) tmp=update(rec[a[i]],tmp,1,n,-1);
		root[i]=update(i,tmp,1,n,1);
		rec[a[i]]=i;
	}
	for (int i=1; i<=n; i++){
		int t,now=1,ans=1;
		while (st[root[now]].sum>i){
			now=query(root[now],1,n,i+1);
			ans++;
		}
		printf("%d ",ans);
	}
	return 0;
}
```
