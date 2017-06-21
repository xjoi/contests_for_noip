#include<bits/stdc++.h>
using namespace std;
int n,a[305],Max=-1,sum=0;
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",a+i);
		sum+=a[i];
		Max=max(a[i],Max);
	}
	for(int i=1;i<=Max;i++){
		for(int j=1;j<=n;j++){
			if(a[j])printf("P"),a[j]--,sum--;
			if(sum==0)break;
			if(j!=n)printf("R");
		}
		if(sum!=0)for(int j=1;j<n;j++)printf("L");
	}
	return 0;
}
/**
题意理解太慢
**/
