[比赛链接]https://vjudge.net/contest/168929#problem)

## 比赛征程
> * Y : solved in the contest
> * A : solved after contest
> * SY : solving


  \# |  A  |  B  |  C  |  D  |  E  |
---|---|---|---|---|---|
|contest0|Y|  Y  |Y| A | A |



# 比赛中解决的问题
## A
### Problem description
> 让你模拟hash表输出第一次冲突的位置。

### Data Limit：n,p<=300  Time Limit: 1s

### Solution
> 保利模拟即可。
### Code
```cpp
	int n,p,x;bool flag=0;
	rd(p);rd(n);
	for(int i=1;i<=n;i++) {
		rd(x);
		if(hash[x%p]) {
			cout<<i<<endl;flag=1;return 0;
		}
		hash[x%p]=1;
	}
	if(!flag) puts("-1");
```
*****


## B
### Problem description
> 给你一个字符串定义每个字母的权值，要求插入k个字母，使得  $$\Sigma$$  i*该位置权值 最大。

### Data Limit：n <= 1e4  Time Limit: 2s
### Solution
> 贪心，每次往后面加最大的即可。（每次加的都是最优值，答案也是最优值，那么该贪心正确）每次最后加最大一定乘积最优。

### Code
```cpp
	for(int i=1;i<=t;i++) s=s+char(no);
	int l=s.length();
	for(int i=0;i<l;i++) {
		ans+=(i+1)*h[s[i]];
	}
```
*****

# 赛后补题

## C
### Problem description

> 给你一个序列，找出最长的一段连续的区间，使得最多进行一次将一个数换成另一个数，使得该区间单调上升.


### Data Limit：n <= 1e5  Time Limit: 4s

### Solution
>做题目之前要考虑各种因素，自己手推一遍，否则打出来是错的，或者边做边想细节容易错</br>
对于这一类改一小类而满足另一大类的问题，可以分治之，即先处理大的块然后考虑利用修改合并。
### Code
```cpp
	cin>>n;for(int i=1;i<=n;i++) cin>>a[i];
	int p=1;
	for(int i=1;i<=n;i++) {
		if(a[i]<=a[i-1]) {
			R[++cnt]=i-1;L[cnt]=p;p=i;
//			cout<<L[cnt]<<" "<<R[cnt]<<endl;
		}
	}
//	cout<<p<<" "<<n<<endl;
	L[++cnt]=p;R[cnt]=n;
//	cout<<L[cnt]<<" "<<R[cnt]<<endl;
	for(int i=1;i<=cnt;i++) ans=max(ans,R[i]-L[i]+1);
	for(int i=1;i<=cnt-1;i++) {
		if(L[i]==R[i]||L[i+1]==R[i+1]) {
			ans=max(ans,R[i+1]-L[i]+1);continue;
		}
		else{
			if(a[R[i]-1]+1<a[L[i+1]]||a[R[i]]+1<a[L[i+1]+1])
			ans=max(ans,R[i+1]-L[i]+1);
		}
		ans=max(ans,R[i+1]-L[i+1]+2);
		ans=max(ans,R[i]-L[i]+2);
	}
```
*****


## D
### Problem description
> 给你一个带权值的n*m的矩阵，每次去一行或取一列，获得这一行或列的权值之和的贡献，然后将这一整行或列减p，求操作k次最大权值和。
### Data Limit：k<= 1e5n,m<=1000  Time Limit: 2s
### Solution
> 这题是一个贪心题，枚举取i行，(k-i)列，因为每个点被重复算得次数相同，所以取得先后不影响，直接贪心取最大的i行(k-i)列，然后枚举一遍更新答案即可，整个过程用
优先队列来维护。</br>
总结：这类题目要样本法考虑，对于每个样本成立的东西对整体成立，并且要有这样题的敏感性。
### Code
```cpp
	scanf("%lld%lld%lld%lld",&n,&m,&k,&p);
	for(int i=1;i<=n;i++) {
		for(int j=1;j<=m;j++) {
			scanf("%lld",&a[i][j]);
			r[i]+=a[i][j];c[j]+=a[i][j];
		}
	}
	for(int i=1;i<=n;i++) q1.push(r[i]);
	for(int j=1;j<=m;j++) q2.push(c[j]);
	for(int i=1;i<=k;i++) {
		int hh=q1.top();ar[i]=ar[i-1]+hh;hh-=p*m;q1.pop();q1.push(hh);
		hh=q2.top();br[i]=br[i-1]+hh;hh-=p*n;q2.pop();q2.push(hh);
	}
	ans=-100000000000000000;
	for(int i=0;i<=k;i++) {
		ans=max(ans,ar[i]+br[k-i]-p*(k-i)*i);
	}
	cout<<ans<<endl;
```
*****

## E
### Problem description
> 一个有n个颜色的排列，对于特定的k，求将原序列分成最少的连续的段数，使每段的颜色数小于等于k。输出k=1~n的答案。

### Data Limit：n <= 1e5  Time Limit: 2s

### Solution
>一个序列A，要求支持以下操作，对于区间[l,r]分别加上fib[i-l+1..r-l+1] ,查询[l,r]的权值和。</br>
考虑到斐波那契额数列是可合并的，所以直接合并考虑细节即可。
</br>类线段树，考虑懒标记是否具有合并性!
# ##Code
```
using namespace std;
#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<cstdlib>
#define N 1200001
#define getmid int mid=(L[no]+R[no])>>1
#define lc no<<1
#define rc no<<1|1
#define int long long
const int mod=(1e9+9);
int L[N],R[N],p[N],q[N],a[N],f[N],n,l,r,ty,S[N],m,sum[N];
int getit(int x,int y,int l,int r) {
	int rel=0,rer=0;
	l--;
	if(l>=2) rel=((S[l-2]+1)%mod*(x)+((S[l-1])%mod*y%mod)%mod)%mod;
	if(l==1) rel=x;
	if(r>=2) rer=(((S[r-2]+1)%mod*(x))%mod+((S[r-1])%mod*y)%mod)%mod;
	if(r==1) rer=x;
	return (rer-rel+mod)%mod;
}
void pushup(int no) {
	if(L[no]!=R[no]) sum[no]=(sum[lc]+sum[rc])%mod;else sum[no]=0;
	sum[no]=(sum[no]+(getit(p[no],q[no],1,R[no]-L[no]+1)))%mod;
}
int query(int no,int l,int r) {
	if(L[no]==l&&R[no]==r) {
		return sum[no]%mod;
	}
	getmid;
	int it=getit(p[no],q[no],l-L[no]+1,r-L[no]+1);
//	cout<<it<<endl;
//	cout<<"xxxx ";cout<<no<<" "<<p[no]<<" "<<q[no]<<" "<<l<<" "<<r<<" "<<L[no]<<" "<<R[no]<<" "<<it<<endl;
	if(l>mid) return (query(rc,l,r)%mod+it)%mod;
	else if(r<=mid) return (query(lc,l,r)%mod+it)%mod;
	else {
		return (query(lc,l,mid)%mod+query(rc,mid+1,r)%mod+it%mod)%mod;
	}
}
void build(int no,int l,int r) {
	L[no]=l;R[no]=r;if(l==r) return;
	getmid;
	build(lc,l,mid);build(rc,mid+1,r);
}
void add(int no,int l,int r,int x) {

	if(L[no]==l&&R[no]==r) {
		p[no]=(p[no]+f[x])%mod;
		q[no]=(q[no]+f[x+1])%mod;
		pushup(no);
		return;
	}
	getmid;
	if(l>mid) add(rc,l,r,x);
	else if(r<=mid) add(lc,l,r,x);
	else {
		add(lc,l,mid,x);add(rc,mid+1,r,x+mid-l+1);
	}
	pushup(no);
}
char c;
void rd(int &x) {
	scanf("%lld",&x);
}
main() {
	rd(n);rd(m);
	for(int i=1;i<=n;i++) rd(a[i]);
	for(int i=1;i<=n;i++) {
		a[i]=(a[i]+a[i-1])%mod;
	}
	f[1]=1;f[2]=1;
	for(int i=3;i<=300001;i++) f[i]=(f[i-2]+f[i-1])%mod;
	for(int i=1;i<=300001;i++) S[i]=(S[i-1]+f[i])%mod;
	build(1,1,n);
	for(int i=1;i<=m;i++) {
		rd(ty);
		if(ty==1) {
			rd(l);rd(r);
			add(1,l,r,1);
		}
		else {
			rd(l);rd(r);
			printf("%lld\n",((query(1,l,r)%mod+a[r]%mod-a[l-1]%mod)+mod)%mod);
		}
	}
}
```
