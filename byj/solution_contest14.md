<script type="text/javascript" src="http://cdn.mathjax.org/mathjax/latest/MathJax.js?config=default"></script>
[Contest Link](https://cn.vjudge.net/contest/168561)

# Solved during contest
## A
### Description
> 给定\\(n\\)个从小到大排序的数。相邻两数在同一段内当且仅当它们之差不大于\\(c\\)。求最后一段的长度。

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
> 给定一个由大写字母和问号组成的字符串$s$。要求将问号都替换成某个大写字母，使得存在长度为$26$的$s$的子串包含了所有大写字母。

### Solution
> 枚举起点，判断接下来的$26$个字母是否可以做到包含所有大写字母。如果可以则将这段子串填充完整，并将不属于这段子串的问号任意填充即可。

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
> 一个游戏的初始等级为$1$，初始数字为$2$。设当前等级为$i$，数字为$n$，若

### Solution

### Code

