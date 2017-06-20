#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<climits>
#include<cmath>
#include<cctype>
using namespace std;
int n,m,k;
int a[100005],x[100005];
int cmp[100005];
int main() {
    while(~scanf("%d%d%d",&n,&m,&k)) {
        for(int i=1; i<=n; i++)
            scanf("%d",&a[i]);
        for(int i=1; i<=m; i++)
            scanf("%d",&x[i]);
        for(int i=1; i<m; i++) {
            if(x[i]<x[i+1])
                cmp[i]=-1;
            else if(x[i]==x[i+1])
                cmp[i]=0;
            else if(x[i]>x[i+1])
                cmp[i]=1;
        }
        int ans=0;
        for(int i=1; i<=n-m+1; i++) {
            int l=i,r=l+m-1,comp;
            bool flg=true;
            //		printf("Case %d#:\n",i);
            for(int p=l; p<r; p++) {
                if(a[p]<a[p+1])
                    comp=-1;
                else if(a[p]==a[p+1])
                    comp=0;
                else if(a[p]>a[p+1])
                    comp=1;
                //			printf("%d:%d--%d\n",p,comp,cmp[p-l+1]);
                if(comp!=cmp[p-l+1]) {
                    flg=false;
                    break;
                }
            }
            if(flg) {
                ans++;
                i=r;
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
