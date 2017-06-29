#include<iostream>
using namespace std;
int main(){
	long long x,y,m,b,ans=0;cin >>m>>b;
	for (long long x=0;b-x/m>=0;x+=m){
		y=b-x/m;
		ans=max(ans,(x+1)*(y+1)*(x+y));
	}
	cout <<ans/2<<endl;return 0;
}
