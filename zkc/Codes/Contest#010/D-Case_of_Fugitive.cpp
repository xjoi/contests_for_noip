#include <bits/stdc++.h>
using namespace std;
#define ll long long

int n,m;
struct lands {
    ll l,r;
    int idx;
} a[200010];
struct bridge {
    ll len;
    int idx;
    bool operator < (const bridge& x) const {
        if(len!=x.len) return len<x.len;
        return idx<x.idx;
    }
};
set<bridge> b;
set<bridge>::iterator sit;
ll ans[200010];


bool cmp(lands x,lands y) {
    if(x.r!=y.r) return x.r<y.r;
    return x.l>y.l;
}

int main() {
    scanf("%d%d",&n,&m);
    ll j=0,k=0,tmp1,tmp2;
    for(int i=1;i<=n;i++) {
        tmp1=j;tmp2=k;
        scanf("%lld%lld",&j,&k);
        if(i==1) continue;
        a[i-1].l=j-tmp2;
        a[i-1].r=k-tmp1;
        a[i-1].idx=i-1;
    }
    sort(a+1,a+n,cmp);
    for(int i=1;i<=m;i++) {
        bridge nw;
        scanf("%lld",&nw.len);
        nw.idx=i;
        b.insert(nw);
    }
    for(int i=1;i<n;i++) {
        if(b.size()==0) {
            puts("No");
            return 0;
        }
        sit=b.lower_bound((bridge){a[i].l,0});
        if(sit==b.end()||(*sit).len>a[i].r) {
            puts("No");
            return 0;
        }
        ans[a[i].idx]=(*sit).idx;
        b.erase(*sit);
    }
    puts("Yes");
    for(int i=1;i<n;i++) {
        printf("%lld ",ans[i]);
    }
    return 0;
}