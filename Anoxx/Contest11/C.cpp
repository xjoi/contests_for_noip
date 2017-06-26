#include <cstdio>
using namespace std;

int n,s[300005],top;

int main()
{
	int i,j,ans=0;
	char op[15];
	scanf("%d",&n);
	for(i=j=1;i<=2*n;++i)
	{
		scanf("%s",op);
		if(op[0]=='a')
			scanf("%d",&s[++top]);
		else
		{
			if(top)
			{
				if(s[top]==j) --top;
				else top=0,++ans;
			}
			++ j;
		}
	}
	printf("%d\n",ans);
}
