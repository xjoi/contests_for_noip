# Solution
```
/******************
    Xjoi链接： http://www.hzxjhs.com:83/contest/753
******************/
```
# #A 四面楚歌
```
/******************
     主要算法：找规律
     Data limit:
     对于30%的数据，保证0<=n,m<=10^2。
对于50%的数据，保证0<=n,m<=10^9。
对于70%的数据，保证0<=n,m<=10^100。
对于100%的数据，保证0<=n,m<=10^10000。
******************/
```
### 题意
n条线有m个交点（只能两两相交），问这些线将平面分为几块**保证数据合法**
### 题解
列个10来个的规律就出来了-> ans=n+m+1  
### 核心代码
```
/******************
    scanf("%s",tmp);
    int la=strlen(tmp);
    for(i=0;i<la;i++) a[i+1]=tmp[la-i-1]-'0';
    scanf("%s",tmp);
    int lb=strlen(tmp);
    for(i=0;i<lb;i++) b[i+1]=tmp[lb-i-1]-'0';
    int pos=1;
    while(a[pos]==9) a[pos++]=0; a[pos]++;
    int l=max(la,lb);
    for(i=1;i<=l;i++)
    {
        c[i]+=a[i]+b[i];
        c[i+1]+=c[i]/10;
        c[i]%=10;
    }
    if(c[l+1]!=0) l++;
    for(i=l;i>=1;i--) printf("%d",c[i]);
    return 0;
******************/
```
### 错题记录
刚开始没看到数据一定合法卡了很久
***
# #B 蒲公英的约定
```
/******************
    主要算法： 快速幂
     Data limit:
     对于30%的数据，保证0<=n,m<=10^4。
对于100%的数据，保证0<=n,m<=10^9。
******************/
```
### 题意
求n^m

### 题解
普通快速幂
### 核心代码
```
/******************

int pow(int a,int P) {return (a%P)*(a%P)%P;}
int qpow(int a,int b,int P)
{
    if(b==1) return a;
    if(b&1) return pow(qpow(a,b/2,P),P)*(a%P)%P;
    else return pow(qpow(a,b/2,P),P)%P;
}
******************/
```
### 错题记录
mdzz刚开始空格都忘打了。。
***
# #C 跨时代
```
/******************
      主要算法：~~DFS+DP~~ or baoli
     Data limit:
     对于30%的数据，1<=n<=10。
对于100%的数据，1<=n<=16,1<=li<=15.
******************/
```
### 题意
给你n个棍子，拼成矩形**可以不全用**，问最大面积。
### 题解
嗯这道题分成若干阶段  
1.10 -> 最朴素的DFS（看对了题后）  
1.30 -> 不知道别人是怎么做的，反正我是没看清题目用了全部的木棍做，然后居然还有30  
3.80 -> 暴力DFS加上剪枝-> 放全部都放不满  
4.90 -> 80分的基础上加上当前点优化（乱得的，就是从上次遍历到的边开始）  
5.100 ->lsk dalao的算法，把长和宽表示为A，B，讨论其三种状态->放A，放B，不放，然后再使用print函数处理，其中用到了简单的DP
### 核心代码
```
/******************
AC：
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
TLE：（其实数据真的太弱了，我的搜索顺序本来打算按面积搜索，然而实际代码并没有做到，但还能A九个点并且最后一个点是T。。。）
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
******************/
```
### 错题记录
见题解。。。
***
