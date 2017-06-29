#include<bits/stdc++.h>
#define LL long long
using namespace std;
typedef pair<LL,LL> P;
LL n,k;
LL a[200000];
map<LL,LL> Map;
vector<P> v;

bool cmp(P a,P b)
{
	return a.first<b.first||(a.first==b.first&&a.second<b.second);
}

int main()
{
	cin>>n>>k;
	for(LL i=1;i<=n;i++)
	{
		LL x;
		cin>>x;
		Map[x]++;
	}
	map<LL,LL>::iterator it;
	for(it=Map.begin();it!=Map.end();it++)
		v.push_back(make_pair(it->first,it->second));
	sort(v.begin(),v.end(),cmp);
	/*for(LL i=0;i<v.size();i++)
		cout<<v[i].first<<" "<<v[i].second<<"\n";*/
	for(LL i=0,num=0;i<v.size()&&num<k;i++)
	{
		if(v[i].second*n+num<k)
		{	num+=v[i].second*n;continue;}
		cout<<v[i].first<<" ";
		LL res=k-num,ans=0;
		for(LL j=0;j<v.size();j++)
		{
			ans+=v[i].second*v[j].second;
			if(ans>=res&&ans-v[i].second*v[j].second<res)
			{	cout<<v[j].first<<"\n";return 0;}
		}
	}
	return 0;
	
}
