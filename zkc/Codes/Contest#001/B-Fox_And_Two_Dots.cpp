#include <bits/stdc++.h>
using namespace std;
char a[100][100];
bool p[100][100];
int n,m,ans;

void out() {
    cout<<"Yes"<<endl;
    exit(0);
    return;
}

void dfs(int x,int y,int prex,int prey) {
    //cout<<"|"<<x<<" "<<y<<endl;
    p[x][y]=1;
    if(x>1&&x-1!=prex&&a[x-1][y]==a[x][y]) {
        if(p[x-1][y]) out();
        dfs(x-1,y,x,y);
    }
    if(y>1&&y-1!=prey&&a[x][y-1]==a[x][y]) {
        if(p[x][y-1]) out();
        dfs(x,y-1,x,y);
    }
    if(x<n&&x+1!=prex&&a[x+1][y]==a[x][y]) {
        if(p[x+1][y]) out();
        dfs(x+1,y,x,y);
    }
    if(y<m&&y+1!=prey&&a[x][y+1]==a[x][y]) {
        if(p[x][y+1]) out();
        dfs(x,y+1,x,y);
    }
}

int main() {
    memset(p,0,sizeof p);
    cin>>n>>m;
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=m;j++) {
            cin>>a[i][j];
        }
    }
    ans=0;
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=m;j++) {
            if(!p[i][j]) dfs(i,j,0,0);
        }
    }
    cout<<"No"<<endl;
    return 0;
}