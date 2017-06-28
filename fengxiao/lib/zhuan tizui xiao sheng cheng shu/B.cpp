#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int n,m=0;
struct Edge
{int s,e,v;}e[10010];
bool cmp(Edge a,Edge b) {return a.v<b.v;}
int fat[110],ans=0;
int father(int x) {return x==fat[x]?x:fat[x]=father(fat[x]);}
int main()
{
    int i,j,x,k=0;
	while(scanf("%d %d",&n,&m)==2)
	{
		ans=k=0;
		for(i=1;i<=m;i++) scanf("%d %d %d",&e[i].s,&e[i].e,&e[i].v);
		sort(e+1,e+m+1,cmp);
		for(i=1;i<=n;i++) fat[i]=i;
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
		printf("%d\n",ans);
	}
    return 0;
}
