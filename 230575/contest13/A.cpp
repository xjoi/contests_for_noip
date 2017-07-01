#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
char c[1000010];
long long ans1=0,ans2=0,mid;
int a[1000010]={0},b[1000010]={0};
bool flag=0;
int main()
{
	scanf("%s",c);
	for (int i=0;i<strlen(c);++i)
	{
		if (c[i]=='^')
		{
			mid=i;
			break;
		}
    }
    for (int i=0;i<strlen(c);++i)
    {
    	if (i<mid&&c[i]!='=') ans1+=(mid-i)*(c[i]-'0');
    	if (i>mid&&c[i]!='=') ans2+=(i-mid)*(c[i]-'0');
	}
	if (ans1==ans2)
	{
		printf("balance\n");
	}
	if (ans1<ans2)
	{
		printf("right\n");
	}
	if (ans1>ans2)
	{
		printf("left\n");
	}
	return 0;
}
