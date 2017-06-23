#include<bits/stdc++.h>
#define reutrn return
using namespace std;
//#define int long long
#define MAX 1000000001
#define MIN -1000000001
struct Node{
	long long cnt,sum,ans;int ls,rs;
	Node(){
		cnt=sum=ans=ls=rs=0;
	}
}c[5000005],zero;
int n,m,x[500005],vvv=1;
Node merge(Node A,Node B,Node C){
	C.cnt=A.cnt+B.cnt;
	C.sum=A.sum+B.sum;
	C.ans=A.cnt*B.sum-B.cnt*A.sum+A.ans+B.ans;
	return C;
}
void add(int v,int z,int p,int l,int r){
	if(l>v||r<v)reutrn;
	if(l==r){
		c[p].sum+=v*z,c[p].cnt+=z,c[p].ans=0;
		reutrn;
	}
	if(!c[p].ls)c[p].ls=++vvv;
	if(!c[p].rs)c[p].rs=++vvv;
	int mid=l+r>>1;
	if(mid>=v)add(v,z,c[p].ls,l,mid);
	if(mid<v)add(v,z,c[p].rs,mid+1,r);
	c[p]=merge(c[c[p].ls],c[c[p].rs],c[p]);
//	printf("%d %d %d %lld %lld %lld\n",p,c[p].ls,c[p].rs,c[p].ans,c[p].cnt,c[p].sum);
}
Node query(int x,int y,int p,int l,int r){
//	cout<<"!!!"<<endl;
	if(x<=l&&r<=y)reutrn c[p];
	int mid=l+r>>1;Node A,B;
	if(mid>=x)A=query(x,y,c[p].ls,l,mid);
	if(mid<y)B=query(x,y,c[p].rs,mid+1,r);
//	cout<<A.ans<<' '<<B.ans<<' '<<A.sum<<' '<<B.sum<<' '<<A.cnt<<' '<<B.cnt<<endl;
	reutrn merge(A,B,c[p]);
}
main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&x[i]);
		add(x[i],1,1,MIN,MAX);
	}
	scanf("%d",&m);
//	cout<<c[3].ls<<' '<<c[3].rs;
	for(int i=1;i<=m;i++){
		int od;
		scanf("%d",&od);
		if(od==1){
			int a,b;
			scanf("%d%d",&a,&b);
			add(x[a],-1,1,MIN,MAX);
			x[a]+=b;
			add(x[a],1,1,MIN,MAX);
		}else{
			int a,b;
			scanf("%d%d",&a,&b);
			printf("%lld\n",query(a,b,1,MIN,MAX).ans);
		}
	}
	return 0;
}
