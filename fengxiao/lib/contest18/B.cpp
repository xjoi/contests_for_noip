#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int a[110],b[110],ca=1,cb=1,n,m;
inline void swap(int &a,int &b) {int t=a;a=b;b=t;}
int gcd(int a,int b) {if(a<b) swap(a,b);return b==0 ? a : gcd(b,a%b);}
int main()
{
	int i;
	scanf("%d %d",&n,&m);
	for(i=1;i<=n+1;i++) scanf("%d",&a[i]);
	for(i=1;i<=m+1;i++) scanf("%d",&b[i]);
	while(a[ca]==0) ca++; while(b[cb]==0) cb++;
	if(n-ca+1<m-cb+1) {puts("0/1"); return 0;}
	if(n-ca+1>m-cb+1)
	{
		if(a[ca] * b[cb]>0) puts("Infinity");
		else puts("-Infinity");
		return 0;
	}
	int t=gcd(abs(a[ca]),abs(b[cb])); a[ca]/=t; b[cb]/=t;
	if(a[ca]*b[cb]>0) printf("%d/%d",abs(a[ca]),abs(b[cb]));
	else printf("-%d/%d",abs(a[ca]),abs(b[cb]));
	return 0;
}
