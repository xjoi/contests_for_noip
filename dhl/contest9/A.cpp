#pragma GCC optimize("O3")
#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<string>
#define ls rt<<1
#define rs rt<<1|1
#define maxn 580000
#define LL long long
using namespace std;
LL n,m,k;
LL a[maxn];
struct Point{LL l,r,w;}p[maxn];
LL sum[maxn],rsum[maxn],answ[maxn];


int main()
{
	cin>>n>>m>>k;
	for(LL i=1;i<=n;i++)
		scanf("%64d",&a[i]);
	for(LL i=1;i<=m;i++)
		cin>>p[i].l>>p[i].r>>p[i].w;
	for(LL i=1;i<=k;i++)
	{
		LL t1,t2;
		cin>>t1>>t2;
		sum[t1]++;sum[t2+1]--;
	}
	LL sumv=0;
	for(LL i=1;i<=maxn;i++)
	{
		sumv+=sum[i];
		rsum[i]=sumv;
	}
	sumv=0;
	for(LL i=1;i<=maxn;i++)
	{
		answ[p[i].l]+=rsum[i]*p[i].w;
		answ[p[i].r+1]-=rsum[i]*p[i].w;
	}
	for(LL i=1;i<=maxn;i++){
		sumv+=answ[i];
		a[i]+=sumv;}

	for(LL i=1;i<=n;i++)
		cout<<a[i]<<" ";
	return 0;
} 
