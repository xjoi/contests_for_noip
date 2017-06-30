#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
using namespace std;
int n,kg;
struct data {
    double k,b;
}f[601];
double k[601],b[601],a[601][601],s[601];
void work(int x) {
    for (int i=1;i<=n;i++) {
        k[i]=a[i][x+1]-a[i][x];
        b[i]=a[i][x]*10;
    }
    double now=200000;
    int tot=2;
    f[1].k=-1e8;f[2].k=1e8;
    f[1].b=200000;f[2].b=200000-1e9;
    for (int i=1;i<=n;i++) {
        int l=-1,r=-1;
        for (int j=1;j<tot;j++) {
            double x=(f[j+1].b-f[j].b)/(f[j].k-f[j+1].k);
            double y=f[j].k*x+f[j].b;
            double nowy=k[i]*x+b[i];
            if (nowy>y) {
                l=j;
                break;
            }
        }
        for (int j=tot;j>1;j--) {
            double x=(f[j].b-f[j-1].b)/(f[j-1].k-f[j].k);
            double y=f[j].k*x+f[j].b;
            double nowy=k[i]*x+b[i];
            if (nowy>y) {
                r=tot-j+1;
                break;
            }
        }
        if (l==-1||r==-1) continue;
        if (l+r==tot) {
            for (int j=tot+1;j>=l+2;j--) f[j]=f[j-1];
            f[l+1].b=b[i];
            f[l+1].k=k[i];
        }
        else {
            for (int j=l+2;j<=l+r+1;j++) f[j]=f[tot+j-l-r-1];
            f[l+1].b=b[i];
            f[l+1].k=k[i];
        }
        tot=l+r+1;
        double nowb=f[2].b,nowx=0,nowans=0;
        for (int j=2;j<tot;j++) {
            double x=(f[j+1].b-f[j].b)/(f[j].k-f[j+1].k);
            double y=f[j].k*x+f[j].b;
            if (j==tot-1) {
                x=10;
                y=10*f[j].k+f[j].b;
            }
            nowans+=0.5*(x-nowx)*(40000-nowb-y);
            nowb=y;
            nowx=x;
        }
        s[i]+=now-nowans;
        now=nowans;
    }
}
int main() {
    scanf("%d%d",&n,&kg);
    for (int i=1;i<=n;i++)
      for (int j=1;j<=kg+1;j++) scanf("%lf",&a[i][j]);
    for (int i=1;i<=kg;i++) work(i);
    for (int i=1;i<=n;i++) printf("%.12lf\n",0.01*s[i]);
    return 0;
}
