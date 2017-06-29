#include <bits/stdc++.h>
using namespace std;

const int MAXS=100010, MAXT=100010;

int a[30];
int f[MAXT],s[MAXS],t[MAXT];
int n,m,ans=0,k,tmp;

bool solve(int x) {
    for(int i=1;i<m;i++) {
        if((t[i]<t[i+1]&&s[x+i-1]>=s[x+i])||(t[i]==t[i+1]&&s[x+i-1]!=s[x+i])||(t[i]>t[i+1]&&s[x+i-1]<=s[x+i])) {
            return false;
        }
    }
    return true;
}

int main() {
    while((scanf("%d%d%d",&n,&m,&k))!=EOF) {
    memset(a,0,sizeof a);
    for(int i=1;i<=n;i++) {
        scanf("%d",&s[i]);
        a[s[i]]=1;
    }
    for(int i=1;i<=m;i++) {
        scanf("%d",&t[i]);
        a[t[i]]=1;
    }
    memset(f,0,sizeof f);
    ans=0;
    for(int i=1;i<=n-m+1;i++) {
        if(solve(i)) {
            i+=m-1;
            ans++;
        }
    }
    printf("%d\n",ans);
    }
    return 0;
}