#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#define int long long
#define N 100010
using namespace std;
int n,m,A,cf,cm;
struct P {int v,pos;} a[N];
int sum[N],sum1[N];
int ans,p,Num;
bool cmp(P a,P b) {return a.v<b.v;}
bool cmp1(P a,P b) {return a.pos<b.pos;}
bool judge(int x,int sum,int pos)
{
	int l=pos,r=n+1,mid;
	while(l<r)
	{
		mid=(l+r)>>1;
		if(a[mid].v>x) r=mid;
		else l=mid+1;
		//puts("?");
	}
	if(l==pos) l++;
	//printf("%I64d %I64d,%I64d %I64d\n",l,r,sum,sum1[l]-(n-l+1)*x);
	if(sum-(sum1[l]-(n-l+1)*x)>=0) return true;
	return false;
}
int calc(int x,int pos)
{
	int l=0,r=A+1;
	while(l<r)
	{
		int mid=(l+r)>>1;
		if(judge(mid,x,pos)) r=mid;
		else l=mid+1;
	}
	//if(!judge(l,x,pos)) l++;
	return l;
}
main()
{
	int i,j;
	//freopen("data.in","r",stdin);
	scanf("%I64d %I64d %I64d %I64d %I64d",&n,&A,&cf,&cm,&m);// printf("?%I64d?",n);
	for(i=1;i<=n;i++) {scanf("%I64d",&a[i].v); a[i].v=A-a[i].v; a[i].pos=i;};
	sort(a+1,a+n+1,cmp);
	for(i=1;i<=n;i++) sum[i]=sum[i-1]+a[i].v;
	for(i=n;i>=1;i--) sum1[i]=sum1[i+1]+a[i].v;
	for(i=0;i<=n;i++)
		if(sum[i]<=m)
		{
			int num=calc(m-sum[i],i);
			int res=i*cf+(A-num)*cm;
			//printf("?%I64d %I64d %I64d?\n",res,i,num);
			if(res>=ans){ans=res; p=i; Num=num; }
			//system("pause");
		}
		else break;
//	printf("%I64d ",Num);
	printf("%I64d\n",ans);
	for(i=1;i<=p;i++) a[i].v=0;
	for(i=n;i>=1;i--) if(a[i].v>Num) {a[i].v=Num; } else break;
	sort(a+1,a+n+1,cmp1);
	for(i=1;i<=n;i++) printf("%I64d ",A-a[i].v);
	return 0;
}
