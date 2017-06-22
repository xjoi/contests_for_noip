#include<cstdio>
#define MOD 1000000007 
#define ll long long
using namespace std;
ll ans,n,m,s,f[2001][2001];
int main(){
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=m;i++)f[1][i]=1;
	for(int i=2;i<=n;i++){
		int s=0;f[i][1]=1;
		for(int j=2;j<=m;j++){
			s=(s+f[i-1][j])%MOD;
			f[i][j]=(f[i][j-1]+s)%MOD;
		}
	}
	for(int i=1;i<=n;i++)
	for(int j=2;j<=m;j++)ans=(ans+(m-j+1)*(f[i][j]-f[i-1][j]+MOD)%MOD*f[n-i+1][j])%MOD;
	printf("%lld",ans);
}
