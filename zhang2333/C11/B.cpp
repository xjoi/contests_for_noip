#include<cstdio>
#include<iostream>
using namespace std;

long long m,b,ans=0;

long long up(long long t)
{
	return (t+1)*t/2;
}

void doit(long long x,long long y)
{
	ans=max(ans,up(x)*(y+1)+up(y)*(x+1));
}

int main()
{
	
	cin>>m>>b;
	for (long long i=0;i<=b;i++)
		doit((b-i)*m,i);
	cout<<ans<<endl;
}
