#include <bits/stdc++.h>
using namespace std;
int a[55][55];
int main(){
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		if(i%2){
			for(int j=1;j<=m;j++)putchar('#');
			putchar('\n');
		}else if(i%4){
			for(int j=1;j<m;j++)putchar('.');
			putchar('#');putchar('\n');
		}else{
			putchar('#');
			for(int j=1;j<m;j++)putchar('.');
			putchar('\n');
		}
	}
	return 0;
}
