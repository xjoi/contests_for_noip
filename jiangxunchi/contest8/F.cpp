#include<cstdio>
const int N=1000001;
int f[N][21],dep[N],cnt=4,maxl=2,maxr=4,len=2;
void addNum(int fa){
	f[++cnt][0]=fa; dep[cnt]=dep[fa]+1;
	for(int i=1;i<=20;++i) f[cnt][i]=f[f[cnt][i-1]][i-1];
}
int lca(int l,int r){
	int t; if(dep[l]<dep[r]) t=l,l=r,r=t;
	for(int t=dep[l]-dep[r],j=20;j>=0;--j) if(t&(1<<j)) l=f[l][j];
	if(l==r) return l;
	for(int j=20;j>=0;--j) if(f[l][j]!=f[r][j]) l=f[l][j],r=f[r][j];
	return f[l][0];
}
int dist(int l,int r){
	return dep[l]+dep[r]-dep[lca(l,r)]*2+1;
}
int main(){
	f[2][0]=f[3][0]=f[4][0]=1; dep[1]=1;
	dep[2]=dep[3]=dep[4]=2;
	int n; scanf("%d",&n);
	for(int i=1;i<=n;++i){
		int x; scanf("%d",&x); addNum(x); addNum(x);
		int t=dist(x,maxl); if(t>len) len=t,maxr=cnt;
		t=dist(x,maxr); if(t>len) len=t,maxl=cnt;
		printf("%d\n",len);
	}
	return 0;
}
