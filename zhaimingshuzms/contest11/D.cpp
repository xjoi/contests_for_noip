#include<cstdio>
#include<map>
#include<queue>
using namespace std;
const int MK=500001,MN=50010,INF=1e9;
map<int,int> mp;
int b[MK],c[MK],ne[MK],fi[MN],n,m,k,en,f[MN],x[MN],y[MN],kk,a,kop;
bool in[MN];
void add(int x,int y,int z){
	b[++k]=y; c[k]=z; ne[k]=fi[x]; fi[x]=k;
}
void spfa(int be){
	queue<int> q;
	for (int i=1; i<=kk+n+m+1; i++) f[i]=INF;
	f[be]=0;
	q.push(be); in[be]=1;
	while (!q.empty()){
		int x=q.front(); q.pop();
		for (int j=fi[x]; j; j=ne[j])
		if (f[b[j]]>f[x]+c[j]){
			f[b[j]]=f[x]+c[j];
			if (!in[b[j]]) in[b[j]]=1,q.push(b[j]);
		}
		in[x]=0;
	}
}
int h(int x,int y){
	return (x-1)*n+y;
}
int main(){
	scanf("%d%d%d",&n,&m,&kk);
	for (int i=1; i<=kk; i++){
		scanf("%d%d",&x[i],&y[i]);
		if (x[i]==n&&y[i]==m) en=i;
		mp[h(x[i],y[i])]=i;
	}
	for (int i=1; i<=kk; i++){
		add(i,kk+x[i],1); add(kk+x[i],i,0);
		add(i,kk+n+y[i],1); add(kk+n+y[i],i,0);
		if (x[i]<n) {a=mp[h(x[i]+1,y[i])]; if (a) add(i,a,0),add(a,i,0); add(kk+x[i]+1,i,0); add(i,kk+x[i]+1,1);}
		if (x[i]>1) {a=mp[h(x[i]-1,y[i])]; if (a) add(i,a,0),add(a,i,0); add(kk+x[i]-1,i,0); add(i,kk+x[i]-1,1);}
		if (y[i]<m) {a=mp[h(x[i],y[i]+1)]; if (a) add(i,a,0),add(a,i,0); add(kk+n+y[i]+1,i,0); add(i,kk+n+y[i]+1,1);}
		if (y[i]>1) {a=mp[h(x[i],y[i]-1)]; if (a) add(i,a,0),add(a,i,0); add(kk+n+y[i]-1,i,0); add(i,kk+n+y[i]-1,1);}
	}
	if (!en){
		en=kk+n+m+1; 
		add(kk+n,en,0);
		add(kk+n+m,en,0);
	}
	spfa(1);
	printf("%d",f[en]<INF?f[en]:-1);
	return 0;
}
