#include <bits/stdc++.h>
using namespace std;

long long n,now;

int main() {
    cin>>n;
    for(long long i=1;i<=n;i++) {
        if(i==1) printf("2\n");
        else printf("%lld\n",(long long)(i*(i+1)*(i+1)-(i-1)));
    }
    return 0;
}