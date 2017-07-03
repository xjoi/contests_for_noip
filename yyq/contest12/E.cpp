#include<bits/stdc++.h>
using namespace std;
#define Len 100005
const int INF=0x3f3f3f3f;
struct node
{
    int x,y;
} s[Len][2];
int n;
int a[Len];
int dp[Len][2];
vector<int> ans[2];
void upp(int x,int y,int i,int j,int m)
{
    if(dp[x][y]>m)
    {
        dp[x][y]=m;
        s[x][y].x=i;
        s[x][y].y=j;
    }
}
void downn(int x,int y,int i,int j,int m)
{
    if(dp[x][y]<m)
    {
        dp[x][y]=m;
        s[x][y].x=i;
        s[x][y].y=j;
    }
}
int set1()
{
    dp[1][0]=dp[1][1]=-1;
    for(int i=1;i<=n-1;i++)
    {
        dp[i+1][0]=dp[i+1][1]=INF;
        for(int j=0;j<=1;j++)
        {
            if(dp[i][j]<INF)
            {
                if(a[i-1]<a[i])
                    upp(i+1,j,i,j,dp[i][j]);
                if(dp[i][j]<a[i])
                    upp(i+1,j^1,i,j,a[i-1]);
            }
        }
    }
    return dp[n][0]+dp[n][1]<INF;
}
int set2()
{
    dp[1][0]=dp[1][1]=INF;
    for(int i=1;i<=n-1;i++)
    {
        dp[i+1][0]=dp[i+1][1]=-1;
        for(int j=0;j<=1;j++)
        {
            if(dp[i][j]>=0)
            {
                if(a[i-1]>a[i])
                    downn(i+1,j,i,j,dp[i][j]);
                if(dp[i][j]>a[i])
                    downn(i+1,j^1,i,j,a[i-1]);
            }
        }
    }
    return dp[n][0]+dp[n][1]>0;
}
int set3()
{
    dp[1][0]=INF;
    dp[1][1]=-1;
    for(int i=1;i<=n-1;i++)
    {
        dp[i+1][0]=-1;
        dp[i+1][1]=INF;
        if(dp[i][0]>0)
        {
            if(a[i-1]<a[i])
                downn(i+1,0,i,0,dp[i][0]);
            if(dp[i][0]>a[i])
                upp(i+1,1,i,0,a[i-1]);
        }
        if(dp[i][1]<INF)
        {
            if(a[i-1]>a[i])
                upp(i+1,1,i,1,dp[i][1]);
            if(dp[i][1]<a[i])
                downn(i+1,0,i,1,a[i-1]);
        }
    }
    return dp[n][0]>0||dp[n][1]<INF;
}
void solve(int x,int y)
{
    if(x<=0)
		return;
    ans[y].push_back(a[x-1]);
    solve(s[x][y].x,s[x][y].y);
}
int main()
{
    scanf("%d",&n);
    memset(s,0,sizeof s);
    for(int i=0;i<=n-1;i++)
    	scanf("%d",&a[i]);
    if(set1()||set2()||set3())
    {
        ans[0].clear();
        ans[1].clear();
        if(dp[n][0]>=1&&dp[n][0]<=n)
			solve(n,0);
        else
			solve(n,1);
        for(int i=0;i<=1;i++)
        {
            if(ans[i].empty())
            {
                ans[i].push_back(ans[i^1].back());
                ans[i^1].pop_back();
            }
        }
        printf("%d %d\n",ans[0].size(),ans[1].size());
        for(int i=0;i<=1;i++)
        {
            for(int j=ans[i].size()-1;j>=0;j--)
            {
                printf("%d",ans[i][j]);
                if(j)
                    printf(" ");
            }
            printf("\n");
        }
    }
    else
        puts("Fail");
    return 0;
}
