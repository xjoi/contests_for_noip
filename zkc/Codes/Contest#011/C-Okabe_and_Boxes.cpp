#include <bits/stdc++.h>
using namespace std;
vector<int> stk;
int n,now,ans=0;
string o;
int main() {
    cin>>n;
    now=1;
    for(int i=1,j;i<=n*2;i++) {
        cin>>o;
        if(o=="add") {
            cin>>j;
            stk.push_back(j);
        } else {
            if(stk.empty()) {
                now++;
            } else if(stk.back()==now) {
                now++;
                stk.pop_back();
            } else {
                //cout<<"Hello\n";
                now++;
                ans++;
                stk.clear();
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}