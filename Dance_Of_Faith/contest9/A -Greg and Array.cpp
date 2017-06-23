#include<iostream>
#include<cstdio>
#include<cstring>
#define int long long
using namespace std;
int a[200010],s[200010],d[200010],p[200010],q[200010],b[200010];
int c[200010][5];
main(){
	int n,k,m,x,y;cin >>n>>m>>k;
	for (int i=1;i<=n;++i) cin >>a[i],p[i]=p[i-1]+a[i];
	for (int i=1;i<=m;++i)
		cin >>c[i][1]>>c[i][2]>>c[i][3];
	for (int i=1;i<=k;++i)
		cin >>x>>y,b[x]++,b[y+1]--;
	for (int i=1;i<=m;++i) q[i]=q[i-1]+b[i];
	for (int i=1;i<=m;++i)
		d[c[i][1]]+=q[i]*c[i][3],d[c[i][2]+1]-=q[i]*c[i][3];
	for (int i=1;i<=n;++i) s[i]=s[i-1]+d[i];
	for (int i=1;i<=n;++i) cout <<p[i]-p[i-1]+s[i]<<' ';
	return 0;
}
