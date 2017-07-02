#include<bits/stdc++.h>
using namespace std;
int n,m,x,y,z,a[1000],s=0;
int main ()
{
    scanf("%d%d",&n,&m);
    memset(a,0,sizeof(a));
    if(m==0)
    {
        printf("0\n");
        return 0;
    }
    for(int i=0;i<m;i++)
    {
        scanf("%d%d%d",&x,&y,&z);
        a[x]-=z;
        a[y]+=z;
    }
    for(int i=1;i<=n;i++)
        if(a[i]>0)
            s+=a[i];
    printf("%d\n",s);
    return 0;
}
