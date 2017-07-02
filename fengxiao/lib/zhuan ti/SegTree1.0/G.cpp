#include<cstdio>
#include<cstring>
#include<iostream>
#define mp make_pair
#define F first
#define S second
#define ll long long
#define pii pair< ll, ll >
using namespace std;
int n,s;
ll a[100010];
struct P
{
    ll mi,ma,s,e;
}tre[1000010];
inline ll min(ll a,ll b){return a<b?a:b;}
void build_tre(int pos,int x,int y)
{
    if(x>y) return;
    tre[pos].s=x,tre[pos].e=y;
    if(x==y) {tre[pos].mi=a[x]; tre[pos].ma=a[x]; return;}
    int mid=( x + y ) / 2;
    build_tre( pos*2  ,x    ,mid);
    build_tre( pos*2+1,mid+1,y);
    tre[pos].mi=min(tre[pos*2].mi,tre[pos*2+1].mi);
    tre[pos].ma=max(tre[pos*2].ma,tre[pos*2+1].ma);
}
pii query(int pos,int l,int r)
{
    //printf("%d %d %d %d\n",pos,l,r,tre[pos].sum);
    if(l<=tre[pos].s&&tre[pos].e<=r) return mp(tre[pos].ma,tre[pos].mi);
        int mid=(tre[pos].s+tre[pos].e)/2;
        pii p1=mp(0,1000000),p2=mp(0,1000000);
        if(l<=mid) p1=query(pos*2  ,l  ,r);
        if(r> mid) p2=query(pos*2+1,l  ,r);    
    return mp(max(p1.F,p2.F),min(p1.S,p2.S));
}
int main()
{
    scanf("%d %d",&n,&s);
    for(int i=1;i<=n;i++)  scanf("%I64d",&a[i]);
    build_tre(1,1,n);
    while(s--)
    {
            int x,y;
            scanf("%d %d",&x,&y);
            pii p=query(1,x,y);
            printf("%I64d\n",p.F-p.S);
    }
    return 0;
}
