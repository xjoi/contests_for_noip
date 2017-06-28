#pragma GCC optimize("O3")
#include<bits/stdc++.h>
#define maxn 1000
#define LL long long
using namespace std;
LL n,book[maxn],dis[maxn][maxn],dist[maxn],s[maxn],d[maxn][maxn];
LL ans=0;
vector<LL> sta;
void Floyd()
{
	for(LL k=n;k>=1;k--)
	{
			LL now=s[k];
			for(LL i=1;i<=n;i++)
				for(LL j=1;j<=n;j++)if(i!=j)
				{
					LL t1=s[i],t2=s[j];
					dis[t1][t2]=min(dis[t1][t2],dis[t1][now]+dis[now][t2]);
				}
			ans=0;
			for(LL i=k;i<=n;i++)
				for(LL j=k;j<=n;j++) if(i!=j)
				{
					LL t1=s[i],t2=s[j];
					ans+=dis[t2][t1];
				}		
			sta.push_back(ans);
	}
	for(LL i=sta.size()-1;i>=0;i--)
		cout<<sta[i]<<" ";
}

int main()
{
	ios::sync_with_stdio(false);
	cin>>n;	
	for(LL i=1;i<=n;i++)
		for(LL j=1;j<=n;j++)
			cin>>dis[i][j];
	for(LL i=1;i<=n;i++)
		cin>>s[i];
	Floyd();
	return 0;
} 
/*
6
0 72137 71041 29217 96749 46417
40199 0 55907 57677 68590 78796
83463 50721 0 30963 31779 28646
94529 47831 98222 0 61665 73941
24397 66286 2971 81613 0 52501
26285 3381 51438 45360 20160 0
6 3 2 4 5 1
*/
