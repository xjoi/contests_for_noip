#include<cstdio>
int main(){
	int n; scanf("%d",&n);
	for(int i=1;i<=n;++i){
		int x; scanf("%d",&x);
		if(x==0){
			if(i!=n) printf("R");
			continue;
		}
		if(i==1){
			printf("P");
			for(int i=1;i<x;++i) 
			printf("RLP");
		}else{
			printf("P");
			for(int i=1;i<x;++i)
			printf("LRP");
		}
		if(i!=n) printf("R");
	}
	return 0;
}
