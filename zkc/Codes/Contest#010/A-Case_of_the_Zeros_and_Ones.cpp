#include <bits/stdc++.h>
using namespace std;

int n,ans,top=0;
char c;
int stck[200010];

int main() {
    scanf("%d",&n);
    getchar();
    for(int i=1;i<=n;i++) {
        scanf("%c",&c);
        if(c=='1') {
            if(top>0&&stck[top]==0) {
                top--;
            } else {
                top++;
                stck[top]=1;
            }
        } else {
            if(top>0&&stck[top]==1) {
                top--;
            } else {
                top++;
                stck[top]=0;
            }
        }
    }
    printf("%d\n",top);
    return 0;
}