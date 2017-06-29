//神奇o2比o3快
#pragma GCC optimize("O2")
#include<bits/stdc++.h>
#define maxn 400000
#define LL long long
#define P pair<pair<LL,LL>,LL>
#define pi pair<LL,LL>
#define mp make_pair
#define fi first
#define se second
using namespace std;
LL n,m;
set<pi>sets;
pi s[maxn];
P a[maxn];
LL ans[maxn];

bool cmp(P a,P b){	return a.fi.se<b.fi.se||(a.fi.se==b.fi.se&&a.fi.fi>b.fi.fi);}

main()
{
	ios::sync_with_stdio(false);
	cin>>n>>m;
	for(LL i=1;i<=n;i++)
		cin>>s[i].fi>>s[i].se;
	for(LL i=1;i<n;i++)
	{
		a[i].fi.fi=s[i+1].fi-s[i].se;
		a[i].fi.se=s[i+1].se-s[i].fi;
		a[i].se=i;
	}
	sort(a+1,a+n,cmp);
	LL x;
	for(LL i=1;i<=m;i++)
	{
		cin>>x;
		sets.insert(mp(x,i));
	}
	for(LL i=1;i<n;i++)
	{
		set<pi> ::iterator it=sets.upper_bound(mp(a[i].fi.fi,0));
		if(it==sets.end()||it->fi>a[i].fi.se)
		{
			cout<<"No\n";
			return 0;
		}
		ans[a[i].se]=it->se;
		sets.erase(it);
	}
	cout<<"Yes\n";
	for(LL i=1;i<n;i++)
		cout<<ans[i]<<" ";
	return 0;
}
