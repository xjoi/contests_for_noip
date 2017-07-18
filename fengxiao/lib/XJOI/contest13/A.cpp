#include<cstdio>
#include<cstring>
#include<iostream>
#define INF 1e9
#define N 20010
using namespace std;
char tmp[N];
int a[N],b[N],c[N];
int main()
{
    int i;
    scanf("%s",tmp);
    int la=strlen(tmp);
    for(i=0;i<la;i++) a[i+1]=tmp[la-i-1]-'0';
    scanf("%s",tmp);
    int lb=strlen(tmp);
    for(i=0;i<lb;i++) b[i+1]=tmp[lb-i-1]-'0';
    int pos=1;
    while(a[pos]==9) a[pos++]=0; a[pos]++;
    int l=max(la,lb);
    for(i=1;i<=l;i++)
    {
        c[i]+=a[i]+b[i];
        c[i+1]+=c[i]/10;
        c[i]%=10;
    }
    if(c[l+1]!=0) l++;
    for(i=l;i>=1;i--) printf("%d",c[i]);
    return 0;
}
