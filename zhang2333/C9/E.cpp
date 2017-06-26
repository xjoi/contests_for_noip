#include<cstdio>
#include<iostream>
#include<algorithm>
#include<vector>
#define xxx 201000
#define yyy 2332333
#define inf 233233233233
using namespace std;
int n,m,tot,a[xxx],b[xxx],c[xxx];
struct line_tree{
	long long ans,sum,siz;
}tr[yyy];
struct point{
	long long v;
	int bel,seat;
}nod[xxx];
vector<int>pos[xxx];
int wei[xxx];
long long real[xxx],full[xxx];

bool cmp(point p1,point p2)
{
	return p1.v<p2.v;
}

line_tree update(line_tree t1,line_tree t2)
{
	line_tree t3;
	t3.siz=t1.siz+t2.siz;
	t3.sum=t1.sum+t2.sum;
	t3.ans=t1.ans+t2.ans+t1.siz*t2.sum-t2.siz*t1.sum;
	return t3;
}
void build(int x,int l,int r)
{
	if (l==r)
	{
		tr[x].siz = real[l]!=inf?1:0;
		tr[x].sum = real[l]!=inf?real[l]:0;
		tr[x].ans = 0;
	//printf("%d %d %d %lld %lld %lld\n",x,l,r,tr[x].siz,tr[x].sum,tr[x].ans);
		return;
	}
	int mid=(l+r)>>1;
	build(x<<1,l,mid);
	build(x<<1|1,mid+1,r);
	tr[x]=update(tr[x<<1],tr[x<<1|1]);
	//printf("%d %d %d %lld %lld %lld\n",x,l,r,tr[x].siz,tr[x].sum,tr[x].ans);
}
void chg(int x,int l,int r,int p)
{
	if (l==r)
	{
		tr[x].siz = real[l]!=inf?1:0;
		tr[x].sum = real[l]!=inf?real[l]:0;
		tr[x].ans = 0;
		return;
	}
	int mid=(l+r)>>1;
	if (p<=mid) chg(x<<1,l,mid,p);
	else chg(x<<1|1,mid+1,r,p);
	tr[x]=update(tr[x<<1],tr[x<<1|1]);
}
line_tree que(int x,int l,int r,int st,int en)
{
	if (l==st&&r==en) return tr[x];
	int mid=(l+r)>>1;
	if (en<=mid) return que(x<<1,l,mid,st,en);
	if (st>mid)  return que(x<<1|1,mid+1,r,st,en);
	return update(que(x<<1,l,mid,st,mid),que(x<<1|1,mid+1,r,mid+1,en));
}

void pri()
{
	for (int i=1;i<=tot*2;i++)
	{
		printf(" %d:%lld %lld %lld\n",i,tr[i].siz,tr[i].sum,tr[i].ans);
	}
}

int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
	{
		scanf("%I64d",&nod[i].v);
		nod[i].bel=i;
		nod[i].seat=0;
		pos[i].push_back(i);
	}
	tot=n;
	scanf("%d",&m);
	for (int i=1;i<=m;i++)
	{
		scanf("%d%d%d",&a[i],&b[i],&c[i]);
		if (a[i]==1)
		{
			tot++;
			nod[tot].v= nod[ pos[b[i]][ pos[b[i]].size() -1 ] ].v+c[i];
			nod[tot].seat=pos[b[i]].size();
			nod[tot].bel=b[i];
			pos[b[i]].push_back(tot);
		}
	}
	sort(nod+1,nod+tot+1,cmp);
	for (int i=1;i<=tot;i++)
	{
		pos[nod[i].bel][nod[i].seat]=i;
		full[i]=nod[i].v;
	}
	
	if (0)
	{
		printf("%d\n",tot);
		for (int i=1;i<=tot;i++) printf(" %lld(%d)\n",full[i],i);printf("\n");
		for (int i=1;i<=n;i++)
		{
			printf("%d(%d):",i,pos[i].size());
			for (int j=0;j<pos[i].size();j++)
				printf(" %d",pos[i][j]);
			printf("\n");
		}
	}
	
	for (int i=1;i<=tot;i++)
		real[i]=inf;
	for (int i=1;i<=n;i++)
		real[pos[i][0]]=full[pos[i][0]];
	//for (int i=1;i<=tot;i++)printf("%lld(%d)\n ",real[i],i);printf("\n");
	build(1,1,tot);
	
	//for (int i=1;i<=tot;i++) printf(" %lld(%d)\n",full[i],i);printf("\n");
	
	int st,en;
	for (int i=1;i<=m;i++)
	{
		if (a[i]==2)
		{
			st=lower_bound(full+1,full+tot+1,(long long)b[i])-full;
			en=lower_bound(full+1,full+tot+1,(long long)c[i]+1)-full;
			while ((en>tot||full[en]>c[i])&&en>=0) en--;
			//printf("  %d(%d) %d(%d)\n",b[i],st,c[i],en);
			if (st<=en)
				printf("%lld\n",que(1,1,tot,st,en).ans);
			else
				printf("0\n");
		}
		else
		{
			wei[b[i]]++;
			real[ pos[ b[i] ][ wei[b[i]]-1 ] ] = inf;
			chg( 1,1,tot,pos[ b[i] ][ wei[b[i]]-1 ] );
			real[ pos[ b[i] ][ wei[b[i]] ] ]=full[ pos[b [i] ][ wei[b[i]] ] ];
			chg( 1,1,tot,pos[ b[i] ][ wei[b[i]] ] );
			//for (int i=1;i<=tot;i++)printf("%lld(%d)\n ",real[i],i);printf("\n");
		}
		//pri();printf("%d %d %d\n",a[i],b[i],c[i]);scanf("%d",&a[i]);
	}
}
