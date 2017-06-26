#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<cmath>
#define INF 1000000000
using namespace std;
int n,nn,m=0;
struct Edge {int s,e; double v;} e[10010];
struct P {double x,y,z,r;} p[110];
bool cmp(Edge a,Edge b) {return a.v<b.v;}
int fat[110]; double ans=0;
int father(int x) {return x==fat[x]?x:fat[x]=father(fat[x]);}
inline double max(double a) {return a>0.0000001 ? a :0.0;}
double get_dis(int x,int y) {return sqrt((p[x].x-p[y].x)*(p[x].x-p[y].x)+(p[x].y-p[y].y)*(p[x].y-p[y].y)+(p[x].z-p[y].z)*(p[x].z-p[y].z));}
int main()
{
    int i,j,k=0;
	while(scanf("%d",&n)==1)
	{
		m=0;ans=0.0;k=0;
		if(n==0) break;
		for(i=1;i<=n;i++) cin>>p[i].x>>p[i].y>>p[i].z>>p[i].r;
		for(i=1;i<=n;i++)
			for(j=i+1;j<=n;j++)
			{
				e[++m].s=i,e[m].e=j,e[m].v=max(get_dis(i,j)-p[i].r-p[j].r);
			}
		for(i=1;i<=n;i++) fat[i]=i;
		sort(e+1,e+m+1,cmp);
		for(i=1;i<=m;i++)
		{
			int x=father(e[i].s),y=father(e[i].e);
			if(x==y) continue;
			else
			{
				fat[x]=y;
				ans+=e[i].v;
				k++;
			}
			if(k==n-1) break;
		}
		printf("%.3f\n",ans);
	}
    return 0;
}
