#include<cstdio>
#include<string>
#include<cstring>
#include<algorithm>
using namespace std;
char a[2]={'A','C'};
int k,xx,n,m;
char s1[200],s2[200];
long long f[2000];
int main(){
	scanf("%d%d%d%d",&k,&xx,&n,&m);
	for(int i=0;i<=n/2;i++)
	for(int j=0;j<=m/2;j++)
	for(int i1=0;i1<2;i1++)
	for(int j1=0;j1<2;j1++)
	for(int i2=0;i2<2;i2++)
	for(int j2=0;j2<2;j2++){
		if(i*2+i1+j1>n||j*2+i2+j2>m)continue;
		f[1]=i;f[2]=j;
		for(int l=3;l<=k;l++){
			f[l]=f[l-1]+f[l-2];
			if(j1&&i2&&l==3)f[l]++;
			if(l!=3){
				if(l%2==0&&i1&&j2)f[l]++;
				if(l%2&&i2&&j2)f[l]++;
			}
		}
		if(f[k]==xx){
			//printf("%d %d %d %d %d %d\n",i,j,i1,j1,i2,j2);
			if(i1)printf("C");
			for(int l=1;l<=i;l++)printf("AC");
			for(int l=1;l<=n-i1-j1-i*2;l++)printf("B");
			if(j1)printf("A");printf("\n");
			if(i2)printf("C");
			for(int l=1;l<=j;l++)printf("AC");
			for(int l=1;l<=m-i2-j2-j*2;l++)printf("B");
			if(j2)printf("A");
			return 0;
		}
		
	}
	return printf("Happy new year!"),0;
}
