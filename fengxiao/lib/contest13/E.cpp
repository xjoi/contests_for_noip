#include<cstdio>
#include<cstring>
#include<iostream>
#include<queue>
#define N 30
#define pii pair<int,int>
#define mp make_pair
#define F first
#define S second
using namespace std;
int dx[]={1,-1,0,0},dy[]={0,0,1,-1};//up down right left
int n,m,s,rs,ans,P;
int map[N][N],sum[N][N],v[10];
char ch[N][N];
bool used[N][N][4][260];
pii p[9];
struct sta {int x,y,from,v,step;};
inline bool ok(int x,int y) {return x>0 && x<=n && y>0 && y<=m && map[x][y]!=-1;}
inline int get_v(int x) {int sum=0; for(int i=0;i<rs;i++) if(x&(1<<i)) sum+=v[i+1]; return sum;}
void test(int fx,int fy,int x,int y,int tmp,int v,int step)
{
	printf("%d %d %d %d %d %d ",fx,fy,x,y,tmp,step);
	for(int i=0;i<s;i++)
		if((1<<i)&v)
			printf("%d",i+1);
	puts("");
}
void init()
{
	int i,j;
	for(i=rs+1;i<=s;i++) P+=1<<(i-1);
	for(i=1;i<=s;i++) sum[p[i].F][p[i].S]=1<<(i-1);
	for(j=1;j<=m;j++)
		for(i=1;i<=n;i++)
			sum[i][j]+=sum[i-1][j];
}
void bfs(int fx,int fy)
{
	queue<sta> que;
	que.push((sta){fx,fy,-1,0,0});
	while(!que.empty())
	{
		sta p=que.front(); que.pop();
		for(int i=0;i<4;i++)
		{
			int step=p.step+1,v=p.v,x=p.x+dx[i],y=p.y+dy[i];
			if(i==2) v=v^sum[p.x][min(p.y,y)];
			if(i==3) v=v^sum[p.x][min(p.y,y)];
			if(!used[x][y][i^1][v] && ok(x,y) && p.from!=i)
			{
				
				used[x][y][i^1][v]=1;
				que.push((sta){x,y,i^1,v,step});
				if(!(v&P) && x==fx && y==fy)
				{
					//test(p.x,p.y,x,y,i^1,v,step);
					ans=max(ans,get_v(v)-step);
				}
			}
		}
	}
	
}
int main()
{
	int i,j,fx,fy;
	scanf("%d %d",&n,&m);
	for(i=1;i<=n;i++)
	{
		scanf("%s",ch[i]+1);
		for(j=1;j<=m;j++)
		{
			if(ch[i][j]=='#' || ch[i][j]=='B' || ( ch[i][j]>='0' && ch[i][j]<='9')) map[i][j]=-1;
			if(ch[i][j]>='0' && ch[i][j]<='9') {p[ch[i][j]-'0']=mp(i,j); rs=max(rs,ch[i][j]-'0');}
			if(ch[i][j]=='S') fx=i,fy=j;
		}
	}
	s=rs;
	for(i=1;i<=n;i++)
		for(j=1;j<=m;j++)
			if(ch[i][j]=='B')
				p[++s]=mp(i,j);
	for(i=1;i<=rs;i++) scanf("%d",&v[i]);
	init();
	bfs(fx,fy);
	printf("%d\n",ans);
	return 0;
}
