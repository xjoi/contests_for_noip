#include<iostream>
#include<cstdio>
#include<cstring>
#define int long long
#define N 60
#define P 1000000007
using namespace std;
int num,v,x,y,k,n,m,f[N*2][N][N],C[N][N],ans;
void get_C()
{
	C[0][0]=1;
	for (int i=1;i<=50;C[i][0]=1,++i)
		for (int j=1;j<=50;++j)
			C[i][j]=(C[i-1][j-1]+C[i-1][j])%P;
}
main()
{
	int i,j,k;
	get_C();
	scanf("%I64d %I64d",&num,&v);
	for(i=1;i<=num;i++) {scanf("%I64d",&x); if(x==50) n++; else m++;}
	f[0][n][m]=1;
	for(i=1;i<=num*2;i++)
	{
		for(j=0;j*50<=v;j++)
			for(k=0;k*100+j*50<=v;k++)
				ans=(ans+f[i-1][j][k])%P;
		if (ans){printf("%I64d\n%I64d",i*2-1,ans);return 0;}
		for(j=0;j<=n;++j)
			for(k=0;k<=m;++k)
				if(f[i-1][j][k])
					for(int go50=0;go50*50<=v&&go50<=j;go50++)
						for(int go100=0;go100*100+go50*50<=v&&go100<=k;go100++)
							for(int ba50=0;ba50*50<=v&&ba50<=n-j+go50;ba50++)
								for(int ba100=ba50==0;ba100*100+ba50*50<=v&&ba100<=m-k+go100;ba100++)	
									f[i][j-go50+ba50][k-go100+ba100]=(f[i][j-go50+ba50][k-go100+ba100]+f[i-1][j][k]*C[j][go50]%P*C[n-j+go50][ba50]%P*C[k][go100]%P*C[m-k+go100][ba100]%P)%P;
	}
	puts("-1\n0");
	return 0;
}
