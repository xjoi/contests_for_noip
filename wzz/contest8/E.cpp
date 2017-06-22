using namespace std;
#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#define N 401
#define F(i,a,b) for(int i=a;i<=b;i++)
#define r(x) scanf("%d",&x)
int n,k,a[N];
double L[1000001],R[1000001],lh[1000001],rh[1000001];
int from[1000001];
int cnt;
double ans=0.00000000;
double S;
#define eps 0.000000000001
int main()
{
	cin>>n>>k;
	cnt=k-1;S=0;
	F(i,0,k-1){from[i]=i;lh[i]=0;rh[i]=0;L[i]=i;R[i]=i+1;}
	for(int i=1;i<=n;i++)
	{
		for(int j=0;j<=k;j++)
		r(a[j]);
		int hh=cnt;
		for(int j=0;j<=hh;j++)
		{
			double lnow,rnow;double kk,b;
			int it=from[j];
			{
				kk=a[it+1]-a[it];b=a[it]-it*kk;
//				cout<<kk<<" "<<b<<endl;
				lnow=kk*L[j]+b;rnow=kk*R[j]+b;
			}
			if(lnow>lh[j]-eps&&rnow>rh[j]-eps){lh[j]=lnow;rh[j]=rnow;continue;}
			if(lnow<lh[j]+eps&&rnow<rh[j]+eps)continue;
			cnt++;
			double k1,b1;
			k1=(rh[j]-lh[j])/(R[j]-L[j]);
			b1=lh[j]-k1*L[j];
//			cout<<k1<<" "<<b1<<endl;
			double x1=(b1-b)/(kk-k1);
			double y1=x1*kk+b;
			if(kk>k1)
			{
				L[cnt]=x1;
				R[cnt]=R[j];
				lh[cnt]=y1;
				rh[cnt]=rnow;
				from[cnt]=from[j];
				R[j]=L[cnt];
				rh[j]=lh[cnt];
			}
			else
			{
				R[cnt]=x1;
				L[cnt]=L[j];
				rh[cnt]=y1;
				lh[cnt]=lnow;
				from[cnt]=from[j];
				L[j]=R[cnt];
				lh[j]=rh[cnt];
			}
		}
		ans=0;
		for(int ii=0;ii<=cnt;ii++)
		{
			ans+=(R[ii]-L[ii])*(lh[ii]+rh[ii])/2;
//			cout<<L[ii]<<" "<<R[ii]<<" "<<lh[ii]<<" "<<rh[ii]<<endl;
		}
		ans-=S;S+=ans;
		printf("%.12lf\n",ans);//要想清楚 
	}
}
