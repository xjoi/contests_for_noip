//注意o2比o3快 deque会萎掉
#pragma GCC optimize("O2")
#include<bits/stdc++.h>
#define inf 124120210
#define maxn 10010
using namespace std;
int n,m,k;
struct Node{int to,w;};
struct POINT{int x,y;}p[maxn];
vector<Node> G[maxn];
int dis[maxn],book[maxn];

int spfa()
{
	queue<int> q;
	for(int i=1;i<=k;i++)
		dis[i]=inf;
	dis[1]=0;
	book[1]=1;
	q.push(1);
	while(!q.empty())
	{
		int now=q.front();q.pop();
		for(int i=1;i<=k;i++)if(i!=now)
		{
			int x=abs(p[i].x-p[now].x),y=abs(p[now].y-p[i].y);
			int val=inf;
			if(x+y==1)
				val=0;
			else if(x<=2||y<=2)
				val=1;
			if(dis[i]>dis[now]+val)
			{
				dis[i]=dis[now]+val;
				if(!book[i])
				{
					book[i]=1;
					q.push(i);
				}
			}
		}
		book[now]=0;	
 	}
	return dis[k]==inf?-1:dis[k];
}

int main()
{
	int ok=0;
	cin>>n>>m>>k;
	for(int i=1;i<=k;i++)
	{
		scanf("%I64d%I64d",&p[i].x,&p[i].y);
		if(p[i].x==n&&p[i].y==m) 
			ok=1;
	}
	if(!ok){p[++k].x=n+1;p[k].y=m+1;}
	/*for(int i=0;i<=k;i++)
		for(int j=0;j<G[i].size();j++)
			cout<<i<<"->"<<G[i][j].to<<" "<<G[i][j].w<<"\n";*/
	cout<<spfa()<<"\n";
	return 0;
}
