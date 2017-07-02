#include<bits/stdc++.h>
using namespace std;
const int maxn=5005;
int sum[maxn][maxn];
int a[maxn][maxn];
int n,m,k;
int main()
{
    memset(a,0,sizeof(a));
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
    {
		char s[maxn];
		scanf("%s",s);
    	for(int j=1;j<=m;j++)
        	a[i][j]=s[j-1]=='1';
    	memset(sum[i],0,sizeof(sum[i]));
    }
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            a[i][j]=a[i][j]?(a[i][j-1]+1):0;
    for(int i=1;i<=n;i++)
    {
        for(int j=m;j>=1;j--)
			if(a[i][j])
	        {
	            k=j-a[i][j]+1;
	            sum[k][j]++;
	            j=k;
	        }
    }
    for(int i=1;i<=m;i++)
        for(int j=m;j>=i;j--)
            sum[i][j]+=sum[i][j+1];
    for(int j=1;j<=m;j++)
        for(int i=1;i<=j;i++)
            sum[i][j]+=sum[i-1][j];
    int ans=0;
    for(int i=1;i<=m;i++)
        for(int j=i;j<=m;j++)
            ans=max(ans,sum[i][j]*(j-i+1));
    printf("%d",ans);
    return 0;
}
