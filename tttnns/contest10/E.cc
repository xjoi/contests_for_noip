#include <cstdio>
#include <map>
using namespace std;
int main(){
    int n, q;
    scanf("%d%d", &n, &q);
    map<int, pair<bool, int> > mp;
    while(q--){
        int x, y;
        char turn[2];
        int ans;
        scanf("%d%d%s", &x, &y, turn);
        if(mp.count(x))
            ans = 0;
        else if(turn[0] == 'U'){
            auto it(mp.upper_bound(x));
            if(it == mp.end())
                ans = y;
            else if(it -> second.first)
                ans = y - it -> second.second;
            else
                ans = -x + it -> first;
            mp[x] = make_pair(true, y - ans);
        }else{
            auto it(mp.lower_bound(x));
            if(it == mp.begin())
                ans = x;
            else{
                --it;
                if(it -> second.first)
                    ans = x - it -> first;
                else
                    ans = x - it -> second.second;
            }
            mp[x] = make_pair(false, x - ans);
        }
        printf("%d\n", ans);
    }
    return 0;
}
