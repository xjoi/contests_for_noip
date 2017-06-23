#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int main(){
	int k,ans,b,p;
	scanf("%d%d",&ans,&b);
	k = ans;
	while (k >= b){
		ans += k/b;
		p = k/b;
		(k %= b) += p;
	}
	cout << ans << endl;
	return 0;
}
