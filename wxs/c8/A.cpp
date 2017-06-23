#include<bits/stdc++.h>
using namespace std;
int a,b,v;
int main(){
	scanf("%d%d",&a,&b);
	while(a>=b){
		v+=a-a%b;
		a=a/b+a%b;
	}
	printf("%d",a+v);
	return 0;
}
/**
手速太慢
**/
