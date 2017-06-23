#include<iostream>
#include<cstdio>
using namespace std;
int main(){
	int x,m,n,k,cnt=0;
	cin >>n>>k;
	for (int i=1;i<=k;++i){
		scanf("%d",&m);cnt+=m-1;
		for (int i=1;i<=m;++i){
			scanf("%d",&x);
			if (x==i) cnt-=2;
		}
	}
	cout <<n+cnt+1<<endl;
	return 0;
}
