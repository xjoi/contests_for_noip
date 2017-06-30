#include<cstdio>
#include<cstring>
#define N 100010
using namespace std;
int n,c,a[N],tmp[N],x,y,ans[N],cnt=0;
int main()
{
	int i;
	scanf("%d %d",&n,&c);
	for(i=1;i<=n;i++) {scanf("%d",&a[i]); tmp[i]=a[i]-a[i-1];}
	for(i=1;i<=n;i++)
	{
		if(tmp[i]>c) cnt=1;
		else cnt++;
	}
	printf("%d",cnt);
	return 0;
}
