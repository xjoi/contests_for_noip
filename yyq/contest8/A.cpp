#include<bits/stdc++.h>
using namespace std;
int a,b,ans=0;
int main()
{
	scanf("%d%d",&a,&b);
	ans=a;
	while(a>=b)
	{
		ans=ans+(a/b);
		a=a%b+(a/b);
	}
	printf("%d\n",ans);
	return 0;
}
