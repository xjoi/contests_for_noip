//#pragma GCC optimize("O3")
#include<bits/stdc++.h>
#define maxn 200000
using namespace std;
struct EDGE{int  from,to,w,id,ans;}e[maxn];
bool cmp(EDGE a,EDGE b){return a.w<b.w;}
bool cmp1(EDGE a,EDGE b){return a.id<b.id;}
int n,m,cnt=0,pre[maxn];

int find(int x){return x==pre[x]?x:pre[x]=find(pre[x]);}

map<int, vector<int > > g,edge;
set<int> Map;
map<int,int> dfn,low;

inline void tarjan(int x)
{
//	if(dfn[x]) return ;
	dfn[x]=low[x]=++cnt;
	for(int i=0;i<g[x].size();i++)
	{
		int to=g[x][i],number=edge[x][i];	
		if(Map.count(number)) continue;
		Map.insert(number);
		if(!dfn[to]) 
		{
			tarjan(to);
			low[x]=min(low[to],low[x]);
			if(low[to]>dfn[x]) e[number].ans=2;
		}
		else if(dfn[to]<dfn[x])
			low[x]=min(low[x],dfn[to]);
	}
}
inline int Read()//inline相当于拷贝的功能减小堆栈加快速度
{
   char ch=getchar();
   int re=0;
   int fl=1;
   while(ch<'0'||ch>'9')
   {
       if(ch=='-')
            fl=-1;
       ch=getchar();
   }
   while(ch>='0'&&ch<='9')
   {
      re=re*10+ch-'0';
      ch=getchar();
   }
   return fl*re;
} 

int main()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++) pre[i]=i;
	for(int i=1;i<=m;i++)
	{	e[i].from=Read();e[i].to=Read();e[i].w=Read();e[i].id=i;}
	sort(e+1,e+m+1,cmp);
	int rt=1;
	while(rt<=m)
	{
		int l=rt;
		while(e[rt].w==e[l].w&&rt<=m) rt++;
		if(rt!=l) rt--;
		g.clear();Map.clear();edge.clear();dfn.clear();
		cnt=0;
		for(int i=l;i<=rt;i++)
		{
			int fx=find(e[i].from),fy=find(e[i].to);
			if(fx==fy) continue;
			e[i].ans=1;
			g[fx].push_back(fy),g[fy].push_back(fx);
			edge[fx].push_back(i),edge[fy].push_back(i);
		}
		for(map<int,vector<int> > ::iterator it=g.begin();it!=g.end();it++)
			tarjan(it->first);
		for(int i=l;i<=rt;i++)
		{
			int fx=find(e[i].from),fy=find(e[i].to);
			pre[fx]=fy;
		}
		rt++;
	}
	sort(e+1,e+m+1,cmp1);
	for(int i=1;i<=m;i++)
	{
		if(e[i].ans==1)puts("at least one\n");
		else if(e[i].ans==2)puts("any\n");
		else puts("none\n");
	}
	return 0;
}
/*
4 5
1 2 101
1 3 100
2 3 2
2 4 2
3 4 1
*/
