#include<cstdio>
#include<cstring>
#define N 100010
using namespace std;
int n,k,ans=0;
int nxt[N];
int main()
{
	int i,j,tmp,a,b;
	scanf("%d %d",&n,&k);
	for(i=1;i<=k;i++)
	{
		scanf("%d",&tmp); scanf("%d",&a);
		for(j=2;j<=tmp;j++)
		{
			scanf("%d",&b);
			nxt[a]=b;
			a=b;
		}
	}
	//for(i=1;i<=n;i++) printf("%d ",nxt[i]);
	i=1; while(nxt[i]==i+1) i++;
	for(i=i;i<n;i++)
	{
		int j=i;
		while(nxt[j]!=0) {int tmp=nxt[j]; nxt[j]=0; j=tmp; ans++;}
		ans++; nxt[i]=i+1;
	}
	printf("%d",ans);
	return 0;
}
