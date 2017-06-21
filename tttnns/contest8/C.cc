#include <cstdio>
#include <unordered_map>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
    int n;
    scanf("%d", &n);
    vector<int> a;
    a.reserve(n);
    while(n--){
        int t;
        scanf("%d", &t);
        a.push_back(t);
    }
    vector<int> b(a);
    sort(b.begin(), b.end());
    unordered_map<int, queue<int> > mp;
    int nowvalue = 0;
    for(int x : b){
        if(nowvalue < x)
            nowvalue = x;
        mp[x].push(nowvalue);
        ++nowvalue;
    }
    for(int x : a){
        printf("%d ", mp[x].front());
        mp[x].pop();
    }
    return 0;
}
