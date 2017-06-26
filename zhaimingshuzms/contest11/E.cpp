#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
typedef long long ll;
const ll MO=1000000007,N=101;
struct jz{ll h,l,z[16][16];}a,b,t;
ll n,k,lac,c,x,y,maxx;
void clear(){
	b.h=b.l=15;
	for (ll i=0; i<=b.h; i++) 
	for (ll j=0; j<=b.l; j++)
	b.z[i][j]=0;
}
jz multi(jz a,jz b){ 
	t.h=a.h; t.l=b.l;
	for (ll i=0; i<=t.h; i++)
	for (ll j=0; j<=t.l; j++){
		t.z[i][j]=0;
		for (ll k=0; k<=a.l; k++)
		t.z[i][j]=(t.z[i][j]+a.z[i][k]*b.z[k][j]%MO)%MO;
	}
	return t;
}
void test(jz b){
	printf("-----------------\n");
	for (ll i=0; i<=b.h; i++){
		for (ll j=0; j<=b.l; j++)
		printf("%lld ",b.z[i][j]);
		printf("\n");
	}
}
void pow(ll x){
	//test(b);
	while (x){
		if (x&1) a=multi(a,b);
		x>>=1;
		b=multi(b,b);
	}
}
int main(){
	scanf("%lld%lld",&n,&k);
	a.h=0; a.l=15; a.z[0][0]=1;
	while (n--){
		scanf("%lld%lld%lld",&x,&y,&c);
		if (y>k) y=k;
		clear();
		for (ll j=0; j<=c; j++){
			b.z[j][j]=1;
			if (j>0) b.z[j][j-1]=1;
			if (j<c) b.z[j][j+1]=1;
		}
		pow(y-x);
	}
	printf("%lld",a.z[0][0]);
	return 0;
}
