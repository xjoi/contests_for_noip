#include<cstdio>
#include<iostream>
using namespace std;
int b,n,m,ans;
int main()
{
	scanf("%d%d",&n,&b);
	m=0;
	ans=0;
	while (n>0)
	{
		ans+=n;
		m+=n;
		n=m/b;
		m-=n*b;
	}
	printf("%d",ans);
}
