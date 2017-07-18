#include<cstdio>
#include<cstring>
#include<algorithm>
#include<set>
#define N 200010
#define ll long long
#define plli pair<pair<ll ,ll >,int >
#define pli pair<ll ,int >
#define F first
#define S second
#define ins insert
#define mp make_pair
using namespace std;
ll t,l[N],r[N],ans[N];
plli a[N];//r,l,pos
multiset<pli > s;//a,pos
multiset<pli >::iterator it;
int n,m;
int main()
{
	int i;
    scanf("%d %d",&n,&m);
    for(i=1;i<=n;i++) scanf("%I64d %I64d",&l[i],&r[i]);
    for(i=1;i<n;i++)  {a[i].F.F=r[i+1]-l[i]; a[i].F.S=l[i+1]-r[i]; a[i].S=i;}
    sort(a+1,a+n); //for(i=1;i<n;i++) printf("%I64d %I64d %d\n",a[i].F.F,a[i].F.S,a[i].S);
    for(i=1;i<=m;i++) {scanf("%I64d",&t); s.ins(mp(t,i));}
    for(i=1;i<n;i++)
    {
        it=s.lower_bound(mp(a[i].F.S,0));
        if(it==s.end()||it->F>a[i].F.F) {puts("No"); return 0;}
        ans[a[i].S]=it->S;
        s.erase(it);
    }
    puts("Yes");
    for(i=1;i<n;i++) printf("%I64d ",ans[i]);
}
