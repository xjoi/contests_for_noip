/*
开O2才能卡过...
*/
%:pragma GCC optimize(2)
#include<iostream>
#include<cstdio>
#include<vector>
#include<map>
#include<set>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<climits>
using namespace std;
map<int,vector<int> > v,mark;
map<int,int> vis,first;
set<int> ms;
char res[10][30]={"none","at least one","any"};
int f[100010],tim,n,m;
struct Edge{
	int u,v,w,id,ans;
};
Edge e[100010];
bool cmp1(Edge a,Edge b)
{
	return a.w<b.w;
}
bool cmp2(Edge a,Edge b)
{
	return a.id<b.id;
}
int getfa(int x)
{
	return f[x]==x?x:f[x]=getfa(f[x]);
}
void tarjan(int x)
{
	if(vis[x])
		return;
	vis[x]=first[x]=++tim;
	for(int i=0;i<v[x].size();i++)
	{
		int y=v[x][i],Mark=mark[x][i];
		if(ms.count(Mark))
			continue;
		ms.insert(Mark);
		tarjan(y);
		if(vis[y]<vis[x])
			vis[x]=vis[y];
		if(vis[y]>first[x])
			e[Mark].ans=2;
	} 
}
int main()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		f[i]=i;
	for(int i=1;i<=m;i++)
	{
		scanf("%d%d%d",&e[i].u,&e[i].v,&e[i].w);
		e[i].id=i;
	}
	sort(e+1,e+m+1,cmp1);
	for(int i=1;i<=m;)
	{
		int s=i,fx,fy;
		while(i<=m&&e[i].w==e[s].w)
			i++;
		v.clear();
		vis.clear();
		mark.clear();
		ms.clear();
		for(int j=s;j<i;j++)
		{
			fx=getfa(e[j].u);
			fy=getfa(e[j].v);
			if(fx==fy)
				continue;
			e[j].ans=1;
			v[fx].push_back(fy);
			v[fy].push_back(fx);
			mark[fx].push_back(j);
			mark[fy].push_back(j);
		}
		for(map<int,vector<int> >::iterator it=v.begin();it!=v.end();it++)
			tarjan(it->first);
		for(int j=s;j<i;j++)
		{
			fx=getfa(e[j].u);
			fy=getfa(e[j].v);
			if(fx==fy)
				continue;
			f[fx]=fy;
		}
	}
	sort(e+1,e+m+1,cmp2);
	for(int i=1;i<=m;i++)
		printf("%s\n",res[e[i].ans]);
	return 0;
}
