#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#define xxx 200100
using namespace std;
struct bridge{
	long long v,p;
}b[xxx];
struct dis{
	long long real_l,real_r,pos;
}d[xxx];
long long n,m,l[xxx],r[xxx],realb[xxx],low,ans[xxx];
bool flag[xxx]={0},used[xxx]={0};
struct haha{
    long long x,y;
}tem;
struct cmp{
    bool operator()(haha &a,haha &b){
        return a.y>b.y;
    }
};
priority_queue<haha,vector<haha>,cmp>q;

int cpb(bridge b1,bridge b2)
{
	return b1.v<b2.v;
}
int cpd(dis d1,dis d2)
{
	return d1.real_l<d2.real_l;
}

int main()
{
	long long x,y;
	scanf("%I64d%I64d",&n,&m);
	for (int i=1;i<=n;i++)
		scanf("%I64d%I64d",&l[i],&r[i]);
	for (int i=1;i<=m;i++)
	{
		scanf("%I64d",&b[i].v);
		b[i].p=i;
	}
	if (n>m+1)
	{
		printf("No");
		return 0;
	}
	sort(b+1,b+m+1,cpb);
	for (int i=1;i<=m;i++)
		realb[i]=b[i].v;
			//	for (int i=1;i<=m;i++) printf("%lld ",realb[i]);printf("\n");
	n--;
	for (int i=1;i<=n;i++)
	{
		x=lower_bound(realb+1,realb+m+1,l[i+1]-r[i])-realb;
		y=lower_bound(realb+1,realb+m+1,r[i+1]-l[i]+1)-realb;
		//printf("   %lld %lld\n",x,y);
		while ((r[i+1]-l[i]<realb[y]||y>m)&&y>=0) y--;
		//printf("   %lld %lld\n",x,y);
		if (x>y)
		{
			printf("No");
			return 0;
		}
		d[i].real_l=x;
		d[i].real_r=y;
		d[i].pos=i;
		//printf(" %lld %lld %lld\n",d[i].real_l,d[i].real_r,d[i].pos);
	}
	sort(d+1,d+n+1,cpd);
	int p=1;
	for (int i=1;i<=m;i++)
	{
		while (d[p].real_l==i&&p<=n) 
		{
			q.push((haha){p,d[p].real_r});
			p++;
		}
		if (!q.empty())
		{
			tem=q.top();q.pop();
			if (i>tem.y)
			{
				printf("No");
				return 0;
			}
			ans[d[tem.x].pos]=i;
		}
	}
	
	printf("Yes\n");
	for (int i=1;i<=n;i++)
		printf("%I64d ",b[ans[i]].p);
}
