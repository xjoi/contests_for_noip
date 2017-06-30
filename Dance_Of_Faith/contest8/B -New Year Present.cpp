#include<iostream>
using namespace std;
int a[200000];
int main(){
    int n,sum=0;cin >>n;
    for (int i=1;i<=n;++i) cin >>a[i],sum+=a[i];
    int loc=1;bool flag=0;
    while (sum>0){
        if (a[loc]){
        if (!flag){flag=1;--sum;--a[loc];cout <<'P';}
        else{
            if (loc==1)  cout <<"RL";
                    else cout <<"LR";
            flag=1;--sum;--a[loc];cout <<'P';
            }
        }else cout <<'R',++loc,flag=0;
    }
    return 0;
}
