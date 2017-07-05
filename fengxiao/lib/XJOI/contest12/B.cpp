#include<cstdio>
#include<cstring>
#include<algorithm>
#define ll long long
#define N 50010
using namespace std;
int T,X,n,x,q;
int f[20][20][1<<15],g[20][20];//i's at j
bool used[20],flag=0;
struct fish{int v,x,l,t,di;} a[20];
inline int sep(int x) {int sum=0;for(int i=0;i<n;i++) if((1<<i)&x) sum++; return sum;}
int main()
{
    int tmp,i,j,k,l,p;
    scanf("%d",&T);
    scanf("%d %d %d %d",&X,&tmp,&x,&q);
    scanf("%d",&n);
    for(i=0;i<n;i++) {scanf("%d %d %d %d %d",&a[i].x,&tmp,&a[i].v,&a[i].l,&a[i].t); a[i].t++; a[i].di= !a[i].x ? 1 : -1;}
    for(i=0;i<n;i++)
    {
        g[a[i].t][a[i].x]+=(1<<i);
        int pos=a[i].x;
        for(j=1;j;j++)
        {
            pos+=a[i].v*a[i].di;
            flag=0;
                for(k=0;k<=a[i].l;k++)
                {
                    if(pos-k*a[i].di>=0 && pos-k*a[i].di<=X)
                        {flag=1; g[a[i].t+j][pos-k*a[i].di]+=(1<<i);}
                }
            if(!flag) break;
        }
    }
    f[0][x][0]=1;
    for(i=1;i<=T+1;i++)
    {
        for(j=0;j<=X;j++)
            for(k=0;k<(1<<14);k++)
                for(l=-q;l<=q;l++)
                    if(j+l>=0 && j+l<=X)
                        f[i][j][k]=f[i][j][k] || f[i-1][j+l][k];
        for(j=0;j<=X;j++)
            if(g[i][j])
                for(k=0;k<(1<<14);k++)
                    f[i][j][k|g[i][j]]=f[i][j][k|g[i][j]] || f[i-1][j][k];
    }
    int ans=0;
    for(j=0;j<=X;j++)
        for(k=0;k<(1<<14);k++)
            if(f[T+1][j][k])
                ans=max(ans,sep(k));
    printf("%d",ans);
    return 0;
}
