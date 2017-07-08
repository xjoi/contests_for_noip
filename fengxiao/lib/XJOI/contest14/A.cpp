#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int n,T,a[5],go[5],used[31][31][31][31];
char s[50],t[50];
inline void clear() {memset(used,0,sizeof(used));memset(a,0,sizeof(a));memset(go,0,sizeof(go));}
inline void dfs(int a,int b,int c,int d)
{
    if (used[a][b][c][d]) return;
    used[a][b][c][d]=1;
    if (a&&c) dfs(a-1,b+1,c-1,d+1);
    if (b&&d) dfs(a+1,b-1,c+1,d-1);
    if (a&&b) dfs(a-1,b-1,c+1,d);
    if (b&&c) dfs(a,b-1,c-1,d+1);
    if (c&&d) dfs(a+1,b,c-1,d-1);
    if (d&&a) dfs(a-1,b+1,c,d-1);
}
int main()
{
    int i;
    scanf("%d",&T);
    while (T--)
    {
        clear();
        scanf("%s",s); for(i=0;i<30;i++) if(s[i]=='*') a[i%4]++;
        scanf("%s",s); for(i=0;i<30;i++) if(s[i]=='*') go[i%4]++;
        dfs(a[0],a[1],a[2],a[3]);
        if(used[go[0]][go[1]][go[2]][go[3]]) puts("YES");
        else puts("NO");
    }
    return 0;
}
