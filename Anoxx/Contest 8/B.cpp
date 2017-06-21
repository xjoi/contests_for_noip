#include<cstdio>
#include<iostream>
#include<cstring>
#include<string>
using namespace std;
int n,a[1000],p;
char ans[1000000];
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		p+=a[i]==0;
	}
	int i=1,l=1,k=0;
	while(p<n){
		if(a[i]){
			ans[k++]='P',a[i]--,p+=a[i]==0;
		}
		if(p==n)break;
			if(l==1){
				if(i!=n)i++,ans[k++]='R';else i--,ans[k++]='L',l=0;
			}
			else{if(i!=1)i--,ans[k++]='L';else i++,ans[k++]='R',l=1;
				
			}
	        
	}
	printf("%s",ans);
}
