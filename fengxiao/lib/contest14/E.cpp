#include<cstdio>
#include<cstring>
#include<map>
#define N 100010
#define int long long
using namespace std;
int n,P,ans;
int head[N],nxt[N<<1],v[N<<1],to[N<<1],lst=1;
int inv[N],root,Maxn=1e9,sz[N];
map<int,int> key;
inline void exgcd(int a,int b,int &x,int &y){if(b==0) x=1,y=0 ; else exgcd(b,a%b,y,x),y-=a/b*x; return;}
inline void adde(int x,int y,int c){nxt[++lst]=head[x]; to[lst]=y; v[lst]=c; head[x]=lst;}
void get_sz(int u,int from)
{
	sz[u]=1;
	for(int i=head[u];i;i=nxt[i]) if(to[i]&&to[i]!=from) {get_sz(to[i],u); sz[u]+=sz[to[i]];}
}
void get_root(int u,int from,int siz)
{
	int maxn=siz-sz[u];
	for(int i=head[u];i;i=nxt[i]) if(to[i]&&to[i]!=from) {get_root(to[i],u,siz); maxn=max(maxn,sz[to[i]]);}
	if(maxn<Maxn) {Maxn=maxn;root=u;}
}
void get_d1(int u,int from,int num,int tim)
{
	key[num]++;
	for(int i=head[u];i;i=nxt[i])
		if(to[i]&&to[i]!=from)
			get_d1(to[i],u,(v[i]*tim+num)%P,tim*10%P);
}
int get_d2(int u,int from,int num,int dep)
{
	int sum=key[(-num*inv[dep]%P+P)%P];//逆元
	for(int i=head[u];i;i=nxt[i]) 
		if(to[i]&&to[i]!=from) 
			sum+=get_d2(to[i],u,(num*10+v[i])%P,dep+1);
	return sum;
}
int calc(int x,int v)
{
	key.clear();
	get_d1(x,0,v%P,v?10:1);
	return get_d2(x,0,v%P,v?2:1)-(v==0);
}
void dfs(int u)
{
	get_sz(u,0); Maxn=1e9;
	get_root(u,0,sz[u]);
	ans+=calc(root,0);
	for(int i=head[root];i;i=nxt[i]) 
		if(to[i]) 
		{
			to[i^1]=0;
			ans-=calc(to[i],v[i]);
			dfs(to[i]);
		}
}
main()
{
	int tmp,iv,i,x,y,c;
	scanf("%I64d %I64d",&n,&P);
	exgcd(10,P,iv,tmp);
	inv[1]=1;
	for(i=2;i<=n;i++) inv[i]=(inv[i-1]*iv)%P;
	for(i=1;i<n;i++) scanf("%I64d %I64d %I64d",&x,&y,&c),adde(x+1,y+1,c),adde(y+1,x+1,c);
	dfs(1);
	printf("%I64d",ans);
	return 0;
}
