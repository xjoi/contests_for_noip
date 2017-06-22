using namespace std;
#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>
#define N 1000001
#define getmid int mid=(L[no]+R[no])>>1
#define lc no<<1
#define rc no<<1|1
#define rep(i,a,b) for(int i=a;i<=b;i++)
#define r(x) cin>>x
#define ll long long
ll L[N],R[N],val[N],sum[N],S[N];
ll num[N],cnt;
ll a[N];
ll bef[N];
ll x[N],y[N];
ll ty[N];
ll tot;
ll n;
ll m;
ll xx[N];
ll su,s,ans;
void pushup(ll no)
{
	val[no]=val[lc]+val[rc]+S[lc]*sum[rc]-S[rc]*sum[lc];
	sum[no]=sum[lc]+sum[rc];
	S[no]=S[lc]+S[rc];
}
void build(ll no,ll l,ll r)
{
	L[no]=l;R[no]=r;
	if(L[no]==R[no]) return;
	getmid;
	build(lc,l,mid);build(rc,mid+1,r);
	return;
}
void add(ll no,ll k,ll cc,ll hh)
{
	if(L[no]==R[no])
	{
		S[no]+=hh;
		sum[no]=cc;
		if(S[no]==0) sum[no]=0;
		val[no]=0;	
		return;
	}
	getmid;
	if(k<=mid) add(lc,k,cc,hh);
	else add(rc,k,cc,hh);
	pushup(no);
	return;
}
void query(ll no,ll l,ll r)
{
	if(L[no]==l&&R[no]==r)
	{
		ans=ans+val[no]+s*sum[no]-S[no]*su;
		su=sum[no]+su;
		s+=S[no];
		return;
	}
	getmid;
	if(r<=mid){query(lc,l,r);return;}
	if(l>mid){query(rc,l,r);return;}
	query(lc,l,mid);query(rc,mid+1,r);
	return;
}
int main()
{
	r(n);
	rep(i,1,n) 
	{
		r(a[i]);
		bef[++tot]=a[i];
	}
	for(ll i=1;i<=n;i++) xx[i]=a[i];
	r(m);
	rep(i,1,m)
	{
		r(ty[i]);r(x[i]);r(y[i]);
		if(ty[i]==1)
		{
//			if(x[i]==7) cout<<xx[x[i]]<<endl;
			bef[++tot]=xx[x[i]]+y[i];
			xx[x[i]]+=y[i];
		}
		else if(ty[i]==2)
		{
			bef[++tot]=x[i];
			bef[++tot]=y[i];
		}
	}
	sort(bef+1,bef+tot+1);
	num[++cnt]=bef[1];
	for(ll i=1;i<=tot;i++)
	{
		if(bef[i]!=num[cnt])num[++cnt]=bef[i];
	}
//	for(ll i=1;i<=cnt;i++) cout<<num[i]<<endl;
	build(1,1,cnt);
	for(ll i=1;i<=n;i++)
	{
		ll it=lower_bound(num+1,num+cnt+1,a[i])-num;
		add(1,it,a[i],1);
	}
	for(ll i=1;i<=m;i++)
	{
		if(ty[i]==1)
		{
			ll it=lower_bound(num+1,num+cnt+1,a[x[i]])-num;
			add(1,it,a[x[i]],-1);
			a[x[i]]+=y[i];
			it=lower_bound(num+1,num+cnt+1,a[x[i]])-num;
			add(1,it,a[x[i]],1);
		}
		if(ty[i]==2)
		{
			ll it1=lower_bound(num+1,num+cnt+1,x[i])-num;
			ll it2=lower_bound(num+1,num+cnt+1,y[i])-num;
			su=0;s=0;ans=0;
			query(1,it1,it2);
			cout<<ans<<endl;
		}
	}
//	for(ll i=1;i<=cnt;i++) cout<<num[i]<<" ";
	
}
