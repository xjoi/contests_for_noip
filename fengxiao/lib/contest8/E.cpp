#include<cstdio>
#include<cstring>
#define N 510
#define P 700010
using namespace std;
int n,k;
int a[N];
double ans=0.0,b[P];
double calc(int x,int y,double p) {return (y-x)*p+x;}
int main()
{
	int i,j;
	scanf("%d %d",&n,&k);
	int m=P/k;
	for(i=1;i<=n;i++)
	{
		ans=0.0;
		for(j=0;j<=k;j++) scanf("%d",&a[j]);
		for(j=0;j<k;j++)
			for(int pos=0;pos<m;pos++)
			{
				double s=calc(a[j],a[j+1],1.0/m*(pos+0.5));
				if(s>b[j*m+pos]) ans+=s-b[j*m+pos],b[j*m+pos]=s;
			}
		printf("%.10lf\n",ans/m);
	}
	
	return 0;
}
