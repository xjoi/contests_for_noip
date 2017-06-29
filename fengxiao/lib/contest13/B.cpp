#include<cstdio>
#include<cstring>
#include<algorithm>
#define N 110
using namespace std;
int in[N],n,m;
int ans=0;
int main()
{
	int i,j,a,b,c;
	scanf("%d %d",&n,&m);
	for(i=1;i<=m;i++)
	{
		scanf("%d %d %d",&a,&b,&c);
		in[a]+=c; in[b]-=c;
	}
	for(i=1;i<=n;i++) ans+=abs(in[i]);
	ans/=2;
	printf("%d",ans);
	return 0;
}
