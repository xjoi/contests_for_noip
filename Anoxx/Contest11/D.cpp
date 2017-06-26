#include<iostream>
#include<cstdio>
#include<map>
using namespace std;
#define hash(x,y) ((x)*(m+1)+y) 
const int N=1e4+10;
map<int,int> ma;
int n,m,x,y,t,k,st,en,pt,tot,f[N*3],fi[N*3],ne[30*N],a[30*N],c[30*N],q[100*N],b[N*3];
inline void add(int x,int y,int z){
	a[++tot]=y;c[tot]=z;ne[tot]=fi[x];fi[x]=tot;
}
main(){
	scanf("%d%d%d",&n,&m,&k);
	pt=n+m+k;
	for (int i=1;i<=k;++i){
		scanf("%d%d",&x,&y);
		if (x==1&&y==1) st=i;
		if (x==n&&y==m) en=i;
		add(i,k+x,1);add(k+x,i,0);if (x>1) add(i,k+x-1,1),add(k+x-1,i,0);if (x<n) add(i,k+x+1,1),add(k+x+1,i,0);
		add(i,k+n+y,1);add(k+n+y,i,0);if (y>1) add(i,k+n+y-1,1),add(k+n+y-1,i,0);if (y<m) add(i,k+n+y+1,1),add(k+n+y+1,i,0);
		if (t=ma[hash(x,y-1)]) add(t,i,0),add(i,t,0);
		if (t=ma[hash(x+1,y)]) add(t,i,0),add(i,t,0);
		if (t=ma[hash(x-1,y)]) add(t,i,0),add(i,t,0);
		if (t=ma[hash(x,y+1)]) add(t,i,0),add(i,t,0);
		ma[hash(x,y)]=i;
	}
	if (!en) en=++pt,add(k+n,pt,0),add(k+n+m,pt,0);
	for (int i=1;i<=pt;++i) f[i]=1e9;f[st]=0;
	q[1]=st;int h=0,t=1;
	while (++h<=t){
		b[q[h]]=0;
		for (int i=fi[q[h]];i;i=ne[i])
		if (f[q[h]]+c[i]<f[a[i]]){
			f[a[i]]=f[q[h]]+c[i];
			if (!b[a[i]]) q[++t]=a[i],b[a[i]]=1;
		}
	}
	printf("%d",f[en]>=1e9?-1:f[en]);
	return 0;
}
