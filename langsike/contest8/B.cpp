#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
using namespace std;
int n;
int a[10000];
int main() {
    scanf("%d",&n);
    for (int i=1;i<=n;i++) scanf("%d",&a[i]);
    for (int i=1;i<=600;i++) {
        if (i%2) {
            for (int j=1;j<=n-1;j++) {
                if (a[j]) {
                    putchar('P');
                    a[j]--;
                }
                putchar('R');
            }
        }
        else {
            for (int j=n;j>1;j--) {
                if (a[j]) {
                    putchar('P');
                    a[j]--;
                }
                putchar('L');
            }
        }
    }
    return 0;
}
