#include <bits/stdc++.h>
using namespace std;

struct node {
    int x,y,ans;
}a[300010];

int n;

bool cmp1(node a,node b) {
    return a.x<b.x;
}

bool cmp2(node a,node b) {
    return a.y<b.y;
}

int main() {
    scanf("%d",&n);
    for(int i=1;i<=n;i++) {
        scanf("%d",&a[i].x);
        a[i].y=i;
        a[i].ans=0;
    }
    sort(a+1,a+1+n,cmp1);
    int tmp=0;
    for(int i=1;i<=n;i++) {
        if(a[i].x>tmp) {
            tmp=a[i].x;
        } else tmp++;
        a[i].ans=tmp;
    }
    sort(a+1,a+1+n,cmp2);
    for(int i=1;i<=n;i++) {
        printf("%d ",a[i].ans);
    }
    return 0;
}
