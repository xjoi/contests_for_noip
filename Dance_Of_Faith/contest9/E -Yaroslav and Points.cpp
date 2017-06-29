#include<cstdio>
#define int long long
#define lson L[t],l,mid
#define rson R[t],mid+1,r
const int oo=1000000000,N=5000010;
struct XY{int cnt,sum,ans;}T[N];
int a[N],L[N],R[N],tot=1;
XY updata(XY L,XY R){
	XY T;T.cnt=L.cnt+R.cnt;T.sum=L.sum+R.sum;
	T.ans=L.ans+R.ans+L.cnt*R.sum-L.sum*R.cnt;return T;
}
void modify(int &t,int l,int r,int x,int v){
	if (!t) t=++tot;if (l==r) {T[t].cnt+=v;T[t].sum+=(x-oo)*v;return;}
	int mid=(l+r)>>1;
	if (x<=mid) modify(lson,x,v);else modify(rson,x,v);
	T[t]=updata(T[L[t]],T[R[t]]);
}
XY query(int t,int l,int r,int ll,int rr){
	if (!t) return T[0];if (l==ll&&r==rr) return T[t];
	int mid=(l+r)>>1;
	if (rr<=mid) return query(lson,ll,rr);
	if (ll> mid) return query(rson,ll,rr);
	return updata(query(lson,ll,mid),query(rson,mid+1,rr));
}
main(){
	int n,m,x,y,z,RR=1;scanf("%lld",&n);
	for (int i=1;i<=n;++i) scanf("%lld",&x),a[i]=x+oo,modify(RR,0,oo*2,a[i],1);
	scanf("%lld",&m);
	while (m--){
		scanf("%lld%lld%lld",&z,&x,&y);
		if (z==1){
			modify(RR,0,oo*2,a[x],-1);a[x]+=y;modify(RR,0,oo*2,a[x],1);
		}else printf("%lld\n",query(RR,0,oo*2,x+oo,y+oo).ans);
	}return 0;
}
