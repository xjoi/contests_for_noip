#include <bits/stdc++.h>
using namespace std;
bool f[30][30],ex[30],flag;
int n,m,inp[30],seq[30],top=0;
char a[110][110];

pair<char,char> stcp(int x,int y) {
    pair<char,char> res;
    int smallen=min(strlen(a[x]),strlen(a[y]));
    for(int i=0;i<smallen;i++) {
        if(a[x][i]!=a[y][i]) {
            res.first=a[x][i];
            res.second=a[y][i];
            return res;
        }
    }
    res.first=res.second='a'-1;
    if(strlen(a[x])>strlen(a[y])) {
        cout<<"Impossible\n";
        exit(0);
    }
    return res;
}

void build(int x,int y) {
    pair<char,char> e=stcp(x,y);
    int u=e.first-'a'+1, v=e.second-'a'+1;
    if(!f[u][v]&&u!=0&&v!=0) {
        f[u][v]=1;
        ex[u]=ex[v]=1;
        inp[v]++;
        m++;
    }
}

bool st() {
    queue<int> Q;
    for(int i=1;i<=26;i++) {
        if(ex[i]&&inp[i]==0) {
            Q.push(i);
            top++;
            seq[top]=i;
        }
    }
    if(Q.empty()&&m>0) return false;
    int now;
    while(1){
    now=Q.front();
    Q.pop();
    for(int i=1;i<=26;i++) {
        if(now!=i&&ex[i]&&f[now][i]) {
            f[now][i]=0;
            //printf("Deleting %d to %d || inp:", now, i);
            m--;
            inp[i]--;
            if(inp[i]==0) {
                Q.push(i);
                top++;
                seq[top]=i;
            }
        }
    }
    if(Q.empty()&&m>0) return false;
    if(m<=0) break;
    }
    return true;
}

int main() {
    cin>>n;
    for(int i=1;i<=n;i++) {
        cin>>a[i];
    }
    m=0;
    memset(f,0,sizeof f);
    memset(inp,0,sizeof inp);
    for(int i=2;i<=n;i++) {
        for(int j=1;j<i;j++) {
            build(j,i);
        }
    }
    //cout<<f[2]<<endl;
    bool flag=st();
    if(flag) {
        for(int i=1;i<=26;i++) {
            if(!ex[i]) {
                top++;
                seq[top]=i;
            }
        }
        for(int i=1;i<=top;i++) {
            cout<<((char)(seq[i]+'a'-1));
        }
        cout<<endl;
    } else cout<<"Impossible\n";
    return 0;
}
