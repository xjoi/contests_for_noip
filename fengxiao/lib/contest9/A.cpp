#include<cstdio>
#include<cstring>
#include<iostream>
#define N 100010
#define ll long long
using namespace std;
ll ope[N];
ll a[N],ans[N];
ll l[N],r[N],v[N];
int  n,m,k;
int main()
{
	int i,x,y;
	cin>>n>>m>>k;
	for(i=1;i<=n;i++) cin>>a[i];
	for(i=1;i<=m;i++) cin>>l[i]>>r[i]>>v[i];
	for(i=1;i<=k;i++)
	{
		cin>>x>>y;
		ope[x]++;ope[y+1]--;
	}
	for(i=1;i<=m;i++)
	{
		ope[i]+=ope[i-1];
		ans[l[i]]+=ope[i]*v[i],ans[r[i]+1]-=ope[i]*v[i];
	}
	ll sum=0;
	for(i=1;i<=n;i++)
	{
		ans[i]+=ans[i-1];
		cout<<ans[i]+a[i]<<" ";
	}
	return 0;
}
