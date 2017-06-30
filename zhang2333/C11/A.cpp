#include<cstdio>
#include<iostream>
using namespace std;

int a[60][60],n;

bool ok(int x,int y)
{
	if (a[x][y]==1) return 1;
	for (int i=1;i<=n;i++)
		for (int j=1;j<=n;j++)
			if (i!=x&&j!=y)
				if (a[i][y]+a[x][j]==a[x][y])
					return 1;
	return 0;
}

int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
		for (int j=1;j<=n;j++)
			scanf("%d",&a[i][j]);
	for (int i=1;i<=n;i++)
		for (int j=1;j<=n;j++)
			if (!ok(i,j))
			{
				printf("No\n");
				return 0;
			}
	printf("Yes\n");
	return 0;
}
