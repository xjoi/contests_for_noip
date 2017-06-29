#include<bits/stdc++.h>
#define mod 1000000007
#define LL long long
using namespace std;
LL c[200][200];
LL n,orzzzy;
LL f[2][200][200],s[2][200][200],cnt[100];

void getC()
{
	for(LL i=0;i<=51;i++)
	 c[i][0]=1;
	for(LL i=1;i<=51;i++)
		for(LL j=1;j<=51;j++)
			c[i][j]=(c[i-1][j-1]+c[i-1][j])%mod;
}

int main()
{
	getC();
	cin>>n>>orzzzy;
	orzzzy/=50;
	for(LL i=1;i<=n;i++)
	{
		LL x;cin>>x;
		cnt[x/50]++;
	}
	memset(s,20,sizeof(s));
	f[0][cnt[1]][cnt[2]]=1;
	s[0][cnt[1]][cnt[2]]=0;
	//cout<<cnt[1]<<" "<<cnt[2]<<"\n";
	
	LL step=-1;
	while(1)
	{
		step++;
		if(step>210)
		{	
			cout<<"-1\n0\n";
			break;	
		}
		LL ok=step%2;
		for(LL i=0;i<=cnt[1];i++)
			for(LL j=0;j<=cnt[2];j++)
				{
					if(s[ok][i][j]!=step) continue;
					if(i==0&&j==0&&ok)
					{
						cout<<s[ok][i][j]<<"\n"<<f[ok][i][j]<<"\n";
						return 0;
					}	
					if(!ok)
					{
						for(LL u=0;u<=i;u++)
							for(LL v=0;v<=j;v++)
							{
								if(u==0&&v==0) continue;
								if(u+2*v>orzzzy) break;
								if(s[1][i-u][j-v]==s[0][i][j]+1)
									f[1][i-u][j-v]+=(f[0][i][j]%mod*c[i][u]*c[j][v]%mod)%mod,f[1][i-u][j-v]%=mod;
								else if(s[1][i-u][j-v]>s[0][i][j]+1)
								{
									s[1][i-u][j-v]=s[0][i][j]+1;
									f[1][i-u][j-v]=(f[0][i][j]%mod*c[i][u]*c[j][v]%mod)%mod,f[1][i-u][j-v]%=mod;
								}
								//cout<<i-u<<j-v;
								//	cout<<i<<" "<<j<<" "<<u<<" "<<v<<" "<<s[1][i-u][j-v]<<" "<<f[1][i-u][j-v]<<endl;
							}
					}
					else
					{
						for(LL u=i;u<=cnt[1];u++)
							for(LL v=j;v<=cnt[2];v++)
							{
								if(u==i&&v==j) continue;
								if((u-i)+(v-j)*2>orzzzy) break;
								if(s[0][u][v]==s[1][i][j]+1)
									f[0][u][v]+=(f[1][i][j]%mod*c[cnt[1]-i][u-i]*c[cnt[2]-j][v-j]%mod)%mod,f[0][u][v]%=mod;
								else if(s[0][u][v]>s[1][i][j]+1)
								{
									s[0][u][v]=s[1][i][j]+1;
									f[0][u][v]=(f[1][i][j]%mod*c[cnt[1]-i][u-i]*c[cnt[2]-j][v-j]%mod)%mod,f[0][u][v]%=mod;		
								}
							}
					}
				}
	}
	return 0;
}
