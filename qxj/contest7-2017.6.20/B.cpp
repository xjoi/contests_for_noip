#include <iostream>
#include <cstdio>
#include <cctype>
#include <cstring>
#include <algorithm>
using namespace std;
inline int Read() {
    char c;
    while (c = getchar(), !isdigit(c));
    int x = c - 48;
    while (c = getchar(), isdigit(c)) x = x * 10 + c - 48;
    return x;
}
inline void Read(int &x) {
    char c;
    while (c = getchar(), !isdigit(c));
    x = c - 48;
    while (c = getchar(), isdigit(c)) x = x * 10 + c - 48;
    return;
}
inline void Writeln(int x) {
    int a[20], k = 0;
    do a[++k] = x % 10;
    while (x /= 10);
    while (k) putchar(a[k--] + 48);
    putchar('\n');
    return;
}
const int maxn = 10000, maxm = 500000;
int n, m, Q;
struct node {
    int u, v, w;
    bool operator < (const node &Other) const {
        return w < Other.w;
    }
} edge[maxm];
int k, w[maxm + 1], cnt[maxm + 2];
int f[maxn], size[maxn];
int Gf(int k) {
    return (k != f[k]) ? (f[k] = Gf(f[k])) : (k);
}
int main() {
    while (scanf("%d%d", &n, &m) == 2) {
        for (int i = 0; i < m; ++i) {
            Read(edge[i].u);
            Read(edge[i].v);
            Read(edge[i].w);
        }
        cnt[w[k = 0] = 0] = 0;
        sort(edge, edge + m);
        for (int i = 0; i < n; ++i) {
            f[i] = i;
            size[i] = 1;
        }
        for (int i = 0; i < m; ++i) {
            int k1 = Gf(edge[i].u), k2 = Gf(edge[i].v);
            if (k1 != k2) {
                w[++k] = edge[i].w;
                cnt[k] = size[k1] * size[k2] * 2;
                if (size[k1] > size[k2]) {
                    f[k2] = k1;
                    size[k1] += size[k2];
                } else {
                    f[k1] = k2;
                    size[k2] += size[k1];
                }
            }
        }
        cnt[k + 1] = 0;
        for (int i = k; i >= 0; --i)
            cnt[i] += cnt[i + 1];
        scanf("%d", &Q);
        while (Q--) {
            int j = lower_bound(w, w + k + 1, Read()) - w;
            Writeln(cnt[j]);
        }
    }
    return 0;
}
