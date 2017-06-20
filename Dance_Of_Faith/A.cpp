#include<cstdio>  
#include<cstring>  
#include<iostream>  
#include<algorithm>  
using namespace std;  
const int maxn=100005;  
int g1[26][maxn],g2[26][maxn],p[maxn],a[maxn],b[maxn],vis[maxn];  
int n,m,t;  

bool judge2(int x,int y){  
    int c1=0,c2=0,c3=0;  
    if(g1[a[x]][x-1]!=g1[a[y]][y-1]-g1[a[y]][y-x])return false;  
    for(int i=1;i<a[x];i++)c1+=g1[i][x-1];  
    for(int i=1;i<a[y];i++)c2+=g1[i][y-1];  
    for(int i=1;i<a[y];i++)c3+=g1[i][y-x];  
    if(c1!=c2-c3)return false;return true;  
}  
void getfail(){  
    p[1]=0;int j=0;  
    for(int i=2;i<=n;i++){  
        while(j&&!judge2(j+1,i))j=p[j];  
        if(judge2(j+1,i)) j++;  
        p[i]=j;
    }  
}  
bool judge(int x,int y){  
    int c1=0,c2=0,c3=0;
    if(g1[a[x]][x-1]!=g2[b[y]][y-1]-g2[b[y]][y-x])return false;  

    for(int i=1;i<a[x];i++)c1+=g1[i][x-1];  
    for(int i=1;i<b[y];i++)c2+=g2[i][y-1];  
    for(int i=1;i<b[y];i++)c3+=g2[i][y-x];  
    if(c1!=c2-c3)return false;  
    return true;  
}  
void kmp(){
    int j=0;  
    for(int i=1;i<=m;i++){  
        while(j&&!judge(j+1,i))j=p[j];  
        if(judge(j+1,i)) j++;  
        if(j==n) vis[i]=1,j=0;
    }  
}  

int main(){  
    while(~scanf("%d%d%d",&m,&n,&t)){  
        memset(g1,0,sizeof(g1));
        memset(g2,0,sizeof(g2));
        memset(vis,0,sizeof(vis));
        for(int i=1;i<=m;i++){  
            scanf("%d",&b[i]);  
            for(int j=1;j<=t;j++) g2[j][i]=g2[j][i-1];  
            g2[b[i]][i]++;  
        }  
        for(int i=1;i<=n;i++){  
            scanf("%d",&a[i]);  
            for(int j=1;j<=t;j++) g1[j][i]=g1[j][i-1];  
            g1[a[i]][i]++;  
        }  
        getfail();  
        kmp();  
        int ans=0,i=1;  
        while(i<=m){  
            if(vis[i]) ans++,i+=n;else i++ ;  
        }  
        printf("%d\n",ans);  
    }  
    return 0;  
}  
