#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
const double eps=1e-8;
struct Point{
	double x,y;
	void in()
	{
		scanf("%lf%lf",&x,&y);
	}
	Point ()
	{
	}
	Point (double x,double y):x(x),y(y)
	{
	}
	Point operator + (Point a)
	{
		return Point(x+a.x,y+a.y);
	}
	Point operator / (double a)
	{
		return Point(x/a,y/a);
	}
	double dot(Point a)
	{
		return x*a.x+y*a.y;
	}
	Point operator - (Point a)
	{
		return Point(x-a.x,y-a.y);
	}
	double operator * (Point a)
	{
		return x*a.y-y*a.x;
	}
}p[210];
int sgn(double x)
{
	return x<-eps?-1:x>eps;
}
int a[210],b[210];
bool dot_on_seg(Point p,Point a,Point b)
{
	return sgn((a-p)*(b-p))==0 && sgn((a-p).dot(b-p))<=0;
}
double cross(Point a,Point b,Point c)
{
	return (b.x-a.x)*(c.y-a.y)-(c.x-a.x)*(b.y-a.y);
}
bool intersect(Point p1,Point p2,Point q1,Point q2)
{
	return (
	            std::min(p1.x,p2.x)<=std::max(q1.x,q2.x) &&
	            std::min(q1.x,q2.x)<=std::max(p1.x,p2.x) &&
	            std::min(p1.y,p2.y)<=std::max(q1.y,q2.y) &&
	            std::min(q1.y,q2.y)<=std::max(p1.y,p2.y) &&
	            cross(p1,q2,q1)*cross(p2,q2,q1)<=0 &&
	            cross(q1,p2,p1)*cross(q2,p2,p1)<=0
	       );
}
int f[210];
int find(int x)
{
	return x==f[x]?x:f[x]=find(f[x]);
}
void Unio(int a,int b)
{
	int fa=find(a);
	int fb=find(b);
	if (fa==fb) return;
	f[fa]=fb;
}
int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	for (int i=0;i<n;++i)
	{
		p[i].in();
	}
	for (int i=0;i<n;++i)
	f[i]=i;
	for (int i=0;i<m;++i)
	{
		scanf("%d%d",&a[i],&b[i]);
		a[i]--;
		b[i]--;
		Unio(a[i],b[i]);
		for (int j=0;j<n;++j)
		if (j!=a[i]&&j!=b[i])
		{
			if (dot_on_seg(p[j],p[a[i]],p[b[i]]))
			{
				Unio(a[i],j);
			}
		}
		for (int j=0;j<i;++j)
		{
			if (intersect(p[a[i]],p[b[i]],p[a[j]],p[b[j]]))
			{
				Unio(a[i],a[j]);
			}
		}
	}
	for (int i=0;i<n;++i)
	{
		if (find(i)!=find(0))
		{
			puts("NO");
			return 0;
		}
	}
	puts("YES");
	return 0;
}
