# 比赛记录
> * YES : solved in the contest
> * Accepted : solved after contest
> * Waiting : solving
> * NO : haven't tried

  \# |  A  |  B  |  C  |  D  |  E  |  F  |  G  
---|---|---|---|---|---|---|---
| contest13 | YES   |   YES   | YES|YES|YES|Accepted|Accepted


[比赛链接](https://cn.vjudge.net/contest/168406#overview)
## A
### Problem description
> 略
### Solution
略
```cpp
#include<cstdio>
#include<cstring>
#define xxx 5202333
using namespace std;
char s[xxx];
int len,p;
long long l,r;

int main()
{
	scanf("%s",s+1);
	len=strlen(s+1);
	for (int i=1;i<=len;i++)
		if (s[i]=='^')
			p=i;
	for (long long i=p-1;i>0;i--)
	{
		if (s[i]>='1'&&s[i]<='9')
		{
			l+=(long long)(p-i)*(s[i]-'0');
		}
	}
	for (long long i=p+1;i<=len;i++)
	{
		if (s[i]>='1'&&s[i]<='9')
		{
			r+=(long long)(i-p)*(s[i]-'0');
		}
	}
	if (l==r) printf("balance");
	else if (l>r) printf("left");
	else printf("right");
	return 0;
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
#include<cstring>
#define xxx 1100
using namespace std;
int n,m,tot[xxx]={0};

int abss(int x)
{
	return x>0?x:-x;
}

int main()
{
	int a,b,c,ans;
	scanf("%d%d",&n,&m);
	for (int i=1;i<=m;i++)
	{
		scanf("%d%d%d",&a,&b,&c);
		tot[a]-=c;
		tot[b]+=c;
	}
	ans=0;
	for (int i=1;i<=n;i++)
	{
		ans+=abss(tot[i]);
	}
	ans/=2;
	printf("%d",ans);
	return 0;
}
```
***** 

## C
### Problem description
> 给一个大数，其位数>=4，其中必含1,6,8,9四个数字。。
> 求重新排列成一个7的倍数。。

### Solution
仔细yy，先处理除了1,6,8,9以外的数，剩下打表。。

```cpp
#include<cstdio>
#include<cstring>
using namespace std;
int l,tot[11]={0};
char s[5202333];

void pri(int x)
{
	if (x==0) printf("1869");
	if (x==1) printf("1968");
	if (x==2) printf("8619");
	if (x==3) printf("6198");
	if (x==4) printf("8691");
	if (x==5) printf("8916");
	if (x==6) printf("8196");
}

int main()
{
	scanf("%s",s);
	l=strlen(s);
	for (int i=0;i<l;i++)
		tot[s[i]-'0']++;
	if (tot[0]==l-4)
	{
		pri(0);
		for (int i=1;i<=tot[0];i++)
			printf("0");
		return 0;
	}
	tot[1]--;tot[6]--;tot[8]--;tot[9]--;
	int mod=0;
	for (int i=9;i>=0;i--)
	{
		if (tot[i]>0)
		{
			for (int j=1;j<=tot[i];j++)
			{
				printf("%d",i);
				mod=(mod*10+i)%7;
			}
		}
	}
	mod=(mod*10000)%7;
	pri(mod==0?0:7-mod);
	return 0;
}
```
***** 

## D
### Problem description
> 求随意打乱行的顺序后的最大子矩阵的最大值。。
### Solution
枚举每一列。。统计出每一行从该列开始向右最远连续的'1'。。

基数排序一下就好。。（自行yy！。。）
```cpp
#include<cstdio>
#include<iostream>
#include<cstring>
#define xxx 5010
using namespace std;
int n,m,a[xxx][xxx],f[xxx],ans;
char s[xxx<<1];

void doit()
{
	int tot=0;
	for (int i=m;i>0;i--)
	{
		tot+=f[i];
		ans=max(ans,tot*i);
	}
}

int main()
{
	scanf("%d%d\n",&n,&m);
	for (int i=1;i<=n;i++)
	{
		scanf("%s",s);
		for (int j=0;j<m;j++)
			a[i][j+1]=s[j]-'0';
		for (int j=m-1;j>=1;j--)
			if (a[i][j]&&a[i][j+1])
				a[i][j]=a[i][j+1]+1;
	}
	for (int j=1;j<=m;j++)
	{
		memset(f,0,sizeof(f));
		for (int i=1;i<=n;i++)
			f[a[i][j]]++;
		doit();
	}
	printf("%d",ans);
	return 0;
}

```
***** 

## E
### Problem description
> 从给定点出发，回到出发点。。
> 限制：只能上下左右走。。不能出界或撞墙（撞宝藏也不行啊）。。不能围炸弹。。
> 最大化：所有围住的宝藏的权值和 - 走的步数
  
### Solution
撞鸭dp（好吧。。或者说叫记忆化广搜。。）

记录到达每种状态的最少步数。。最后再统计就好了

```cpp
#include<cstdio>
#include<iostream>
#include<cstring>
#include<vector>
#include<queue>
#define xxx 23
using namespace std;
struct bomb{
	int bx,by;
};
vector<bomb>bb;
int n,m,q[22][22][555],inf,f[22][22],v[10],vx[10],vy[10],tot,vt;
int stx,sty;

struct zt{
	int x,y,z;
}tem;
queue<zt>p;

int in(int i,int j)
{
	char c;
	while (1)
	{
		c=getchar();
		if (c=='.') return 0;
		if (c=='#') return 1;
		if (c=='S')
		{
			stx=i;
			sty=j;
			return 0;
		}
		if (c>='1'&&c<='8')
		{
			vx[c-'0']=i;
			vy[c-'0']=j;
			tot=max(tot,(int)(c-'0'));
			return 1;
		}
		if (c=='B')
		{
			bb.push_back((bomb){i,j});
			return 1; 
		}
	}
}

int dx[4]={1,-1,0,0},dy[4]={0,0,1,-1};

int main()
{
	memset(f,1,sizeof(f));
	memset(q,-2,sizeof(q));
	inf=q[0][0][0];
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++)
		for (int j=1;j<=m;j++)
			f[i][j]=in(i,j);
	if (0)
	{
		for (int i=1;i<=n;i++)
		{
			for (int j=1;j<=m;j++)
				printf("%d",f[i][j]);
			printf("\n");
		}	
	}
	for (int i=1;i<=tot;i++)
		scanf("%d",&v[i]);
	vt=tot;
	for (int i=0;i<bb.size();i++)
	{
		tot++;
		vx[tot]=bb[i].bx;
		vy[tot]=bb[i].by;
		v[tot]=inf;
	}
	if (0)
	{
		printf("%d:\n",tot);
		for (int i=1;i<=tot;i++)
			printf("%d %d %d\n",vx[i],vy[i],v[i]);	
	}
	
	q[stx][sty][0]=0;
	p.push((zt){stx,sty,0});
	zt u,w;
	int low;
	while (!p.empty())
	{
		u=p.front();
		p.pop();
		//printf("%d %d %d %d\n",u.x,u.y,u.z,q[u.x][u.y][u.z]);scanf("%d",&v[9]);
		for (int dir=0;dir<4;dir++)
		{
			w.x=u.x+dx[dir];
			w.y=u.y+dy[dir];
			if (f[w.x][w.y]) continue;
			w.z=u.z;
			if (u.y!=w.y)
			{
				low=min(u.y,w.y);
				for (int i=1;i<=tot;i++)
				{
					if (vy[i]==low&&vx[i]<w.x)
						w.z=w.z^(1<<(i-1));
				}
			}
			if (q[w.x][w.y][w.z]==inf)
			{
				q[w.x][w.y][w.z]=q[u.x][u.y][u.z]-1;
				p.push(w);
			}
		}
	}
	int ans=0,an;
	for (int i=0;i<(1<<tot);i++)
	{
		//printf("%d %d\n",i,q[stx][sty][i]);
		an=q[stx][sty][i];
		for (int j=1;j<=tot;j++)
		{
			if (i&(1<<(j-1)))
				an+=v[j];
		}
		ans=max(ans,an);
	}
	printf("%d\n",ans);
	return 0;
}
```
***** 

## F
### Problem description
> 给出一个每个节点都有颜色的有根树。。
> 询问：以v为根的子树中（含根），有多少种颜色，满足颜色为该颜色的节点数>=k。。
  
### Solution

树转区间+莫队。。

```cpp
#include<cstdio>
#include<iostream>
#include<cmath>
#include<vector>
#include<algorithm>
#include<cstring>
#define xxx 100100
#define yyy 100100
#define ll long long
using namespace std;
int a[xxx],n,m,c[xxx],st[xxx],en[xxx],dft=0,ans[xxx];
vector<int>r[xxx];
int bel[xxx],siz,tot;
struct que{
	int aa,bb,cc,p;
}q[xxx];

void dfs(int x,int fa)
{
	st[x]=++dft;
	a[dft]=c[x];
	for (int i=0;i<r[x].size();i++)
		if (r[x][i]!=fa)
			dfs(r[x][i],x);
	en[x]=dft;
}

bool cmp(que q1,que q2)
{
	return bel[q1.aa]!=bel[q2.aa]?bel[q1.aa]<bel[q2.aa]:q1.bb<q2.bb;
}

int sma=0,big=0;
int cnt[xxx],flbl[400],cc[xxx];

void add(int v)
{
	cc[v]++;
	cnt[cc[v]]++;
}

void del(int v)
{
	cnt[cc[v]]--;
	cc[v]--;
}

int main()
{
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++)
		scanf("%d",&c[i]);
	int u,v,w;
	for (int i=1;i<n;i++)
	{
		scanf("%d%d",&u,&v);
		r[u].push_back(v);
		r[v].push_back(u);
	}
	dfs(1,0);
	
	siz=sqrt(n);
	for (int i=1;i<=n;i++)
		bel[i]=(i-1)/siz+1;
	tot=bel[n];
	
	for (int i=1;i<=m;i++)
	{
		scanf("%d%d",&u,&v);
		q[i].aa=st[u];
		q[i].bb=en[u];
		q[i].cc=v;
		q[i].p=i;
	}
	sort(q+1,q+m+1,cmp);
	
	for (int i=1;i<=m;i++)
	{
		if (!flbl[bel[q[i].aa]])
		{
			flbl[bel[q[i].aa]]=1;
			memset(cnt,0,sizeof(cnt));
			memset(cc,0,sizeof(cc));
			sma=big=q[i].aa;
			big--;
			while (big<q[i].bb)
			{
				add(a[big+1]);
				big++;
			}
		}
		else
		{
			if (sma>q[i].aa)
			{
				while (sma>q[i].aa)
				{
					add(a[sma-1]);
					sma--;
				}
			}
			
			if (big<q[i].bb)
			{
				while (big<q[i].bb)
				{
					add(a[big+1]);
					big++;
				}
			}
			
			if (big>q[i].bb)
			{
				while (big>q[i].bb)
				{
					del(a[big]);
					big--;
				}
			}
			
			if (sma<q[i].aa)
			{
				while (sma<q[i].aa)
				{
					del(a[sma]);
					sma++;
				}
			}
			
		}
		ans[q[i].p]=cnt[q[i].cc];
	}
	
	for (int i=1;i<=m;i++)
		printf("%d\n",ans[i]);
	return 0;
}

```
***** 

## G
### Problem description
> 给出一棵有边权的树。。树上每个节点均为红色或黑色。。
> 目标：每个红点在距离x内有黑点。。
> 可用操作：交换两点颜色。。
> 最小化：达到目标的操作次数。。

### Solution
tree dp。。

定义“u控制v”意为最终状态下红点v到黑点u的距离<=x。。

f[i,j,k]表示以i为根的子树中，

使得所有非根节点都被控制（可以被k）且根节点被k节点控制的方案中，

恰用了j个黑点（不含k）的最少操作次数（即红变黑）。。

```cpp
#include<cstdio>
#include<iostream>
#include<vector>
#include<cstring>
#define xxx 501
#define debug 0
using namespace std;
short f[xxx][xxx][xxx],be[xxx][xxx]; 
int ww[xxx],cnt=0,n,siz[xxx];
long long dd,d[xxx][xxx];
struct R{
	int to,was;
};
vector<R>r[xxx];
vector<int>ch[xxx];

void dis(int root,int x,int fa,long long t)
{
	d[root][x]=t;
	for (int i=0;i<r[x].size();i++)
		if (r[x][i].to!=fa)
			dis(root,r[x][i].to,x,t+(long long)r[x][i].was);
	return;
}

short tem[xxx];
void dfs(int x,int fa)
{
	siz[x]=1;
	for (int i=0;i<r[x].size();i++)
	{
		if (r[x][i].to!=fa)
		{
			dfs(r[x][i].to,x);
			siz[x]+=siz[r[x][i].to];
			ch[x].push_back(r[x][i].to); 
		}
	}
	if (debug) printf("%d %d %d\n",x,fa,siz[x]);
	int s,y,chsiz=ch[x].size();
	for (int i=1;i<=n;i++)
	{
		if (d[x][i]>dd) continue;
		for (int a=0;a<=siz[x];a++)
			tem[a]=520;
		tem[0]=tem[1]=0;
		s=1;
		for (int t=0;t<chsiz;t++)
		{
			y=ch[x][t];
			//背包貌似一维的更好写？。。 
			for (int a=min(s+siz[y],cnt);a>=0;a--)
			{
				short realtem=520;
				for (int b=max(0,a-s);b<=min(siz[y],a);b++)
				{
					realtem=min(realtem,(short)(tem[a-b]+f[y][b][i]));
					realtem=min(realtem,(short)(tem[a-b]+be[y][b]));
				}
				tem[a]=realtem;
			}
			s+=siz[y];
		}
		for (int a=0;a<=s;a++)
			f[x][a][i]=tem[a];
	}
	for (int a=0;a<siz[x];a++)
	{
		be[x][a+1]=520;
		for (int i=1;i<=n;i++)
			if (d[x][i]<=dd)
				be[x][a+1]=min(be[x][a+1],(short)(f[x][a][i]+ww[i]));
	}
	if (debug)
	{
		printf("%d:\n",x);
		for (int a=0;a<=s;a++)
		{
			printf("%d:",a);
	 		for (int i=1;i<=n;i++)cout<<" ("<<i<<")"<<f[x][a][i];
			cout<<"  best:"<<be[x][a]<<endl;
		}
	}
}

int main()
{
	memset(f,5,sizeof(f));
	memset(be,5,sizeof(be));
	scanf("%d%d",&n,&dd);
	for (int i=1;i<=n;i++)
	{
		scanf("%d",&ww[i]);
		cnt+=ww[i];
		ww[i]^=1;
	}
	int u,v,w;
	for (int i=1;i<n;i++)
	{
		scanf("%d%d%d",&u,&v,&w);
		r[u].push_back((R){v,w});
		r[v].push_back((R){u,w});
	}
	for (int i=1;i<=n;i++)
		dis(i,i,0,(long long)0);
	if (debug){
		for (int i=1;i<=n;i++){for (int j=1;j<=n;j++) printf("%d ",d[i][j]);printf("\n");}
	}
	dfs(1,0);
	be[1][cnt] = be[1][cnt]>=520?-1:be[1][cnt];
	cout<<be[1][cnt]<<endl;
	return 0;
}
```
