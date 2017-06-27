#include<bits/stdc++.h>
using namespace std;
int a[55][55];
int main(){
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			scanf("%d",&a[i][j]);
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(a[i][j]!=1){
				int k=0;
				for(int ii=1;ii<=n;ii++){
					for(int jj=1;jj<=n;jj++){
						if(ii!=i&&jj!=j){
							if(a[i][jj]+a[ii][j]==a[i][j])k=1;
						}
					}
				}
				if(k==0){
					puts("No");
					return 0;
				}
			}
		}
	}
	puts("Yes");
	return 0;
}
