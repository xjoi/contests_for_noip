#include<cstdio>
#include<iostream>
using namespace std;
const int N=1010005;
int st[N][21],dep[N];
inline void update(int x) {
	int p=st[x][0];
	for(int i=1;i<=20;i++) {
		p=st[p][i-1];
		st[x][i]=p;
		if(!p) break;
	}
}
inline int lca(int a,int b) {
	int x=a,y=b;
	if(dep[a]<dep[b]) swap(a,b);
	for(int i=20;i>=0;i--) if(dep[st[a][i]]>=dep[b]) a=st[a][i];
	if(a==b) return a;
	for(int i=20;i>=0;i--) if(st[a][i]!=st[b][i]) a=st[a][i],b=st[b][i];
	return st[a][0];
}
int main() {
	int q,x,n=4,lx=2,ly=3,la=2,nx,ny,na,tmp;
	for(int i=2;i<=4;i++) {
		st[i][0]=1;
		dep[i]=1;
	}
	scanf("%d",&q);
	while(q--) {
		scanf("%d",&x);
		st[++n][0]=x;
		dep[n]=dep[x]+1;
		update(n);
		st[++n][0]=x;
		update(n);
		dep[n]=dep[x]+1;
		na=la;nx=lx;ny=ly;
		tmp=lca(lx,n-1);
		tmp=dep[lx]+dep[n-1]-2*dep[tmp];
		if(tmp>na) {
			na=tmp;
			nx=lx,ny=n-1;
		}
		tmp=lca(ly,n-1);
		tmp=dep[ly]+dep[n-1]-2*dep[tmp];
		if(tmp>na) {
			na=tmp;
			nx=ly,ny=n-1;
		}
		tmp=lca(lx,n-2);
		tmp=dep[lx]+dep[n-2]-2*dep[tmp];
		if(tmp>na) {
			na=tmp;
			nx=lx,ny=n-2;
		}
		tmp=lca(ly,n-2);
		tmp=dep[ly]+dep[n-2]-2*dep[tmp];
		if(tmp>na) {
			na=tmp;
			nx=ly,ny=n-2;
		}
		printf("%d\n",na);
		la=na;lx=nx;ly=ny;
	}
}
