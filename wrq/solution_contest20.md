[比赛链接](https://cn.vjudge.net/contest/172463)

# 比赛中解决的问题  

## A Nuts 
### Problem description
> 有a个物品和很多箱子，你可以在箱子中放置x块隔板将箱子分成x+1个区域  
现有两个限制：  
1.每个箱子最多被分成k份  
2.每个区域最多放置v个物品  
求，当有b个隔板时，最少几个箱子就能够放下这些物品

### Data Limit：1 <= k,a,b,v <= 10^3  Time Limit: 1s

### Solution
> 贪心策略：在一个箱子里放尽量多的隔板，每个分出的区域都放满，模拟即可

### Code
```cpp
	int ans=0;
	while (a>0){
		if (b>=k-1){
			b-=k-1; ans++;
			a-=k*v;
		}else if (b>0){
			ans++, a-=(b+1)*v;
			b=0;
		}else ans++,a-=v;
	}
```
*****


## B Trees in a Row 
### Problem description
> 有一个序列a，现在要使其满足a[i+1]-a[i]=k(1<=i<n)，求最小修改次数

### Data Limit：1 <= n,k,a[i] <= 10^3  Time Limit: 1s

### Solution
> 枚举每个位置x，以该位置的a[x]为标准，向前向后分别计算修改次数，选择修改次数最少的为标准即可

### Code
```cpp
	int sum=n-1,loc=1;
	for (int i=1;i<=n;++i){
		if (a[i]-k*(i-1)<=0) continue;
		int tmp=0;
		for (int j=1;j<i;++j) if (a[j]!=a[i]-k*(i-j)) tmp++;
		for (int j=i+1;j<=n;++j) if (a[j]!=a[i]+k*(j-i)) tmp++;
		if (tmp<sum) sum=tmp,loc=i;
	}
	printf("%d\n",sum);
	for (int i=1;i<loc;++i)
		if (a[i]!=a[loc]-k*(loc-i)){
			int x=a[loc]-k*(loc-i);
			if (a[i]>x) printf("- %d %d\n",i,a[i]-x);
			else printf("+ %d %d\n",i,x-a[i]);
		}
	for (int i=loc+1;i<=n;++i)
		if (a[i]!=a[loc]+k*(i-loc)){
			int x=a[loc]+k*(i-loc);
			if (a[i]>x) printf("- %d %d\n",i,a[i]-x);
			else printf("+ %d %d\n",i,x-a[i]);
		}
```
*****


## F Searching for Graph
### Problem description
> 定义一个n个点的p-interesting图满足如下条件：  
1.有2*n+p条边  
2.没有重边和自环  
3.对于每个有k个点的子图，边数不超过2*k+p  
求构造一个n个点的p-interesting图

### Data Limit：5 <= n <= 24, 2*n+p <= n*(n-1)/2  Time Limit: 1s

### Solution
> 照着样例直接枚举每个点，和其他点连起来就行了吖……  
证明？那是是什么？可以吃吗？

### Code
```cpp
	while (t){
		t--;
		scanf("%d%d",&n,&p);
		int cnt=0; bool f=1;
		for (int i=1;i<=n;++i){
			for (int j=i+1;j<=n;++j){
				printf("%d %d\n",i,j); cnt++;
				if (cnt==2*n+p){f=0; break;}
			}
			if (!f) break;
		}
	}
```
*****

# 赛后补题  

## C Strictly Positive Matrix
### Problem description
> 给出一个n*n的矩阵A，保证A[i,j]>=0，且从左上方到右下方的对角线上的元素之和大于0，
问是否能找到一个k使得A^k的所有元素大于0

### Data Limit：n <= 2*10^5  Time Limit: 1s

### Solution
> 若矩阵A是一张图的邻接矩阵表示，则A^k[i,j]表示走k步能否从i走到j  
题中只要求判断元素是否全为正，所以可以转化为，判断该矩阵表示的图的每两点之间是否都能互相到达   
用tarjan判断即可

### Code
```cpp
void tarjan(int x){
	dfn[x]=low[x]=++cnt; t[++top]=x;
	for (int i=1;i<=n;++i){
		if (x==i) continue;
		if (a[x][i]==0) continue;
		if (!dfn[i]) tarjan(i),low[x]=min(low[x],low[i]);
		else if (!col[i]) low[x]=min(low[x],dfn[i]);
	}
	if (low[x]==dfn[x]){
		sum++;
		while (true){
			col[t[top]]=sum; top--;
			if (t[top+1]==x) break;
		}
	}
}
if (sum==1&&cnt==n) printf("YES\n"); else printf("NO\n");
```
*****

## E Upgrading Array
### Problem description
> 给出m个素数b[i]，规定这些素数为badprime，其余素数为goodprime  
定义一个f(s)：当s==1时，f(s)=0；当s的最小质因数p为badprime时，f(s)=f(s/p)-1；
当s的最小质因数p为goodprime时，f(s)=f(s/p)+1  
现在给出一个序列a，你可以对a进行如下操作：选定一个数字r(1<=r<=n)，将所有a[1~r]除以这r个数的GCD  
问所能获得的f(a[i])(1<=i<=n)之和的最大值

### Data Limit：1 <= n,m <= 5*10^3, a[i],b[i] <= 10^9  Time Limit: 1s

### Solution
> 观察可知，f(s)=(s分解质因数后，goodprime的数量减去badprime的数量)  
显然地，如果要进行操作，必须从后向前进行，因此可以预处理出前r个数的GCD  
具体计算时可以从后往前枚举，计算如果在当前位置r进行操作，ans的变化量，如果能使ans变大则进行一次操作

### Code
```cpp
inline int prime_calc(int tmp){
	int calc=0;
	for (int x=1;x<=sum&&tmp>1;++x){
		int cnt=0;
		while (tmp%prime[x]==0) tmp/=prime[x],cnt++;
		if (badprime.find(prime[x])!=badprime.end()) calc-=cnt;
			else calc+=cnt;
	}
	if (tmp>1){
		if (badprime.find(tmp)!=badprime.end()) calc--; else calc++;
	}
	return calc;
}

	for (int i=1;i<=n;++i) scanf("%d",&a[i]);
	for (int i=1;i<=m;++i){
		int x; scanf("%d",&x);
		badprime.insert(x);
	}
	b[1]=1;
	for (int i=2;i<50000;++i){
		if (!b[i]) prime[++sum]=i;
		for (int j=1;j<=sum;++j){
			if (i*prime[j]>50000) break;
			b[i*prime[j]]=1;
			if (i%prime[j]==0) break;
		}
	}
	pre[1]=a[1];
	for (int i=2;i<=n;++i) pre[i]=gcd(pre[i-1],a[i]);
	ans=0; int used=1;
	for (int i=1;i<=n;++i) ans+=prime_calc(a[i]);
	for (int i=n;i>=1;--i){
		int tmp=-prime_calc(pre[i]/used);
		if (tmp>0) ans+=i*tmp, used=pre[i];
	}
```
