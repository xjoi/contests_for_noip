[比赛链接](https://cn.vjudge.net/contest/171671)

# 比赛中解决的问题
## A
### Problem description
> 令hash(x)=x mod p, 共给出n个数x，输出第一次冲突是在第几次操作之后。若没有冲突返回-1

### Data Limit：2 <= n,p <= 300, 0 <= x <= 10^9  Time Limit: 1s

### Solution
> 用一个布尔数组记录，模拟即可

### Code
```cpp
	memset(f,0,sizeof f);
	scanf("%d%d",&p,&n);
	for (int i=1;i<=n;++i){
		int x;
		scanf("%d",&x);
		if (f[x%p]){
			printf("%d",i); return 0;
		}
		f[x%p]=1;
	}
	printf("-1");
```
*****


## B
### Problem description
> 给出一个由小写字母组成的字符串s，并给出每个小写字母的权值w[i]。 
定义f(s)=Σ(w[s[i]]*i),求往字符串s中加入k个字母后f(s)最大值

### Data Limit：0 <= |s|,k <= 10^3 , w[i] <= 10^3 Time Limit: 1s

### Solution
> 根据f(s)的定义，最佳方案是将所有字母中权值最大的字母加在字符串最后  
从前到后扫一遍即可

### Code
```cpp
	scanf("%s",s);
	scanf("%d",&k);
	int m=0,ans=0;
	for (int i=1;i<=26;++i) scanf("%d",&w[i]),m=max(m,w[i]);
	for (int i=0;i<strlen(s);++i) ans+=w[s[i]-'a'+1]*(i+1);
	for (int i=strlen(s)+1;i<=strlen(s)+k;++i){
		ans+=m*i;
	}
	printf("%d",ans);
```
*****

# 赛后补题

## C
### Problem description
> 给出一个由n个数字组成的序列a，求最多替换一个数字后，所能找到的最长严格上升子串的长度

### Data Limit： 1 <= n <= 10^5, a[i] <= 10^9  Time Limit: 1s

### Solution
> 先判断每个位置与它前面的数的大小关系，统计出到i位置的最长严格上升子串长度f[i]  
然后枚举每一个位置，若它所在的子串a能和前面的子串b，通过修改a的第一个或b的最后一个达到题意要求，就与ans取max

### Code
```cpp
	scanf("%d",&n);
	for (int i=1;i<=n;++i) scanf("%d",&a[i]),f[i]=1;
	for (int i=2;i<=n;++i)
		if (a[i]>a[i-1]) f[i]=f[i-1]+1;
	int ans=0;
	for (int i=1;i<=n;++i){
		ans=max(ans,min(n,f[i]+1));
		if (a[i-f[i]+1]-1>a[i-f[i]-1]) ans=max(ans,f[i]+f[i-f[i]]);
		if (a[i-f[i]+2]-1>a[i-f[i]]) ans=max(ans,f[i]+f[i-f[i]]);
	}
	printf("%d",ans);
```
*****


## D
### Problem description
> 给出一个n*m的矩阵和两种操作，求经过k次操作后所能获得的最大值  
操作1：选取矩阵的一行，获得的值为该行数字当前的和，然后将这行每个数都减去p
操作2：选取矩阵的一列，获得的值为该列数字当前的和，然后将这列每个数都减去p

### Data Limit: 1 <= n,m,a[i][j] <= 10^3, 1 <= k <= 10^6  Time Limit: 2s
### Solution
> 根据题意，矩阵的行和列间的相对位置对答案没有影响，因此只需记录每行和每列的和来进行操作  
不考虑行和列之间的影响，枚举操作次数x，计算经过x次对行或列进行操作分别能获得的最大值  
最后枚举k，则答案为ansrow[i]+anscol[k-i]-i*(k-i)*p  
> i*(k-i)*p为不考虑行和列之间的影响时多计算的值 

### Code
```cpp
priority_queue<ll> q_row;
priority_queue<ll> q_col;

int main(){
	scanf("%lld%lld%lld%lld",&n,&m,&k,&p);
	for (int i=1;i<=n;++i)
		for (int j=1;j<=m;++j){
			ll x; scanf("%lld",&x);
			row[i]+=x, col[j]+=x;
		}
	for (int i=1;i<=n;++i) q_row.push(row[i]);
	for (int j=1;j<=m;++j) q_col.push(col[j]);
	for (int i=1;i<=k;++i){
		int tmp=q_row.top(); q_row.pop();
		ansrow[i]=ansrow[i-1]+tmp;
		q_row.push(tmp-m*p);
		
		tmp=q_col.top(); q_col.pop();
		anscol[i]=anscol[i-1]+tmp;
		q_col.push(tmp-n*p);
	}
	ll ans=-1e17;
	for (int i=0;i<=k;++i){
		ans=max(ans,ansrow[i]+anscol[k-i]-i*(k-i)*p);
	}
	printf("%lld",ans);

	return 0;
}
```
*****

## E
### Problem description
> f是一个斐波那契数列，其中f(1)=1,f(2)=1  
给出由n个数组成的序列a，进行m次操作，对于每次询问操作返回一个结果  
操作如下：  
1 l r代表对于每个l<=i<=r, a[i]+=f[i-l+1];  
2 l r代表询问a[l]到a[r]的和

### Data Limit：1 <= n,m <= 3*10^5, a[i] <= 10^9  Time Limit: 4s

### Solution
> 斐波那契数列的每一项都是前两项之和，所以当斐波那契数列相加后，得到的结果仍为斐波那契数列  
可以根据该特性维护一颗线段树

### Code
```cpp
ll calcf(ll fx,ll fy,int x){
	if (x==1) return fx;
	if (x==2) return fy;
	return (fx*f[x-2]+fy*f[x-1])%mod;
}
ll calcs(ll fx,ll fy,int x){
	return (calcf(fx,fy,x+2)-fy+mod)%mod;
}
void pushdown(int x){
	if (tree[x].f1){
		int i=x*2,j=x*2+1,mid=(tree[x].l+tree[x].r)/2;
		int fx=calcf(tree[x].f1,tree[x].f2,mid-tree[x].l+2);
		int fy=calcf(tree[x].f1,tree[x].f2,mid-tree[x].l+3);
		tree[i].f1=(tree[i].f1+tree[x].f1)%mod;
		tree[i].f2=(tree[i].f2+tree[x].f2)%mod;
		tree[j].f1=(tree[j].f1+fx)%mod;
		tree[j].f2=(tree[j].f2+fy)%mod;
		tree[i].sum=(tree[i].sum+calcs(tree[x].f1,tree[x].f2,mid-tree[x].l+1))%mod;
		tree[j].sum=(tree[j].sum+calcs(fx,fy,tree[x].r-mid))%mod;
		tree[x].f1=tree[x].f2=0;
	}
	//printf("%d %lld\n",x,tree[x].sum);
}
void update(int k,int l,int r){
	//printf("%d %d %d\n",tree[k].l,tree[k].r,k);
	if (l<=tree[k].l&&tree[k].r<=r){
		tree[k].f1=(tree[k].f1+f[tree[k].l-l+1])%mod;
		tree[k].f2=(tree[k].f2+f[tree[k].l-l+2])%mod;
		tree[k].sum=(tree[k].sum+calcs(f[tree[k].l-l+1],f[tree[k].l-l+2],tree[k].r-tree[k].l+1))%mod;
		return;
	}
	pushdown(k);
	int mid=(tree[k].l+tree[k].r)/2;
	if (l<=mid) update(k*2,l,r);
	if (r>mid) update(k*2+1,l,r);
	tree[k].sum=(tree[k*2].sum+tree[k*2+1].sum)%mod;
}
```
