#include<cstdio>
#include<iostream>
#define xxx 333
#define yyy 2332333
#define eps 0.000001
using namespace std;
struct point{
	double x,y;
}a[xxx];
struct line{
	double k,b;
};
struct area{
	point st,en;
	line l;
	int bel;
}room[yyy];
int n,m,cnt;

line get_line(point c,point d) {
	double tk,tb; 
	tk=(c.y-d.y)/(c.x-d.x);
	tb=c.y-tk*c.x;
	return (line){tk,tb};
}

point cross(line l1,line l2)
{
	double tx,ty;
	tx=(l2.b-l1.b)/(l1.k-l2.k);
	ty=l1.k*tx+l1.b;
	return (point){tx,ty};
}

double doit(int t,point le,point ri)
{
	line tl=get_line(le,ri);
	le=(point){room[t].st.x,tl.k*room[t].st.x+tl.b};
	ri=(point){room[t].en.x,tl.k*room[t].en.x+tl.b};
	if (le.y<=room[t].st.y+eps&&ri.y<=room[t].en.y+eps) return (double)0;
	if ((le.y>=room[t].st.y-eps&&ri.y>=room[t].en.y-eps))
	{
		double turn=(le.y+ri.y-room[t].st.y-room[t].en.y)*(room[t].en.x-room[t].st.x)/2;
		room[t].st=le;room[t].en=ri;
		room[t].l=tl;
		return turn;
	}
	point cr=cross(tl,room[t].l);
	cnt++;
	room[cnt].st=cr;room[cnt].en=room[t].en;
	room[cnt].l=get_line(room[cnt].st,room[cnt].en);
	room[cnt].bel=room[t].bel;
	
	room[t].en=cr;
	room[t].l=get_line(room[t].st,room[t].en);
	return doit(t,le,ri);
}

int main()
{
	scanf("%d%d",&n,&m);
	cnt=m;
	for (int i=1;i<=cnt;i++)
	{
		room[i].st=(point){i-1,0};
		room[i].en=(point){i,0};
		room[i].l=get_line(room[i].st,room[i].en);
		room[i].bel=i;
	}
	double ans;
	for (int ttt=1;ttt<=n;ttt++)
	{
		ans=0;
		for (int i=0;i<=m;i++)
		{
			scanf("%lf",&a[i].y);
			a[i].x=i;
		}
		for (int i=1;i<=cnt;i++)
			ans+=doit(i,a[room[i].bel-1],a[room[i].bel]);
		printf("%.10lf\n",ans);
	}
		
}
