#include<cstdio>
#include<cstring>
#include<cmath>
#define N 20
#define M 200
#define P 1000000007
#define ll long long
using namespace std; 
ll s[N][N],h[N][N],t[N][N];
ll n,K,a[M],b[M],c[M];  
void mul(ll a[][N],ll b[][N],ll c[][N])  
{
	ll t[N][N];  memset(t,0,sizeof(t));
	int i,j,k;
    for(i=1;i<=16;i++)
        for(j=1;j<=16;j++)
            for(k=1;k<=16;k++)
                t[i][j]=(t[i][j]+(a[i][k]*b[k][j])%P)%P;
    for(i=1;i<=16;i++)
        for(j=1;j<=16;j++)
            c[i][j]=t[i][j];
}  
void pow(ll n)  
{  
    memset(t,0,sizeof(t));
    for(int i=1;i<=16;i++) t[i][i]=1;  
    while(n)
    {  
        if(n&1) mul(h,t,t);
        n>>=1;
        mul(h,h,h);  
    }  
}  
int main()  
{  
	int i,j,k;
    while(scanf("%I64d %I64d",&n,&K)!=EOF)  
    {  
        memset(s,0,sizeof(s));  memset(h,0,sizeof(h));  
        for(i=1;i<=n;i++) scanf("%I64d %I64d %I64d",&a[i],&b[i],&c[i]),c[i]++;  
        for(i=1;i<=16;i++) s[i][i]=h[i][i]=1; 
        for(k=1;k<=n;k++)
        {  
            memset(h,0,sizeof(h));  
            for(i=1;i<=c[k];i++)
                for(j=1;j<=c[k];j++)
                    if(abs(i-j)<=1)  
                        h[i][j]=1;
            ll m=b[k]-a[k];
            if(k==n) m=K;
            pow(m);
            K-=(b[k]-a[k]); 
            mul(t,s,s);
        }  
        printf("%I64d\n",s[1][1]);
    }  
    return 0;  
}  
