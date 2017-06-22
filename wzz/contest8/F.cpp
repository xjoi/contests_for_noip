using namespace std;
#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
int q;
#define N 2000001
#define r(x) scanf("%d",&x)
int k1,k2;
int fa[N],d[N];
int st[N][22];
int x;
int ans;
int sz;
int LCA(int x,int y)
{
	if(d[x]>d[y]) swap(x,y);
	if(d[x]<d[y])
	{
		for(int i=21;i>=0;i--)
		{
			if(d[y]-(1<<i)>=d[x])y=st[y][i];
		}
	}
	if(x==y) return x;
	for(int i=21;i>=0;i--)
	{
		if(st[x][i]!=st[y][i])
		{
			x=st[x][i];
			y=st[y][i];
		}
	}
	return st[x][0];
}
int main()
{
	r(q);
	fa[2]=1;fa[3]=1;fa[4]=1;d[2]=1;d[3]=1;d[4]=1;sz=4;
	k1=2;k2=3;ans=2;
	while(q--)
	{
		r(x);
		d[++sz]=d[x]+1;fa[sz]=x;
		st[sz][0]=fa[sz];
		for(int i=1;i<=21;i++)
		{
			st[sz][i]=st[st[sz][i-1]][i-1];
			if(st[sz][i]==0) break;
		}
		d[++sz]=d[x]+1;fa[sz]=x;
		st[sz][0]=fa[sz];
		for(int i=1;i<=21;i++)
		{
			st[sz][i]=st[st[sz][i-1]][i-1];
			if(st[sz][i]==0) break;
		}
		int atp=0;
		int it=LCA(sz,k1);atp=d[sz]+d[k1]-2*d[it];if(atp>ans){ans=atp;k2=sz;}
		it=LCA(sz,k2);atp=d[sz]+d[k2]-2*d[it];if(atp>ans){ans=atp;k1=sz;}
		printf("%d\n",ans); 
	}
}
