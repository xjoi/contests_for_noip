#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double db;
struct Point{
	db x,y;
}p[8];
ll dis(Point a,Point b)
{
	return (a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y);
}
Point getmid(Point a,Point b)
{
	Point tmp;
	tmp.x=(a.x+b.x)/2.0;
	tmp.y=(a.y+b.y)/2.0;
	return tmp;
}
bool check(int a,int b)
{
	if(a%2==0)
	{
		int c=(a+6)%8,d=(a+2)%8;
		if(dis(p[a],p[c])==dis(p[a],p[d])&&dis(p[b],p[c])==dis(p[b],p[d]))
			return true;
		else
			return false;
	}
	else
	{
		int c,d,e,f;
		if(a==1)
			c=4,d=6,e=0,f=2;
		if(a==3)
			c=0,d=6,e=2,f=4;
		if(dis(p[a],p[c])==dis(p[a],p[d])&&dis(p[b],p[e])==dis(p[b],p[f]))
			return true;
		else
			return false;
	}
}
int main()
{
	int ans=0;
	for(int i=0;i<8;i+=2)
	{
		scanf("%lf%lf",&p[i].x,&p[i].y);
		if(i==0)
			continue;
		else
			p[i-1]=getmid(p[i-2],p[i]);
		p[7]=getmid(p[6],p[0]);
	} 
	for(int i=0;i<4;i+=2)
		if(check(i,i+4))
			ans+=2;
	for(int i=1;i<4;i+=2)
		if(check(i,i+4))
			ans+=2;
	printf("%d\n",ans);
	return 0;
}
