#include<cstdio>
#include<iostream>
using namespace std;
int seq[1005];
int main() {
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&seq[i]);
	for(int i=1;i<=n*3;i++) {
		bool flag=1;
		for(int j=1;j<=n;j++) if(seq[j]!=j-1) {flag=0;break;}
		if(flag) {
			printf("Yes\n");
			return 0;
		}
		for(int j=1;j<=n;j++) {
			if(j%2) seq[j]=(seq[j]+1)%n;
			else seq[j]=(seq[j]+n-1)%n;
		}
	}
	printf("No\n");
	return 0;
}
