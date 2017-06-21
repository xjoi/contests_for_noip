#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
using namespace std;
int a,b;
int main() {
    scanf("%d%d",&a,&b);
    int ans=a;
    while (a>=b) {
        ans+=a/b;
        a=(a%b)+a/b;
    }
    printf("%d\n",ans);
    return 0;
}
