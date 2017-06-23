#include <bits/stdc++.h>
using namespace std;
int n=0,t[106],w[106],dp[205],m;
int main(){
	scanf("%d",&m);
	for(int i=1;i<=m;i++)scanf("%d%d",&t[i],&w[i]),n+=t[i],w[i]+=t[i];
	for(int i=1;i<=m;i++)for(int j=n;j>=w[i];j--)dp[j]=max(dp[j],dp[j-w[i]]+t[i]);
	cout<<n-dp[n];
	return 0;
}
