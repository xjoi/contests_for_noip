#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
#define N 50010
#define lc (u<<1)
#define rc (u<<1|1)
#define left u<<1,l,r
#define right u<<1|1,l,r
#define sz (e[u]-s[u]+1)
#define mid ((s[u]+e[u])>>1)
#define mem(a) memset(a,0,sizeof(a));
using namespace std;
int n,m,L,R,C;
int s[N<<2],e[N<<2],sum[N<<2];
void clear() {mem(s); mem(e); mem(sum);}
void pu(int u) {sum[u]=sum[lc]+sum[rc];}
void pd(int u)
{
	if(sum[u])
	{
		sum[lc]=e[lc]-s[lc]+1;
		sum[rc]=e[rc]-s[rc]+1;
	}
	else sum[lc]=sum[rc]=0;
}
void build_tre(int u,int l,int r)  
{  
    s[u]=l,e[u]=r; sum[u]=0;
    if(l==r) return; 
    int mi=(l+r)>>1;
    build_tre(lc,l,mi);
    build_tre(rc,mi+1,r);
}
int l,r;
void update(int u)
{  
	if(C<=0) return;
    if(l<=s[u]&&e[u]<=r && (sum[u]==sz || sum[u]==0))
	{
		if(sum[u]==sz) { r+=sz; if(r>n) r=n+1;}
		else 
		{
			sum[u]=sz; C-=sz;
			if(L<0) L=s[u];
			R=e[u];
		}
		return;
	}  
    if(!sum[u] || sum[u]==sz) pd(u);
    if(mid>=l) update(lc);
    if(mid< r) update(rc);
    pu(u);
}

int query(int u,int l,int r)  
{  
	int ans=0;
    if(l<=s[u]&&e[u]<=r) {int tmp=sum[u]; sum[u]=0; return tmp;}
    if(!sum[u] || sum[u]==sz) pd(u);
    if(mid>=l) ans=ans+query(left);
    if(mid< r) ans=ans+query(right);
	pu(u);
	return ans;
}
void test()
{
	for(int i=1;i<=30;i++) if(s[i]) printf("%d %d %d\n",s[i],e[i],sum[i]);
}
int main()
{
    int i,type,x,y,T;
	scanf("%d",&T);
    while(T--)
	{
		clear();
		scanf("%d %d",&n,&m);
        build_tre(1,1,n);
        for(i=1;i<=m;i++)
		{
			scanf("%d %d %d",&type,&x,&y);
            if(type==1)
			{
				L=R=-1; C=y; l=x+1; r=x+y;
				update(1);
				if(L!=-1) printf("%d %d\n",L-1,R-1);
				else puts("Can not put any one.");
			}
			if(type==2) printf("%d\n",query(1,x+1,y+1));
			//test();
        }
		puts("");
    }  
    return 0;  
}  
