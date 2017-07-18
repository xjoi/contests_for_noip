#include<cstdio>
#include<cstring>
#include<algorithm>
#define N 1010
using namespace std;
int n,m=0;
struct Edge {int s,e,v;} e[N*N];
bool cmp(Edge a,Edge b) {return a.v<b.v;}
int fat[N],a[N],ans=0;
int father(int x) {return x==fat[x]?x:fat[x]=father(fat[x]);}
int main()
{
    int i,j,x,k=0,T;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		m=ans=k=0;
		for(i=1;i<=n;i++) scanf("%d",&a[i]);
		for(i=1;i<=n;i++)
			for(j=1;j<=n;j++)
			{
				scanf("%d",&x);
				if(i<j) e[++m].s=i,e[m].e=j,e[m].v=x+a[i]+a[j];    
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
		printf("%d\n",ans);
	}
    return 0;
}
