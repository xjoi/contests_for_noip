#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
struct data{
    int x,num,ans;
}a[300001];
int n;
bool cmp1(data p,data q) {
    return p.x<q.x;
}
bool cmp2(data p,data q) {
    return p.num<q.num;
}
int main() {
    scanf("%d",&n);
    for (int i=1;i<=n;i++) {
        scanf("%d",&a[i].x);
        a[i].num=i;
    }
    sort(a+1,a+n+1,cmp1);
    for (int i=1;i<=n;i++) a[i].ans=max(a[i-1].ans+1,a[i].x);
    sort(a+1,a+n+1,cmp2);
    for (int i=1;i<=n;i++) printf("%d ",a[i].ans);
    return 0;
}
