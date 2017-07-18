#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<cstdlib>
struct node{
	int g[4][4];
	void change()
	{
		int b[4][4];
		for (int i=0;i<4;++i)
		for (int j=0;j<4;++j)
		b[i][j]=g[j][3-i];
		for (int i=0;i<4;++i)
		for (int j=0;j<4;++j)
		g[i][j]=b[i][j];
	}
};
bool vis[9];
node a[9],s[9];
void dfs(int x)
{
	if (x==9)
	{
		int ans[10][10],xx=0,yy=0;
		for (int i=0;i<9;++i)
		{
			for (int j=0;j<4;++j)
			for (int k=0;k<4;++k)
			ans[xx+j][yy+k]=s[i].g[j][k];
		    yy+=3;
	    	if (yy==9)
	    	{
	     		xx+=3;
	    		yy=0;
	    	}
		}
		for (int i=0;i<10;++i)
		{
			for (int j=0;j<10;++j)
			printf("%d ",ans[i][j]);
			printf("\n");
		}
		exit(0);
	}
	for (int i=0;i<9;++i)
	if (!vis[i])
	{
		s[x]=a[i];
		for (int j=0;j<4;++j)
		{
			s[x].change();
			bool flag=1;
			if (x%3)
			for (int k=0;k<4;++k)
			if (s[x].g[k][0]!=s[x-1].g[k][3])
			{
				flag=0;
				break;
			}
			if (!flag) continue;
			if (x>2)
			for (int k=0;k<4;++k)
			if (s[x].g[0][k]!=s[x-3].g[3][k])
			{
				flag=0;
				break;
			}
			if (!flag) continue;
			vis[i]=1;
			dfs(x+1);
			vis[i]=0;
		}
	}
}
int main()
{
	for (int i=0;i<9;++i)
	for (int j=0;j<4;++j)
	for (int k=0;k<4;++k)
	scanf("%d",&a[i].g[j][k]);
	dfs(0);
}
