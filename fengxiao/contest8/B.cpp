#include<cstdio>
#include<cstring>
using namespace std;
int n,a[310];
int main()
{
	int i;
	scanf("%d",&n);
	for(i=1;i<=n;i++) scanf("%d",&a[i]);
	for(i=1;i<=n;i++)
	{
		if(i!=n)
		{
			if(a[i]!=0) {printf("P");a[i]--;}
			while(a[i]!=0) {printf("RLP"),a[i]--;}
			printf("R");
		}
		else
		{
			if(a[i]!=0) {printf("P");a[i]--;}
			while(a[i]!=0) {printf("LRP"),a[i]--;}
		}
	}
	return 0;
}
