#include<cstdio>
#include<cstring>
#define N 1000010
using namespace std;
int anc[N][21],dep[N],lst=4;
int n,ans,v,u;
inline void swap(int &a,int &b) {int t=a;a=b;b=t;}
int lca(int x,int y)
{
	int i;
	if(dep[x]<dep[y]) swap(x,y);
	for(i=20;i>=0;i--) if(dep[anc[x][i]]>=dep[y]) x=anc[x][i];
	if(x==y) return x;
	for(i=20;i>=0;i--) if(anc[x][i]!=anc[y][i])x=anc[x][i],y=anc[y][i];
	return anc[x][0];
}
int get_dis(int x,int y) {return dep[x]+dep[y]-2*dep[lca(x,y)];}
int main()
{
	int i,j,x;
	scanf("%d",&n);
	anc[2][0]=anc[3][0]=anc[4][0]=1;
	dep[1]=1;dep[2]=dep[3]=dep[4]=2;
	u=2,v=3; ans=2;
	for(i=1;i<=n;i++)
	{
		scanf("%d",&x);
		anc[++lst][0]=x; dep[lst]=dep[x]+1;
		for(j=1;j<=20;j++) anc[lst][j]=anc[anc[lst][j-1]][j-1];
		anc[++lst][0]=x; dep[lst]=dep[x]+1;
		for(j=1;j<=20;j++) anc[lst][j]=anc[anc[lst][j-1]][j-1];
		//printf("%d %d\n",lca(lst,u),lca(lst,v));
		int dis=get_dis(lst,u);if(dis>ans) ans=dis,v=lst;
		    dis=get_dis(lst,v);if(dis>ans) ans=dis,u=lst;
		printf("%d\n",ans);
	}
	return 0;
}
