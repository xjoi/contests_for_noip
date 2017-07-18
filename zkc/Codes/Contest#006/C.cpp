#include <bits/stdc++.h>
using namespace std;

int n,m,b,md,a[510],dp[510][510];

int main() {
    scanf("%d%d%d%d",&n,&m,&b,&md);
    for(int i=1;i<=n;i++) {
        scanf("%d",&a[i]);
    }
    memset(dp,0,sizeof dp);
    for(int i=0;i<=b;i++) dp[0][i]=1;
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=m;j++) {
            for(int k=a[i];k<=b;k++) {
                dp[j][k]=(dp[j][k]+dp[j-1][k-a[i]])%md;
            }
        }
    }
    cout<<dp[m][b]<<endl;
    return 0;
}
