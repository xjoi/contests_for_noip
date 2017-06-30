#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
int n,m,u,v,w;
int a[105];
int main()
{
	scanf("%d%d",&n,&m);
	memset(a,0,sizeof(a));
	for (int i=1;i<=m;++i)
	{
		scanf("%d%d%d",&u,&v,&w);
		a[u]+=w;
		a[v]-=w;
	}
	int ans=0;
	for (int i=1;i<=n;++i)
	if (a[i]>0) ans+=a[i];
	printf("%d",ans);
	return 0;
}
