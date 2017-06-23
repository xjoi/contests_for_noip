# B

倒过来做Floyed。

和这题差不多的还有**xjoi1446长城之北**，那题是倒过来并查集。

# C

首先可以dp求出最短次数。然后设f[i][j][k]表示还剩下i个50kg，j个100kg，通过k次过河的方法数。

然后就可以暴力枚举去几个，回几个，进行状态转移。对于哪几个过去，哪几个回来的组合数可以用杨辉三角预处理。

### 注意及时取模！！！

# D

卡题意啊！！！

知道题意后，大致方法就是dp+前缀和优化，不过我还没有写，coming soon........

# E

有一个神奇的结论！！！

告诉你两个区间的一些信息：点的个数n1,n2，坐标总和s1,s2，区间内答案a1,a2，你就可以说出第三个区间的答案a3=n1*s2-n2*s1+a1+a2。

知道这个以后，就可以用线段树动态维护这3个值————当然是要动态开点啦~~或者离散~~

```cpp

#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<cmath>
#include<vector>
using namespace std;
#define ll long long
const ll MAXN=100000;
const ll L=-1000000000;
const ll R=1000000000;
ll n,m;
ll x[MAXN+10];
ll t1[50*MAXN+10],t2[50*MAXN+10],t3[50*MAXN+10];
ll lc[50*MAXN+10],rc[50*MAXN+10];
ll cnt;
void push(const ll o,const ll l,const ll r,const ll q,const int k)
{
	if(l==r)
	{
		t1[o]+=k;t2[o]+=k*l;
		return;
	}
	ll mid=(l+r)>>1;
	if(q<=mid)
	{
		if(!lc[o])
		{
			++cnt;
			lc[o]=cnt;
		}
		push(lc[o],l,mid,q,k);
	}
	else
	{
		if(!rc[o])
		{
			++cnt;
			rc[o]=cnt;
		}
		push(rc[o],mid+1,r,q,k);
	}
	t1[o]=t1[lc[o]]+t1[rc[o]];t2[o]=t2[lc[o]]+t2[rc[o]];t3[o]=t3[lc[o]]+t3[rc[o]]+t1[lc[o]]*t2[rc[o]]-t1[rc[o]]*t2[lc[o]];
}
void push(const ll q){push(1,L,R,q,1);}
void pull(const ll q){push(1,L,R,q,-1);}
vector<ll> query(const ll o,const ll l,const ll r,const ll ql,const ll qr)
{
	if(l==ql&&r==qr)
	{
		vector<ll> res;res.push_back(t1[o]);res.push_back(t2[o]);res.push_back(t3[o]);
		return res;
	}
	ll mid=(l+r)>>1;
	if(qr<=mid)
	{
		if(lc[o])return query(lc[o],l,mid,ql,qr);
		else return vector<ll>(3);
	}
	else if(mid<ql)
	{
		if(rc[o])return query(rc[o],mid+1,r,ql,qr);
		else return vector<ll>(3);
	}
	else
	{
		vector<ll> a=query(lc[o],l,mid,ql,mid),b=query(rc[o],mid+1,r,mid+1,qr),res;
		res.push_back(a[0]+b[0]);res.push_back(a[1]+b[1]);res.push_back(a[0]*b[1]-b[0]*a[1]+a[2]+b[2]);
		return res;
	}
}
ll query(const ll l,const ll r){return query(1,L,R,l,r)[2];}
int main()
{
	scanf("%I64d",&n);cnt=1;
	for(int i=1;i<=n;++i)
	{
		scanf("%I64d",x+i);
		push(x[i]);
	}
	scanf("%I64d",&m);
	ll q;
	ll a,b;
	for(int i=1;i<=m;++i)
	{
		scanf("%I64d%I64d%I64d",&q,&a,&b);
		if(q&1)
		{
			pull(x[a]);
			push(x[a]+=b);
		}
		else printf("%I64d\n",query(a,b));
	}
	return 0;
}

```
