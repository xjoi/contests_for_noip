## 比赛征程
> * Y : solved in the contest
> * A : solved after contest
> * W : solving

  \# |  A  |  B  |  C  |  D  |  E  |
---|---|---|---|---|---|
| contest17 |Y|Y|Y|Y|A|

[比赛链接](https://cn.vjudge.net/contest/171671#overview)

## A
### Problem description
> 略

### Data Limit：略  Time Limit: 略
### Solution
> 略

### Code
```cpp
#include<cstdio>
#include<iostream>
#include<string>
#include<cstring>
#include<vector>
#include<queue>
#include<map>
#include<cmath>
#include<algorithm>
#define ll long long
#define db double
#define mod 1000000007
#define xxx 520233
using namespace std;
map<int,int>mp;
int p,n,x;

int main(){
	mp.clear();
	scanf("%d%d",&p,&n);
	for (int i=1;i<=n;i++){
		scanf("%d",&x);
		x%=p;
		if (mp[x]){
			printf("%d",i);
			return 0;
		}
		mp[x]++;
	}
	printf("-1");
}
```
*****

## B
### Problem description
> 略

### Data Limit：略  Time Limit: 略
### Solution
> 略

### Code
```cpp
#include<cstdio>
#include<iostream>
#include<string>
#include<cstring>
#include<vector>
#include<queue>
#include<map>
#include<cmath>
#include<algorithm>
#define ll long long
#define db double
#define mod 1000000007
#define xxx 520233
using namespace std;
int p,n,a[xxx],l,mx=0;
char s[xxx];
ll ans;

int main(){
	scanf("%s",s);
	scanf("%d",&n);
	for (int i=0;i<26;i++){
		scanf("%d",&a[i]);
		if (a[i]>a[mx])
			mx=i;
	}
	
	l=strlen(s);
	for (int i=0;i<l;i++){
		ans+=(i+1)*a[s[i]-'a'];
	}
	for (int i=1;i<=n;i++){
		ans+=(i+l)*a[mx];
	}
	printf("%lld",ans);
}
```
*****
## C
### Problem description
> 细节题。。</br>
  定义一个序列合法当且仅当这个序列可以通过改变一个元素的键值使序列严格递增。。</br>
  求一个给定序列s(|s|<1e5)的最长合法子序列。。</br>

### Time Limit: 1s
### Solution
> 预处理后暴力枚举更改哪个元素。。</br>

### Code
```cpp
#include<cstdio>
#include<iostream>
#include<string>
#include<cstring>
#include<vector>
#include<queue>
#include<map>
#include<cmath>
#include<algorithm>
#define ll long long
#define db double
#define mod 1000000007
#define xxx 520233
using namespace std;
int n,a[xxx],nex[xxx],pre[xxx],ans;

int main(){
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	if (n==1){
		printf("1");
		return 0;
	}
	pre[1]=1;
	for (int i=2;i<=n;i++){
		if (a[i]>a[i-1])
			pre[i]=pre[i-1];
		else
			pre[i]=i;
	}
	nex[n]=n;
	for (int i=n-1;i>=1;i--){
		if (a[i]<a[i+1])
			nex[i]=nex[i+1];
		else
			nex[i]=i;
	}
	ans=max(nex[2],n-pre[n-1]+1);
	for (int i=2;i<n;i++){
		if (a[i-1]+1<=a[i+1]-1){
			ans=max(ans,nex[i+1]-pre[i-1]+1);
		}else{
			ans=max(ans,nex[i+1]-i+1);
			ans=max(ans,i-pre[i-1]+1);
		}
	}
	printf("%d",ans);
}
```
*****
## D
### Problem description
> 给出一个矩阵(行数列数均在1000以内)。。</br>
  定义单次操作可以选择一行或一列,ans的增加值为这一串数字的和,并将这一串数字都减p(p<=100)。。</br>
  对于强制k(k<=1e6)次操作,最大化ans。。</br>

### Time Limit: 2s
### Solution
> 行和列分开贪心。。然后暴力枚举对行下手的次数。。</br>

### Code
```cpp
#include<cstdio>
#include<iostream>
#include<string>
#include<cstring>
#include<vector>
#include<queue>
#include<map>
#include<cmath>
#include<algorithm>
#define ll long long
#define db double
#define mod 1000000007
#define xxx 520233
using namespace std;
struct cmp{
	bool operator()(ll &a,ll &b){
		return a<b;
	}
};
priority_queue<ll,vector<ll>,cmp>q1,q2;
ll n,m,k,p,a[10100],b[10100],cg1,cg2,x;
ll ans,doa[1001000],dob[1001000];

int main(){
	while (!q1.empty()) q1.pop();
	while (!q2.empty()) q2.pop();
	scanf("%I64d%I64d%I64d%I64d",&n,&m,&k,&p);
	memset(a,0,sizeof(a));
	memset(b,0,sizeof(b));
	for (int i=1;i<=n;i++){
		for (int j=1;j<=m;j++){
			scanf("%I64d",&x);
			a[i]+=x;
			b[j]+=x;
		}
	}
	
	for (int i=1;i<=n;i++)
		q1.push(a[i]);
	for (int i=1;i<=m;i++)
		q2.push(b[i]);	
	
	ll t;
	doa[0]=0;
	for (int i=1;i<=k;i++){
		t=q1.top();
		doa[i]=doa[i-1]+t;
		q1.pop();
		t-=p*m;
		q1.push(t);
	}
	
	dob[0]=0;
	for (int i=1;i<=k;i++){
		t=q2.top();
		dob[i]=dob[i-1]+t;
		q2.pop();
		t-=p*n;
		q2.push(t);
	}
	
	ll ans=-5202333333333333;
	for (int i=0;i<=k;i++){
		t=doa[i]+dob[k-i]-(k-i)*i*p;
		ans=max(ans,t);
	}
	
	printf("%I64d",ans);
}
```
*****
## E
### Problem description
> 给出一个序列a(|a|<=3e5)。。</br>
  要求支持两种操作:</br>
    1-将一段区间的值按从左到右加上斐波那契数列(及从左边界到右边界分别加上1,1,2,3,5,8...)。。</br>
    2-求区间和。。</br>

### Time Limit: 2s
### Solution
> 据说此题有多种解法。。</br>
  解1：线段树,将区间加入斐波那契改为a[i]+=k1[i]\*x+k2[i]\*y。。</br>
  解2：分块,原理同上,懒得写。。</br>
  解3：我不会。。</br>
  
### Code
```cpp
#include<cstdio>
#include<iostream>
#include<string>
#include<cstring>
#include<vector>
#include<queue>
#include<map>
#include<cmath>
#include<algorithm>
#define ll long long
#define db double
#define mod 1000000009
#define xxx 520233
#define yyy 5202333
using namespace std;
ll fb[xxx],ffb[xxx],u[3][xxx],su[3][xxx],n,m,a[xxx];
struct LT{
	ll sum,lx,ly;
}tr[yyy];

void build(ll x,ll l,ll r){
	tr[x]=(LT){0,0,0};
	if (l==r){
		tr[x].sum=a[l];
		return;
	}
	ll mid=(l+r)>>1;
	build(x<<1,l,mid);
	build(x<<1|1,mid+1,r);
	tr[x].sum=(tr[x<<1].sum+tr[x<<1|1].sum)%mod;
	return;
}

void D(ll x,ll l,ll r){
	if (tr[x].lx==0&&tr[x].ly==0) return;
	ll mid=(l+r)>>1;
	tr[x<<1].sum=(tr[x<<1].sum + tr[x].lx*(su[1][mid]-su[1][l-1]) + tr[x].ly*(su[2][mid]-su[2][l-1]) )%mod;
	tr[x<<1].lx=(tr[x<<1].lx+tr[x].lx)%mod; tr[x<<1].ly=(tr[x<<1].ly+tr[x].ly)%mod;
	tr[x<<1|1].sum=(tr[x<<1|1].sum + tr[x].lx*(su[1][r]-su[1][mid]) + tr[x].ly*(su[2][r]-su[2][mid]) )%mod;
	tr[x<<1|1].lx=(tr[x<<1|1].lx+tr[x].lx)%mod; tr[x<<1|1].ly=(tr[x<<1|1].ly+tr[x].ly)%mod;
	tr[x].lx=tr[x].ly=0;
	tr[x].sum=(tr[x<<1].sum+tr[x<<1|1].sum)%mod;
	//if ((tr[x<<1].sum+tr[x<<1|1].sum-tr[x].sum)%mod!=0) while (1);
}

void cg(ll x,ll l,ll r,ll st,ll en,ll xx,ll yy){
	if (l==st&&r==en){
		tr[x].sum=(tr[x].sum+xx*(su[1][r]-su[1][l-1])+yy*(su[2][r]-su[2][l-1]))%mod;
		tr[x].lx=(tr[x].lx+xx)%mod;
		tr[x].ly=(tr[x].ly+yy)%mod;
		return;
	}
	D(x,l,r);
	ll mid=(l+r)>>1;
	if (en<=mid) cg(x<<1,l,mid,st,en,xx,yy);
	else if (st>mid) cg(x<<1|1,mid+1,r,st,en,xx,yy);
	else { cg(x<<1,l,mid,st,mid,xx,yy);cg(x<<1|1,mid+1,r,mid+1,en,xx,yy); }
	tr[x].sum=(tr[x<<1].sum+tr[x<<1|1].sum)%mod;
}

ll que(ll x,ll l,ll r,ll st,ll en){
	if (l==st&&r==en){
		return tr[x].sum%mod;
	}
	D(x,l,r);
	ll mid=(l+r)>>1;
	if (en<=mid) return que(x<<1,l,mid,st,en)%mod;
	if (st>mid) return que(x<<1|1,mid+1,r,st,en)%mod;
	return (que(x<<1,l,mid,st,mid)+que(x<<1|1,mid+1,r,mid+1,en))%mod;
}

ll FB(ll x){
	if (x>=0) return fb[x];
	x=-x;
	return ffb[x];
}

int main(){
	cin>>n>>m;
	for (int i=1;i<=n;i++){
		scanf("%I64d",&a[i]);
	}
	fb[0]=0;fb[1]=1;
	for (int i=2;i<=n+233;i++){
		fb[i]=(fb[i-1]+fb[i-2])%mod;
		u[1][i]=fb[i-2];
		u[2][i]=fb[i-1];
	}
	for (int i=0;i<=n+233;i++){
		ffb[i]= (i&1)?fb[i]:-fb[i];
	}
	
	u[1][1]=1;u[2][1]=0;
	su[1][0]=su[2][0]=0;
	for (int i=1;i<=n+233;i++){
		for (int j=1;j<=2;j++)
			su[j][i]=(su[j][i-1]+u[j][i])%mod;
	}
	
	build(1,1,n);
	ll t,x,y;
	while (m--){
		scanf("%I64d%I64d%I64d",&t,&x,&y);
		if (t==1){
			cg(1,1,n,x,y,FB(2-x),FB(3-x));
		}else{
			printf("%I64d\n",(que(1,1,n,x,y)%mod+mod)%mod);
		}
	}
}
```
*****
