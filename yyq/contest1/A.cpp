#include<bits/stdc++.h>
using namespace std;
int n,m;
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	{
		if(i%2==0&&i%4!=0)
		{
			for(int j=1;j<=m-1;j++)
				putchar('.');
			putchar('#');
			putchar('\n');
		}
		else if(i%4==0)
		{
			putchar('#');
			for(int j=1;j<=m-1;j++)
				putchar('.');
			putchar('\n');
		}
		else
		{
			for(int j=1;j<=m;j++)
				putchar('#');
			putchar('\n');
		}
	}
	return 0;
}
