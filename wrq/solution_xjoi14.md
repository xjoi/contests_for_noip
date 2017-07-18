[比赛链接](http://210.33.19.101/contest/755)

# 比赛中解决的问题
## B
### Problem description
> 给出一个n*m的矩阵，每个1*1的区域都有一个高度。若两区域间高度差为x，则从一区域到另一区域需花费x^2+1。  
给出矩阵的p个区域，求从(1,1)出发，经过所有给出的p个区域的最小花费。

### Data Limit： 1<=n,m<=100, 1<=p<=10  Time Limit: 1s

### Solution
> 因为p较小，可以dfs枚举经过每个区域的顺序，依次用SPFA算出两个区域间的花费，加起来统计最小值即可。

### Code
```cpp
#define num(i,j) m*(i-1)+j

//spfa
LL calc(int s,int t){
	if (diss[s][t]!=-1) return diss[s][t];
	memset(dis,2,sizeof dis);
	dis[a[s]]=0;
	queue<int>q; q.push(a[s]);
	while (!q.empty()){
		int tmp=q.front(); q.pop(); //printf("tmp=%d dis[tmp]=%lld\n",tmp,dis[tmp]);
		int y=tmp-1; if (tmp%m!=1&&y>0&&y<=num(n,m)){
			LL d=abs(h[y]-h[tmp]); d*=d, d++;
			if (d+dis[tmp]<dis[y]) dis[y]=dis[tmp]+d,q.push(y);
		}
		y=tmp+1; if (tmp%m!=0&&y>0&&y<=num(n,m)){
			LL d=abs(h[y]-h[tmp]); d*=d, d++;
			if (d+dis[tmp]<dis[y]) dis[y]=dis[tmp]+d,q.push(y);
		}
		y=tmp+m; if (y>0&&y<=num(n,m)){
			LL d=abs(h[y]-h[tmp]); d*=d, d++;
			if (d+dis[tmp]<dis[y]) dis[y]=dis[tmp]+d,q.push(y);
		}
		y=tmp-m; if (y>0&&y<=num(n,m)){
			LL d=abs(h[y]-h[tmp]); d*=d, d++;
			if (d+dis[tmp]<dis[y]) dis[y]=dis[tmp]+d,q.push(y);
		}
	}
	for (int i=1;i<=cnt;++i) diss[s][i]=diss[i][s]=dis[a[i]];
	return dis[a[t]];
}
void arr(int s,LL dist,int last){
	//printf("****%d %I64d %d\n",s,dist,last);
	if (dist>=ans) return;
	if (s==cnt){ans=dist; return;}
	for (int i=1;i<=cnt;++i)
		if (!b[i]){
			b[i]=1;
			LL x=calc(last,i);
			arr(s+1,dist+x,i);
			b[i]=0;
		}
}

	for (int i=1;i<=n;++i)
		for (int j=1;j<=m;++j) scanf("%d",&h[num(i,j)]);
	scanf("%d",&cnt);
	a[0]=1;
	for (int i=1;i<=cnt;++i){
		int x,y; scanf("%d%d",&x,&y);
		a[i]=num(x,y);
		b[i]=0;
	}
	ans=inf;
	for (int i=0;i<cnt;++i)
		for (int j=i+1;j<=cnt;++j) diss[i][j]=-1;
	arr(0,0,0);
	
```
*****

# 赛后补题


## A
### Problem description
> 有一个N*1的棋盘，N是无限的。给出前30个位置的棋子摆放情况，求是否能达到下面给出一种的情况。每个测试点T组数据。
> 有以下几种操作：  
（1）若某位置右边第4个位置为空，可以将该位置上的棋子右移4格  
（2）若某位置右边第1、3个位置为空，第2个不为空，可以将该位置上的棋子右移3格
（3）若某位置右边第2个位置为空，第1个不为空，可以将该位置上的棋子右移2格

### Data Limit：T<=10  Time Limit: 1s

### Solution
> 因为只要右边为空，棋子就能向右移4格，说明事实上，棋子的具体位置没有关系，只需统计将所有位置x根据x%4的余数分为4组，并统计每组的棋子个数即可。

### Code
```cpp
void dfs(int a,int b,int c,int d){
	if (vis[a][b][c][d]) return;
	if (a==num2[0]&&b==num2[1]&&c==num2[2]&&d==num2[3]){
		ans=1; return;
	}
	if (a+b+c+d<num2[0]+num2[1]+num2[2]+num2[3]) return;
	vis[a][b][c][d]=1;
	if (a&&c) dfs(a-1,b+1,c-1,d+1);
	if (ans) return;
	if (b&&d) dfs(a+1,b-1,c+1,d-1);
	if (ans) return;
	if (a&&b) dfs(a-1,b-1,c+1,d);
	if (ans) return;
	if (b&&c) dfs(a,b-1,c-1,d+1);
	if (ans) return;
	if (c&&d) dfs(a+1,b,c-1,d-1);
	if (ans) return;
	if (a&&d) dfs(a-1,b+1,c,d-1);
}

    	cin >> s1 >> s2;
		memset(num1,0,sizeof num1);
		memset(num2,0,sizeof num2);
		for (int i=0;i<s1.length();++i)
			if (s1[i]=='*') num1[i%4]++;
		for (int i=0;i<s2.length();++i)
			if (s2[i]=='*') num2[i%4]++;
		memset(vis,0,sizeof vis);
		ans=0;
		dfs(num1[0],num1[1],num1[2],num1[3]);
		if (ans) printf("YES\n"); else printf("NO\n");

```
*****


## C
### Problem description
> 给出正整数N，求方程1/N!=1/X+1/Y的正整数解(X,Y)的数量

### Data Limit：N<=10000, 数据组数<=30  Time Limit: 1s

### Solution
> 将方程变形，可将问题转化为求满足等式(N!)^2=ab的a、b数量  
分解质因数求解即可

### Code
```cpp
	prime[1]=2, prime[2]=3, prime[3]=5;
	int cnt=3;
	for (int i=7;i<=10000;++i){
		bool f=1;
		for (int j=1;j<=cnt;++j) 
			if (i%prime[j]==0){ f=0; break; }
		if (f) prime[++cnt]=i;
	}
	scanf("%d",&n);
	while (n!=0){
		memset(sum,0,sizeof sum);
		for (int i=2;i<=n;++i){
			int tmp=i;
			for (int j=1;j<=cnt;++j)
				while (tmp%prime[j]==0&&tmp) sum[j]++, tmp/=prime[j];
		}
		int len=1;
		memset(ans,0,sizeof ans);
		ans[1]=1;
		for (int i=1;i<=cnt;++i)
			if (sum[i]){
				for (int j=1;j<=len;++j) ans[j]*=(sum[i]*2+1);
				len+=20;
				for (int j=1;j<=len;++j) ans[j+1]+=ans[j]/10, ans[j]%=10;
				while (ans[len]==0&&len>1) len--;
			}
		for (int i=len;i>=1;--i) printf("%d",ans[i]);
		printf("\n");
		scanf("%d",&n);
	}
```
*****
