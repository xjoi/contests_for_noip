#include<iostream>
#include<cstdio>
using namespace std;
int main(){
  int n,b,ans=0;
	cin >>n>>b;
	ans+=n;
	while (n>=b){
		int ff=n/b;
		ans+=ff;n=n%b+ff;
	}
	cout <<ans<<endl;
}
