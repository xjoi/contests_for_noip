#include<bits/stdc++.h>
#define mp make_pair
using namespace std;
const int M=305;
int n,c[M],l[M];
map<int,int> dp;
map<int,int>::iterator it;
int gcd(int a,int b)
{
	return b==0?a:gcd(b,a%b);
}
int main()
{
    scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&l[i]);
	for(int i=1;i<=n;i++)
		scanf("%d",&c[i]);
	for(int i=1;i<=n;i++)
	{
		for(it=dp.begin();it!=dp.end();it++)
		{
			int x=it->first;
			x=gcd(x,l[i]);
			if (!dp[x])
				dp[x]=it->second+c[i];
			else
				dp[x]=min(dp[x],it->second+c[i]);
		}
		int x=l[i];
		if(!dp[x])
			dp[x]=c[i];
		else
			dp[x]=min(dp[x],c[i]);
	}
	if(!dp[1])
		puts("-1");
	else
		printf("%d\n",dp[1]);
	return 0;
}
