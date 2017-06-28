#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int n,nn,m=0;
struct Edge {int s,e,v;} e[10010];
bool cmp(Edge a,Edge b) {return a.v<b.v;}
int fat[110],ans=0;
int father(int x) {return x==fat[x]?x:fat[x]=father(fat[x]);}
int main()
{
    int i,k=0; char ch;
	scanf("%d",&nn);
	while(1)
	{
		if(nn==0) break;
		n=nn;
		m=0;ans=0;k=0;
		while(scanf("%d",&e[++m].s) && (ch=getchar()) && ch!='\n') scanf("%d %d",&e[m].e,&e[m].v);
		nn=e[m--].s;
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
