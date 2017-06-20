#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
using namespace std;
int n,m,k;
int a[100001],b[100001];
int f[100];
int main()
{
	while (scanf("%d%d%d",&n,&m,&k)!=-1)
	{
		int ans=0;
		for (int i=1;i<=n;i++) scanf("%d",&a[i]);
		for (int i=1;i<=m;i++) scanf("%d",&b[i]);
		for (int i=1;i<=n-m+1;)
		{
			for (int j=1;j<=k;j++) f[j]=0;
			bool judge=1;
			for (int j=i;j<=i+m-1;j++)
			{
				if (f[b[j-i+1]]&&f[b[j-i+1]]!=a[j]) 
				{
					judge=0;
					break;
				}
				f[b[j-i+1]]=a[j];
				int before=f[1];
				for (int i0=2;i0<=k;i0++)
				{
					if (f[i0]&&f[i0]<=before) 
					{
						judge=0;
						break;
					}
					if (f[i0]) before=f[i0];
				}
				if (!judge) break;
			}
			if (judge)
			{
				ans++;
				i+=m;
			}
			else i++;
		}
		printf("%d\n",ans);		
	}
	return 0;
}
