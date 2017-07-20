#include<cstdio>
#include<cstring>
#include<algorithm>
#define N 300010
#define int long long
#define P 1000000009
#define lc (u<<1)
#define rc (lc+1)
#define left lc,l,r
#define right rc,l,r
#define mid ((s[u]+e[u])>>1)
using namespace std;
int n,m;
int f[N][2],fs[N][2],a[N];
int s[N<<2],e[N<<2],sum[N<<2],laz[N<<2][2];
int summ[N<<2];
void init_fib()
{
	f[1][0]=f[2][1]=1;
	for(int i=3;i<=300000;i++) {f[i][0]=(f[i-1][0]+f[i-2][0])%P; f[i][1]=(f[i-1][1]+f[i-2][1])%P;}
	for(int i=1;i<=300000;i++) {fs[i][0]=(fs[i-1][0]+f[i][0])%P; fs[i][1]=(fs[i-1][1]+f[i][1])%P;}
}
inline void build_tre(int u,int l,int r)
{
	s[u]=l,e[u]=r;
	if(l==r) {sum[u]=a[l]; return;}
	build_tre(lc,l,mid); build_tre(rc,mid+1,r);
	sum[u]=sum[lc]+sum[rc]; return ;
}
inline int calc(int f1,int f2,int len) {return (f1*f[len][0]+f2*f[len][1])%P;}
void pd(int u)
{
	if(laz[u][0] && laz[u][1] && s[u]!=e[u])
	{
		int lenl=mid-s[u]+1,lenr=e[u]-mid;
		int tmp1=calc(laz[u][0],laz[u][1],lenl+1),tmp2=calc(laz[u][0],laz[u][1],lenl+2);
		sum[lc]=(sum[lc]+(laz[u][0]*fs[lenl][0])%P+(laz[u][1]*fs[lenl][1])%P)%P;
		sum[rc]=(sum[rc]+(tmp1*fs[lenr][0])%P+(tmp2*fs[lenr][1])%P)%P;
		laz[lc][0]=(laz[lc][0]+laz[u][0])%P;laz[lc][1]=(laz[lc][1]+laz[u][1])%P;
		laz[rc][0]=(laz[rc][0]+tmp1)%P;     laz[rc][1]=(laz[rc][1]+tmp2)%P;
		laz[u][0]=laz[u][1]=0;
		return;
	}
	return;
}
void update(int u,int l,int r)
{
	if(l<=s[u] && e[u]<=r)
	{
		int tmp1=calc(1,1,s[u]-l+1),tmp2=calc(1,1,s[u]-l+2),len=e[u]-s[u]+1;
		laz[u][0]=(laz[u][0]+tmp1)%P;laz[u][1]=(laz[u][1]+tmp2)%P; 
		sum[u]=(sum[u]+(tmp1*fs[len][0])%P+(tmp2*fs[len][1])%P)%P;
		return;
	}
	pd(u);
	if(l<=mid) update(left); if(r> mid) update(right);
	sum[u]=(sum[lc]+sum[rc])%P;
}
int query(int u,int l,int r)
{
	if(l<=s[u] && e[u]<=r) return sum[u];
	pd(u); int ans=0;
	if(l<=mid) ans=(ans+query(left))%P;
	if(r> mid) ans=(ans+query(right))%P;
	return ans;
}
main()
{
	int i;
	init_fib();
	scanf("%I64d %I64d",&n,&m);
	for(i=1;i<=n;i++) scanf("%I64d",&a[i]);
	build_tre(1,1,n);
	while(m--)
	{
		int type,l,r;
		scanf("%I64d %I64d %I64d",&type,&l,&r);
		if(type==1) {update(1,l,r);}
		else if(type==2) {printf("%I64d\n",query(1,l,r));}
	}
	return 0;
}
