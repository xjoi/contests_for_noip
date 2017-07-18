#include<cstdio>
#include<iostream>
using namespace std;
typedef long long ll;
ll m,b,ans=0,s1,s2;
int main()
{
	cin>>m>>b;
	for(ll x=0;x<=m*b;x++)
	{
		ll y=(ll)b-x/m;
		if(x%m!=0)
		    y--;
		s1=(x+1)*x/2;
		s2=s1*(y+1)+(y+1)*y*(x+1)/2;
		ans=max(ans,s2);
	}
	cout<<ans<<endl;
	return 0;
}
