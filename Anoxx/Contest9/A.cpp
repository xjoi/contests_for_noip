#include<cstdio>
#include<algorithm>
using namespace std;
long long a[100100],l[100100],p,t[100100];
int n,m,k,x,y;
struct node{
	int l,r,d;
}c[100100];
int main(){
	scanf("%d%d%d",&n,&m,&k);
	for(int i=0;i<n;i++)scanf("%lld",&a[i]);
	for(int i=0;i<m;i++)scanf("%d%d%d",&c[i].l,&c[i].r,&c[i].d);
	for(int i=0;i<k;i++){
		scanf("%d%d",&x,&y);
		t[x-1]++;t[y]--;
	}
	for(int i=0;i<m;i++){
		p+=t[i];
		l[c[i].l-1]+=p*c[i].d;l[c[i].r]-=p*c[i].d;
	}
	p=0;
	for(int i=0;i<n;i++){
		p+=l[i];
		a[i]+=p;
		printf("%lld ",a[i]);
	}
}
