#include <bits/stdc++.h>
using namespace std;
char n[20],b[20];
bool check(char* s) {
    for(int i=0; i<strlen(n); i++) {
        if(s[i]!=n[i]) return false;
    }
    return true;
}
int dfs(char* x,int y,int top) {
    if(check(x)) return y;
    if(x[top]=='4') {
        x[top]='7';
        return dfs(x,y+1,top);
        x[top]='4';
    } else {
        int k=top;
        while(k>=0&&x[k]=='7') {
            x[k]='4';
            k--;
        }
        if(k>=0) x[k]='7';
        else {
            top++;
            x[top]='4';
        }
        return dfs(x,y+1,top);
    }
    return 0;
}
int main() {
    cin>>n;
    b[0]='4';
    cout<<dfs(b,1,0);
    return 0;
}
