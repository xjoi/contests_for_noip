#include <bits/stdc++.h>
using namespace std;
int n,f[60][60],a[60][100010],b[60][100010],ans;
bool flag=true;
bool check(int x,int y) {
    int v=f[x][y];
    bool p=false;
    a[x][v]--;
    b[y][v]--;
    for(int i=1;i<v;i++) {
        if(a[x][i]&&b[y][v-i]) {
            //printf("%d+%d=%d\n",i,v-i,v);
            p=true;
            break;
        }
    }
    a[x][v]++;
    b[y][v]++;
    return p;
}
int main() {
    scanf("%d",&n);
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=n;j++) {
            scanf("%d",&f[i][j]);
        }
    }
    for(int i=1;i<=n;i++) {
        memset(a[i],0,sizeof a[i]);
        memset(b[i],0,sizeof b[i]);
        for(int j=1;j<=n;j++) {
            a[i][f[i][j]]++;
            b[i][f[j][i]]++;
        }
    }
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=n;j++) {
            if(f[i][j]>1) flag=check(i,j);
            if(!flag) break;
        }
        if(!flag) break;
    }
    if(flag) puts("Yes");
    else puts("No");
    return 0;
}