#include <bits/stdc++.h>
using namespace std;
int f[55][55],m,n;
char c[55][55];
bool dfs(int x,int y,int fx,int fy){
	if(f[x][y]==1)return 1;
	f[x][y]=1;
	int j=0;
	if(x<n&&c[x+1][y]==c[x][y]&&fx!=x+1)j=j|dfs(x+1,y,x,y);
	if(x>1&&c[x-1][y]==c[x][y]&&fx!=x-1)j=j|dfs(x-1,y,x,y);
	if(y>1&&c[x][y-1]==c[x][y]&&fy!=y-1)j=j|dfs(x,y-1,x,y);
	if(y<m&&c[x][y+1]==c[x][y]&&fy!=y+1)j=j|dfs(x,y+1,x,y);
	return j;
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%s",c[i]+1);
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++)if(!f[i][j]){
			memset(f,0,sizeof f);
			if(dfs(i,j,i,j)){
				puts("Yes");
				return 0;
			}
		}
	}
	puts("No");
	return 0;
}
