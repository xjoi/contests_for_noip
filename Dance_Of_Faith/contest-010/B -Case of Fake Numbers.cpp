#include<iostream>
#include<cstdio>
using namespace std;
int a[1010];
int main(){
	int n;cin >>n;
	for (int i=1;i<=n;++i) scanf("%d",&a[i]);
	for (int i=1;i<=5000;++i){
		bool flag=true;
		for (int i=1;i<=n;++i)
			if (a[i]!=i-1) {flag=0;break;}
		if (flag){puts("Yes");return 0;}
		for (int i=1;i<=n;++i)
			if (i%2==1)	 a[i]=(a[i]+1)%n;
					else a[i]=(a[i]-1+n)%n;
	}
	puts("No");return 0;
}
