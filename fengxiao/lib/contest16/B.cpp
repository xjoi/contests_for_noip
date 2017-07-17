#include<cstdio>
#include<cstring>
#include<iostream>
#define ll unsigned long long
#define N 10000010
using namespace std;
int n;
char tmp[N];
int num=0;
char pr[N]; int sz=0;
int main()
{
	int i,j; bool flag=0;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%s",tmp);
		int lt=strlen(tmp);
		if(lt==1 && tmp[0]=='0') {puts("0"); return 0;}
		for(j=lt-1;j>=0;j--)
			if(tmp[j]=='0')
				num++;
			else break;
		if(tmp[j]!='1' || j!=0) {for(int k=0;k<=j;k++) pr[k]=tmp[k]; sz=j; flag=1;}
	}
	if(!flag) printf("1"); else for(i=0;i<=sz;i++) printf("%c",pr[i]);
	for(i=1;i<=num;i++) printf("0");
}
