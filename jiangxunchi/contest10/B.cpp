#include<cstdio>
#include<cstdlib>
int a[1001];
void error(){
	printf("No"); exit(0);
}
int main(){
	int n; scanf("%d",&n);
	for(int i=1;i<=n;++i) scanf("%d",&a[i]);
	int rot=a[1]%n;
	for(int i=2;i<=n;++i){
		if(i%2==0) if((a[i]+rot)%n!=i-1) error(); else;
		else if((a[i]-rot+n)%n!=i-1) error();
	}
	printf("Yes"); return 0;
}
