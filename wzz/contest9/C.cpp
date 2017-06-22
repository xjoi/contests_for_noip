using namespace std;
#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#define N 51
#define mod 50
#define F(i,a,b) for(int i=a;i<=b;i++)
#define rep F
#define r(x) scanf("%d",&x)
#define p(x) printf("%d",x)
#define pk(x) printf("%d ",x)
#define pln(x) printf("%d\n",x)
#define ll long long
int m;
int tot;
int a[N];
int n;
int ty[3];
ll dp[1001][51][51][2];
const ll prmod=1e9+7;
struct NODE{
	int x,y,z,ty;
}xx;
ll C[101][101];
bool inq[1001][53][53][2];
int ans=1000;
int main()
{
	r(n);r(m);rep(i,1,n) r(a[i]);
	m/=mod;rep(i,1,n) a[i]/=mod;
	rep(i,1,n){ty[a[i]]++;}
//	cout<<ty[1]<<" "<<ty[2]<<" "<<m<<endl;
	C[0][0]=1;
	rep(i,0,100)
	{
		C[i][0]=1;
		rep(j,1,i)
		{
			C[i][j]=C[i-1][j]+C[i-1][j-1];
			C[i][j]=C[i][j]%prmod;
		}	
	}
	if(1)
	{
		if(n==1&&a[1]<=m){puts("1");puts("1");return 0;}
		if(ty[1]==0){if(m<4) {puts("-1");puts("0");return 0;}}
		if(ty[1]==1){if(m<3) {puts("-1");puts("0");return 0;}}
		if(ty[1]==2){if(m<2) {puts("-1");puts("0");return 0;}}
	}
	dp[0][ty[1]][ty[2]][0]=1;
	rep(i,0,1000)
	{
		rep(j,0,ty[1])
		{
			rep(k,0,ty[2])
			{
				rep(tt,0,1)
				{
					if(!dp[i][j][k][tt]) continue;
					if(tt==0)
					{
						rep(l1,0,min(m,j))
						rep(l2,0,min((m-l1)/2,k))
						{
							if(l1==0&&l2==0) continue;
							dp[i+1][j-l1][k-l2][1]=(dp[i+1][j-l1][k-l2][1]+((dp[i][j][k][tt]*C[j][l1])%prmod*C[k][l2])%prmod)%prmod;
						}
					}
					else
					{
						int jj=ty[1]-j,kk=ty[2]-k;
						rep(l1,0,min(m,jj))
						rep(l2,0,min((m-l1)/2,kk))
						{
							if(l1==0&&l2==0) continue;
							dp[i+1][j+l1][k+l2][0]=(dp[i+1][j+l1][k+l2][0]+((dp[i][j][k][tt]*C[jj][l1])%prmod*C[kk][l2])%prmod)%prmod;
						}
					}
				}
			}
		}
		if(dp[i][0][0][1])
		{
			ans=i;break;
		}
	}
	if(ans>800)
	{
		puts("-1");puts("0");return 0;
	}
	cout<<ans<<endl;
	int res=0;
	res=(dp[ans][0][0][1])%prmod;
	cout<<res<<endl;
}
