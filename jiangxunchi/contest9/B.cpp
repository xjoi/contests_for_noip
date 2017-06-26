#include<cstdio>
typedef long long ll;
const int N=501;
ll dis[N][N]; int a[N]; ll ans[N];
int main(){
	int n; scanf("%d",&n);
	for(int i=1;i<=n;++i) for(int j=1;j<=n;++j) scanf("%I64d",&dis[i][j]);
	for(int i=1;i<=n;++i) scanf("%d",&a[i]);
	for(int i=n;i>=1;--i){
		for(int j=1;j<=n;++j) for(int k=1;k<=n;++k)
			if(dis[j][a[i]]+dis[a[i]][k]<dis[j][k]) dis[j][k]=dis[j][a[i]]+dis[a[i]][k];
		for(int j=i;j<=n;++j) for(int k=i;k<=n;++k) ans[i]+=dis[a[j]][a[k]];
	}
	for(int i=1;i<=n;++i) printf("%I64d ",ans[i]); return 0;
}
