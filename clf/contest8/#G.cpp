/*第一次接触仙人掌，我想我注释写得该是很多了*/
#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;
const int N=2515;
const int M=50000;
const int INF=2e7;
struct node{int to,nxt;}edge[M];
int cnt=0,head[N],size[N],f[N][N][3][3],up[N],vis[N];
inline void add(int x,int y) {
	edge[++cnt].to=y;
	edge[cnt].nxt=head[x];
	head[x]=cnt;
}
inline void link(int x,int y) {add(x,y);add(y,x);}
void dp(int x,int fa) {
	vis[x]=1;
	size[x]=1;
	f[x][0][0][0]=f[x][1][1][0]=0;
	f[x][0][2][0]=1;
	int v,mx;
	for(int w=head[x];w;w=edge[w].nxt) {
		v=edge[w].to;
		if(v==fa||vis[v]==2) continue;
		if(vis[v]==0) {
			dp(v,x);
			size[x]+=size[v];
			if(up[v]&&up[v]!=x) up[x]=up[v];//then x is on a cycle of the cactus, up[x] represents the shallowest node on the cycle
			for(int i=size[x];i>=0;i--) { //we choose (i) sons as black in x's subtree, including x
				for(int a=0;a<=2;a++) {//the state of x is a(0->empty 1->black 2->white)
					for(int c=2;c>=0;c--) {//must be in this order because position[0] might be used again, it shouldn't be altered
						mx=-INF;
						for(int j=max(0,i+size[v]-size[x]);j<=size[v];j++) {//we choose (j) sons as black on this chtree
							//j's lower bound is i-(size[x] without subtree[v]) so that it won't TLE, setting the bound as zero makes no mistake but slows the procedure down quite a lot
							if(i<j) break;
							for(int b=0;b<=2;b++) {//the state of this(v) son is b
								if(a+b==3) continue;//since x and v are adjacent, they cannot be 1 and 2
								if(up[v]==x) mx=max(mx,f[x][i-j][a][c]+f[v][j][b][a]);//exists a cycle with x as the shallowest node
								else if(up[v]) mx=max(mx,f[x][i-j][a][0]+f[v][j][b][c]);//exists a cycle, but x isn't the top and must be dp[x][a-b][cu]***[0] because x can only be at exactly one cycle's middle part
								else mx=max(mx,f[x][i-j][a][c]+f[v][j][b][0]);//x not on the cycle of this son(or this son has no cycle)
							}
						}
						f[x][i][a][c]=mx;
					}
				}
			}
		} else {
			up[x]=v;//we must do it here so that up[x] gets updated intime for the next 'for'
			for(int i=0;i<=size[x];i++) {//indeed this for can be put outside the REP(w)
				for(int j=1;j<=2;j++) {
					f[x][i][j][j]=f[x][i][j][0];
					f[x][i][0][j]=f[x][i][0][0];
				}
				f[x][i][1][2]=f[x][i][2][1]=-INF;
			}
		}
	}
	vis[x]=2;
}
int main() {
	int n,m,x,y;
	memset(f,200,sizeof(f));
	scanf("%d%d",&n,&m);
	while(m--) {
		scanf("%d%d",&x,&y);
		link(x,y);
	}
	dp(1,-1);
	int ans;
	for(int i=0;i<=n;i++) {
		ans=-INF;
		for(int j=0;j<=2;j++) ans=max(ans,f[1][i][j][0]);
		printf("%d ",ans);
	}
	printf("\n");
	return 0;
}
