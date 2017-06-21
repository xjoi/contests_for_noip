#include<bits/stdc++.h>
using namespace std;
int n,m;
int x,y;
int w[105];
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&w[i]);
	scanf("%d",&m);
	for(int i=1;i<=m;i++)
	{
		scanf("%d%d",&x,&y);
		if(x==1)
			w[2]+=w[1]-y;
		else if(x==n)
			w[n-1]+=y-1;
		else
		{
			w[x+1]+=w[x]-y;
			w[x-1]+=y-1;
		}
		w[x]=0;
	}
	for(int i=1;i<=n;i++)
		printf("%d\n",w[i]);
	return 0; 
}
