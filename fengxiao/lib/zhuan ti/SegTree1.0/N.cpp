#include<cstdio>
#include<cstring>
#include<algorithm>
#define N 5010
#define A 10000
using namespace std;
struct edge{int x,y1,y2; bool flag;}h[N<<1],z[N<<1];
int n,X[30010],Y[30010],ans=0;
bool cmp(edge a,edge b) {return a.x==b.x? a.flag>b.flag : a.x<b.x;}
void add(edge &a,int b,int c,int d,bool f) {edge tmp={b,c,d,f}; a=tmp;}
int main()
{
    int x,y,x1,y1,i,j;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        scanf("%d %d %d %d",&x,&y,&x1,&y1);
        add(h[i<<1],y,x,x1,1); add(h[i*2-1],y1,x,x1,0);
        add(z[i<<1],x,y,y1,1); add(z[i*2-1],x1,y,y1,0);
    }
    sort(h+1,h+2*n+1,cmp); sort(z+1,z+2*n+1,cmp);
    for(i=1;i<=2*n;i++)
    {
        if(h[i].flag) for(j=h[i].y1;j<h[i].y2;j++) {if(!X[j+A]) ans++; X[j+A]++;}
        else          for(j=h[i].y1;j<h[i].y2;j++) {X[j+A]--; if(!X[j+A]) ans++;}
        if(z[i].flag) for(j=z[i].y1;j<z[i].y2;j++) {if(!Y[j+A]) ans++; Y[j+A]++;}
        else          for(j=z[i].y1;j<z[i].y2;j++) {Y[j+A]--; if(!Y[j+A]) ans++;}
    }
    printf("%d",ans);
    return 0;
}
