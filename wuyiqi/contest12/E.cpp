#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
const int N = 100010;
int a[N], f[N][2], n, pre[N][2];
//1: inc
//0: dec
bool solve(int f1, int f2)
{
    memset(f, -1, sizeof(f));
    if(f1) {
        f[1][1] = 0;
    } else {
        f[1][1] = n + 1;
    }
    if(f2){
        f[1][0] = 0;
    } else {
        f[1][0] = n + 1;
    }
    memset(pre, -1, sizeof(pre));
    for(int i = 2; i <= n; i++) {
        if(f[i - 1][0] != -1) {
            if((a[i] < a[i - 1]) ^ f1) {
                pre[i][0] = 0;
                f[i][0] = f[i - 1][0];
            }
            if((a[i] < f[i - 1][0]) ^ f2) {
                pre[i][1] = 0;
                f[i][1] = a[i - 1];
            }
        }
        if(f[i - 1][1] != -1) {
            if((a[i] < f[i - 1][1]) ^ f1) {
                if(f[i][0] == -1 || ((a[i - 1] > f[i][0]) ^ f2)) {
                    pre[i][0] = 1;
                    f[i][0] = a[i - 1];
                }
            }
            if((a[i] < a[i-1]) ^ f2) {
                if(f[i][1] == -1 || ((f[i - 1][1] > f[i][1]) ^ f1)) {
                    pre[i][1] = 1;
                    f[i][1] = f[i - 1][1];
                }
            }
        }
    }
    std::vector<int> up;
    std::vector<int> down;
    //for(int i = 1; i <= n; i++) printf("%d %d\n", f[i][0], f[i][1]);

    if(f[n][0] == -1 && f[n][1] == -1) return false;
    int now;
    if(f[n][1]!=-1) now = 1;
    else now = 0;
    for(int i = n; i >= 1; i--) {
        if(i == 1) {
            if(up.size()== n - 1) {
                down.push_back(a[i]);
                break;
            } else if(down.size() == n - 1){
                up.push_back(a[i]);
                break;
            }
        }
        if(now == 0) up.push_back(a[i]);
        else down.push_back(a[i]);
        now = pre[i][now];
    }
    std::reverse(up.begin(), up.end());
    std::reverse(down.begin(), down.end());
    printf("%d %d\n", up.size(), down.size());
    for(int i = 0; i < up.size(); i++) {
        printf("%d%c",up[i],i == (int)up.size() - 1 ? '\n': ' ');
    }
    for(int i = 0; i < down.size(); i++) {
        printf("%d%c",down[i],i == (int)down.size() - 1 ? '\n': ' ');
    }
    return true;
}
int main()
{
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
    }
    //solve(1, 0);

    bool flag = false;
    for(int i = 0; i < 2; i++) {
        for(int j = 0; j < 2; j++) {
            if(solve(i, j)) {
                flag = true;
                break;
            }
        }
        if(flag) {
            break;
        }
    }
    if(!flag) {
        puts("Fail");
    }
    return 0;
}
