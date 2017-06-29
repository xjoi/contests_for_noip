#include<cstdio>
using namespace std;
int n,a[1001];
bool judge(){
	for(int i=1;i<=n;i++)
	if(a[i]!=(i-1))return 0;
	return 1;
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++)
		a[j]=j%2?(a[j]+1)%n:(a[j]-1+n)%n;
		if(judge())return printf("YES"),0;
	}
	return printf("NO"),0;
}
