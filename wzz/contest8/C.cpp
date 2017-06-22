using namespace std;
#include<map>
#include<queue>
#include<cstdio>
#include<iostream>
#include<algorithm>
#define N 3000001
int a[N];
int cnt[N];
int tot;
int n;
int val[N];
struct man{
	int v,no;
}xx[N];
int ans[N];
bool cmp(man x,man y)
{
	return x.v<y.v;
}
map<int,int>M;
int  main()
{
	cin>>n;
	for(int i=1;i<=n;i++) scanf("%d",&xx[i].v);
	for(int i=1;i<=n;i++) xx[i].no=i;
	sort(xx+1,xx+n+1,cmp);
	for(int i=1;i<=n;i++) a[i]=xx[i].v;
	for(int i=1;i<=n;i++)
	{
		if(M.count(a[i]))cnt[tot]++;
		else 
		{
			M[a[i]]=1;
			val[++tot]=a[i];
			cnt[tot]=1;
		}
	}
//	for(int i=1;i<=tot;i++) cout<<val[i]<<" "<<cnt[i]<<endl;
	val[tot+1]=2e9;
	int hh=0;
	for(int i=1;i<=tot;i++)
	{
		if(cnt[i]>val[i+1]-val[i])
		{
			cnt[i+1]+=cnt[i]-val[i+1]+val[i];
			cnt[i]=val[i+1]-val[i];
		}
		for(int j=1;j<=cnt[i];j++)
		{
			ans[xx[++hh].no]=val[i]+j-1;
		}
	}
	for(int i=1;i<=n;i++) printf("%d ",ans[i]);
}
