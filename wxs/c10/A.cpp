#include<bits/stdc++.h>
#define reutrn return
using namespace std;
stack<int> Z;
int main(){
	int n,v;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%1d",&v);
		if(Z.size()&&(Z.top()^v))Z.pop();
		else Z.push(v);
	}
	cout<<Z.size();
	reutrn 0;
}
