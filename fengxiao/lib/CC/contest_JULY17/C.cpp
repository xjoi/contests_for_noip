#include<cstdio>
#include<cstring>
#include<iostream>
#define int long long
using namespace std;
int n,b;
inline int max(int a,int b) {return a>b?a:b;}
main()
{
	int T;
	cin>>T;
	while(T--)
	{
		cin>>n>>b;
		int ans=(n/2/b*b)*(n-(n/2/b*b))/b;
		if(n/2/b*b!=n/2)
		ans=max((n/2/b*b+b)*(n-(n/2/b*b+b))/b,ans);
		cout<<ans<<endl;
	}
	return 0;
}
