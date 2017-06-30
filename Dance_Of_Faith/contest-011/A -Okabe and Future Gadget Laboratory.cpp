#include<iostream>
#include<cstdio>
using namespace std;
int a[100][100];
int main(){
	int n;cin >>n;
	for (int i=1;i<=n;++i)
		for (int j=1;j<=n;++j) cin >>a[i][j];
	for (int i=1;i<=n;++i)
		for (int j=1;j<=n;++j)
		if (a[i][j]!=1){
			int flag=false;
			for (int s=1;s<=n;++s)
				for (int t=1;t<=n;++t)
				if (a[i][s]+a[t][j]==a[i][j]){flag=true;break;}
			if (!flag){puts("No");return 0;}
		}
	puts("Yes");return 0;
}
