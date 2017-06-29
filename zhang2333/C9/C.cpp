#include<cstdio>
#include<iostream>
#include<queue>
#include<cstring>
#define xxx 520
#define mod 1000000007
using namespace std;
long long n,k,x,cnt[3];
long long f[2][60][60],st[2][60][60],c[60][60];

int main()
{
	for (int i=0;i<=52;i++)
		c[i][0]=1;
	for (int i=1;i<=52;i++)
		for (int j=1;j<=52;j++)
			c[i][j]=(c[i-1][j-1]+c[i-1][j])%mod;
	cin>>n>>k;
	k/=50;
	for (int i=1;i<=n;i++)
	{
		cin>>x;
		cnt[x/50]++;
	}
	memset(st,38,sizeof(st));
	f[0][cnt[1]][cnt[2]]=1;
	st[0][cnt[1]][cnt[2]]=0;
	long long step=-1,p;
	while (1)
	{
		step++;
		if (step>200)
		{
			printf("-1\n0");
			return 0;
		}
		p=step%2;
		//printf("%d\n",step);
		for (int i=0;i<=cnt[1];i++)
			for (int j=0;j<=cnt[2];j++)
			{
				if (st[p][i][j]!=step) continue;
				if (i==0&&j==0)
				{
					printf("%I64d\n%I64d",st[p][i][j],f[p][i][j]);
					return 0;
				}
				
				if (p==0)
				{
					for (int u=0;u<=cnt[1];u++)
					{
						for (int v=0;v<=cnt[2];v++)
						{
							if (u==0&&v==0) continue;
							if (u+v*2>k) break;
							//[i,j]->[i-u,j-v]
							if (st[1][i-u][j-v]==st[0][i][j]+1)
								f[1][i-u][j-v]=(f[1][i-u][j-v]+f[0][i][j]*c[i][u]%mod*c[j][v]%mod)%mod;
							else if (st[1][i-u][j-v]>st[0][i][j]+1)
							{
								st[1][i-u][j-v]=st[0][i][j]+1;
								f[1][i-u][j-v]=f[0][i][j]*c[i][u]%mod*c[j][v]%mod;
							}
							//printf("%d %d %d %d: %lld %lld %lld\n",i,j,u,v,f[0][i][j],c[i][u],c[j][v]);
						}
					}
				}
				else
				{
					for (int u=i;u<=cnt[1];u++)
					{
						for (int v=j;v<=cnt[2];v++)
						{
							if (u==i&&v==j) continue;
							if (u-i+(v-j)*2>k) break;
							//[1,i,j]->[0,u,v]
							if (st[0][u][v]==st[1][i][j]+1)
								f[0][u][v]=(f[0][u][v]+f[1][i][j]*c[cnt[1]-i][u-i]%mod*c[cnt[2]-j][v-j]%mod)%mod;
							else if (st[0][u][v]>st[1][i][j]+1)
							{
								st[0][u][v]=st[1][i][j]+1;
								f[0][u][v]=f[1][i][j]*c[cnt[1]-i][u-i]%mod*c[cnt[2]-j][v-j]%mod;
							}
						}
					}
				}
			}
	}
}
