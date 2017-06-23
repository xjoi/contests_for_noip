#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=600005;
const ll mo=1000000000000000007;
set<ll> s;
int n,m;
ll mul[maxn];
char c[maxn];
int geti(char x)
{
	int num=x-'a'+1;
	return num;
}
ll hash()
{
	ll tmp=0;
	for(int i=0;i<strlen(c);i++)
		tmp=(tmp+(geti(c[i]))*mul[i]%mo)%mo;
	return tmp;
}
bool check()
{
	ll sum=hash();
	for(int i=0;i<strlen(c);i++)
	{
		int num=geti(c[i]);
		for(int j=1;j<=3;j++)
			if(j!=num)
			{
				ll ans=(sum-(num*mul[i]%mo)+(j*mul[i]%mo)+mo)%mo;
//				cout<<c[i]<<"->"<<(char)(j+'a'-1)<<":"<<ans<<endl;
				if(s.count(ans))
					return true;
			}
	}
	return false;
}
int main()
{
	s.clear();
	mul[0]=1;
	for(int i=1;i<=maxn;i++)
		mul[i]=mul[i-1]*4%mo;
	cin>>n>>m;
	while(n--)
	{
		cin>>c;
//		cout<<c<<":"<<hash()<<endl;
		s.insert(hash());
	}
	while(m--)
	{
		cin>>c;
		if(check())
		{
			puts("YES");
			continue;
		}
		else
		{
			puts("NO");
			continue;
		}
	}
	return 0;
}
