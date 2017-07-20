## 比赛征程
> * Y : solved in the contest
> * A : solved after contest
> * W : solving

  \# |  A  |  B  |  C  |  D  |  E  | F |
---|---|---|---|---|---|---|
| contest18 |A|Y|Y|A|Y|A|

[比赛链接](https://cn.vjudge.net/contest/172100)

## A
### Problem description
> 博弈题..给一个矩形..两人轮流放硬币(不能重叠)..不能操作的输..

### Data Limit：略  Time Limit: 略
### Solution
> 小学数学..先手只需在中心放一枚硬币后对称放就好了..

### Code
```cpp
#include<cstdio>
#include<iostream>
using namespace std;
int a,b,r;
int main(){
	scanf("%d%d%d",&a,&b,&r);
	if (min(a,b)<r*2){
		printf("Second");
	}else{
		printf("First");
	}
}
```
*****

## B
### Problem description
> 略

### Data Limit：略  Time Limit: 略
### Solution
> 略

### Code
```cpp
#include<cstdio>
#include<iostream>
using namespace std;
int n,m,a[2333],b[2333],f;
int main(){
	scanf("%d%d",&n,&m);
	for (int i=0;i<=n;i++){
		scanf("%d",&a[i]);
	}
	for (int i=0;i<=m;i++){
		scanf("%d",&b[i]);
	}
	
	if (n<m){
		printf("0/1");
		return 0;
	}
	
	if (n>m){
		if (a[0]*b[0]<0){
			printf("-");
		}
		printf("Infinity");
		return 0;
	}
	
	f=1;
	
	if (a[0]*b[0]<0){
		printf("-");
	}
	if (a[0]<0) a[0]*=-1;
	if (b[0]<0) b[0]*=-1;
	
	for (int i=1000;i>=2;i--){
		if (a[0]%i==0&&b[0]%i==0){
			a[0]/=i;
			b[0]/=i;
		}
	}
	printf("%d/%d",a[0],b[0]);
	return 0;
	if (b[0]!=1){
		
	}else{
		printf("%d",a[0]);
	}
}
```
*****
## C
### Problem description
> 略。。</br>

### Time Limit: 2s
### Solution
> 略。。</br>

### Code
```cpp
#include<cstdio>
#include<iostream>
#include<string>
#include<cstring>
using namespace std;
char s[5202333];
int l,las;

int main(){
	scanf("%s",s);
	l=strlen(s);
	las=0;
	for (int i='z';i>='a';i--){
		for (int j=las;j<l;j++){
			if (s[j]==(char)i){
				printf("%c",s[j]);
				las=j;
			}
		}
	}
}
```
*****
## D
### Problem description
> 给出一个矩型图(行数列数均在1500以内)。。</br>
  无限平铺。。</br>
  求是否可以走无限远。。</br>

### Time Limit: 2s
### Solution
> 暴力。。不想说什么,如果同一坐标能在不同地图上走到两次就是Yes。。</br>

### Code
```cpp
#include<cstdio>
#include<iostream>
#include<string>
#include<cstring>
#include<vector>
#include<queue>
#include<map>
using namespace std;
int n,m,f[1510][1510],used[1510][1510],stx,sty,flag=1,ux[1510][1510],uy[1510][1510];
int dx[4]={1,-1,0,0},dy[4]={0,0,1,-1};

int gc(){
	char c;
	while (1){
		c=getchar();
		if (c=='.') return 0;
		if (c=='#') return 1;
		if (c=='S') return 2;
	}
}

struct P{
	int x,y,xx,yy;
}U,V;
queue<P>q;
void bfs(){
	int t;
	used[stx][sty]=1;
	q.push((P){stx,sty,0,0});
	while (!q.empty()){
		U=q.front();q.pop();
		//printf("%d %d %d %d\n",U.x,U.y,U.xx,U.yy);
		for (int i=0;i<4;i++){
			V.x=U.x+dx[i];
			V.y=U.y+dy[i];
			V.xx=U.xx;
			V.yy=U.yy;
			if (V.x==0) {
				V.x=n;
				V.xx--;
			}
			if (V.x==n+1) {
				V.x=1;
				V.xx++;
			}
			if (V.y==0) {
				V.y=m;
				V.yy--;
			}
			if (V.y==m+1) {
				V.y=1;
				V.yy++;
			}
			if (f[V.x][V.y]) continue;
			if (used[V.x][V.y]){
				if (V.xx!=ux[V.x][V.y]||V.yy!=uy[V.x][V.y]){
					printf("Yes");
					flag=0;
					return;
				}
			}else{
				used[V.x][V.y]=1;
				ux[V.x][V.y]=V.xx;
				uy[V.x][V.y]=V.yy;
				q.push(V);
			}
		}	
	}
}

int main(){
	memset(f,0,sizeof(f));
	memset(used,0,sizeof(used));
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++){
		for (int j=1;j<=m;j++){
			f[i][j]=gc();
			if (f[i][j]==2){
				stx=i;
				sty=j;
				f[i][j]=0;
			}
		}
	}
	bfs();
	if (flag)
		printf("No");
	return 0;
}
```
*****
## E
### Problem description
> 平面直角坐标系上有n个点(n<=1500),且没有任意三点共线。。</br>
  要求n个点连不相交的边使得与一棵树同构..</br>
  输出平面直角坐标系中每个点对应的树上点。。</br>

### Time Limit: 2s
### Solution
> 分治。。</br>
  树上每个节点对应最低的点,剩下的按极角分给孩子。。</br>
  
### Code
```cpp
#include<cstdio>
#include<iostream>
#include<algorithm>
#include<vector>
#define xxx 1510
#define ll long long
#define db long double
using namespace std;
struct P{
	ll x,y,id;
}p[xxx];
vector<P>vec[xxx],vv[xxx];
int n;
struct R{
	int to,nex;
}r[23333];
int hea[xxx]={0},cnt=1,ans[xxx],sz[xxx],realans[xxx],xx[xxx],yy[xxx];

void A(int u,int v){
	r[++cnt]=(R){v,hea[u]};
	hea[u]=cnt;
	r[++cnt]=(R){u,hea[v]};
	hea[v]=cnt;
}

void dfs(int x,int fa){
	sz[x]=1;
	int y;
	for (int i=hea[x];i>0;i=r[i].nex){
		y=r[i].to;
		if (y==fa) continue;
		dfs(y,x);
		sz[x]+=sz[y];
	}
	return;
}

bool cmp(P p1,P p2){
	return p1.x*p2.y-p1.y*p2.x < 0;
}
bool high(P p1,P p2){
	return p1.y!=p2.y?p1.y<p2.y:p1.x<p2.x;
}

void doit(int x,int fa){
	sort(vv[x].begin(),vv[x].end(),high);
	ans[x]=vv[x][0].id;
	int vsz=vv[x].size()-1,tt,pos=-1,t;
	for (int i=1;i<=vsz;i++){
		vec[x].push_back(vv[x][i]);
	}
	for (int i=0;i<vsz;i++){
		vec[x][i].x-=xx[ans[x]];
		vec[x][i].y-=yy[ans[x]];
	}
	sort(vec[x].begin(),vec[x].end(),cmp);
	//printf("%d:(%d)\n",x,ans[x]);for (int i=0;i<vsz;i++){printf(" %lld %lld %lld\n",vec[x][i].id,vec[x][i].x,vec[x][i].y);}
	for (int i=hea[x];i>0;i=r[i].nex){
		tt=r[i].to;
		if (tt==fa) continue;
		for (int j=0;j<sz[tt];j++){
			t=vec[x][++pos].id;
			vv[tt].push_back((P){xx[t],yy[t],t});
			//printf("(%d)",pos);
		}
		doit(tt,x);
	}
}

int main(){
	scanf("%d",&n);
	int u,v;
	for (int i=1;i<n;i++){
		scanf("%d%d",&u,&v);
		A(u,v);
	}
	dfs(1,1);
	
	for (int i=1;i<=n;i++){
		cin>>p[i].x>>p[i].y;
		xx[i]=p[i].x;yy[i]=p[i].y;
		p[i].id=i;
	}
	
	for (int i=1;i<=n;i++){
		vv[1].push_back((P){p[i].x,p[i].y,p[i].id});
	}
	doit(1,1);
	
	for (int i=1;i<=n;i++){
		realans[ans[i]]=i;
	}
	for (int i=1;i<=n;i++){
		printf("%d ",realans[i]);
	}
}
```
*****
## F
### Problem description
> 带权无向图(|V|<=1e5,|E|<=1e5)中,有k(k<=n)个点上有传送门。。</br>
  一个传送门到达就打开,可以从一个传送门瞬移到另一个打开的传送门..</br>
  求打开所有传送门的最小时间。。</br>

### Time Limit: 2s
### Solution
> 题意约等于求k个点的最小生成树。。</br>
  利用m很小,所以只需将每条边的两端点分别延伸至最近的有传送门的点作为可能的树边(最多m条,显然克鲁斯卡尔)。。</br>
  
### Code
```cpp
#include<cstdio>
#include<iostream>
#include<queue>
#include<cstring>
#include<algorithm>
#define xxx 233520
#define ll long long
using namespace std;
ll n,m,g,st,ans,aim;
struct R{
	ll to,val,nex;
}r[xxx];
ll hea[xxx],cnt=1;
struct E{
	ll from,to,val;
}e[xxx];
bool bo[xxx];

void A(ll u,ll v,ll w){
	r[++cnt]=(R){v,w,hea[u]};
	hea[u]=cnt;
	r[++cnt]=(R){u,w,hea[v]};
	hea[v]=cnt;
}

struct P{
	ll p,d;
}U,V;
struct cmp{
	bool operator()(P &p1,P &p2){
		return p1.d>p2.d;
	}
};
priority_queue<P,vector<P>,cmp>q;

ll d[xxx],pre[xxx];
void doit(){
	while (!q.empty()){
		U=q.top();q.pop();
		if (U.d>d[U.p]) continue;
		for (int i=hea[U.p];i>0;i=r[i].nex){
			V.p=r[i].to;
			V.d=U.d+r[i].val;
			if (V.d<d[V.p]){
				d[V.p]=V.d;
				pre[V.p]=pre[U.p];
				q.push(V);
			}
		}
	}
}

bool cmp(E e1,E e2){
	return e1.val<e2.val;
}

int fa[xxx];
int GF(int x){
	return fa[x]==x ? x : fa[x]=GF(fa[x]);
}

int main(){
	scanf("%I64d%I64d",&n,&m);
	memset(hea,0,sizeof(hea));
	ll x,y,z;
	for (int i=1;i<=m;i++){
		scanf("%I64d%I64d%I64d",&x,&y,&z);
		e[i]=(E){x,y,z};
		A(x,y,z);
	}
	scanf("%I64d",&g);
	memset(d,38,sizeof(d));
	for (int i=1;i<=g;i++){
		scanf("%I64d",&x);
		bo[x]=1;
		d[x]=0;
		pre[x]=i;
		q.push((P){x,0});
	}
	
	doit();
	ans=d[1];
	
	for (int i=1;i<=m;i++){
		e[i].val+= d[e[i].from]+d[e[i].to];
		e[i].from= pre[e[i].from];
		e[i].to= pre[e[i].to];
	}
	
	sort(e+1,e+m+1,cmp);
	for (int i=1;i<=g;i++){
		fa[i]=i;
	}
	int f1,f2;
	for (int i=1;i<=m;i++){
		f1=GF(e[i].from);f2=GF(e[i].to);
		if (f1!=f2){
			ans+=e[i].val;
			fa[f1]=f2;
		}
	}
	
	cout<<ans;
}
```
*****
