#include<cstdio>
#include<algorithm>
using namespace std;
int n,b[501],x[501];
long long ans[501],a[501][501],f[501][501];
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	for(int j=1;j<=n;j++){
		scanf("%lld",&a[i][j]);f[i][j]=a[i][j];
	}
	for(int i=1;i<=n;i++)scanf("%d",&x[i]);
	for(int i=n;i>=1;i--){
		b[x[i]]=1;
		for(int j=1;j<=n;j++)
		for(int k=1;k<=n;k++)f[j][k]=min(f[j][k],f[j][x[i]]+f[x[i]][k]);
		for(int j=1;j<=n;j++)
		for(int k=1;k<=n;k++)if(b[j]&&b[k])ans[i]+=f[j][k];
		
	}
	for(int i=1;i<=n;i++)printf("%lld ",ans[i]);
	return 0;
}
