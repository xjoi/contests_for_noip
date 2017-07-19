#include<bits/stdc++.h>
//#define use_fastio; ios::sync_with_stdio(false);cin.tie(0);
using namespace std;
typedef unsigned long long ll;
ll l,r,k;
bool f=0;
int main() {
//	use_fastio;
	cin>>l>>r>>k;
	for(ll i=1;i<=r;i*=k) {
		if(i>=l) {
			f=1;
			cout<<i<<" ";
		}
		if(r/k>=i)
			continue;
		else
			break;
	}
	if(!f) {
		cout<<"-1";
	}
	cout<<endl;
	return 0;
}
