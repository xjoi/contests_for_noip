#pragma GCC optimize("O3")
#include<iostream>
#include<stdio.h>
#include<string.h>
#include<algorithm>
#define ls rt<<1
#define rs rt<<1|1
#define mid (l+(r-l)/2)
#define maxn 300000
using namespace std;
struct Nde{int l,r,t,id;}a[maxn];
int tr[maxn<<2],id[maxn<<2],n,m,t[maxn],ans[maxn];

bool cmp(Nde a,Nde b){return a.l<b.l||(a.l==b.l&&a.id<b.id);}

void update(int L,int C,int idx,int l,int r,int rt)
{
	if(l==r)
	{
		tr[rt]=C;
		id[rt]=idx;
//		cout<<id[rt]<<"\~\n";
		return ;
	}
	if(L<=mid) update(L,C,idx,l,mid,ls);
	else update(L,C,idx,mid+1,r,rs);
	tr[rt]=max(tr[ls],tr[rs]);
}

int query(int L,int C,int l,int r,int rt)
{
	if(tr[rt]<C) return -1;
	if(l==r) return id[rt];
	int ans=(L<=mid)?query(L,C,l,mid,ls):-1;
	return ans==-1 ? query(L,C,mid+1,r,rs) : ans;
}

int main()
{
	cin>>n>>m;
	for(int i=1;i<=n+m;i++)
	{
		scanf("%d%d%d",&a[i].l,&a[i].r,&a[i].t);
		a[i].id=i;
		t[i]=a[i].t;
	}
	sort(a+1,a+n+m+1,cmp);
//	for(int i=1;i<=n+m;i++)
//		cout<<a[i].l<<" "<<a[i].r<<" "<<a[i].t<<" "<<a[i].id<<"~\n";
	sort(t+1,t+n+m+1);//离散化，对每一个时间点建树 
	for(int i=1;i<=n+m;i++)
	{
		int pos=lower_bound(t+1,t+m+n+1,a[i].t)-t;
//		cout<<a[i].id<<"\n";
		if(a[i].id<=n) update(pos,a[i].r,a[i].id,1,n+m,1);
		else ans[a[i].id-n]=query(pos,a[i].r,1,n+m,1);
	}
	for(int i=1;i<=m;i++)
		printf("%d ",ans[i]);
	return 0;
	
} 
/*
4 3
1 10 10
5 6 2
6 7 3
5 7 4
5 7 1
1 2 1
1 10 11
*/
