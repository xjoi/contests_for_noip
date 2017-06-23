#include<bits/stdc++.h>
using namespace std;
const int maxn=10010;
int num[2][maxn];
int Count(int n)
{
	if(n==4)
		return 1;
	if(n==7)
		return 2;
	int ans=2,cnt=2;
	int d=10,x=0;
	num[0][1]=4;
	num[0][2]=7;
	while(1)
	{
		int temp=0;
		for(int i=1;i<=cnt;++i)
		{
			num[(x+1)%2][++temp]=num[x%2][i]+4*d;
			ans++;
			if(num[(x+1)%2][temp]==n)
				return ans;
		}
		for(int i=1;i<=cnt;++i)
		{
			num[(x+1)%2][++temp]=num[x%2][i]+7*d;
			ans++;
			if(num[(x+1)%2][temp]==n)
				return ans;
		}
		d*=10;cnt=temp;x++;
	}
}
int main()
{
	int n,i,j,k,l;
	scanf("%d",&n);
	printf("%d\n",Count(n));
	return 0;
}
