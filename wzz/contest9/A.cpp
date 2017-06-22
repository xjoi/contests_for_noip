using namespace std;
#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#define N 400009
#define pk(x) printf("%d ",x)
#define rep(i,a,b) for(int i=a;i<=b;i++)
#define getmid int mid=(L[no]+R[no])>>1
#define lc no<<1
#define rc no<<1|1
#define F rep
#define r(x) cin>>x
#define ll long long
ll val[N],num[N],d[N];
int L[N],R[N];
int  l[N],r[N];
ll a[N];
int n,m,k;
int x,y;
void build(int no,int l,int r)
{
	L[no]=l;R[no]=r;
	if(L[no]==R[no]){val[no]=a[L[no]];num[no]=0;return;}
	getmid;
	build(lc,l,mid);build(rc,mid+1,r);
	return;
}
void add(int no,int x,int y)
{
	if(L[no]==x&&R[no]==y){num[no]+=1;return;}
	getmid;
	if(x>mid) add(rc,x,y);
	else if(y<=mid) add(lc,x,y);
	else {add(lc,x,mid);add(rc,mid+1,y);}
	return;
}
ll get(int no,int it)
{
	if(L[no]==R[no]){return num[no];}
	getmid;
	ll res=num[no];
	if(it>mid) res+=get(rc,it);
	else res+=get(lc,it);
	return res;
}
void inc(int no,int x,int y,ll v)
{
	if(L[no]==x&&R[no]==y){val[no]+=v;return;}
	getmid;
	if(x>mid) inc(rc,x,y,v);
	else if(y<=mid) inc(lc,x,y,v);
	else {inc(lc,x,mid,v);inc(rc,mid+1,y,v);}
	return;
}
ll query(int no,int it)
{
	if(L[no]==R[no]){return val[no];}
	getmid;
	ll res=val[no];
	if(it>mid) res+=query(rc,it);
	else res+=query(lc,it);
	return res;
}
int main()
{
	r(n);r(m);r(k);
	rep(i,1,n) r(a[i]);
	build(1,1,100001);
	F(i,1,m)
	{
		r(l[i]);r(r[i]);r(d[i]);
	}
	F(i,1,k)
	{
		r(x);r(y);
		add(1,x,y);
	}
	F(i,1,m)
	{
		ll times=get(1,i);
		d[i]*=times;
		inc(1,l[i],r[i],d[i]);
	}
	F(i,1,n)
	{
		cout<<query(1,i)<<" ";
	}
}
