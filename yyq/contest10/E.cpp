#include<bits/stdc++.h>
using namespace std;
const int maxn=200010;
int X[maxn];
int N,M;
struct node
{
    int x,y;
    char d[5];
}op[maxn];
bool vis[maxn];
struct IntervalTree
{
    int up[maxn<<2];
    int down[maxn<<2];
    int set1[maxn<<2];
    int set2[maxn<<2];
    void build(int o,int l,int r)
    {
        up[o]=down[o]=0;
        set1[o]=set2[o]=0;
        if(l==r)
			return;
        int mid=(l+r)>>1;
        build(o<<1,l,mid);
        build(o<<1|1,mid+1,r);
    }
    void update(int o,int l,int r,int q1,int q2,int x,bool f)
    {
        if(q1<=l&&r<=q2)
        {
            if(f&&x>up[o])
				set1[o]=x,up[o]=x;
            else if(!f&&x>down[o])
				set2[o]=x,down[o]=x;
            return ;
        }
        pushdown(o,f);
        int mid=(l+r)>>1;
        if(q1<=mid)
			update(o<<1,l,mid,q1,q2,x,f);
        if(q2>mid)
			update(o<<1|1,mid+1,r,q1,q2,x,f);
    }
    void pushdown(int o,bool f)
    {
        if(f)
        {
            if(set1[o])
            {
                if(set1[o]>set1[o<<1])
                    set1[o<<1]=set1[o],up[o<<1]=set1[o];
                if(set1[o]>set1[o<<1|1])
                    set1[o<<1|1]=set1[o],up[o<<1|1]=set1[o];
                set1[o]=0;
            }
        }
        else
        {
            if(set2[o])
            {
                if(set2[o]>set2[o<<1])
                    set2[o<<1]=set2[o],down[o<<1]=set2[o];
                if(set2[o]>set2[o<<1|1])
                    set2[o<<1|1]=set2[o],down[o<<1|1]=set2[o];
                set2[o]=0;
            }
        }
    }
    int query(int o,int l,int r,int pos,bool f)
    {
        if(l==r)
			return f?up[o]:down[o];
        pushdown(o,f);
        int mid=(l+r)>>1;
        if(pos<=mid)
			return query(o<<1,l,mid,pos,f);
        return query(o<<1|1,mid+1,r,pos,f);
    }
}tree;
int main()
{
    scanf("%d%d",&M,&N);
    for(int i=1;i<=N;i++)
    {
        scanf("%d%d%s",&op[i].y,&op[i].x,op[i].d);
        X[i]=op[i].x;
    }
    sort(X+1,X+1+N);
    tree.build(1,1,N);
    for(int i=1;i<=N;i++)
    {
        int tmp=lower_bound(X+1,X+1+N,op[i].x)-X;
        if(vis[tmp])
		{
			printf("0\n");
			continue;
		}
        vis[tmp]=1;
        if(op[i].d[0]=='U')
        {
            int pos=tree.query(1,1,N,tmp,1);
            int tmp1=lower_bound(X+1,X+1+N,pos)-X;
            if(pos==0)
				tmp1=0;
            if(tmp1+1<=tmp)
				tree.update(1,1,N,tmp1+1,tmp,op[i].y,0);
            printf("%d\n",op[i].x-pos);
        }
        else
        {
            int pos=tree.query(1,1,N,tmp,0);
            int tmp1=lower_bound(X+1,X+1+N,1+M-pos)-X;
            if(pos==0)
				tmp1=N+1;
            if(tmp1-1>=tmp)
				tree.update(1,1,N,tmp,tmp1-1,op[i].x,1);
            printf("%d\n",op[i].y-pos);
        }
    }
    return 0;
}
