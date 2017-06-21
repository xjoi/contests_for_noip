#include<cstdio>
#include<iostream>
using namespace std;
int n,x;
int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
	{
		scanf("%d",&x);
		while (x>0)
		{
			if (i!=n) printf("RLP");
			else printf("LRP");
			x--;
		}
		if (i!=n) printf("R");
	}
}
