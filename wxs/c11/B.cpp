#include<bits/stdc++.h>
using namespace std;
#define int long long
int m,b;long long MAX=-1;
main(){
	scanf("%lld%lld",&m,&b);
	for(int y=0;y<=b;y++){
		int x=(b-y)*m;
		MAX=max(MAX,(y+1)*(x+1)*x/2+(x+1)*(y+1)*y/2);
	}
	printf("%lld",MAX);
	return 0;
}
