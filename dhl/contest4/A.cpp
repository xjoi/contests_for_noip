#include<bits/stdc++.h>
using namespace std;
int n;
int a[200];
int ans=0,sum=0,rans=0;
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{	cin>>a[i];sum+=a[i];}
	sort(a+1,a+n+1);
	for(int i=n;i>=1;i--)
	{
		ans+=a[i];
		if(ans>sum-ans) break;
		rans++;
	}
	cout<<rans+1<<endl;
	return 0;
}
