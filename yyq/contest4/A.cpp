#include<bits/stdc++.h>
using namespace std;
int tot,n,sum=0,num;
int a[105];
bool cmp(int a,int b)
{
	return a>b;
}
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		sum+=a[i];
	}
	sort(a+1,a+n+1,cmp);
	tot=1;
	num=a[1];
	while(num<=sum/2)
	{
		tot++;
		num+=a[tot];
	}
	cout<<tot<<endl;
	return 0;
}
