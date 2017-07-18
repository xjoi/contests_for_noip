%:pragma GCC optimize(3)//AC
#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#define N 20
using namespace std;
int n,ans;
bool f1[N<<2],f2[N<<2];
int a[N],used[N];
void print(int A,int B)
{
    if(A*B<=ans) return;
    memset(f1,0,sizeof(f1)); memset(f2,0,sizeof(f2));
    f1[0]=1; f2[0]=1;
    for(int i=1;i<=n;i++)
        for(int j=A;j>=a[i];j--)
        {
          if(used[i]==1) if(f1[j-a[i]]) f1[j]=1;
          if(used[i]==2) if(f2[j-a[i]]) f2[j]=1;
        }
    for(int i=1;i<=A-1;i++) if(f1[i]&&f2[i]) ans=max(ans,i*(A-i));
}
void dfs(int step,int A,int B)
{
    if (step==n+1) {if(A==B) print(A,B);return;}
    used[step]=1; dfs(step+1,A+a[step],B);//put to A
    used[step]=2; dfs(step+1,A,B+a[step]);//put to B
    used[step]=0; dfs(step+1,A,B);//not put
}
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    ans=-1e9;
    dfs(1,0,0);
    if (ans==-1e9) puts("No Solution");
    else printf("%d\n",ans);
    return 0;
}
#pragma GCC optimize(2)//T10
#include<cstdio>
#include<cstring>
#include<algorithm>
#define N 20
using namespace std;
int a[N],n,Sum;
bool used[N];
bool cmp(int a,int b) {return a>b;}
inline bool dfs(int A,int B,int l1,int l2,int l3,int l4,int u,int now)
{
    if(l1==l3 && l2==l4 && l1==A && l2==B) {printf("%d",A*B); return true; }
    if(2*A+2*B-l1-l2-l3-l4>Sum-u) return false;
    if(A-l1<a[n] && A!=l1 || B-l2<a[n] && B!=l2 || A-l3<a[n] && A!=l3 || B-l4<a[n] && B!=l4) return false;
    for(int i=now;i<=n;i++)
        if(!used[i])
        {
            if(!used[i-1] && a[i]==a[i-1]) continue;
            used[i]=1;
            u+=a[i];
            if(l1+a[i]<=A) {used[i]=1;if(dfs(A,B,l1+a[i],l2,l3,l4,u,i+1)) return true; used[i]=0;}
            if(l2+a[i]<=B) {used[i]=1;if(dfs(A,B,l1,l2+a[i],l3,l4,u,i+1)) return true; used[i]=0;}
            if(l3+a[i]<=A && l1!=l3) {used[i]=1; if(dfs(A,B,l1,l2,l3+a[i],l4,u,i+1)) return true; used[i]=0;}
            if(l4+a[i]<=B && l2!=l4) {used[i]=1; if(dfs(A,B,l1,l2,l3,l4+a[i],u,i+1)) return true; used[i]=0;}
            u-=a[i];
            used[i]=0;
        }
    return false;
}
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++) {scanf("%d",&a[i]); Sum+=a[i];}
    sort(a+1,a+n+1,cmp);
    int sum=Sum/2;
    for(int s=sum;s>=2;s--)
        for(int i=s/2,j=s-i;i<=s,j>=1;i++,j--)
            if(dfs(i,j,0,0,0,0,0,1)) return 0;
    puts("No Solution");
    return 0;
}
