#include<cstdio>
#include<cstring>
#include<iostream>
#define int long long
using namespace std;
int n,m;
int pow(int a,int P) {return (a%P)*(a%P)%P;}
int qpow(int a,int b,int P)
{
    if(b==1) return a;
    if(b&1) return pow(qpow(a,b/2,P),P)*(a%P)%P;
    else return pow(qpow(a,b/2,P),P)%P;
}
main()
{
    cin>>n>>m;
    if(m==0) {puts("1 1"); return 0;}
    if(n==0) {puts("0 0"); return 0;}
    int ans1=qpow(n,m,19941023);
    int ans2=qpow(n,m,19950814);
    cout<<ans1<<" "<<ans2<<endl;
    return 0;
}
