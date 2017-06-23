#include<cstdio>
#include<algorithm>
using namespace std;
struct data{
	int v,d;
}a[300001];
bool operator<(data a,data b){
	return a.v<b.v;
}
int ans[300001];
int main(){
	int n; scanf("%d",&n);
	for(int i=1;i<=n;++i){
		scanf("%d",&a[i].v);
		a[i].d=i;
	}
	sort(a+1,a+n+1); int cnt=0;
	for(int i=1;i<=n;++i){
		if(a[i].v>cnt) cnt=a[i].v;
		ans[a[i].d]=cnt; ++cnt;
	}
	for(int i=1;i<=n;++i)
		printf("%d ",ans[i]);
	return 0;
}
