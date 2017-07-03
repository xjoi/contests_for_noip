# 比赛记录
> * YES : solved in the contest
> * Accepted : solved after contest
> * Waiting : solving
> * NO : haven't tried

  \# |  A  |  B  |  C  |  D  |  E  |
---|---|---|---|---|---|
| contest14 | YES   |   YES   | YES|Accepted|Accepted|


[比赛链接](https://cn.vjudge.net/contest/168561#overview)
## A
### Problem description
> 略
### Solution
略
```cpp
#include<cstdio>
#include<iostream>
#define xxx 520233
using namespace std;
int n,c,a[xxx],ans=0;

int main()
{
	scanf("%d%d",&n,&c);
	for (int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	a[0]=a[1];
	for (int i=1;i<=n;i++)
	{
		if (a[i]-a[i-1]<=c)
			ans++;
		else
			ans=1;
	}
	printf("%d",ans);
} 
```
***** 

## B
### Problem description
> 略
### Solution
略
```cpp
#include<cstdio>
#include<iostream>
#include<cstring>
#define xxx 520233
using namespace std;
int n,c,ans=0,l,cnt[128],wh;
char s[xxx];

bool doit(int st)
{
	for (int i='A';i<='Z';i++)
		cnt[i]=0;
	cnt['?']=0;
	for (int i=st;i<st+26;i++)
	{
		cnt[s[i]]++;
		if (s[i]!='?'&&cnt[s[i]]>1) return 0;
	}
	int p='A';
	for (int i=st;i<st+26;i++)
	{
		if (s[i]=='?')
		{
			while (cnt[p]) p++;
			s[i]=p++;
		}
	}
	for (int i=1;i<=l;i++)
	{
		if (s[i]=='?') printf("A");
		else printf("%c",s[i]);
	}
	return 1;
}

int main()
{
	scanf("%s",s+1);
	l=strlen(s+1);
	for (int i=1;i<=l-25;i++)
		if (doit(i))
			return 0;
	printf("-1");
	return 0;
} 
```
***** 

## C
### Problem description
> 数学题一枚

### Solution
略
```cpp
#include<cstdio>
#include<iostream>
#include<cstring>
#define xxx 520233
using namespace std;
long long a[xxx];
int n;

int main()
{
	a[1]=2;
	for (long long i=2;i<=100001;i++)
		a[i]=(long long)(i+1)*(i+1)*i-i+1;
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
		printf("%lld\n",a[i]);
	return 0;
} 
```
***** 

## D
### Problem description
> 给一张有边权的无向图。。其中一些边为可变边（权值可变的边）。。
> 可行操作：随意改变可变边的权值。。
> 目标：对于一对给定的s和t，使得s到t的最短路距离恰为l。。
> 输出：每条边两端的顶点及其权值。。（当然是SPJ。。）
### Solution
解一：暴力。。先判断NO。。

　　之后把最短路上的任意一条可变边的权值增大l-dis[s,t]。。

　　无限循环直至l==dis[s,t]。。

解二：先将可变边边权赋为1。。

　　先以t为出发点跑一遍单元最短路。。求出dis\[u,t](u属于G)。。

　　再以s为出发点跑一遍单源最短路。。注意：这一遍很关键！。。每当松弛一条可变边(u,v)时，将这条边(u,v)的边权改为max(edge[u,v]，l-dis[s,u]-dis[v,t]）。。保证走过这条可变边的s到t的路径一定>=l。。

　　最后根据dis[s,t]==l?判断是否可行。。

```cpp
//解一：
#include<cstdio>
#include<iostream>
#include<cstring>
#include<vector>
#include<queue>
#define ll long long
#define xxx 1010
#define yyy 20233
#define inf 5202333333
using namespace std;
struct R{
	ll to,val,nex,pos;
}r[yyy];
struct E{
	int from,to,waste,pos;
}e[yyy];
ll n,m,l,st,en,cnt=1,hea[xxx];

queue<ll>q;
ll d[xxx],in[xxx],pre[xxx],prp[xxx];
void S(int ss)
{
	memset(d,38,sizeof(d));
	d[ss]=0;
	while (!q.empty()) q.pop();
	q.push(ss);
	memset(in,0,sizeof(in));
	ll x,y;
	while (!q.empty())
	{
		x=q.front();
		q.pop();
		in[x]=0;
		for (int i=hea[x];i>0;i=r[i].nex)
		{
			y=r[i].to;
			if (d[y]>d[x]+r[i].val)
			{
				d[y]=d[x]+r[i].val;
				pre[y]=x;prp[y]=i;
				if (!in[y])
				{
					in[y]=1;
					q.push(y);
				}
			}
		}
	}
}

int main()
{
	scanf("%I64d%I64d%I64d%I64d%I64d",&n,&m,&l,&st,&en);
	st++;en++;
	for (int i=1;i<=m;i++)
	{
		scanf("%I64d%I64d%I64d",&e[i].from,&e[i].to,&e[i].waste);
		e[i].from++;e[i].to++;
		r[++cnt]=(R){e[i].to,e[i].waste,hea[e[i].from],i};
		hea[e[i].from]=cnt;
		r[++cnt]=(R){e[i].from,e[i].waste,hea[e[i].to],i};
		hea[e[i].to]=cnt;
		e[i].pos=cnt;
	}
	//0->inf
	for (int i=1;i<=m;i++)
	{
		if (e[i].waste==0)
		{
			r[e[i].pos].val=inf;
			r[e[i].pos^1].val=inf;
		}
	}
	S(st);
	if (d[en]<l)
	{
		printf("NO\n");
		return 0;
	}
	if (d[en]==l)
	{
		printf("YES\n");
		for (int i=1;i<=m;i++)
			printf("%I64d %I64d %I64d\n",(ll)(e[i].from-1),(ll)(e[i].to-1),(ll)r[e[i].pos].val);
		return 0;
	}
	
	//0->1
	for (int i=1;i<=m;i++)
	{
		if (e[i].waste==0)
		{
			r[e[i].pos].val=1;
			r[e[i].pos^1].val=1;
		}
	}
	S(st);
	if (d[en]>l)
	{
		printf("NO\n");
		return 0;
	}
	
	int t,p,las,cg;
	while (d[en]<l)
	{
		t=en;
		while (t!=st)
		{
			p=prp[t];
			if (e[r[p].pos].waste==0)
			{
				r[p].val+=l-d[en];
				r[p^1].val+=l-d[en];
				break;
			}
			t=pre[t];
		}
		S(st);
	}
	
	printf("YES\n");
	for (int i=1;i<=m;i++)
		printf("%I64d %I64d %I64d\n",(ll)(e[i].from-1),(ll)(e[i].to-1),(ll)r[e[i].pos].val);
	return 0;
}
```
```cpp
解2：
#include<cstdio>
#include<iostream>
#include<cstring>
#include<vector>
#include<queue>
#define ll long long
#define xxx 1010
#define yyy 20233
#define inf 5202333333
using namespace std;
struct R{
	ll to,val,nex,pos;
}r[yyy];
struct E{
	int from,to,waste,pos;
}e[yyy];
ll n,m,l,st,en,cnt=1,hea[xxx];

bool flag=0;
queue<ll>q;
ll d[xxx],dd[xxx],in[xxx];
void S(int ss)
{
	memset(d,38,sizeof(d));
	d[ss]=0;
	while (!q.empty()) q.pop();
	q.push(ss);
	memset(in,0,sizeof(in));
	ll x,y;
	while (!q.empty())
	{
		x=q.front();
		q.pop();
		in[x]=0;
		for (int i=hea[x];i>0;i=r[i].nex)
		{
			y=r[i].to;
			if (flag&&e[r[i].pos].waste==0) 
				r[i].val=r[i^1].val=max(r[i].val,l-d[x]-dd[y]);
			if (d[y]>d[x]+r[i].val)
			{
				d[y]=d[x]+r[i].val;
				if (!in[y])
				{
					in[y]=1;
					q.push(y);
				}
			}
		}
	}
}

int main()
{
	scanf("%I64d%I64d%I64d%I64d%I64d",&n,&m,&l,&st,&en);
	st++;en++;
	for (int i=1;i<=m;i++)
	{
		scanf("%I64d%I64d%I64d",&e[i].from,&e[i].to,&e[i].waste);
		e[i].from++;e[i].to++;
		r[++cnt]=(R){e[i].to,e[i].waste,hea[e[i].from],i};
		hea[e[i].from]=cnt;
		r[++cnt]=(R){e[i].from,e[i].waste,hea[e[i].to],i};
		hea[e[i].to]=cnt;
		e[i].pos=cnt;
	}
	
	//0->1
	for (int i=1;i<=m;i++)
	{
		if (e[i].waste==0)
		{
			r[e[i].pos].val=1;
			r[e[i].pos^1].val=1;
		}
	}
	S(en);
	for (int i=1;i<=n;i++)
		dd[i]=d[i];
	flag=1;
	S(st);
	
	if (d[en]!=l)
	{
		printf("NO\n");
		return 0;
	}
	
	printf("YES\n");
	for (int i=1;i<=m;i++)
		printf("%I64d %I64d %I64d\n",(ll)(e[i].from-1),(ll)(e[i].to-1),(ll)r[e[i].pos].val);
	return 0;
}
```
***** 

## E
### Problem description
> 给一颗有边权的树（节点数n<=1e5，边权为一位正整数）。。</br>
  规定一条路径的长为沿途所有边权组成的l位十进制数。。</br>
  求对于一个给定的正整数m，有多少个有序点对(u,v)(u!=v),使得u到v的路径长度是m的倍数。。</br>

### Solution
  树的点分治。。稍微加一点容斥思想。。</br>
  我们注意到所有满足题意的点对(u,v)，令u到lca的距离为u.key，lca到v的距离为v.key，v的深度为v.dep。。</br>
  则：u.key*pow(10,v.dep)+v.key 三 0(mod m)</br>
  => u.key 三 (-v.key)*pow(10,-v.dep);(逆元有扩欧搞一搞。。)</br>
  然后就很简单了。。</br>
  （还有注意u==v的时候）。。</br>

```cpp
#include<cstdio>
#include<iostream>
#include<map>
#define xxx 520233
#define ll long long
using namespace std;
map<ll,ll>mp;
struct R{
	ll to,val,nex;
}r[xxx<<1];
ll n,m,hea[xxx],cnt=1,siz[xxx],die[xxx],ans=0,ny[xxx],zy[xxx];

ll f[233],x,y;
void K(ll a,ll b)
{
	if (b==1)
	{
		x=0;y=1;
		return;
	}
	K(b,a%b);
	swap(x,y);
	y=y-a/b*x;
	return;
}

void P()
{
	ny[0]=zy[0]=1;
	for (ll i=1;i<=100002;i++)
		zy[i]=zy[i-1]*10%m;
	for (ll i=1;i<=100002;i++)
	{
		K(zy[i],m);
		ny[i]=(x%m+m)%m;
	}
	return;
}

void A(ll x,ll fa,ll dep,ll v)
{
	mp[v]++;
	for (ll i=hea[x];i>0;i=r[i].nex)
	{
		if (r[i].to==fa||die[r[i].to]) continue;
		A(r[i].to,x,dep+1,(r[i].val*zy[dep]+v)%m);
	}
	return;
}

ll B(ll x,ll fa,ll dep,ll v)
{
	ll turn=mp[ ((-v)%m+m)*ny[dep]%m ];
	for (ll i=hea[x];i>0;i=r[i].nex)
	{
		if (r[i].to==fa||die[r[i].to]) continue;
		turn+=B(r[i].to,x,dep+1,(v*10+r[i].val)%m);
	}
	return turn;
}

ll C(ll x,ll stdep,ll v)
{
	mp.clear();
	A(x,-1,stdep,v);
	return B(x,-1,stdep,v);
}

void S(ll x,ll fa)
{
	siz[x]=1;
	for (ll i=hea[x];i>0;i=r[i].nex)
	{
		if (r[i].to==fa||die[r[i].to]) continue;
		S(r[i].to,x);
		siz[x]+=siz[r[i].to];
	}
	return;
}

ll H(ll x,ll fa,ll totsiz)
{
	for (ll i=hea[x];i>0;i=r[i].nex)
		if (siz[r[i].to]*2>totsiz&&!die[r[i].to]&&r[i].to!=fa)
			return H(r[i].to,x,totsiz);
	return x;
}

void D(ll x,ll fa)
{
	die[x]=1;
	ans+=C(x,0,0);
	for (ll i=hea[x];i>0;i=r[i].nex)
	{
		if (r[i].to==fa||die[r[i].to]) continue;
		ans-=C(r[i].to,1,r[i].val);
		S(r[i].to,-1);
		D(H(r[i].to,-1,siz[r[i].to]),x);
	}
}

int main()
{
	scanf("%I64d%I64d",&n,&m);
	P();
	ll u,v,w;
	for (ll i=1;i<n;i++)
	{
		scanf("%I64d%I64d%I64d",&u,&v,&w);
		w%=m;
		r[++cnt]=(R){v,w,hea[u]};
		hea[u]=cnt;
		r[++cnt]=(R){u,w,hea[v]};
		hea[v]=cnt;
	}
	S(0,-1);
	D(H(0,-1,siz[0]),-1);
	ans-=n;
	cout<<ans;
}
```
***** 
