#include<cstdio>
#include<iostream>
#define xxx 100100
#define yyy 520233
using namespace std;
long long n,m,k,ml[xxx],mr[xxx],mv[xxx],a[xxx],b[xxx];
long long times[xxx];

int main()
{
	scanf("%I64d%I64d%I64d",&n,&m,&k);
	for (int i=1;i<=n;i++)
		scanf("%I64d",&a[i]);
	for (int i=1;i<=m;i++)
		scanf("%I64d%I64d%I64d",&ml[i],&mr[i],&mv[i]);
	long long x,y;
	for (int i=1;i<=k;i++)
	{
		scanf("%I64d%I64d",&x,&y);
		times[x]++;
		times[y+1]--;
	}
	for (int i=1;i<=m;i++)
	{
		times[i+1]+=times[i];
		mv[i]*=times[i];
	}
	for (int i=1;i<=m;i++)
	{
		b[ml[i]]+=mv[i];
		b[mr[i]+1]-=mv[i];
	}
	for (int i=1;i<=n;i++)
	{
		b[i+1]+=b[i];
		printf("%I64d ",a[i]+b[i]);
	}
}
