#include<bits/stdc++.h>
using namespace std;
const int maxn=25;
struct node{
	int x,y,st;
	node(int a=0,int b=0,int c=0):x(a),y(b),st(c){}
}S;
char mp[maxn][maxn];
int V[8][2],cnt;
int number[8],value[8];
int f[maxn][maxn][1<<8],step[4][2]={1,0,-1,0,0,1,0,-1};
int n,m;
bool valid(int x,int y)
{
	return 0<=x&&x<n&&0<=y&&y<m&&(mp[x][y]=='.'||mp[x][y]=='S');
}
int get(int x,int y,int nowy,int ST)
{
	for(int i=0;i<cnt;i++)
		if(x>V[i][0]&&((y==V[i][1]&&nowy==V[i][1]+1)||(nowy==V[i][1]&&y==V[i][1]+1)))
			ST^=1<<i;
	return ST;
}
int BFS()
{
	memset(f,-1,sizeof(f));
	queue<node>q;
	q.push(S);
	f[S.x][S.y][0]=0;
	while(!q.empty())
	{
		node u=q.front();
		q.pop();
		for(int i=0;i<4;i++)
		{
			node v=u;
			v.x+=step[i][0];
			v.y+=step[i][1];
			if(!valid(v.x,v.y))
				continue;
			v.st=get(v.x,v.y,u.y,u.st);
			if(f[v.x][v.y][v.st]!=-1)
				continue;
			f[v.x][v.y][v.st]=f[u.x][u.y][u.st]+1;
			q.push(v);
		}
	}
	int ans=0;
	for(int i=0;i<(1<<cnt);i++)
		if(f[S.x][S.y][i]!=-1)
		{
			bool bomb=false;
			int sum=0;
			for(int j=0;j<cnt;j++)
				if(i&(1<<j))
				{
					if(number[j]==-1)
					{
						bomb=true;
						break;
					}
					sum+=value[number[j]];
				}
			if(bomb)
				continue;
			ans=max(ans,sum-f[S.x][S.y][i]);
		}
	return ans;
}
void init()
{
	cnt=0;
	int bz=0;
	memset(number,-1,sizeof(number));
	for(int i=0;i<n;i++)
	{
		scanf("%s",mp[i]);
		for(int j=0;j<m;j++)
			if(mp[i][j]=='B')
			{
				V[cnt][0]=i;
				V[cnt++][1]=j;
			}
			else if('1'<=mp[i][j]&&mp[i][j]<='8')
			{
				V[cnt][0]=i;
				V[cnt][1]=j;
				number[cnt++]=mp[i][j]-'1'; bz++;
			}
			else if(mp[i][j]=='S')
			{
				S.x=i;
				S.y=j;
				S.st=0;
			}
	}
	for(int i=0;i<bz;i++)
		scanf("%d",&value[i]);
}
int main()
{
	scanf("%d %d",&n,&m);
	init();
	printf("%d\n", BFS());
	return 0;
} 
