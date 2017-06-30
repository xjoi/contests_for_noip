#include<bits/stdc++.h>
using namespace std;
#define int long long
#define MOD 1000000007
int n,size=1;
long long k;
struct M{
	int mat[17][17];
	M(){
		memset(mat,0,sizeof mat);
	}
}e,m,ans;
void init(){
	for(int i=0;i<=15;i++){
		e.mat[i][i]=1;
		m.mat[i][i]=1;
		if(i>0)m.mat[i][i-1]=1;
		if(i<15)m.mat[i][i+1]=1;
	}
}
M operator*(M A,M B){
	M C;
	for(int i=0;i<size;i++){
		for(int j=0;j<size;j++){
			for(int k=0;k<size;k++){
				C.mat[i][j]+=A.mat[i][k]*B.mat[k][j]%MOD;
				C.mat[i][j]%=MOD;
			}
		}
	}
	return C;
}
M Pow(M A,int B){
	M ANS=e;
	while(B){
		if(B&1)ANS=ANS*A;
		A=A*A;
		B>>=1;
	}
	return ANS;
}
main(){
	init();
	ans.mat[0][0]=1;
	scanf("%lld%lld",&n,&k);
	for(int i=1;i<=n;i++){
		long long a,b;
		int c;
		scanf("%lld%lld%lld",&a,&b,&c);
		long long v=min(k,b)-a;
		for(int j=c+1;j<16;j++)ans.mat[0][j]=0;
		size=c+1;
		ans=ans*Pow(m,v);
		if(k<=b){
			printf("%lld",ans.mat[0][0]);
			return 0;
		}
	}
	return 0;
}
