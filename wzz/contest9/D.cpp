using namespace std;
#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#define ll long long
#define r(x) cin>>x
#define F(i,a,b) for(int i=a;i<=b;i++)
#define N 2001
const ll mod=1e9+7;
ll f[N][N];
ll ans;
ll n,m;
int main()
{
	r(n);r(m);
	for(int i=2;i<=m;i++) f[1][i]=1;
	for(int i=2;i<=n;i++)
	{
		f[i][1]=1;
		for(int j=2,s=0;j<=m;j++)
		{
			s+=f[i-1][j];
			s=s%mod;
			f[i][j]=(f[i][j-1]+s)%mod;
		}
	}
	ans=0;
	for(int i=1;i<=n;i++)
	{
		for(int j=2;j<=m;j++)
		{
			ans=((ans+((m-j+1)%mod)*((f[i][j]-f[i-1][j]+mod)%mod*(f[n-i+1][j])%mod))%mod);
		}
	}
	cout<<ans<<endl;
}
