#include<cstdio>
using namespace std;
int n,a[51][51];
int main(){
	scanf("%d",&n);
	for (int i=1; i<=n; i++)
	for (int j=1; j<=n; j++)
	scanf("%d",&a[i][j]);
	bool ff=0;
	for (int i=1; i<=n; i++)
	for (int j=1; j<=n; j++){
		bool flag=0;
		if (a[i][j]>1){
			for (int k=1; k<=n; k++)
			for (int l=1; l<=n; l++)
			if (a[i][j]==a[k][j]+a[i][l]) flag=1;
		} else flag=1;
		if (!flag) ff=1;
	}
	if (!ff) printf("Yes"); else printf("No");
	return 0;
}
