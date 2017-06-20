#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n;
int a[100005],i;
ll k,sum=0;
int main()
{
	cin>>n>>k;
	for(i=0;i<n;i++)
		cin>>a[i];
	sort(a,a+n);
	k--;
	for(i=0;i<n;i+=sum)
	{
		for(sum=1;a[i]==a[i+sum];sum++);
		if(sum*n>k)
			break;
		k-=sum*n;
	}
	cout<<a[i]<<" "<<a[k/sum]<<endl;
	return 0;
}
