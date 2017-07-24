#include<bits/stdc++.h>
#define N 100010 
#define pb(a) push_back(a)
#define lc (u<<1) 
#define rc (lc+1)
#define left lc,l,r
#define right rc,l,r
#define mid ((tre[u].s+tre[u].e)>>1)
using namespace std;  
struct Set_tree{int s,e;vector<int>v;}tre[N<<2];
struct Point {int x,y;}p[N];  
bool cmp(Point a,Point b) {return a.x!=b.x?a.x<b.x:a.y<b.y;}
int n,x[N],y[N];
int a[9],b[9];
void bulid_tre(int u,int l,int r)
{  
    tre[u].s=l;tre[u].e=r;
    for(int i=l;i<=r;i++) tre[u].v.pb(p[i].y);  
    sort(tre[u].v.begin(),tre[u].v.end());  
    if(l==r) return;
    bulid_tre(lc,l,mid); bulid_tre(rc,mid+1,r);  
}  
int query(int u,int l,int r,int v)
{  
    if(l<=tre[u].s&&tre[u].e<=r)
	{  
        if(tre[u].v.size()==0 || tre[u].v[0]>v) return 0;
        if(tre[u].v.back()<=v) return tre[u].v.size();  
        return upper_bound(tre[u].v.begin(),tre[u].v.end(),v)-tre[u].v.begin();  
    }
    int ans=0;
    if(l<=mid) ans+=query(left,v); 
    if(r> mid) ans+=query(right,v);  
    return ans;
}  
bool ok()
{  
    int x1=a[0]+a[1]+a[2]-1;  
    int x2=x1+a[3]+a[4]+a[5];  
    int y1=a[0]+a[3]+a[6]-1;
    int y2=y1+a[1]+a[4]+a[7];
    if(x1+1>=n||x[x1]==x[x1+1]) return false;  
    if(x2+1>=n||x[x2]==x[x2+1]) return false;  
    if(y1+1>=n||y[y1]==y[y1+1]) return false;  
    if(y2+1>=n||y[y2]==y[y2+1]) return false;  
    if(query(1,0,x1,y[y1])!=a[0]) return false; 
    if(query(1,0,x1,y[y2])!=a[0]+a[1]) return false; 
    if(query(1,x1+1,x2,y[y1])!=a[3]) return false;  
    if(query(1,x1+1,x2,y[y2])!=a[3]+a[4]) return false;  
    printf("%.10lf %.10lf\n%.10lf %.10lf\n",x[x1]+0.5,x[x2]+0.5,y[y1]+0.5,y[y2]+0.5);
    return true;   
}  
int main()
{  
    scanf("%d",&n); 
    for(int i=0;i<n;i++){scanf("%d %d",&p[i].x,&p[i].y); x[i]=p[i].x;y[i]=p[i].y;}  
    sort(p,p+n,cmp); sort(x,x+n); sort(y,y+n);  
    bulid_tre(1,0,n-1);  
    for(int i=0;i<9;i++) scanf("%d",&a[i]); sort(a,a+9);
    do if(ok()) return 0; while(next_permutation(a,a+9));
    puts("-1");
    return 0;  
}
