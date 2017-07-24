#include<bits/stdc++.h>
#define N 100010
#define int long long
using namespace std;
int a[N],n,p; 
inline int dist(int a,int b) {return (b+n-a)%n;}
main()
{
	int i,j;
	scanf("%I64d %I64d",&n,&p); p--;
	for(i=0;i<n;i++) scanf("%I64d",&a[i]);
	int minn=1000000000000000,pos;
	for(i=p;i!=(p+1)%n;i=(i-1+n)%n) if(minn>a[i]) {minn=a[i]; pos=i;} if(minn>a[(p+1)%n]) pos=(p+1)%n;
	int tmp=dist(pos,p)+a[pos]*n,t=a[pos];
	if(pos!=p) for(j=(pos+1)%n;j!=p;j=(j+1)%n) a[j]--; a[p]--; 
	for(j=0;j<n;j++) a[j]-=t; a[pos]=tmp;
	for(j=0;j<n;j++) printf("%I64d ",a[j]);
	return 0;
}
