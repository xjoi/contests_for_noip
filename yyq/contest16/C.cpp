#include<bits/stdc++.h>
#define use_fastio; ios::sync_with_stdio(false);cin.tie(0);
using namespace std;
typedef long long LL;
#define sqr(x) ((x) * (x))
const double eps = 1e-8;
const double inf=1e25;
const double pi=3.1415926535897932384626433;
int sgn(double x) 
{
        return x < -eps ? -1 : x > eps;
}
struct Point;
typedef Point Vector;
struct Point 
{
	double x, y;
	void in() {
		scanf("%lf%lf", &x, &y);
	}
	void print() {
		printf("%.2lf %.2lf\n", x, y);
	}
	Point(double x = 0, double y = 0) : x(x), y(y) {
	}
        inline Vector rotate(double ang) {
                return Vector(x * cos(ang) - y * sin(ang), x * sin(ang) + y * cos(ang));
        }
        inline double dot(const Vector &a) {
                return x * a.x + y * a.y;
        }
        inline bool operator == (const Point &a) const {
                return sgn(x - a.x) == 0 && sgn(y - a.y) == 0;
        }
        inline bool operator < (const Point &a) const {
                return sgn(x - a.x) < 0 || sgn(x - a.x) == 0 && sgn(y - a.y) < 0;
        }
        inline Vector operator + (const Vector &a) const {
                return Vector(x + a.x, y + a.y);
        }
        inline Vector operator - (const Vector &a) const {
                return Vector(x - a.x, y - a.y);
        }
        inline double operator * (const Vector &a) const {
                return x * a.y - y * a.x;
        }
        inline Vector operator * (double t) const {
                return Vector(x * t, y * t);
        }
        inline Vector operator / (double t) {
                return Vector(x / t, y / t);
        }
        inline double vlen() {
                return sqrt(x * x + y * y);
        }
        inline Vector norm() {
                return Point(-y, x);
        }

};

struct Cir
{
        Point ct;
        double r;
        void in() {
                ct.in();
                scanf("%lf", &r);
        }
};
struct Seg 
{
        Point s, e;
        Seg() {
        }
        Seg(Point s, Point e): s(s), e(e) {
        }
        void in() {
                s.in();
                e.in();
        }
};
struct Line
{
        int a, b, c;
};

inline bool cmpyx(const Point &a, const Point &b) 
{
        if(a.y != b.y) {
                return a.y < b.y;
        }
        return a.x < b.x;
}

double cross(Point a, Point b, Point c) 
{
	return (b.x - a.x) * (c.y - a.y) - (c.x - a.x) * (b.y - a.y);
}
bool same_dir(Vector a, Vector b) 
{						
	return sgn(a.x * b.y - b.x * a.y) == 0 && sgn(a.x * b.x) >= 0 && sgn(a.y * b.y) >= 0;
}
bool dot_on_seg(Point p, Seg L) 
{
        return sgn((L.s - p) * (L.e - p)) == 0 && sgn((L.s - p).dot(L.e - p)) <= 0;
}
double ppdis(Point a, Point b) 
{							
	return sqrt((a - b).dot(a - b));
}
double pldis(Point p,Point l1,Point l2)
{					
	return fabs(cross(p,l1,l2))/ppdis(l1,l2);
}
double pldis(Point p, Line ln)  
{								
	return fabs(ln.a * p.x + ln.b * p.y + ln.c) / sqrt(ln.a * ln.a + ln.b * ln.b);
}
bool point_in_circle(Point &a, Cir cr) 
{
	return sgn(ppdis(a, cr.ct) - cr.r) <= 0;
}
bool intersect(Point P, Vector v, Point Q, Vector w, Point &ret) 
{
        Vector u = P - Q;
        if(sgn(v * w) == 0) return false;
        double t = w * u / (v * w);
        ret = P + v * t;
        return true;
}
Point intersect(Point P, Vector v, Point Q, Vector w)
{
        Point ret;
        Vector u = P - Q;
        if(sgn(v * w) == 0) return false;
        double t = w * u / (v * w);
        ret = P + v * t;
        return ret;
}
//µãµ½Ö±Ïß¾àÀë
Point disptoline(Point p, Seg l)
{
        return fabs(cross(p, l.s, l.e)) / ppdis(l.s, l.e);
}
//µãµ½Ö±ÏßµÄ´¹×ã(×î½üµã)
Point ptoline(Point p, Seg l)
{
        Point vec = l.s - l.e;
        return intersect(p, vec.norm(), l.s, vec);
}
//µãµ½Ïß¶ÎµÄ×î½üµã
Point nptoseg(Point p, Seg l)
{
        Point norm = (l.s - l.e).norm();
        if(sgn(norm * (p - l.s)) * sgn(norm * (p - l.e)) > 0) {
                double sa = ppdis(p, l.s);
                double sb = ppdis(p, l.e);
                return sgn(sa - sb) < 0 ? l.s : l.e;
        }
        return intersect(p, norm, l.s, l.e - l.s);
}
Point fptoseg(Point p, Seg l)
{
        if(ppdis(p,l.s)>ppdis(p,l.e))
        	return l.s;
        else
        	return l.e;
}
bool segcross(Point p1, Point p2, Point q1, Point q2) 
{
	return (
			std::min(p1.x, p2.x) <= std::max(q1.x, q2.x) &&
			std::min(q1.x, q2.x) <= std::max(p1.x, p2.x) &&
			std::min(p1.y, p2.y) <= std::max(q1.y, q2.y) &&
			std::min(q1.y, q2.y) <= std::max(p1.y, p2.y) && /* ¿çÁ¢ÊµÑé */
			cross(p1, q2, q1) * cross(p2, q2, q1) <= 0 && 
			cross(q1, p2, p1) * cross(q2, p2, p1) <= 0  /* ²æ»ýÏà³ËÅÐ·½Ïò */
	       );
}
Line turn(Point s, Point e) 
{
	Line ln;
	ln.a = s.y - e.y;
	ln.b = e.x - s.x;
	ln.c = s.x * e.y - e.x * s.y;
	return ln;
}
bool cir_line(Point ct, double r, Point l1, Point l2, Point& p1, Point& p2) 
{
	if ( sgn (pldis(ct, l1, l2) - r ) > 0)
		return false;
	double a1, a2, b1, b2, A, B, C, t1, t2;
	a1 = l2.x - l1.x; a2 = l2.y - l1.y;
	b1 = l1.x - ct.x; b2 = l1.y - ct.y;
	A = a1 * a1 + a2 * a2;
	B = (a1 * b1 + a2 * b2) * 2;
	C = b1 * b1 + b2 * b2 - r * r;
	t1 = (-B - sqrt(B * B - 4.0 * A * C)) / 2.0 / A;
	t2 = (-B + sqrt(B * B - 4.0 * A * C)) / 2.0 / A;
	p1.x = l1.x + a1 * t1; p1.y = l1.y + a2 * t1;
	p2.x = l1.x + a1 * t2; p2.y = l1.y + a2 * t2;
	return true;
}
bool cir_cir(Point c1, double r1, Point c2, double r2, Point& p1, Point& p2) 
{
	double d = ppdis(c1, c2);
	if ( sgn(d - r1 - r2) > 0|| sgn (d - fabs(r1 - r2) ) < 0 )
		return false;
	Point u, v;
	double t = (1 + (r1 * r1 - r2 * r2) / ppdis(c1, c2) / ppdis(c1, c2)) / 2;
	u.x = c1.x + (c2.x - c1.x) * t;
	u.y = c1.y + (c2.y - c1.y) * t;
	v.x = u.x + c1.y - c2.y;
	v.y = u.y + c2.x - c1.x;
	cir_line(c1, r1, u, v, p1, p2);
	return true;
}
double multi(Point &o, Point &a, Point &b) {							// µã»ý
	return (a.x-o.x)*(b.x-o.x) + (a.y-o.y)*(b.y-o.y);
}
double cross(Point &o, Point &a, Point &b) {							// ²æ»ý
	return (a.x-o.x)*(b.y-o.y) - (b.x-o.x)*(a.y-o.y); 
}
double cp(Point &a, Point &b) {									
	return a.x*b.y - b.x*a.y;
}
double angle(Point &a, Point &b) {												// Á½ÏòÁ¿¼Ð½Ç
	double ans = fabs((atan2(a.y, a.x) - atan2(b.y, b.x)));
	return ans > pi+eps ? 2*pi-ans : ans;
}
Point p[100050];
int n;
Point O;
double mi=inf,ma=-inf;
int main() {
//	use_fastio;
	scanf("%d",&n);
	O.in();
	for(int i=1;i<=n;i++)
		p[i].in();
	mi=min(mi,ppdis(O,nptoseg(O,Seg(p[1],p[n]))));
	ma=max(ma,ppdis(O,fptoseg(O,Seg(p[1],p[n]))));
	for(int i=2;i<=n;i++) {
		mi=min(mi,ppdis(O,nptoseg(O,Seg(p[i],p[i-1]))));
		ma=max(ma,ppdis(O,fptoseg(O,Seg(p[i],p[i-1]))));
	}
	cout<<setprecision(18)<<fixed<<pi*(ma*ma-mi*mi)<<endl;
	return 0;
}
