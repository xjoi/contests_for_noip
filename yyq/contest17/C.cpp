#include<bits/stdc++.h>
#define use_ios ios::sync_with_stdio(false);
#define use_tie cin.tie(0);
using namespace std;
int a[100020],l[100020],r[100020],n;
int main()
{
	use_ios
	use_tie
	cin>>n;
    for(int i=1;i<=n;i++)
    	cin>>a[i];
    l[1]=1,r[n]=1;
    for(int i=2;i<=n;i++) {
        if(a[i]>a[i-1])
            l[i]=l[i-1]+1;
        else
            l[i]=1;
    }
    for(int i=n-1;i>=1;i--) {
        if(a[i]<a[i+1])
            r[i]=r[i+1]+1;
        else
            r[i]=1;
    }
    int ans=0;
    for(int i=1;i<=n;i++) {
        if(a[i+1]>a[i-1]+1) {
            if(l[i-1]+1+r[i+1]>ans)
                ans=l[i-1]+1+r[i+1];
        }
        else {
            if(l[i-1]+1>ans)
                ans=l[i-1]+1;
            if(r[i+1]+1>ans)
                ans=r[i+1]+1;
        }
    }
    cout<<ans<<endl;
    return 0;
}
