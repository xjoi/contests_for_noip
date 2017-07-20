#include<cstdio>  
#include<cstdlib>  
#include<cstring>  
#include<cmath>  
#include<algorithm>
using namespace std;
const double eps=1e-8,pi=acos(-1.0);
struct Poi{double x,y;}p[100010],sta[100010];
inline Poi poi(double x,double y) {Poi tmp; tmp.x=x; tmp.y=y; return tmp;}
struct Seg{Poi a,b;}s[100010];
inline Seg seg(Poi x,Poi y) {Seg tmp; tmp.a=x; tmp.b=y; return tmp;}
inline void swap(double &x,double &y) {double t=x; x=y; y=t;}
int sgn(double x){return x<-eps ? -1 : x>eps;} 
double cj(Poi p1,Poi p2,Poi p3){return (p3.x-p1.x)*(p2.y-p1.y)-(p3.y-p1.y)*(p2.x-p1.x);  }  
double dist(Poi a,Poi b){return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));  }  
bool cmp(Poi a,Poi b)
{  
    int tmp=sgn(cj(p[0],a,b));
    return tmp==0 ? dist(p[0],a)-dist(p[0],b)<=0 : tmp>0;  
}
Poi operator + (Poi a,Poi b) {return poi(a.x+b.x,a.y+b.y);}
Poi operator - (Poi a,Poi b) {return poi(a.x-b.x,a.y-b.y);}
double operator * (Poi a,Poi b) {return a.x*b.y-b.x*a.y;}
Poi operator * (Poi a,double t) {return poi(a.x*t,a.y*t);}
double dot(Poi a,Poi b) {return a.x*b.x+a.y*b.y;}
bool P_on_S(Poi p, Seg l) {return sgn((l.a-p)*(l.b-p)) == 0 && sgn(dot(l.a-p,l.b-p)) <= 0;}
bool intersect(Poi P,Poi v,Poi Q,Poi w,Poi &ret) 
{
    Poi u=P-Q;
    if(sgn(v*w)==0) return false;
    double t=w*u/(v*w);
    ret=P+v*t;
    return true;
}
bool disps(Poi p, Seg l,double &tmp)
{
    Poi vec = l.a - l.b; Poi pp;
    if(!intersect(p,poi(-vec.y,vec.x),l.a,vec,pp)) return false;
    if(!P_on_S(pp,l)) return false;
    tmp=dist(p,pp);
    return true;
}
int main()  
{  
    int T,i,cnt=0,n,r;  
    scanf("%d %lf %lf",&n,&p[0].x,&p[0].y);
    int pos=1;
    for(i=1;i<=n;i++)
	{  
        scanf("%lf %lf",&p[i].x,&p[i].y);
    }  
    for(i=1;i<n;i++) s[i]=seg(p[i],p[i+1]);
    s[n]=seg(p[1],p[n]);
    double midis=100000000.0,madis=0.0;
	for(i=1;i<=n;i++) {double tmp;/* printf("?%d?",disps(p[0],s[i],tmp));*/ if(disps(p[0],s[i],tmp) && tmp<midis) midis=tmp;}
	
	for(i=1;i<=n;i++) {double tmp=dist(p[i],p[0]);if(tmp>madis) madis=tmp; if(tmp<midis) midis=tmp;}//printf("!%lf %lf %lf!\n",midis,madis,tmp);
	//printf("#%lf %lf %lf %lf %lf#",dist(p[3],p[0]),p[0].x,p[0].y,p[3].x,p[3].y);
	double ans=pi*(madis+midis)*(madis-midis);
	printf("%.8lf",ans);
    return 0;  
}  
