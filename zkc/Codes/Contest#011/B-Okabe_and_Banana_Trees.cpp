#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll m,b,n,ans=0;
int main() {
    cin>>m>>b;
    ll k=m*b;
    for(ll i=1;i<=k;i++) {
        ll x=(-i*1.0)/m+b;
        if((double)(-i*1.0)/m+b!=x) continue;
        ll fir=x*(x+1)/2,las=fir+i*(x+1);
        ll tmp=(fir+las)*(i+1)/2;
        //printf("[%lld,%lld] : %lld~%lld =%lld\n",i,x,fir,las,tmp);
        if(tmp>ans) ans=tmp;
    }
    cout<<ans<<endl;
}
