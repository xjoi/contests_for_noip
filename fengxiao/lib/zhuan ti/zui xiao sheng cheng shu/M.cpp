#include<cstdio>
#include<cstring>
#include<iostream>
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
    int i,j,k=0,tmp; char ch,c;
	while(cin>>n)
	{
		if(n==0) break;
		ans=k=m=0;
		for(i=1;i<n;i++) 
		{
			cin>>c>>tmp;
			for(j=1;j<=tmp;j++)
			{
				cin>>ch>>e[m+j].v;
				e[m+j].s=c-'A'+1,e[m+j].e=ch-'A'+1;
			}
			m+=tmp;
		}
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
