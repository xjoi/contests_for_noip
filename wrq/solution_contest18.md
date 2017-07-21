[比赛链接](https://cn.vjudge.net/contest/172100)

# 比赛中解决的问题

## C
### Problem description
> 给出一个字符串s, 求s中字典序最大的子序列

### Data Limit：|s| <= 10^5  Time Limit: 2s

### Solution
> 要使字符串的字典序最大, 前面的字符越大越好, 则后面的字符大小必定是递减的  
可以用f[i]表示i位置及其后面的字符中, 字符最大的位置, f可从后往前扫O(n)得到, 最后从前到后, 将最大的字符依次加入答案

### Code
```cpp
	int len=strlen(s);
	f[len-1]=len-1;
	for (int i=len-2;i>=0;i--){
		if (s[i]>=s[f[i+1]]) f[i]=i; else f[i]=f[i+1];
	}
	string ans; int x=0;
	while (x<len){
		ans+=s[f[x]];
		x=f[x]+1;
	}
```
*****


# 赛后补题

## A
### Problem description
> A和B两人轮流在一张长方形桌子上摆放盘子, 盘子需全部在长方形内部, 盘子间可以接触, 但不能叠放。若轮到某个人的时候不能继续摆放, 则这个人输  
给出桌子的长a和宽b, 盘子的半径r, 若先手有必胜策略输出First, 否则输出Second

### Data Limit：1 <= a,b,r <= 100  Time Limit: 2s

### Solution
> 结论: 若min(a,b)>=2*r, 则先手必胜, 否则必输
> 理由: 如果min(a,b)<2*r, 即桌上不能放下一个盘子, 先手必输  
反之, 先手能在第一步将盘子放在桌子正中间, 对于接下来的每一步, 都能和另一个人进行对称的摆放  

### Code
```cpp
	scanf("%d%d%d",&a,&b,&r);
	if (min(a,b)<2*r) printf("Second");
	else printf("First");
```
*****

## B
### Problem description
> 给出n次多项式P(x)和m次多项式Q(x)【保证最高次项系数不为零】, 求P(x)/Q(x)的极限

### Data Limit：0 <= n,m <= 100, -100 <= a[i],b[i] <= 100  Time Limit: 2s  

### Solution
> 分类讨论, 详见程序  
注意: 判断是Infinity和-Infinity时应看两式最高次项系数乘机的正负性, 不能只看P(x)

### Code
```cpp
	if (n>m){
		if (a[0]*b[0]>0) printf("Infinity\n");
		else printf("-Infinity\n");
	}else if (n<m) printf("0/1\n");
	else{
		if (a[0]*b[0]<0) printf("-");
		a[0]=abs(a[0]); b[0]=abs(b[0]);
		bool f=false;
		if (a[0]<b[0]){
			int tmp=a[0]; a[0]=b[0]; b[0]=tmp; f=true;
		}
		int x=a[0],y=b[0];
		while (a[0]%b[0]!=0){
			int r=a[0]%b[0];
			a[0]=b[0]; b[0]=r;
		}
		x/=b[0],y/=b[0];
		if (!f) printf("%d/%d\n",x,y);
		else printf("%d/%d\n",y,x);
	}
```
*****

## D
### Problem description
> 有一个无限大的迷宫, 由一个 n*m 的矩阵拼凑而成, (x,y)位置上的情况和(x mod n,y mod m)上是一样的  
迷宫中有墙, 不能行走, 用'#'表示, 路用'.'表示。给出起点S, 问从S出发能否到达无限远的地方

### Data Limit：1 <= n,m <= 1500  Time Limit: 2s

### Solution
> 用vis[x mod n][y mod m][0]和vis[x mod n][y mod m][1]分别记录上次到(x mod n,y mod m)时, 具体是在哪个(x,y)的位置, 
若与上次相同, 说明进入走回去了, 否则是在另一个n*m的区域中, 说明能够到达无限远处
> mod时应当用(x%n+n)%n, 否则当x为一个很小的负数时会引起RE

### Code
```cpp
bool dfs(int x,int y){
	//printf("%d %d ",x,y);
	int fx=(x%n+n)%n,fy=(y%m+m)%m;
	//printf("%d %d\n",fx,fy);
	if (a[fx][fy]=='#') return false;
	if (vis[fx][fy][0]!=inf) return vis[fx][fy][0]!=x||vis[fx][fy][1]!=y;
	vis[fx][fy][0]=x,vis[fx][fy][1]=y;
	for (int i=1;i<=4;++i) if (dfs(x+dx[i],y+dy[i])) return true;
	return false;
} 
```
*****

## E
### Problem description
> 给出一个n个点的树的连边情况, 并给出平面上的n个点的具体坐标, 要求给出树上的点和平面上的点一一对应的一种方案, 
使得将平面上的点按照树的结构连边后, 没有任意两条边相交【保证没有三点共线】

### Data Limit：1 <= n <= 1500  Time Limit: 2s

### Solution
> 先默认一个根节点root, 用dfs求出每颗子树的节点总数, 确定每个点的孩子, 连边（题目没有给出根节点, 给出的连边不能确认两点间的父子关系）  
然后从以根节点root为根的整棵树开始, 对于每颗子树, 找出最靠左下方的点s作为当前根节点的对应点, 将所有平面上的点按照与点s间的角度排序。
根据当前根节点的每个孩子所在的子树规模, 将排好序的点分成几块,作为子树的对应点继续递归
> 注意: 如果随意取点作为标准来排序, 则该点的360°都有点, 将排完序的点分为几块子树后, 不同块之间的边可能会产生影响  
如果取左下角(或左上角或右上角或右下角), 将点根据子树分到不同区域后, 连边一定在该区域内, 不会对其他区域产生影响

### Code
```cpp
void tree(int x){
	vis[x]=1; sz[x]=1;
	for (int i=fst[x];i;i=nxt[i])
		if (!vis[des[i]]) tree(des[i]),add2(x,des[i]),sz[x]+=sz[des[i]];
}
bool cmp(Point i,Point j){
	if (i==s) return 1;
	if (j==s) return 0;
	double y=cross(i,j,s);
	if (y<0) return 0;
	return 1;
}
void solve(vector<Point>b,int fa){
	s=b[0];
	for (int i=1;i<b.size();++i) if (b[i]<s) s=b[i];
	sort(b.begin(),b.end(),cmp);
	int l=1; ans[s.num]=fa;
	for (int i=fstc[fa];i;i=nxtc[i]){
		int k=c[i]; vector<Point>m;
		for (int j=1;j<=sz[k];++j) m.push_back(b[l]),l++;
		solve(m,k);
	}
}
```
