# 比赛记录

[比赛链接](https://vjudge.net/contest/168406)
## A1
### Problem description
>求一个天平的平衡情况
### Solution
求出点的位置以及到中心的距离
```cpp
for(int i=0;i<point;i++)
		if(isdigit(str[i]))
			left=left+(str[i]-'0')*(point-i);
for(int i=point+1;i<len;i++)
  if(isdigit(str[i]))
    right=right+(str[i]-'0')*(i-point);
```
## B1
### Problem description
>给定有向的类似于debt的东西，求最小的中间操作
### Solution
我们就拿欠别人钱，来算，统计欠的数量，如果他收到别人的钱，就在自己的欠加上钱数，统计总的就可以了
```cpp
for(int i=1;i<=m;i++)
		sum[u[i]]+=w[i],sum[v[i]]-=w[i];
for(int i=1;i<=n;i++)
  if(sum[i]>0) ans+=sum[i];
```
## A
### Problem description
>给定一个数列，求重新排列之后的能被7整除的方案
### Solution
1、6、8、9组成的四位数能够成7的完整的剩余系，也就是能生成各种余数，我们保留一个1689，其余放最前面，0放最后面
```cpp
for(int i=0;i<len;i++)
		s[i]=str[i]-'0',book[s[i]]++;
	for(int i=1;i<=9;i++)
	{
		if(i==1||i==8||i==6||i==9)
			for(int j=1;j<book[i];j++)
				{printf("%d",i);m=(10*m+i)%7;num++;}
		else
			for(int j=1;j<=book[i];j++)
				{printf("%d",i);m=(10*m+i)%7;num++;}
	}
	m=m*10000,m%=7;
	Map[0]=9681;
	Map[1]=1896;
	Map[2]=9861;
	Map[3]=1698;
	Map[4]=6891;
	Map[5]=6981;
	Map[6]=6819;
	printf("%d",Map[m]);num+=4;
	for(int i=num;i<len;i++)
		printf("0");
```
## B
### Problem description
>求对行进行随意变换后的最大全1子矩阵
### Solution
如果没有变换的话，我们可以使用悬线法在一个较优的时间之内求解。
但是本题有更为巧妙的做法，设left[i][j]表示i，j位置向左延伸的最长的长度lef[j][i]=(a[i][j]==1)?lef[j-1][i]+1:0，枚举右端点进行统计就可以了。
```cpp
for(int i=0;i<n;i++)
	{
		lef[0][i]=a[i][0];
		for(int j=1;j<m;j++)
			lef[j][i]=(a[i][j]==1)?lef[j-1][i]+1:0;
	}
	for(int r=0;r<m;r++)
	{
		sort(lef[r],lef[r]+n,cmp);
		for(int i=0;i<n;i++)
			ans=max(ans,lef[r][i]*(i+1));
	}
```

***** 
# 赛后补题

## C
### Problem description
> 求出围绕若干个点的最大的利润
### Solution
首先要看懂题意，特别是小字！首先要看懂题意，特别是小字！首先要看懂题意，特别是小字！
然后根据小字的提示，暴力广搜。
小技巧，我们判断是否在图形内部的时候可以向下引一条直线，这样子不会算重复  

## BFS
```cpp
queue<Point> q;
	memset(dp,-2,sizeof(dp));
	int INF =dp[39][39][39];
	q.push((Point){sx,sy,0});
	dp[sx][sy][0]=0;
	while(!q.empty())
	{
		Point e=q.front();q.pop();
		int fx=e.x,fy=e.y,w=e.w;
		for(int k=0;k<4;k++)
		{
			int u=fx+temp[k][0];
			int v=fy+temp[k][1];
			if(s[u][v]||u<0||v<0||u>=n||v>=m) continue;
			int noww=w;
			if(fy!=v)
			{
				int low=min(fy,v);
				for(int i=0;i<line.size();i++)
					if(line[i].y==low&&line[i].x<u) 	
						noww=noww^(1<<i);
			}
//			cout<<noww<<"\n";
			if(dp[u][v][noww]==INF)
			{
				dp[u][v][noww]=dp[fx][fy][w]-1;
				q.push((Point){u,v,noww});
				//cout<<dp[sx][sy][(1<<(line.size()))-1]<<"~~\n";
			}
		}
	}
```
## answer
```cpp
for(int i=0;i<(1<<line.size());i++)
	{
		int rans=dp[sx][sy][i];
		for(int j=0;j<line.size();j++)
			if((1<<j)&i)
				rans+=line[j].w;
		ans=max(ans,rans);
}
```
## D
### Problem description
> 给你一棵树n个点，m次询问(n=100000，m=100000)，每个节点有一种颜色， 
  每次询问问你以v节点为根的子树中  满足  同一种颜色的个数>=k的  颜色有几个。
### Solution
用莫队以及前缀和求出即可，具体分析可以见此
[我是链接]<http://blog.csdn.net/auto_ac/article/details/22087707>
我只会这里的第12种，先贴一个代码吧。
## DFS
```cpp
void dfs(int x,int fa)
{
	lef[x]=++cnt;
	col[lef[x]]=coll[x];
	for(int i=0;i<g[x].size();i++)
	{
		int j=g[x][i];
		if(j!=fa)
			dfs(j,x);
	}
	ri[x]=cnt;
}
```
## 莫队
```cpp
int l=1,r=0;//左闭右闭的区间
	for(int i=1;i<=m;i++)
	{
		while(l>p[i].l) l--,book[col[l]]++,sum[book[col[l]]]++;
		while(l<p[i].l) sum[book[col[l]]]--,book[col[l]]--,l++;
		while(r>p[i].r) sum[book[col[r]]]--,book[col[r]]--,r--;
		while(r<p[i].r) r++,book[col[r]]++,sum[book[col[r]]]++;
		ans[p[i].id]=sum[p[i].kk];
		//cout<<l<<" "<<r<<"\n";
	}
```
## E
### Problem description
> 还不会
### Solution
真的不会
