#include <cstdio>  
#include <cstring> 
#include <iostream>  
#include <algorithm>  
#include <queue>  
#include <vector> 
#include <stdlib.h> 
#include <time.h>
#include <cmath>
using namespace std;
int die=0;
int ans[12][12];

struct pt{
	int v[5][5][5];
	int fx[5];
	void in()
	{
		for (int i=1;i<=4;i++)
		{
			for (int j=1;j<=4;j++)
				cin>>v[0][i][j];
		}
		for (int k=1;k<4;k++)
		{
			for (int i=1;i<=4;i++)
				for (int j=1;j<=4;j++)
					v[k][i][j]=v[k-1][j][5-i];	
		}
	}
	void pri(int x)
	{
		printf("\n");
		for (int i=1;i<=4;i++)
		{
			for (int j=1;j<=4;j++)
				printf("%d ",v[x][i][j]);
			printf("\n");
		}
	}
}p[10];

int q[11],dir[11],used[11];

bool leftright(int p1,int d1,int p2,int d2)
{
	for (int i=1;i<=4;i++)
		if (p[p1].v[d1][i][4]!=p[p2].v[d2][i][1])
			return 0;
	return 1;
}

bool updown(int p1,int d1,int p2,int d2)
{
	for (int i=1;i<=4;i++)
		if (p[p1].v[d1][4][i]!=p[p2].v[d2][1][i])
			return 0;
	return 1;
}

bool ok(int x)
{
	if (x%3!=1) 
	{
		if (!leftright(q[x-1],dir[x-1],q[x],dir[x]))
			return 0;
	}
	if (x>3)
	{
		if (!updown(q[x-3],dir[x-3],q[x],dir[x]))
			return 0;
	}
	return 1;
}

void dfs(int x)
{
	if (die) return;
	if (x>9)
	{
		if (!die)
		{
			//for (int i=1;i<=9;i++)printf("%d %d\n",q[i],dir[i]);
			int a,b,x,y;
			for (int t=1;t<=9;t++)
			{
				a=(t+2)/3;
				b=t-(a-1)*3;
				x=(a-1)*3;
				y=(b-1)*3;
				for (int i=1;i<=4;i++)
				{
					for (int j=1;j<=4;j++)
					{
						ans[x+i][y+j]=p[q[t]].v[dir[t]][i][j];
					}
				}
			}
			for (int i=1;i<=10;i++)
			{
				for (int j=1;j<=10;j++)
					printf("%d ",ans[i][j]);
				printf("\n");
			}
		}
		die=1;
		return;
	}
	for (int i=1;i<=9;i++)
	{
		if (!used[i])
		{
			used[i]=1;
			q[x]=i;
			for (int j=0;j<4;j++)
			{
				dir[x]=j;
				if (ok(x))
					dfs(x+1);
			}
			used[i]=0;
		}
	}
}

int main()
{
	for (int i=1;i<=9;i++)
	{
		p[i].in();
	}
	dfs(1);
	if (!die)
		while (1);
}
