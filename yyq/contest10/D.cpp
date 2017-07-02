#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
struct Island
{
	ll l,r;
	int no;
	bool operator <(Island one) const
	{
		return r>one.r;
	}
}island[200010];
bool cmp(Island one,Island two)
{
	return one.l<two.l;
}
struct Bridge
{
	ll len;
	int no;	
}bridge[int(2e5)+10];
bool cmp1(Bridge one,Bridge two)
{
	return one.len<two.len;
}
priority_queue<Island>qq;
int ans[int(2e5)+10];
int main()
{
	int n,m;
	cin>>n>>m;
	ll pl,pr;
	for(int i=0;i<n;i++)
	{
		ll l,r;
		cin>>l>>r;
		if(i>0)
		{
			island[i-1].l=l-pr;
			island[i-1].r=r-pl;
			island[i-1].no=i-1;
		}
		pl=l;
		pr=r;
	}
	sort(island,island+n-1,cmp);
	for(int i=0;i<m;i++)
	{
		cin>>bridge[i].len;
		bridge[i].no=i;
	}
	sort(bridge,bridge+m,cmp1);
	int sum=0;
	for(int i=0,j=0;i<m;i++)
	{
		while(j<n-1&&island[j].l<=bridge[i].len&&bridge[i].len<=island[j].r)
			qq.push(island[j++]);
		if(qq.empty())
			continue;
		Island t=qq.top();
		qq.pop();
		if(bridge[i].len>t.r)
		{
			puts("No");
			return 0;
		}
		ans[t.no]=bridge[i].no;
		sum++;
	}
	if(sum<n-1)
	{
		puts("No");
		return 0;
	}
	puts("Yes");
	for(int i=0;i<n-1;i++)
	{
		if(i)
			cout<<" ";
		cout<<ans[i]+1;
	}
	cout<<endl;
	return 0;
}
