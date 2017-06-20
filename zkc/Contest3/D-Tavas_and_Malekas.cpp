#include <bits/stdc++.h>
using namespace std;

const int MAX=1000010;
const int Md=1e9+7;

int next[MAX],a[MAX];
char s[MAX];
int n,m,ans=0,lens;

void KMPinit() {
    int i=-1,j=0;
    next[0]=-1;
    while(j<lens) {
        if(i==-1||s[i]==s[j]) {
            i++;
            j++;
            next[j]=i;
        } else {
            i=next[i];
        }
    }
}

long long power(int x1,int y1) {
    long long ans=1;
    long long x=(long long)x1,y=(long long)y1;
    while(y) {
        if(y&1) ans=(ans*x)%Md;
        x=(x*x)%Md;
        y>>=1;
    }
    return ans;
}

int main() {
    cin>>n>>m>>s;
    lens=strlen(s);
    KMPinit();
    for(int i=1; i<=m; i++) {
        cin>>a[i];
        if(i==1) {
            n-=lens;
            continue;
        }
        if(a[i]-a[i-1]>=lens) n-=lens;
        else {
            int k=lens,q=lens-a[i]+a[i-1];
            while(next[k]>q) {
                k=next[k];
                if(next[k]<q) {
                    puts("0");
                    exit(0);
                }
                if(next[k]==q) {
                    break;
                }
            }
            if(next[k]==q) n-=lens-q;
            else if(next[k]<q) {
                puts("0");
                exit(0);
            }
        }
    }
    cout<<power(26,n)<<endl;
    return 0;
}