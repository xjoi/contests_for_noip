#include<bits/stdc++.h>
using namespace std;
int n;
int num[305];
int tot;
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&num[i]);
		tot+=num[i];
	}
	int sum=1;
	if(num[sum]>0)
	{
		cout<<"P";
		num[sum]--;
		tot--;
		while(num[sum]>0)
		{
			cout<<"R";
			sum++;
			if(num[sum]>0)
			{
				cout<<"PLP";
				num[sum]--;
				tot--;
			}
			else
				cout<<"LP";
			sum--;
			num[sum]--;
			tot--;
		}
	}
	while(tot>0)
	{
		while(num[sum]==0)
		{
			cout<<"R";
			sum++;
		}
		if(num[sum]>0)
		{
			cout<<"P";
			num[sum]--;
			tot--;
			while(num[sum]>0)
			{
				cout<<"LRP";
				num[sum]--;
				tot--;
			}
		}
	}
	return 0;
}
