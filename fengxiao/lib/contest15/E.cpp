#include<cstdio>
#include<cstring>
#define N 100010
using namespace std;
int n,a[N],ans[N],ha[N];
int calc(int x)
{
	memset(ha,0,sizeof(ha));
	int cnt=0,sum=1;
	for(int i=1;i<=n;i++)
		if(ha[a[i]]!=sum)
		{
			cnt++; ha[a[i]]=sum;
			if(cnt>x) {sum++,cnt=1;ha[a[i]]=sum;}
		}
	return sum;
}
void bsearch(int l,int r)
{
	if(l>r) return;
	ans[l]=calc(l); ans[r]=calc(r);
	if(ans[l]==ans[r])
	{
		for(int i=l+1;i<r;i++) ans[i]=ans[l];
		return;
	}
	int mid=(l+r)/2;
	bsearch(l+1,mid); bsearch(mid+1,r-1);
}
int main()
{
	int i;
	scanf("%d",&n);
	for(i=1;i<=n;i++) scanf("%d",&a[i]);
	bsearch(1,n);
	for(i=1;i<=n;i++) printf("%d ",ans[i]);
	return 0;
}
