#include<cstdio>
#include<cstring>
#include<iostream>
#define int long long
#define N 1010
#define M 20010
#define INF 1000000000000000
using namespace std;
int n,m,L,s,e,x,y,c,lst=1,to[M],v[M],head[N],nxt[M],que[N*N],dis[N][2];
bool flag[M],used[N];
inline void adde(int x,int y,int c)
{
	if (!c) flag[lst+1]=c=1;
	to[++lst]=y;v[lst]=c;nxt[lst]=head[x];head[x]=lst;
}
void spfa(int s,int type)
{
	int i,h=0,t=1;
	for(i=0;i<n;i++) dis[i][type]=INF; dis[s][type]=0; que[1]=s;
	while(h<=t)
	{
		used[que[++h]]=0;
		for(i=head[que[h]] ; i ; i=nxt[i])
		{
			if(type && flag[i]) v[i]=v[i^1]=max(v[i],L-dis[to[i]][0]-dis[que[h]][1]);
			if(dis[to[i]][type]>dis[que[h]][type]+v[i])
			{
				dis[to[i]][type]=dis[que[h]][type]+v[i];
				if(!used[to[i]]) que[++t]=to[i],used[to[i]]=1;
			}
		}
	}
}
main()
{
	int i,x,y,c;
	scanf("%I64d %I64d %I64d %I64d %I64d",&n,&m,&L,&s,&e);
	for (i=1;i<=m;++i) scanf("%I64d%I64d%I64d",&x,&y,&c),adde(x,y,c),adde(y,x,c);
	spfa(e,0);
	spfa(s,1);
	if (dis[e][1]!=L) {puts("NO"); return 0;}
	puts("YES");
	for (i=3;i<=lst;i+=2) printf("%I64d %I64d %I64d\n",to[i],to[i^1],v[i]);
	return 0;
}
