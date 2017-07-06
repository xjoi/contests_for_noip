#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#define pb push_back
#define N 100010
using namespace std;
int n,s,q,c[N],fa[N],are[N],cnt=0,l[N],r[N],key[N],_key[N],ans[N];
struct query {int x,k,pos;} qu[N];
int head[N],nxt[N<<1],to[N<<1],lst=0;
bool cmp(query a,query b) {return l[a.x]/s==l[b.x]/s ? r[a.x]<r[b.x] :l[a.x]<l[b.x]; }
inline void adde(int x,int y) {nxt[++lst]=head[x]; to[lst]=y; head[x]=lst;}
void dfs(int u,int from)
{
	l[u]=++cnt;
	are[cnt]=c[u];
	for(int i=head[u]; i ;i=nxt[i]) if(to[i]!=from) dfs(to[i],u);
	r[u]=cnt;
}
void solve()
{
	int s=0,e=0;
	for(int i=1;i<=q;i++)
	{
		while(s<l[qu[i].x]) {_key[key[are[s]]]--; key[are[s]]--; s++;}
		while(s>l[qu[i].x]) {s--; key[are[s]]++; _key[key[are[s]]]++; }
		while(e<r[qu[i].x]) {e++; key[are[e]]++; _key[key[are[e]]]++; }
		while(e>r[qu[i].x]) { _key[key[are[e]]]--; key[are[e]]--; e--;}
		ans[qu[i].pos]=_key[qu[i].k];
	}
}
int main()
{
    int i,x,y;
    scanf("%d %d",&n,&q); s=sqrt(n);
    for(i=1;i<=n;i++) scanf("%d",&c[i]);
    for(i=1;i<n;i++)  {scanf("%d %d",&x,&y); adde(x,y); adde(y,x);}
    for(i=1;i<=q;i++) {scanf("%d %d",&qu[i].x,&qu[i].k); qu[i].pos=i;}
	dfs(1,0);
	sort(qu+1,qu+q+1,cmp);
	solve();
	for(i=1;i<=q;i++) printf("%d\n",ans[i]); 
    return 0;
}
