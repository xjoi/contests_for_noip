#include<cstdio>
#include<iostream>
#include<queue>
#include<cstring>
#define xxx 520
#define inf 2332333
using namespace std;
int n,f[xxx][xxx],del[xxx],ok[xxx],g[xxx][xxx];
long long ans[xxx],an;
int in[xxx],d[xxx];
queue<int>q;

void gof(int st)
{
	memset(in,0,sizeof(in));
	memset(d,38,sizeof(d));
	while (!q.empty()) q.pop();
	d[st]=0;q.push(st);
	int x;
	while (!q.empty())
	{
		x=q.front();q.pop();
		in[x]=0;
		for (int i=1;i<=n;i++)
		{
			if (!ok[i]) continue;
			if (d[i]>d[x]+f[x][i])
			{
				d[i]=d[x]+f[x][i];
				if (!in[i])
				{
					q.push(i);
					in[i]=1;
				}
			}
		}
	}
	for (int i=1;i<=n;i++)
	{
		if (!ok[i]||i==st) continue;
		f[st][i]=d[i];
	}
}

void gog(int st)
{
	memset(in,0,sizeof(in));
	memset(d,38,sizeof(d));
	while (!q.empty()) q.pop();
	d[st]=0;q.push(st);
	int x;
	while (!q.empty())
	{
		x=q.front();q.pop();
		in[x]=0;
		for (int i=1;i<=n;i++)
		{
			if (!ok[i]) continue;
			if (d[i]>d[x]+g[x][i])
			{
				d[i]=d[x]+g[x][i];
				if (!in[i])
				{
					q.push(i);
					in[i]=1;
				}
			}
		}
	}
	for (int i=1;i<=n;i++)
	{
		if (!ok[i]||i==st) continue;
		f[i][st]=d[i];
	}
}

void fff(int k)
{
	for (int i=1;i<=n;i++)
	{
		if (!ok[i]||i==k) continue;
		for (int j=1;j<=n;j++)
		{
			if (j==k||i==j||!ok[j]) continue;
			f[i][j]=min(f[i][k]+f[k][j],f[i][j]);
		}
	}
}

void pri()
{
	for (int i=1;i<=n;i++)
	{
		for (int j=1;j<=n;j++)
		{
			if (!ok[i]||!ok[j]||i==j)
			{
				printf("inf ");
				continue;
			}
			printf("%3d ",f[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}

int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
		for (int j=1;j<=n;j++)
		{
			scanf("%d",&f[i][j]);
			if (i==j) f[i][j]=inf;
			g[j][i]=f[i][j];
		}
	for (int i=1;i<=n;i++)
		scanf("%d",&del[i]);
	for (int i=n;i>0;i--)
	{
		ok[del[i]]=1;
		if (i==n) continue;
		gof(del[i]);//pri();
		gog(del[i]);//pri();
		fff(del[i]);//pri();
		an=0;
		for (int i=1;i<=n;i++)
		{
			for (int j=1;j<=n;j++)
			{
				if (i==j||!ok[i]||!ok[j]) continue;
				an+=f[i][j];
				g[j][i]=f[i][j];
			}
		}
		ans[i]=an;
	}
	for (int i=1;i<=n;i++)
		printf("%I64d ",ans[i]);
}
