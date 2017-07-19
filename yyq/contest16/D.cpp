#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=100005;
pair<int,int> a[N];
int pr[N];
ll sum[N];
int n,A,cf,cm;
ll m;
int main() {
    scanf("%d%d%d%d%I64d",&n,&A,&cf,&cm,&m);
    for(int i=0;i<n;i++) {
        scanf("%d",&a[i].first);
        a[i].second=i;
    }
    sort(a,a+n);
    sum[0]=a[0].first;
    for(int i=1;i<n;i++)
		sum[i]=sum[i-1]+a[i].first;
    a[n].first=A;
    ll ans=0,x1=n,x2=0;
    for(int i=n;i>=0;i--) {
        m-=A-a[i].first;
        if(m<0)
			break;
        ll cur=1ll*(n-i)*cf;
        int l=0,r=A,fd=0;
        while(l<=r) {
            int mid=l+r>>1;
            int ql=0,qr=i-1,fk=-1;
            while(ql<=qr) {
                int mid2=ql+qr>>1;
                if(a[mid2].first<=mid) {
                    fk=mid2;
                    ql=mid2+1;
                }
				else {
                    qr=mid2-1;
                }
            }
            if(fk==-1) {
                fd=mid;
                l=mid+1;
            }
			else {
                ll qq=1ll*mid*(fk+1)-sum[fk];
                if(qq<=m) {
                    fd=mid;
                    l=mid+1;
                }
				else
                    r=mid-1;
            }
        }
        ll tmp=cur+1ll*fd*cm;
        if(ans<tmp) {
            ans=tmp;
            x1=i;
            x2=fd;
        }
    }
    for(int i=n;i>=x1;i--)
		a[i].first=A;
    for(int i=0;i<n;i++)
		a[i].first=max(1ll*a[i].first,x2);
    for(int i=0;i<n;i++)
		pr[a[i].second]=a[i].first;
    printf("%I64d\n",ans);
    for(int i=0;i<n;i++)
		printf("%d ",pr[i]);
	puts("");
    return 0;
}
