using namespace std;
#include<cstdio>
#include<iostream>
int n,k;
int ans;
int main()
{
	cin>>n>>k;
	while(n)
	{
		if(n<k){ans+=n;cout<<ans<<endl;return 0;}
		else
		{
			n-=k;ans+=k;n++;
		}
	}
}
