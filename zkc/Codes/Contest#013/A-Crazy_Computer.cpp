#include <bits/stdc++.h>
using namespace std;

int n,c,ans,lst;

int main() {
    ans=0;
    lst=0;
    scanf("%d%d",&n,&c);
    for(int i=1,j;i<=n;i++) {
        scanf("%d",&j);
        if(j-lst>c) ans=0;
        ans+=1;
        lst=j;
    }
    printf("%d\n",ans);
    return 0;
}