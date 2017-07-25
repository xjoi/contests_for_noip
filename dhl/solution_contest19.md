ABC 不想写..
# D
### 数据范围=1e5
## 题意,给定一些点的值的度,以及每一个点的颜色,让你构造一颗树满足题意,黑色的点不能和白色点相连,输出树的构造.
## 题解:
> 首先我们可以发现一个美妙的性质,对于一个节点,与他消去的一定是和他节点颜色不同的点,于是我们随便消一下就行了,构造两个指针扫一遍就行了.
## 贪心的证明,我们每一次至少有一个节点值为0,总共n个点,进行n-1次操作,于是最后构造出来的树,一定是满足n-1跳边.
> 我之前的解法,是对节点的度进行排序,后来发现不进行排序也是可行的,于是就过了..
## 代码
```cpp
#include<bits/stdc++.h>
#define P pair<int,int>
#define W first
#define ID second
using namespace std;
int n;
P p[2][300000];
int main()
{
	cin>>n;
	for(int i=1,c,w;i<=n;i++)
		scanf("%d%d",&c,&w),p[c][++p[c][0].W]=P(w,i);
	//sort(p[0]+1,p[0]+p[0][0].W+1);
	//sort(p[1]+1,p[1]+p[1][0].W+1);
	for(int i=1,j=1;i<=p[0][0].W,j<=p[1][0].W;)
	{
		int Min=min(p[0][i].W,p[1][j].W);
		printf("%d %d %d\n",p[0][i].ID,p[1][j].ID,Min);
		p[0][i].W-=Min,p[1][j].W-=Min;
		if(p[0][i].W) j++;
		else if(p[1][j].W) i++;
		else i<p[0][0].W?i++:j++;
	}
	return 0;
	
}
```

# E
## 题意,给定若干个点的坐标,让你用4条线分成井字形的9个部分,并且满足要求.
## 题解
>首先数据范围好大好大我们先进行离散化,然后我们对x排序之后,以y坐标建立若干颗线段树,也就是主席树.然后我们暴力枚举9!中排列方案
>每次利用o1的时间确定两个垂直于x轴的线,并且根据在主席树上做差,最后看是否满足,也就是判断这个点和他的下一个点是否存在一个共线的情况
### 时间复杂度nlgn+9!*lgn,空间复杂度nlgn
>于是就解决了这个问题,还是比较巧妙地
### 代码
```cpp
#include<bits/stdc++.h>
#define mid (l+(r-l)/2)
using namespace std;
const int inf=1e10,N=110000;

struct tree
{
	int lc,rc,sz;int l,r;
}tr[N<<5],nul;
int cnt=0,n,b[N],a[N],c[N],ok=0,s[N],tox[N],toy[N],root[N];
struct XY{int x,y,rx,ry;}p[N];
bool cmp_x(XY x,XY y){return x.x<y.x;}
bool cmp_y(XY x,XY y){return x.y<y.y;}

int newnode(){tr[++cnt]=nul;return cnt;}

void build(int now,int pre,int l,int r,int add)
{
	tr[now].sz=tr[pre].sz+1;tr[now].l=l,tr[now].r=r;
	if(l==r) return ;
	if(add<=mid)
	{
		tr[now].rc=tr[pre].rc,tr[now].lc=newnode();
		build(tr[now].lc,tr[pre].lc,l,mid,add);
	}
	else
	{
		tr[now].lc=tr[pre].lc,tr[now].rc=newnode();
		build(tr[now].rc,tr[pre].rc,mid+1,r,add);
	}
}

int query(int now,int pre,int v)
{
	if(tr[now].l==tr[now].r) return tr[now].l;
	int sum=tr[tr[now].lc].sz-tr[tr[pre].lc].sz;
	if(v<=sum) return query(tr[now].lc,tr[pre].lc,v);
	else return query(tr[now].rc,tr[pre].rc,v-sum);
}

void solve()
{
	int in,ax,y1,y2,pos1,pos2;
	s[0]=0,s[1]=b[1]+b[4]+b[7],s[2]=s[1]+b[2]+b[5]+b[8],s[3]=n;
	if((tox[s[1]]==tox[s[1]+1])||tox[s[2]]==tox[s[2]+1]) return ;
	//cout<<"233";
	in=-inf,ax=inf;
	for(int i=1;i<=3;i++)
	{
		pos1=query(root[s[i]],root[s[i-1]],b[i]);
		pos2=query(root[s[i]],root[s[i-1]],b[i]+1);
		in=max(in,toy[pos1]),ax=min(ax,toy[pos2]);
		if(in>=ax) return ;
	}
	y1=in;
	in=-inf,ax=inf;
	for(int i=1;i<=3;i++)
	{
		pos1=query(root[s[i]],root[s[i-1]],b[i]+b[i+3]);
		pos2=query(root[s[i]],root[s[i-1]],b[i]+1+b[i+3]);
		in=max(in,toy[pos1]),ax=min(ax,toy[pos2]);
		if(in>=ax) return ;
	}
	y2=in;
	ok=1;
	printf("%.6f %.6f\n%.6f %.6f\n",(double)tox[s[1]]+0.5,(double)tox[s[2]]+0.5,(double)y1+0.5,(double)y2+0.5);
}

signed main()
{
	cin>>n;
	for(int i=1;i<=n;i++) scanf("%d%d",&p[i].x,&p[i].y);
	sort(p+1,p+n+1,cmp_y);
	for(int i=1;i<=n;i++) p[i].ry=i,toy[i]=p[i].y;
	sort(p+1,p+n+1,cmp_x);
	for(int i=1;i<=n;i++) p[i].rx=i,tox[i]=p[i].x;
	for(int i=1;i<=9;i++) scanf("%d",&a[i]),c[i]=i;
	nul.lc=nul.rc=nul.sz=0;tr[0]=nul,root[0]=0;
	for(int i=1;i<=n;i++) root[i]=newnode(),build(root[i],root[i-1],1,n,p[i].ry);
	for(int i=1;i<=362880&&!ok;i++)
	{
		for(int j=1;j<=9;j++) b[j]=a[c[j]];
		solve();
		next_permutation(c+1,c+9+1);
	}
	if(!ok) puts("-1");
	return 0;
}
```
## 还有一种线段树的做法。
```cpp
#include<bits/stdc++.h>
#define mid (l+(r-l)/2)
#define N 110000
#define ls (rt<<1)
#define rs (rt<<1|1)
using namespace std;
vector<int> v[N<<2];
int a[N],b[N],c[N],ok=0,n,sx[N],sy[N],fx[N],fy[N],x[N],y[N];
struct P{int x,y;}p[N];
bool cmp(P a,P b){return a.x<b.x;}

void build(int l,int r,int rt)
{
	for(int i=l;i<=r;i++) v[rt].push_back(p[i].y);
	if(l==r) return ;
	sort(v[rt].begin(),v[rt].end());
	build(l,mid,ls),build(mid+1,r,rs);
}

int q(int x,int y,int l,int r,int rt)
{
	if(p[l].x>x) return 0;
	if(p[r].x<=x) return upper_bound(v[rt].begin(),v[rt].end(),y)-v[rt].begin();
	return q(x,y,l,mid,ls)+q(x,y,mid+1,r,rs);
}

void solve()
{
	sx[1]=b[1]+b[4]+b[7],sx[2]=sx[1]+b[2]+b[5]+b[8];
	sy[1]=b[1]+b[2]+b[3],sy[2]=sy[1]+b[4]+b[5]+b[6];
	for(int i=1;i<=2;i++)
		if(x[sx[i]]==x[sx[i]+1]||y[sy[i]]==y[sy[i]+1])return ;
	for(int i=1;i<=2;i++)
		fx[i]=x[sx[i]],fy[i]=y[sy[i]];
	if(q(fx[1],fy[1],1,n,1)!=b[1]
	||q(fx[1],fy[2],1,n,1)!=b[1]+b[4]
	||q(fx[2],fy[1],1,n,1)!=b[1]+b[2]
	||q(fx[2],fy[2],1,n,1)!=b[1]+b[2]+b[4]+b[5]) return ;
	ok=1;
	printf("%.8f %.8f\n%.8f %.8f",(double)fx[1]+0.5,(double)fx[2]+0.5,(double)fy[1]+0.5,(double)fy[2]+0.5);
}

main()
{
	cin>>n;
	for(int i=1;i<=n;i++) 
		scanf("%d%d",&p[i].x,&p[i].y),x[i]=p[i].x,y[i]=p[i].y;
	sort(p+1,p+n+1,cmp),sort(x+1,x+n+1);sort(y+1,y+n+1);
	for(int i=1;i<=9;i++) scanf("%d",&a[i]),c[i]=i;
	build(1,n,1);
	for(int i=1;i<=362880&&!ok;i++)
	{
		for(int j=1;j<=9;j++) b[j]=a[c[j]];
		solve();
		next_permutation(c+1,c+9+1);
	}
	if(!ok) puts("-1");
	return 0;
}
````
