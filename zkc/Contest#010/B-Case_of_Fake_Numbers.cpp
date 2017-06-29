#include <bits/stdc++.h>
using namespace std;

int n,a[1010];
bool f=1;

int main() {
    scanf("%d",&n);
    for(int i=1;i<=n;i++) {
        scanf("%d",&a[i]);
        if(a[i]!=i-1) f=false;
    }
    for(int i=1;i<=n;i++) {
        bool f=1;
        for(int j=1;j<=n;j++) {
            if(j&1) {
                a[j]=(a[j]+1)%n;
            } else {
                a[j]=(a[j]+n-1)%n;
            }
            if(a[j]!=j-1) f=0;
        }
        if(f) {
            puts("Yes");
            return 0;
        }
    }
    puts("No");
    return 0;
}