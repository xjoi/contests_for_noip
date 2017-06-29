#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;  
char g[5005][5005];  
int h[5005][5005],n,m,ans=0;  
bool cmp(int a,int b)  
{  
    return a>b;  
}  
  int main()  
{  
    scanf("%d%d",&n,&m);  
    for(int i=0;i<n;i++)
	scanf("%s",g[i]);  
    for(int i=1;i<=n;i++)  
    {  
        for(int j=1;j<=m;j++)  
        {  
            if(g[i-1][j-1]=='1') h[j][i]=h[j-1][i]+1;  
        }  
    }  
    for(int i=1;i<=m;i++)  
    {  
        sort(h[i]+1,h[i]+n+1,cmp);  
        for(int j=1;j<=n;j++)  
        {  
            if(h[i][j]==0) break;  
            ans=max(ans,h[i][j]*j);  
        }  
    }  
    printf("%d\n",ans);  
    return 0;  
}
