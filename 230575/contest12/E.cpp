#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
#define inf 100000009
using namespace std;
int dir[3];
int a[100010],team[100010];
int n,z;
int f[100010][2],p[100010][2];
void print(int dd)
{
	int t[2]={0,0};
	int now=dd;
	for (int i=n;i>=1;--i)
	{
		t[now]++;
		team[i]=now;
		now^=p[i-1][now];
	}
	printf("%d %d\n",t[0],t[1]);
	for (int i=1;i<=n;++i)
	if (team[i]==0) printf("%d ",a[i]);
	printf("\n");
	for (int i=1;i<=n;++i)
	if (team[i]==1) printf("%d ",a[i]);
	printf("\n");
}
int solved()
{
	for (int j=0;j<=n;++j)
	for (int i=0;i<2;++i)
	f[j][i]=(j>1^dir[i^1]==1)?0:inf;
	for (int j=2;j<=n;++j)
	{
		for (int i=0;i<2;++i)
		{
			if ((a[j-1]>a[j])^dir[i])
			{
				f[j][i]=f[j-1][i];
				p[j-1][i]=0;
			}
			if ((a[j]<f[j-1][i^1])^dir[i])
			{
				dir[i^1]?f[j][i]=min(f[j][i],a[j-1]):f[j][i]=max(f[j][i],a[j-1]);
				p[j-1][i]=f[j][i]==a[j-1]?1:0;
			}
		}
	}
	for (int i=0;i<2;++i)
	{
		if ((f[n][i]!=0&&f[n][i]!=inf))
		{
			print(i);
			return 1;
		}
	}
	return 0;
}
int main()
{
	cin>>n;
	for (int i=1;i<=n;++i)
	scanf("%d",&a[i]);
	for (int i=0;i<2;++i)
	for (int j=0;j<2;++j)
	{
		dir[0]=i;
		dir[1]=j;
		if (solved()) return 0;
	}
	printf("Fail");
	return 0;
}
