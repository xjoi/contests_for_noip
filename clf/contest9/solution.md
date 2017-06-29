# A
貌似有人用线段树做了...其实没必要
由于每次增加的是区间，而查询只是在最后进行一次，可以考虑在l处+1，r+1处-1，然后用前缀和的方式从头到尾扫一遍，比线段树还快。
如果是线段树的话，也应该最后再把lazy标记pushdown，可以提高效率。
codeforces816B也是同样的思路。
```cpp
#include<cstdio>
#include<iostream>
using namespace std;
typedef long long LL;
const int N=120005;
LL init[N],l[N],r[N],d[N],ope[N],nar[N];
int main() {
	int n,m,k,a,b;
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=n;i++) scanf("%I64d",&init[i]);
	for(int i=1;i<=m;i++) scanf("%I64d%I64d%I64d",&l[i],&r[i],&d[i]);
	for(int i=1;i<=k;i++) {
		scanf("%d%d",&a,&b);
		ope[a]++;
		ope[b+1]--;
	}
	for(int i=1;i<=m;i++) {
		ope[i]+=ope[i-1];
		nar[l[i]]+=d[i]*ope[i];
		nar[r[i]+1]-=d[i]*ope[i];
	}
	for(int i=1;i<=n;i++) nar[i]+=nar[i-1];
	for(int i=1;i<=n;i++) printf("%I64d ",nar[i]+init[i]);
	return 0;
}

```

# B
题意是逐个删除点，借用zzy大爷的说法：遇难则反
反过来操作，每次动态加入节点，然后用Floyd的思路维护距离和，注意顺序!!!
先更新新节点和原有节点之间的最短路，才能再把新节点当成中转节点更新原有节点内的最短路!

```cpp
#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;
typedef long long LL;
const int N=505;
LL G[N][N],ans[N];
int ord[N],n;
int main() {
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++) scanf("%I64d",&G[i][j]);
	for(int i=1;i<=n;i++) scanf("%d",&ord[i]);
	for(int i=n;i>=1;i--) {
		for(int j=i;j<=n;j++)
			for(int k=i;k<=n;k++) G[ord[k]][ord[i]]=min(G[ord[k]][ord[i]],G[ord[k]][ord[j]]+G[ord[j]][ord[i]]);
		for(int j=i;j<=n;j++)
			for(int k=i;k<=n;k++) G[ord[i]][ord[k]]=min(G[ord[i]][ord[k]],G[ord[i]][ord[j]]+G[ord[j]][ord[k]]);
		for(int j=i+1;j<=n;j++)
			for(int k=i+1;k<=n;k++) G[ord[j]][ord[k]]=min(G[ord[j]][ord[i]]+G[ord[i]][ord[k]],G[ord[j]][ord[k]]);
		for(int j=i;j<=n;j++)
			for(int k=i;k<=n;k++) ans[i]+=G[ord[j]][ord[k]];
	}
	for(int i=1;i<=n;i++)  printf("%I64d ",ans[i]);
	printf("\n");
	return 0;
}
```

# C

第一眼就看出是动态规划，dp[i][j][k][l]表示第i步原来河岸仍有j个50kg的人，k个100kg的人，l为1则船在对岸，为0船在此岸。
然后动规即可，注意i要取到200为宜，注意边界，注意及时取模...

```cpp
#include<cstdio>
#include<iostream>
using namespace std;
typedef long long LL;
const int N=51;
const LL mod=1e9+7;
int n,k,n1=0,n2=0;
LL dp[202][N][N][2],C[N][N];//dp[st][l1][l2][boat] boat=0->this;1->oppo l1,l2:this side
int main() {
	int x;
	scanf("%d%d",&n,&k);
	k/=50;
	for(int i=1;i<=n;i++) {
		scanf("%d",&x);
		if(x==50) n1++;
		else n2++;
	}
	for(int i=0;i<=n;i++) C[i][0]=1,C[i][i]=1;
	for(int i=2;i<=n;i++)
		for(int j=1;j<i;j++) {
			C[i][j]=(C[i-1][j-1]+C[i-1][j])%mod;
		}
	dp[0][n1][n2][0]=1;
	for(int st=0;st<=200;st++) {
		if(dp[st][0][0][1]) {
			printf("%d\n%I64d\n",st,dp[st][0][0][1]);
			return 0;
		}
		for(int a1=0;a1<=n1;a1++) {
			for(int a2=0;a2<=n2;a2++) {
				if(dp[st][a1][a2][0]) {
					for(int u=0;u<=a1;u++) {
						if(u>k) break;
						for(int v=0;v<=a2;v++) {
							if(u+v*2>k) break;
							if(u+v==0) continue;
							dp[st+1][a1-u][a2-v][1]+=(C[a2][v]*(dp[st][a1][a2][0]*C[a1][u])%mod)%mod;
							dp[st+1][a1-u][a2-v][1]%=mod;
						}
					}
				}
				if(dp[st][a1][a2][1]) {
					for(int u=0;u<=n1-a1;u++) {
						if(u>k) break;
						for(int v=0;v<=n2-a2;v++) {
							if(u+v*2>k) break;
							if(u+v==0) continue;
							dp[st+1][a1+u][a2+v][0]+=(C[n2-a2][v]*(dp[st][a1][a2][1]*C[n1-a1][u])%mod)%mod;
							dp[st+1][a1+u][a2+v][0]%=mod;
						}
					}
				}
			}
		}
	}
	printf("-1\n0\n");
	return 0;
}
```

# D

动态规划，up[i][j]记录第i行两个黑格相距离为j是上方不递减的方案数，down[i][j]记录第i行距离为j，i+1行取的距离小于j时的方案数，即可水过.
注意及时取模，且统计答案时要注意hole可以左右平移.
```cpp
#include<cstdio>
#include<iostream>
using namespace std;
typedef long long LL;
const int N=2001;
const LL mod=1e9+7;
LL up[N][N],down[N][N],he[N];
int main() {
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=2;i<=m;i++) up[1][i]=1;
	for(int i=2;i<=n;i++) {
		for(int j=2;j<=m;j++) up[i][j]=(up[i][j-1]+up[i-1][j])%mod;
		for(int j=2;j<=m;j++) up[i][j]=(up[i][j]+up[i][j-1])%mod;
		for(int j=2;j<=m;j++) up[i][j]=(up[i][j]+1)%mod;
	}
	for(int i=2;i<=m;i++) down[n][i]=1;
	for(int i=n-1;i>=1;i--) {
		for(int j=2;j<=m;j++) down[i][j]=(down[i][j-1]+up[n-i][j])%mod;
		for(int j=2;j<=m;j++) down[i][j]=(down[i][j]+down[i][j-1])%mod;
		for(int j=2;j<=m;j++) down[i][j]=(down[i][j]-up[n-i][j]+1)%mod;
	}
	LL ans=0;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++) ans=(ans+((up[i][j]*down[i][j])%mod*(m-j+1))%mod)%mod;
	printf("%I64d\n",ans);
}
```

# E

线段树更改，先全部读进来离散化，然后操作
我们在线段树中维护以下值：
num：该区间有多少个点。
sum：该区间点的横坐标之和。
ans ：该区间每一对点的距离之和。
有了上面的量，下面关键的一点就是合并，其实很容易，设当前区间为t[p],其左子树为t[ls],右子树为[rs],则：
t[p].sum=t[ls].sum+t[rs].sum
t[p].num=t[ls].num+t[rs].num
t[p].ans=t[rs].sum*t[ls].num-t[rs].num*t[ls].sum+t[ls].ans+t[rs].ans
貌似Anoxx是在线离散的，妙啊dalao.

```cpp

#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long LL;
const int N=110000;
LL init[N],tab[N*2],ope[N][3],ch[N],h[N],num[N*8],sum[N*8],ans[N*8],nn,ss,aa;
bool ini[N*2];
int sz=0;
inline void Update(int x,int l,int r) {
	if(l==r) return;
	int lc=(x<<1),rc=lc+1;
	sum[x]=sum[lc]+sum[rc];
	num[x]=num[lc]+num[rc];
	ans[x]=ans[lc]+ans[rc]+num[lc]*sum[rc]-num[rc]*sum[lc];
}
inline void Build(int x,int l,int r) {
	if(l==r) {
		if(ini[l]) {
			num[x]=1;sum[x]=tab[l];ans[x]=0;
		}
		return;
	}
	int mid=(l+r)>>1,lc=(x<<1),rc=lc+1;
	Build(lc,l,mid);
	Build(rc,mid+1,r);
	Update(x,l,r);
}
inline void Insert(int x,int l,int r,int pos,int tp) {
	if(l==r) {
		if(tp==1) {
			num[x]=1;sum[x]=tab[l];ans[x]=0;
		} else num[x]=sum[x]=ans[x]=0;
		return;
	}
	int mid=(l+r)>>1;
	if(pos<=mid) Insert(x<<1,l,mid,pos,tp);
	else Insert(x<<1|1,mid+1,r,pos,tp);
	Update(x,l,r);
}
inline void Query(int x,int l,int r,int a,int b) {
	if(l>r) return;
	if(l==a&&r==b) {
		aa=aa+ans[x]+nn*sum[x]-num[x]*ss;
		nn+=num[x];ss+=sum[x];
		return;
	}
	if(l==r) return;
	int mid=(l+r)>>1;
	if(b<=mid) Query(x<<1,l,mid,a,b);
	else if(a>mid) Query(x<<1|1,mid+1,r,a,b);
	else Query(x<<1,l,mid,a,mid),Query(x<<1|1,mid+1,r,mid+1,b);
}
int main() {
	int n,q;
	scanf("%d",&n);
	for(int i=1;i<=n;i++) {
		scanf("%I64d",&init[i]);
		tab[i]=ch[i]=h[i]=init[i];
	}
	sz=n;
	scanf("%d",&q);
	for(int i=1;i<=q;i++) {
		scanf("%I64d%I64d%I64d",&ope[i][0],&ope[i][1],&ope[i][2]);
		if(ope[i][0]==1) {
			ch[ope[i][1]]+=ope[i][2];
			tab[++sz]=ch[ope[i][1]];
		}
	}
	sort(init+1,init+n+1);
	sort(tab+1,tab+sz+1);
	unique(tab+1,tab+sz+1);
	for(int i=1;i<=sz;i++) if(tab[i]>tab[i+1]) sz=i;
	int p=1;
	for(int i=1;i<=n;i++) {
		while(tab[p]!=init[i]&&p<=sz) p++;
		ini[p]=1;
	}
	Build(1,1,sz);
	int l,r;
	for(int i=1;i<=q;i++) {
		if(ope[i][0]==2) {
			l=std::lower_bound(tab+1,tab+sz+1,ope[i][1])-tab;
			while(tab[l]<ope[i][1]&&l<=sz) l++;
			if(l==0) l=1;
			if(l>sz) {
				printf("0\n");
				continue;
			}
			r=std::lower_bound(tab+1,tab+sz+1,ope[i][2])-tab;
			if(r>sz) r=sz;
			while(tab[r]>ope[i][2]&&r>=1) r--;
			if(r<=0) {
				printf("0\n");
				continue;
			}
			nn=ss=aa=0;
			Query(1,1,sz,l,r);
			printf("%I64d\n",aa);
		} else {
			l=std::lower_bound(tab+1,tab+sz+1,h[ope[i][1]])-tab;
			h[ope[i][1]]+=ope[i][2];
			r=std::lower_bound(tab+1,tab+sz+1,h[ope[i][1]])-tab;
			Insert(1,1,sz,l,-1);
			Insert(1,1,sz,r,1);
		}
	}
	return 0;
}

```
