#include<cstdio>
#include<cstring>
#include<iostream>
#define ll unsigned long long
using namespace std;
ll l,r,k; bool flag=0;
int main()
{
	scanf("%I64d %I64d %I64d",&l,&r,&k);
	ll num=1;
	if(l<=1) {printf("1 "); flag=1;}
	for(int i=1; num<=r/k;i++)
	{
		num*=k;
		if(num>=l){ printf("%I64d ",num);flag=1;}
	}
	if(!flag) puts("-1");
	return 0;
}
