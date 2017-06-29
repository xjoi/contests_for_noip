#include <bits/stdc++.h>
using namespace std;
map<int,int> tmp;
map<int,int>::iterator it;
int n,m,a[500],b[500];

int main() {
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    for(int i=1;i<=n;i++) scanf("%d",&b[i]);
    for(int i=1;i<=n;i++) {
        for(it=tmp.begin();it!=tmp.end();it++) {
            int k=__gcd(it->first,a[i]);
            if(tmp[k]==0) tmp[k]=tmp[it->first]+b[i];
            else tmp[k]=min(tmp[k],tmp[it->first]+b[i]);
        }
        if(tmp[a[i]]==0) tmp[a[i]]=b[i];
        else tmp[a[i]]=min(tmp[a[i]],b[i]);
    }
    if(tmp[1]==0) cout<<-1<<endl;
    else cout<<tmp[1]<<endl;
    return 0;
}