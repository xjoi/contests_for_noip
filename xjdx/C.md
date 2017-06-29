# 题目:[CodeForces - 514C](http://codeforces.com/problemset/problem/514/C)
time limit per test3 seconds
memory limit per test256 megabytes
Watto, the owner of a spare parts store, has recently got an order for the mechanism that can process strings in a certain way. Initially the memory of the mechanism is filled with n strings. Then the mechanism should be able to process queries of the following type: "Given string s, determine if the memory of the mechanism contains string t that consists of the same number of characters as s and differs from s in exactly one position".

Watto has already compiled the mechanism, all that's left is to write a program for it and check it on the data consisting of n initial lines and m queries. He decided to entrust this job to you.

Input
The first line contains two non-negative numbers n and m (0 ≤ n ≤ 3·10^5, 0 ≤ m ≤ 3·10^5) — the number of the initial strings and the number of queries, respectively.

Next follow n non-empty strings that are uploaded to the memory of the mechanism.

Next follow m non-empty strings that are the queries to the mechanism.

The total length of lines in the input doesn't exceed 6·10^5. Each line consists only of letters 'a', 'b', 'c'.

Output
For each query print on a single line "YES" (without the quotes), if the memory of the mechanism contains the required string, otherwise print "NO" (without the quotes).

Examples
input
2 3
aaaaa
acacaca
aabaa
ccacacc
caaac
output
YES
NO
NO
# 题意:
就是对于给定的n个字符串(n <= 3*10^5,n个字符串总长度<=6*10^5,并且只包含'a','b','c'), 对于接下来输入的m次字符串询问(m <= 3*10^5), 判断每一次询问的字符串在给定的n个字符串中是否存在长度相同且刚好有1处字符不同的字符串.
# 思路:
### 解法一:字符串哈希大法
将原字符串按照字符串哈希计算放到set中,对于询问串枚举修改位置,判断修改后的字符串哈希值是否在set中存在,存在即为yes.
**unordered_set 不排序的set,插入和查询更快一点**
**哈希大法好写,但是存在冲突的可能性!**
### 解法二:[Trie树](http://blog.csdn.net/hguisu/article/details/8131559)
利用Trie树插入原字符串,然后查询的时候稍作修改,查询的时候允许有一次错误查询即可.具体见代码.
**其实这样复杂度是没有保证的**,因为采用的是DFS.完全可以构造出数据卡掉.那么要让复杂度有保证应该怎么办呢?请看解法三.
## 解法三:分组+正反序Trie树+set查询
　　先把原字符串按照长度分组,按组建Trie树,并且每组都建2颗Trie树,正序和反序字符串都建Trie树.然后从左到右枚举每个字符串的切断点k,把s[0..k-1]在正序trie树种的位置l1,以及s[end..k+1]在反序树的位置r1,以pair< l1,r1>保存到对应分组的set中。
　　对于查询串，也是枚举切断点k，查询s[0..k-1]在正序trie树种的位置l1,以及s[end..k+1]在反序树的位置r1，若pair< l1,r1>在set中存在，则表示该查询串符合题意。
# 代码
## 解法一:
```c++
#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,n) for (int i=a;i<n;i++)
#define per(i,a,n) for (int i=n-1;i>=a;i--)
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define SZ(x) ((int)(x).size())
#define fi first
#define se second
typedef vector<int> VI;
typedef long long ll;
typedef pair<int,int> PII;
const ll mod=1000000000000000003;
ll powmod(ll a,ll b) {ll res=1;a%=mod;for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
// head
const int N=601000;
int n,m;
ll pw[N];
char s[N];
unordered_set<ll> ff;
int main() {
	scanf("%d%d",&n,&m);
	pw[0]=1;
	rep(i,1,600001) pw[i]=pw[i-1]*3%mod;
	rep(i,0,n) {
		scanf("%s",s);
		int l=strlen(s);
		ll hs=0;
		for (int j=0;j<l;j++) hs=(hs*3+s[j]-'a')%mod;
		ff.insert(hs);
	}
	rep(i,0,m) {
		scanf("%s",s);
		int l=strlen(s);
		ll hs=0;
		bool fg=0;
		for (int j=0;j<l;j++) hs=(hs*3+s[j]-'a')%mod;
		for (int j=0;j<l;j++) {
			ll nhs=(hs-(s[l-1-j]-'a')*pw[j])%mod;
			if (nhs<0) nhs+=mod;
			rep(k,0,3) if (s[l-1-j]-'a'!=k) {
				if (ff.count((nhs+k*pw[j])%mod)) fg=1;
			}
			if (fg) break;
			// s[l-1-j]
		}
		puts(fg?"YES":"NO");
	}
}
```
## 解法二代码:
```c++
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <queue>
using namespace std;

const int N = 600005;

struct node {
    node *CH[ 3 ];
    bool exist;
    node( ) {
        memset( CH, 0, sizeof( CH ) );
        exist = false;
    }
}*root, *tmp;

char S[ N ];
int n, m;
int dp[ 2 ][ N ];
int cookie[ 2 ][ N ];
int timer = 0;
int len;

void add( ) {
    len = strlen( S );
    tmp = root;
    for( int i = 0; i < len; i++ ) {
        int ff = S[ i ] - 'a';
        if( tmp -> CH[ ff ] == NULL ) tmp -> CH[ ff ] = new node;
        tmp = tmp -> CH[ ff ];
    }
    tmp -> exist = true;
}

void load( ) {
    root = new node;
    scanf( "%d%d", &n, &m );
    for( int i = 0; i < n; i++ ) {
        scanf( "%s", S );
        add( );
    }
}
bool OK;

void go( int pos, node *tmp, int was ) {
    if( pos == len ) {
        if( tmp -> exist && was == 1 ) {
            OK = true;
        }
        return;
    }
    int curr = S[ pos ] - 'a';
    for( int i = 0; i < 3; i++ ) {
        if( tmp -> CH[ i ] == NULL ) continue;
        if( curr == i ) go( pos + 1, tmp -> CH[ i ], was );
        else {
            if( was ) continue;
            else go( pos + 1, tmp -> CH[ i ], 1 );
        }
    }
}

void solve( ) {
    for( int i = 0; i < m; i++, timer++ ) {
        scanf( "%s", S );
        len = strlen( S );
        OK = false;
        go( 0, root, 0 );
        if( OK ) printf( "YES\n" );
        else printf( "NO\n" );
    }
}

int main( void ) {
    load( );
    solve( );
    return 0;
}
```
## 解法三代码（待补充）：
