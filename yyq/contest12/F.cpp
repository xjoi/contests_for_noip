#include<bits/stdc++.h>
using namespace std;
const double eps=1e-8;
int dcmp(double d)
{
    return d < -eps ? -1 : d > eps;
}
struct Point{
    double x, y;
    Point() {}
    Point(double x, double y): x(x), y(y) {}
    Point operator + (const Point& a) const {
        return Point(x + a.x, y + a.y);
    }
    Point operator - (const Point& a) const {
        return Point(x - a.x, y - a.y);
    }
    Point operator * (double k) const {
        return Point(x * k, y * k);
    }
    Point operator / (double k) const {
        return Point(x / k, y / k);
    }
    double cross(const Point& a) const {
        return (x * a.y - y * a.x);
    }
    double dot(const Point& a) const {
        return x * a.x + y * a.y;
    }
    void read(){
        scanf("%lf%lf", &x, &y);
    }
    bool operator < (const Point& a) const {
        return x < a.x || (x == a.x && y < a.y);
    }
    bool operator == (const Point& a) const {
        return dcmp(x - a.x) == 0 && dcmp(y - a.y) == 0;
    }
    double length() {
        return sqrt(x * x + y * y);
    }
};
struct Line{
    Point a, b;
    Line() {}
    Line(const Point& a, const Point& b):a(a),b(b){}
    bool onSegment(Point p)
	{
        return dcmp((p-a).cross(b-a))==0&&dcmp((a-p).dot(b-p))<=0;
    }
    int segCrossSeg(const Line &u)
	{
        int d1=dcmp((b-u.a).cross(a-u.a));
        int d2=dcmp((b-u.b).cross(a-u.b));
        int d3=dcmp((u.b-a).cross(u.a-a));
        int d4=dcmp((u.b-b).cross(u.a-b));
        if ((d1^d2)==-2&&(d3^d4)==-2)
			return 2;
        return ((d1==0&&dcmp((b-u.a).dot(a-u.a))<=0)||(d2==0&&dcmp((b-u.b).dot(a-u.b))<=0)||(d3==0&&dcmp((u.b-a).dot(u.a-a))<=0)||(d4==0&&dcmp((u.b-b).dot(u.a-b))<=0));
    }
};
Point p[250];
int fa[250];
int eu[250],ev[250];
int n,m;
void init()
{
	for(int i=1;i<=250;i++)
		fa[i]=-1;
}
int getfa(int x)
{
	return fa[x]==-1?x:fa[x]=getfa(fa[x]);
}
int main()
{
	cin>>n>>m;
	init();
	for(int i=1;i<=n;i++)
		p[i].read();
	for(int i=1;i<=m;i++)
	{
		cin>>eu[i]>>ev[i];
		int fu=getfa(eu[i]);
		int fv=getfa(ev[i]);
		if(fu!=fv)
			fa[fu]=fv;
	}
	for(int i=1;i<=m;i++)
	{
		Line l(p[eu[i]],p[ev[i]]);
		for(int j=1;j<=n;j++)
		{
			if(l.onSegment(p[j])==0)
				continue;
			int fu=getfa(j);
			int fv=getfa(eu[i]);
			if(fu!=fv)
				fa[fu]=fv;
		}
	}
	for(int i=1;i<=m;i++)
		for(int j=i+1;j<=m;j++)
		{
			Line l1(p[eu[i]],p[ev[i]]);
			Line l2(p[eu[j]],p[ev[j]]);
			if(l1.segCrossSeg(l2)==0)
				continue;
			int fu=getfa(eu[j]);
			int fv=getfa(eu[i]);
			if(fu!=fv)
				fa[fu]=fv;
		}
	int cnt=0;
	bool flg=true;
	for(int i=1;i<=n;i++)
		if(fa[i]==-1)
			cnt++;
	if(cnt==1)
		puts("YES");
	else
		puts("NO");
    return 0;
}
