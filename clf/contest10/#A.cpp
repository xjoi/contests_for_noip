#include<cstdio>
#include<iostream>
#include<cstring>
#include<cmath>
using namespace std;
char s[200005];
int main() {
	int a0=0,a1=0,n;
	scanf("%d\n",&n);
	scanf("%s",s);
	for(int i=0;i<n;i++) {
		if(s[i]=='0') a0++;
		else a1++;
	}
	if(a1>a0) printf("%d\n",a1-a0);
	else printf("%d\n",a0-a1);
	return 0;
}
