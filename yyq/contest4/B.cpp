#include<bits/stdc++.h>
using namespace std;
int n,a[101],b[101];
char u[202];
bool flg=true;
int main()
{
	scanf("%d",&n);
	scanf("%s",&u);
	for(int i=0;i<n;i++)
		a[i]=u[i]-'0';
	for(int i=0;i<n;i++)
		b[i]=u[i+n]-'0';
	sort(a,a+n);
	sort(b,b+n);
	if(a[0]>b[0])
	{
		for(int i=0;i<n;i++)
		{
			if(a[i]<=b[i])
			{
				printf("NO\n");
				flg=false;
				break;
			}
		}
		if(flg)
			printf("YES\n");
	}
	else if(a[0]<b[0])
	{
		for(int i=0;i<n;i++)
		{
			if(a[i]>=b[i])
			{
				printf("NO\n");
				flg=false;
				break;
			}
		}
		if(flg)
			printf("YES\n");
	}
	else
		printf("NO\n");
	return 0;
}
