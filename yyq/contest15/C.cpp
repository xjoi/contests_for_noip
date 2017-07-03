#include<bits/stdc++.h>
using namespace std;
const int maxn=7005;
int n,m;
int dp[maxn][2];
int sta[2][maxn];
int k[2];
bool vis[maxn][2];
int deg[maxn][2];
struct point{
    int p,turn,ans;
};
queue<point> que;
void bfs()
{
    while(!que.empty())
	{
        point cnt=que.front();
		que.pop();
        vis[cnt.p][cnt.turn]=1;
        int turn=!cnt.turn;
        if(cnt.ans==2)
		{
            for(int i=0;i<k[turn];i++)
			{
                int nex=(cnt.p+n-sta[turn][i])%n;
                if(!vis[nex][turn])
				{
					dp[nex][turn]=1;
					que.push((point){nex,turn,1});
				}
            }
        }
        else
		{
            for(int i=0;i<k[turn];i++)
			{
                int nex=(cnt.p+n-sta[turn][i])%n;
                deg[nex][turn]--;
                if (deg[nex][turn]==0&&!vis[nex][turn])
				{
                    dp[nex][turn]=2;
                    que.push((point){nex,turn,2});
                }
            }
        }
    }
}
int main()
{
    scanf("%d",&n);
    scanf("%d",&k[0]);
    for(int i=0;i<k[0];i++)
        scanf("%d",&sta[0][i]);
    scanf("%d",&k[1]);
    for(int i=0;i<k[1];i++)
        scanf("%d",&sta[1][i]);
    for(int i=0;i<n;i++)
	{
        deg[i][0]=k[0];
        deg[i][1]=k[1];
    }
    dp[0][0]=dp[0][1]=2;
    vis[0][0]=vis[0][1]=1;
    que.push((point){0,0,2});
    que.push((point){0,1,2});
    bfs();
    for(int k=0;k<=1;k++)
	{
	    for(int i=1;i<n;i++)
		{
	        if(!vis[i][k])
				printf("Loop ");
	        else if(dp[i][k]==1)
				printf("Win "); 
	        else
				printf("Lose ");
	    }
	    printf("\n");
    }
    return 0;
}
