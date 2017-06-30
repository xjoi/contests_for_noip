#include<cstdio>
#include<algorithm>
using namespace std;
int fa[2000000][22],n,ans,k1,k2,dep[2000000],x;
int lca(int x,int y){
	if(dep[x]<dep[y])swap(x,y);int ans=dep[x]+dep[y];
	for(int i=21;i>=0;i--)if(dep[fa[x][i]]>=dep[y])x=fa[x][i];//printf("%d\n",y);
	for(int i=21;i>=0;i--)if(fa[x][i]!=fa[y][i])x=fa[x][i],y=fa[y][i];
	x=fa[x][0];
	return ans-dep[x]*2;
}
int main(){
	scanf("%d",&n);
	k1=2;k2=3;ans=2;fa[2][0]=fa[3][0]=fa[4][0]=1;dep[2]=dep[3]=dep[4]=1;int p=4;
	for(int i=1;i<=n;i++){
		scanf("%d",&x);
		fa[p+1][0]=fa[p+2][0]=x;
		for(int i=1;i<=21;i++)
		fa[p+1][i]=fa[fa[p+1][i-1]][i-1],fa[p+2][i]=fa[fa[p+2][i-1]][i-1];
		dep[p+1]=dep[p+2]=dep[x]+1;
		p+=2;
		int l1=lca(p,k1),l2=lca(p,k2);
		if(l1>l2&&l1>ans)ans=l1,k2=p;
		if(l2>=l1&&l2>ans)ans=l2,k1=p;
		printf("%d\n",ans);
	}
	
}
