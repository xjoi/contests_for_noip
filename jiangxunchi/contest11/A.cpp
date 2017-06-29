#include<bits/stdc++.h>
using namespace std;
int a[51][51]; 
int main(){
	ios::sync_with_stdio(false);
	int n; cin>>n;
	for(int i=1;i<=n;++i) for(int j=1;j<=n;++j)
		cin>>a[i][j];
	for(int i=1;i<=n;++i) for(int j=1;j<=n;++j)
		if(a[i][j]!=1){
			bool get=0;
			for(int s=1;s<=n;++s){
				for(int t=1;t<=n;++t)
					if(a[i][j]==a[i][s]+a[t][j]){
						get=1; break;
					}
				if(get) break;
			}
			if(!get){
				cout<<"No"; return 0;
			}
		}
	cout<<"Yes"; return 0; 
}
