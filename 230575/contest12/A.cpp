#include<iostream>
#include<cmath>
using namespace std;
int main()
{
	long long n,m,N,M;
	cin>>n>>m>>N;
    M=(N+1)*m/n;
    if(M>N) M=N;
    printf("%I64d\n",M);
	return 0;
}
