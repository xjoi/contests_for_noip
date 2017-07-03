#include<iostream>
using namespace std;
long int a[105]={0};
int main()
{
	int m,n;
	cin>>m>>n;
	int i,j,k,l;
	for(i=0;i<n;i++)
	{
		cin>>j>>k>>l;a[--j]+=l;a[--k]-=l;
	}
	int sum=0;
	for(i=0;i<m;i++)if(a[i]>0)sum+=a[i];
	cout<<sum;
	return 0;
}
