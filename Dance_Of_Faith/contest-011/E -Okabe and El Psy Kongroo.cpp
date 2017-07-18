#include<iostream>
#include<cstring>
#include<cstdio>
#define int long long
const int INF=1e16,MOD=1e9+7;
using namespace std;
int n,k,y;
int a[1000],b[1000],c[1000];
struct Matrix{
	int data[20][20];
	Matrix(){memset(data,0,sizeof(data));}
};
Matrix cheng(Matrix a,Matrix b){
	Matrix c;
	for (int i=0;i<=y;++i)
	for (int j=0;j<=y;++j)
	for (int k=0;k<=y;++k)
		c.data[i][k]=(c.data[i][k]+a.data[i][j]*b.data[j][k]%MOD)%MOD;
	return c;
}
Matrix power(Matrix a,int k){
	Matrix b;
	for (int i=0;i<=y;++i) b.data[i][i]=1;
	while (k>0){
		if (k&1) b=cheng(b,a);
		a=cheng(a,a);k/=2;
	}
	return b;
}
main(){
	cin >>n>>k;
	for (int i=1;i<=n;++i) scanf("%lld%lld%lld",&a[i],&b[i],&c[i]),y=max(y,c[i]);
	b[n]=k;Matrix ans;ans.data[0][0]=1;
	for (int i=1;i<=n;++i){
		Matrix F;
		for (int j=0;j<=c[i];++j){
			if (j-1>=0) F.data[j-1][j]=1;
			if (j+1<=c[i]) F.data[j+1][j]=1;
			F.data[j][j]=1;
		}
		ans=cheng(ans,power(F,b[i]-a[i]));
		if (c[i]>c[i+1]) for (int j=c[i+1]+1;j<=y;++j) ans.data[j][0]=0;
	}
	cout <<ans.data[0][0]<<endl;return 0;
}
