#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
using namespace std;
#define mod 1000000007
int fa[110],d[110],s[110];
int vis[110][110];
long long ans;
int find(int x)
{
	if (fa[x]==x) return x;
	return fa[x]=find(fa[x]);
}
int main()
{
	int n,m,i,x;
	cin>>n>>m;
	memset(vis,0,sizeof(vis));
	for (i=1;i<=n;++i)
	{
		fa[i]=i;
		s[i]=1;
		d[i]=0;
	}
	int sum=n,flag=0;
	for (i=1;i<=m;++i)
	{
		scanf("%d",&x);
		if (vis[i][x]||vis[x][i]) continue;
		vis[i][x]=vis[x][i]=1;
		d[i]++;
		d[x]++;
		if (find(x)!=find(i))
		{
			s[find(i)]+=s[find(x)];
			fa[find(x)]=fa[find(i)];
			sum--;
		}
		else flag=1;
	}
	if (n==2)
	{
		printf("1\n");
		return 0;
	}
	for (i=1;i<=n;++i)
	if (d[i]>2) break;
	if (i<=n||(sum>1&&flag))
	{
		printf("0\n");
		return 0;
	}
	ans=1;
	for (i=1;i<=sum-1;++i)
	ans=(ans*i)%mod;
	for (i=1;i<=n;++i)
	if (fa[i]==i&&s[i]>1) ans=(ans*2)%mod;
	printf("%I64d\n",ans);
	return 0;
}
