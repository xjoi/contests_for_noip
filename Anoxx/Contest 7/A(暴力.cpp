#include<cstdio>
using namespace std;
int n,m,k,x[100100],a[100100],x_sml[100100],x_big[100100],a_sml[100100],a_big[100100],ans;
bool judge(int x) {
    for(int i=x; i<=x+m-1; i++)if(x_sml[i]-x_sml[x]!=a_sml[i-x+1]-a_sml[1]||x_big[i]-x_big[x]!=a_big[i-x+1]-a_big[1])return 0;
    return 1;
}
int main() {
    while(scanf("%d%d%d",&n,&m,&k)==3) {
        for(int i=1; i<=n; i++)scanf("%d",&x[i]);
        for(int i=1; i<=m; i++)scanf("%d",&a[i]);
        ans=0;
        x_sml[1]=x_big[1]=a_sml[1]=a_big[1]=0;
        for(int i=2; i<=n; i++)x_sml[i]=x_sml[i-1]+(x[i-1]<x[i]),x_big[i]=x_big[i-1]+(x[i-1]>x[i]);
        for(int i=2; i<=m; i++)a_sml[i]=a_sml[i-1]+(a[i-1]<a[i]),a_big[i]=a_big[i-1]+(a[i-1]>a[i]);
        int i=1;
        while(i+m<=n+1)
            if(judge(i)) {
                ans++;
                i+=m;
            } else i++;
        printf("%d\n",ans);
    }

}
