#include<cstdio>
using namespace std;
int a,b,c,d;
int main()
{
    scanf("%d %d %d %d",&b,&a,&d,&c);
    while(c!=a and a<100000)  a<c?a+=b:c+=d;
    if(a>=100000) puts("-1");
    else printf("%d",a);
    return 0;
}
