#include<bits/stdc++.h>
#define mod 1000000007
#define int long long
using namespace std;
int n,m,dp[3000][3000];

main()
{
	cin>>n>>m;
	for(int i=1;i<=m;i++) dp[1][i]=1;
	for(int i=2;i<=n;i++)
	{
		int s=0;dp[i][1]=1;
		for(int j=2;j<=m;j++)
		{
			s+=dp[i-1][j]%mod,s%=mod;
			dp[i][j]=(dp[i][j-1]+s)%mod;
		}
	}	
	int ans=0;
	for(int i=1;i<=n;i++)
		for(int j=2;j<=m;j++)
			ans=(ans+((dp[i][j]-dp[i-1][j]+mod)%mod*(dp[n-i+1][j])%mod*(m-j+1))%mod)%mod;
	cout<<ans%mod<<endl;
	return 0;
}
