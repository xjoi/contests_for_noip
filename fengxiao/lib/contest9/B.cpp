#include<cstdio>
#include<cstring>
#define N 510
#define int long long
using namespace std;
int dis[N][N];
int ord[N],ans[N];
int n;
inline int min(int a,int b) {return a<b?a:b;}
main()
{
	int i,j;
	scanf("%I64d",&n);
	for(i=1;i<=n;i++)
		for(j=1;j<=n;j++)
			scanf("%I64d",&dis[i][j]);
	for(i=n;i>=1;i--)	scanf("%I64d",&ord[i]);
	for(int k=1;k<=n;k++)
	{
		for(i=1;i<=n;i++)
			for(j=1;j<=n;j++)
				dis[i][j]=min(dis[i][j],dis[i][ord[k]]+dis[ord[k]][j]);
		for(i=1;i<=k;i++)
			for(j=1;j<=k;j++)
				ans[k]+=dis[ord[i]][ord[j]];
	}
	for(i=n;i>=1;i--) printf("%I64d ",ans[i]);
	return 0;
}
