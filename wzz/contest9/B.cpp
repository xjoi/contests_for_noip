using namespace std;
#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<cstring>
#define N 1001
#define r(x) cin>>x
#define rep(i,a,b) for(int i=a;i<=b;i++)
#define ll long long
ll way[N][N];
ll f[N][N];
ll ans[N];
ll xu[N];
int n;
ll res=0;
bool vis[N];
int main()
{
	r(n);
	memset(f,63,sizeof(f));
	for(int i=1;i<=n;i++) f[i][i]=0;
	for(int i=1;i<=n;i++)
	for(int j=1;j<=n;j++)
	r(way[i][j]);
	for(int i=1;i<=n;i++) r(xu[i]);
	reverse(xu+1,xu+n+1);


	for(int i=1;i<=n;i++)
	{
		int it=xu[i];
		for(int j=1;j<=n;j++)if(!vis[j]) f[it][j]=way[it][j];
		for(int j=1;j<=n;j++)
		{
			if(!vis[j])continue;
			for(int k=1;k<=n;k++)
			{
				if(!vis[k]) continue;
				if(f[it][j]>f[it][k]+f[k][j])
				{
					f[it][j]=f[it][k]+f[k][j];
				}
			}
			res+=f[it][j];
		}
		for(int j=1;j<=n;j++)if(!vis[j]) f[j][it]=way[j][it];
		for(int j=1;j<=n;j++)
		{
			if(!vis[j])continue;
			for(int k=1;k<=n;k++)
			{
				if(!vis[k]) continue;
				if(f[j][it]>f[j][k]+f[k][it])f[j][it]=f[j][k]+f[k][it];
			}
			res+=f[j][it];
		}
		vis[it]=1;
		for(int j=1;j<=n;j++)
		{
			if(!vis[j])continue;
			for(int k=1;k<=n;k++)
			{
				if(!vis[k])continue;
				if(f[j][k]>f[j][it]+f[it][k])
				{
					res-=(f[j][k]-f[j][it]-f[it][k]);
					f[j][k]=f[j][it]+f[it][k];
				}
			}
		}
		ans[i]=res;
	}
	for(int i=n;i>=1;i--) cout<<ans[i]<<" ";
}
