#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,k,num,tmp;
int main()
{
	scanf("%d%d",&n,&k);
	tmp=n;
	for(int i=1;i<=k;i++)
	{
		scanf("%lld",&num);
		tmp=max(tmp+num-n,0ll);
	}
	printf("%lld\n",tmp);
	return 0;
}
