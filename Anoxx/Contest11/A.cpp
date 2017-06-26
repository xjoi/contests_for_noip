#include<cstdio>
using namespace std;
int n,a[100][100],o;
int main(){
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	for(int j=0;j<n;j++)scanf("%d",&a[i][j]);
	for(int i=0;i<n;i++)
	for(int j=0;j<n;j++){
		if(a[i][j]==1)continue;
		o=0;
		for(int k=0;k<n;k++)
		for(int l=0;l<n;l++)
	    if(a[i][k]+a[l][j]==a[i][j]){o=1;break;}
	    if(o==0)return printf("No"),0;
	}
	return printf("Yes"),0;
}
