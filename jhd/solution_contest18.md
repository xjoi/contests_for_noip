

[Contest 18-比赛链接](https://cn.vjudge.net/contest/172100)

# 比赛中解决的问题
## A - Plate Game
### Problem description
> 给出一个a*b的矩形桌子,两个人轮流在桌子上放盘子,盘子不能超出桌子,也不能互相重叠,问先放者还是后放者有必胜方案.

### Data Limit：1 ≤ a, b, r ≤ 100  Time Limit: 2s
### Solution
> 可以发现,只要先放者能够放下第一个盘子(放不下就是后放者胜),就可以把它放在矩形的中心.则后放者任意在一个地方放盘子,他就一定能找到一个与之关于矩形中心的点放盘子,也就是说,他一定有位置放,则他必胜.

### Code
```cpp
int main(){
	int a,b,r;
	scanf("%d%d%d",&a,&b,&r);
	if (a<2*r||b<2*r) printf("Second");
	else printf("First");
	
}
```
*****


## B - Limit
### Problem description
> 给出一个分式P/Q(P,Q为整式),求它的极限![img](https://odzkskevi.qnssl.com/0038b6af93be5c64cf0089a30fd80510?v=1500452280)

### Data Limit：P,Q最高次数 ≤ 100,- 100 ≤ 每一项系数 ≤ 100 ,且最高项系数不为零. Time Limit: 2s
### Solution
> 显然,当函数逼近无穷时,其增长速度仅与最高项有关.
> 考虑P,Q的次数
> 
> 1. P的次数>Q的次数.则显然会逼向无穷.正负性则由P,Q的最高项系数乘积正负性决定.
> 2. P的次数=Q的次数.此时等比增长,极限为`P的最高项系数/Q的最高项系数`.
> 3. P的次数<Q的次数,此时极限为0.

> (其实复杂度分析也是这样的,思考时可以用复杂度分析的思维考虑)
### Code
```cpp
int P[105],Q[105];
int gcd(int a,int b){
	return b?gcd(b,a%b):a;
}
int main(){
	int n,m;
	scanf("%d%d",&n,&m);
	for (int i=0;i<=n;i++) scanf("%d",&P[i]);
	for (int i=0;i<=m;i++) scanf("%d",&Q[i]);
	if (n>m){
		if (P[0]*Q[0]>0) printf("Infinity");
		if (P[0]*Q[0]<0) printf("-Infinity");
	}else if (n<m){
		printf("0/1");
	}else{
		int sgn=P[0]*Q[0];
		P[0]=abs(P[0]);Q[0]=abs(Q[0]);
		int d=gcd(P[0],Q[0]);
		if (sgn<0) printf("-");
		printf("%d/%d",P[0]/d,Q[0]/d);
	}
	
}
```
*****



## C - Lexicographically Maximum Subsequence
### Problem description
> 给出一个字符串,求出其字典序最大的子串.

### Data Limit：len(s) <= 1e5  Time Limit: 2s

### Solution
> 可以开一个类似于单调队列(?)的东西,每扫描到一个字母,将队尾比它小的弹出,并把它加入队列.最后输出整个队列.
> 
(或者从z到a枚举,输出从前一个字母最后一位后的该字母)
### Code
```cpp
char s[100001],s2[100001];
int cnt;
int main(){
	scanf("%s",s);
	int len=strlen(s);
	s2[cnt=1]=s[0];
	for (int i=1;i<len;i++){
		while(cnt>0&&s2[cnt]<s[i])cnt--;
		s2[++cnt]=s[i];
	}
	for (int i=1;i<=cnt;i++){
		printf("%c",s2[i]);
	}
}
```
*****

# 赛后补题
## D - Infinite Maze
### Problem description
> 给出一个n\*m的迷宫,每个点为可以行走的点(`.`)或不可行走的墙(`#`),将迷宫向上下左右复制无数份,使得点(x,y) 和(x%n,y%m)相同.给出出发点(`S`),问是否能够到达最远点.

### Data Limit：n <= 1e5  Time Limit: 2s
### Solution
> 如果在1个n\*m矩阵(或者1+4个n\*m矩阵甚至3*3个n\*m矩阵)上跑BFS,都有可能因为细节处理WA(或者MLE).

> 考虑对无数个n\*m矩阵建立坐标系(出发点所在矩阵记为(0,0)),并记录n\*m个点第一次在哪一个矩阵中被访问.BFS时记录现在的点在哪个矩阵中,如果相同的点在不同的矩阵中被访问2次,则存在通向无穷的远方的道路.只需要在出边界时修改矩阵的坐标即可.

### Code
```cpp
const int go[4][2]={{1,0},{-1,0},{0,1},{0,-1}};
bool map[1501][1501];
int visit[1501][1501][2];
char buff[1501];
struct sy{
	int x,y;
	int mx,my;
	sy(int x,int y,int mx,int my):x(x),y(y),mx(mx),my(my){}
};
queue <sy> Q;
int stx,sty;

int main(){ 
	int n,m;
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++){
		for (int j=1;j<=m;j++){
			visit[i][j][0]=visit[i][j][1]=inf;
		}
	}
	for (int i=1;i<=n;i++){
		scanf("%s",buff);
		for (int j=0;j<m;j++){
			if (buff[j]=='#') map[i][j+1]=0;
			else map[i][j+1]=1;
			if (buff[j]=='S') Q.push(sy(i,j+1,0,0)),visit[i][j+1][0]=0,visit[i][j+1][1]=0;
		}
	}
	while(!Q.empty()){
		sy a=Q.front();Q.pop();
		for (int i=0;i<4;i++){
			int x=a.x+go[i][0],y=a.y+go[i][1],ex=a.mx,ey=a.my;
			if (x==0) x=n,ex--;
			if (y==0) y=m,ey--;
			if (x>n)  x=1,ex++;
			if (y>m)  y=1,ey++;
			if (map[x][y]) {
				if (visit[x][y][0]==ex&&visit[x][y][1]==ey) continue;
				if (visit[x][y][0]!=inf){
					printf("Yes");return 0;
				}
				visit[x][y][0]=ex,visit[x][y][1]=ey;
				Q.push(sy(x,y,ex,ey));
			}
		}
	}
	printf("No");
}
```
*****

## E
### Problem description
> 给出一颗n个节点的树和平面上的n个点(没有三点共线),求一种将这n个点与树上n个顶点一一对应的方案,使得将各点按照树上的边相连后,各边不出现交叉.

### Data Limit：1 ≤ n ≤ 1500 ,- 10^9 ≤ xi, yi ≤ 10^9  Time Limit: 2s

### Solution
> 对于一颗子树,考虑极角排序,选择y坐标最小(若y坐标相同,则x坐标最小)的点,对应根节点,将其余点按极角排序,并按各子树大小分配数量,递归处理.

> (我在做的时候,先转成dfs序,再用dfs序处理序列的,效果其实一样)

### Code
```cpp
struct node{
	int v,next;
	node(int v,int next):v(v),next(next){}
	node(){}
}map[3001];
int head[1501],tail;
void insert(int u,int v){
	map[++tail]=node(v,head[u]);head[u]=tail;
	map[++tail]=node(u,head[v]);head[v]=tail;
}
struct point{
	int x,y,v,id;
}P[1501];
LL cross(point a,point b,point c){
	return 1ll*(1ll*b.x-1ll*a.x)*(1ll*c.y-1ll*a.y)
	      -1ll*(1ll*b.y-1ll*a.y)*(1ll*c.x-1ll*a.x);
}
bool cmpy(point a,point b){
	return a.y<b.y||(a.y==b.y&&a.x<b.x);
}
int tmp;
bool cmpth(point a,point b){
	return cross(P[tmp],a,b)>0;
}
int seq[1501],end[1501];
int dfs(int x,int fa,int id){
	seq[id]=x;int k=id;
	for (int i=head[x];i;i=map[i].next){
		int v=map[i].v;
		if (v!=fa) id=dfs(v,x,id+1); 
	}
	return end[k]=id;
}
bool cmpid(point a,point b){
	return a.id<b.id;
}
int main(){
	int n;
	scanf("%d",&n);
	for (int i=1;i<n;i++){
		int u,v;
		scanf("%d%d",&u,&v);
		insert(u,v);
	}
	for (int i=1;i<=n;i++){
		scanf("%d%d",&P[i].x,&P[i].y);
		P[i].id=i;
	}
	sort(P+1,P+n+1,cmpy);
	dfs(1,0,1);//求dfs序
	for (int i=1;i<=n;i++){
		P[i].v=seq[i];//确定根节点对应点
		tmp=i;
		sort(P+i+1,P+end[i]+1,cmpth);//按极角排序
	}
	sort(P+1,P+n+1,cmpid);
	for (int i=1;i<=n;i++) printf("%d ",P[i].v);
}
```

****

## F
### Problem description
> 给出一张n个点,m条边的连通图(有边权),其中有k个节点,若一个节点访问过了,则可以用0的代价访问这k个节点中其它的已经访问过的节点,求从1号节点出发,访问这k个节点的最小代价.

### Data Limit：n,m <= 1e5,1 ≤ wi ≤ 109 ,1 ≤ k ≤ n Time Limit: 2s

### Solution
> 因为每个节点至少要通过非0边访问1次,所以最小代价=这k个点的最小生成树+1号节点到这k个节点之一的最小代价.
> 
> 如果暴力加0权值边会T.

> 我们可以预处理这k个点(看做一个点)到其它点的最短路(和最短路是从哪个点出发的).
> 
> 接着枚举每一条边,它的两个节点(a,b)的最短路出发点(c,d)如果为同一点,则没有必要加边,反之,则意味着从c通过非0边转移到d的最小代价有可能为dist(a)+w(a,b)+dist(b),将它加到另一个图中.

> 最后只需要跑一个最小生成树即可.

### Code
```cpp
#define mp make_pair
typedef long long LL;
typedef pair<LL,int> pii;
struct node{
	int v;
	LL w;
	int next;
	node(int v=0,LL w=0,int next=0):v(v),w(w),next(next){}
}map1[200005];
int head1[100005],tail1;
inline void insert1(int u,int v,LL w){
	map1[++tail1]=node(v,w,head1[u]);head1[u]=tail1;
	map1[++tail1]=node(u,w,head1[v]);head1[v]=tail1;
}
struct node2{
	int u,v;
	LL w;
	node2(int u=0,int v=0,LL w=0):u(u),v(v),w(w){}
}map2[200005];
int tail2;
inline void insert2(int u,int v,LL w){
	map2[++tail2]=node2(u,v,w);
}

int fa[100005];
int getf(int x){
	if (fa[x]==x) return x;
	return fa[x]=getf(fa[x]);
}
bool cmp(node2 a,node2 b){
	return a.w<b.w;
}

LL dist[100005];
int from[100005],portal[100005];
priority_queue <pii,vector<pii>,greater<pii> > Q;
int main(){
	int n,m,k;
	scanf("%d%d",&n,&m);
	for (int i=1;i<=m;i++){
		int u,v,w;
		scanf("%d%d%d",&u,&v,&w);
		insert1(u,v,w);
	}
	scanf("%d",&k);
	memset(dist+1,127,sizeof(LL)*n);
	for (int i=1;i<=k;i++){
		scanf("%d",&portal[i]);
		Q.push(mp(dist[portal[i]]=0,from[portal[i]]=portal[i]));
	}
	//dijkstra
	while(!Q.empty()){
		pii a=Q.top();Q.pop();
		LL d=a.first;int id=a.second;
		if (d!=dist[id]) continue;
		for (int i=head1[id];i;i=map1[i].next){
			int v=map1[i].v;LL w=map1[i].w;
			if (dist[id]+w<dist[v]){
				Q.push(mp(dist[v]=dist[id]+w,v));
				from[v]=from[id];
			}
		}
	}
	for (int i=1;i<=m;i++){
		int u=map1[i*2].v,v=map1[i*2-1].v;
		if (from[u]!=from[v]){
			insert2(from[u],from[v],dist[u]+dist[v]+map1[i*2].w);
		}
	}
	//kruskal
	for (int i=1;i<=n;i++) fa[i]=i;
	sort(map2+1,map2+tail2+1,cmp);
	LL Ans=dist[1];
	for (int i=1;i<=tail2;i++){
		int u=map2[i].u,v=map2[i].v;
		int x=getf(u),y=getf(v);
		if (x!=y){
			fa[x]=y;
			Ans+=map2[i].w;
		}
	}
	cout<<Ans;
}

```