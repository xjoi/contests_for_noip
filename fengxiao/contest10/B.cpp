#include<cstdio>
#include<cstring>
using namespace std;
int n,a[1010];
int main()
{
	int i;
	scanf("%d",&n);
	for(i=1;i<=n;i++) scanf("%d",&a[i]);
	int t=(n-a[1])%n;
	for(i=2;i<=n;i++)
		if(i&1)
		{
			if((a[i]+t)%n!=i-1) {printf("No"); return 0;}
		}
		else
		{
			if((a[i]-t+n)%n!=i-1) {printf("No"); return 0;}
		}
	printf("Yes");
	return 0;
}
