#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
const int dx[]={1,0,-1,0},dy[]={0,1,0,-1};
int n,m,sx,sy,ans,T,B,p[1<<8],price[9],c[22][22],d[22][22][1<<8],f[200000],g[200000],e[200000];
char s[22][22];
int main()
{
	scanf("%d%d",&n,&m);
	for (int i=0;i<n;++i)
	{
		scanf("%s",s[i]);
		for (int j=0;j<m;++j)
		if (s[i][j]=='S') sx=i,sy=j,s[i][j]='.';
		for (int j=0;j<m;++j)
		if (s[i][j]>'0'&&s[i][j]<'9')
		{
			++T;
			for (int k=0;k<i;++k)
			c[k][j]|=1<<(s[i][j]-'1');
		}
	}
	for (int i=0;i<T;++i)
	scanf("%d",&price[i]);
	B=T;
	for (int i=0;i<(1<<T);++i)
	for (int j=0;j<T;++j)
	if (i>>j&1) p[i]+=price[j];
	for (int i=0;i<n;++i)
	for (int j=0;j<m;++j)
	if (s[i][j]=='B')
	{
		for (int k=0;k<i;++k)
		c[k][j]|=1<<B;
		++B;
	}
	int h=0,t=1;
	f[1]=sx;
	g[1]=sy;
	e[1]=0;
	memset(d,6,sizeof(d));
	d[sx][sy][0]=0;
	while (h<t)
	{
		int x=f[++h],y=g[h],z=e[h],D=d[x][y][z];
		for (int dir=0;dir<4;++dir)
		{
			int i=x+dx[dir],j=y+dy[dir],k=z;
			if (i<0||i>=n||j<0||j>=m||s[i][j]!='.') continue;
			if (y!=j) k^=c[i][min(y,j)];
			if (D+1<d[i][j][k]) d[i][j][k]=D+1,f[++t]=i,g[t]=j,e[t]=k;
		}
	}
	for (int i=0;i<(1<<T);++i)
	ans=max(ans,p[i]-d[sx][sy][i]);
	printf("%d\n",ans);
	return 0;
}
