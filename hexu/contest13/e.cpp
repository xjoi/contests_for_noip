#include <cstdio>
#include <algorithm>
const int d[4][2] = {{1,0},{-1,0},{0,1},{0,-1}},N = 30;//D数组为方向增量 
int n,m,T,B,f[N][N][1 << 8],ans,sum[1 << 8],q[(1 << 8)*N*N][3],sx,sy,st[N][N],v[N],bit[10];
char map[N][N];
bool vis[N][N][1 << 8];
void BFS()
{
	int h = 1,t = 0;
	vis[sx][sy][0] = true;   q[++t][1] = sx; q[t][2] = sy;
	for (; h <= t; ) {
		const int x = q[h][1],y = q[h][2],sta = q[h][0];//Q[H][0]为此时搜索的宝石获得状态，X和Y为此时坐标 
		//printf("%d: \n",h);
		++h;
		for (int i = 0; i < 4; ++i) //四个方向 
		{
			const int nx = x + d[i][0],ny = y + d[i][1];//NY和NX为下一步走的位置 
			//printf("%d %d\n",nx,ny);
			if (nx < 0 || nx == n || ny < 0 || ny == m || map[nx][ny] != '.') continue;//判断这组状态是否合法 
			int nst = sta;
			if (i == 1) nst ^= st[nx][ny];         
			else if (i == 0) nst ^= st[x][y]; //更新状态 ，很明显，引出的射线是与X轴平行的，只记录Y左边的点 
			if (vis[nx][ny][nst]) continue;//如果这组状态已经搜索过就不做了 
			vis[nx][ny][nst] = true;//标记这组状态已搜索过 
			//printf("%d %d %d\n",nx,ny,nst);
			q[++t][0] = nst;
			q[t][1] = nx; q[t][2] = ny;//将这组状态加入队列 
			f[nx][ny][q[t][0]] = f[x][y][sta] + 1;//计算这组状态的耗费 
		}
	}
}
int main()
{
	scanf("%d%d\n",&n,&m);
	for (int i = 0; i <= 8; ++i) bit[i] = 1 << i;
	for (int i = 0; i < n; ++i) 
	{
		for (int j = 0; j < m; ++j) 
		{
			scanf("%c",&map[i][j]);
			if (map[i][j] == 'S') sx = i,sy = j,map[i][j] = '.';
			else if ('0' < map[i][j] && map[i][j] < '9')//如果这个格子是宝石，那么就更新ST 
			 {
				++T;
				for (int k = j + 1; k < m; ++k)
					st[i][k] |= bit[map[i][j] - '1']; //st 表存 I,K正左边有的宝石状态 
			}
		}
		scanf("\n");
	}
	for (int i = 0; i < T; ++i) scanf("%d",v + i);//V[I]表示第I个宝石的价值 
	for (int i = 0; i < bit[T]; ++i)
		for (int j = 0; j < T; ++j)                         
			if (i & bit[j]) sum[i] += v[j]; 	//计算该状态的宝石价值 
	B = T;
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j)
			if (map[i][j] == 'B') //接着处理炸弹的情况 
			{          
				for (int k = j + 1; k < m; ++k) st[i][k] |= bit[B]; 
				++B;
			}
	BFS();
	for (int i = 0; i < bit[T]; ++i)
		if (vis[sx][sy][i]) ans = std::max(ans,sum[i] - f[sx][sy][i]);
	printf("%d\n",ans);
}
