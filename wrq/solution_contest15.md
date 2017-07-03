[比赛链接](https://cn.vjudge.net/contest/168929)

# 比赛中解决的问题
## A
### Problem description
> 给出a,b,c,d，求有正整数x,y使ax+b=cy+d成立时，ax+b的最小值

### Data Limit：1 <= a,b,c,d <= 100  Time Limit: 1s

### Solution
> a,b,c,d的数据范围很小，在一定范围内一定有解，枚举即可

### Code
```cpp
LL x=b,y=d;
while (x<=inf&&y<=inf){
	if (x<y) x+=a;
	if (x>y) y+=c;
	if (x==y){
		printf("%d",x); return 0;
	}
}
printf("-1");
```
*****


## B
### Problem description
> 有n个平行宇宙，编号为1~n，第i个宇宙有编号为+x和-x的两人，其中有且仅有1人为叛徒（但题目不给出叛徒具体是谁）。
所有人被分为m组。  
求所有的2*n种情况中，是否会出现一组中所有人均为叛徒的情况。

### Data Limit：1 <= n,m <= 10000  Time Limit: 2s

### Solution
> 若同一组中同时出现+x和-x，则两人中必有一人不是叛徒。统计即可。

### Code
```cpp
	for (int i=1;i<=m;++i){
		int x; scanf("%d",&x);
		memset(f,0,sizeof f);
		for (int j=1;j<=x;++j){
			scanf("%d",&a[j]);
			if (a[j]<0&&f[0-a[j]]==0) f[0-a[j]]=1;
			if (a[j]<0&&f[0-a[j]]==2) f[0-a[j]]=3;
			if (a[j]>0&&f[a[j]]==0) f[a[j]]=2;
			if (a[j]>0&&f[a[j]]==1) f[a[j]]=3;
		}
		bool ans=0;
		for (int j=1;j<=x;++j){
			int tmp=abs(a[j]);
			if (f[tmp]==3) ans=1;
		}
		if (!ans){
			printf("YES"); return 0;
		}
	}
	printf("NO");
```
*****

# 赛后补题

## C
### Problem description
> 有n个编号为0~n-1的点以顺时针排列成环，其中0为黑洞。题目给出甲和乙两人分别可以移动的步数。
甲乙两人可以选择任意位置（除0外）为起点，每次移动题目给出的任意一种可行步数。  
求两人在每一个位置时，若先走，是否有必胜策略。  

### Data Limit：2 <= n <= 7000  Time Limit: 1s

### Solution
> 令两人分别为0和1，f[x][y]为x人在第y个位置是否有必胜策略。f[x][y]==1表示有必胜策略，-1表示必输，2表示尚未确定或平局。
> 令步数为t  
（1）若(y+t)%n==0，则一步就能赢，f[x][y]=1;  
（2）若f[1-x][(y+t)%n]==-1，则f[x][y]=1，因为此时x移动t步为对方的必输状态  
（3）若对于x的所有可行的t，f[1-x][(y+t)%n]==1，则f[x][y]=-1，因为不管怎么移动都为对方的必胜状态

### Code
```cpp
void sch(int x,int y){
	if (b[x][y]||f[x][y]!=2) return;
	b[x][y]=1;
	for (int i=1;i<=a[x][0];++i){
		int t=a[x][i];
		if ((y+t)%n==0){
			f[x][y]=1; return;
		}
	}
	int cnt=0;
	for (int i=1;i<=a[x][0];++i){
		int t=(y+a[x][i])%n;
		sch(1-x,t);
		if (f[1-x][t]==-1){
			f[x][y]=1; return;
		}
		if (f[1-x][t]==1) cnt++;
	}
	if (cnt==a[x][0]) f[x][y]=-1;
}


	scanf("%d",&a[0][0]);
	for (int i=1;i<=a[0][0];++i) scanf("%d",&a[0][i]);
	scanf("%d",&a[1][0]);
	for (int i=1;i<=a[1][0];++i) scanf("%d",&a[1][i]);
	for (int i=0;i<=1;++i)
		for (int j=0;j<n;++j) f[i][j]=2;
	for (int i=0;i<=1;++i){
		memset(b,0,sizeof b);
		for (int j=n-1;j>0;--j) sch(0,j),sch(1,j);
	}
	for (int i=0;i<=1;++i){
		for (int j=1;j<n;++j){
			if (f[i][j]==1) printf("Win ");
			else if (f[i][j]==-1) printf("Lose ");
			else if (f[i][j]==2) printf("Loop ");
		}
		printf("\n");
	}
```
*****


## D
### Problem description
> 

### Data Limit：  Time Limit: 

### Solution
> 

### Code
```cpp
```
*****

## E
### Problem description
> 

### Data Limit：  Time Limit: 

### Solution
> 

### Code
```cpp
```
