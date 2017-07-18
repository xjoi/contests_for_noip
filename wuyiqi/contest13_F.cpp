#include <bits/stdc++.h>

using namespace std;

#define _sz(x) (int)x.size()

int const N = 1e5+20;
int n, q, c[N], x[N], y[N], res[N];
vector <int> g[N], vec[N];
map <int, int> mp[N], cnt[N];

void dfs (int v, int par = -1){
  	mp[v][c[v]] = 1, cnt[v][1] = 1;
	for (int u: g[v]){
		if (u == par) continue;
		dfs(u, v);
		if (_sz(mp[u]) > _sz(mp[v])) mp[u].swap(mp[v]), cnt[u].swap(cnt[v]);
		for (map<int, int>::iterator it = mp[u].begin(); it != mp[u].end(); it ++){
		  	int C = it->first;
			while (mp[u][C]--){
				mp[v][C]++;
				cnt[v][mp[v][C]]++;
			}
		}
	}

	for (int x: vec[v]) res[x] = cnt[v][y[x]];
}


int main(){
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n >> q;
	for (int i = 0; i < n; i ++) cin >> c[i];
	for (int i = 0, u, v; i < n-1; i ++)
	  	cin >> u >> v, u--, v--, g[u].push_back(v), g[v].push_back(u);
	for (int i = 0; i < q; i++) cin >> x[i] >> y[i], x[i]--, vec[x[i]].push_back(i);

	dfs(0);

	for (int i = 0; i < q; i ++) cout << res[i] << '\n';
}
