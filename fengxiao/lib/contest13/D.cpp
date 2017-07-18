#include<cstdio>
#include<cstring>
#include<iostream>
#define N 5010
using namespace std;
int f[N][N],n,m,ans=0;
int a[N][N],b[N][N];
char map[N][N];
int main()
{
	int i,j;
	scanf("%d %d",&n,&m);
	for(i=1;i<=n;i++) scanf("%s",map[i]+1);
	for(i=1;i<=n;i++)
		for(j=1;j<=m;j++)
			if(map[i][j]=='1')
			{
				a[i][j]=a[i][j-1]+1;
				b[j][a[i][j]]++;
			}
	for(j=1;j<=m;j++)
	{
		int c=0;
		for(i=m;i>=1;i--)
		{
			c+=b[j][i];
			ans=max(ans,c*i);
 		}
	}
	printf("%d",ans);
	return 0;
}
