#include<cstdio>//luan gao
#include<cstring>
#include<algorithm>
using namespace std;
int a,b,r;
int main()
{
	scanf("%d %d %d",&a,&b,&r);
	a/=2*r; b/=2*r;
	int ans=a*b;
	if(ans&1) {puts("First"); return 0;}
	ans=max(0,(a-1))*b;
	if(ans&1) {puts("First"); return 0;}
	ans=a*max(0,(b-1));
	if(ans&1) {puts("First"); return 0;}
	ans=max(0,(a-1))*max(0,(b-1));
	if(ans&1) {puts("First"); return 0;}
	puts("Second");
	return 0;
}
int main()
{
    scanf("%d %d %d",&a,&b,&r);
    a/=2*r;b/=2*r;
    if(a!=0 || b!=0) puts("First"); else puts("Second");
    return 0;
}
