#include<cstdio>
#include<iostream>
#define xxx 1010
using namespace std;
int n,a[xxx];

bool pd()
{
	for (int i=1;i<=n;i++)
		if (a[i]!=i-1)
			return 0;
	return 1;
}

int cg(int x)
{
	if (x%2) return 1;
	return n-1;
}

int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	int step=0;
	while (step<2000)
	{
		if (pd())
		{
			printf("Yes");
			return 0;
		}
		for (int i=1;i<=n;i++)
			a[i]=(a[i]+cg(i))%n;
		step++;
	}
	printf("No");
}
