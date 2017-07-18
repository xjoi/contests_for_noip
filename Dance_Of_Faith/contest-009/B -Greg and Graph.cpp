#include<iostream>
#define int long long
using namespace std;
int d[510][510],l[510],ans[510];
main(){
	int n;cin >>n;
	for (int i=1;i<=n;++i)
		for (int j=1;j<=n;++j) cin >>d[i][j];
	for (int i=1;i<=n;++i) cin >>l[i];
	for (int k=n;k>=1;--k){
		for (int i=1;i<=n;++i)
		for (int j=1;j<=n;++j)
			d[l[i]][l[j]]=min(d[l[i]][l[j]],d[l[i]][l[k]]+d[l[k]][l[j]]);
		for (int i=k;i<=n;++i)
		for (int j=k;j<=n;++j)
			ans[k]+=d[l[i]][l[j]];
	}
	for (int i=1;i<=n;++i) cout <<ans[i]<<' ';
	return 0;
}
