#include <cstdio>
#include <algorithm>
using namespace std;
int k, x, n, m;
const int maxn = 128;
const int maxk = 64;
int f[maxk];
char bg[maxk], ed[maxn];
static bool dp(){
    for(int i = 3; i <= k; ++i){
        bg[i] = bg[i - 2];
        ed[i] = ed[i - 1];
        f[i] = f[i - 1] + f[i - 2] + (ed[i - 2] == 'A' and bg[i - 1] == 'C');
        if(f[i] > x) return false;
    }
    return f[k] == x;
}
int main(){
    scanf("%d%d%d%d", &k, &x, &n, &m);
    for(char bg1 = 'A'; bg1 <= 'C'; bg1 ++)
        for(char ed1 = 'A'; ed1 <= 'C'; ed1 ++)
            for(char bg2 = 'A'; bg2 <= 'C'; bg2 ++)
                for(char ed2 = 'A'; ed2 <= 'C'; ed2 ++){
                    if(n == 1 and bg1 != ed1 or m == 1 and bg2 != ed2)
                        continue;
                    bg[1] = bg1;
                    ed[1] = ed1;
                    bg[2] = bg2;
                    ed[2] = ed2;
                    for(int f1 = (n == 2 and bg1 == 'A' and ed1 == 'C'); f1 < (n + 1) / 2 + (n % 2 == 0 and bg1 == 'A' and ed1 == 'C') - (n > 1 and n % 2 != 0 and (bg1 != 'A' and ed1 != 'C')); ++f1)
                        for(int f2 = (m == 2 and bg2 == 'A' and ed2 == 'C'); f2 < (m + 1) / 2 + (m % 2 == 0 and bg2 == 'A' and ed2 == 'C') - (m > 1 and m % 2 != 0 and (bg2 != 'A' and ed2 != 'C')); ++f2){
                            f[1] = f1;
                            f[2] = f2;
                            if(dp()){
                                char s1[maxn], s2[maxn];
                                char *p1 = s1, *p2 = s2;
                                *p1++ = bg1;
                                *p2++ = bg2;
                                int sm1 = 0, sm2 = 0;
                                if(f1 and bg1 == 'A'){
                                    *p1++ = 'C';
                                    ++sm1;
                                }
                                if(f2 and bg2 == 'A'){
                                    *p2++ = 'C';
                                    ++sm2;
                                }
                                while(sm1 < f1){
                                    *p1++ = 'A';
                                    *p1++ = 'C';
                                    ++sm1;
                                }
                                while(sm2 < f2){
                                    *p2++ = 'A';
                                    *p2++ = 'C';
                                    ++sm2;
                                }
                                while(p1 - s1 < n)
                                    *p1++ = 'Z';
                                *(p1 - 1) = ed1;
                                *p1 = '\0';
                                while(p2 - s2 < m)
                                    *p2++ = 'Z';
                                *(p2 - 1) = ed2;
                                *p2 = '\0';
                                int cm1 = 0, cm2 = 0;
                                for(char *c1 = s1; c1 + 1 < p1; ++c1)
                                    if(*c1 == 'A' and *(c1 + 1) == 'C')
                                        ++cm1;
                                for(char *c2 = s2; c2 + 1 < p2; ++c2)
                                    if(*c2 == 'A' and *(c2 + 1) == 'C')
                                        ++cm2;
                                if(cm1 != f1 or cm2 != f2) continue;
                                puts(s1);
                                puts(s2);
                                return 0;
                            }
                        }
                }
    puts("Happy new year!");
    return 0;
}
