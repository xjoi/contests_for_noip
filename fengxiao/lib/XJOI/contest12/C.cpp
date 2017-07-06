#include<cstdio>
#include<cstring>
#include<cmath>
#define N 1000010
#define pi 3.14159265358979
using namespace std;
double a,ans=0.0;
int n;
struct P {double a,h,l,b;}p[N];
 
int main()
{
    double tmp; int i;
    scanf("%lf",&a); if(a>pi/2) a=pi-a;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        scanf("%lf %lf",&p[i].a,&p[i].b);
        p[i].a/=2; p[i].b/=2;
        p[i].l=p[i].a/sin(p[i].b);
        p[i].h=p[i].a/tan(p[i].b);
    }
    ans+=p[1].l,tmp=p[1].a;
    for(i=2;i<=n;i++)//count right
    {
        double x=tmp*tan(a)/(tan(a)+tan(pi/2-p[i].b))/sin(p[i].b);
        if(x>=p[i].l) tmp-=p[i].h/tan(a);
        else ans+=p[i].l-x,tmp=p[i].a;
    }
    if((pi/2-p[1].b)<a) ans+=p[1].l,tmp=p[1].a;
    else tmp=p[1].h/(tan(a));
    for(i=2;i<=n;i++)//count left
    {
        if((pi/2-p[i].b)>a) {tmp+=p[i].h/tan(a); continue;}
        double x=(tmp*tan(pi/2-a)/(tan(p[i].b)-tan(pi/2-a))+tmp)/sin(p[i].b);
        if(x>=p[i].l) tmp+=p[i].h/tan(a);
        else ans+=p[i].l-x,tmp=p[i].a;
    }
    printf("%.1lf\n",ans+0.001);
    return 0;
}
