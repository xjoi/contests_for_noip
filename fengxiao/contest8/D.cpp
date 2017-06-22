#include<cstdio>
#include<cstring>
#include<string>
#define ll long long
using namespace std;
ll n,m,x,k;
char ch[55][2];
ll a[55],b[55],c[55],d[55],c1[55],c2[55],s1,s2;//a 12 b 21 c 11 d 22
void work(int x,int y,int z)
{
	a[x]=a[y]+a[z]; b[x]=b[y]+b[z]; c[x]=c[y]+c[z]; d[x]=d[y]+d[z];
	c1[x]=c1[y]+c1[z]; c2[x]=c2[y]+c2[z];
	a[x]+= (ch[y][1]=='1' && ch[z][0]=='2') ? 1 : 0;
	b[x]+= (ch[y][1]=='2' && ch[z][0]=='1') ? 1 : 0;
	c[x]+= (ch[y][1]=='1' && ch[z][0]=='1') ? 1 : 0;
	d[x]+= (ch[y][1]=='2' && ch[z][0]=='2') ? 1 : 0;
	ch[x][0]=ch[y][0]; ch[x][1]=ch[z][1];
}
void getl()
{
	ch[1][0]=ch[1][1]='1',ch[2][1]=ch[2][0]='2';c1[1]=c2[2]=1; 
	for(int i=3;i<=k;i++)
		work(i,i-2,i-1);
	return;
}
int main()
{
	int i,j,ii,jj;
	scanf("%I64d %I64d %I64d %I64d",&k,&x,&n,&m);
	getl();
	int lk=strlen(ch[k]);
	s1=n/2; s2=m/2;
	//for(i=1;i<=k;i++) printf("%d %d\n",c1[i],c2[i]);
	//for(i=1;i<=k;i++) printf("%d %d\n",a[i],b[i]);
	//printf("%I64d %I64d %I64d %I64d %I64d",a[k],b[k],c[k],d[k],c2[k]);
	for(i=0;i<=s1;i++)
		for(j=0;j<=s2;j++)
		{
			ll tmp=i*c1[k]+j*c2[k];
			//printf("?%I64d?",tmp+d[k]);
			if(x==tmp)//none
			{
				for(ii=1;ii<=i;ii++) printf("AC");for(ii=(i+1)*2-1;ii<=n;ii++) printf("A"); printf("\n");
				for(jj=1;jj<=j;jj++) printf("AC");for(jj=(j+1)*2-1;jj<=m;jj++) printf("A"); printf("\n");
				return 0;
			}
			else if(i*2<n && j*2<m && x==tmp+a[k])//a
			{
			//	printf("?%d %d %d?",i,j,tmp);
				for(ii=1;ii<=i;ii++) printf("AC");for(ii=(i+1)*2-1;ii<n;ii++) printf("A"); puts("A");
				printf("C"); for(jj=1;jj<=j;jj++) printf("AC");for(jj=(j+1)*2;jj<=m;jj++) printf("B"); puts("");
				return 0;
			}
			else if(j*2<m && i*2<n && x==tmp+b[k])//b
			{
				printf("C"); for(ii=1;ii<=i;ii++) printf("AC");for(ii=(i+1)*2;ii<=n;ii++) printf("B"); puts("");
				for(jj=1;jj<=j;jj++) printf("AC");for(jj=(j+1)*2-1;jj<m;jj++) printf("A"); puts("A");
				return 0;
			}
			else if(i*2+1<n && x==tmp+c[k])//c
			{
				printf("C"); for(ii=1;ii<=i;ii++) printf("AC");for(ii=(i+1)*2;ii<n;ii++) printf("A"); puts("A");
				for(jj=1;jj<=j;jj++) printf("AC");for(jj=(j+1)*2-1;jj<=m;jj++) printf("B"); puts("");
				return 0;
			}
			else if(j*2+1<m && x==tmp+d[k])//d
			{
				for(ii=1;ii<=i;ii++) printf("AC");for(ii=(i+1)*2-1;ii<=n;ii++) printf("B"); puts("");
				printf("C"); for(jj=1;jj<=j;jj++) printf("AC"); for(jj=(j+1)*2;jj<m;jj++) printf("A"); puts("A");
				return 0;
			}
			else if(i*2+1<n && j*2<m && x==tmp+b[k]+c[k])//b c
			{
				printf("C"); for(ii=1;ii<=i;ii++) printf("AC");for(ii=(i+1)*2;ii<n;ii++) printf("A"); puts("A");
				for(jj=1;jj<=j;jj++) printf("AC");for(jj=(j+1)*2-1;jj<m;jj++) printf("A"); puts("A");
				return 0;
			}
			else if(i*2<n && j*2+1<m && x==tmp+a[k]+d[k])//a d
			{
				for(ii=1;ii<=i;ii++) printf("AC");for(ii=(i+1)*2-1;ii<n;ii++) printf("A"); puts("A");
				printf("C"); for(jj=1;jj<=j;jj++) printf("AC");for(jj=(j+1)*2;jj<m;jj++) printf("A"); puts("A");
				return 0;
			}
			else if(i*2+1<n && j*2<m && x==tmp+a[k]+c[k])//a c
			{
				printf("C"); for(ii=1;ii<=i;ii++) printf("AC");for(ii=(i+1)*2;ii<n;ii++) printf("A"); puts("A");
				printf("C"); for(jj=1;jj<=j;jj++) printf("AC");for(jj=(j+1)*2;jj<=m;jj++) printf("B"); puts("");
				return 0;
			}
			else if(i*2<n && j*2+1<m && x==tmp+b[k]+d[k])//b d
			{
				printf("C"); for(ii=1;ii<=i;ii++) printf("AC");for(ii=(i+1)*2;ii<=n;ii++) printf("B"); puts("");
				printf("C"); for(jj=1;jj<=j;jj++) printf("AC");for(jj=(j+1)*2;jj<m;jj++) printf("A"); puts("A");
				return 0;
			}
			else if(i*2+1<n && j*2+1<m && x==tmp+a[k]+b[k]+c[k]+d[k])//a b c d
			{
				printf("C"); for(ii=1;ii<=i;ii++) printf("AC");for(ii=(i+1)*2;ii<n;ii++) printf("A"); puts("A");
				printf("C"); for(jj=1;jj<=j;jj++) printf("AC");for(jj=(j+1)*2;jj<m;jj++) printf("A"); puts("A");
				return 0;
			}
		}
	printf("Happy new year!");
	return 0;
}//7 3 1 3
