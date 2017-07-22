#include<cstdio>
#include<cstring>
#define N 1510
using namespace std;
int dx[]={0,1,-1,0,0},dy[]={0,0,0,1,-1};
int n,m; char map[N][N];
struct P {int x,y;} f[N][N];
bool dfs(int x, int y)
{
    int nx=(x%n+n)%n,ny=(y%m+m)%m;
    if(map[nx][ny]=='#') return false;
    if(f[nx][ny].x!=f[N-1][N-1].x) return f[nx][ny].x!=x||f[nx][ny].y!=y;
    f[nx][ny].x=x,f[nx][ny].y=y;
    for(int i=1;i<=4;i++) if(dfs(x+dx[i],y+dy[i])) return true;
    return false;
}
int main()
{
    scanf("%d %d",&n,&m);
    bool flag=1;
    for(int i=0;i<n;i++) scanf("%s",map[i]);
    memset(f,63,sizeof(f));
    for(int i=0;flag&&i<n;i++)
        for(int j=0;j<m;j++)
            if(map[i][j]=='S')
            {
                if(dfs(i,j)) puts("Yes");
                else puts("No");
                flag=0; break;
        	}
}
