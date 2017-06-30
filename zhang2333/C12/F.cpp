#include<cstdio>
#include<iostream>
#include<cmath>
#define xxx 210
using namespace std;

struct edge{
	int u,v;
}e[xxx];
int n,m,f[xxx][xxx];
struct P{
	long long x,y;
}p[xxx];
struct L{
	long long a,b,c;
};
L line(P p1,P p2)
{
	return (L){p2.y-p1.y,p1.x-p2.x,p2.x*p1.y-p2.y*p1.x};
}

double mult(P a, P b, P c)  
{  
    return (a.x-c.x)*(b.y-c.y)-(b.x-c.x)*(a.y-c.y);  
}  

bool pd(P aa, P bb, P cc, P dd)  
{  
    if ( max(aa.x, bb.x)<min(cc.x, dd.x) )  return 0;  
    if ( max(aa.y, bb.y)<min(cc.y, dd.y) )  return 0;  
    if ( max(cc.x, dd.x)<min(aa.x, bb.x) )  return 0;  
    if ( max(cc.y, dd.y)<min(aa.y, bb.y) )  return 0;  
    if ( mult(cc, bb, aa)*mult(bb, dd, aa)<0 )  return 0;  
    if ( mult(aa, dd, cc)*mult(dd, bb, cc)<0 )  return 0;  
    return 1;  
}  

void $(int a,int b)
{
	P p1=p[e[a].u],p2=p[e[a].v],p3=p[e[b].u],p4=p[e[b].v];
	if 	( pd(p1,p2,p3,p4) )
	{
		f[e[a].u][e[b].u]=f[e[a].u][e[b].v]=f[e[a].v][e[b].u]=f[e[a].v][e[b].v]=1;
		swap(a,b);
		f[e[a].u][e[b].u]=f[e[a].u][e[b].v]=f[e[a].v][e[b].u]=f[e[a].v][e[b].v]=1;
	}
}

void _(int t,int tt)
{
	P p1=p[tt];
	if (p1.x<min(p[e[t].u].x,p[e[t].v].x)||p1.x>max(p[e[t].u].x,p[e[t].v].x)) return;
	if (p1.y<min(p[e[t].u].y,p[e[t].v].y)||p1.y>max(p[e[t].u].y,p[e[t].v].y)) return;
	L l=line(p[e[t].u],p[e[t].v]);
	if (l.a*p1.x+l.b*p1.y+l.c==0)
	{
		f[e[t].u][tt]=f[tt][e[t].u]=1;
		f[e[t].v][tt]=f[tt][e[t].v]=1;
	}
}

int used[xxx];
void dfs(int x)
{
	used[x]=1;
	for (int i=1;i<=n;i++)
		if (f[x][i]&&!used[i])
			dfs(i);
}

int main()
{
	cin>>n>>m;
	for (int i=1;i<=n;i++)
		cin>>p[i].x>>p[i].y;
	for (int i=1;i<=m;i++)
	{
		cin>>e[i].u>>e[i].v;
		f[e[i].u][e[i].v]=f[e[i].v][e[i].u]=1;
	}
	for (int i=1;i<=m;i++)
		for (int j=1;j<=n;j++)
			_(i,j);
	for (int i=1;i<m;i++)
		for (int j=i+1;j<=m;j++)
			$(i,j);
	int tot=0;
	if (0)
	{
		for (int i=1;i<=n;i++)
		{
			for (int j=1;j<=n;j++)
				printf(" %d",f[i][j]);
			printf("\n");
		}
	}
	
	for (int i=1;i<=n;i++)
	{
		if (!used[i])
		{
			tot++;
			dfs(i);
		}
	}
	if (tot<=1)
		printf("YES");
	else
		printf("NO");
}
