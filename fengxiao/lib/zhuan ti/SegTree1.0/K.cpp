#include<iostream>  
#include<algorithm>  
#include<cstring>  
#include<cstdio>  
using namespace std;  
#define N 200005  
#define P 10007  
#define lc (u<<1)  
#define rc (u<<1|1)  
typedef long long ll;  
int n,m;  
struct point {int s,e,add,tim,sum[4];}tre[N<<2];  
void pu(int u) {for(int i=1;i<=3;++i) tre[u].sum[i]=(tre[lc].sum[i]+tre[rc].sum[i])%P;}
void calc(int u,int tim,int add)
{  
    int len=tre[u].e-tre[u].s+1;  
    tre[u].sum[1]=tre[u].sum[1]*tim%P;
    tre[u].sum[2]=tre[u].sum[2]*tim%P*tim%P;
    tre[u].sum[3]=tre[u].sum[3]*tim%P*tim%P*tim%P;
    tre[u].tim=(tre[u].tim*tim)%P;
    tre[u].add=((tre[u].add*tim)% P+add)%P;
      
    tre[u].sum[3]=(tre[u].sum[3] + 3*add%P*add%P *tre[u].sum[1]%P)%P;  
    tre[u].sum[3]=(tre[u].sum[3] + 3*add%P*tre[u].sum[2]%P)%P ;  
    tre[u].sum[3]=(tre[u].sum[3] + len * add%P *add %P *add%P)%P;  
      
    tre[u].sum[2]=(tre[u].sum[2] + 2*add%P *tre[u].sum[1] %P )%P;  
    tre[u].sum[2]=(tre[u].sum[2] + len*add%P*add%P)%P;  
  
    tre[u].sum[1]=(tre[u].sum[1]+len*add%P)%P;
}  
void pd(int u)  
{  
    if(tre[u].s==tre[u].e){return;}  
    calc(lc,tre[u].tim,tre[u].add);  
    calc(rc,tre[u].tim,tre[u].add);  
    tre[u].tim = 1;  
    tre[u].add = 0;  
}  
void build_tre(int u,int l,int r)  
{  
    tre[u].s = l,tre[u].e = r;  
    tre[u].tim = 1,tre[u].add = 0;tre[u].sum[1] = tre[u].sum[2] = tre[u].sum[3] = 0;  
    if(l==r) return; 
    int mid=(l+r)>>1;  
    build_tre(lc,l,mid);  
    build_tre(rc,mid+1,r);  
}  
void update(int u,int s,int e,int tim,int add)  
{  
    if(s<=tre[u].s&&tre[u].e<=e){calc(u,tim,add); return;}  
    pd(u);
	int mid=(tre[u].s+tre[u].e)>>1;
    if(mid>=s) update(lc,s,e,tim,add);
    if(mid< e) update(rc,s,e,tim,add);
    pu(u);  
}  
int query(int u,int s,int e,int p)  
{  
    if(s<=tre[u].s&&e>=tre[u].e) return tre[u].sum[p]; 
    pd(u);
	int mid=(tre[u].s+tre[u].e)>>1,ans=0;
    if(mid>=s) ans=(ans+query(lc,s,e,p))%P;
    if(mid< e) ans=(ans+query(rc,s,e,p))%P;
	return ans;
}  
int main()
{
    int i,type,x,y,c;  
    while(scanf("%d %d",&n,&m)==2 && n && m )  
    {  
        build_tre(1,1,n);
        for(i=1;i<=m;i++)
		{
          scanf("%d %d %d %d",&type,&x,&y,&c);  
            if(type==1) update(1,x,y,1,c);
            else if(type==2) update(1,x,y,c,0);  
            else if(type == 3) update(1,x,y,0,c);
            else  printf("%d\n",query(1,x,y,c)%P);  
        }  
    }  
    return 0;  
}  
