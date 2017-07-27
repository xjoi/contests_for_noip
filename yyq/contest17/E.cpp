#include <bits/stdc++.h>
#define use_ios ios::sync_with_stdio(false);
#define use_tie cin.tie(0);
#define LL long long
using namespace std;
const int MAXN=1500000;
const int wuyiqi=1e9+9;
LL bas=276601605;
LL q1=691504013;
LL q2=308495997;
LL mul1[MAXN],mul2[MAXN];
int c[MAXN];
LL s[MAXN];
struct Node {
	LL a,b,sum;
} node[MAXN];
int n, k;
void init(int m) {
	mul1[0]=mul2[0]=1;
	for (int i=1;i<=m;i++) {
		mul1[i]=mul1[i-1]*q1%wuyiqi;
		mul2[i]=mul2[i-1]*q2%wuyiqi;
	}
}
void build(int o,int l,int r) {
	node[o].a=node[o].b=node[o].sum=0;
	if(l==r)
		return;
	int m=(l+r)>>1;
	build(o<<1,l,m);
	build((o<<1)+1,m+1,r);
}
void push_down(int o,int l,int r) {
	LL aa=node[o].a,bb=node[o].b;
	if(!aa&&!bb)
		return;
	int lc=o<<1, rc=(o<<1)|1,mid=(l+r)>>1;
	int len1=mid-l+1,len2=r-mid;
	node[lc].a=(node[lc].a+aa)%wuyiqi;
	node[lc].b=(node[lc].b+bb)%wuyiqi;
 	node[lc].sum=(node[lc].sum+aa*(mul1[len1+2]-mul1[2]))%wuyiqi;
 	node[lc].sum=(node[lc].sum-bb*(mul2[len1+2]-mul2[2]))%wuyiqi;
 	node[rc].a=(node[rc].a+aa*mul1[len1])%wuyiqi;
 	node[rc].b=(node[rc].b+bb*mul2[len1])%wuyiqi;
 	node[rc].sum=(node[rc].sum+aa*mul1[len1]%wuyiqi*(mul1[len2+2]-mul1[2])%wuyiqi)%wuyiqi;
 	node[rc].sum=(node[rc].sum-bb*mul2[len1]%wuyiqi*(mul2[len2+2]-mul2[2])%wuyiqi)%wuyiqi;
 	node[o].a=node[o].b=0;
}
void push_up(int o) {
	node[o].sum=(node[o<<1].sum+node[(o<<1)|1].sum)%wuyiqi;
}
LL query(int o,int l,int r,int ql,int qr) {
	if(l==ql&&r==qr)
		return node[o].sum;
	push_down(o,l,r);
	int mid=(l+r)>>1;
	if (qr<=mid)
		return query(o<<1,l,mid,ql,qr);
	else if(ql>mid)
		return query((o<<1)|1,mid+1,r,ql,qr);
	else 
		return (query(o<<1,l,mid,ql,mid)+query((o<<1)|1,mid+1,r,mid+1,qr))%wuyiqi;
}
void update(int o,int l,int r,int ql,int qr,LL x,LL y) {
	if (l==ql&&r==qr) {
		node[o].a=(node[o].a+x)%wuyiqi;
		node[o].b=(node[o].b+y)%wuyiqi;
		node[o].sum=(node[o].sum+x*(mul1[r-l+3]-mul1[2]))%wuyiqi;
 		node[o].sum=(node[o].sum-y*(mul2[r-l+3]-mul2[2]))%wuyiqi;
 		return;
	}
	push_down(o,l,r);
	int mid=(l+r)>>1;
	if (qr<=mid)
		update(o<<1,l,mid,ql,qr,x,y);
	else if (ql>mid) 
		update((o<<1)|1,mid+1,r,ql,qr,x,y);
	else {
		int len = mid - ql + 1;
		update(o<<1,l,mid,ql,mid,x,y);
		update((o<<1)|1,mid+1,r,mid+1,qr,x*mul1[len]%wuyiqi,y*mul2[len]%wuyiqi);
	}
	push_up(o);
}
int main()
{
	use_ios
	use_tie
	cin>>n>>k;
	for(int i=1;i<=n;i++) {
		cin>>c[i];
		s[i]=s[i-1]+c[i];
	}
	init(301000);
	build(1,1,n);
	for(int i=1;i<=k;i++) {
		int op,l,r;
		cin>>op>>l>>r;
		if(op==1) 
			update(1,1,n,l,r,1,1);
		else {
			LL ans=(bas*query(1,1,n,l,r)%wuyiqi+s[r]-s[l-1])%wuyiqi;
			if(ans<0)
				ans+=wuyiqi;
			cout<<ans<<endl;
		}
	}
	return 0;
}
