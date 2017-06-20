#include <bits/stdc++.h>
using namespace std;

long long n,m,k,a,b,l,t,ans;

inline bool check(long long r) {
    long long sum=a*(r-l+1)+b*(((l-1+r-1)*(r-l+1))/2);
    return sum<=(long long)(m*t);
}

int main() {
    cin>>a>>b>>n;
    for(int i=1; i<=n; i++) {
        cin>>l>>t>>m;
        long long hl=a+l*b-b, dh=t-hl;
        long long rb=((dh/b)+l);
        if(rb<l) {
            puts("-1");
            continue;
        }
        long long mid,lb=l;
        while(lb<=rb) {
            //printf("%lld %lld\n",l,r);
            mid=((lb+rb)/2);
            if(check(mid)) {
                ans=mid;
                lb=mid+1;
            } else rb=mid-1;
        }
        cout<<ans<<endl;
    }
    return 0;
}