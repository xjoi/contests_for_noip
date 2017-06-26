#include<cstdio>
#include<algorithm>
#include<queue>
using namespace std;
typedef long long ll;
const int N=400001;
struct data{int type; ll l,r; int lb;}a[N];
bool operator<(const data &a,const data &b){
	return a.l==b.l?a.type<b.type:a.l<b.l;
}
struct node{ll v;int d;}; priority_queue<node> Q;
bool operator<(const node &a,const node &b){return a.v>b.v;}
int ans[N];
int main(){
	int n,m,cnt=0; scanf("%d%d",&n,&m); ll prel,prer;
	scanf("%lld%lld",&prel,&prer);
	for(int i=1;i<n;++i){
		ll l,r; scanf("%lld%lld",&l,&r);
		a[++cnt]={0,l-prer,r-prel,i}; prel=l; prer=r;
	}
	for(int i=1;i<=m;++i){
		ll x; scanf("%lld",&x);
		a[++cnt]={1,x,0,i};
	}
	sort(a+1,a+cnt+1); int cntt=0;
	for(int i=1;i<=cnt;++i) if(a[i].type==0) Q.push({a[i].r,a[i].lb});
	else{
		for(;!Q.empty()&&Q.top().v<a[i].l;Q.pop());
		if(Q.empty()) continue;
		ans[Q.top().d]=a[i].lb; Q.pop(); ++cntt;
	}
	if(cntt!=n-1){
		printf("No"); return 0;
	}
	printf("Yes\n");
	for(int i=1;i<n;++i) printf("%d ",ans[i]); return 0;
}
