#include<cstdio>
#include<cstring>
#include<cmath>
#define N 100010
#define ll long long
using namespace std;
int n,s,cnt[N<<2];
ll a[N<<2];
struct P {ll sum,s,e;}tre[N<<2];
inline void swap(int &a,int &b) {int t=a;a=b;b=t;}
inline void clear() {memset(a,0,sizeof(a)); memset(tre,0,sizeof(tre));memset(cnt,0,sizeof(cnt));}
void build_tre(int pos,int x,int y)
{
    if(x>y) return;
    tre[pos].s=x,tre[pos].e=y;
    if(x==y) {tre[pos].sum=a[x]; return;}
    int mid=(x+y)/2;
    if(mid>=x) build_tre(pos*2,x,mid);
	if(mid<y)  build_tre(pos*2+1,mid+1,y);
    tre[pos].sum=tre[pos*2].sum+tre[pos*2+1].sum;
}
void update(int pos,int l,int r)
{
	if(cnt[pos]>=7) return;
	if(l<=tre[pos].s && tre[pos].e<=r) cnt[pos]++;
    if(tre[pos].s==tre[pos].e) {tre[pos].sum=sqrt(tre[pos].sum); return;}
    int mid=(tre[pos].s+tre[pos].e)/2;
    if(l<=mid) update(pos*2  ,l,r); 
    if(r> mid) update(pos*2+1,l,r);
    tre[pos].sum=tre[pos*2].sum+tre[pos*2+1].sum;
    if(cnt[pos*2]>=7 && cnt[pos*2+1]>=7) cnt[pos]=7;
}
ll query(int pos,int l,int r)
{
    ll ans=0;
    if(l<=tre[pos].s&&tre[pos].e<=r) return tre[pos].sum;
    int mid=(tre[pos].s+tre[pos].e)/2;
    if(l<=mid) ans+=query(pos*2  ,l,r);
    if(r> mid) ans+=query(pos*2+1,l,r);
    return ans;
}
int main()
{
	int t=0;
    while(scanf("%d",&n)!=EOF)
    {
    	printf("Case #%d:\n",++t); clear();
	    for(int i=1;i<=n;i++)  scanf("%I64d",&a[i]);
	    build_tre(1,1,n);
	    scanf("%d",&s);
	    while(s--)
	    {
	        int type,x,y;
	        scanf("%d %d %d",&type,&x,&y);
	        if(x>y) swap(x,y);
	        if(type==0) update(1,x,y);
	        else if(type==1) printf("%I64d\n",query(1,x,y));
	    }
	    puts("");
	}
    return 0;
}
