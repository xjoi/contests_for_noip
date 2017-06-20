#include <iostream>
using namespace std;
typedef long long ll;
ll z[501][501];
ll a[500];
int main(){
    ll n, m, b, mod;
    cin >> n >> m >> b >> mod;
    for(int i = 0; i < n; ++i)
        cin >> a[i];
    z[0][0] = 1;
    for(int i = 0; i < n; ++i)
        for(int j = 1; j <= m; ++j)
            for(int k = 0; k <= b; ++k)
                if(k >= a[i]){
                    z[j][k] += z[j - 1][k - a[i]];
                    z[j][k] %= mod;
                }
    ll ans = 0;
    for(int i = 0; i <= b; ++i){
        ans += z[m][i];
        ans %= mod;
    }
    cout << ans;
    return 0;
}
