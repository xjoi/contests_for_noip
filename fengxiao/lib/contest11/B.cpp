#include <cstdio>
#include<cstring>
#define ll long long
using namespace std;
ll m,b,ans=0;
inline ll max(ll a,ll b) {return a>b?a:b;}
int main()
{
	scanf("%I64d %I64d",&m,&b);
	for(ll i=0;i<=b;i++)
	{
		ll j=(b-i)*m;
		ll sum=(i+1)*(j+1)*(i+j)/2;
		ans=max(ans,sum);
	}
	printf("%I64d\n",ans);
}
