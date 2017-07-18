#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
int n,m,num=0;
char c[1000010];
int a[10];
int main()
{
	scanf("%s",c);
	int len=strlen(c);
	for (int i=0;i<len;++i)
	{
		if (c[i]=='0') a[0]++;
	    else if (c[i]=='1'&&a[1]==0) a[1]++;
	    else if (c[i]=='6'&&a[6]==0) a[6]++;
	    else if (c[i]=='8'&&a[8]==0) a[8]++;
	    else if (c[i]=='9'&&a[9]==0) a[9]++;
	    else
	    {
	    	printf("%c",c[i]);
	    	num=(num*10+c[i]-'0')%7;
	    }
    }
 	if (num==0) printf("1869");
 	if (num==1) printf("6198");
 	if (num==2) printf("1896");
 	if (num==3) printf("1689");
 	if (num==4) printf("1986");
 	if (num==5) printf("1968");
 	if (num==6) printf("1698");
 	while (a[0]--)
	{
		printf("0");
	}
	printf("\n");
	return 0;
}
