#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
	ios::sync_with_stdio(false);
	ll m,b; cin>>m>>b; ll ans=0;
	for(int i=0;i<=b;++i){
		ll x=m*(b-i),y=i; if(x<0) continue;
		ans=max(ans,x*(x+1)/2*(y+1)+y*(y+1)/2*(x+1));
	}
	cout<<ans; return 0;
}
