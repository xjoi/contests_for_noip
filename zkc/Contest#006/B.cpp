#include <bits/stdc++.h>
using namespace std;

int n,a[110][110],k,ans=0;

int main() {
	cin>>n>>k;
	int i=1,j=1;
	while(ans<k&&i<=n&&j<=n) {
		a[i][j]=1;
		ans++;
		i+=2;
		if(i>n) {
			j++;
			i=j%2;
			if(i==0) i=2;
		}
	}
	if(ans>=k) {
		puts("YES");
		for(int i=1;i<=n;i++) {
			for(int j=1;j<=n;j++) {
				if(a[i][j]==1) cout<<"L";
				else cout<<"S";
			}
			cout<<endl;
		}
	} else {
		puts("NO");
	}
    return 0;
}