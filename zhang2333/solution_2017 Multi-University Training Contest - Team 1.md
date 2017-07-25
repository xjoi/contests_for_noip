## 1003 Colorful Tree
### Problem description
> 给出一棵点染色的树(|V|<=2e5),定义一条路径的权值为路径上不同的颜色数..</br>
  求所有路径(无向)的权值和..</br>

### Time Limit: 3s
### Solution
> 树分治?树DP?..然而我并不会..</br>
  简谈我的思路:定义每个点的贡献值为经过该点并且不经过以该点为根的子树中颜色与该点相同的点的路径数..</br>
  经yy得答案就是所有点的贡献和..</br>
  每个点的贡献怎么求呢?..用数据结构嘛..</br>
  一遍dfs由深到浅(由孩子到祖先)依次做每个点..</br>
  每个点的状态(用线段树表示)可以由其所有孩子合并然后修改一个叶子节点得到..</br>
  That's all..</br>

### Code
```cpp
#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
#define mod 100000000000000007
#define ll long long
using namespace std;
ll n,ans;
ll c[520233];

struct R{
    ll to,nex;
}r[520233];
ll rrr,hea[200100];

void A(ll u,ll v){
    r[++rrr]=(R){v,hea[u]};
    hea[u]=rrr;
    r[++rrr]=(R){u,hea[v]};
    hea[v]=rrr;
}

ll aliv[201000],size[201000];

struct LT{
    ll lc,rc,sz;
}tr[10000000],nil;
ll cnt=0,root[201000];

ll NEW(){
    tr[++cnt]=nil;
    return cnt;
}

void onion(ll p1,ll p2,ll l,ll r){
    tr[p1].sz+=tr[p2].sz;
    if (l==r) return;
    ll mid=(l+r)>>1;
    if (tr[p2].lc){
        if (!tr[p1].lc){
            tr[p1].lc=tr[p2].lc;
        }else{
            onion(tr[p1].lc,tr[p2].lc,l,mid);
        }
    }
    if (tr[p2].rc){
        if (!tr[p1].rc){
            tr[p1].rc=tr[p2].rc;
        }else{
            onion(tr[p1].rc,tr[p2].rc,mid+1,r);
        }
    }
}

void CG(ll p,ll l,ll r,ll w,ll v){
    if (l==r){
        tr[p].sz=v;
        return;
    }
    ll mid=(l+r)>>1;
    if (w<=mid){
        if (!tr[p].lc) tr[p].lc=NEW();
        CG(tr[p].lc,l,mid,w,v);
    }else{
        if (!tr[p].rc) tr[p].rc=NEW();
        CG(tr[p].rc,mid+1,r,w,v);
    }
}

ll QUE(ll p,ll l,ll r,ll w){
    if (p<=0) return 0;
    if (l==r){
        return tr[p].sz;
    }
    ll mid=(l+r)>>1;
    if (w<=mid){
        return QUE(tr[p].lc,l,mid,w);
    }else{
        return QUE(tr[p].rc,mid+1,r,w);
    }
}

vector<ll>vec[201000];
void dfs(ll x,ll f){
    vec[x].clear();
    root[x]=NEW();
    size[x]=1;
    ll y,t;
    for (ll i=hea[x];i>0;i=r[i].nex){
        y=r[i].to;
        if (y==f) continue;
        dfs(y,x);
        size[x]+=size[y];
        t=size[y]-QUE(root[y],1,n,c[x]);
        vec[x].push_back(t);
        onion(root[x],root[y],1,n);
    }
    CG(root[x],1,n,c[x],size[x]);
    ans=(ans+(ll)aliv[c[x]]-1)%mod;
    ll tot=0;
    for (ll i=0;i<vec[x].size();i++){
        ans=(ans+tot*vec[x][i])%mod;
        tot+=vec[x][i];
    }
    aliv[c[x]]=aliv[c[x]]-tot-1;
    ans=(ans+=tot*(ll)aliv[c[x]])%mod;
}

int main(){
    //freopen("a.txt","r",stdin);
    ll T=0,u,v;
    nil.lc=nil.rc=nil.sz=0;
    while (scanf("%lld",&n)==1){
        for (ll i=1;i<=n;i++){
            scanf("%lld",&c[i]);
            aliv[i]=n;
        }
        memset(hea,0,sizeof(hea));
        rrr=1;
        for (ll i=1;i<n;i++){
            scanf("%lld%lld",&u,&v);
            A(u,v);
        }
        ans=0;
        cnt=0;
        dfs(1,0);
        printf("Case #%d: ",++T);
        printf("%lld\n",ans);
    }
    return 0;
}
```
