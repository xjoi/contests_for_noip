#include<bits/stdc++.h>
using namespace std;
int n;
struct node{
	int num,give,hao;
}p[300005];
bool cmp(node a,node b)
{
	return a.num<b.num;
}
bool cmp2(node a,node b)
{
	return a.hao<b.hao;
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&p[i].num);
		p[i].hao=i;
	}
	sort(p+1,p+n+1,cmp);
	p[1].give=p[1].num;
	for(int i=2;i<=n;i++)
	{
		if(p[i].num==p[i-1].num||p[i].num<=p[i-1].give)
			p[i].give=p[i-1].give+1;
		else if(p[i].num>p[i-1].give)
			p[i].give=p[i].num;
	}
	sort(p+1,p+n+1,cmp2);
	for(int i=1;i<=n;i++)
		printf("%d ",p[i].give);
	return 0;
}
