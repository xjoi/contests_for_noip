#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int dep[1000010];
int grand[1000010][21];

int LCA(int x,int y){
	if (dep[x]>dep[y]) swap(x,y);
	int direct=dep[y]-dep[x];
	for (int i=0;i<=20;++i)
		if ((1<<i)&direct) y=grand[y][i];
	for (int i=20;i>=0;--i)
		if (grand[x][i]!=grand[y][i])
			x=grand[x][i],y=grand[y][i];
	return x==y? x:grand[x][0];
}

int main(){
	int q,v,l1,maxi=0;cin >>q;
	int n=4;dep[2]=dep[3]=dep[4]=1;
	grand[2][0]=grand[3][0]=grand[4][0]=1;
	l1=2;maxi=2;
	for (int i=1;i<=q;++i){
		scanf("%d",&v);
		dep[n+1]=dep[n+2]=dep[v]+1;
		grand[n+1][0]=v;grand[n+2][0]=v;
		for (int k=1;k<=20;++k) grand[n+1][k]=grand[grand[n+1][k-1]][k-1];
		for (int k=1;k<=20;++k) grand[n+2][k]=grand[grand[n+2][k-1]][k-1];
		if (dep[n+1]>dep[l1])	l1=n+1,++maxi;
		else if (dep[n+1]+dep[l1]>maxi){
			int lca=LCA(n+1,l1);
			if (dep[n+1]+dep[l1]-2*dep[lca]>maxi) ++maxi;
		}
		n+=2;
		printf("%d\n",maxi);
	}
	return 0;
}
