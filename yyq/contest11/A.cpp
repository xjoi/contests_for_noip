#include<bits/stdc++.h>
using namespace std;
int n;
bool flg=1;
int num[55][55];
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			cin>>num[i][j];
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(num[i][j]!=1)
			{
//				cout<<num[i][j]<<endl;
				bool flg2=false;
//				cout<<"!!!"<<endl;
				for(int k=1;k<=n;k++)
				{
					if(k==i)
						continue;
					for(int p=1;p<=n;p++)
					{
						if(p==j)
							continue;
//						cout<<num[i][p]<<" "<<num[k][j]<<endl;
						if(num[i][p]+num[k][j]==num[i][j])
						{
							flg2=1;
							break;
						}
					}
					
					if(flg2)
						break;
				}
				if(!flg2)
				{
					flg=0;
					break;
				}
			}
			if(!flg)
				break;
		}
		if(!flg)
			break;
	}
	if(flg)
		puts("Yes");
	else
		puts("No");
	return 0;
}
