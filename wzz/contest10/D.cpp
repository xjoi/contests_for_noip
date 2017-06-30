using namespace std;
#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<cstring>
#include<queue>
#define N 400001
#define F(i,a,b) for(int i=a;i<=b;i++)
#define ll long long
#define ub upper_bound
struct is{
	ll mind,maxd;
	int no;
	friend bool operator <(is a,is b)
	{
		return a.maxd>b.maxd;
	}
}xx[N],what;
priority_queue<is>q;
struct bri{
	ll len;
	int no;
}yy[N];
bool cmp1(is a,is b)
{
	if(a.mind!=b.mind)
	return a.mind<b.mind;else return a.maxd<b.maxd;
}
bool cmp(bri a,bri b)
{
	return a.len<b.len;
}
int n,m;
ll f[N],k[N];
int cnt=0;
bool vis[N];
int pos[N];
int loc[N];
int tot;
int from[N];
int no[N];
ll mind[N];
ll maxd[N];
int wzz=0;
int main()
{
	cin>>n>>m;
	if(n<=1)
	{
		puts("Yes");while(1);return 0;
	}
	for(int i=1;i<=n;i++)
	{
		cin>>f[i]>>k[i];
	}
	for(int i=1;i<=m;i++)
	{
		cin>>yy[i].len; yy[i].no=i;
	}
	for(int i=1;i<=n-1;i++)
	{
		xx[i].mind=f[i+1]-k[i];
		xx[i].maxd=k[i+1]-f[i];
		xx[i].no=i;
	}
	sort(xx+1,xx+n,cmp1);
	sort(yy+1,yy+m+1,cmp);
	for(int i=1;i<=n-1;i++) {mind[i]=xx[i].mind;maxd[i]=xx[i].maxd;no[i]=xx[i].no;}
	int it=0;
	for(int i=1;i<=m;i++)
	{
		if(wzz==n-1) break;
		int L=ub(mind+it+1,mind+n,yy[i].len)-mind-1;
//		cout<<yy[i].len<<" "<<L<<endl;
		for(int j=it+1;j<=L;j++) 
		{
			what.no=no[j];what.mind=mind[j];
			what.maxd=maxd[j];
			q.push(what);
		}
		if(!q.empty())
		{
			what=q.top();
			q.pop();
//			cout<<what.no<<endl;
			if(what.maxd<yy[i].len)
			{
				puts("No");return 0;
			}
			else 
			{
				from[what.no]=yy[i].no;
				wzz++;
			}
		}
		it=L;
	}
	if(wzz<n-1)
	{
		puts("No");return 0;
	}
	puts("Yes");
	for(int i=1;i<=n-1;i++)cout<<from[i]<<" ";
}
	
