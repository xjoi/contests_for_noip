#include<cstdio>
#include<cstring>
#include<algorithm>
#include<map>
#define ll long long
#define INF 1e9
#define N 1000010
using namespace std;
struct T{ll num,sum,ans; };
map<ll,ll> key,_key;
ll s[N],e[N],num[N],sum[N],ans[N],a[N],ask[N][3],app[N],tmp[N],cnt=0;
int n,m;
void build_tre(int u,ll l,ll r)
{
	s[u]=l; e[u]=r;
	//printf("%d %I64d %I64d\n",u,l,r);
	int mid=(l+r)/2;
	if(l==r) return;
	build_tre(u<<1,l,mid);
	build_tre(u<<1|1,mid+1,r);
}
void pu(int u,int lc,int rc)
{
	num[u]=num[lc]+num[rc];
	sum[u]=sum[lc]+sum[rc];
	ans[u]=sum[rc]*num[lc]-sum[lc]*num[rc]+ans[lc]+ans[rc];
}
void update(int u,ll x,int v)
{
	if(s[u]>x || e[u]<x) return;
	if(s[u]==e[u] && s[u]==x) {num[u]+=v; sum[u]+=key[x]*v; return;}
	update(u<<1,x,v); update(u<<1|1,x,v);
	pu(u,u<<1,u<<1|1);
}
T work(T a,T b)
{
	T tmp;
	tmp.num=a.num+b.num;
	tmp.sum=a.sum+b.sum;
	tmp.ans=b.sum*a.num-a.sum*b.num+a.ans+b.ans;
	return tmp;
}
T query(int u,ll l,ll r)
{
	T tmp={num[u],sum[u],ans[u]};
	if(l<=s[u] && e[u]<=r) return tmp;
	int mid=(s[u]+e[u])/2;
	if(mid>=r) return query(u<<1,l,r);
	if(mid<l)return query(u<<1|1,l,r);
	return work(query(u<<1,l,r),query(u<<1|1,l,r));
}
int main()
{
	int i;
	scanf("%d",&n);
	for(i=1;i<=n;i++) {scanf("%I64d",&a[i]); app[++cnt]=tmp[i]=a[i];}
	scanf("%d",&m);
	for(i=1;i<=m;i++)
	{
		scanf("%I64d %I64d %I64d",&ask[i][0],&ask[i][1],&ask[i][2]);
		if(ask[i][0]==1)
		{
			app[++cnt]=tmp[ask[i][1]]+ask[i][2];
			tmp[ask[i][1]]+=ask[i][2];
		}
		if(ask[i][0]==2)
		{
			app[++cnt]=ask[i][1];app[++cnt]=ask[i][2];
		}
	}
	sort(app+1,app+cnt+1);
	for(i=1;i<=n;i++) tmp[i]=a[i];
	for(i=1;i<=cnt;i++) if(app[i]!=app[i-1] || i==1 ) key[i]=app[i],_key[app[i]]=i;
	for(i=1;i<=m;i++)
		if(ask[i][0]==1) {tmp[ask[i][1]]+=ask[i][2]; ask[i][2]=_key[tmp[ask[i][1]]];}
		else ask[i][1]=_key[ask[i][1]],ask[i][2]=_key[ask[i][2]];
	for(i=1;i<=n;i++) a[i]=_key[a[i]];
	build_tre(1,1,cnt); 
	for(i=1;i<=n;i++) update(1,a[i],1);
	for(i=1;i<=m;i++)
	{
		if(ask[i][0]==1) 
		{
			update(1,a[ask[i][1]],-1); //printf("!%I64d ",key[a[ask[i][1]]]);
			update(1,ask[i][2],1);  a[ask[i][1]]=ask[i][2];  //printf("%I64d!",key[ask[i][2]]);
		}
		else
		printf("%I64d\n",query(1,ask[i][1],ask[i][2]).ans);
			//printf("?%I64d %I64d?",ask[i][1],ask[i][2]);}
	}
	/*for(i=1;i<=n;i++) printf("%I64d ",a[i]); printf("\n");
	for(i=1;i<=m;i++)
	{
		printf("%I64d %I64d %I64d\n",ask[i][0],ask[i][1],ask[i][2]);
	}*/
	return 0;
}
