#include<bits/stdc++.h>
using namespace std;
const int MAXN=100005;
int a[MAXN];
int n,m,k;
long long ans[MAXN];
struct opera{
	int l,r,d;
}q[MAXN];
int x,y;
int sum[MAXN];
int main()
{
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for(int i=1;i<=m;i++)
		scanf("%d%d%d",&q[i].l,&q[i].r,&q[i].d);
	for(int i=1;i<=k;i++)
	{
		scanf("%d%d",&x,&y);
		sum[x]++;
		sum[y+1]--;
	}
	for(int i=1;i<=m;i++)
		sum[i]+=sum[i-1];
	for(int i=1;i<=m;i++)
	{
		ans[q[i].l]+=(long long)sum[i]*(long long)q[i].d;
		ans[q[i].r+1]+=(long long)-sum[i]*(long long)q[i].d;
	}
//	for(int i=1;i<=n;i++)
//		cout<<ans[i]<<" ";
//	cout<<endl;
	for(int i=1;i<=n;i++)
		ans[i]+=ans[i-1];
	for(int i=1;i<=n;i++)
		printf("%I64d ",ans[i]+a[i]);
	return 0;
}
