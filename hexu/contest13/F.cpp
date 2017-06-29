#include<algorithm>
#include<cmath>
#include<cstring>
#include<cstdio>
using namespace std;
struct NODE
{
	int left,right,id,k;
}a[1000010];
int n,m,cnt = 0;
int color[1000010];
struct node{int toit,next;}road[1000005];
int list[1000010], ans[1000010],S[1000010],C[1000010],dfs_color[1000010];
int LEFT[1000010],RIGHT[1000010],dep = 0, blo;
bool cmp(NODE x, NODE y) 
{
    return x.right/blo==y.right/blo ? x.left<y.left: x.right/blo<y.right/blo;
}
void read(int &x) 
{
	#define CH getchar() 
	char ch; x=0; 
	for (ch=CH; ch<'0'||ch>'9'; ch=CH);
	for (;ch>='0'&&ch<='9';x=x*10+ch-48,ch=CH);
}
void add(int u,int v)
{
	road[++cnt].toit = v;  road[cnt] . next = list[u] ; list[u] = cnt;
	road[++cnt].toit = u;  road[cnt] . next = list[v] ; list[v] = cnt;
 }
void dfs(int x, int fa)
{
	LEFT[x] = ++dep;  dfs_color[dep] = color [x]; 
	for (int i=list[x];i;i=road[i].next) if (fa!=road[i].toit) dfs(road[i].toit,x) ;
	RIGHT[x] = dep;  	
}
int main()
{
	read(n); read(m);  blo=sqrt(n);
	for (int i=1; i<=n; i++) read(color[i]);
	int x,y;
	for (int i=1; i<n; i++) { read(x),read(y);add(x,y); }
	dfs(1,-1);
	for (int i=1; i<=m; i++) read(x) , read(y) , a[i]. left=LEFT[x] , a[i].right = RIGHT[x], a[i].k = y ,a[i] . id = i;
	sort(a+1,a+1+m,cmp);
	int LL=1, RR=0;
	for (int i=1; i<=m; i++) 
	{
		while (RR<a[i].right) ++C[++S[dfs_color[++RR]]];
		while (LL<a[i].left)  --C[S[dfs_color[LL++]]--];
		while (LL>a[i].left)  ++C[++S[dfs_color[--LL]]];
		while (RR>a[i].right) --C[S[dfs_color[RR--]]--];
		ans[a[i].id] = C[a[i].k] ;
	}
	for (int i=1; i<=m; i++) printf("%d\n",ans[i]);	
}
