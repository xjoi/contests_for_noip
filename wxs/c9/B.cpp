#include<bits/stdc++.h>
#define int long long
using namespace std;
int h[505],d[505][505],m[505][505],n,ans[505];
main(){
	scanf("%I64d",&n);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			scanf("%I64d",&d[i][j]);
		}
	}
	for(int i=n;i>0;i--){
		scanf("%I64d",&h[i]);
	}
	for(int i=1;i<=n;i++){
		for(int k=1;k<=i;k++){
			for(int j=1;j<=i;j++){
				if(j!=k&&d[h[i]][h[k]]+d[h[k]][h[j]]<d[h[i]][h[j]])d[h[i]][h[j]]=d[h[i]][h[k]]+d[h[k]][h[j]];
				if(j!=k&&d[h[j]][h[k]]+d[h[k]][h[i]]<d[h[j]][h[i]])d[h[j]][h[i]]=d[h[j]][h[k]]+d[h[k]][h[i]];
			}
		}
		if(i==1){ans[i]=0;continue;}
		ans[i]=0;
		for(int j=1;j<=i;j++){
			for(int k=1;k<=i;k++){
				if(j!=k&&d[h[j]][h[i]]+d[h[i]][h[k]]<d[h[j]][h[k]])d[h[j]][h[k]]=d[h[j]][h[i]]+d[h[i]][h[k]];
			}
		}
		for(int j=1;j<=i;j++){
			for(int k=1;k<=i;k++){
				ans[i]+=d[h[j]][h[k]];
			}
		}
	}
	for(int i=n;i>0;i--){
		printf("%I64d ",ans[i]);
	}
	return 0;
}
