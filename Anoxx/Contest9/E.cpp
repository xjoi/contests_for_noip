#include<cstdio>
#include<algorithm>
#define root -1000000001,1000000001,1
#define lson l,m
#define rson m+1,r
#define ll long long
using namespace std;
struct node{
	ll cnt,sum,ans;
	int ls,rs;
	node(){
		cnt=sum=ans=ls=rs=0;
	}
}a[6000000],zero;
int n,j,p,x[100010],type,m,l,r,tot=1;
node merge(node c,node a,node b){
	c.sum=a.sum+b.sum;
	c.cnt=a.cnt+b.cnt;
	c.ans=a.ans+b.ans+a.cnt*b.sum-b.cnt*a.sum;
	return c;
}
void update(int val,int z,int l,int r,int rt){
	if(val<l||val>r)return;
	if(l==r){
		a[rt].ans=0;a[rt].cnt+=z;a[rt].sum+=z*val;return;
	}
	if(a[rt].ls==0)a[rt].ls=++tot;
	if(a[rt].rs==0)a[rt].rs=++tot;
	int m=(l+r)>>1;
	if(m>=val)update(val,z,lson,a[rt].ls);
	if(m<val)update(val,z,rson,a[rt].rs);
	a[rt]=merge(a[rt],a[a[rt].ls],a[a[rt].rs]);
	//printf("%d %d %d %d %d\n",a[rt].ls,a[rt].rs,a[rt].ans,a[rt].cnt,a[rt].sum);
}
node query(int x,int y,int l,int r,int rt){
	if(y<l||x>r)return zero;
	if(x<=l&&r<=y)return a[rt];
	int m=(l+r)>>1;node p,q;
	if(m>=x)p=query(x,y,lson,a[rt].ls);
	if(m<y)q=query(x,y,rson,a[rt].rs);
	return merge(a[rt],p,q);
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&x[i]);
		update(x[i],1,root);
		//printf("%d %d\n",a[1].rs,a[1].ls);
	}
	scanf("%d",&m);
	for(int i=1;i<=m;i++){
		scanf("%d",&type);
		if(type==1){
			scanf("%d%d",&j,&p);
			update(x[j],-1,root);x[j]+=p;update(x[j],1,root);
		}
		else{
			scanf("%d%d",&l,&r);
			printf("%lld\n",query(l,r,root).ans);
		}
	}
}
