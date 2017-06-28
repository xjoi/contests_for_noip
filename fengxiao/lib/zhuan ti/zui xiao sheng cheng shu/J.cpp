#include <stdio.h>
#include <iostream>
#include <string.h>
#define INF 0xfffffff
using namespace std;
 
char str[55][55];
int Map[55][55];
int dis[55];
int dist[105][105];
int edge[105][105];
int num, n, m, p    ;
 
int Move[4][2] = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};
 
int min(int a, int b)
{
    return a > b ? b : a;
}
 
void BFS(int i, int j)
{
    int head = 0, tail = 0;
    int q_x[2550], q_y[2550];
    bool vis[55][55];
    memset(vis, false, sizeof(vis));
    memset(dist, 0, sizeof(dist));
    vis[i][j] = true;
    q_x[tail] = i;
    q_y[tail++] = j;
    while(head < tail)
    {
        int x = q_x[head];
        int y = q_y[head++];
        if(Map[x][y])
        {
            edge[Map[i][j]][Map[x][y]] = dist[x][y];
        }
        for(int t = 0; t < 4; t++)
        {
            int dx = x+Move[t][0];
            int dy = y+Move[t][1];
            if(dx >= 1 && dx <= m && dy >= 1 && dy <= n)
            {
                if(!vis[dx][dy] && str[dx][dy] != '#')
                {
                    q_x[tail] = dx;
                    q_y[tail++] = dy;
                    vis[dx][dy] = true;
                    dist[dx][dy] = dist[x][y]+1;
                }
            }
        }
    }
}
 
 
int Prim()
{
    int Ans;
    int Min_ele, Min_node;
    for(int i = 1; i <= num; i++)
    {
        dis[i] = INF;
    }
    Ans = 0;
    int r = 1;
    for(int i = 1; i <= num-1; i++)
    {
        Min_ele = INF;
        dis[r] = -1;
        for(int j = 1; j <= num; j++)
        {
            if(dis[j] >= 0)
            {
                dis[j] = min(dis[j], edge[r][j]);
                if(dis[j] < Min_ele)
                {
                    Min_ele = dis[j];
                    Min_node = j;
                }
            }
        }
        r = Min_node;
        Ans += Min_ele;
    }
    return Ans;
}
 
void Solve()
{
    int i, j;
    cin >> p;
    while(p--)
    {
        memset(Map, 0, sizeof(Map));
        num = 0;
        cin >> n >> m;
        char s[100];
        gets(s);///这里太坑了
        for(int i = 1; i <= m; i++)
        {
            gets(str[i]);
            for(int j = 0; j < n; j++)
            {
                if(str[i][j] == 'A' || str[i][j] == 'S')
                {
                    Map[i][j] = ++num;
                }
            }
        }
        for(int i = 1; i <= m; i++)
        {
            for(int j = 1; j <= n; j++)
            {
                if(Map[i][j])
                {
                    BFS(i, j);
                }
            }
        }
        printf("%d\n", Prim());
    }
}
 
int main()
{
    Solve();
 
    return 0;
}
