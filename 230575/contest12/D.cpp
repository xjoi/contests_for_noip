#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
	int n,k,t;
	int a[25];
	cin>>n>>k;
	for (int i=1;i<=k;++i)
	cin>>a[i];
	t=n;
	for (int i=1;i<=k;++i)
	{
		t=t+a[i]-n;
		if (t<=0)
		{
			cout<<'0'<<endl;
			return 0;
		}
	}
	cout<<t<<endl;
	return 0;
}
