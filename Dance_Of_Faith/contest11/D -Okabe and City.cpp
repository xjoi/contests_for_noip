#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
const int INF=1e9;
int x[10010],y[10010],dis[10010],vis[10010];
int main(){
	bool b=0;int n,m,k;
	cin>>n>>m>>k;
	for(int i=1;i<=k;++i){
		scanf("%d %d",&x[i],&y[i]);dis[i]=INF;
		if (x[i]==n&&y[i]==m) b=1;
	}
	if(b) ;//x[++k]=n,y[k]=m,dis[k]=INF;
	 else x[++k]=n+1,y[k]=m+1,dis[k]=INF;
	dis[0]=0;x[0]=1;y[0]=1;
	for(int i=0;i<=k;++i){
		int Min=k;
		for(int j=0;j<=k-1;++j) if(!vis[j]&&dis[j]<dis[Min]) Min=j;
		vis[Min]=1;
		for(int j=0;j<=k;++j) if(!vis[j]){
			int xx=abs(x[j]-x[Min]),yy=abs(y[j]-y[Min]);
			if(xx+yy<=1) dis[j]=dis[Min];
			else if(xx<=2||yy<=2) dis[j]=min(dis[j],dis[Min]+1);
		}
	}
	printf("%d",dis[k]==INF?-1:dis[k]);return 0;
}
