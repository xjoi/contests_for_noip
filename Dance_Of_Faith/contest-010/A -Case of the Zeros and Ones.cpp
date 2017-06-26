#include<iostream>
#include<cstring>
#include<cstdio>
#include<cmath>
using namespace std;
int pr[500010];char a[500010];
int main(){
	int n,ans;
	cin >>n;ans=n;a[0]='R';
	for (int i=1;i<=n;++i) cin >>a[i];
	for (int i=1;i<=n;++i) pr[i]=i-1;
	for (int i=2;i<=n;++i)
		if (a[i]==a[pr[i]]+1||a[i]+1==a[pr[i]])
			ans-=2,pr[i+1]=pr[pr[i]];
	cout <<abs(ans)<<endl;return 0;
}
