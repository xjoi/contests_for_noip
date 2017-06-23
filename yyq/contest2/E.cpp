#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
typedef struct Matrix
{
    ll mat[105][105];
}matrix;
matrix A,B,tmp,ans;
ll len[105];
ll dp[100000];
Matrix matrix_mul(matrix a,matrix b)
{
    matrix c;
    memset(c.mat,0,sizeof(c.mat));
    ll i,j,k;
    for(ll i=0;i<101;i++)
        for(ll j=0;j<101;j++)
            for(ll k=0;k<101;k++)
                c.mat[i][j]=(c.mat[i][j]+(a.mat[i][k]*b.mat[k][j])%mod)%mod;
    return c;
}
Matrix matrix_quick_power(matrix a,ll k)
{  
    matrix b;
    memset(b.mat,0,sizeof(b.mat));
    for(ll i=0;i<101;i++)
    	b.mat[i][i]=1;
    while(k)
    {
        if(k%2==1)
        {
            b=matrix_mul(a,b);
            k-=1;
        }
        else
        {
            a=matrix_mul(a,a);
            k/=2;
        }
    }
    return b;
}
int main()
{
    ll n,m;
    scanf("%lld%lld",&n,&m);
    memset(len,0,sizeof(len));
    memset(dp,0,sizeof(dp));
    for(ll i=1;i<=n;i++)
    {
        ll x;
        scanf("%lld",&x);
        len[x]++;
    }
    dp[0]=1;
    for(ll i=1;i<=100;i++)
    {
        for(ll j=1;j<=i;j++)
        {
            dp[i]+=dp[i-j]*len[j];
            dp[i]%=mod;
        }
    }
    ll presum=0;
    for(ll i=1;i<=m&&i<=100;i++)
		presum+=dp[i],presum%=mod;
    if(m<=100)
        printf("%lld\n",presum+1);
    else
    {
        memset(A.mat,0,sizeof(A.mat));
        memset(tmp.mat,0,sizeof(tmp.mat));
        for(ll i=0;i<100;i++)
			tmp.mat[i][0]=dp[i+1];
        tmp.mat[100][0]=presum+1;
        for(ll i=0;i<99;i++)
            A.mat[i][i+1]=1;
        for(ll i=0;i<100;i++)
			A.mat[99][i]=len[100-i];
        for(ll i=0;i<100;i++)
			A.mat[100][i]=len[100-i];
        A.mat[100][100]=1;
        B=matrix_quick_power(A,m-100);
        B=matrix_mul(B,tmp);
        printf("%lld\n",(B.mat[100][0]+mod)%mod);
    }
    return 0;
}  
