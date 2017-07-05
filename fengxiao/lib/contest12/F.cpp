#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
const int N = 5e4+20, M = 1e2+10, mod = 1e9+7, inf = 1e9+1000;
typedef long long ll;
const double INF  = 1E200;
const double EP  = 1E-10;
const int  MAXV = 30000;
const double PI  = 3.14159265;
struct POINT
{
 double x;
 double y;
 POINT(double a=0, double b=0) { x=a; y=b;} //constructor
 POINT operator - (const POINT &b) const {
    return POINT(x - b.x , y - b.y);
 }
  double operator ^ (const POINT &b) const {
    return x*b.y - y*b.x;
 }
};
struct LINE
{
 POINT s;
 POINT e;
 LINE(POINT a, POINT b) { s=a; e=b;}
 LINE() { }
};
int sgn(double x) {if(fabs(x) < EP)return 0;if(x < 0) return  -1;else return 1;}
bool inter(LINE l1,LINE l2) {
    return
    max(l1.s.x,l1.e.x) >= min(l2.s.x,l2.e.x) &&
    max(l2.s.x,l2.e.x) >= min(l1.s.x,l1.e.x) &&
    max(l1.s.y,l1.e.y) >= min(l2.s.y,l2.e.y) &&
    max(l2.s.y,l2.e.y) >= min(l1.s.y,l1.e.y) &&
    sgn((l2.s-l1.e) ^ (l1.s - l1.e))*sgn((l2.e-l1.e) ^ (l1.s-l1.e)) <= 0 &&
    sgn((l1.s-l2.e) ^ (l2.s - l2.e))*sgn((l1.e-l2.e) ^ (l2.s-l2.e)) <= 0;
}
bool onseg(POINT P , LINE L) {
    return
    sgn((L.s-P)^(L.e-P)) == 0 &&
    sgn((P.x - L.s.x) * (P.x - L.e.x)) <= 0 &&
    sgn((P.y - L.s.y) * (P.y - L.e.y)) <= 0;
}
//intersection
POINT p[N];
LINE dg[N];
int n,m,posa[N],posb[N],fa[N],cnt,vis[N];

int finds(int x) {return x==fa[x]?x:fa[x]=finds(fa[x]);}
void unions(int x,int y) {
    int fx = finds(x);
    int fy = finds(y);
    if(fx != fy) fa[fx]  = fy;
}
int main()
{
    scanf("%d%d",&n,&m);

    for(int i=1;i<=n;i++) fa[i] = i;

    for(int i=1;i<=n;i++) {
        double x,y;
        scanf("%lf%lf",&x,&y);
        p[i] = (POINT) {x,y};
    }
    for(int i=1;i<=m;i++) {
        scanf("%d%d",&posa[i],&posb[i]);
        unions(posa[i],posb[i]);
        dg[i] = (LINE) {p[posa[i]],p[posb[i]]};
    }
//з‚№ењЁзєїж®µдёЉ
     for(int i=1;i<=n;i++) {
        for(int j=1;j<=m;j++) {
            if(onseg(p[i],dg[j])) {
               unions(i,posa[j]);
               unions(i,posb[j]);
            }
        }
    }

    POINT pp ;//зєїж®µдє¤з‚№
    for(int i=1;i<=m;i++) {
        for(int j=1;j<=m;j++) {
            if(inter(dg[i],dg[j])) {
                unions(posa[i],posa[j]);
                unions(posa[i],posb[j]);
                unions(posb[i],posa[j]);
                unions(posb[i],posb[j]);
            }
        }
    }



    int all = 1;
    int fi = finds(1);
    for(int i=1;i<=n;i++) {
        if(finds(i)!=fi) {
            puts("NO");return 0;
        }
    }
    puts("YES");

}
