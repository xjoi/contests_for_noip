#include<cstdio>
#include<cstring>
#define P 1000000007 
#define N 2010
#define ll long long
using namespace std;
ll ans,n,m,f[N][N];
int main()
{
	int i,j;
	scanf("%I64d %I64d",&n,&m);
	for(i=1;i<=m;i++)f[1][i]=1;
		for(i=2;i<=n;i++)
		{
			int s=0; f[i][1]=1;
			for(int j=2;j<=m;j++)
			{
				s=(s+f[i-1][j])%P;
				f[i][j]=(f[i][j-1]+s)%P;
			}
		}
	for(i=1;i<=n;i++)
		for(j=2;j<=m;j++)
			ans=(ans+(m-j+1)*(f[i][j]-f[i-1][j]+P)%P*f[n-i+1][j])%P;
	printf("%I64d",ans);
	return 0;
}
