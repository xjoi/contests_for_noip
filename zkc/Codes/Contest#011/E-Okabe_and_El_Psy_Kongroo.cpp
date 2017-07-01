#include <iostream>
#include <fstream>
#include <cstdio>
#include <cstring>
using namespace std;
const long long md=1e9+7;
int n,m,f[50];
long long k;
struct Mat {
    int lenx,leny;
    long long v[50][50];
}ans;

inline Mat mult(Mat x,Mat y) {
    Mat prod;
    prod.lenx=x.lenx;
    prod.leny=y.leny;
    memset(prod.v,0,sizeof prod.v);
    for(int i=1;i<=x.lenx;i++) {
        for(int j=1;j<=y.leny;j++) {
            prod.v[i][j]=0;
            for(int k=1;k<=x.leny;k++) {
                prod.v[i][j]=(prod.v[i][j]+(x.v[i][k]*y.v[k][j])%md)%md;
            }
        }
    }
    return prod;
}

void matinit(Mat &x,int len) {
	x.lenx=len;
	x.leny=len;
    for(int i=1;i<=len;i++) {
        for(int j=1;j<=len;j++) {
            if(i==j) x.v[i][j]=1;
            else x.v[i][j]=0;
        }
    }
}

Mat power(Mat x,long long y) {
    Mat ans;
    matinit(ans,x.lenx);
    while(y) {
        if(y&1) ans=mult(ans,x);
        x=mult(x,x);
        y=y>>1;
    }
    return ans;
}

Mat prepare(int x) {
    Mat res;
    res.lenx=res.leny=16;
    memset(res.v,0,sizeof res.v);
    for(int i=1;i<=x+1;i++) {
        res.v[i][i]=1;
        if(i>1) res.v[i-1][i]=1;
        if(i<=x) res.v[i+1][i]=1;
    }
    return res;
}

int main() {
    scanf("%d%lld",&n,&k);
    memset(f,0,sizeof f);
    ans.lenx=16;
    ans.leny=1;
    ans.v[1][1]=1;
    long long x,y;
    for(int i=1,c;i<=n;i++) {
        scanf("%lld%lld%d",&x,&y,&c);
        Mat temp=prepare(c);
        /*for(int j=1;j<=5;j++) {
            for(int l=1;l<=5;l++) {
                printf("%d ",temp.v[j][l]);
            }
            printf("\n");
        }*/
        temp=power(temp,min(k,y-x));
        k-=(y-x);
        ans=mult(ans,temp);
        /*for(int j=1;j<=16;j++) {
            printf("%d ",ans.v[1][j]);
        }
        printf("\n");*/
    }
    cout<<ans.v[1][1]<<endl;
    return 0;
}