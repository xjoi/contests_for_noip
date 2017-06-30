#include <bits/stdc++.h>
using namespace std;
const int MAXN=200000 + 5;
map<int,int> mp;
map<int,int>::iterator it;
int res[MAXN];
char oper[MAXN];
int n,m,x;
int main() {
    scanf("%d%d",&n,&m);
    memset(res,0,sizeof res);
    mp[0]=0, mp[n+1]=m+1;
    oper[0]='U', oper[m+1]='L';
    res[0]=0, res[m+1]=0;
    for(int i=1,tmp;i<=m;i++) {
        scanf("%d %d %c",&x,&tmp,&oper[i]);
        it=mp.lower_bound(x);
        if(it->first==x) {
            puts("0");
            continue;
        }
        if(oper[i]=='L') it--;
        int ans=abs((it->first)-x);
        if(it!=mp.end()&&oper[it->second]==oper[i]) {
            ans+=res[it->second];
        }
        printf("%d ",ans);
        res[i]=ans;
        mp[x]=i;
    }
    return 0;
}
