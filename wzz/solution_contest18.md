[比赛链接]https://vjudge.net/contest/172100#overview)

## 比赛征程
> * Y : solved in the contest
> * A : solved after contest
> * SY : solving


  \# |  A  |  B  |  C  |  D  |  E  | F |
---|---|---|---|---|---|---|
|contest0|Y|  Y  |Y| A | A |A|



# 比赛中解决的问题
## A
### Problem description
> 两个人轮流放圆，谁不能放谁输

### Data Limit：n,p<=300  Time Limit: 1s

### Solution
> 博弈题，对称一发就可以保证先手赢，但不能放的情况总是后手赢。这类双方博弈题可以想到这个。
### Code
```cpp
	cin>>n>>m>>c;
	if(c*2>n||c*2>m) {
		puts("Second");return 0;
	}
	puts("First");
```
*****


## B
### Problem description
> 求两个多项式的分数值，x趋向于无穷大时，该分数的值。

### Data Limit：n <= 1e4  Time Limit: 2s
### Solution
> 按题意模拟。

### Code
```cpp
	cin>>n>>m;
	for(int i=1;i<=n+1;i++) scanf("%d",&a[i]);
	for(int i=1;i<=m+1;i++) scanf("%d",&b[i]);
	if(n>m) {
		if(a[1]*b[1]>0) puts("Infinity");
		if(a[1]*b[1]<0)puts("-Infinity");
		return 0;
	}
	if(n<m) {
		puts("0/1");return 0;
	}
	int it=gcd(a[1],b[1]);
	a[1]/=it;b[1]/=it;
	if(b[1]<0) a[1]=-a[1],b[1]=-b[1];
	cout<<a[1]<<"/"<<b[1]<<endl;
```
*****

# 赛后补题

## C
### Problem description

> 题意，在一个字符串中找出一些下标递增的字符连成字符串，使其字符串的字典序最大。


### Data Limit：n <= 1e5  Time Limit: 4s

### Solution
>维护一下上一个字母的位置二分即可。
### Code
```cpp
	for(int i=25;i>=0;i--) {
		if(!cnt[i]) continue;
		int ll=1,rr=cnt[i],ans=cnt[i]+1;
		while(ll<=rr) {
			int mid=(ll+rr)>>1;
			if(hh[i][mid]>=bef) {
				ans=mid;rr=mid-1;
			}
			else ll=mid+1;
		}
		int num=cnt[i]-ans+1;
		for(int j=1;j<=num;j++) res+=(char)('a'+i);
		bef=max(hh[i][cnt[i]]+1,bef);
	}
```
*****


## D
### Problem description
> 给你一个带权值的n*m的矩阵，有一些障碍点和一些非障碍点，你可以无限在这个图周围拼这个图，问你是否能无限走而不被墙拦住。
这一类进两次的题目可以这么设计vis不爆空间。
### Data Limit：k<= 1e5n,m<=1000  Time Limit: 2s
### Solution
> 这道题按题意广搜，当一个点在不同的象限被搜到两次，说明可行，所以vis数组只需记录这个点被第一次搜到的象限即可，这种题重复的题，可以搜象限。
### Code
```cpp
	memset(vx,63,sizeof(vx));
	memset(vy,63,sizeof(vy));
	vx[x0][y7]=1;vy[x0][y7]=1;
	tmp.xx=tmp.yy=1;tmp.x=x0;tmp.y=y7;
	q.push(tmp);
	while(!q.empty()) {
		ind=q.front();q.pop();
		int x=ind.x,y=ind.y,xx=ind.xx,yy=ind.yy;
//		cout<<"-------------"<<x<<" "<<y<<" "<<xx<<" "<<yy<<"-----------------------------"<<endl;
		for(int i=0;i<=3;i++) {
			int xd=x+dx[i],yd=y+dy[i],xc=xx,yc=yy;
			if(xd==0||xd==n+1) {
				xc=xc+1*(xd==0?-1:1);
				xd=xd+n;if(xd>n) xd=1;
			} 
			if(yd==0||yd==m+1) {
				yc=yc+1*(yd==0?-1:1);
				yd=yd+m;if(yd>m) yd=1;
			}
			if(!ma[xd][yd]) continue;
			if(vx[xd][yd]==xc&&vy[xd][yd]==yc) {
				continue;
			}
			if(vx[xd][yd]>100000) {
				vx[xd][yd]=xc;vy[xd][yd]=yc;
				tmp.x=xd,tmp.y=yd,tmp.xx=xc,tmp.yy=yc;
				q.push(tmp);
				continue;
			} 
			puts("Yes");return 0;
		}
	}
```
*****

## E
### Problem description
> 给你n个平面直角坐标系上的点，告诉你这些点对应树上的点，且这些边在坐标系里两两不相交，问你一个方案，将点对应到树上的点。（这些点不三点共线）

### Data Limit：n <= 1e5  Time Limit: 2s

### Solution
>这道题是一道分治构造题，满足相同性质的东西互不影响可分开构造。
本题就是先按极角排序，然后给每个子树分配点来完成的，满足分治性质。
# ##Code
```
vector<POINT>son[N];
void DFS(int x,int f) {
	mx=1e17;my=1e17;
	for(int i=0;i<son[x].size();i++) {
		if(my>son[x][i].y||(my==son[x][i].y&&son[x][i].x<mx))
		{
			mx=son[x][i].x;
			my=son[x][i].y;
		}
	}
	sort(son[x].begin(),son[x].end());
	ans[son[x][0].id]=x;
	int p=1;
	forw(i,x) {
		int V=to[i];
		if(V==f) continue;
		for(int j=0;j<S[V];j++) {
			son[V].push_back(son[x][p++]);
		}
		DFS(V,x);
	}
}
```
## F
##Probem Description
给你一张有权无向图，其中有几个传送门，你可以从一个传送门瞬间传送到一个已经走过的传送门，问你从1出发，遍历全部传送门所需的时间。
##n<=100000,m<=100000
##首先最基础的想法就是先从1走到一个传送门，然后做传送门。
然后一遍单源最短路碰到传送门把dis赋成0再更新，这样时空复杂度都不够。
</br>所以最后的想法是观察性质：这k个点相当于在跑最小生成树，所以你就预处理每个点离其最近的传送门和距离，实质就是利用该边跑最小生成树所需的代价，即是
该边分别到传送门的最近距离加边长可以将两个传送门和一起，最后跑一遍Kruscal就可以了。</br>
建模转化思想值得借鉴。
##Solution
```
	memset(inq,0,sizeof(inq));
	memset(dis,127,sizeof(dis));
	for(int i=1;i<=k;i++) {
		dis[it[i]]=0;q.push(it[i]); pre[it[i]]=it[i];inq[it[i]]=1;
	}
	for(int i=1;i<=n;i++) fa[i]=i;
	while(!q.empty()) {
		int ind=q.front();q.pop();inq[ind]=0;
		forw(i,ind) {
			int V=to[i];
			if(dis[V]>dis[ind]+C[i]) {
				dis[V]=dis[ind]+C[i];pre[V]=ind;
				if(!inq[V]) {
					inq[V]=1;
					q.push(V);
				}
			}
		}
	}
	for(int i=1;i<=n;i++) {
		fa[getf(i)]=getf(pre[i]);
	}
	for(int i=1;i<=cxt;i++) {
		xx[i].C+=dis[xx[i].u]+dis[xx[i].v];
		xx[i].u=getf(xx[i].u);
		xx[i].v=getf(xx[i].v);
	}
	sort(xx+1,xx+cxt+1);
	for(int i=1;i<=n;i++) fa[i]=i;
	int tot=0;
	for(int i=1;i<=cxt;i++) {
		if(getf(xx[i].u)!=getf(xx[i].v)) {
//			cout<<xx[i].u<<" "<<xx[i].v<<endl;
			fa[getf(xx[i].u)]=getf(xx[i].v);
			ans+=xx[i].C; 
			tot++;
		}
	}
	printf("%lld\n",ans);
```
