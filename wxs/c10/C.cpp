#include<bits/stdc++.h>
using namespace std;
int n,m,ans=0,a[100005],f;
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++){
		int w;
		f=1;
		scanf("%d",&w);
		for(int j=1;j<=w;j++){
			scanf("%d",&a[j]);
			if(f&&a[j]==j){if(j>1)ans-=2;}
			else f=0;
		}
		ans+=w-1;
	}
	cout<<ans+n-1;
	return 0;
}
