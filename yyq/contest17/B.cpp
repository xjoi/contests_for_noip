#include<bits/stdc++.h>
#define use_fastio ios::sync_with_stdio(false);cin.tie(0);
using namespace std;
string s;
int k;
int ma=0;
int num[30];
int ans=0;
int main() {
	use_fastio
	cin>>s;
	cin>>k;
	for(int i=1;i<=26;i++) {
		cin>>num[i];
		ma=max(ma,num[i]);
	}
	for(int i=0;i<s.length();i++) {
		ans=ans+num[s[i]-'a'+1]*(i+1);
//		cout<<ans<<endl;
	}
	for(int i=s.length()+1;i<=s.length()+k;i++) {
		ans=ans+i*ma;
//		cout<<ans<<endl;
	}
	cout<<ans<<endl;
	return 0;
}
