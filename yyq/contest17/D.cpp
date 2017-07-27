#include<bits/stdc++.h>
#define use_ios ios::sync_with_stdio(false);
#define use_tie cin.tie(0);
using namespace std;
typedef long long ll;
const ll inf=1e18;
const int maxn=1010;
const int maxk=1000010;
int n,m;
ll k,p,ans=-inf;
ll a[maxn][maxn];
ll suma[maxn],sumb[maxn];
ll br[maxk],bc[maxk];
priority_queue<ll> qr,qc;
int main() {
	use_ios
	use_tie
	cin>>n>>m>>k>>p;
	for(int i=1;i<=n;i++) {
		for(int j=1;j<=m;j++) {
			cin>>a[i][j];
			suma[i]+=a[i][j];
			sumb[j]+=a[i][j];
		}
	}
	for(int i=1;i<=n;i++)
		qr.push(suma[i]);
	for(int i=1;i<=m;i++)
		qc.push(sumb[i]);
	for(int i=1;i<=k;i++) {
		ll r=qr.top();
		qr.pop();
		br[i]=br[i-1]+r;
		qr.push(r-m*p);
		ll c=qc.top();
		qc.pop();
		bc[i]=bc[i-1]+c;
		qc.push(c-n*p);
	}
	for(int i=0;i<=k;i++) {
		ans=max(ans,br[i]+bc[k-i]-(i*(k-i)*p));
	}
	cout<<ans<<endl;
	return 0;
}
