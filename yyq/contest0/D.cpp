#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
map<ll,ll> mp[100010];
const int INF=2147483647;
int n,m,x,y;
char c[3];
int sx,sy;
ll t,tot=0,sum=1;
int dis=INF;
int main()
{
	scanf("%d%d%d%d%s",&n,&m,&x,&y,c+1);
	if(c[1]=='U')
		sx=-1;
	else
		sx=1;
	if(c[2]=='L')
		sy=-1;
	else
		sy=1;
	t=n+m-2;
	if(x==1||x==n||y==1||y==m)
	{
		t--;
		mp[x][y]=1;
	}
	while(1)
	{
		dis=INF;
		tot++;
		if(tot>=1234567)
		{
			puts("-1");
			return 0;
		}
		if(sx==1)
			dis=min(dis,n-x);
		else
			dis=min(dis,x-1);
		if(sy==1)
			dis=min(dis,m-y);
		else
			dis=min(dis,y-1);
//		cout<<dis<<endl;
		x=x+sx*dis;
		y=y+sy*dis;
		sum+=dis;
//		cout<<"x="<<x<<" y="<<y<<" dis="<<dis<<endl;
		if(x==1)
			sx=1;
		else if(x==n)
			sx=-1;
		if(y==1)
			sy=1;
		else if(y==m)
			sy=-1;
		if(!mp[x][y])
		{
			mp[x][y]=1;
			t--;
		}
		if(t==0)
		{
			printf("%I64d\n",sum);
			return 0;
		}
	}
	return 0;
}
