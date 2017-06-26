#include<cstdio>
#include<cstring>
#define MOD 1000000007
#define ll long long
using namespace std;
int n;
ll a[200],b[200],c[200],y,k;
struct matrix{
	ll a[20][20];
	matrix(){
		memset(a,0,sizeof(a));
	}
};
matrix operator *(matrix a,matrix b){
	matrix c;
	for(int i=0;i<=y;i++)
	for(int j=0;j<=y;j++)
	for(int k=0;k<=y;k++)
	c.a[i][j]=(c.a[i][j]+b.a[i][k]*a.a[k][j]%MOD)% MOD;
	return c;
}
matrix operator ^(matrix a,ll b){
	matrix c;
	for(int i=0;i<=y;i++)c.a[i][i]=1;
	while(b){
		if(b&1)c=c*a;
		a=a*a;b>>=1;
	}
	return c;
}
int main(){
    scanf("%d%lld",&n,&k);
    for(int i=1;i<=n;i++){
    	scanf("%lld%lld%lld",&a[i],&b[i],&c[i]);
    	y=c[i]>y?c[i]:y;
	}
	b[n]=k;
    matrix tmp;tmp.a[0][0]=1;
    for(int i=1;i<=n;i++){
    	matrix f;
    	for(int j=0;j<=c[i];j++){
    		if(j-1>=0)f.a[j-1][j]=1;
    		if(j+1<=c[i])f.a[j+1][j]=1;
    		f.a[j][j]=1;
		}
		tmp=tmp*(f^(b[i]-a[i]));
		if(c[i]>c[i+1])for(int j=c[i+1]+1;j<=y;j++)tmp.a[j][0]=0;
		
	}
	printf("%lld",tmp.a[0][0]);
	return 0;
}
