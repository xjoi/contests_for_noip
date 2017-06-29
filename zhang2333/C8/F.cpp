#include<cstdio>
#include<iostream>
#include<algorithm>
#include<vector>
#include<cmath>
#define zz 20
#define xxx 2330000
using namespace std;
int cnt,x,y,z,fa[xxx][zz+2],dep[xxx];

int get_lca(int x,int y)
{
	if (dep[x]<dep[y]) swap(x,y);
	for (int i=zz;i>=0;i--)
		if (dep[x]-(1<<i)>=dep[y])
			x=fa[x][i];
	if (x==y) return x;
	for (int i=zz;i>=0;i--)
		if (fa[x][i]!=fa[y][i])
		{
			x=fa[x][i];
			y=fa[y][i];
		}
	return fa[x][0];
}

int doit(int x,int y)
{
	//printf("%d %d %d\n",x,y,get_lca(x,y));
	return dep[x]+dep[y]-2*dep[get_lca(x,y)];
}

int realmain()
{
	for (int ttt=1;ttt<=2;ttt++)
	{
		cnt++;
		fa[cnt][0]=z;
		dep[cnt]=dep[z]+1;
		for (int i=1;i<=zz;i++)
			if (dep[cnt]>(1<<i))
				fa[cnt][i]=fa[fa[cnt][i-1]][i-1];
			else
				break;
	}
	z=cnt;
	int xy=doit(x,y),yz=doit(y,z),zx=doit(z,x);
	if (xy>=yz&&xy>=zx)
	{
		return xy;
	}
	if (yz>=xy&&yz>=zx)
	{
		x=z;
		return yz;
	}
	if (zx>=xy&&zx>=yz)
	{
		y=z;
		return zx;
	}
}

int main()
{
	cnt=4;
	x=2;y=3;
	fa[2][0]=fa[3][0]=fa[4][0]=1;
	dep[1]=1;
	dep[2]=dep[3]=dep[4]=2;
	int T;
	scanf("%d",&T);
	while (T--)
	{
		scanf("%d",&z);
		printf("%d\n",realmain());
	}
}
