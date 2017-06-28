#include<cstdio>
#include<cstring>
#include<queue>
#define N 10010
#define pii pair<int,int>
#define mp make_pair
#define F first
#define S second
using namespace std;
int dx[]={0,1,-1,0,0},dy[]={0,0,0,1,-1};
int dis[N],n,m,k;
bool used[N];
pii a[N];
inline int abs(int a) {return a>0?a:-a;}
inline int min(int a,int b) {return a<b?a:b;}
int main()
{
	int i,j,x,y,ans=0; bool flag=0;
	scanf("%d %d %d",&n,&m,&k);
	for(i=1;i<=k;i++) {scanf("%d %d",&x,&y); a[i]=mp(x,y);if(x==n&&y==m) {flag=1;ans=i;}} if(!flag) a[++k]=mp(n,m),ans=k;
	memset(dis,63,sizeof(dis));int p=1,minn=dis[0]; dis[1]=0;
	for(i=1;i<=k;i++)
	{
		minn=dis[0]; used[p]=1;
		for(j=1;j<=k;j++)
			if( (!used[j]) && (abs(a[p].F-a[j].F)<=2 || abs(a[p].S-a[j].S)<=2) )
			{
				if((abs(a[p].F-a[j].F)>=2 && abs(a[p].S-a[j].S)>=2) &&j==ans&& !flag) continue;
				if(j==ans&& !flag) {dis[j]=min(dis[j],dis[p]+1); continue;}
				for(int ii=1;ii<=4;ii++) if(a[p].F+dx[ii]==a[j].F && a[p].S+dy[ii]==a[j].S) {dis[j]=dis[p]; continue;}
				dis[j]=min(dis[j],dis[p]+1);
			}
		//for(j=1;j<=)
		for(j=1;j<=k;j++) if(minn>dis[j] && !used[j]) {p=j; minn=dis[j];}
		//printf("?%d?",p);
	}
//	for(i=1;i<=k;i++) printf("%d ",dis[i]);
	if(dis[ans]>=dis[0]) {puts("-1"); return 0;}
//	dis[ans]+=(!flag)?1:0; 
	printf("%d",dis[ans]);
	return 0;
}
