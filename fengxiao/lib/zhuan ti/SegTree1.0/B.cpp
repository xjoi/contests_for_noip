#include<cstdio>
#include<cstring>
#include<iostream>
#define N 200010
using namespace std;
int n,m,s[N<<2],e[N<<2],ans[N<<2],a[N];
inline int max(int a,int b) {return a>b?a:b;}
void build_tre(int u,int l,int r)
{
    s[u]=l,e[u]=r;
    if(l==r) {ans[u]=a[l]; return;}
    int mid=(l+r)/2;
    build_tre(u<<1,l,mid);
    build_tre(u<<1|1,mid+1,r);
    ans[u]=max(ans[u<<1],ans[u<<1|1]);
}
void update(int u,int pos,int v)
{
    if(s[u]>pos || e[u]<pos) return;
    if(s[u]==pos && pos==e[u]) {if(ans[u]<v) ans[u]=v; return;}
    update(u<<1,pos,v); update(u<<1|1,pos,v);
    ans[u]=max(ans[u<<1],ans[u<<1|1]);
}
int query(int u,int l,int r)
{
    if(s[u]>r || e[u]<l) return 0;
    if(l<=s[u] && e[u]<=r) return ans[u];
    return max(query(u<<1,l,r),query(u<<1|1,l,r));
}
int main()
{
    int i,j;
    while(scanf("%d %d",&n,&m)==2)
    {
	    for(i=1;i<=n;i++) scanf("%d",&a[i]); 
	    build_tre(1,1,n);
	    for(i=1;i<=m;i++)
	    {
	        int x,y; char type;
	        cin>>type>>x>>y;
	        if(type=='U') update(1,x,y);
	        else if(type=='Q') printf("%d\n",query(1,x,y));
	    }
	}
    return 0;
}
