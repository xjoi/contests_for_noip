#include<cstdio>
#include<cstring>
#include<algorithm>
#define N 1010
#define lc (u<<1)
#define rc (lc+1)
#define left lc,l,r
#define right rc,l,r
#define mid ((s[u]+e[u])>>1)
#define sz (e[u]-s[u]+1)
#define mem(a) memset(a,0,sizeof(a))
using namespace std;
double key[N<<2],sum[N<<3],ans;
int s[N<<3],e[N<<3],cov[N<<3];
int n,m;
struct seg{double l,r,h; int v;} se[N<<1];
void clear() {mem(key); mem(sum); mem(s); mem(e); mem(cov); mem(se); ans=0;}
bool cmp(seg a,seg b) {return a.h<b.h;}
void build_tre(int u,int l,int r)
{
	s[u]=l; e[u]=r;
	if(l==r) return;
	build_tre(lc,l,mid);
	build_tre(rc,mid+1,r);
}
void pu(int u)
{
	if(cov[u]>1) sum[u]=key[e[u]+1]-key[s[u]];// printf("%lf %d %d\n",sum[u],e[u]+1,s[u]);}
	else if(s[u]==e[u]) sum[u]=0;
	else sum[u]=sum[lc]+sum[rc];
}
void pd(int u)
{
	cov[lc]+=cov[u];
	cov[rc]+=cov[u];
	cov[u]=0;
}
void update(int u,int l,int r,int v)
{
	if(s[u]==e[u]) {cov[u]+=v; pu(u); return;}
	if(mid>=l) update(left,v);
	if(mid< r) update(right,v);
	pu(u);
}
int main()
{
	double x1,y1,x2,y2;
	int i,T;
	scanf("%d",&T);
	while(T--)
	{
		clear();
		scanf("%d",&n);
		for(i=1;i<=n;i++)
		{
			scanf("%lf %lf %lf %lf",&x1,&y1,&x2,&y2);
			se[i]=(seg){x1,x2,y1,1}; se[i+n]=(seg){x1,x2,y2,-1};
			key[i]=x1; key[i+n]=x2;
		}
		sort(se+1,se+n*2+1,cmp);
		sort(key+1,key+n*2+1);
		m=unique(key+1,key+2*n+1)-key-1;
		//for(i=1;i<=n*2;i++) printf("%lf %lf %lf %d\n",se[i].l,se[i].r,se[i].h,se[i].v); printf("\n");
		build_tre(1,1,m);
		for(i=1;i<2*n;i++)
		{
			int l=lower_bound(key+1,key+m+1,se[i].l)-key;
            int r=lower_bound(key+1,key+m+1,se[i].r)-key;
			update(1,l,r-1,se[i].v);
			ans+=sum[1]*(se[i+1].h-se[i].h);
			//printf("%d %d %lf %lf %lf %lf\n",l,r,ans,sum[1],se[i].h,se[i+1].h);
			//for(int i=1;i<=20;i++) printf("%lf ",sum[i]); puts("");
		}
		printf("%.2lf\n",ans);
	}
	
	return 0;
}
