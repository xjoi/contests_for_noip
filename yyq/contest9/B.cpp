#include<bits/stdc++.h>
using namespace std;
int n;
int dis[505][505];
long long sumdis[505];
int v[505];
bool InGraph[505];
int main()
{
	memset(InGraph,false,sizeof InGraph);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			scanf("%d",&dis[i][j]);
	for(int i=1;i<=n;i++)
		scanf("%d",&v[i]);
	InGraph[v[n]]=1;
	for(int i=n-1;i>=1;i--)
	{
		int u=v[i];
		InGraph[u]=1;
		for(int k=1;k<=n;k++)
		{
			for(int j=1;j<=n;j++)
			{
				if(u==j||!InGraph[k]||!InGraph[j])
					continue;
				dis[u][j]=min(dis[u][j],dis[u][k]+dis[k][j]);
				dis[j][u]=min(dis[j][u],dis[j][k]+dis[k][u]);
			}
		}
		for(int j=1;j<=n;j++)
		{
			for(int k=1;k<=n;k++)
			{
				if(j==k||!InGraph[j]||!InGraph[k])
					continue;
				dis[j][k]=min(dis[j][k],dis[j][u]+dis[u][k]);
				dis[k][j]=min(dis[k][j],dis[k][u]+dis[u][j]);
			}
		}
		for(int j=1;j<=n;j++)
		{
			for(int k=1;k<=n;k++)
			{
				if(j==k||!InGraph[j]||!InGraph[k])
					continue;
				sumdis[i]+=dis[j][k];
			}
		}
	}
	for(int i=1;i<=n;i++)
		printf("%I64d ",sumdis[i]);
	return 0;
}
