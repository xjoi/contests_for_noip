#include<cstdio>
#include<cstring>
#include<iostream>
#include<cmath>
#define pdd pair<double,double>
#define mp make_pair
#define F first
#define S second
using namespace std;
pdd a,b,c,d,e,f,g,h;
int ans=0;
void print()
{
	printf("%lf %lf\n",a.F,a.S);
	printf("%lf %lf\n",b.F,b.S);
	printf("%lf %lf\n",c.F,c.S);
	printf("%lf %lf\n",d.F,d.S);
	printf("%lf %lf\n",e.F,e.S);
	printf("%lf %lf\n",f.F,f.S);
	printf("%lf %lf\n",g.F,g.S);
	printf("%lf %lf\n",h.F,h.S);
	                            	
}
double get_dis(pdd a,pdd b) {return sqrt((a.F-b.F)*(a.F-b.F)+(a.S-b.S)*(a.S-b.S));}
bool eq(double a,double b) {return fabs(a-b)<0.000001;}
pdd zd(pdd a,pdd b) {return mp((a.F+b.F)/2,(a.S+b.S)/2);}
bool cz(pdd a,pdd b,pdd c,pdd d)
{  
    if(!eq(a.F,b.F) && !eq(c.F,d.F))  return eq(((a.S-b.S)*(c.S-d.S))/((a.F-b.F)*(c.F-d.F)),-1);  
    if(eq(a.F,b.F)) return eq(c.S,d.S);
    if(eq(c.F,d.F)) return eq(a.S,b.S);
}

int main()
{
	double x,y;
	scanf("%lf %lf",&x,&y); a=mp(x,y);
	scanf("%lf %lf",&x,&y); b=mp(x,y);
	scanf("%lf %lf",&x,&y); c=mp(x,y);
	scanf("%lf %lf",&x,&y); d=mp(x,y);
	e=zd(a,b);f=zd(b,c);g=zd(c,d),h=zd(d,a);
	//print();
	if(cz(a,c,b,d))
	{
		if(eq(get_dis(a,b),get_dis(a,d)) && eq(get_dis(c,b),get_dis(c,d))) ans++;
		if(eq(get_dis(b,a),get_dis(b,c)) && eq(get_dis(d,a),get_dis(d,c))) ans++;
	}
	if(cz(e,g,a,b) && cz(e,g,c,d)) ans++;
	if(cz(f,h,b,c) && cz(f,h,a,d)) ans++;
	ans<<=1;
	printf("%d",ans);
	return 0;
}
