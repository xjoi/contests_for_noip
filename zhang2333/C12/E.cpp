#include<cstdio>
#include<iostream>
#include<cmath>
#define xxx 100100
#define inf 520233
using namespace std;
int dir[3];
int n,a[xxx];
int f[xxx][2],p[xxx][2],z;
int team[xxx];

void pri(int dd)
{
	int t[2]={0,0};
	int te=dd;
	for (int i=n;i>=1;i--)
	{
		t[te]++;
		team[i]=te;
		te^=p[i-1][te];
	}
	printf("%d %d\n",t[0],t[1]);
	for (int i=1;i<=n;i++)
		if (team[i]==0)
			printf("%d ",a[i]);
	printf("\n");
	for (int i=1;i<=n;i++)
		if (team[i]==1)
			printf("%d ",a[i]);
	printf("\n");
}

int sol()
{
	for (int ttt=0;ttt<=n;ttt++)
		for (int i=0;i<2;i++)
			f[ttt][i]= (ttt>1^dir[i^1]==1)? 0:inf;
	for (int ttt=2;ttt<=n;ttt++)
	{
		for (int i=0;i<2;i++)
		{
			if ((a[ttt-1]>a[ttt])^dir[i])
			{
				f[ttt][i]=f[ttt-1][i];
				p[ttt-1][i]=0;
			}
			if ((a[ttt]<f[ttt-1][i^1])^dir[i])
			{
				dir[i^1]? f[ttt][i]=min(f[ttt][i],a[ttt-1]): f[ttt][i]=max(f[ttt][i],a[ttt-1]);
				p[ttt-1][i] = f[ttt][i]==a[ttt-1]?1:0;
			}
		}
	}
	for (int i=0;i<2;i++)
	{
		if ( (f[n][i]!=0&&f[n][i]!=inf) )
		{
			pri(i);
			return 1;
		}
	}
	return 0;
}

int main() 
{
	cin>>n;
	for (int i=1;i<=n;i++)
		cin>>a[i];
	for (int i=0;i<2;i++)
		for (int j=0;j<2;j++)
		{
			dir[0]=i;dir[1]=j;
			if (sol())
				return 0;
		}
	printf("Fail");
	return 0;
}
