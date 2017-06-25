#include<iostream>  
#include<cstdio>  
#include<cstring>  
#include<algorithm>  
using namespace std;  
int fa[110000];  
bool fib[110000];  
struct node  {int s,e,co;}e[110000];  
int Find(int x)  
{
    if(fa[x]==x) return x;  
    else return fa[x]=Find(fa[x]);  
}
bool cmp1(node a,node b)  {return a.co<b.co;}  
bool cmp2(node a,node b)  {return a.co>b.co;}  
void get_fib()
{  
    memset(fib,false,sizeof(fib));  
    int a=1,b=2,c;  
    fib[a]=fib[b]=true;  
    while(1)  
    {  
        c=a+b;  
        if(c>100000) break;  
        fib[c]=true;  
        a=b,b=c;  
    }  
}  
int main()  
{  
    int i,j,T;  
    scanf("%d",&T);  
    get_fib();
    for(int k=1;k<=T;k++)  
    {  
        int n,m;
        scanf("%d %d",&n,&m);  
        for(int i=1;i<=m;i++)  scanf("%d %d %d",&e[i].s,&e[i].e,&e[i].co);  
        int ans1=0,ans2=0;  
        sort(e+1,e+m+1,cmp1);                               //以黑边为主的排序  
        for(int i=1;i<=n;i++) fa[i]=i;  
        for(int i=1;i<=m;i++)  
        {  
            int fx=Find(e[i].s),fy=Find(e[i].e);  
            if(fx!=fy)  
            {  
                if(e[i].co) ans1++;                                     //如果是白边则加1  
                fa[fx]=fy;  
            }
        }
        int fg=1,tem=Find(1);  
        for(int i=2;i<=n;i++)  if(Find(i)!=tem)  {fg=0;break;} 
        if(!fg) {printf("Case #%d: No\n",k);  continue;  }  
        sort(e+1,e+m+1,cmp2);
        for(int i=1;i<=n;i++) fa[i]=i;  
        for(int i=1;i<=m;i++)  
        {  
            int fx=Find(e[i].s),fy=Find(e[i].e);  
            if(fx!=fy)  
            {
                if(e[i].co) ans2++;  
                fa[fx]=fy;  
            }
        }  
        fg=0;  
        for(int i=ans1;i<=ans2;i++) if(fib[i]) {fg=1;break;}  
        if(fg) printf("Case #%d: Yes\n",k);  
        else printf("Case #%d: No\n",k);  
    }  
    return 0;  
}
