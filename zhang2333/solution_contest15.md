## 比赛征程
> * Y : solved in the contest
> * A : solved after contest
> * W : solving

  \# |  A  |  B  |  C  |  D  |  E  |
---|---|---|---|---|---|
| contest15 |Y|Y|Y|A|A|

[比赛链接](https://cn.vjudge.net/contest/168929#overview)

## A
### Problem description
> 略

### Data Limit：略  Time Limit: 略
### Solution
> 略

### Code
```cpp
#include<cstdio>
#include<iostream>
#include<cstring>
#include<cmath>
#define ll long long
using namespace std;
ll a,b,c,d,ans;

int main()
{
	cin>>b>>a>>d>>c;
	for (ll i=0;i<=1234;i++)
		for (ll j=0;j<=1234;j++)
			if (a+b*i==c+d*j)
			{
				ans=a+b*i;
				cout<<ans<<endl;
				return 0;
			}
	printf("-1\n");
	return 0;
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
#include<cstring>
#include<cmath>
#include<map>
#define xxx 520233
#define ll long long
using namespace std;
ll n,m,k;
map<ll,ll>mp;

bool die()
{
	int f=1;
	mp.clear();
	cin>>k;
	ll x;
	for (int i=1;i<=k;i++)
	{
		cin>>x;
		if (mp[x]==1) f=0;
		mp[-x]=1;
	}
	return f;
}

int main()
{
	cin>>n>>m;
	while (m--)
	{
		if (die())
		{
			printf("YES\n");
			return 0;
		}
	}
	printf("NO\n");
	return 0;
}
```
*****
## C
### Problem description
> 博弈题。。</br>
  给出一个长度为n的环，环上的点编号为 1 to n。。有一只怪兽在[2,n]中的某一点上。。</br>
  有两只小明各有一个正整数集合。。</br>
  操作：一只小明可以让怪兽顺时针走t步（t 属于 他的正整数集合）。。</br>
  aim：使怪兽走到1号点的小明获胜。。</br>
  分别求出：每种情况下某只小明先手必胜or必输or死循环？。。</br>

### Data Limit：n <= 7e3  Time Limit: 4s
### Solution
> dp或记忆化搜索。。</br>

### Code
```cpp
#include<cstdio>
#include<iostream>
#include<cstring>
#include<cmath>
#include<map>
#define xxx 520233
#define ll long long
using namespace std;
int n,m,f[2][xxx],cg;
int g[2],a[2][xxx];

void doit(int p,int w)
{
	if (f[p][w]!=0) return;
	int cnt=0;
	for (int i=1;i<=g[p];i++)
	{
		int to=(w+a[p][i])%n;
		if (to==0)
		{
			f[p][w]=1;
			cg=1;
			return;
		}
		else if (f[p^1][to]==-1)
		{
			f[p][w]=1;
			cg=1;
			return;
		}
		else if (f[p^1][to]==1)
		{
			cnt++;
		}
	}
	if (cnt==g[p]) 
	{
		f[p][w]=-1;
		cg=1;
	}
	return;
}

int main()
{
	scanf("%d",&n);
	for (int i=0;i<2;i++)
	{
		scanf("%d",&g[i]);
		for (int j=1;j<=g[i];j++)
		{
			scanf("%d",&a[i][j]);
			a[i][j]%=n;
		}
	}
	cg=1;
	while (cg)
	{
		cg=0;
		for (int i=n-1;i>0;i--)
			for (int j=0;j<2;j++)
				doit(j,i);
	}
	for (int i=0;i<2;i++)
	{
		for (int j=1;j<n;j++)
		{
			if (f[i][j]==1)
				printf("Win ");
			else if (f[i][j]==-1)
				printf("Lose ");
			else
				printf("Loop ");
		}
		printf("\n");
	}
	return 0;
}
```
*****
## D
### Problem description
> 给出一张n个点的有向图，给出q条边，共3种边：</br>
    type 1:点u到点v一条权值为w的边。。</br>
    type 2:点u到区间[l,r]中的点均有一条权值为w的边。。</br>
    type 3:区间[l,r]中的点到点v均有一条权值为w的边。。</br>
  求：单源最短路。。</br>

### Data Limit：n <= 1e5  Time Limit: 2s
### Solution
> 用线段树的思想构造一堆虚拟点。。</br>
  每一半用于一个方向。。（也就是说区间[l,r]对应的虚拟点到[l,r]中的每个点都有一条距离为0的路径。。）</br>
  最后跑一遍最短路即可。。</br>

### Code
```cpp
#include<cstdio>
#include<iostream>
#include<cstring>
#include<cmath>
#include<map>
#include<queue>
#include<vector>
#define xxx 2332333
#define ll long long
using namespace std;

ll n,g,start,hea[xxx],cnt=1,tot,inf;
struct R{
	ll to,val,nex;
}r[xxx];
ll pos[xxx][2];

void add(ll u,ll v,ll w)
{
	r[++cnt]=(R){v,w,hea[u]};
	hea[u]=cnt;
}

void build(ll x,ll l,ll r)
{
	if (l==r) 
	{
		pos[x][0]=pos[x][1]=l;
		return;
	}
	pos[x][0]=++tot;
	pos[x][1]=++tot;
	ll mid=(l+r)>>1;
	build(x<<1,l,mid);
	build(x<<1|1,mid+1,r);
	add(pos[x][0],pos[x<<1][0],0);
	add(pos[x][0],pos[x<<1|1][0],0);
	add(pos[x<<1][1],pos[x][1],0);
	add(pos[x<<1|1][1],pos[x][1],0);
	return;
}

ll w,aim;
void que(ll x,ll l,ll r,ll st,ll en,ll t)
{
	if (l==st&&r==en)
	{
		if (t==0) add(aim,pos[x][t],w);
		else add(pos[x][t],aim,w);
		return;
	}
	ll mid=(l+r)>>1;
	if (en<=mid) 
	{
		que(x<<1,l,mid,st,en,t);
		return;
	}
	if (st>mid)
	{
		que(x<<1|1,mid+1,r,st,en,t);
		return;
	}
	que(x<<1,l,mid,st,mid,t);
	que(x<<1|1,mid+1,r,mid+1,en,t);
	return;
}

ll d[xxx];
bool used[xxx];
struct P{
	ll p,d;
}U,V;
struct cmp{
	bool operator()(P &p1,P &p2){
		return p1.d>p2.d;
	}
};
priority_queue<P,vector<P>,cmp>q;
void Dj()
{
	memset(d,38,sizeof(d));
	inf=d[0];
	d[start]=0;
	q.push((P){start,0});
	while (!q.empty())
	{
		U=q.top();
		q.pop();
		if (used[U.p]) continue;
		used[U.p]=1;
		for (ll i=hea[U.p];i>0;i=r[i].nex)
		{
			V.p=r[i].to;
			V.d=U.d+r[i].val;
			if (V.d<d[V.p])
			{
				d[V.p]=V.d;
				q.push(V);
			}
		}
	}
}

int main()
{
	cin>>n>>g>>start;
	tot=n;
	build(1,1,n);
	ll t,a,b,u,v;
	for (ll i=1;i<=g;i++)
	{
		scanf("%I64d",&t);
		if (t==1)
		{
			scanf("%I64d%I64d%I64d",&u,&v,&w);
			add(u,v,w);
		}else
		if (t==2)
		{
			scanf("%I64d%I64d%I64d%I64d",&u,&a,&b,&w);
			aim=u;
			que(1,1,n,a,b,0);
		}else
		if (t==3)
		{
			scanf("%I64d%I64d%I64d%I64d",&v,&a,&b,&w);
			aim=v;
			que(1,1,n,a,b,1);
		}
	}
	Dj();
	for (ll i=1;i<=n;i++)
		printf("%I64d ",d[i]==inf?-1:d[i]);
	return 0;
}
```
*****
## E
### Problem description
> n个颜色排成一排。。</br>
  对于一个正整数k。。ans[k]的计算方式如下：</br>
    把这排颜色砍成t段。。要求每一段的不同颜色数<=k。。ans[k]为t的最小值。。</br>
  求：输出ans\[i](1<=i<=n)。。</br>

### Data Limit：n <= 1e5  Time Limit: 2s
### Solution
> n*n的贪心显然要TLE。。</br>
  解1：在"HmoEbaiXdaUlao"大佬的提示下易得：ans[1..n]是不递增的。。所以。。呵呵。。</br>
  解2：线段树。。离线算法。。对于每个需要求右端点的k都用二分找。。</br>
  解3：树状数组。。同上。。</br>
  
### Code
```cpp
//1:
#include<cstdio>
#include<iostream>
#include<cstring>
#define xxx 100100
using namespace std;

int n,a[xxx],ans[xxx];

int cnt[xxx];
int que(int k)
{
	memset(cnt,0,sizeof(cnt));
	int t=1,s=0,p=1;
	for (int i=1;i<=n;i++)
	{
		if ((++cnt[a[i]])==1)
			s++;
		if (s>k)
		{
			for (int j=p;j<i;j++)
				cnt[a[j]]--;
			p=i;
			s=1;
			t++;
		}
	}
	return t;
}

void doit(int l,int r)
{
	if (l+1>=r) return;
	if (ans[l]==ans[r])
	{
		for (int i=l+1;i<r;i++)
			ans[i]=ans[l];
		return;
	}
	int mid=(l+r)>>1;
	ans[mid]=que(mid);
	doit(l,mid);
	doit(mid,r);
	return;
}

int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	ans[1]=que(1);
	ans[n]=1;
	doit(1,n);
	for (int i=1;i<=n;i++)
		printf("%d ",ans[i]);
}
```
```cpp
//2:
#include<cstdio>
#include<iostream>
#include<vector>
#define xxx 100100
#define yyy 1520233
using namespace std;

int n,a[xxx],hea[xxx],nex[xxx],ans[xxx]={0};
struct T{
	int val,laz;
}tr[yyy];
vector<int>v[xxx];

void D(int x)
{
	tr[x<<1].laz+=tr[x].laz;
	tr[x<<1].val+=tr[x].laz;
	tr[x<<1|1].laz+=tr[x].laz;
	tr[x<<1|1].val+=tr[x].laz;
	tr[x].laz=0;
}

void C(int x,int l,int r,int st,int en,int cg)
{
	if (l==st&&r==en)
	{
		tr[x].val+=cg;
		tr[x].laz+=cg;
		return;
	}
	D(x);
	int mid=(l+r)>>1;
	if (en<=mid) 
	{
		C(x<<1,l,mid,st,en,cg);
		tr[x].val=min(tr[x<<1].val,tr[x<<1|1].val);
		return;
	}
	if (st>mid)
	{
		C(x<<1|1,mid+1,r,st,en,cg);
		tr[x].val=min(tr[x<<1].val,tr[x<<1|1].val);
		return;
	}
	C(x<<1,l,mid,st,mid,cg);
	C(x<<1|1,mid+1,r,mid+1,en,cg);
	tr[x].val=min(tr[x<<1].val,tr[x<<1|1].val);
	return;
}

int fin(int x,int l,int r,int v)
{
	if (l==r) return l;
	D(x);
	int mid=(l+r)>>1;
	if (tr[x<<1|1].val<=v) return fin(x<<1|1,mid+1,r,v);
	else return fin(x<<1,l,mid,v);
}

int main()
{
	scanf("%d",&n);
	tr[1].val=tr[1].laz=0;
	for (int i=1;i<=n;i++)
		nex[i]=hea[i]=n+1;
	int x,y;
	for (int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for (int i=n;i>0;i--)
	{
		nex[i]=hea[a[i]];
		hea[a[i]]=i;
	}
	for (int i=1;i<=n;i++)
		if (hea[i]<=n)
			C(1,1,n,hea[i],n,1);
			
	for (int i=1;i<=n;i++)
		v[1].push_back(i);
	for (int i=1;i<=n;i++)
	{
		for (int j=0;j<v[i].size();j++)
		{
			x=v[i][j];
			y=fin(1,1,n,x)+1;
			v[y].push_back(x);
			ans[x]++;
		}
		C(1,1,n,i,nex[i]-1,-1);
	}
	
	for (int i=1;i<=n;i++)
		printf("%d ",ans[i]);
}
```

```cpp
//3:
#include<cstdio>
#include<iostream>
#include<vector>
#define xxx 100100
#define yyy 520233
using namespace std;

int n,a[xxx],hea[xxx],nex[xxx],ans[xxx]={0};
vector<int>v[xxx];
int c[yyy];

void C(int p,int v)
{
	for (int i=p;i<=n;i+=(i&(-i)))
		c[i]+=v;
	return;
}

//树状数组上直接二分前缀和。。 
int F(int k)
{
	int t=0,b;
	for (int i=16;i>=0;i--)
	{
		b=1<<i;
		if (c[t+b]<=k&&t+b<=n)
		{
			t+=b;
			k-=c[t];
		}
	}
	return t;
}

int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
		nex[i]=hea[i]=n+1;
	int x,y;
	for (int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for (int i=n;i>0;i--)
	{
		nex[i]=hea[a[i]];
		hea[a[i]]=i;
	}
	for (int i=1;i<=n;i++)
		if (hea[i]<=n)
			C(hea[i],1);
			
	for (int i=1;i<=n;i++)
		v[1].push_back(i);
	for (int i=1;i<=n;i++)
	{
		for (int j=0;j<v[i].size();j++)
		{
			x=v[i][j];
			y=F(x)+1;
			v[y].push_back(x);
			ans[x]++;
		}
		C(i,-1);
		C(nex[i],1);
	}
	
	for (int i=1;i<=n;i++)
		printf("%d ",ans[i]);
}
```
*****
