#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int n,a[100010];
int sum[100010];
int nxt[100010];
int main()
{
	int ans=0; int msum=0;
	int i; int pos=1;
	scanf("%d",&n);
	for(i=1;i<=n;i++) scanf("%d",&a[i]);
	for(i=1;i<=n;i++) {if(a[i]>a[i-1]) sum[i]=sum[i-1]+1;else {sum[i]=1;for(int j=pos;j<=i-1;j++) nxt[j]=i-1; pos=i;}} for(i=pos;i<=n;i++)nxt[i]=n;
	//for(i=1;i<=n;i++) printf("%d ",sum[i]); puts("");
	//for(i=1;i<=n;i++) printf("%d ",nxt[i]); puts("");
	for(i=1;i<=n;i++)
	{
		msum=max(msum,sum[i]);
		//if(i==2) printf("%d ",sum[i-1]+sum[nxt[i+1]]+(a[i]>=a[i+1] ? 1 : 0));
		if(sum[i]==1&& a[i+1]-a[i-1]>1) ans=max(ans,sum[i-1]+sum[nxt[i+1]]+(a[i]>=a[i+1] ? 1 : 0));
		if(nxt[i]==i&& a[i+1]-a[i-1]>1) { ans=max(ans,sum[i-1]+1+sum[nxt[i+1]]);}
	}
	//printf("%d ",ans);
	printf("%d",max(msum+(msum==n ? 0 : 1),ans));
	return 0;
}
