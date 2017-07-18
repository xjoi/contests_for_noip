#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#define INF 1000000000
using namespace std;
int n,nn,m=0;
struct Edge {int s,e; double v;} e[10010];
struct P {int x,y;} p[110];
bool cmp(Edge a,Edge b) {return a.v<b.v;}
int fat[110]; double ans=0;
int father(int x) {return x==fat[x]?x:fat[x]=father(fat[x]);}
double get_dis(int x,int y) {return sqrt((p[x].x-p[y].x)*(p[x].x-p[y].x)+(p[x].y-p[y].y)*(p[x].y-p[y].y))*100;}
int main()
{
    int i,j,k=0,T;
	scanf("%d",&T);
	while(T--)
	{
		m=0;ans=0.0;k=0;
		scanf("%d",&n);
		for(i=1;i<=n;i++) scanf("%d %d",&p[i].x,&p[i].y);
		for(i=1;i<=n;i++)
			for(j=i+1;j<=n;j++)
			{
				e[++m].s=i,e[m].e=j,e[m].v=get_dis(i,j);
				//printf("?%1f %d?",e[m].v,m);
				if(e[m].v<1000 || e[m].v>100000) m--;
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
		//printf("?%d?",m);
		if(k<n-1) printf("oh!\n");
		else printf("%.1f\n",ans);
	}
    return 0;
}
