#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
using namespace std;
int q,n;
int fa[1000008][22],deep[1000008];
int LCA(int u,int v) {
    int ans=0;
    while (deep[u]>deep[v]) {
        int kx=log2(deep[u]-deep[v]);
        u=fa[u][kx];
        ans+=1<<kx;
    }
    while (deep[u]<deep[v]) {
        int kx=log2(deep[v]-deep[u]);
        v=fa[v][kx];
        ans+=1<<kx;
    }
    if (u==v) return ans;
    int kx=log2(deep[u]);
    for (int i=kx;i>=0;i--)
        if (fa[u][i]!=fa[v][i]) {
            u=fa[u][i];
            v=fa[v][i];
            ans+=1<<(i+1);
        }
    return ans+2;
}
int main() {
    scanf("%d",&q);
    n=4;
    fa[2][0]=fa[3][0]=fa[4][0]=1;
    int depth=1,nowans=2,deepest=2;
    deep[1]=1;
    deep[2]=deep[3]=deep[4]=2;
    while (q--) {
        int x;
        scanf("%d",&x);
        n+=2;
        deep[n-1]=deep[n]=deep[x]+1;
        fa[n-1][0]=fa[n][0]=x;
        int dx=log2(deep[n]);
        for (int i=1;i<=dx;i++) {
            fa[n-1][i]=fa[fa[n-1][i-1]][i-1];
            fa[n][i]=fa[fa[n][i-1]][i-1];
        }
        if (deep[n]>depth) {
            deepest=n;
            depth=deep[n];
            nowans++;
        }
        else nowans=max(nowans,LCA(n,deepest));
        printf("%d\n",nowans);
    }
    return 0;
}
