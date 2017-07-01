#include<bits/stdc++.h>
using namespace std;
typedef double db;
typedef long long ll;
db n,m,N;
int main()
{
	scanf("%lf%lf%lf",&n,&m,&N);
	printf("%lld\n",(ll)(min((N+1)*(m/n),N)));
	return 0;
} 
