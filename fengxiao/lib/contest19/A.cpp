#include<bits/stdc++.h>
using namespace std;
int b,n;
int main()
{
	int a;bool flag=0;
	scanf("%d %d %d",&a,&b,&n);
	for(int i=0;i<=9;i++)
		if((a*10+i)%b==0)
		{
			a=a*10+i;
			//printf("%d",a);
			flag=1; break;
		}
	if(!flag) {puts("-1"); return 0;}
	printf("%d",a);
	for(int i=1;i<n;i++) printf("0");
		
	return 0;
}
