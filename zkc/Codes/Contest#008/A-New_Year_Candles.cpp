#include <bits/stdc++.h>
using namespace std;

int n,m=0,k,b=0;

int main() {
    cin>>n>>k;
    while(n||b) {
        m+=n;
        b+=n;
        n=b/k;
        b%=k;
        if(n==0&&b<k) break;
    }
    cout<<m<<endl;
    return 0;
}