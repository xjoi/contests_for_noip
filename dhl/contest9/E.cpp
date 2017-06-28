#pragma GCC optimize("O3")
#include<iostream>
#include<stdio.h>
#include<string.h>
#include<algorithm>
#define ls rt<<1
#define rs rt<<1|1
#define mid (l+(r-l)/2)
#define maxn 5001000
#define N 1000002000
#define LL long long
using namespace std;
LL n,m,cnt=1;
LL L[maxn],R[maxn],a[maxn];
struct TREE
{
	LL num,sum,ans;
}tr[maxn];

TREE operator +(TREE a,TREE b)
{
	TREE c;
	c.sum=a.sum+b.sum;
	c.num=a.num+b.num;
	c.ans=b.sum*a.num-a.sum*b.num+a.ans+b.ans;
	return c;
}

inline void update(LL &rt,LL l,LL r,LL ll,LL C)
{
	if(!rt) rt=++cnt;
	if(l==r)
	{
		tr[rt].sum+=(ll)*C;
		tr[rt].num+=C;
		return ;
	}
	if(ll<=mid) update(L[rt],l,mid,ll,C);
	else update(R[rt],mid+1,r,ll,C);
	tr[rt]=tr[L[rt]]+tr[R[rt]];
}

inline TREE query(LL rt,LL l,LL r,LL ll,LL rr)
{
	if(!rt) return (TREE){0,0,0};
	if(ll==l&&r==rr) return tr[rt];
	if(rr<=mid) return query(L[rt],l,mid,ll,rr);
	if(ll>mid) return query(R[rt],mid+1,r,ll,rr);
	return query(L[rt],l,mid,ll,mid)+query(R[rt],mid+1,r,mid+1,rr);
	
}

int main()
{
	LL rt=1,x;
	cin>>n;
	for(LL i=1;i<=n;i++)
	{	
		scanf("%I64d",&a[i]);
		update(rt,-N,N,a[i],1);
	}
	cin>>m;
	for(LL i=1;i<=m;i++)
	{
		LL t1,t2,t3;
		scanf("%I64d%I64d%I64d",&t1,&t2,&t3);
		if(t1==1)
		{
			update(rt,-N,N,a[t2],-1);
			update(rt,-N,N,a[t2]+=t3,1);
		}
		else
			printf("%I64d\n",query(rt,-N,N,t2,t3).ans);
	}
	return 0;	
} 
