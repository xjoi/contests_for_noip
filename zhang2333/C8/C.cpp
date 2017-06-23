#include<cstdio>
#include<iostream>
#include<algorithm>
#define xxx 5200000
using namespace std;
struct node{
	int v,p;
}a[xxx];
int n,b[xxx],low=0;
bool cmp(node x,node y)
{
	return x.v<y.v;
}
int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
	{
		scanf("%d",&a[i].v);;
		a[i].p=i;
	}
	sort(a+1,a+n+1,cmp);
	for (int i=1;i<=n;i++)
	{
		if (a[i].v>low)
			low=a[i].v;
		else
			low++;
		b[a[i].p]=low;
	}
	for (int i=1;i<=n;i++)
		printf("%d ",b[i]);
}
