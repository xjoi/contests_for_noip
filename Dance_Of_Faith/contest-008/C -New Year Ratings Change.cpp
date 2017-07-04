#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
struct XY{int v,id;}a[500000];
bool cmp(XY a,XY b){return a.v<b.v;}
bool cmp2(XY a,XY b){return a.id<b.id;}
int main(){
	int n;cin >>n;
	for (int i=1;i<=n;++i) scanf("%d",&a[i].v),a[i].id=i;
	sort(a+1,a+1+n,cmp);
	for (int i=2;i<=n;++i)
		if (a[i].v<=a[i-1].v) a[i].v=a[i-1].v+1;
	sort(a+1,a+1+n,cmp2);
	for (int i=1;i<=n;++i) printf("%d ",a[i]);
	return 0;
}
