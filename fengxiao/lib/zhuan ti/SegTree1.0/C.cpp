#include<cstdio>
#include<cstring>
#define ll long long
using namespace std;
int n,s;
ll a[100010];
struct P
{
    ll sum,s,e,add;
}tre[1000010];
void build_tre(int pos,int x,int y)
{
    if(x>y) return;
    tre[pos].s=x,tre[pos].e=y,tre[pos].add=0;
    if(x==y) {tre[pos].sum=a[x]; return;}
    int mid=( x + y ) / 2;
    build_tre( pos*2  ,x    ,mid);
    build_tre( pos*2+1,mid+1,y);
    tre[pos].sum=tre[pos*2].sum+tre[pos*2+1].sum;
}

void pd(int pos)
{
    if(tre[pos].add)
    {
        tre[pos*2].add+=tre[pos].add;
        tre[pos*2+1].add+=tre[pos].add;
        tre[pos*2].sum+=tre[pos].add*(tre[pos*2].e-tre[pos*2].s+1);
        tre[pos*2+1].sum+=tre[pos].add*(tre[pos*2+1].e-tre[pos*2+1].s+1);
        tre[pos].add=0;
    }
}
void update(int pos,int l,int r,int v)
{
    if(l<=tre[pos].s && tre[pos].e<=r) {tre[pos].add+=v; tre[pos].sum+=v*(tre[pos].e-tre[pos].s+1);}
    else
    {
        int mid=(tre[pos].s+tre[pos].e)/2;
        pd(pos);
        if(l<=mid) update(pos*2  ,l  ,r  ,v); 
        if(r> mid) update(pos*2+1,l  ,r  ,v);
        tre[pos].sum=tre[pos*2].sum+tre[pos*2+1].sum;
    }
}

ll _sum=0; 
void query(int pos,int l,int r)
{
    //printf("%d %d %d %d\n",pos,l,r,tre[pos].sum);
    if(l<=tre[pos].s&&tre[pos].e<=r) _sum+=tre[pos].sum;
    else
    {
        pd(pos);
        int mid=(tre[pos].s+tre[pos].e)/2;
        if(l<=mid) query(pos*2  ,l  ,r);
        if(r> mid) query(pos*2+1,l  ,r);    
    }
}
int main()
{
    scanf("%d %d",&n,&s);
    for(int i=1;i<=n;i++)  scanf("%lld",&a[i]);
    build_tre(1,1,n);
    while(s--)
    {
        char type[20];
        scanf("%s",type);
        if(type[0]=='C')
        {
            int x,y,k;
            scanf("%d %d %d",&x,&y,&k);
            update(1,x,y,k);
        }
        else if(type[0]=='Q')
        {
            int x,y;
            _sum=0;
            scanf("%d %d",&x,&y);
            query(1,x,y);
            printf("%lld\n",_sum);
        }
    }
    return 0;
}
