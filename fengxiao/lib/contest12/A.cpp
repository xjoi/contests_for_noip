#include<cstdio>
#include<cstring>
#define ll long long
ll n,m,N,M;
int main()
{
    while(scanf("%I64d %I64d %I64d",&n,&m,&N)!=EOF)  
    {  
        M=(N+1)*m/n;
        if(M>N) M=N;
        printf("%I64d\n",M);
    }
    return 0;  
}
