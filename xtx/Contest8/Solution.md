# E

将一段大的单位长度分为许多段小的单位长度，大概是2000吧，这样精度就可以达到1/2000/2000，然后暴力求面积。

具体实现上与扫描线算法好像差不多，就酱

```cpp

#include<iostream>
#include<cstring>
#include<algorithm>
#include<cstdio>
using namespace std;
#define ll long long
const int MAXN=300;
const int MAXK=300;
const int BLOCK=2000;
int n,k;
int a[MAXN+10][MAXK+10];
ll s[MAXN+10];
int main()
{
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;++i)for(int j=0;j<=k;++j)scanf("%d",&a[i][j]);
	for(int cnt=1;cnt<=k;++cnt)
	{
		for(int j=0;j<=BLOCK;++j)
		{
			int my=0,y;
			for(int i=1;i<=n;++i)
			{
				y=a[i][cnt]*j+a[i][cnt-1]*(BLOCK-j);
				if(y>my)
				{
					s[i]+=(y-my)*((!j||j==BLOCK)?1:2);
					my=y;
				}
			}
		}
	}
	for(int i=1;i<=n;++i)printf("%.12lf\n",(double)s[i]/BLOCK/BLOCK/2);
	return 0;
}

```

# F

有一个**重要结论**:

> 有一棵树，离某点最远的点一定是树直径两端点之一

~~由于这样就结束有一点短，证明一下~~

首先设直径为s-t，某点为u。

如果

## 1.u在s-t上

结论是显然的。

## 2.u不在s-t上

设u走向s-t时遇到了x，u离v最远，x离y最远

### x在u-v上

u-x是定值，然后x到哪里最远呢？这就是1.的问题了。

### x不在u-v上

先假设y为t吧

∵dist(u,v)>dist(u,x)+dist(x,t)

∴dist(u,v)>dist(x,t)

∴dist(s,x)+dist(x,u)+dist(u,v)>dist(s,x)+dist(x,t)

∴直径就不是直径了

∴假设不成立

然后就可以动态维护树的直径了 

```cpp

#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<cmath>
using namespace std;
const int MAXBIT=20;
const int MAXN=1000000;
int q;
int f[MAXN+10][MAXBIT+10],dep[MAXN+10];
int cnt=4;
int lca(int x,int y)
{
	if(dep[x]<dep[y])swap(x,y);
	for(int i=MAXBIT;~i;--i)
	{
		if(dep[f[x][i]]>=dep[y])x=f[x][i];
	}
	if(x==y)return x;
	for(int i=MAXBIT;~i;--i)
	{
		if(f[x][i]!=f[y][i])
		{
			x=f[x][i];
			y=f[y][i];
		}
	}
	return f[x][0];
}
int GetDist(const int x,const int y){return dep[x]+dep[y]-dep[lca(x,y)]*2;}
int main()
{
	f[2][0]=f[3][0]=f[4][0]=1;
	dep[1]=1;dep[2]=dep[3]=dep[4]=2;
	scanf("%d",&q);
	int a=2,b=3,mx=2;
	for(int i=1;i<=q;++i)
	{
		int x;
		scanf("%d",&x);
		f[++cnt][0]=x;dep[cnt]=dep[x]+1;
		for(int i=1;i<=MAXBIT;++i)f[cnt][i]=f[f[cnt][i-1]][i-1];
		f[++cnt][0]=x;dep[cnt]=dep[x]+1;
		for(int i=1;i<=MAXBIT;++i)f[cnt][i]=f[f[cnt][i-1]][i-1];
		int tmp;
		tmp=GetDist(x,a)+1;
		if(tmp>mx)
		{
			mx=tmp;
			b=cnt;
		}
		tmp=GetDist(x,b)+1;
		if(tmp>mx)
		{
			mx=tmp;
			a=cnt;
		}
		printf("%d\n",mx);
	}
	return 0;
}

```
