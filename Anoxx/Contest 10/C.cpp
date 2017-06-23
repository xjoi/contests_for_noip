#include<cstdio>
using namespace std;
int n,m,x,y,p,z;
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++){
		scanf("%d%d",&x,&y);
		if(y==1)for(int j=2;j<=x;j++){
			scanf("%d",&z);
			if(z==y+1)y=z,p--;else p++;
		}
		else for(int j=1;j<x;j++){
			scanf("%d",&z);p++;
		}
	}
	printf("%d",n-1+p);
}
