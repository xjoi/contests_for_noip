# 比赛记录

### Problem description

求M，使M/(N+1)和m/n尽量接近

## # A

> 考虑到此人也在中国，N要加一.

```cpp
#include<cstdio>
#include<iostream>
using namespace std;
int main() {
	double n,m,N;
	int ans;
	cin>>n>>m>>N;
	ans=(N+1.0)*m/n;
	if(ans>N) ans=N;
	cout<<ans<<endl;
	return 0;
}
```
### Problem description

几个人围坐在圆桌边，第一个人必须坐在某个位置，某些人特别要求坐在某些人旁边，求总的方案数.

# C

### Problem description

 求一个四边形的对称轴数量并*2输出.
 
 > 四边形的对称轴只可能是对角线所在直线或者是某边的中垂线，后者仅当其与对边中垂线重合时才符合.
  
```cpp
#include<cstdio>
#include<iostream>
#include<cmath>
using namespace std;
const double eps=1e-8;
double x[5],y[5],k1,b1,k2,b2;
int main() {
	int cnt=0;
	for(int i=1;i<=4;i++) cin>>x[i]>>y[i];
	if(y[1]==y[2]&&y[3]==y[4]&&x[1]+x[2]==x[3]+x[4]) cnt++;
	else if(x[1]==x[2]&&x[3]==x[4]&&y[1]+y[2]==y[3]+y[4]) cnt++;
	else if(y[1]!=y[2]&&y[3]!=y[4]){
		k1=-(x[1]-x[2])/(y[1]-y[2]);
		k2=-(x[3]-x[4])/(y[3]-y[4]);
		b1=(y[1]+y[2])/2-k1*((x[1]+x[2])/2);
		b2=(y[3]+y[4])/2-k2*((x[3]+x[4])/2);
		if(fabs(k1-k2)<=eps&&fabs(b1-b2)<=eps) cnt++;
	}
	if(y[1]==y[4]&&y[2]==y[3]&&x[1]+x[4]==x[3]+x[2]) cnt++;
	else if(x[1]==x[4]&&x[3]==x[2]&&y[1]+y[4]==y[3]+y[2]) cnt++;
	else if(y[1]!=y[4]&&y[3]!=y[2]){
		k1=-(x[1]-x[4])/(y[1]-y[4]);
		k2=-(x[3]-x[2])/(y[3]-y[2]);
		b1=(y[1]+y[4])/2-k1*((x[1]+x[4])/2);
		b2=(y[3]+y[2])/2-k2*((x[3]+x[2])/2);
		if(fabs(k1-k2)<=eps&&fabs(b1-b2)<=eps) cnt++;
	}
	if(y[1]==y[3]&&x[2]==x[4]&&x[1]+x[3]==2*x[2]) cnt++;
	else if(x[1]==x[3]&&y[2]==y[4]&&y[1]+y[3]==2*y[2]) cnt++;
	else if(x[2]!=x[4]&&y[1]!=y[3]) {
		k1=(y[2]-y[4])/(x[2]-x[4]);
		b1=y[2]-k1*x[2];
		k2=-(x[1]-x[3])/(y[1]-y[3]);
		b2=(y[1]+y[3])/2-k2*((x[1]+x[3])/2);
		if(fabs(k1-k2)<=eps&&fabs(b1-b2)<=eps) cnt++;
	}
	if(y[2]==y[4]&&x[1]==x[3]&&x[2]+x[4]==2*x[1]) cnt++;
	else if(x[2]==x[4]&&y[1]==y[3]&&y[2]+y[4]==2*y[1]) cnt++;
	else if(x[1]!=x[3]&&y[2]!=y[4]){
		k1=(y[1]-y[3])/(x[1]-x[3]);
		b1=y[1]-k1*x[1];
		k2=-(x[2]-x[4])/(y[2]-y[4]);
		b2=(y[2]+y[4])/2-k2*((x[2]+x[4])/2);
		if(fabs(k1-k2)<=eps&&fabs(b1-b2)<=eps) cnt++;
	}
	cout<<cnt*2<<endl;
	return 0;
}
```

# D

> 简单的容斥

```cpp
#include<cstdio>
#include<iostream>
using namespace std;
long long d[22],k,t;
int main() {
	int n;
	cin>>k>>n;
	for(int i=1;i<=n;i++) cin>>d[i];
	t=d[1];
	for(int i=2;i<=n;i++) t=max(0ll,t+d[i]-k);
	cout<<t<<endl;
	return 0;
}
```

# 赛后补题

## #B

> 显然如果存在可能方案，要么是一个大环，要么是几条链.

> 如果人数为2，输出1即可（一个人必须坐在第一个位置）
  
> 在一条链中，显然可行的方案只有正反两种（对于长度为1的仅有一种）
  
> 若存在环且环外有点，则方案数为0.
  
> 由于一个人的位置已经固定，他所属于的链的位置已经固定，所以链的总排列方案是(n-1)!
  
> 对于每条链，若长度大于1，则需方案数*2
  
```cpp
#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;
typedef long long LL;
const int N=205;
const LL mod=1e9+7;
int cnt=0,du[N],mx=0,sz[N],tot=0;
int n,m,p;
bool vis[N],jud=1,G[N][N];
inline void dfs(int x) {
	vis[x]=1;
	mx++;
	for(int i=1;i<=n;i++) if(G[x][i]&&!vis[i]) dfs(i);
}
inline void dfs_1(int x,int pa) {
	vis[x]=1;
	sz[tot]++;
	for(int i=1;i<=n;i++) if(G[x][i]&&i!=x&&i!=pa) {
		if(vis[i]) jud=0;
		if(!vis[i]) dfs_1(i,x);
	}
}
int main() {
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++) {
		scanf("%d",&p);
		if(G[i][p]) continue;
		du[i]++;
		du[p]++;
		G[i][p]=G[p][i]=1;
	}
	if(n==2) {
		printf("1\n");
		return 0;
	}
	for(int i=1;i<=n;i++) if(du[i]>2) {
		printf("0\n");
		return 0;
	}
	dfs(1);
	if(mx==n) {
		printf("2\n");
		return 0;
	}
	memset(vis,0,sizeof(vis));
	for(int i=1;i<=n;i++) if(!vis[i]) tot++,dfs_1(i,-1);
	if(!jud) {
		printf("0\n");
		return 0;
	}
	LL ans=1ll;
	for(int i=1;i<tot;i++) ans=(ans*(LL)i)%mod;
	for(int i=1;i<=tot;i++) if(sz[i]>1) ans=(ans*2ll)%mod;
	cout<<ans<<endl;
	return 0;
}
```

# E
同增同减的情况用贪心特判
> (a[i-1],f[i-1])->(a[i],f[i]=f[i-1])

> (a[i-1],f[i-1])->(g[i]=a[i-1],a[i])

> (g[i-1],a[i-1])->(a[i],f[i]=a[i-1])

> (g[i-1],a[i-1])->(g[i]=g[i-1],a[i])


```cpp
#include<cstdio>
#include<iostream>
#include<cstring>
#include<queue>
using namespace std;
const int N=200005;
const int INF=2139062143;
int a[N],f[N],g[N],frec[N],grec[N],n;
bool found=0,used[N];
void solve(int a0,int a1) {
	if(found) return;
	memset(frec,0,sizeof(frec));
	memset(grec,0,sizeof(grec));
	if(a0==1) memset(g,127,sizeof(g)); else memset(g,0,sizeof(g));
	if(a1==1) memset(f,127,sizeof(f)); else memset(f,0,sizeof(f));
	g[1]=INF-g[1];
	f[1]=INF-f[1];
	int now;
	bool upd=0;
	for(int i=2;i<=n;i++) {
		upd=0;
		if(a[i]*a0>a[i-1]*a0) {
			if(f[i-1]*a1<f[i]*a1) {
				f[i]=f[i-1];
				frec[a[i]]=a[i-1];
				now=1;
				upd=1;
			}
		}
		if(a[i]*a1>f[i-1]*a1) {
			if(a[i-1]*a0<g[i]*a0) {
				g[i]=a[i-1];
				grec[a[i]]=f[i-1];
				now=2;
				upd=1;
			}
		}
		if(a[i]*a0>g[i-1]*a0) {
			if(a[i-1]*a1<f[i]*a1) {
				f[i]=a[i-1];
				frec[a[i]]=g[i-1];
				now=1;
				upd=1;
			}
		}
		if(a[i]*a1>a[i-1]*a1) {
			if(g[i-1]*a0<g[i]*a0) {
				g[i]=g[i-1];
				grec[a[i]]=a[i-1];
				now=2;
				upd=1;
			}
		}
		if(!upd) return;
	}
	found=1;
	int p,ct0=1;
	used[a[n]]=1;
	if(now==1) {
		p=frec[a[n]];
		while(p&&p!=INF) used[p]=1,p=frec[p],ct0++;
	} else {
		p=grec[a[n]];
		while(p&&p!=INF) used[p]=1,p=grec[p],ct0++;
	}
	printf("%d %d\n",ct0,n-ct0);
	for(int i=1;i<=n;i++) if(used[a[i]]) printf("%d ",a[i]);
	printf("\n");
	for(int i=1;i<=n;i++) if(!used[a[i]]) printf("%d ",a[i]);
}
priority_queue<int> q1, q2;
int f_ans[N], g_ans[N], f_lnth, g_lnth;
bool work1(){
	while(!q1.empty()) q1.pop();
	while(!q2.empty()) q2.pop();
	q1.push(a[1]);
	for(int i=2;i<=n;i++) {
		if(q1.top()<a[i]) {
			q1.push(a[i]);
		} else {
			if(q2.empty()) q2.push(a[i]);
			else if(q2.top() < a[i]) q2.push(a[i]);
			else return false;
		}
	}
	if(q1.size()==n){
		q2.push(q1.top());
		q1.pop();
	}
	f_lnth=q1.size();
	g_lnth=q2.size();
	for(int i=f_lnth;i>=1;i--) f_ans[i]=q1.top(),q1.pop();
	for(int i=g_lnth;i>=1;i--) g_ans[i]=q2.top(),q2.pop();
	printf("%d %d\n",f_lnth,g_lnth);
	for(int i=1;i<=f_lnth;i++) printf("%d%c",f_ans[i]," \n"[i==f_lnth]);
	for(int i=1;i<=g_lnth;i++) printf("%d%c",g_ans[i]," \n"[i==g_lnth]);
	return true;
}
bool work2(){
	while(!q1.empty()) q1.pop();
	while(!q2.empty()) q2.pop();
	q1.push(-a[1]);
	for(int i=2;i<=n;i++){
		if(q1.top()<-a[i]){
			q1.push(-a[i]);
		} else{
			if(q2.empty()) q2.push(-a[i]);
			else if(q2.top() < -a[i]) q2.push(-a[i]);
			else return false;
		}
	}
	if(q1.size() == n){
		q2.push(q1.top());
		q1.pop();
	}
	f_lnth=q1.size();
	g_lnth=q2.size();
	for(int i=f_lnth;i>=1;i--) f_ans[i]=-q1.top(),q1.pop();
	for(int i=g_lnth;i>=1;i--) g_ans[i]=-q2.top(),q2.pop();
	printf("%d %d\n",f_lnth, g_lnth);
	for(int i=1;i<=f_lnth;i++) printf("%d%c",f_ans[i]," \n"[i==f_lnth]);
	for(int i=1;i<=g_lnth;i++) printf("%d%c", g_ans[i]," \n"[i==g_lnth]);
	return true;
}
int main() {
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	if(work1()) return 0;
	if(work2()) return 0;
	solve(1,-1);
	solve(-1,1);
	if(!found) printf("Fail\n");
	return 0;
}
```

# F

### Problem description

给定一些点和线段，判断所有点是否连通.

> 简单的判断点在线段上、线段相交的题，感谢老师的模板.

```cpp
#include<cstdio>
#include<iostream>
#include<cmath>
using namespace std;
const int N=205;
const double eps=1e-8;
struct Point {
    double x, y;
    int num;
    Point () {
    }
    Point (double x, double y) : x(x), y(y) {
    }
    Point operator + (Point a) {
        return Point(x + a.x, y + a.y);
    }
    Point operator / (double a) {
        return Point(x / a, y / a);
    }
    double dot(Point a) {
        return x * a.x + y * a.y;
    }
    Point operator - (Point a) {
        return Point(x - a.x, y - a.y);
    }
    double operator * (Point a) {
        return x * a.y - y * a.x;
    }
}p[N];
struct L{Point a,b;}l[N];
int sgn(double x) {
    return x<-eps?-1:x>eps;
}
bool dot_on_seg(Point p, Point a, Point b) {
    return sgn((a-p)*(b-p))==0&&sgn((a-p).dot(b-p))<=0;
}
int fa[N];
double cross(Point a,Point b,Point c) {
	return (b.x-a.x)*(c.y-a.y)-(c.x-a.x)*(b.y-a.y);
}
bool intersect(L l1, L l2) {
	Point p1=l1.a,p2=l1.b,q1=l2.a,q2=l2.b;
    return (
			std::min(p1.x, p2.x) <= std::max(q1.x, q2.x) &&
			std::min(q1.x, q2.x) <= std::max(p1.x, p2.x) &&
			std::min(p1.y, p2.y) <= std::max(q1.y, q2.y) &&
			std::min(q1.y, q2.y) <= std::max(p1.y, p2.y) &&
			cross(p1, q2, q1)*cross(p2, q2, q1) <= 0 &&
			cross(q1, p2, p1)*cross(q2, p2, p1) <= 0
	       );
}

inline int getf(int x) {
	if(fa[x]==x) return x;
	fa[x]=getf(fa[x]);
	return fa[x];
}
int main() {
	int a,b,n,m,x,y;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++) {
		cin>>p[i].x>>p[i].y;
		fa[i]=i;
		p[i].num=i;
	}
	for(int i=1;i<=m;i++) {
		scanf("%d%d",&x,&y);
		a=getf(x);
		b=getf(y);
		fa[a]=b;
		l[i].a=p[x];
		l[i].b=p[y];
	}
	for(int i=1;i<m;i++) {
		for(int j=i+1;j<=m;j++) {
			if(intersect(l[i],l[j])) {
				a=getf(l[i].a.num);
				b=getf(l[j].a.num);
				fa[a]=b;
			}
		}
	}
	for(int i=1;i<=m;i++) {
		for(int j=1;j<=n;j++) {
			if(j==l[i].a.num||j==l[i].b.num) continue;
			if(dot_on_seg(p[j],l[i].a,l[i].b)) {
				a=getf(l[i].a.num);
				b=getf(j);
				fa[a]=b;
			}
		}
	}
	int g=getf(1);
	for(int i=2;i<=n;i++) {
		if(getf(i)!=g) {
			printf("NO\n");
			return 0;
		}
	}
	printf("YES\n");
	return 0;
}
```
