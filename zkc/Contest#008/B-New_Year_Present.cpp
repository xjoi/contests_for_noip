#include <bits/stdc++.h>
using namespace std;

int n,a[1000],now,cnt=0,b[1000],tmp,ans=0;
bool f[1000];

int main() {
    memset(f,0,sizeof f);
    scanf("%d",&n);
    for(int i=1;i<=n;i++) {
        scanf("%d",&a[i]);
        ans+=a[i];
    }
    now=1;
    tmp=1;
    while(cnt<ans) {
        if(!f[now]&&b[now]==a[now]) {
            f[now]=1;
        } else if(b[now]<a[now]) {
            printf("P");
            b[now]++;
            cnt++;
        };
        if(now==1&&tmp==-1) {
            tmp=1;
        } else if(now==n&&tmp==1) {
            tmp=-1;
        }
        if(tmp==1) {
            printf("R");
            now++;
        } else {
            printf("L");
            now--;
        }
    }
    return 0;
}