#pragma GCC optimize("O3")
#include<bits/stdc++.h>
#define P pair<char ,int>
#define dmap map<int, pair<char ,int> > 
using namespace std;
dmap ma;
dmap ::iterator it;
int ans=0,n,m,x,y;
string s;


int main()
{
	ios::sync_with_stdio(false);
	cin>>n>>m;
	ma[0]=P('U',0);
	ma[n+1]=P('L',0); 
	while(m--)
	{
		cin>>x>>y>>s;
		ans=0;
		it=ma.lower_bound(x);
		if(it->first==x){cout<<"0\n";continue;}
		if(s[0]=='L')it--;
		ans=abs((it->first)-x);
		if(it->second.first==s[0]) 
			ans+=it->second.second;
		cout<<ans<<endl;
		ma[x]=P(s[0],ans); 
	}
	return 0;
}
