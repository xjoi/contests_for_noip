#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
typedef int ll;
struct data {
    ll type,len,from,to,lb;
} a[600001];
bool operator<(const data &a,const data &b) {
    return a.len==b.len?a.type>b.type:a.len<b.len;
}
ll fa[600001];
ll sz[600001],val[600001];
ll ans=0;
bool vis[600001];
ll getf(ll x) {
    return fa[x]==x?x:fa[x]=getf(fa[x]);
}
void merge(ll x,ll y) {
    ans-=(sz[x]-1)*sz[x];
    ans-=(sz[y]-1)*sz[y];
    sz[y]+=sz[x];
    fa[x]=y;
    ans+=(sz[y]-1)*sz[y];
}
int main() {
    ll n,m;
    for(; scanf("%d%d",&n,&m)!=EOF;) {
        memset(vis,0,sizeof vis);
        for(ll i=1; i<=m; ++i) {
            scanf("%d%d%d",&a[i].from,&a[i].to,&a[i].len);
            a[i].type=1;
            ++a[i].from;
            ++a[i].to;
        }
        ll p;
        scanf("%d",&p);
        for(ll i=m+1; i<=m+p; ++i) {
            scanf("%d",&a[i].len);
            a[i].lb=i-m;
            a[i].type=2;
        }
        sort(a+1,a+m+p+1);
        for(ll i=1; i<=n; ++i) fa[i]=i,sz[i]=1;
        ans=0;
        for(ll i=1; i<=m+p; ++i) if(a[i].type==1) {
                ll x1=getf(a[i].from),x2=getf(a[i].to);
                if(x1!=x2) merge(x1,x2);
            } else val[a[i].lb]=ans;
        for(ll i=1; i<=p; ++i) printf("%d\n",ans-val[i]);
    }
    return 0;
}
