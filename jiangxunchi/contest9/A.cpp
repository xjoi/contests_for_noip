#include<cstdio>
const int N=100001;
struct{long long l,r,val,tag;}a[400001];
void buildTree(long long p,long long l,long long r){
	a[p].l=l; a[p].r=r; if(l==r) scanf("%I64d",&a[p].val);
	else{
		long long mid=(l+r)/2; buildTree(p*2,l,mid); buildTree(p*2+1,mid+1,r);
		a[p].val=a[p*2].val+a[p*2+1].val;
	}
}
void pushDown(long long p){
	a[p*2].tag+=a[p].tag; a[p*2].val+=(a[p*2].r-a[p*2].l+1)*a[p].tag;
	a[p*2+1].tag+=a[p].tag; a[p*2+1].val+=(a[p*2+1].r-a[p*2+1].l+1)*a[p].tag;
	a[p].tag=0;
}
void change(long long p,long long l,long long r,long long v){
	if(a[p].l==l&&a[p].r==r){
		a[p].tag+=v; a[p].val+=(r-l+1)*v; return;
	}
	pushDown(p); long long mid=(a[p].l+a[p].r)/2;
	if(r<=mid) change(p*2,l,r,v); else if(l>mid) change(p*2+1,l,r,v);
	else{
		change(p*2,l,mid,v); change(p*2+1,mid+1,r,v);
	}
	a[p].val=a[p*2].val+a[p*2+1].val;
}
long long query(long long p,long long l,long long r){
	if(a[p].l==l&&a[p].r==r) return a[p].val;
	pushDown(p); long long mid=(a[p].l+a[p].r)/2;
	if(r<=mid) return query(p*2,l,r); if(l>mid) return query(p*2+1,l,r);
	return query(p*2,l,mid)+query(p*2+1,mid+1,r);
}
long long L[N],R[N],v[N],f[N];
int main(){
	long long n,m,k; scanf("%I64d%I64d%I64d",&n,&m,&k);
	buildTree(1,1,n);
	for(int i=1;i<=m;++i) scanf("%I64d%I64d%I64d",&L[i],&R[i],&v[i]);
	for(int i=1;i<=k;++i){
		long long l,r; scanf("%I64d%I64d",&l,&r);
		++f[l]; --f[r+1];
	}
	long long sum=0;
	for(int i=1;i<=m;++i){
		sum+=f[i]; change(1,L[i],R[i],sum*v[i]);
	}
	for(int i=1;i<=n;++i) printf("%I64d ",query(1,i,i));
	return 0;
}
