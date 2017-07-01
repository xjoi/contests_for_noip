#include <bits/stdc++.h>
using namespace std;

int n;
string s;

void print() {
    for(int i=0;i<n;i++) {
        if(s[i]!='?') printf("%c",s[i]);
        else printf("A");
    }
    printf("\n");
    exit(0);
}

void check(int x) {
    int f[30];
    for(int i=0;i<=30;i++) f[i]=0;
    for(int i=x;i<=x+25;i++) {
        if(s[i]!='?') {
            f[s[i]-'A']++;
            if(f[s[i]-'A']>1) return;
        }
    }
    int j=0;
    for(int i=x;i<=x+25;i++) {
        if(s[i]=='?') {
            while(f[j]>0) j++;
            s[i]=(char)(j+'A');
            f[j]++;
        }
    }
    print();
}

int main() {
    cin>>s;
    n=s.length();
    if(n<26) {
        puts("-1");
        return 0;
    }
    for(int i=0;i<=n-26;i++) {
        check(i);
    }
    puts("-1");
    return 0;
}