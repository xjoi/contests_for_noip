#include<cstdio>
#include<cstring>
#define N 30
using namespace std;
int a[N],n,cnt=0,tmp,sum=0,b[10000010];
int gcd(int a,int b) {return b==0 ? a : gcd(b,a%b);}
int main()
{
	int t;
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	t=a[1]; for(int i=2;i<=n;i++) t=gcd(a[i],t);
	for(int i=1;i<=n;i++) {a[i]/=t; sum+=a[i]; if(a[i]&1) cnt++,tmp=i;}
	if(cnt!=1) 
	{
		if(t&1){puts("0");for(int i=1;i<=n;i++) for(int j=1;j<=a[i]*t;j++) printf("%c",i-1+'a'); return 0;}
		printf("%d\n",t); t/=2;for(int i=1;i<=26;i++) a[i]<<=1; sum<<=1;
	}
	if(sum&1)printf("%d\n",t);
	for(int i=1,j=sum,k=1;i<j;i++,j--) {while(a[k]<2) k++; b[i]=b[j]=k,a[k]-=2;}
	if(sum&1) b[sum/2+1]=tmp;
	for(int i=1;i<=t;i++)
		for(int j=1;j<=sum;j++)
		{
			char ch=b[j]+'a'-1;
			printf("%c",ch);
		}
	return 0;
}
