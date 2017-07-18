[比赛链接]https://vjudge.net/contest/168929#problem)

## 比赛征程
> * Y : solved in the contest
> * A : solved after contest
> * SY : solving


  \# |  A  |  B  |  C  |  D  |  E  
---|---|---|---|---|---
|contest0|Y|  Y  | A | A | A 



# 比赛中解决的问题
## A
### Problem description
> 给你四个正整数a,b,c,d,问你存不存在时刻，使得(a+k1 * b)与 (c+k2 * s d)相等？k1，k2为正整数。

### Data Limit：a,b,c,d<=100  Time Limit: 1s

### Solution
> 1、直接暴枚到30000000  O(30000000)*小常数</br>
2、枚举k1到10000 O(10000)*小常数</br>
3、扩展欧几里德算法
### Code
```cpp
using namespace std;
#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<cstdlib>
int x,y;
int gcd(int x,int y)
{
	return y==0?x:gcd(y,x%y);
}
void exgcd(int a,int b,int &x,int &y)
{
	if(b==0){x=1;y=0;return;} exgcd(b,a%b,x,y);int xx=x,yy=y;y=(xx-(a/b)*yy);x=yy;
}
int a,b,c,d;
int main()
{
	cin>>a>>b>>c>>d;
	int it=gcd(a,c);
	if(((d-b)/it)*it!=(d-b)){puts("-1");return 0;}
	exgcd(a,c,x,y);
	x*=(d-b)/it;
	y*=(d-b)/it;
//	cout<<x<<" "<<y<<endl;
	it=(a*c)/it;
	int t1=it/a,t2=it/c;
	while(y>0)
	{
		y-=t2;x+=t1;
	}
	while(abs(y)>t2)
	{
		y+=t2;x-=t1;
	}
	while(x<0) {x+=t1;y-=t2;}
	cout<<x*a+b<<endl;
}
```
*****


## B
### Problem description
> 每个宇宙来两个人，这两个人一叛徒一忠臣，他们报了一些组，当某一组全为叛徒时，机会取消，问是否有这样的可能性。

### Data Limit：n <= 1e4  Time Limit: 2s
### Solution
> 直接模拟即可。每次每组若出现两个来自同一个平行宇宙的，说明该组没危险。

### Code
```cpp
	scanf("%d",&n);cin>>m;
	for(int i=1;i<=m;i++)
	{
		scanf("%d",&num);
		memset(vis,0,sizeof(vis));
		bool flag=0;
		for(int j=1;j<=num;j++)
		{
			scanf("%d",&pp[j]);
		}
		for(int j=1;j<=num;j++) if(pp[j]>0) vis[pp[j]]=1;
		for(int j=1;j<=num;j++) if(pp[j]<0) if(vis[-pp[j]]){flag=1;break;}
		if(flag);else {puts("YES");return 0;}
	}
	puts("NO");
```
*****

# 赛后补题

## C
### Problem description
> 两个人玩游戏，每个人有一个集合，两人轮流游戏，每次他们能让怪兽顺时针走他们选出的自己集合中的数步（可以多次使用），某人走完后怪兽到了结束点就赢了，问对于怪兽在每个位置（不在
游戏结束点）某人先手是否必胜/必输或有策略无限循环？
### Data Limit：n <= 7e3  Time Limit: 4s

### Solution
> 这种博弈问题看到题目就两种思路：</br>
1、SG函数，这道题很难用</br>
2、广搜的赢点输点DP，一方不能再走为输</br>
对于一个赢点，那么所有对方能转移到他的点都为输点。</br>
对于一个点，如果所有他能够出发到达的点都是对手的赢点，那么该点为输点</br>
这是一大类套路DP，我要多做这方面的题。
### Code
```cpp
using namespace std;
#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<queue>
#include<map>
#define N 7001
struct NODE{
	int x,y,z;
}ind;
map<int,string>M;
int k[2],s[N][2];
int n,m;
bool b[N][3];
int ans[N][3];
int du[N][3];
queue<NODE>q;
void p(int x,int y,int z)
{
	if(b[x][y]) return;
	ind.x=x;ind.y=y;ind.z=z;
//	cout<<x<<" "<<y<<" "<<z<<endl;
	b[x][y]=1;q.push(ind);ans[x][y]=z;
}
int main()
{
	scanf("%d",&n);
	for(int i=0;i<=n;i++) for(int j=0;j<2;j++) ans[i][j]=3;
	for(int i=0;i<2;i++)
	{
		scanf("%d",&k[i]);
		for(int j=1;j<=k[i];j++) scanf("%d",&s[j][i]); 
	}
	for(int i=0;i<2;i++)
	{
		for(int j=1;j<=n;j++)
		{
			du[j][i]=k[i];
		}
	}
	M[0]="Win";M[1]="Lose";M[3]="Loop";
	p(0,0,1);p(0,1,1);
	while(!q.empty())
	{
		NODE hh=q.front();q.pop();
		int x=hh.x,y=hh.y,z=hh.z;
		if(z)
		for(int i=1;i<=k[y^1];i++) p((x-s[i][y^1]+n*5)%n,y^1,0);
		else
		{
			for(int i=1;i<=k[y^1];i++)
			{
				du[(x-s[i][y^1]+n*5)%n][y^1]--;
				if(!du[(x-s[i][y^1]+n*5)%n][y^1])
				p((x-s[i][y^1]+n*5)%n,y^1,1);
			}
		}
	}
	for(int i=0;i<2;i++)
	{
		for(int j=1;j<=n-1;j++)
		{
			cout<<M[ans[j][i]]<<" ";
		}
		puts("");
	}
}
```
*****


## D
### Problem description
> 
有三种类型的道路，1.花费x，从u->v.</br>
2、花费x，从u->[L,R]中任意一点。</br>
3、花费x，从[L,R]中任意一点->u;</br>
求s，到所有点的最少花费
### Data Limit：n <= 1e5  Time Limit: 2s
### Solution
> 这题是虚拟建建节点的方法，利用类似线段树的构造，把边数优化到nlogn</br>
这种题用单项边汇。
### Code
```cpp
using namespace std;
#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<queue>
#define r(x) scanf("%lld",&x)
#define forw(i,x) for(long long i=fir[x];i;i=ne[i])
#define N 3000001
long long root1,n,m,root2;
long long ty,x,u,v,l,r,w;
long long ne[N],dis[N],fir[N],to[N],C[N],cnt,tot;
bool inq[N];
long long s;
void add(long long x,long long y,long long z)
{
	ne[++cnt]=fir[x];fir[x]=cnt;to[cnt]=y;C[cnt]=z;
}
long long L[N],R[N];
long long lc[N],rc[N],sz;
queue<long long>q;
long long build1(long long l,long long r)
{
	if(l==r) {L[l]=l;R[l]=r;return l;}
	++sz;
	long long mid=(l+r)>>1;
	long long no=sz;
	add(no,lc[no]=build1(l,mid),0);add(no,rc[no]=build1(mid+1,r),0);
	L[no]=l;R[no]=r;
	return no;
}
long long build2(long long l,long long r)
{
	if(l==r) {L[l]=l;R[l]=r;return l;}
	++sz;long long mid=(l+r)>>1;
	long long no=sz;
	add(lc[no]=build2(l,mid),no,0);add(rc[no]=build2(mid+1,r),no,0);
	L[no]=l;R[no]=r;
	return no;
}
void ADD1(long long no,long long u,long long l,long long r,long long w)
{
	if(L[no]==l&&R[no]==r) {add(u,no,w);return;}
	long long mid=(L[no]+R[no])>>1;
	if(l>mid)
	ADD1(rc[no],u,l,r,w);else
	if(r<=mid)
	ADD1(lc[no],u,l,r,w);else
	{
		ADD1(lc[no],u,l,mid,w);
		ADD1(rc[no],u,mid+1,r,w);
		return;
	}
}
void ADD2(long long no,long long u,long long l,long long r,long long w)
{
	if(L[no]==l&&R[no]==r) {add(no,u,w);return;}
	long long mid=(L[no]+R[no])>>1;
	if(l>mid)
	ADD2(rc[no],u,l,r,w);else
	if(r<=mid)
	ADD2(lc[no],u,l,r,w);else
	{
		ADD2(lc[no],u,l,mid,w);
		ADD2(rc[no],u,mid+1,r,w);
		return;
	}
}
void SPFA(long long s)
{
	q.push(s);inq[s]=1;dis[s]=0;
	while(!q.empty())
	{
		long long ind=q.front();q.pop();inq[ind]=0;
		forw(i,ind)
		{
			long long V=to[i];
			if(dis[V]>dis[ind]+C[i])
			{
				dis[V]=dis[ind]+C[i];
				if(!inq[V])
				{
					inq[V]=1;
					q.push(V);
				}
			}
		}
	}
}
main()
{
	cin>>n>>m>>s;sz=n;
	root1=build1(1,n);
	root2=build2(1,n);
	for(long long i=1;i<=m;i++)
	{
		cin>>ty;
		if(ty==1) 
		{
			r(u);r(v);r(w);add(u,v,w);
		}
		if(ty==2) 
		{
			r(v);r(l);r(r);r(w);
			ADD1(root1,v,l,r,w);
		}
		if(ty==3)
		{
			r(v);r(l);r(r);r(w);
			ADD2(root2,v,l,r,w);
		}
	}
	for(long long i=1;i<=sz;i++) dis[i]=1e18;
	SPFA(s);
	for(long long i=1;i<=n;i++)
	{
		if(dis[i]<1e18) cout<<dis[i]<<' ';else cout<<"-1 ";
	}
}

```
*****

## E
### Problem description
> 一个有n个颜色的排列，对于特定的k，求将原序列分成最少的连续的段数，使每段的颜色数小于等于k。输出k=1~n的答案。

### Data Limit：n <= 1e5  Time Limit: 2s

### Solution
> 1、如果k=l的个数等于k=r的个数那么k=l~r这么多数答案均相同，这样就每次二分+模拟就可以了。调和级数约为logn.所以O(nlog^2n)
</br>
2、这类区间的题，可以用切割区间然后按左端点排序从左到右查找更新的方法解决，用树状数组维护从i~j内的不同颜色数，然后二分最远位置即可。
</br>特殊处理就是nxt数组记录下一个这种颜色，以便查询完i后删除i。很好的方法，对离线问题值得借鉴！

# ##Code1
```
using namespace std;
#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#define N 200001
int n,color[100001];
int ans[N];
int confuse[100001];
bool num[100001];
int cal(int x)
{
	if(confuse[x]) return confuse[x];
	for(int l=1;l<=n;)
	{
		int cnt=0;
		int f=l;
		while(cnt<x&&f<=n)
		{
			if(!num[color[f]])cnt++;
			num[color[f++]]=1;
		}
		while(num[color[f]]&&f<=n)f++;
		if(!num[color[f]])f--;
		for(int k=l;k<=f;k++) num[color[k]]=0;
		confuse[x]++;l=f+1;
	}
	return confuse[x];
}
void doit(int l,int r)
{
	if(l>r) return;
	int rr=r,ll=l+1;
	int an=l;
	while(ll<=rr)
	{
		int mid=(ll+rr)>>1;
		if(cal(mid)==cal(l))
		{
			ll=mid+1;an=mid;
		}
		else
		rr=mid-1;
	}
	for(int i=l;i<=an;i++) 
	{
		ans[i]=cal(l);
	}
	doit(an+1,r);
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&color[i]);
	doit(1,n);
	for(int i=1;i<=n;i++)
	{
		cout<<ans[i]<<" ";
	}
}
```
# ##Code1
```
using namespace std;
#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
#define N 300001
#define F(i,a,b) for(int i=a;i<=b;i++)
#define lowbit(x) (x&(-x))
int c[N],S[N];
int n,m;
vector<int>q[N];
int col[N];
void add(int x,int v)
{
	for(int i=x;i<=n;i+=lowbit(i))
	S[i]+=v;
}
int get(int k)
{
	int res=0;
	for(int i=16;i>=0;i--)
	{
		int x=(1<<i);
		if(res+x<=n)
		if(S[res+x]<=k)
		{
			res+=x;
			k-=S[res];
		}
	}
	return res;
}
int num[N];
int ans[N];
int nxt[N];
int main()
{
	scanf("%d",&n);for(int i=1;i<=n;i++) scanf("%d",&c[i]);
	for(int i=1;i<=n;i++)
	{
		q[1].push_back(i);
		if(!num[c[i]])
		{
			num[c[i]]=i;
			add(i,1);
		}
		else 
		{
			nxt[num[c[i]]]=i;
			num[c[i]]=i;
		}
	}
	F(i,1,n)
	{
		int hh=q[i].size();
		for(int j=0;j<hh;j++)
		{
			int xx=get(q[i][j]);
			ans[q[i][j]]++;
			q[xx+1].push_back(q[i][j]);
		} 
		hh=nxt[i];
		add(i,-1);if(hh>0) add(hh,1);
	}
	for(int i=1;i<=n;i++) cout<<ans[i]<<" ";
}
```
