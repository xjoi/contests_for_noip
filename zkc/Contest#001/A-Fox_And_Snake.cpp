#include <bits/stdc++.h>
using namespace std;
int n,m,tmp=0;
int main() {
    cin>>n>>m;
    for(int i=1;i<=n;i++) {
        if(i%2==1) {
            for(int j=1;j<=m;j++) {
                cout<<"#";
            }
        } else {
            tmp++;
            if(tmp%2==1) {
                for(int j=1;j<m;j++) {
                    cout<<".";
                }
                cout<<"#";
            } else {
                cout<<"#";
                for(int j=1;j<m;j++) {
                    cout<<".";
                }
            }
        }
        cout<<endl;
    }
    return 0;
}