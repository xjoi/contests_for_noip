#include <bits/stdc++.h>
using namespace std;

int n,f[50],ans=0;
char c[200];

int main() {
    cin>>n>>c;
    memset(f,0,sizeof f);
    for(int i=0;i<strlen(c);i++) {
        if(f[c[i]-'a']==0) {
            ans++;
            f[c[i]-'a']=1;
        }
    }
    if(ans<n) {
        puts("NO");
    } else {
        puts("YES");
        memset(f,0,sizeof f);
        int tmp=n;
        for(int i=0;i<strlen(c);i++) {
            if(tmp&&f[c[i]-'a']==0) {
                if(tmp<n) cout<<endl;
                tmp--;
                f[c[i]-'a']=1;
            }
            cout<<c[i];
        }
    }
    return 0;
}