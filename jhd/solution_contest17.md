

[Contest 17-比赛链接](https://cn.vjudge.net/contest/171671)

# 比赛中解决的问题
## A
### Problem description
> 给出一个大小为p的哈希表,哈希函数h(x)=x%p,给出n个加入哈希表的数,求出在第几次操作后发生冲突.如果没有冲突,输出-1.

### Data Limit：2 ≤ p, n ≤ 300  Time Limit: 1s
### Solution
> 直接模拟,用bool数组储存该位置是否有数.

### Code
```cpp
bool A[301];
int main(){
	int n,p;
	scanf("%d%d",&p,&n);
	for (int i=1;i<=n;i++){
		int x;
		scanf("%d",&x);
		int h=x%p;
		if (A[h]){
			printf("%d",i);
			return 0;
		}else{
			A[h]=1;
		}
	}
	printf("-1");
}
```
*****


## B
### Problem description
> 给出26个字母的权值w[c],和字符串s.定义字符串的权值为*每一位上的字母权值\*这一位的下标*的和(下标从1开始)(即
![img](https://odzkskevi.qnssl.com/558267f8b698e3bfdc0383fcc66377e5?v=1500330448), si表示第i位上的字符).求出加入k个字符后所得到的字符串的权值最大值.

### Data Limit：1 ≤ |s| ≤ 10^3 0 ≤ k ≤ 10^3 Time Limit: 1s
### Solution
> 显然,取出权值最大的字母加到最后能够使结果最大.计算出来即可.

### Code
```cpp
int w[30],k;
string s;
int main(){
	cin>>s>>k;
	int maxx=0;
	for (int i=1;i<=26;i++) cin>>w[i],maxx=max(w[i],maxx);
	int Ans=0;
	for (int i=0;i<s.length();i++){
		Ans+=w[s[i]-'a'+1]*(i+1);
	}
	for (int i=s.length()+1;i<=s.length()+k;i++) Ans+=maxx*i;
	cout<<Ans;
}
```
*****


## C
### Problem description
> 给出一个序列,求出最长的一个子序列,使得改动其中至多一个数的值之后,这个序列成为严格上升序列.

### Data Limit：1 ≤ n ≤ 10^5, 1 ≤ ai ≤ 10^9 Time Limit: 1s

### Solution
> 先预处理f[i]和g[i]分别表示"到i位为止最长递增子序列长度"和"从i位开始最长递增子序列长度".
> 
> 则答案第一种可能:f[i]+1或g[i]+1,表示更改序列的最后一位(或首位).(注意细节:i=n时不存在f[i]+1,只存在f[i],i=1时不存在g[i]+1,只存在g[i].)
> 
> 答案第二种可能,枚举修改的节点i,若A[i+1]-A[i-1]>=2(即可以修改成为严格递增),则答案为f[i-1]+1+g[i+1].
> 
> 则答案为两者中的最大值.

### Code
```cpp
int A[100005],B[100005],C[100005];
int main(){
	int n;
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%d",&A[i]);
	int tmp=0,Ans=0;
	B[n]=1;
	for (int i=n-1;i>0;i--){
		if (A[i]<A[i+1]) B[i]=B[i+1]+1;
		else B[i]=1;
		Ans=max(Ans,i==1?B[i]:B[i]+1);
	}
	C[1]=1;
	for (int i=2;i<=n;i++){
		if (A[i-1]<A[i]) C[i]=C[i-1]+1;
		else C[i]=1;
		Ans=max(Ans,i==n?C[i]:C[i]+1);
	}
	A[0]=0;A[n+1]=1e9+1;
	B[0]=0;B[n+1]=0;
	C[0]=0;C[n+1]=0;
	for (int i=1;i<=n;i++){
		if (A[i+1]-A[i-1]>=2) Ans=max(Ans,B[i+1]+C[i-1]+1);
	}
	printf("%d",Ans);
	
}
```
*****

# 赛后补题

## D
### Problem description
> 给出一个n*m的矩阵,每次可以选一行或一列,愉快值增加这一行(列)数字和,之后将每一个数字减p.求k次操作后,愉快值的最大值.

### Data Limit：1 ≤ n, m ≤ 10^3; 1 ≤ k ≤ 10^6; 1 ≤ p ≤ 100  Time Limit: 2s
### Solution
> 单独考虑行(列),则显然取权值和最大的行(列).
> 
> 但是同时可以取行和列时,就无法保证每次取权值最大的行或列的正确性.反例如下:
> 
> **Input**
> 
	3 2 3 1
	-1 0
	-1 0
	-1 0

>**正确答案:** -3 (3次分别取3行)
>
>但按照那种贪心会输出-4(先取第二列,再取1,2行).

> 可以考虑既然每行每列分开时,取最大得到的答案最优,就可以预处理每行(列)权值总和,再(用堆或优先队列)求出取i行(列)的最大权值.

> 可以证明先取行和先取列效果相同.(假定先取行)

> 则可以枚举k次操作中取的行数i(0~k行),考虑取行时对列的影响,只会把在各行和各列的交叉点(如果某一行取了多次,则算作多行)的数减去p.则会使总答案减少i\*(k-i)\*p,求出所有答案的最大值即可.

### Code
```cpp
int col[1001],row[1001],cold=0,rowd=0,A[1001][1001];
priority_queue<LL> Q1,Q2;
LL V1[1000001],V2[1000001];
int main(){
	int n,m,k,p;
	scanf("%d%d%d%d",&n,&m,&k,&p);
	for (int i=1;i<=n;i++)
		for (int j=1;j<=m;j++) 
			scanf("%d",&A[i][j]),col[j]+=A[i][j],row[i]+=A[i][j];
	for (int i=1;i<=n;i++) Q1.push(row[i]);
	for (int i=1;i<=m;i++) Q2.push(col[i]);
	for (int i=1;i<=k;i++){
		LL t=Q1.top();Q1.pop();V1[i]=V1[i-1]+t;Q1.push(t-p*m);
		   t=Q2.top();Q2.pop();V2[i]=V2[i-1]+t;Q2.push(t-p*n);
	}
	LL Ans=-1e15;
	for (int i=0;i<=k;i++){
		int j=k-i;
		LL tmp=V1[i]+V2[j]-1ll*i*j*p;
		Ans=max(Ans,tmp);
	}
	cout<<Ans;	
}
```
*****

## E
### Problem description
> 给出一个数组A[1..n].有m次操作,可以执行下列两种操作中的一种:
> 
> 1. 将[l..r]区间内的数A[i]加上f\[i-l+1\]\(f[k]为斐波那契数列1,1,2,3....的第k项)
> 2. 求出[l..r]区间的数的总和(模1e9+9)

### Data Limit：1 ≤ n, m ≤ 300000 ,1 ≤ ai ≤ 10^9 Time Limit: 4s

### Solution
> **法1: 线段树**
> 
> 可以在保存区间和的基础上设计两个`lazy tag`,分别储存该区间累加的斐波那契数列的第1,2项. 显然累加斐波那契数列后得到的数列也满足F[n]=F[n-1]+F[n-2].

> 在下传(并更新区间和)的过程中,需要用到下面的性质:
>
	若一个数列f前两项为a,b,且满足f[n]=f[n-1]+f[n-2](n>=3),则存在下列两个结论:
	1.f[n]=b*fib(n-1)+a*fib(n-2);(n>=3)
	2.Sum[n]=f[n+2]-f[2]. (Sum[n]=f[1]+f[2]+...+f[n])

> 两个结论均可以用数学归纳法证明.

> **法2:分块**
> 
> 将区间分成sqrt(n),对于每个分块同样记录区间和以及累加数列的前两项.
> 
> 修改时,对于完整的分块,只需要对区间和以及数列进行修改即可;
> 对于不完整的分块,暴力修改单点并更新区间和.
> 
> 查询时,对于完整的分块,直接累加;
> 对于不完整的分块,暴力求出单点上累加数列的值,并加到总答案中.
> 
> 时间复杂度n\*sqrt(n),如果常数小,不会超时.
> 
> (但是听说有人也造出能卡分块的数据...)
### Code

**(线段树)**

```cpp

typedef long long LL;
const int maxn=300000+1;
const int mod=1e9+9;
inline void add(int &x,int y){x+=y;if(x>=mod) x-=mod;}
inline int sub(int x,int y){x-=y;if(x<0) x+=mod;return x;}
int D1[4*maxn],D2[4*maxn],S[4*maxn];
int A[maxn],fib[maxn+10],Sf[maxn+10];
void build(int node,int l,int r){
	if (l==r){
		S[node]=A[l];
		return;
	}
	int mid=(l+r)>>1;
	build(node<<1,l,mid);build(node<<1|1,mid+1,r);
	S[node]=(S[node<<1]+S[(node<<1)|1])%mod;
}

inline int getit(int a,int b,int n){
	if (n==1) return a;
	if (n==2) return b;
	return ((1ll*b*fib[n-1])%mod+(1ll*a*fib[n-2])%mod)%mod;
}
inline int getsum(int a,int b,int n){
	return sub(getit(a,b,n+2),b);
}
void pushdown(int node,int l,int r){
	int mid=(l+r)>>1;
	if (D1[node]||D2[node]){
		int a=D1[node],b=D2[node];
		add(D1[node<<1],a);
		add(D2[node<<1],b);
		int x=getit(a,b,mid-l+2),y=getit(a,b,mid-l+3);
		add(D1[node<<1|1],x);
		add(D2[node<<1|1],y);
		add(S[node<<1],getsum(a,b,mid-l+1));
		add(S[node<<1|1],getsum(x,y,r-mid));
		D1[node]=D2[node]=0;
	}
}
void change(int node,int l,int r,int fl,int fr,int L){
	if (l==r){
		add(S[node],fib[l-L+1]);
	}else if (l==fl&&r==fr){
		add(D1[node],fib[l-L+1]);
		add(D2[node],fib[l-L+2]);
		add(S[node],sub(Sf[r-L+1],Sf[l-L]));
	}else{
		int mid=(l+r)>>1;
		pushdown(node,l,r);
		if (fl<=mid) change(node<<1,l,mid,fl,min(fr,mid),L);
		if (fr>mid) change(node<<1|1,mid+1,r,max(mid+1,fl),fr,L);
		S[node]=(S[node<<1]+S[(node<<1)|1])%mod;
	}
}
int query(int node,int l,int r,int fl,int fr){
	if (l==r||(fl==l&&fr==r))return S[node];
	pushdown(node,l,r);
	S[node]=(S[node<<1]+S[(node<<1)|1])%mod;
	int Ans=0,mid=(l+r)>>1;
	if (fl<=mid) add(Ans,query(node<<1,l,mid,fl,min(fr,mid)));
	if (fr>mid)  add(Ans,query(node<<1|1,mid+1,r,max(mid+1,fl),fr));
	return Ans;
}

int main(){
	int n,m;
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++) scanf("%d",&A[i]);
	fib[1]=fib[2]=1;Sf[1]=1,Sf[2]=2;
	for (int i=3;i<=n+2;i++) fib[i]=(fib[i-1]+fib[i-2])%mod,Sf[i]=(Sf[i-1]+fib[i])%mod;
	build(1,1,n);
	while(m--){
		int q,a,b;
		scanf("%d%d%d",&q,&a,&b);
		if (q==1) change(1,1,n,a,b,a);
		if (q==2) printf("%d\n",query(1,1,n,a,b));
	}
}
```

**(分块)**

```cpp
int A[300001],D1[30001],D2[30001],S[30001];
int fib[300001],sfi[300001];
int main(){
	int n,m;
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++) scanf("%I64d",&A[i]);
	fib[1]=1;fib[2]=1;
	sfi[1]=1;sfi[2]=2;
	for (int i=3;i<=n;i++) fib[i]=(fib[i-1]+fib[i-2])%mod,sfi[i]=(sfi[i-1]+fib[i])%mod;
	int sq=floor(sqrt(n));
	for (int i=1;i<=n;i++){
		int pl=i/sq;
		S[pl]=(S[pl]+A[i])%mod;
	}
	while(m--){
		int q,l,r;
		scanf("%d%d%d",&q,&l,&r);
		if (q==1){
			int lb=l/sq,rb=r/sq;
			for (int i=l;i<=min(r,(lb+1)*sq-1);i++) A[i]=(A[i]+fib[i-l+1])%mod,S[lb]=(S[lb]+fib[i-l+1])%mod;
			for (int i=lb+1;i<rb;i++){
				D1[i]=(D1[i]+fib[i*sq-l])%mod;
				D2[i]=(D2[i]+fib[i*sq-l+1])%mod;
				S[i]=(S[i]+sfi[(i+1)*sq-l]-sfi[i*sq-l])%mod;
				S[i]=(S[i]+mod)%mod;
			}
			if (lb!=rb)
				for (int i=rb*sq;i<=r;i++) A[i]=(A[i]+fib[i-l+1])%mod,S[rb]=(S[rb]+fib[i-l+1])%mod;
		}else{
			int Ans=0;
			int lb=l/sq,rb=r/sq,f0=D1[lb],f1=D2[lb];
			for (int i=lb*sq;i<l;i++){
				int f2=(f0+f1)%mod;f0=f1,f1=f2;
			}
			for (int i=l;i<=min(r,(lb+1)*sq-1);i++){
				Ans=(Ans+f1)%mod;Ans=(Ans+A[i])%mod;int f2=(f0+f1)%mod;f0=f1,f1=f2;
			}
			for (int i=lb+1;i<rb;i++) Ans=(Ans+S[i])%mod;
			f0=D1[rb],f1=D2[rb];
			if (lb!=rb)
				for (int i=rb*sq;i<=r;i++){
					Ans=(Ans+f1)%mod;Ans=(Ans+A[i])%mod;int f2=(f0+f1)%mod;f0=f1,f1=f2;
				}
			printf("%d\n",Ans);
		}
	}
}
```