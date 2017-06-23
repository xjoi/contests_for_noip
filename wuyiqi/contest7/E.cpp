#include <cstdio>
#include <cstring>
const int N = 210;
int ch[N][2];
int fail[N];
int sz;
int val[N];
int ID[256];
const int CD = 2;
void Init() {
    sz = 1;
    memset(ch[0],0,sizeof(ch[0]));
    ID['R'] = 0;
    ID['D'] = 1;
}
void Insert(char *s,int id) {
    int p = 0;
    for(; *s; s++) {
        int c = ID[*s];
        if(!ch[p][c]) {
            memset(ch[sz],0,sizeof(ch[sz]));
            val[sz] = 0;
            ch[p][c] = sz++;
        }
        p = ch[p][c];
    }
    val[p] |= 1<<id;
}
int Q[N];
void Construct() {
    int *s = Q, *e = Q;
    for(int i = 0; i < CD; i++) if(ch[0][i]) {
            *e++ = ch[0][i];
            fail[ch[0][i]] = 0;
        }
    while(s!=e) {
        int u = *s ++;
        for(int i = 0; i < CD; i++) {
            int &v = ch[u][i];
            if(v) {
                fail[v]  = ch[fail[u]][i];
                val[v] |= val[fail[v]];
                *e++ = v;
            } else {
                v = ch[fail[u]][i];
            }
        }
    }
}
int dp[2][201][201][1<<2];
const int mod = 1000000007;
void Add(int &x,int y) {
    x += y;
    if(x >= mod) x -= mod;
}
void solve(int n,int r) {
    int nxt=1,cur=0;
    memset(dp,0,sizeof(dp));
    dp[cur][0][0][0] = 1;
    for(int i = 0; i <= n; i++) {
        memset(dp[nxt],0,sizeof(dp[nxt]));
        for(int x = 0; x <= r; x++)
            for(int j = 0; j < sz; j++) {
                for(int k = 0; k < 4; k++)  {
                    for(int c = 0; c < CD; c++) {
                        //printf("dp[%d][%d][%d]=%d\n",i,j,k,dp[i][x][j][k]);
                        Add(dp[nxt][x+(c==0)][ch[j][c]][k|val[ch[j][c]]], dp[cur][x][j][k]);
                    }
                }
            }
        int t=cur;
        cur=nxt;
        nxt=t;
    }

    int ans = 0;
    for(int i = 0; i < sz; i++) Add(ans, dp[nxt][r][i][3]);
    printf("%d\n",ans);
}
int main() {
    int t,n,m;
    scanf("%d",&t);
    while(t--) {
        scanf("%d%d",&m,&n);
        Init();
        char str[110];
        for(int i = 0; i < 2; i++) scanf("%s",str),Insert(str,i);
        Construct();
//        for(int i = 0; i <sz; i++) printf("fail[%d]=%d\n",i,fail[i]);
        solve(n+m,m);
    }
    return 0;
}
