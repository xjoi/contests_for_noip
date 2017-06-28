#include<cstdio>
#include<iostream>
#include<algorithm>
#define xxx 520233
using namespace std;

int a[xxx],n,tot=0,t=1,ans=0,dead=0;
char s[xxx];

bool cmp(int x,int y)
{
	return x>y;
}

int main()
{
	int x;
	scanf("%d",&n);
	for (int i=1;i<=2*n;i++)
	{
		scanf("\n");
		scanf("%s",s);
		if (s[0]=='a')
		{
			scanf("%d",&x);
			a[++tot]=x;
		}
		else
		{
			if (tot>dead)
			{
				if (a[tot]!=t)
				{
					sort(a+dead+1,a+tot+1,cmp);
					ans++;
					dead=tot;
				}
				else
				{
					tot--;
				}
			}
			t++;
		}
	}
	printf("%d\n",ans);
}
