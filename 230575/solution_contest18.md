[比赛链接](https://cn.vjudge.net/contest/172100)

# 比赛中解决的问题
## A
### Problem description
> 给一张长为a，宽为b的桌子。设有无数张半径为r的圆形纸片。有两个人在桌子上放纸片，之前已放好的纸片不能挪动位置，纸片在放的时候不能相交但可以外切且不能超过桌子的边界，谁放不了谁就输了。问先手者是否可以必胜，若是输出“First”，否则输出“Second”。

### Data Limit:1≤a,b,r≤100  Time Limit:2s

### Solution
> 按题意模拟。若圆的直径2×r>a或2×r>b，则不能放纸片，输出“Second”，否则若可以放下一个纸片，我们可以得出分析：当先手者把第一张纸片的圆心放在桌子的重心上，那么接下来无论后手者将纸片放在什么位置上，先手者都可以找到一个以第一个圆的圆心为对称中心，与后手者放的圆对称的位置。所以若能放纸片，则先手必胜，输出“First”。

### Code
```cpp
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
int a,b,r;
int main()
{
	scanf("%d%d%d",&a,&b,&r);
	if (2*r>a||2*r>b) printf("Second\n");
	else printf("First\n");
	return 0;
}
```
*****


## B
### Problem description
> 给出整数n，m，构造两个方程P(x)=a[0]·x^n+a[1]·x^n-1+...+a[n-1]·x+a[n]和Q(x)=b[0]·x^m+b[1]·x^m-1+...+b[m-1]·x+b[m]。求当x的值趋于无穷大时P(x)/Q(x)的值。

### Data Limit:0≤n,m≤100,-100≤ai,bi≤100,a0≠0,b0≠0  Time Limit:2s

### Solution
> 数学分析题。若n<m，则函数值无穷趋近于0，按题目要求输出“0/1”。若n=m，则输出a[0]/b[0]约分后的分数。若n>m，则判断a[0]*b[0]的正负性，若为负先输出负号，再输出“Infinity”即可。

### Code
```cpp
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
int n,m,a[105],b[105];
int gcd(int x,int y)
{
	if (y==0) return x;
	return gcd(y,x%y);
}
int main()
{
	memset(a,0,sizeof(a));
	memset(b,0,sizeof(b));
	scanf("%d%d",&n,&m);
	for (int i=0;i<=n;++i)
	scanf("%d",&a[i]);
	for (int i=0;i<=m;++i)
	scanf("%d",&b[i]);
	if (n<m)
	{
		printf("0/1\n");
		return 0;
	}
	if (n==m)
	{
		if (a[0]*b[0]<0) printf("-");
		a[0]=abs(a[0]);
		b[0]=abs(b[0]);
		int t=gcd(a[0],b[0]);
		printf("%d/%d\n",a[0]/t,b[0]/t);
	}
	if (n>m)
	{
		if (a[0]*b[0]<0) printf("-");
		printf("Infinity");
	}
	return 0;
}
```
*****


## C
### Problem description
> 给一个字符串，从字符串中找出一个可不连续但是必须按顺序的子串，使得子串的字典序最大。输出该子串。

### Data Limit:字符串长度<=1e5  Time Limit:2s

### Solution
> 贪心。按字母z到a的顺序搜索字符串。当字母为z时开始从前往后找，若找到z则输出，并将位置标记在此处。这样我们输出所有z后，找y就从标记z的最后一处开始找......以此类推可以得到字典序最大的子串。

### Code
```cpp
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
char s[100005];
int a[27];
int main()
{
	scanf("%s",s);
	int len=strlen(s);
	memset(a,0,sizeof(a));
	for (int i=25;i>=0;--i)
	{
		for (int j=a[i+1];j<len;++j)
		if (s[j]==i+'a')
		{
			printf("%c",s[j]);
			a[i]=j;
		}
		a[i]=max(a[i],a[i+1]);
	}
	return 0;
}
```
*****


## D
### Problem description
> 给定一个n×m的地图，“#”表示墙，不能走，“S”表示出发起点，“.”表示道路。现在将地图无限复制并贴合在一起，问是否能从一张小地图处的S走到另一张小地图处的S，若可以输出“Yes”，否则输出“No”。

### Data Limit:1≤n,m≤1500  Time Limit:2s

### Solution
> BFS。将原地图复制，长扩大到原来的2倍，宽也扩大到原来的2倍，即得到4份相连的和原来一模一样的地图((2×n)×(2×m))。然后BFS遍历图，若从一处的S到了另一处的S则输出“Yes”。否则若整张图遍历完也未遇到另一处的S，则输出“No”。

### Code
```cpp
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<queue>
using namespace std;
struct node{
	int x,y;
};
queue<node>Q;
int n,m,sx,sy;
char s[3005][3005];
bool vis[3005][3005];
int dx[4]={-1,1,0,0},dy[4]={0,0,-1,1};
int main()
{
	scanf("%d%d",&n,&m);
	gets(s[0]);
	memset(vis,0,sizeof(vis));
	for (int i=0;i<n;++i)
	{
		gets(s[i]);
		for (int j=0;j<m;++j)
		if (s[i][j]=='S')
		{
			node a;
			a.x=sx=i;
			a.y=sy=j;
			Q.push(a);
			vis[i][j]=1;
		}
	}
	for (int i=0;i<n;++i)
	for (int j=0;j<m;++j)
	s[i][j+m]=s[i][j];
	for (int i=0;i<n;++i)
	for (int j=0;j<2*m;++j)
	s[i+n][j]=s[i][j];
	while (!Q.empty())
	{
		node a,b;
		a=Q.front();
		Q.pop();
		for (int i=0;i<4;++i)
		{
			int x=a.x+dx[i];
			int y=a.y+dy[i];
			if (x<0) x+=2*n;
			if (y<0) y+=2*m;
			if (x>=2*n) x-=2*n;
			if (y>=2*m) y-=2*m;
			if ((x!=sx||y!=sy)&&x%n==sx&&y%m==sy)
			{
				printf("Yes\n");
				return 0;
			}
			if (!vis[x][y]&&s[x][y]!='#')
			{
				b.x=x;
		    	b.y=y;
		    	vis[x][y]=1;
		    	Q.push(b);
		  	}
		}
	}
	printf("No\n");
	return 0;
}
```
*****

# 赛后补题

## E
### Problem description
> 给出一棵有n个节点的树，描述其相连的(n-1)条边的两个端点。再给出这n个点的坐标。题目保证没有三点共线。已知这n个点的顺序已不确认，请给这些点重新编号,使得该树成立，线段除了顶点处无其他交点。

### Data Limit:1≤n≤1500  Time Limit:2s

### Solution
> 计算几何和DFS。该题为极角排序。我们考虑以当前平面左下角的点p作为树根，对平面上的点以p做基准进行极角排序，则所有点与p点的连线都不会有除了p以外的交点。现在我们已经会填树根处的点了，对于树根的每个子节点，我们都可以递归的处理以其为根的子树，假设该子树包含x个节点，我们考虑以一根从p出发，长度不限的射线，从p的正下方开始按逆时针扫过去，直到扫过的平面包含x个节点即可停止。此时扫过的平面即为该子树应当处理的平面。每次处理需要先找到左下角的点，然后对当前平面的所有点进行排序。

### Code
```cpp
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
struct point{
	int x,y,num;
}p[3005];
int a,b,n,cnt=0,size[3005],next[3005],h[3005],toit[3005],ans[3005];
bool cmp(point a,point b){
	long long t=(long long)a.x*(long long)b.y-(long long)a.y*(long long)b.x;
	return t>0;
}
void add(int x,int y)
{
	next[++cnt]=h[x];
	h[x]=cnt;
	toit[cnt]=y;
}
void dfs1(int x)
{
	size[x]=1;
	for (int i=h[x];i;i=next[i])
	if (size[toit[i]]==0)
	{
		dfs1(toit[i]);
		size[x]+=size[toit[i]];
	}
}
void dfs2(int root,int l,int r)
{
	if (l>r) return;
	point choose=p[l];
	int used=l;
	for (int i=l;i<=r;++i)
	if (p[i].y<choose.y)
	{
		choose=p[i];
		used=i;
	}
	ans[choose.num]=root;
	swap(p[used],p[l]);
	if (l==r) return;
	for (int i=l+1;i<=r;i++)
	{
		p[i].x-=p[l].x;
		p[i].y-=p[l].y;
	}
	sort(p+l+1,p+r+1,cmp);
	int now=l+1;
	for (int i=h[root];i;i=next[i])
	if (size[toit[i]]<size[root])
	{
		dfs2(toit[i],now,now+size[toit[i]]-1);
		now+=size[toit[i]];
	}
}
int main()
{
	scanf("%d",&n);
	for (int i=1;i<n;++i)
	{
		scanf("%d%d",&a,&b);
		add(a,b);
		add(b,a);
	}
	dfs1(1);
    for (int i=1;i<=n;++i)
	{
		scanf("%d%d",&p[i].x,&p[i].y);
		p[i].num=i;
	}
	dfs2(1,1,n);
	for (int i=1;i<=n;++i)
	printf("%d ",ans[i]);
	return 0;
}
```
*****


## F
### Problem description
> 给定n个点，m条边，再给出k个有传送门的点，若一个点已经经过一次且上面有传送门，则传送门可打开。若有两个点上面有传送门且传送门都打开，则可以直接在这两个点上瞬间移动。问遍历所有点至少需要经过多少长度的路径。

### Data Limit:1≤n≤1e5,0≤m≤1e5,1≤k≤n  Time Limit:2s

### Solution
> 首先根据传送门的性质，如果所有点都是传送门的话那么结果就是该图的最小生成树。对于只有其中k个结点是传送门的图，只要在原算法的基础上稍作修改即可。具体，对每个点求出P[i]和D[i]（表示距离这个点最近的传送门和其距离）。之后对每条边，再根据D[x]+D[y]+w作为关键字跑最小生成树。以上分别用最短路和稍作修改的克鲁斯卡尔求最小生成树即可。

### Code
```cpp
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<queue>
#define maxn 200005
using namespace std;
struct edge{
	int u,v;
	long long c;
}e[maxn];
int n,m,k,u,v,y[maxn],next[maxn],fir[maxn],fa[maxn],p[maxn],tot=1;
long long d[maxn],w[maxn],c,ans;
bool vis[maxn];
priority_queue< pair<long long,int> >Q;
bool cmp(edge a,edge b){
	return a.c<b.c;
}
int find(int x)
{
	return fa[x]==x?x:fa[x]=find(fa[x]);
}
void add(int u,int v,long long c)
{
	y[tot]=v;
	next[tot]=fir[u];
	w[tot]=c;
	fir[u]=tot++;
}
int main()
{
	scanf("%d%d",&n,&m);
	for (int i=1;i<=m;++i)
	{
		scanf("%d%d%I64d",&u,&v,&c);
		e[i]=(edge){u,v,c};
		add(u,v,c);
		add(v,u,c);
	}
	memset(d,50,sizeof(d));
	scanf("%d",&k);
	for (int i=1;i<=k;++i)
	{
		scanf("%d",&u);
		d[u]=0;
		p[u]=u;
		Q.push(make_pair(0,u));
	}
	while (Q.size())
	{
		while (vis[u=Q.top().second]&&Q.size()) Q.pop();
		if (Q.empty()) break;
		vis[u]=1;
		Q.pop();
		for (int i=fir[u];i;i=next[i])
		if (d[u]+w[i]<d[y[i]])
		{
			d[y[i]]=d[u]+w[i];
			p[y[i]]=p[u];
			Q.push(make_pair(-d[y[i]],y[i]));
		}
	}
	for (int i=1;i<=m;++i)
	{
		e[i].c+=d[e[i].u]+d[e[i].v];
		e[i]=(edge){p[e[i].u],p[e[i].v],e[i].c};
	}
	sort(e+1,e+m+1,cmp);
	for (int i=1;i<=n;++i)
	fa[i]=i;
	for (int i=1;i<=m;++i)
	if (find(e[i].u)!=find(e[i].v))
	{
		fa[fa[e[i].u]]=fa[e[i].v];
		ans+=e[i].c;
	}
	printf("%I64d",ans+d[1]);
	return 0;
}
```
