#include<bits/stdc++.h>
using namespace std;
typedef double db;
const db INF=99999999;
set<db> s;
int n;
db x,y;
db xx,yy;
db k;
int main()
{
	cin>>n>>x>>y;
	for(int i=1;i<=n;i++)
	{
		cin>>xx>>yy;
		if(xx!=x&&yy!=y)
			k=(yy-y)/(xx-x);
		if(xx==x&&yy!=y)
			k=INF;
		if(yy==y&&xx!=x)
			k=-INF;
		s.insert(k);
//		cout<<"Case #"<<i<<":"<<k<<endl;
	}
	cout<<s.size()<<endl;
	return 0;
}
