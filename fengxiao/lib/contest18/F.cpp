#include<bits/stdc++.h>
#define N 100010
#define int long long
using namespace std;
int n,m,K,ans;
struct E {int x,y,c;} e[N];
int fat[N];
int head[N],nxt[N<<1],to[N<<1],v[N<<1],lst=0;
int dis[N],pa[N]; bool used[N]; queue<int> que;
inline int father(int x) {if(x!=fat[x]) fat[x]=father(fat[x]); return fat[x];}
inline void adde(int x,int y,int c) {nxt[++lst]=head[x]; to[lst]=y; v[lst]=c; head[x]=lst;} 
bool cmp(E a,E b) {return a.c<b.c;}
main()
{
	memset(dis,63,sizeof(dis));
	int i,k=0,x,y,c;
	scanf("%I64d %I64d",&n,&m);
	for(i=1;i<=n;i++) fat[i]=i;
	for(i=1;i<=m;i++) {scanf("%I64d %I64d %I64d",&x,&y,&c); adde(x,y,c); adde(y,x,c);}
	scanf("%I64d",&K);
	for(i=1;i<=K;i++) {scanf("%I64d",&x); que.push(x); used[x]=1; dis[x]=0; pa[x]=x;}
	while(!que.empty())
	{
		int p=que.front(); que.pop();
		for(i=head[p];i;i=nxt[i])
			if(dis[to[i]]>dis[p]+v[i])
			{
				dis[to[i]]=dis[p]+v[i];
				pa[to[i]]=pa[p];
				if(!used[to[i]]) {used[to[i]]=1; que.push(to[i]);}
			}
		used[p]=0;
	}
	for(i=1;i<=lst;i+=2) e[(i+1)/2]=(E){pa[to[i]],pa[to[i+1]],dis[to[i]]+dis[to[i+1]]+v[i]};
	//for(i=1;i<=m;i++) printf("%d ",e[i].c); puts("");
	sort(e+1,e+m+1,cmp);
	for(i=1;i<=m;i++)
	{
		int fx=father(e[i].x),fy=father(e[i].y);
		//printf("%d %d %d %d\n",e[i].x,e[i].y,fx,fy);
		if(fx!=fy)
		{
			fat[fx]=fy;
			ans+=e[i].c;
			k++; if(k==K-1) break;
		}
	}
	ans+=dis[1];
	printf("%I64d",ans);
	return 0;
}
