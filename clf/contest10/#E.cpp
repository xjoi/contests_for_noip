#include<cstdio>
#include<iostream>
#include<algorithm>
#include<string>
#include<map>
using namespace std;
const int N=200005;
int tab[N*2],l[N],u[N],type[N];
struct seg_tree {
	int rec[N*6];
	inline void update(int x,int l,int r) {
		if(l==r) return;
		rec[x<<1]=max(rec[x<<1],rec[x]);
		rec[x<<1|1]=max(rec[x<<1|1],rec[x]);
	}
	inline void Insert(int x,int l,int r,int a,int b,int val) {
		if(l==a&&r==b) {
			rec[x]=max(rec[x],val);
			return;
		}
		update(x,l,r);
		int mid=(l+r)>>1;
		if(b<=mid) Insert(x<<1,l,mid,a,b,val);
		else if(a>mid) Insert(x<<1|1,mid+1,r,a,b,val);
		else Insert(x<<1,l,mid,a,mid,val),Insert(x<<1|1,mid+1,r,mid+1,b,val);
	}
	inline int Query(int x,int l,int r,int pos) {
		if(l==r) return rec[x];
		update(x,l,r);
		int mid=(l+r)>>1;
		if(pos<=mid) return Query(x<<1,l,mid,pos);
		else return Query(x<<1|1,mid+1,r,pos);
	}
}vertical,horizon;
int main() {
	int n,q;
	string s;
	scanf("%d%d",&n,&q);
	for(int i=1;i<=q;i++) {
		scanf("%d%d",&l[i],&u[i]);
		cin>>s;
		if(s[0]=='L') type[i]=1;
		else type[i]=2;
		tab[i*2-1]=l[i];
		tab[i*2]=u[i];
	}
	int rr=q*2,p,L,U,P;
	sort(tab+1,tab+rr+1);
	for(int i=1;i<=q;i++) {
		L=std::lower_bound(tab+1,tab+rr+1,l[i])-tab;
		U=std::lower_bound(tab+1,tab+rr+1,u[i])-tab;
		if(type[i]==1) {//L
			p=vertical.Query(1,1,rr,U);
			printf("%d\n",l[i]-p);
			P=std::lower_bound(tab+1,tab+rr+1,p)-tab;
			horizon.Insert(1,1,rr,P,L,u[i]);
			vertical.Insert(1,1,rr,U,U,l[i]);
		} else {//U
			p=horizon.Query(1,1,rr,L);
			printf("%d\n",u[i]-p);
			P=std::lower_bound(tab+1,tab+rr+1,p)-tab;
			vertical.Insert(1,1,rr,P,U,l[i]);
			horizon.Insert(1,1,rr,L,L,u[i]);
		}
	}
	return 0;
}
