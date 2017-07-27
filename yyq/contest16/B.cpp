#include<bits/stdc++.h>
#define use_fastio; ios::sync_with_stdio(false);cin.tie(0);
using namespace std;
typedef long long ll;
string s;
string ans="";
int sum=0;
int n;
bool f=0;
int main() {
	use_fastio;
	cin>>n;
	while(n--) {
		cin>>s;
		if(s[0]=='0') {
			puts("0");
			return 0;
		}
		else if(s[0]!='1') {
			ans=ans+s;
			f=1;
			continue;
		}
		else if(s[0]=='1') {
			for(int i=1;i<s.length();i++) {
				if(s[i]!='0') {
					ans+=s;
					f=1;
					sum-=(i-1);
					break;
				}
				if(s[i]=='0')
					sum++;
			}
		}
	}
	if(!f)
		cout<<"1";
	else
		cout<<ans;
	for(int i=1;i<=sum;i++)
		cout<<"0";
	cout<<endl;
	return 0;
}
