#include<cstdio>
#include<iostream>
#include<cstring>
#include<map>
#define xxx 233233
using namespace std;
map<int,int>mpx;
map<int,int>::iterator ddqx;
map<int,int>mpy;
map<int,int>::iterator ddqy;
int n,q,x[xxx],y[xxx],ans[xxx],p;
char c[xxx];

char gc()
{
	char cc;
	while (1)
	{
		cc=getchar();
		if (cc=='L'||cc=='U') return cc;
	}
}

int main()
{
	int t;
	scanf("%d%d",&n,&q);
	for (int i=1;i<=q;i++)
	{
		scanf("%d%d",&x[i],&y[i]);
		c[i]=gc();
		if (c[i]=='U')
		{
			ddqx=mpx.lower_bound(x[i]);
			if (ddqx==mpx.end())
				ans[i]=y[i];
			else
			{
				p=ddqx->second;
				if (y[p]==y[i])
					ans[i]=0;
				else
					if (c[p]=='L')
						ans[i]=y[i]-y[p];
					else 
						ans[i]=y[i]-y[p]+ans[p];
			}
		}
		else
		{
			ddqy=mpy.lower_bound(y[i]);
			if (ddqy==mpy.end())
				ans[i]=x[i];
			else
			{
				p=ddqy->second;
				if (x[p]==x[i])
					ans[i]=0;
				else
					if (c[p]=='U')
						ans[i]=x[i]-x[p];
					else
						ans[i]=x[i]-x[p]+ans[p];
			}
		}
		printf("%d\n",ans[i]);
		if (!mpx.count(x[i])) mpx[x[i]]=i;
		if (!mpy.count(y[i])) mpy[y[i]]=i;
	}
}
