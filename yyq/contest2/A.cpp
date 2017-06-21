#include<bits/stdc++.h>
using namespace std;
char a[19];
int main()
{
	scanf("%s",a);
	for(int i=0;i<strlen(a);i++)
	{
		if('9'-a[i]<a[i]-'0')
			a[i]='9'-a[i]+'0';
	}
	if(a[0]=='0')
		a[0]='9';
	printf("%s\n",a);
	return 0;
}
