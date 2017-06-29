#include<cstdio>
using namespace std;
int main() {
	int n,m;
	scanf("%d%d",&n,&m);
	int ans=2*n-m+1;
	for(int i=0;i<m;i++) {
		int k;
		scanf("%d",&k);
		for (int i=0;i<k;i++) {
			int a;
			scanf("%d",&a);
			if(a==i+1) ans-=2;
		}
	}
	printf("%d\n",ans);
	return 0;
}
