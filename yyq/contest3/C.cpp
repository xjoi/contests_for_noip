#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll A,B,n,l,T,m,x,t;
int ok(ll k)
{
    ll la=(k-1)*B+x;
    if(la>(ll)T)
		return 0;
    if((la+x)*k/2<=t)
		return 1;
    return 0;
}
int main()
{
    scanf("%lld%lld%lld",&A,&B,&n);
    for (int i=1;i<=n;i++)
    {
        scanf("%lld%lld%lld",&l,&T,&m);
        x=A+(l-1)*B;
        if(T<x)
        {
            puts("-1");
            continue;
        }
        t=T*m;
        ll L=1,R=1e6,ans=0;
        while(L<=R)
        {
            ll M=(L+R)>>1;
            if(ok(M))
				ans=M,L=M+1;
            else
				R=M-1;
        }
        printf("%lld\n",(l-1+ans));
    }
    return 0;
}
