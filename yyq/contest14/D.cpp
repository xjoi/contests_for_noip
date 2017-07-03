#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const LL INF=1e15;
const int N=1000+10;
struct node{
    int u,v,next;
    LL w;
}E[N*30];
int n,m,s,t,top;
LL L;
int head[N];
LL dis[N];
bool vis[N];
vector<node> V;
void add(int u,int v,LL w)
{
    E[top].u=u;
    E[top].v=v;
    E[top].w=w;
    E[top].next=head[u];
    head[u]=top++;
}
struct Node{
    int id;
    LL d;
    Node(){}
    Node(int id,int d):
        id(id),d(d){}
    bool friend operator < (Node a,Node b)
	{
        return a.d>b.d;
    }
};
void dij()
{
    for(int i=0;i<N;i++)
    {
		dis[i]=INF;
		vis[i]=false;
	}
	dis[s] = 0;
    priority_queue<Node> q;
    q.push(Node(s,0));
    while(!q.empty())
	{
        Node u=q.top();
        q.pop();
        if(vis[u.id])
			continue;
        vis[u.id]=true;
        for(int i=head[u.id];i!=-1;i=E[i].next)
		{
            int v=E[i].v;
            if(!vis[v]&&dis[v]>dis[u.id]+E[i].w)
			{
                dis[v]=dis[u.id]+E[i].w;
                q.push(Node(v,dis[v]));
            }
        }
    }
}
int main()
{
    memset(head,-1,sizeof head);
    scanf("%d%d%I64d%d%d",&n,&m,&L,&s,&t);
    for(int i=1;i<=m;i++)
	{
        int u,v;
        LL w;
        scanf("%d%d%I64d",&u,&v,&w);
        if(w!=0)
		{
            add(u,v,w);
            add(v,u,w);
        }
        else
		{
            node edge;
            edge.u=u;
			edge.v=v;
			edge.w=w;
			edge.next=-1;
            V.push_back(edge);
        }
    }
    dij();
    if(dis[t]<L)
	{
        puts("NO");
        return 0;
    }
    else if(dis[t]==L)
	{
        puts("YES");
        for(int i=0;i<top;i+=2)
            printf("%d %d %I64d\n",E[i].u,E[i].v,E[i].w);
        for(int i=0;i<V.size();i++)
            printf("%d %d %I64d\n",V[i].u,V[i].v,INF);
        return 0;
    }
    int pos=-1;
    for(int i=0;i<V.size();i++)
	{
        add(V[i].u,V[i].v,1);
        add(V[i].v,V[i].u,1);
        dij();
        if(dis[t]<=L)
		{
            E[top-2].w+=L-dis[t];
            E[top-1].w+=L-dis[t];
            pos=i;
            break;
        }
    }
    if(pos==-1)
	{
        puts("NO");
        return 0;
    }
    puts("YES");
    for(int i=0;i<top;i+=2)
        printf("%d %d %I64d\n",E[i].u,E[i].v,E[i].w);
    for(int i=pos+1;i<V.size();i++)
        printf("%d %d %I64d\n",V[i].u,V[i].v,INF);
    return 0;
}
