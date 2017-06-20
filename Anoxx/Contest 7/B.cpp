#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
struct edge {
    int u,v,w;
} e[600000];
int n,m,fa[20000],b[600000],num[20000],p,t;
long long a[600000],sum[600000];
bool cmp(edge a,edge b) {
    return a.w<b.w;
}
int ask(int x) {
    return x==fa[x]?x:fa[x]=ask(fa[x]);
}
int main() {
    while(scanf("%d%d",&n,&m)==2) {
        for(int i=1; i<=m; i++)scanf("%d%d%d",&e[i].u,&e[i].v,&e[i].w);
        sort(e+1,e+m+1,cmp);
        int l=n-1,i=0;
        for(int i=0; i<n; i++)fa[i]=i,num[i]=1;
        memset(a,0,sizeof(a));
        memset(sum,0,sizeof(sum));
        for(int i=1; i<=m; i++)b[i]=e[i].w;
        while(l) {
            i++;
            int x=ask(e[i].u),y=ask(e[i].v);
            if(x!=y) {
                a[i]=2*num[x]*num[y];
                fa[x]=y;
                num[y]+=num[x];
                l--;
            }
        }
        for(int i=m; i>=0; i--)sum[i]=sum[i+1]+a[i];
        scanf("%d",&p);
        for(int i=1; i<=p; i++) {
            scanf("%d",&t);
            int r=lower_bound(b+1,b+m+1,t)-b-1;
            ;
            printf("%lld\n",sum[r+1]);
        }
    }
}
