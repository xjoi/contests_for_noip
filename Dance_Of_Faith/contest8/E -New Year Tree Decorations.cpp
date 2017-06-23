#include<iostream>
#include<cstdio>
using namespace std;
const int MAXK=2000;
int n,k,y,h,a[310][310];
double s[310];
int main(){
	cin >>n>>k;
	for (int i=1;i<=n;++i)
		for (int j=1;j<=k+1;++j) cin >>a[i][j];
	for (int p=1;p<=k;++p)
		for (int j=0;j<=MAXK;++j)
			for (int i=1,ym=0;i<=n;++i){
				y=a[i][p]*j+a[i][p+1]*(MAXK-j);
				h=max(0,y-ym);ym=max(ym,y);
				s[i]+=h*(j&&j<MAXK?2:1);
			}
	for (int i=1;i<=n;++i) printf("%.12lf\n",s[i]/(2*MAXK*MAXK));
	return 0;
}
