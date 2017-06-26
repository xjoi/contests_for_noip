#include<iostream>
#include<cstdio>
#include<cstring>
#include<set>
#include<algorithm>
#define int long long
using namespace std;
const int INF=1e16;

set<pair<int,int> > s;
set<pair<int,int> > ::iterator it;
pair<int,int> a[300100];
pair<pair<int,int>,int> br[300100];
int ans[300010];
bool cmp(pair<pair<int,int>,int> a,pair<pair<int,int>,int> b){
	return a.first.first>b.first.first;
}

main(){
	int n,m,xx;cin >>n>>m;
	for (int i=1;i<=n;++i) scanf("%lld%lld",&a[i].first,&a[i].second);
	for (int i=1;i<n;++i)
		br[i]=make_pair(make_pair(a[i+1].first-a[i].second,a[i+1].second-a[i].first),i);
	for (int i=1;i<=m;++i) scanf("%lld",&xx),s.insert(make_pair(xx,i));
	sort(br+1,br+n,cmp);
	for (int i=1;i<n;++i){
		int l=br[i].first.first,r=br[i].first.second;
		it=s.lower_bound(make_pair(r,INF));
		if (it==s.begin()) return puts("No");
		--it;
		if (it->first<l) return puts("No");
		ans[br[i].second]=it->second;
		s.erase(it);
	}
	puts("Yes");
	for (int i=1;i<n;++i) printf("%lld ",ans[i]);
	return 0;
}
