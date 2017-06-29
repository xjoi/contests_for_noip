using namespace std;
#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#define N 100001
#define ll long long
#define F(i,a,b) for(int i=a;i<=b;i++)
#define rep F
#define r(x) cin>>x
ll S[N];
ll l[N],r[N],d[N];
ll a[N];
ll v[N];
int n,m,k;
int x,y;
int main()
{
	r(n);r(m);r(k);
	F(i,1,n)r(a[i]);
	F(i,1,m){r(l[i]);r(r[i]);r(d[i]);}
	F(i,1,k)
	{
		r(x);r(y);
		v[x]++;v[y+1]--;
	}
	int hh=0;
	F(i,1,m){hh+=v[i];d[i]*=hh;}
	F(i,1,m){S[l[i]]+=d[i];S[r[i]+1]-=d[i];}
	ll what=0;
	F(i,1,n)
	{
		what+=S[i];
		a[i]+=what;
		cout<<a[i]<<" ";
	}
}
