#include<bits/stdc++.h>
#define LL long long
#define P pair<long long ,long long>
using namespace std;
LL n,rx,ry;
LL m,b;
vector<P> v;
LL ans=0;

int main()
{
	cin>>m>>b;
	rx=m*b;ry=b;
	for(LL i=0;i<=ry;i++)
		v.push_back(P((LL)(b-i)*m,i));
	for(LL i=0;i<v.size();i++)
	{
		LL x=v[i].first,y=v[i].second;
		ans=max(ans,(x+1)*(y+1)*(x+y)/2);
	}
	cout<<ans<<endl;
	return 0;
}
