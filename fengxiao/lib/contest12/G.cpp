#include<cstdio>
#include<cstring>
using namespace std;
int map[40][4][4],ord[11],G[15][15];//shun
bool used[9],flag=0;
inline void rotate(int x)
{
	for(int i=0;i<4;i++)
		for(int j=0;j<4;j++)
		{
			map[x+1][j][3-i]=map[x][i][j];
			map[x+2][3-i][3-j]=map[x][i][j];
			map[x+3][3-j][i]=map[x][i][j];
		}
}
inline bool cmp1(int x,int y) //  |
{
	for(int i=0;i<4;i++) if(map[x][i][3]!=map[y][i][0]) return false;
	return true;
}
inline bool cmp2(int x,int y)// --
{
	for(int i=0;i<4;i++) if(map[x][3][i]!=map[y][0][i]) return false;
	return true;
}
bool judge(int p,int x)
{
	if(p%3!=0 && !cmp1(ord[p-1],x)) return false;
	if(p>=3 && !cmp2(ord[p-3],x)) return false;
	return true;
}
void print()
{
	int i,j;
	for(i=0;i<12;i++)
		for(j=0;j<12;j++)
			G[i][j]=map[ord[i/4*3+j/4]][i-i/4*4][j-j/4*4];
	for(i=0;i<12;i++)
	{
		for(j=0;j<12;j++)
			if(i!=4 && i!=8 && j!=4 && j!=8)
				printf("%d ",G[i][j]);
		if(i!=4 && i!=8) printf("\n");
	}
}
void dfs(int step)
{
	if(step==9) {print(); flag=1; return;}
	for(int i=0;i<9;i++)
		if(!used[i])
		{
			for(int j=0;j<4;j++)
				if(judge(step,i*4+j))
				{
					used[i]=1; ord[step]=i*4+j;
					dfs(step+1); if(flag) return;
					used[i]=0; ord[step]=0;
				}
		}
}
int main()
{
	int i,j,k;
	for(i=0;i<36;i+=4)
	{
		for(j=0;j<4;j++)
			for(k=0;k<4;k++)
				scanf("%d",&map[i][j][k]);
		rotate(i);
	}
	dfs(0);
	return 0;
}
