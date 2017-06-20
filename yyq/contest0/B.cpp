#include<bits/stdc++.h>
using namespace std;
const int maxn=100+10;
int n;
int tot1,tot2;
int a[maxn];
int b[maxn];
bool cmp(int a1,int a2)
{
    return a1>a2;
}
int suma[maxn],sumb[maxn]; 
int main()
{
    scanf("%d",&n);
    int x,y;
    tot1=tot2=0;
    for(int i=0;i<n;i++)
    {
        scanf("%d%d",&x,&y); 
        if(x==1)
			a[tot1++]=y;
        if(x==2)
			b[tot2++]=y;
    }
    sort(a,a+tot1,cmp);
    sort(b,b+tot2,cmp);
    suma[0]=0;
    sumb[0]=0;
    for(int i=1;i<=tot1;i++)
		suma[i]=a[i-1]+suma[i-1];
    for(int i=1;i<=tot2;i++)
		sumb[i]=b[i-1]+sumb[i-1];
    int ans=100000;
	for(int i=0;i<=tot1;i++)
		for(int j=0;j<=tot2;j++)
		{
		    int thick=i+j*2;
		    int width=suma[tot1]-suma[i]+sumb[tot2]-sumb[j];
		    if(thick>=width&&ans>thick)
				ans=thick;
		}
	printf("%d\n",ans);
    return 0;
}
