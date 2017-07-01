#include<cstdio>
#include<cstring>
#define N 1010
#define INF 1e9
using namespace std;
int dis[N],map[N][N],n,ans;
bool used[N];
int main()
{
	int i,j,x,y,q;
	while(scanf("%d",&n)==1)
	{
		memset(used,0,sizeof(used)); ans=0;
		for(i=1;i<=n;i++)
			for(j=1;j<=n;j++)
				scanf("%d",&map[i][j]);
		scanf("%d",&q);
		for(i=1;i<=q;i++) {scanf("%d %d",&x,&y); map[x][y]=map[y][x]=0;}
		for(i=1;i<=n;i++) dis[i]=map[1][i];
		for(i=1;i<=n;i++)
		{
			int minn=INF,pos=0;
			for(j=1;j<=n;j++) if(dis[j]<minn && !used[j]) {pos=j; minn=dis[j];}
			used[pos]=1; ans+=minn;
			for(j=1;j<=n;j++) if(dis[j]>map[pos][j]&&!used[j]) dis[j]=map[pos][j];
		}
		printf("%d\n",ans);
	}
	
	return 0;
}
