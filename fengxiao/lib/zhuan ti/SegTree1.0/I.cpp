#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#define N 50010
using namespace std;
struct P {int l,r,ll,rl,ml;}tre[N<<2];
void build_tre(int u,int l,int r)
{
    tre[u].l=l;tre[u].r=r;tre[u].ll=tre[u].rl=tre[u].ml=r-l+1;
    if(l==r) return;
    int mid=(l+r)>>1;
    build_tre(u<<1,l,mid);
    build_tre(u<<1|1,mid+1,r);
}
void update(int u,int t,int v)
{
    if(tre[u].l==tre[u].r)
    {
        if(v==1) tre[u].ll=tre[u].rl=tre[u].ml=1;
        else tre[u].ll=tre[u].rl=tre[u].ml=0;
        return;
    }
    int mid=(tre[u].l+tre[u].r)>>1;
    if(t<=mid) update(u<<1,t,v);
    else       update(u<<1|1,t,v);
    tre[u].ll=tre[u<<1].ll;
    tre[u].rl=tre[u<<1|1].rl;
    tre[u].ml=max(tre[u<<1].ml,tre[u<<1|1].ml);
    tre[u].ml=max(tre[u].ml,tre[u<<1].rl+tre[u<<1|1].ll);
    if(tre[u<<1].ll==tre[u<<1].r-tre[u<<1].l+1)
		tre[u].ll+=tre[u<<1|1].ll;
    if(tre[u<<1|1].rl==tre[u<<1|1].r-tre[u<<1|1].l+1) 
		tre[u].rl+=tre[u<<1].rl;
}
int query(int u,int pos)
{
    if(tre[u].l==tre[u].r||tre[u].ml==0||tre[u].ml==tre[u].r-tre[u].l+1) return tre[u].ml;
    int mid=(tre[u].l+tre[u].r)>>1;
    if(pos<=mid)
    {
        if(pos>=tre[u<<1].r-tre[u<<1].rl+1) return query(u<<1,pos)+query((u<<1)|1,mid+1);
        else return query(u<<1,pos);
    }
    else
    {
        if(pos<=tre[(u<<1)|1].l+tre[(u<<1)|1].ll-1)
           return query((u<<1)|1,pos)+query(u<<1,mid);
        else return query((u<<1)|1,pos);
    }
}
int que[N];
int top;
int main()
{
    int n,m;
    char ch[20];
    int x;
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        build_tre(1,1,n); top=0;
        while(m--)
        {
            scanf("%s",ch);
            if(ch[0]=='D')
            {
                scanf("%d",&x);
                que[top++]=x;
                update(1,x,0);
            }
            else if(ch[0]=='Q')
            {
                scanf("%d",&x);
                printf("%d\n",query(1,x));
            }
            else if(ch[0]=='R' && x>0)
                {
                    x=que[--top];
                    update(1,x,1);
                }
        }
    }
    return 0;
}
