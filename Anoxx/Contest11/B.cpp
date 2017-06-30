#include<cstdio>
#include<algorithm>
using namespace std;
long long m,b,ans;
int main(){
	scanf("%lld%lld",&m,&b);
	for(long long i=0;i<=b;i++){
		long long x=(b-i)*m;
		long long sum=x*(x+1)/2;
		ans=max(ans,(sum+sum+(x+1)*i)*(i+1)/2);
	}
	printf("%lld",ans);
}
