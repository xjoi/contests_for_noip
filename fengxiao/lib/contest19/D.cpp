#include<bits/stdc++.h>
#define N 100010
#define pii pair<int,int>
#define mp make_pair
#define F first
#define S second
using namespace std;
int n;
pii a[2][N];
bool used[N];
int fat[N];
int main()
{
	int i,j,c,v;
	scanf("%d",&n);
	for(i=1;i<=n;i++) {scanf("%d %d",&c,&v); a[c][++a[c][0].F]=mp(v,i);}
	sort(a[0]+1,a[0]+a[0][0].F+1); sort(a[1]+1,a[1]+a[1][0].F+1);
	i=j=1;
	for(int t=1;t<n;t++)
	{
		int tmp=min(a[0][i].F,a[1][j].F);
		printf("%d %d %d\n",a[0][i].S,a[1][j].S,tmp);
		a[0][i].F-=tmp,a[1][j].F-=tmp;
		if(a[0][i].F) j++;
		else if(a[1][j].F) i++;
		else if(i<a[0][0].F) i++;
		else j++;
		//printf("%d %d\n",i,j);
	}
	return 0;
}
