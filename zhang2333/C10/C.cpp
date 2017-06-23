#include<cstdio>
#include<iostream>
#include<vector>
#define xxx 100100
using namespace std;
int n,k,ans=0,a[xxx],g,lian[xxx];

int main()
{
	int x,y,p;
	scanf("%d%d",&n,&k);
	for (int nnd=1;nnd<=k;nnd++)
	{
		scanf("%d",&y);
		for (int i=1;i<=y;i++)
			scanf("%d",&a[i]);
		p=y;
		for (int i=1;i<y;i++)
		{
			if(a[i]+1!=a[i+1])
			{
				for (int j=i+1;j<=y;j++)
					lian[a[j]]=1;
				ans+=y-i;
				p=i;
				break;
			}
		}
		for (int i=1;i<=p;i++)
			lian[a[i]]=p-i+1;
	}
	//for (int i=1;i<=n;i++) printf("%d ",lian[i]);printf("\n");
	p=1;
	while (lian[p]>1&&p<n) p++;
	for (int i=p+1;i<=n;)
	{
		if (lian[i]==1)
		{
			ans++;
			i++;
		}
		else
		{
			ans+=2*lian[i]-1;
			i+=lian[i];
		}
	} 
	printf("%d",ans);
}
