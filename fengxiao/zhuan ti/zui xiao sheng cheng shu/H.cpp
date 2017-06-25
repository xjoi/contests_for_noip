#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#define N 1010
#define INF 1000000000
using namespace std;
int n,nn,m=0;
struct Edge {int s,e; double v;} e[N*N];
struct P {double x,y;} p[N];
struct A {int a,b;} an[N];
int fat[N]; double ans=0;
int tmp[N]; bool used[N];
bool cmp(Edge a,Edge b) {return a.v<b.v;}
bool cmp1(A a,A b) {return a.a<b.a;}
int father(int x) {if(x!=fat[x])fat[x]=father(fat[x]); return fat[x];}
double get_dis(int x,int y) {return sqrt((p[x].x-p[y].x)*(p[x].x-p[y].x)+(p[x].y-p[y].y)*(p[x].y-p[y].y)*1.0);}
int main()
{
    int i,j,k=0,x,y,s;
	m=0;ans=0.0;k=0;memset(used,0,sizeof(used));
	scanf("%d",&n);
	for(i=1;i<=n;i++) scanf("%lf %lf",&p[i].x,&p[i].y);
	for(i=1;i<=n;i++)
		for(j=i+1;j<=n;j++)
		{
			e[++m].s=i,e[m].e=j,e[m].v=get_dis(i,j);
		}
	for(i=1;i<=n;i++) fat[i]=i;
	scanf("%d",&s);
	for(i=1;i<=s;i++) {scanf("%d %d",&x,&y); fat[father(x)]=father(y);}
	sort(e+1,e+m+1,cmp);
	for(i=1;i<=m;i++)
	{
		int x=father(e[i].s),y=father(e[i].e);
		if(x==y) continue;
		else
		{
			fat[x]=y;
			tmp[++k]=i; an[k].a=e[i].s,an[k].b=e[i].e;
		}
		if(k==n-1) break;
	}
	for(i=1;i<=k;i++)  printf("%d %d\n",an[i].a,an[i].b);
	return 0;
}
