#include<cstdio>
#include<iostream>
#include<cstring>
#define xxx 110
#define mod 1000000007
using namespace std;

long long n,k,a,b,c;

struct jz{
	long long v[17][17];
}ans,f[17][62],nil;

void pri(jz ff)
{
	for (int i=0;i<=15;i++)
	{
		for (int j=0;j<=15;j++)
			printf("%lld ",ff.v[i][j]);
		printf("\n");
	}
}

jz cheng(jz f1,jz f2)
{
	long long t;
	jz f3=nil;
	for (int i=0;i<=15;i++)
		for (int j=0;j<=15;j++)
		{
			t=0;
			for (int u=0;u<=15;u++)
				t=(t+f1.v[i][u]*f2.v[u][j])%mod;
			f3.v[i][j]=t;
		}
	return f3;
}

void build(int x)
{
	f[x][0]=nil;
	for (int i=0;i<=x;i++)
	{
		for (int j=max(0,i-1);j<=min(i+1,x);j++)
			f[x][0].v[i][j]=1;
	}
	for (int i=1;i<=60;i++)
		f[x][i]=cheng(f[x][i-1],f[x][i-1]);
}

void realmain()
{
	b=min(b,k);
	long long l=b-a;
	for (long long i=c+1;i<=15;i++)
		ans.v[i][0]=0;
	for (long long i=60;i>=0;i--)
	{
		if (l>=((long long)1<<i))
		{
			l-=((long long)1<<i);
			ans=cheng(f[c][i],ans);
		}
	}
}

int main()
{
	cin>>n>>k;
	memset(nil.v,0,sizeof(nil.v));
	ans=nil;
	ans.v[0][0]=1;
	for (int i=0;i<=15;i++)
		build(i);
	while (n--)
	{
		cin>>a>>b>>c;
		realmain();
		//pri(ans);
	}
	cout<<ans.v[0][0];
}
