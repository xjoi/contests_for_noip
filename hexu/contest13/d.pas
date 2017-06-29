#include<stdio.h>
#include<string.h>
#include<iostream>
#include<cmath>
using namespace std;
int dp[5050][5050], d[5050];
int main()
{
    int i, j, k, n, m, l, Max;
    char s[5050];
    while(~scanf("%d%d", &n, &m))
    {
        memset(dp, 0, sizeof(dp));
        for(i = 1; i <= n; i++)
        {
            scanf("%s", s+1);
            l = -1;
            for(j = 1; j <= m; j++)
            {
                if(s[j] == '1' && l == -1) l = j;
                if(s[j] == '0' && l != -1) 
				{
                    dp[l][j-1]++; l = -1;
                }
            }
            if(l != -1) dp[l][m]++;
        }
        memset(d, 0, sizeof(d));
        Max = 0;
        for(i = 1; i <= m; i++)
        {
            l = 0;
            for(j = m; j >= i; j--)
            {
                d[j] += dp[i][j];
                l += d[j];
                Max = Max > ((j - i + 1) * l) ? Max : ((j - i + 1) * l);
            }
        }
        printf("%d\n", Max);
    }
    return 0;
}
