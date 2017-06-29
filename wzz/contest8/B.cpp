using namespace std;
#include<bits/stdc++.h>
int n,m,k;
int a[501];
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=a[1];i++){cout<<"RLP";}cout<<"R";
	for(int i=2;i<=n-1;i++){for(int j=1;j<=a[i];j++)cout<<"RLP";cout<<"R";}
	for(int i=1;i<=a[n];i++)
	{
		cout<<"LRP";
	}
}
