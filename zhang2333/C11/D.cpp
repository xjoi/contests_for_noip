#include<cstdio>
#include<iostream>
#include<queue>
#include<cstring>
#define xxx 100100
using namespace std;
int inf;
int x[xxx],y[xxx],n,m,k,st,en;

int abss(int x)
{
	return x>0?x:-x;
}

int dist(int a,int b)
{
	if (a==b) return 2;
	if (x[a]==x[b]||y[a]==y[b])
		return max(abss(x[a]-x[b]),abss(y[a]-y[b]))==1?0:1;
	return min(abss(x[a]-x[b]),abss(y[a]-y[b]))<3?1:2;
}

queue<int>q;
int in[xxx],d[xxx];
int spfa()
{
	while (!q.empty()) q.pop();
	q.push(st);
	memset(in,0,sizeof(in));
	memset(d ,38,sizeof(d));
	inf=d[0];
	d[st]=0;
	int x,y,dis;
	while (!q.empty())
	{
		x=q.front();
		q.pop();
		if (x==en) continue;
		in[x]=0;
		for (int i=1;i<=k;i++)
			if ((dis=dist(x,i))<2)
			{
				//printf("%d %d:%d\n",x,i,dis);
				if (d[i]>d[x]+dis)
				{
					d[i]=d[x]+dis;
					if (!in[i])
					{
						in[i]=1;
						q.push(i);
					}
				}
			}
	}
	if (d[en]==inf) return -1;
	return d[en];
}

int main()
{
	scanf("%d%d%d",&n,&m,&k);
	for (int i=1;i<=k;i++)
	{
		scanf("%d%d",&x[i],&y[i]);
		if (x[i]==1&&y[i]==1)
			st=i;
		if (x[i]==n&&y[i]==m)
			en=i;
	}
	if (en==0)
	{
		k++;
		en=k;
		x[k]=n+1;
		y[k]=m+1;
	}
	printf("%d\n",spfa());
	return 0;
}
