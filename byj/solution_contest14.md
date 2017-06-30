[Contest Link](https://cn.vjudge.net/contest/168561)

# Solved during contest
## A
### Description
> 给定n个从小到大排序的数。相邻两数在同一段内当且仅当它们之差不大于c。求最后一段的长度。

### Solution
> 直接模拟。

### Code
```cpp
#include <iostream>
using namespace std;
int n, c, a[1000001], p;
int main()
{
    cin >> n >> c;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    p = 1;
    for (int i = 2; i <= n; ++i) {
        if (a[i] - a[i - 1] > c) {
            p = i;
        }
    }
    cout << n - p + 1 << endl;
    return 0;
}
```

### Tag
> Simulation
*****

## B
## Description
> 给定一个由大写字母和问号组成的字符串s。要求将问号都替换成某个大写字母，使得存在长度为26的s的子串包含了所有大写字母。

### Solution
> 枚举起点，判断接下来的26个字母是否可以做到包含所有大写字母。如果可以则将这段子串填充完整，并将不属于这段子串的问号任意填充即可。

### Code
```cpp
#include <iostream>
#include <cstring>
using namespace std;
string s;
bool flag;
int a[26], len, t, c;
int main()
{
    cin >> s;
    if (s.length() < 26) {
        cout << -1 << endl;
        return 0;
    }
    len = s.length();
    for (int k = 0; k < len - 25; k++) {
        memset(a, 0, sizeof(a));
        c = t = 0;
        for (int i = 0; i < 26; ++i) {
            if (s[k + i] != '?') ++a[s[k + i] - 'A'];
            else c++;
        }
        for (int i = 0; i < 26; ++i) {
            if (!a[i]) t++;
        }
        if (t <= c) {
            flag = true;
            for (int i = 0; i < 26; ++i) {
                if (!a[i]) {
                    for (int j = k; j < k + 26; ++j) {
                        if (s[j] == '?') {
                            s[j] = i + 'A';
                            break;
                        }
                    }
                }
            }
            for (int i = 0; i < 26; ++i) {
                if (s[k + i] == '?') s[k + i] = 'A';
            }
            break;
        }
    }
    for (int i = 0; i < len; ++i) {
        if (s[i] == '?') s[i] = 'A';
    }
    if (flag) cout << s << endl;
    else cout << -1 << endl;
    return 0;
}
```

### Tag
> Simulation
*****

## C
### Description
> 一个游戏的初始等级为1，初始数字为2。设当前等级为i，数字为n，有两种操作：①n+=i;②++i, n=sqrt(n)。执行②操作的前提是sqrt(n)能被(i+1)整除。求每两个②操作之间①操作的次数。

### Solution
> 设第k次开方后的数为k*(k+1)，则上一次开方后的数为(k-1)*k。易知(k-1)*k+xk=(k*(k+1))^2，于是得到x=(k-1)*k*k-(k-2)。

### Code
```cpp
#include <iostream>
using namespace std;
long long n;
int main()
{
    cin >> n;
    cout << 2 << endl;
    for (long long i = 2; i <= n; i++) {
        cout << i * (i + 1) * (i + 1) - i + 1 << endl;
    }
    return 0;
}
```

### Tag
> Math
*****

# Solved after contest
## D
### Description
> 给定一张连通无向图，其中所有边的权值均为自然数。要求将所有权值为0的边的权值变成任意一个不大于10^18的正整数，使得从s到t的最短路径的长度为L。

### Solution
> 首先将权值为0的边的权值变成无穷大，求一次最短路，若s和t之间的距离dist<L则无解。
若dist==L，则已得到可行解。
若dist>L，枚举初始权值为0的边，将它的权值变成1，求一次最短路，若dist≤L则说明已有可行解，把这条边的权值增加L−dist，即得到可行解。若所有初始权值为0的边都已枚举且dist>L，则说明无解。

### Code
```cpp
#include <iostream>
#include <queue>
#include <cstring>
using namespace std;
long long n, m, L, s, t, dist[1001], line[1001][1001];
bool flag, in[1001], sign[1001][1001];
void spfa(int p = -1, int q = -1) {
    queue<int> que;
    while (!que.empty()) que.pop();
    memset(in, false, sizeof(in));
    if (p == -1) {
        memset(dist, 0x1f, sizeof(dist));
        que.push(s), dist[s] = 0, in[s] = true;
    } else {
        if (dist[p] > dist[q]) p ^= q ^= p ^= q;
        que.push(p), in[p] = true;
    }
    while (!que.empty()) {
        long long u = que.front();
        que.pop();
        in[u] = false;
        for (int i = 0; i < n; ++i) {
            if (line[u][i] && dist[i] > dist[u] + line[u][i]) {
                dist[i] = dist[u] + line[u][i];
                if (!in[i]) que.push(i), in[i] = true;
            }
        }
    }
}
int main()
{
    cin >> n >> m >> L >> s >> t;
    for (int i = 1; i <= m; ++i) {
        long long x, y, w;
        cin >> x >> y >> w;
        line[x][y] = line[y][x] = w;
        if (!w) sign[x][y] = sign[y][x] = true;
    }
    spfa();
    if (dist[t] < L) {
        cout << "NO" << endl;
        return 0;
    } else if (dist[t] > L) {
        for (int i = 0; i < n - 1; ++i) {
            for (int j = i + 1; j < n; ++j) {
                if (sign[i][j]) {
                    line[i][j] = line[j][i] = 1;
                    sign[i][j] = sign[j][i] = false;
                    spfa(i, j);
                    if (dist[t] <= L) {
                        line[i][j] = line[j][i] = L - dist[t] + 1;
                        flag = true; break;
                    }
                }
            }
            if (flag) break;
        }
    } else flag = true;
    if (!flag) cout << "NO" << endl;
    else {
        cout << "YES" << endl;
        for (int i = 0; i < n - 1; ++i) {
            for (int j = i + 1; j < n; ++j) {
                if (line[i][j] || sign[i][j]) {
                    cout << i << ' ' << j << ' ';
                    if (line[i][j]) cout << line[i][j];
                    if (sign[i][j]) cout << (long long) 1e18;
                    cout << endl;
                }
            }
        }
    }
    return 0;
}
```

### Tag
> Shortest Path
