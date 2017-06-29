#include<cstdio>
#include<cstring>
#define N 2010
#define INF 1e9
using namespace std;
int dis[N],map[N][N],n,ans;
char a[N][20];
bool used[N];
int main()
{
	int i,j,k;
	while(scanf("%d",&n)==1 && n)
	{
		memset(map,0,sizeof(map)); memset(used,0,sizeof(used)); ans=0;
		for(i=1;i<=n;i++) scanf("%s",a[i]);
		for(i=1;i<=n;i++)
			for(j=1;j<=n;j++)
				for(k=0;k<7;k++)
					if(a[i][k]!=a[j][k]) map[i][j]++;
		for(i=1;i<=n;i++) dis[i]=map[1][i];
		for(i=1;i<=n;i++)
		{
			int minn=INF,pos=0;
			for(j=1;j<=n;j++) if(dis[j]<minn && !used[j]) {pos=j; minn=dis[j];}
			used[pos]=1; ans+=minn;
			for(j=1;j<=n;j++) if(dis[j]>map[pos][j]&&!used[j]) dis[j]=map[pos][j];
		}
		printf("The highest possible quality is 1/%d.\n",ans);
	}
	
	return 0;
}
