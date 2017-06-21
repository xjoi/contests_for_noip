#include <bits/stdc++.h>
using namespace std;
#define ll long long
struct edge {
    int x,y,w;
    ll s;
}E[500010];
int n,m,res,tot=0,k;
int fa[10010],siz[10010],tmp[10010];
ll sum[10010],ans[10010];

bool cmp(edge a,edge b) {
    return a.w<b.w;
}

int find(int x) {
    if(fa[x]!=x) fa[x]=find(fa[x]);
    return fa[x];
}

int main() {
    while(~(scanf("%d%d",&n,&m))) {
        for(int i=1;i<=m;i++) {
            scanf("%d%d%d",&E[i].x,&E[i].y,&E[i].w);
            E[i].s=0;
        }
        sort(E+1,E+1+m,cmp);
        for(int i=1;i<=n;i++) {
            fa[i]=i;
            siz[i]=1;
        }
        tot=0;
        for(int i=1;i<=m;i++) {
            int fx=find(E[i].x),fy=find(E[i].y);
            if(fx!=fy) {
                sum[tot]=E[i].s=(ll)(siz[fx]*siz[fy]*2);
                tmp[tot]=E[i].w;
                tot++;
                siz[fx]+=siz[fy];
                fa[fy]=fx;
            }
        }
        ans[tot]=0;
        for(int i=tot-1;i>=0;i--) {
            ans[i]=ans[i+1]+sum[i];
        }
        scanf("%d",&k);
        for(int t,l,r,i=1;i<=k;i++) {
            scanf("%d",&t);
            l=0;
            r=tot-1;
            res=-1;
            while(l<=r) {
                int mid=(l+r+1)>>1;
                if(tmp[mid]>=t) {
                    res=mid;
                    l=mid+1;
                } else {
                    r=mid-1;
                }
            }
            if(res==-1) puts("0");
            else printf("%lld\n",ans[res]);
        }
    }
    return 0;
}