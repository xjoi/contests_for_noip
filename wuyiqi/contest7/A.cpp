#include <cstdio>
#include <cstring>
const int N = 100010;
int buf[N],pat[N];
int fail[N];
int pre[N],succ[N];
int app[30];
bool mycmp(int *a,int *b,int k) { //模式串的0～k-1已经匹配了主串中的一段
    if(b[app[a[k]]] != b[k]) return false;
    if(pre[a[k]]>=0 && b[pre[a[k]]] >= b[k]) return false;
    if(succ[a[k]]>=0&&b[succ[a[k]]] <= b[k]) return false;
    return true;
}
void getfail(int *pat,int m) {
//    for(int i = 0; i < m ;i++) printf("%d ",buf[i]);puts("");
    fail[0] = -1;
    for(int i = 1, j = -1; i < m; i++) {
        while(j>=0 && !mycmp(pat,pat+i-j-1,j+1)) j = fail[j];
        //     printf("i=%d j=%d\n",i,j);
        if(mycmp(pat,pat+i-j-1,j+1)) j++;
        fail[i] = j;
    }
}
int match(int *buf,int *pat,int n,int m) {
    int ans=0;
    for(int i = 0, j = -1; i < n; i++) {
        while(j >= 0 && !mycmp(pat,buf+i-j-1,j+1)) j = fail[j];
        if(mycmp(pat,buf+i-j-1,j+1)) j++;
        // printf("i=%d j=%d\n",i,j);
        if(j == m-1) {
            ans++;
            j = -1;
        }
    }
    return ans;
}
int main() {
    int n,m,s;
    while(scanf("%d%d%d",&n,&m,&s)!=EOF) {
        for(int i = 0; i < n; i++) scanf("%d",&buf[i]);
        for(int i = 0; i < m; i++) scanf("%d",&pat[i]);
        memset(app,-1,sizeof(app));
        for(int i = 0; i < m; i++) {
            if(app[pat[i]]==-1) app[pat[i]] = i;
            int j;
            for(j=pat[i]-1; j>=1&&app[j]==-1; j--);
            pre[pat[i]] = app[j];
            for(j=pat[i]+1; j<=s&&app[j]==-1; j++);
            succ[pat[i]] = app[j];
        }
        //  printf("%d %d\n",app[1],app[2]);
        getfail(pat,m);
        //for(int i = 0; i < m; i++) printf("fail[%d]=%d\n",i,fail[i]);
        printf("%d\n",match(buf,pat,n,m));
    }
    return 0;
}
