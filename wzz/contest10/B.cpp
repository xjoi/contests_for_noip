using namespace std;
#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<cmath>
#define N 1001
int a[N];
int n;
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	int ans=0;
	for(int i=1;i<=n;i++)
	{
		if(i%2==1)
		{
			ans+=(a[i]-(i-1));
		}
		else
		{
			ans-=(a[i]-(i-1));
		}
	}
	if(ans%n==0)puts("Yes");
	else puts("No");
}
