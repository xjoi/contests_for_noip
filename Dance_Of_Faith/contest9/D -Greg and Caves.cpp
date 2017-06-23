#include<iostream>
#define int long long
using namespace std;
int n,m,ans=0,g[2010][2010],f[2010][2010],MOD=1e9+7;
void pls(int &x,int y){x+=y;x%=MOD;}
main(){
	cin >>n>>m;
	for (int i=1;i<=n;++i){
		int sum=0;
		for (int j=2;j<=m;++j)
			pls(f[i][j],g[i-1][j]+1),
			pls(sum,f[i][j]),
			pls(g[i][j],g[i][j-1]+sum);
	}
	for (int i=1;i<=n;++i)
		for (int j=2;j<=m;++j)
			pls(ans,f[i][j]*(g[n-i][j]-f[n-i][j]+1)%MOD*(m-j+1)%MOD);
	cout <<ans<<endl;
	return 0;		
}
