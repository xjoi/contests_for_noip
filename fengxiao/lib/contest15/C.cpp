#include<cstdio>
#include<cstring>
#define N 7010
using namespace std;
int n,l[2],v[7010][2];
int f[7010][2],cnt[7010][2];
void dfs(int u,int t)
{
	int i,j;
	if (f[u][t]) return;
	f[u][t]=2;
	if(!u) return;
	for(i=1;i<=l[!t];i++) 
	{
		cnt[(u-v[i][!t]+n)%n][!t]++;
		if (cnt[(u-v[i][!t]+n)%n][!t]==l[!t])
	    {
	    	f[(u-v[i][!t]+n)%n][!t]=1;
	    	for(j=1;j<=l[t];j++) dfs( (u-v[i][!t]+n-v[j][t]+n)%n,t );
		}
	}
}
int main()
{
	int i,j;
	scanf("%d",&n);
	scanf("%d",&l[0]); for(i=1;i<=l[0];i++) scanf("%d",&v[i][0]);
	scanf("%d",&l[1]); for(i=1;i<=l[1];i++) scanf("%d",&v[i][1]);
	for(j=0;j<2;j++) 
			for(i=1;i<=l[j];i++) dfs(n-v[i][j],j);
	for(j=0;j<2;j++)
	{
		for(i=1;i<n;i++) 
		{
			if(f[i][j]==2) printf("Win ");
			else if(f[i][j]==1) printf("Lose ");
			else printf("Loop ");
		}
		puts("");
	}
 } 
