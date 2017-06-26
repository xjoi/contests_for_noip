#include<cstdio>
#include<cstring>
typedef long long ll;
const ll P=1000000007,N=101;
ll min(ll a,ll b){return a<b?a:b;}
struct Mat{
	ll n,m; ll a[N][N];
	Mat(){
		memset(a,0,sizeof a);
	}
	void print(){
	}
};
Mat operator*(const Mat &a,const Mat &b){
	Mat ans; ans.n=a.n; ans.m=b.m;
	for(ll i=1;i<=ans.n;++i) for(ll j=1;j<=ans.m;++j){
		ans.a[i][j]=0;
		for(ll k=1;k<=a.m;++k) (ans.a[i][j]+=a.a[i][k]*b.a[k][j])%=P;
	}
	return ans;
}
Mat pow(Mat a,ll b){
	Mat ans; ans.n=a.n; ans.m=a.m;
	for(ll i=1;i<=ans.n;++i) ans.a[i][i]=1;
	for (;b;b/=2,a=a*a) if(b%2) ans=ans*a;
	return ans;
}
int main(){
	ll n,k; scanf("%lld%lld",&n,&k);
	Mat a; a.n=1; a.m=1; a.a[1][1]=1;
	Mat b; b.n=16; b.m=16;
	for(ll i=1;i<=16;++i) b.a[i][i]=b.a[i][i-1]=b.a[i][i+1]=1;
	for(ll i=1;i<=n;++i){
		ll l,r,p; scanf("%lld%lld%lld",&l,&r,&p); ++p;
		r=min(r,k);
		a.n=p; b.n=p; b.m=p;
		a=a*pow(b,r-l); if(r==k) break;
	}
	printf("%lld",a.a[1][1]); return 0;
}
