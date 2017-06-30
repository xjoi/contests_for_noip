#include<bits/stdc++.h>
using namespace std;
const int N=10000,inf=0x3f3f3f3f;
int x[N+2],y[N+2],dis[N+2],vis[N+2];
int main(){
	int n,m,k; cin>>n>>m>>k; bool b=0;
	for(int i=1;i<=k;++i){
		cin>>x[i]>>y[i]; dis[i]=inf;
		if(x[i]==n&&y[i]==m) b=1;
	}
	if(b){
		x[++k]=n; y[k]=m; dis[k]=inf;
	}else{
		x[++k]=n+1; y[k]=m+1; dis[k]=inf;
	}
	dis[0]=0; x[0]=1; y[0]=1;
	for(int i=0;i<=k;++i){
		int Min=k;
		for(int j=0;j<=k-1;++j) if(!vis[j]&&dis[j]<dis[Min])
			Min=j;
		vis[Min]=1;
		for(int j=0;j<=k;++j) if(!vis[j]){
			int xx=abs(x[j]-x[Min]),yy=abs(y[j]-y[Min]);
			if(xx+yy<=1) dis[j]=dis[Min];
			else if(xx<=2||yy<=2) dis[j]=min(dis[j],dis[Min]+1);
		}
	}
	cout<<(dis[k]==inf?-1:dis[k]); return 0;
}
