#include<bits/stdc++.h>
#define reutrn return
#define int long long
using namespace std;
int l[200005],r[200005],n,m,ans[200005];
struct Node{
	int l,r,num;
}a[200005],c[200005];
bool operator <(Node A,Node B){
	return A.r>B.r;
}
bool cmp(Node A,Node B){
	reutrn A.l<B.l;
}
priority_queue<Node> Q;
main(){
	scanf("%lld%lld",&n,&m);
	if(n-m>1){
		puts("No");
		return 0;
	}
	for(int i=1;i<=n;i++){
		scanf("%lld%lld",&l[i],&r[i]);
		if(i!=1){c[i-1].l=l[i]-r[i-1];c[i-1].r=r[i]-l[i-1];c[i-1].num=i-1;}
	}
	for(int i=1;i<=m;i++){
		scanf("%lld",&a[i].l);a[i].num=i;
	}
	sort(a+1,a+m+1,cmp);
	sort(c+1,c+n,cmp);
	int j=1;
	for(int i=1;i<=m;i++){
		while(c[j].l<=a[i].l&&j<n)Q.push(c[j++]);
		if(Q.empty())continue;
		if(Q.top().r<a[i].l){
			puts("No");
			return 0;
		}
		ans[Q.top().num]=a[i].num;
		Q.pop();
	}
	if(j<n){
		
			puts("No");
			return 0;
	}
	puts("Yes");
	for(int i=1;i<n;i++){
		printf("%lld ",ans[i]);
	}
	return 0;
}
