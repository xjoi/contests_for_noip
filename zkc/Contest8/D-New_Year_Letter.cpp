#include <bits/stdc++.h>
using namespace std;

int n,m,k,x;

void print(int a,int b,int h1,int t1,int h2,int t2) {
    int tmp=h1,cnt=1,bef=0;
    while(cnt<=n) {
        if(tmp==1) {
            printf("A");
        } else if(tmp==2) {
            printf("C");
        } else printf("B");
        cnt++;
        if(bef==1&&tmp==2) a--;
        bef=tmp;
        if(a) {
            if(tmp==1) tmp=2;
            else if(tmp==2) tmp=1;
            else if(tmp==0) tmp=1;
        } else tmp=0;
        if(cnt==n) tmp=t1;
    }
    printf("\n");
    tmp=h2,cnt=1,bef=0;
    while(cnt<=m) {
        if(tmp==1) {
            printf("A");
        } else if(tmp==2) {
            printf("C");
        } else printf("B");
        cnt++;
        if(bef==1&&tmp==2) b--;
        bef=tmp;
        if(b) {
            if(tmp==1) tmp=2;
            else if(tmp==2) tmp=1;
            else if(tmp==0) tmp=1;
        } else tmp=0;
        if(cnt==m) tmp=t2;
    }
    printf("\n");
    exit(0);
}

void solve(int a,int b,int h1,int t1,int h2,int t2) {
    long long f[1000];
    int h[1000],t[1000];
    f[1]=a;
    f[2]=b;
    h[1]=h1,h[2]=h2;
    t[1]=t1,t[2]=t2;
    for(int i=3;i<=k;i++) {
        f[i]=f[i-2]+f[i-1];
        if(t[i-2]==1&&h[i-1]==2) {
            f[i]+=1;
        }
        h[i]=h[i-2];
        t[i]=t[i-1];
    }
    if(f[k]==x) {
        print(a,b,h1,t1,h2,t2);
    }
}

int main() {
    cin>>k>>x>>n>>m;
    for(int i=0;i<=n/2;i++) {
        for(int j=0;j<=m/2;j++) {
            for(int h1=0;h1<=2;h1++) {
                for(int t1=0;t1<=2;t1++) {
                    for(int h2=0;h2<=2;h2++) {
                        for(int t2=0;t2<=2;t2++){
                            if(n!=1&&i*2==n-1&&h1!=1&&t1!=2) continue;
                            if(m!=1&&j*2==m-1&&h2!=1&&t2!=2) continue;
                            //特判：长度不为1且除去所有AC之后只剩一个空余字符的话，那么要满足头是A或者尾是C
                            if(n==1&&h1!=t1) continue;
                            if(m==1&&h2!=t2) continue;
                            //特判：如果长度为1，那么前后字符必须相同
                            if(i*2==n&&(h1!=1||t1!=2)) continue;
                            if(j*2==m&&(h2!=1||t2!=2)) continue;
                            //特判：如果全串都是AC，那么头必须是A，尾必须是C
                            solve(i,j,h1,t1,h2,t2);
                        }
                    }
                }
            }
        }
    }
    puts("Happy new year!");
    return 0;
}