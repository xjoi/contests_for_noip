#include <bits/stdc++.h>
using namespace std;

int n,f[1000010][20],dep[1000010],tot,ans=2,est;

int lca(int x,int y) {
    if(dep[x]<dep[y]) swap(x,y);
    int tmp=dep[x]-dep[y];
    for(int i=0;(1<<i)<=tmp;i++) {
        if((1<<i)&tmp) x=f[x][i];
    }
    if(x==y) return x;
    for(int i=20;i>=0;i--) {
        if((1<<i)<=dep[x]&&f[x][i]!=f[y][i]) x=f[x][i],y=f[y][i];
    }
    return f[x][0];
}

int main() {
    scanf("%d",&n);
    f[1][0]=1;
    f[2][0]=f[3][0]=f[4][0]=1;
    dep[1]=1;
    dep[2]=dep[3]=dep[4]=2;
    tot=4;
    est=2;
    for(int q,i=1;i<=n;i++) {
        scanf("%d",&q);
        tot++;
        dep[tot]=dep[q]+1;
        f[tot][0]=q;
        for(int j=1;(1<<j)<=dep[tot];j++) {
            f[tot][j]=f[f[tot][j-1]][j-1];
        }
        tot++;
        dep[tot]=dep[q]+1;
        f[tot][0]=q;
        for(int j=1;(1<<j)<=dep[tot];j++) {
            f[tot][j]=f[f[tot][j-1]][j-1];
        }
        if(dep[tot]>dep[est]) {
            est=tot;
            ans++;
        } else {
            int dis=dep[q]+dep[est]-2*dep[lca(q,est)]+1;
            if(dis>ans) ans=dis;
        }
        cout<<ans<<endl;
    }
    return 0;
}