#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
#define int long long
#define N 1000010
using namespace std;
int n,m,K,p,ans=-10000000000000000;
int map[5010][5010],rs[N],cs[N],sumr[N],sumc[N];
priority_queue<int> rq,cq;
main()
{
	int i,j;
	scanf("%I64d %I64d %I64d %I64d",&n,&m,&K,&p);
	for(i=1;i<=n;i++)
		for(j=1;j<=m;j++)
		{
			scanf("%I64d",&map[i][j]);
			rs[i]+=map[i][j]; cs[j]+=map[i][j];
		}
	for(i=1;i<=n;i++) rq.push(rs[i]);
	for(i=1;i<=K;i++)
	{
		int u=rq.top(); rq.pop();
		sumr[i]=sumr[i-1]+u;// printf("%I64d ",u);
		u-=p*m; rq.push(u);
	}//puts("");
	for(i=1;i<=m;i++) cq.push(cs[i]);
	for(i=1;i<=K;i++)
	{
		int u=cq.top(); cq.pop();
		sumc[i]=sumc[i-1]+u;// printf("%I64d ",u);
		u-=p*n; cq.push(u);
	}
	for(i=0;i<=K;i++) ans=max(sumr[i]+sumc[K-i]-p*i*(K-i),ans);
	printf("%I64d",ans);
	return 0;
}
