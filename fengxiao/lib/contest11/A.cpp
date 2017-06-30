#include<cstdio>
#include<cstring>
#define N 60
using namespace std;
int a[N][N],n;
bool flag=0;
int main()
{
	int i,j;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
		for(j=1;j<=n;j++)
			scanf("%d",&a[i][j]);
	for(i=1;i<=n;i++)
		for(j=1;j<=n;j++)
			if(a[i][j]!=1)
			{
				flag=0;
				for(int s=1;s<=n;s++)
					for(int t=1;t<=n;t++)
						if(a[i][s]+a[t][j]==a[i][j]) {flag=1; break;}
				if(!flag) {printf("No\n"); return 0;}
			}
	printf("Yes\n");
	return 0;
}
