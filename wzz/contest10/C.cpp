using namespace std;
#include<cstdio>
#include<iostream>
#include<cstring>
#define N 100001
#define r(x) scanf("%d",&x)
int n,k;
int a[N];
int ans;
int x;
int y;
int main()
{
	r(n);r(k);
	a[0]=-5;
	for(int i=1;i<=k;i++)
	{
		r(x);
		bool flag=0;
		for(int j=1;j<=x;j++)
		{
			r(a[j]);
			if(j==1&&a[j]!=1)flag=1;
			if(j==1)continue;
			if(a[j]==a[j-1]+1)
			{
				if(!flag) ans-=2;
			}
			else flag=1;
		}
	}
	ans-=k;
	ans+=n*2-1;
	cout<<ans<<endl;
}
