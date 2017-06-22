//If you are strong minded do it without any hestation. 
using namespace std;
#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>
#define F rep
int Max(int x,int y,int z)
{
	return max(max(x,y),z);
}
#define N 2501
#define M 500001
#define forw(i,x) for(int i=fir[x];i;i=ne[i])
#define r(x) scanf("%d",&x)
#define rep(i,a,b) for(int i=a;i<=b;i++)
const int inf=-2e8;
int dfn[N],low[N],fir[N],S[N];
int ne[M],to[M];
int n,m;
int cnt=1,tot=1;
int dp[N][N][3],dance[N][3],d1[N][3][3],fire[N][3][3];
int fa[N];
bool vis[N];
int cir[N];
void link(int x,int y)
{
	ne[++cnt]=fir[x];fir[x]=cnt;to[cnt]=y;
	ne[++cnt]=fir[y];fir[y]=cnt;to[cnt]=x;
}
void pushup(int &x,int y)
{
	if(x<y) x=y;
}
void docircle(int u,int v)
{
	int len=0;
//	if(u==1)cout<<v<<endl;
	while(1)
	{
		cir[++len]=v;
		if(v==u)break;
		v=fa[v];
	}
	reverse(cir+1,cir+len+1);
	rep(i,0,S[u]) 
	{
		rep(j,0,2) rep(k,0,2) d1[i][j][k]=inf;
		rep(j,0,2) d1[i][j][j]=dp[u][i][j];
	}
	rep(i,2,len)
	{
		v=cir[i];
		rep(j,0,S[u]) rep(h1,0,2) rep(h2,0,2) fire[j][h1][h2]=d1[j][h1][h2];
		rep(j,0,S[u]+S[v]) rep(h1,0,2) rep(h2,0,2) d1[j][h1][h2]=inf;
		rep(j,0,S[u])
		rep(k,0,S[v])
		rep(l,0,2)
		{
			pushup(d1[j+k][l][0],dp[v][k][0]+Max(fire[j][l][0],fire[j][l][1],fire[j][l][2]));
			pushup(d1[j+k][l][1],dp[v][k][1]+max(fire[j][l][0],fire[j][l][1]));
			pushup(d1[j+k][l][2],dp[v][k][2]+max(fire[j][l][0],fire[j][l][2]));
		}
		S[u]+=S[v];
//		if(u==1)cout<<v<<endl;
	}
	rep(i,0,S[u])
	{
		pushup(dp[u][i][0],Max(d1[i][0][0],d1[i][0][1],d1[i][0][2]));
		pushup(dp[u][i][1],max(d1[i][1][1],d1[i][1][0]));
		pushup(dp[u][i][2],max(d1[i][2][0],d1[i][2][2]));
	}
//	if(u==1) cout<<S[u]<<endl;
}
void dfs(int x,int f)
{
	S[x]=1;
	low[x]=dfn[x]=++tot;
	vis[x]=1;
	fa[x]=f;
	dp[x][0][0]=0;
	dp[x][1][1]=0;
	dp[x][0][2]=1;
	forw(ii,x)
	{
		int V=to[ii];
		if(V==f) continue;
		if(!vis[V])
		{
			dfs(V,x);
			if(low[V]>dfn[x])
			{
				rep(i,0,S[x]+S[V]) rep(j,0,2) dance[i][j]=inf;
				rep(i,0,S[x]) rep(j,0,S[V]) 
				{
					pushup(dance[i+j][0],dp[x][i][0]+Max(dp[V][j][0],dp[V][j][1],dp[V][j][2]));
					pushup(dance[i+j][1],dp[x][i][1]+max(dp[V][j][0],dp[V][j][1]));
					pushup(dance[i+j][2],dp[x][i][2]+max(dp[V][j][0],dp[V][j][2]));
				}
				S[x]+=S[V];
				F(j,0,S[x]) F(k,0,2) dp[x][j][k]=dance[j][k];
			}
		}
		low[x]=min(low[x],low[to[ii]]);
	}
	forw(i,x)
	{
		int v=to[i];
		if(dfn[v]>dfn[x]&&x!=fa[v])
		{
			docircle(x,v);
		}
	}
}
int x,y;
int main()
{
	r(n);r(m);
	rep(i,1,m)
	{
		r(x);r(y);
		link(x,y);
	}
	memset(dp,0xdd,sizeof(dp));//有些地方0加上一个正的去会萎 
	dfs(1,0);
	int ans=-666;
	rep(i,0,n)
	{
		ans=Max(dp[1][i][0],dp[1][i][1],dp[1][i][2]);
		printf("%d ",ans);
	}
}
