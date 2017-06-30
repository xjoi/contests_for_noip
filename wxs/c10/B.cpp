#include<bits/stdc++.h>
#define reutrn return
using namespace std;
int main(){
	int v,n,z;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d",&v);
		if(i==0){
			z=(n-v)%n;
		}else if(i%2==1){
			if(z!=(v-i+n)%n){
				puts("No");
				return 0;
			}
		}else{
			if(z!=(i-v+n)%n){
				puts("No");
				return 0;
			}
		}
	}
	puts("Yes");
	reutrn 0;
}
