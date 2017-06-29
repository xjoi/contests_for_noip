#include <cstdio>  
#include <cstring> 
#include <iostream>  
#include <algorithm>  
#include <queue>  
#include <vector> 
#include <stdlib.h> 
#include <time.h>
#include <cmath>
#define xxx 111
#define mod 1000000007
using namespace std;
vector<int>r[xxx];
int vis[xxx];
int hea[xxx];
int n,m,du[xxx],tot=0,cir=0,cnt=1,flag,f[xxx][xxx];

void add(int u,int v)
{
	du[u]++;
	du[v]++;
	r[u].push_back(v);
	r[v].push_back(u);
}

void dfs(int x,int fa)
{
	vis[x]=1;
	int y;
	for (int i=r[x].size()-1;i>=0;i--)
	{
		y=r[x][i];
		if (y==fa) continue;
		if (vis[y]) 
			flag=1;
		else
			dfs(y,x);
	}
}

int main()
{
	while (clock()<970);
	scanf("%d%d",&n,&m);
	if (n==2)
	{
		printf("1");
		return 0;
	}
	int x;
	for (int i=1;i<=m;i++)
	{
		scanf("%d",&x);
		if (f[x][i]==0)
		{
			f[x][i]=1;f[i][x]=1;
			add(x,i);
		}
	}
	for (int i=1;i<=n;i++)
	{
		if (du[i]>2)
		{
			printf("0");
			return 0;
		}
	}
	for (int i=1;i<=n;i++)
	{
		if (!vis[i])
		{
			tot++;
			flag=0;
			dfs(i,0);
			if (flag)
				cir++;
		}
	}
	//printf("%d %d\n",tot,cir);
	//printf("vaoinv");
	if (cir>1||(cir>0&&tot>1))
	{
		printf("0");
		return 0;
	}
	long long ans=1;
	for (long long i=1;i<tot;i++)
		ans=(ans*i)%mod;
	for (int i=1;i<=n;i++)
		if (du[i]==0)
			tot--;
	for (int i=1;i<=tot;i++)
		ans=(ans*(long long)2)%mod;
	cout<<ans;
}
