#include <bits/stdc++.h>
using namespace std;
const double eps=1e-32;
struct node {
    double x,y;
    int w;
} a[200010],b[200010];
int f[200010],ans[200010],n,top=0;

inline double dcmp(double x) {
    if(fabs(x)<eps) return 0;
    else if(x>0) return 1;
    else if(x<0) return -1;
}

bool cmp(node a,node b) {
    if(dcmp(a.x-b.x)==-1) return true;
    else if(dcmp(a.x-b.x)==1) return false;
    else if(dcmp(a.y-b.y)>=0) return true;
    else return false;
}

double cross(node x1,node x2,node y1,node y2) {
    double dx1=x1.x-x2.x, dy1=x1.y-x2.y, dx2=y1.x-y2.x, dy2=y1.y-y2.y;
    return dx1*dy2-dx2*dy1;
}

bool same(node a,node b) {
    if(dcmp(a.x-b.x)==0&&dcmp(a.y-b.y)==0) return true;
    return false;
}

int main() {
    scanf("%d",&n);
    int jx,jy;
    for(int i=1; i<=n; i++) {
        scanf("%d %d",&jx,&jy);
        a[i].x=(double)(1.0/jx);
        a[i].y=(double)(1.0/jy);
        a[i].w=i;
        b[i]=a[i];
    }
    a[0].w=0;
    a[0].y=1e9;
    a[0].x=0;
    a[n+1].w=n+1;
    a[n+1].x=1e9;
    a[n+1].y=0;
    b[0]=a[0];
    b[n+1]=a[n+1];
    sort(a+1,a+1+n,cmp);
    memset(f,0,sizeof f);
    top=0;
    for(int i=0; i<=n+1; i++) {
        while(top>1&&dcmp(cross(b[a[f[top]].w],b[a[f[top-1]].w],a[i],b[a[f[top-1]].w]))<=0) top--;
        top++;
        f[top]=i;
    }
    int tmp=top;
    for(int i=1; i<=tmp; i++) {
        if(f[i]==0||f[i]==n+1) continue;
        int j=f[i]-1;
        while(j>0&&same(b[a[j].w],b[a[j+1].w])) {
            top++;
            f[top]=j;
            j--;
        }
    }
    for(int i=1; i<=top; i++) f[i]=a[f[i]].w;
    sort(f+1,f+1+top);
    for(int i=1; i<=top; i++) if(f[i]!=0&&f[i]!=n+1) printf("%d ",f[i]);
}
