#include <cstdio>  
#include <iostream>  
#include <cmath>
#define eps 0.0000001
using namespace std;
int ans=0;

struct P{
	double x,y;
}p[5];
struct L{
	double a,b,c;
}l[5];

L line(P p1,P p2)
{
	return (L){p2.y-p1.y,p1.x-p2.x,-p2.y*p1.x+p2.x*p1.y};
}

bool cz(L l1,L l2)
{
	if (abs(l1.a*l2.a+l1.b*l2.b)<eps) return 1;
	return 0;
}

double dis(L l1,P p1)
{
	return ( abs( (l1.a*p1.x+l1.b*p1.y+l1.c) / sqrt(pow(l1.a,2)+pow(l1.b,2)) ) );
}

bool px(L l1,L l2)
{
	if (abs(l1.a*l2.b-l1.b*l2.a)<=eps) return 1;
	return 0;
}

P mid(P p1,P p2)
{
	return (P){(p1.x+p2.x)/2,(p1.y+p2.y)/2};
}

void doit(P p1,P p2,L l2)
{
	L l1=line(p1,p2);
	if (!cz(l1,l2)) return;//printf("aso\n");
	ans+=2;return;
}

int main()
{
	for (int i=1;i<=4;i++)
		cin>>p[i].x>>p[i].y;
	p[0]=p[4];
	for (int i=1;i<=4;i++)
		l[i]=line(p[i-1],p[i]);
	if (cz(line(p[1],p[3]),line(p[2],p[4])))
	{
		if (abs(dis(line(p[1],p[3]),p[2])-dis(line(p[1],p[3]),p[4]))<eps)
			ans+=2;
		if (abs(dis(line(p[2],p[4]),p[1])-dis(line(p[2],p[4]),p[3]))<eps)
			ans+=2;
	}
	
	if (px(l[1],l[3])) doit(mid(p[0],p[1]),mid(p[2],p[3]),l[1]);
	if (px(l[2],l[4])) doit(mid(p[1],p[2]),mid(p[3],p[4]),l[2]);
	cout<<ans;
}
