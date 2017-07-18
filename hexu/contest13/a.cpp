#include <cstdio>
typedef long long int ll;
char s[1000200];
ll a, b;
ll i, j, n, k, l, p, r;
int main(){
    scanf("%s", s);
    l = r = 0;
    for (i = 0; s[i]; i++) if (s[i] == '^') p = i;
    for (i = 0; s[i]; i++) if (s[i] != '^' && s[i] != '='){
        if (i < p)  l += (p - i) * (s[i] - 48);
        else        r += (i - p) * (s[i] - 48);
    }
    if (l == r) printf("balance");
    else if (l > r) printf("left");
    else printf("right");
    return 0;
}
