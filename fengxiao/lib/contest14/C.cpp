#include<cstdio>
int n; 
int main(){
	scanf("%d",&n);
	printf("2\n");
	for(long long i=1;i<n;++i)
		printf("%lld\n",(i+2)*(i+2)*(i+1)-i);
	return 0;
}
