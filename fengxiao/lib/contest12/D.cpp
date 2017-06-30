#include<cstdio>
#include<iostream>
#define int long long
int a[30],n,k,ans;
inline int max(int a,int b) {return a>b?a:b;}
main()
{
	scanf("%I64d %I64d",&n,&k);
	for(int i=1;i<=k;i++) scanf("%I64d",&a[i]);
	for(int i=2;i<=k;i++) a[1]=max(0,a[1]+a[i]-n);
	printf("%I64d",a[1]);
	
	return 0;
}
