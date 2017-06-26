#include<cstdio>
#include<algorithm>
using namespace std;
const int INF=1e9;
int n,ans,x[500001],p[500001],minn,maxx,o,tot,tot2;
char s[21];
bool flag;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	scanf("%d",&n);
	for (int i=1; i<=2*n; i++){
		scanf("%s",s);
		if (s[0]=='a')
			scanf("%d",&x[++tot]);
		else{
			++tot2;
			if (x[tot]!=tot2&&tot>o) o=tot,ans++;
			tot--; o=min(o,tot);
		}
	}
	printf("%d",ans);
	return 0;
}
