#include <bits/stdc++.h>
using namespace std;

int n,m,a[100010],b[100010],ans,sum=0;
bool flag=0;

int main() {
    scanf("%d%d",&n,&m);
    for(int i=1,k;i<=m;i++) {
        scanf("%d",&k);
        a[i]=0;
        flag=0;
        for(int j=1;j<=k;j++) {
            scanf("%d",&b[j]);
            if(b[j]==1) flag=1;
            if(j==1) {
                a[i]++;
                continue;
            }
            if(!flag||b[j]!=b[j-1]+1) {
                a[i]++;
                flag=0;
            }
        }
        ans+=(a[i]-1);
        sum+=a[i];
    }
    ans+=(sum-1);
    printf("%d\n",ans);
    return 0;
}
