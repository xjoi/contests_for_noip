#include<cstdio>
#include<cstring>
#include<algorithm>
#define N 300010
using namespace std;
struct P
{
	int v,pos,ans;
}a[N];
int n;
bool cmp(P a,P b) {return a.v<b.v;}
bool cmp2(P a,P b) {return a.pos<b.pos;}
int main()
{
	int i;
	scanf("%d",&n);
	for(i=1;i<=n;i++) {scanf("%d",&a[i].v); a[i].pos=i;}
	sort(a+1,a+n+1,cmp);
	int now=-1;
	for(i=1;i<=n;i++)
	{
		now=max(a[i].v,now+1);
		a[i].ans=now;
	}
	sort(a+1,a+n+1,cmp2);
	for(i=1;i<=n;i++) printf("%d ",a[i].ans);
	return 0;
}
