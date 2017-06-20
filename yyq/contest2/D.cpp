#include<bits/stdc++.h>
using namespace std;
const int maxn=400005;
int n,m,k;
int tmx[5];
int knum,snum,ans[5];
struct node
{
	int l,r,mx[5];
}tree[maxn];
void build(int l,int r,int index)
{
	tree[index].l=l;
	tree[index].r=r;
	if(l==r)	
	{
		for(int i=0;i<m;i++)
			scanf("%d",tree[index].mx+i);
		return;
	}
	int mid=(l+r)>>1;
	build(l,mid,index<<1);
	build(mid+1,r,index<<1|1);
	int lson=index<<1,rson=index<<1|1;
	for(int i=0;i<m;i++)
		tree[index].mx[i]=max(tree[lson].mx[i],tree[rson].mx[i]);
}
void query(int l,int r,int index)
{
	if(l==tree[index].l&&r==tree[index].r)
	{
		for(int i=0;i<m;i++)
			tmx[i]=max(tmx[i],tree[index].mx[i]);
		return;
	}
	int mid=(tree[index].l+tree[index].r)>>1;
	if(r<=mid)
		query(l,r,index<<1);
	else if(l>mid)
		query(l,r,index<<1|1);
	else
	{
		query(l,mid,index<<1);
		query(mid+1,r,index<<1|1);
	}
}
int main()
{
	cin>>n>>m>>k;
	build(1,n,1);
	int l=1,r=n;
	while(l<=r)
	{
		bool flag=0;
		int mid=(l+r)>>1;
		for(int i=1;i+mid-1<=n;i++)
		{
			memset(tmx,0,sizeof(tmx));
			query(i,i+mid-1,1);
			int sum=0;
			for(int i=0;i<m;i++)
				sum+=tmx[i];
			if(sum<=k)
			{
				flag=1;
				if(knum<mid||(knum==mid&&snum>sum))
				{
					knum=mid;
					snum=sum;
					for(int i=0;i<m;i++)
						ans[i]=tmx[i];
				}
			}
		}
		if(flag)
			l=mid+1;
		else
			r=mid-1;
	}
	cout<<ans[0];
	for(int i=1;i<m;i++)
		cout<<" "<<ans[i];
	cout<<endl;
	return 0;
}
