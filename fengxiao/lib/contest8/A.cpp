#include<cstdio>
#include<cstring>
using namespace std;
int a,b,ret,ans;
int main()
{
	int i;
	scanf("%d %d",&a,&b);
	while(a!=0)
	{
		ans+=a;
		int tmp=(a+ret)%b;
		a=(a+ret)/b;
		ret=tmp;
	}
	printf("%d",ans);
	return 0;
}
