#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<cctype>
#include<iostream>
using namespace std;
typedef long long ll;
const int mo=1e9+7;
int n,m,ans,f[2005][2005];
int sum[2005][2005],h[2005][2005];
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=2;i<=m;i++)
	{
		f[i][1]=1;
		sum[i][1]=i-1;
	}
	for(int i=2;i<=n;i++)
		for(int j=2;j<=m;j++)
		{
			f[j][i]=(f[j-1][i]+sum[j][i-1])%mo;
			sum[j][i]=(f[j][i]+sum[j-1][i])%mo;
		}
	memset(sum,0,sizeof(sum));
	for(int i=1;i<=n;i++)
		for(int j=m;j>0;j--)
		{
			f[j][i]=(ll)f[j][i]*(m-j+1)%mo;
			sum[j][i]=(sum[j+1][i]+f[j][i])%mo;
		}
	for(int i=2;i<=n;i++)
	{
		for(int j=m;j>1;j--)
			h[j][i]=(h[j+1][i]+sum[j][i-1])%mo;
		for(int j=m;j>1;j--)
			h[j][i]=(h[j][i]-f[j][i-1]+mo)%mo;
	}
	memset(sum,0,sizeof(sum));
	for(int i=2;i<=n;i++)
	{
		int tmp=0;
		for(int j=m;j>1;j--)
		{
			tmp=(tmp+sum[j][i-1])%mo;
			h[j][i]=(h[j][i]+tmp)%mo;
			sum[j][i]=(sum[j+1][i]+h[j][i])%mo;
		}
	}
	for(int i=1;i<=m;i++)
		for(int j=1;j<=n;j++)
		{
			ans=(ans+(ll)f[i][j]*(n-j+1)%mo)%mo;
			ans=(ans+(ll)h[i][j]*(n-j+1)%mo)%mo;
		}
	printf("%d\n",ans);
	return 0;
}
