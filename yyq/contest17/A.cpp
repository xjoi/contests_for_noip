#include<bits/stdc++.h>
#define use_fastio ios::sync_with_stdio(false);cin.tie(0);
using namespace std;
set<int> s;
int n,p,x;
int main() {
	use_fastio
	cin>>p>>n;
	for(int i=1;i<=n;i++) {
		cin>>x;
		x%=p;
		if(!s.count(x)) {
			s.insert(x);
		}
		else {
			cout<<i<<endl;
			return 0;
		}
	}
	cout<<"-1"<<endl;
	return 0;
}
