#include<cstdio>
#include<iostream>
#define xxx 2010
#define mod 1000000007
using namespace std;
long long f[xxx][xxx],g[xxx][xxx],n,m,s[xxx],ans;
int main()
{
	cin>>n>>m;
	for (int i=2;i<=m;i++)
		f[1][i]=1;
	for (int i=2;i<=n;i++)
	{
		s[1]=0;
		for (int j=2;j<=m;j++)
			s[j]=(s[j-1]+f[i-1][j])%mod;
		for (int j=2;j<=m;j++)
			f[i][j]=(f[i][j-1]+s[j])%mod;
		for (int j=2;j<=m;j++)
			f[i][j]++;
	}
	
	if (0)
	{
		for (int i=1;i<=n;i++)
		{
			for (int j=1;j<=m;j++)
				cout<<f[i][j]<<' ';
			cout<<endl;
		}	
		cout<<endl;
	}
	
	for (int i=2;i<=m;i++)
		g[1][i]=1;
	for (int i=2;i<=n;i++)
	{
		s[1]=0;
		for (int j=2;j<=m;j++)
			s[j]=(s[j-1]+f[i-1][j])%mod;
		for (int j=2;j<=m;j++)
			g[i][j]=(g[i][j-1]+s[j])%mod;
		for (int j=2;j<=m;j++)
			g[i][j]-=f[i-1][j]-1;
	}
	
	if (0)
	{
		for (int i=1;i<=n;i++)
		{
			for (int j=1;j<=m;j++)
				cout<<g[i][j]<<' ';
			cout<<endl;
		}	
		cout<<endl;
	}
	
	ans=0;
	for (int i=1;i<=n;i++)
		for (int j=2;j<=m;j++)
			ans=(ans+f[i][j]*g[n-i+1][j]%mod*(m-j+1))%mod;
	cout<<ans;
}
