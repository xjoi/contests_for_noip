#include<iostream>
#include<cstdio>
using namespace std;
typedef long long LL;
bool judge=0;
LL n,m,x,k;
LL f[100];
char ans1[1000],ans2[1000];
void find(int opt) {
    LL nown=n,nowm=m,nowx=x;
    if (opt&1) {
        nowx-=f[k-2];
        nown--;
        nowm--;
    }
    if (opt&2) {
        nowx-=f[k-2];
        if (k&1) nowx++;
        nown--;
        nowm--;
    }
    if (opt==3) nowx-=f[k-3]-(k+1)%2;
    if (opt==4) {
        nowx-=f[k-3]-(k+1)%2;
        nowm-=2;
    }
    if (opt==5) {
        nowm--;
        nowx-=f[k-3]-(k+1)%2;
    }
    if (nowx<0||nown<0||nowm<0) return;
    int nown0=nown/2,nowm0=nowm/2;
    for (LL i=0;i<=nown0;i++)
        for (LL j=0;j<=nowm0;j++) 
              if (f[k-2]*i+f[k-1]*j==nowx) {
                  judge=1;
                  int g1=0,g2=0;
                  int k1=n,k2=m;
                  if (opt&1) g2++,k1--;
                  if (opt&2) g1++,k2--;
                  if (opt==4) g2++,k2--;
                  if (opt==5) k2--;
                  for (LL k=1;k<=i;k++){
                      ans1[k*2-2+g1]='A';
                      ans1[k*2-1+g1]='C';
                  }
                for (LL k=i*2+g1;k<k1;k++) ans1[k]='L';
                  for (LL k=1;k<=j;k++){
                      ans2[k*2-2+g2]='A';
                      ans2[k*2-1+g2]='C';
                  }
                for (LL k=j*2+g2;k<k2;k++) ans2[k]='L';
                if (opt&1) {
                    ans1[n-1]='A';
                    ans2[0]='C';
                }
                if (opt&2) {
                    ans1[0]='C';
                    ans2[m-1]='A';
                }
                if (opt==4) {
                    ans2[0]='C';
                    ans2[m-1]='A';
                }
                if (opt==5) ans2[m-1]='A';
                return;            
            }
}
int main() {
    f[1]=1;
    f[2]=1;
    for (int i=3;i<=50;i++) f[i]=f[i-1]+f[i-2];
    scanf("%d%d%d%d",&k,&x,&n,&m);
    for (int i=0;i<=5;i++) {
        find(i);
        if (judge) break;
    }
    if (judge) {
        printf("%s\n%s\n",ans1,ans2);
        return 0;
    }
    printf("Happy new year!\n");
    return 0;
}
