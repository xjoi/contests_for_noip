#include<bits/stdc++.h>
using namespace std;
#define int long long
const int p=1000000007;
int dp[2005][2005],n,k;
main(){
	scanf("%lld%lld",&n,&k);
	for(int i=1;i<=n;i++){
		int s=0;
		for(int j=2;j<=k;j++){
			(s+=dp[i-1][j])%=p;
			dp[i][j]=(s+(j>2?dp[i][j-1]:1))%p;
		}
	}
	int ans=0;
	for(int i=1;i<=n;i++){
		for(int j=2;j<=k;j++){
			(ans+=(k-j+1)*(dp[i][j]-dp[i-1][j]+p)%p*(dp[n-i+1][j])%p)%=p;
		}
	}
	printf("%lld",ans);
	return 0;
}
