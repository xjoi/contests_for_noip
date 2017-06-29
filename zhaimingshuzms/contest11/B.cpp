#include<cstdio>
#include<algorithm>
using namespace std;
long long m,b,x;
long long maxx,ans;
int main(){
	scanf("%lld%lld",&m,&b);
	for (long long i=0; i<=b; i++){
		x=m*(b-i);
		ans=0;
		for (long long j=0; j<=i; j++)
		ans+=(x+2*j)*(x+1)/2;
		maxx=max(maxx,ans);
	}
	printf("%lld",maxx);
	return 0;
}
