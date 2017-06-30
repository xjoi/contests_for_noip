#include<bits/stdc++.h>
using namespace std;
stack<int> S;
int main(){
	ios::sync_with_stdio(false);
	int n,ans=0,cnt=0; cin>>n;
	for(int i=1;i<=n*2;++i){
		string s; cin>>s;
		if(s=="remove"){
			++cnt;
			if(S.empty()) continue;
			if(S.top()==cnt) S.pop();
			else{
				++ans;
				for(;!S.empty();S.pop());
			}
		}else if(s=="add"){
			int x; cin>>x;
			S.push(x);
		}
	}
	cout<<ans; return 0;
}
