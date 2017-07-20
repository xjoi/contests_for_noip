# 比赛记录

[比赛链接div2](http://codeforces.com/contest/197)
[比赛链接div1](http://codeforces.com/contest/196)

## div2:A
### Problem description
> A和B轮流在a\*b的矩形里放置不重叠的半径为r的圆形,求最后是先手赢还是后手赢(a,b,r<=100)
### Solution
加入矩形连一个圆形都放不下,那么显然是后手赢;除此之外,先手都可以把圆形放正中间,然后只要相对称的与后手放就能保证必胜
```cpp
#include<cstdio>
int a,b,r;
int main(){
	scanf("%d%d%d",&a,&b,&r);
	return (a>=2*r&&b>=2*r)?puts("First"):puts("Second"),0;
}
```

## div 2:B
### Problem description
> 求n次多项式(可能最高次项系数为0)/m次多项式(可能最高次项系数为0)的极限(n,m<=100)
### Solution
分类讨论
```cpp
#include<cstdio>
#include<algorithm>
using namespace std;
int gcd(int c,int y){
	return y==0?c:gcd(y,c%y);
}
int n,m,a[10000],b[10000],w;
int main(){
	scanf("%d%d",&n,&m);
	for(int i=0;i<=n;i++)scanf("%d",&a[i]);
	for(int i=0;i<=m;i++)scanf("%d",&b[i]);
	int i=0,j=0;
	while(a[i]==0)i++;
	while(a[j]==0)j++;
	if(n-i==m-j){
		w=(a[i]<0)^(b[j]<0);
		a[i]=abs(a[j]);
		b[i]=abs(b[j]);
		int g=gcd(a[i],b[j]);
		if(w)printf("-%d/%d",a[i]/g,b[j]/g);else printf("%d/%d",a[i]/g,b[j]/g);
		return 0;
	}
	if(n-i>m-j){
		w=(a[i]<0)^(b[j]<0);
		if(w)printf("-Infinity");
		else printf("Infinity");
		return 0;
	}
	if(n-i<m-j){
		printf("0/1");
		return 0;
	}
}
```

## div 2:C
### Problem description
> 给你n个小写英文字符,求字典序最大的子序列(n<=10^5)
### Solution
由字典序的定义可得,最大的字典序子序列一定是全部'z'+在最后一个'z'后面的'y'+...
```cpp
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<string>
#include<iostream>
using namespace std;
string ans;
char s[1000100];
int main(){
	scanf("%s",s);
	int n=strlen(s);int j=0;
	for(int i='z';i>='a';i--){
		for(int k=j;k<n;k++)if(s[k]==i){
			ans=ans+s[k];
		    j=k;
	    }
	}
	cout << ans;
	return 0;
}
```


## div 2:D
### Problem description
> 给你一个n\*m的矩阵,矩阵里面的点分为可以走和不能走两种,给出起点,且矩阵可以无限次复制再拼接(不能旋转),求能否走到无限远处(n,m<=1500)
### Solution
搜索即可,对于每一个点,我们记录四个信息,它在原矩阵中的位置x,y和它所在的复制图的位置mapx,mapy;显然可以得到当在两个不同的复制图中走到原矩阵同一个点时,我们就可以一直走循环以到无限远,所以输出'Yes';反之则'No';
```cpp
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<queue>
#include<string>
using namespace std;
int v[2000][2000],n,m,a[2000][2000],o,h,t;
pair<int,int>map[2000][2000];
int dx[4]={-1,1,0,0};
int dy[4]={0,0,-1,1};
char s[2000];
struct Point{
	int x,y,mapx,mapy;
	Point(int x=0,int y=0,int mapx=0,int mapy=0):x(x),y(y),mapx(mapx),mapy(mapy){};
};
queue<Point>q;
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%s",s);
		for(int j=0;j<m;j++){
	    	if(s[j]=='S')q.push(Point(i,j+1,0,0));
	    	a[i][j+1]=s[j]=='#'?2:1;	
		}
	}
	while(!q.empty()){
		Point now=q.front();q.pop();
		//printf("%d %d %d %d\n",now.x,now.y,now.mapx,now.mapy);
		for(int i=0;i<4;i++){
		    Point nxt=Point(now.x+dx[i],now.y+dy[i],now.mapx,now.mapy);
			if(!nxt.x)nxt.x=n,nxt.mapx--;
			if(!nxt.y)nxt.y=m,nxt.mapy--;
            if(nxt.x>n)nxt.x=1,nxt.mapx++;
            if(nxt.y>m)nxt.y=1,nxt.mapy++;
            if(v[nxt.x][nxt.y]&&(map[nxt.x][nxt.y].first!=nxt.mapx||map[nxt.x][nxt.y].second!=nxt.mapy))return printf("Yes"),0;
			if(a[nxt.x][nxt.y]==2||v[nxt.x][nxt.y])continue;
			v[nxt.x][nxt.y]=1;
			map[nxt.x][nxt.y]=make_pair(nxt.mapx,nxt.mapy);
			q.push(nxt);
		}
	}
	return printf("No"),0;
	
}
```

## div 2:E
### Problem description
>给你n个节点的树,和平面内的n个点,求一种映射方案,使得映射的树边除顶点在平面内没有交叉(n<=1500)
### Solution
分治,按照树上的父子关系,递归处理每个子树区间即可,处理的时候,选择最低的那个点为根后将其他点按极角排序即可.</br>
正确性证明:<br>
&emsp;&emsp;由于选择最低点为根,设其为root,可以得到其他点相对于root的极角α都满足0<=α<=180.又因为按极角大小排序,所以排序后递归选择的区间之间必然没有交叉.而区间内因为递归处理,依旧保证没有交叉,得证.
```cpp
#include<cstdio>
#include<algorithm>
#include<vector>
#define LL long long
#define M 20000
using namespace std;
struct Point{
	int x,y,id;
}p[2000];
vector<pair<int,int> >vec[2000];
int t,mix,miy,siz[2000];
bool cmp(Point a,Point b){
	int w=0;
	if(a.x>=mix&&b.x<=mix) return 1;
	if(a.x<=mix&&b.x>=mix) return 0;
		if(a.x<mix){
			w=1LL*(a.y-miy)*1LL*(mix-b.x)>=1LL*(b.y-miy)*1LL*(mix-a.x);
		}else{
		    w=1LL*(a.y-miy)*1LL*(b.x-mix)<=1LL*(b.y-miy)*1LL*(a.x-mix);
		} 
	return w;
}
int n,x,y,pnt=1,a[M],fi[M],ne[M],la[M],ans[M],tot;
void add(int x,int y){
	a[++tot]=y;
	!fi[x]?fi[x]=tot:ne[la[x]]=tot;la[x]=tot;
}
void dfs(int x,int fa){
	siz[x]=1;
	for(int i=fi[x];i;i=ne[i])if(a[i]!=fa){
		dfs(a[i],x);
		siz[x]+=siz[a[i]];
	}
}
void calc(int trt,int l,int r,int fa){
	//printf("%d %d %d\n",pnt,trt,fa);
	int pos=l;
	for(int i=l;i<=r;i++)if(p[i].y<p[pos].y)pos=i;
	swap(p[pos],p[l]);
	ans[p[l].id]=trt;
	mix=p[l].x;
	miy=p[l].y;
	//printf("%d\n",pos);
	pos=l+1;
    sort(p+pos,p+r+1,cmp);
	for(int i=fi[trt];i;i=ne[i])if(a[i]!=fa){
		calc(a[i],pos,pos+siz[a[i]]-1,trt);
		pos+=siz[a[i]];
	}
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<n;i++){
		scanf("%d%d",&x,&y);
		add(x,y);
		add(y,x);
	}
	//mix=miy=0x7f7f7f7f;
	//printf("%d\n",miy);
	for(int i=1;i<=n;i++){
		scanf("%d%d",&p[i].x,&p[i].y);
		p[i].id=i;

	}
	dfs(1,0);
	calc(1,1,n,0);
	for(int i=1;i<=n;i++)printf("%d ",ans[i]);
	return 0;
}
```
# 赛后补题

## div 1:E
### Problem description
>给你一张n个点m条边的DAG,有k个门户城市,这k各门户城市中任意两个城市a,b只要被到达,之后就可以瞬间从a到b或b到a,求从1开始遍历所有门户城市的最小花费(n,m,k<=10^5)
### Solution
首先考虑当所有点都是门户城市的时候,这时答案显然等于MST的边权和</br>
而现在,我们考虑如何建出一张包含且仅包含k个门户城市的连通图.</br>
我们可以做如下操作:</br>
&emsp;&emsp;1.做一遍多源最短路,求出每个点i最近的门户城市p[i]和距离f[i]</br>
&emsp;&emsp;2.对于每一条边<u,v,w>,若p[u]!=p[v],则将p[u]与p[v]连一条长为w+f[u]+f[v],连完之后就得到了各个门户城市间的最短路,直接跑MST即可,别忘了最后要加上f[1];
正确性证明:</br>
&emsp;&emsp;我们考虑若存在一条门户城市x1到门户城市xt的更短路<x,x1,x2,x3...xt>则必然存在一个xp,使得p[xp]!=p[xp-1],由此x1和xt的最短路就会被更新为这条.
这与这条路径是更短路的定义相悖,故得证.
```cpp
#include<bits/stdc++.h>
#define M 200010
using namespace std;
struct edge{
	long long w;
	int u,v;
	edge(long long w=0,int u=0,int v=0):w(w),u(u),v(v){}
}e[M];
int a[M],c[M],w[M],fi[M],ne[M],la[M],fa[M],tot,p[M],b[M],n,m,x,y,z,cnt,k;
long long f[M],ans;
bool cmp(edge a,edge b){
	return a.w<b.w;
}
void add(int x,int y,int z){
	a[++tot]=y;c[tot]=z;w[tot]=x;
	!fi[x]?fi[x]=tot:ne[la[x]]=tot;la[x]=tot;
}
queue<int>q;
void spfa(){
	while(!q.empty()){
		int x=q.front();q.pop();
		b[x]=0;
		for(int i=fi[x];i;i=ne[i])if(f[a[i]]>f[x]+c[i]){
			f[a[i]]=f[x]+c[i];
			p[a[i]]=p[x];
			if(!b[a[i]]){
				q.push(a[i]);
				b[a[i]]=1;
			}
		}
	}
}
int ask(int x){
	return x==fa[x]?x:fa[x]=ask(fa[x]);
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++){
		scanf("%d%d%d",&x,&y,&z);
		add(x,y,z);
		add(y,x,z);
	}
	scanf("%d",&k);
	memset(f,0x3f3f,sizeof(f));
	for(int i=1;i<=k;i++){
		scanf("%d",&x);
		q.push(x);f[x]=0;p[x]=x;b[x]=1;
	}
	spfa();
	for(int i=1;i<=tot;i++){
		if(p[w[i]]==p[a[i]])continue;
		e[cnt++]=edge(f[w[i]]+f[a[i]]+c[i],p[w[i]],p[a[i]]);
	}
	sort(e,e+cnt,cmp);
	for(int i=1;i<=n;i++)fa[i]=i;
	int l=k-1,i=0;
	while(l){
		int x=ask(e[i].u),y=ask(e[i].v);
		if(x!=y){
			fa[x]=y;
			ans+=e[i].w;
			l--;
		}
		i++;
	}
	return printf("%lld",ans+f[1]),0;
}

```
