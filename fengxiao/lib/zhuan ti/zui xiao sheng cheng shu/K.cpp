#include<cstdio>
#include<cstring>
#include<algorithm>
#define N 1010
using namespace std;
struct Edge{int s,e,v;} e[N*N];
int fat[N],n,m,tmp[N];
bool vis[N*N],used[N*N];
bool cmp(Edge a,Edge b) {return a.v<b.v;}
int father(int x) {if(fat[x]!=x) fat[x]=father(fat[x]); return fat[x];}
int kru()
{
	int k=0,ans=0;
	for(int i=1;i<=n;i++) fat[i]=i;
	for(int i=1;i<=m;i++)
	{
		int fx=father(e[i].s),fy=father(e[i].e);
		if(!vis[i] && fx!=fy)
		{
			fat[fx]=fy;
			used[i]=1;
			ans+=e[i].v;
			k++;
		}
		if(k==n-1) break;
	}
	if(k<n-1) return 1000000000;
	return ans;
}
int main()
{
	int i,T;
	scanf("%d",&T);
	while(T--)
	{
		int ans=0,cnt=0;  bool flag=0; memset(used,0,sizeof(used));
		scanf("%d %d",&n,&m);
		for(i=1;i<=m;i++) scanf("%d %d %d",&e[i].s,&e[i].e,&e[i].v);
		sort(e+1,e+m+1,cmp);
		ans=kru();
		for(i=1;i<=m;i++) if(used[i]) tmp[++cnt]=i;
		for(i=1;i<=cnt;i++)
		{
			vis[tmp[i]]=1;
			//printf("%d ",kru());
			if(ans==kru()) flag=1;
			vis[tmp[i]]=0;
			if(flag) break;
		}
		if(flag) printf("Not Unique!\n");
		else printf("%d\n",ans);
		
	}
	
	return 0;
}
