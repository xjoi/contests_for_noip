#include<cstdio>
#include<iostream>
#include<vector>
#include<cstring>
#define xxx 2510 
using namespace std;
int n,m,f[xxx][xxx][3][3],inf;
vector<int>r[xxx];
int used[xxx],top[xxx],siz[xxx],ans[xxx]={0};
void dfs(int x,int fa)
{
	int y,oldsiz,flag=0,ma;
	used[x]+=siz[x]=f[x][0][2][0]=1;
	f[x][0][0][0]=f[x][1][1][0]=0;
	for (int k=r[x].size()-1;k>=0;k--)
	{
		y=r[x][k];
		if (y==fa||used[y]>=2) continue;
		if (!used[y])
		{
			dfs(y,x);
			oldsiz=siz[x];
			siz[x]+=siz[y];
			if (top[y]&&top[y]!=x)
				top[x]=top[y];
			for (int i=siz[x];i>=0;i--)
				for (int u=2;u>=0;u--)
					for (int w=2;w>=0;w--)
					{
						ma=inf;
						for (int j=max(0,i-oldsiz);j<=min(siz[y],i);j++)
							for (int v=2;v>=0;v--)
								if (u+v!=3)
									if (top[y])
										if (top[y]==x)
											ma=max(ma,f[x][i-j][u][w]+f[y][j][v][u]);
										else
											ma=max(ma,f[x][i-j][u][0]+f[y][j][v][w]);
									else
										ma=max(ma,f[x][i-j][u][w]+f[y][j][v][0]);
						f[x][i][u][w]=ma;
					}
		}
		else
			flag=top[x]=y;
	}
	if (flag)
	{
		for (int i=0;i<=siz[x];i++)
		{
			for (int j=0;j<=2;j++)
				f[x][i][j][2]=f[x][i][j][1]=f[x][i][j][0];
			f[x][i][1][2]=f[x][i][2][1]=inf;
		}
	}
	used[x]++;
}
int main()
{
	memset(f,-38,sizeof(f));
	inf=f[0][0][0][0];
	scanf("%d%d",&n,&m);
	int x,y;
	for (int i=1;i<=m;i++)
	{
		scanf("%d%d",&x,&y);
		r[x].push_back(y);
		r[y].push_back(x);
	}
	dfs(1,0);
	for (int i=0;i<=n;i++)
		printf("%d ",max(max(f[1][i][0][0],f[1][i][1][0]),f[1][i][2][0]));
}
