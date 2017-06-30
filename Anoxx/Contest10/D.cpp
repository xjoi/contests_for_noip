#include<cstdio>
#include<algorithm>
#include<set>
#define LL long long
using namespace std;
struct node{
	LL l,r,pos;
}a[300000];
LL l[300000],r[300000],val,n,m,ans[300000];
bool cmp(node a,node b){
	return a.l<b.l;
}
pair<LL,int>p[300000];
set<pair<LL,int> >st;
int main(){
	scanf("%I64d%I64d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%I64d%I64d",&l[i],&r[i]);
		if(i>1)a[i-1].l=l[i]-r[i-1],a[i-1].r=r[i]-l[i-1],a[i-1].pos=i-1;
	}
	for(int i=1;i<=m;i++){
		scanf("%I64d",&val);
		p[i]=make_pair(val,i);
	}
	sort(p+1,p+m+1);
	sort(a+1,a+n,cmp);
	for(int i=n-1,j=m;i>0;i--){
		while(j>0&&p[j].first>=a[i].l)st.insert(p[j]),j--;
		set<pair<LL,int> >::iterator it=st.upper_bound(make_pair(a[i].r+1,0));
		if(it==st.begin())return printf("No"),0;
		it--;
		ans[a[i].pos]=it->second;
		st.erase(it);
		
	}
	printf("Yes\n");
	for(int i=1;i<n;i++)printf("%I64d ",ans[i]);
	return 0;
}
