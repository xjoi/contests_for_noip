#include<cstdio>
#include<iostream>
using namespace std;
int k,x,n,m;
struct DP{
	long long cnt[3],st,en,con[3][3];
}dp[520];

int alright(int a1,int a2,int b1,int b2)
{
	//printf("%d %d %d %d\n",a1,a2,b1,b2);
	int sn=a1>0?2:1;
	int en=n-(a2>0?1:0);
	int sm=b1>0?2:1;
	int em=m-(b2>0?1:0);
	//	if (a1==0&&a2==1&&b1==2&&b2==0) printf("fsfadc\n");
	if (sn>en+1||sm>em+1) return 0;
	int must=0;
	if (a2==1&&a1==2)
		must+=dp[k].con[1][1];
	if (a2==1&&b1==2)
		must+=dp[k].con[1][2];
	if (b2==1&&a1==2)
		must+=dp[k].con[2][1];
	if (b2==1&&b1==2)
		must+=dp[k].con[2][2];
	if (must>x) return 0;
	for (int i=0;i<=(en-sn+1)/2;i++)
		for (int j=0;j<=(em-sm+1)/2;j++)
			if (must+dp[k].cnt[1]*i+dp[k].cnt[2]*j==x)
			{
				if (a1>0) printf("%c",a1==1?'A':'C');
				for (int u=sn;u<=en;)
				{
					if (i>0)
					{
						printf("AC");
						u+=2;
						i--;
					}
					else
					{
						printf("B");
						u++;
					}
				}
				if (a2>0) printf("%c",a2==1?'A':'C');
				printf("\n");
				if (b1>0) printf("%c",b1==1?'A':'C');
				for (int u=sm;u<=em;)
				{
					if (j>0)
					{
						printf("AC");
						u+=2;
						j--;
					}
					else
					{
						printf("B");
						u++;
					}
				}
				if (b2>0) printf("%c",b2==1?'A':'C');
				return 1;
			}
	return 0;
}

int main()
{
	scanf("%d%d%d%d",&k,&x,&n,&m);
	dp[1].cnt[1]=1;
	dp[1].st=dp[1].en=1;
	dp[2].cnt[2]=1;
	dp[2].st=dp[2].en=2;
	for (int i=3;i<=k;i++)
	{
		for (int u=1;u<=2;u++)
			dp[i].cnt[u]=dp[i-2].cnt[u]+dp[i-1].cnt[u];
		for (int u=1;u<=2;u++)
			for (int v=1;v<=2;v++)
				dp[i].con[u][v]=dp[i-2].con[u][v]+dp[i-1].con[u][v];
		dp[i].con[dp[i-2].en][dp[i-1].st]++;
		dp[i].st=dp[i-2].st;
		dp[i].en=dp[i-1].en;
	}
	//printf("%lld %lld %lld %lld %lld %lld %lld %lld\n",dp[k].cnt[1],dp[k].cnt[2],dp[k].con[1][1],dp[k].con[1][2],dp[k].con[2][1],dp[k].con[2][2],dp[k].st,dp[k].en);
	for (int i=0;i<=2;i++)
		for (int j=0;j<=2;j++)
			for (int k=0;k<=2;k++)
				for (int l=0;l<=2;l++)
					if (alright(i,j,k,l))
						return 0;
	printf("Happy new year!");
}
