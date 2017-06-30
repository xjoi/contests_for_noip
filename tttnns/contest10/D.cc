#pragma optimize("t", on)
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#define lld "%lld"
using namespace std;
typedef long long ll;
static inline bool gtp1r(pair<pair<ll, ll>, ll> const &l, pair<pair<ll, ll>, ll> const &r) {
    return r.first.second < l.first.second;
}
int main() {
    ll n, m;
    vector<pair<ll, ll> > islands;
    vector<pair<ll, ll> > bridges;
    scanf(lld lld, &n, &m);
    if(m < n - 1) {
        puts("No");
        return 0;
    }
    islands.reserve(n);
    for(ll i = 0; i < n; ++i) {
        ll l, r;
        scanf(lld lld, &l, &r);
        islands.push_back(make_pair(l, r));
    }
    bridges.reserve(m);
    for(ll i = 0; i < m; ++i) {
        ll t;
        scanf(lld, &t);
        bridges.push_back(make_pair(t, i));
    }
    sort(bridges.begin(), bridges.end());
    vector<pair<pair<ll, ll>, ll> > ranges;
    ranges.reserve(n - 1);
    for(ll i = 0; i < n - 1; ++i) {
        ll mindis = islands[i + 1].first - islands[i].second;
        ll maxdis = islands[i + 1].second - islands[i].first;
        ranges.push_back(make_pair(make_pair(mindis, maxdis), i));
    }
    sort(ranges.begin(), ranges.end());
    vector<ll> anss(n - 1);
    vector<pair<pair<ll, ll>, ll> >::const_iterator cur(ranges.begin());
    priority_queue<pair<pair<ll, ll>, ll>, vector<pair<pair<ll, ll>, ll> >, bool (*)(pair<pair<ll, ll>, ll> const &l, pair<pair<ll, ll>, ll> const &r)> q(gtp1r);
    for(vector<pair<ll, ll> >::const_iterator
            it(bridges.begin()); it != bridges.end(); ++it) {
        const ll bridge_len = it -> first;
        while(cur != ranges.end() && cur -> first.first <= bridge_len)
            q.push(*cur++);
        if(!q.empty() && q.top().first.second < bridge_len) {
            puts("No");
            return 0;
        }
        if(!q.empty()) {
            anss[q.top().second] = it -> second;
            q.pop();
        }
    }
    if(!q.empty() || cur != ranges.end()) {
        puts("No");
        return 0;
    }
    puts("Yes");
    for(vector<ll>::const_iterator it(anss.begin()); it != anss.end(); ++it)
        printf(lld " ", *it + 1);
    return 0;
}
