#pragma GCC optimize("O3")
#include<bits/stdc++.h>
#define int long long
using namespace std;
priority_queue<int,vector<int>,greater<int> > q;
stack<int> s;
int n,ans=0,ok=0,now=0;
char str[200];

main()
{
	cin>>n;
	n=n*2;
	while(n--)
	{
		cin>>str;
		if(str[0]=='a')
		{
			int t1;
			cin>>t1;
			s.push(t1);
		}
		else
		{
			now++;
			if(s.empty())
				q.pop();
			else if(s.top()==now)
				s.pop();
			else 
			{
				ans++;
				while(!s.empty())
					{q.push(s.top());s.pop();}
				q.pop();
			}
		}
	}
	cout<<ans<<endl;
}
