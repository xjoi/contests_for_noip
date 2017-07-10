# Solution
```
/******************
    XJOI链接：http://www.hzxjhs.com:83/contest/755
题目按CF顺序排序
******************/
```
# #A 棋子
```
/******************
     主要算法：DFS+诡异处理
     Data limit:T<=30
******************/
```
### 题意
给你1*N的无限长的1维空间，给你前三十位的初始状态以及目标状态，后面都是空，每个非空元素有如下操作  
1.移动4格，如果目标格不为空的话  
2.如果有x.x.的情况，两个x整体移动一格  
3.如果有xx.的情况，前x可以跳到后x后面并吃掉后x。  
判断是否能达到目标状态  
### 题解
第一遍写judge函数写到崩溃，然后听了lsk大佬的讲解豁（hen）然（xiang）开（tu）朗（xie）  
分析那三种操作可以知道每4个位置是可以来回穿梭的（1操作），那么就记录%4余0，1，2，3的棋子数量（由于可以互相穿梭那么与位置就无关了）  
然后再根据2，3操作进行模拟。。就简单了INF倍。。  
### 核心代码
```
/******************
inline void dfs(int a,int b,int c,int d)
{
    if (used[a][b][c][d]) return;
    used[a][b][c][d]=1;
    if (a&&c) dfs(a-1,b+1,c-1,d+1);
    if (b&&d) dfs(a+1,b-1,c+1,d-1);
    if (a&&b) dfs(a-1,b-1,c+1,d);
    if (b&&c) dfs(a,b-1,c-1,d+1);
    if (c&&d) dfs(a+1,b,c-1,d-1);
    if (d&&a) dfs(a-1,b+1,c,d-1);
}
******************/
```
### 错题记录
还没写完一切就结束了。。
***
# #B 路线
```
/******************
    主要算法： SPFA
     Data limit:n,m<=100,s<=10
******************/
```
### 题意
给你一个map，只能上下左右再范围内移动，移动的代价为两点数据只差的平方+1  
给你s个必须经过的点  
问你从左上角开始安排一条代价最小的可以经过都经过这些点的路径  
输出路径代价  
### 题解
先10遍SPFA求出必过点与必过点之间的距离  
然后再暴力DFS遍历求出ans（要加最优性剪枝要不然就T）  
### 核心代码
```
/******************
void SPFA(int X)
{
    memset(dis[X],63,sizeof(dis[X])); memset(used,0,sizeof(used));
    queue<pii> que;
    dis[X][p[X].F][p[X].S]=0; used[p[X].F][p[X].S]=1; que.push(p[X]);
    while(!que.empty())
    {
        pii p=que.front(); que.pop();
        for(int i=1;i<=4;i++)
        {
            int x=p.F+dx[i],y=p.S+dy[i];
            if(x>=1 && x<=n && y>=1 && y<=m && dis[X][x][y]>dis[X][p.F][p.S]+calc(p.F,p.S,x,y))
            {
                dis[X][x][y]=dis[X][p.F][p.S]+calc(p.F,p.S,x,y);
                if(!used[x][y]) {used[x][y]=1; que.push(mp(x,y));}
            }
        }
        used[p.F][p.S]=0;
    }
    for(int i=1;i<=s;i++) Dis[X][i]=dis[X][p[i].F][p[i].S];
}
inline bool ok() {for(int i=1;i<=s;i++) if(!vis[i]) return false; return true;}
void dfs(int pos,int u)
{
    if(ok()) {if(u<ans) ans=u; return;}
    if(u>=ans) return;
    for(int i=1;i<=s;i++)
        if(!vis[i])
        {
            vis[i]=1;
            dfs(i,Dis[pos][i]+u);
            vis[i]=0;
        }
    return;
}
******************/
```
### 错题记录
刚开始把暴力DFS用最小生成树instead，然而随便搞个数据就发现这不对了  
然后DFS后没加剪枝T了。。
***
# #C 方程
```
/******************
      主要算法：数论+高精
     Data limit:n<=10000 T<=30
******************/
```
### 题意
给你若干n，对于每组n求方程1/n!=1/x+1/y中x,y的正整数解个数
### 题解
将方程变形xy=xn!+yn! -> xy-xn!-yn!=0 -> (x-n!)(y-n!)=-n! -> pow(x-n!)*pow(y-n!)=pow(n!) 设等式左边两个因式分别为a，b，那么问题就变成了ab=pow(n!)  c
先将n!质因数分解，然后就能推出pow（n！）的了。然后根据分解结果高精度就可以了  
### 核心代码
```
/******************
 get_p();
    while(scanf("%d",&n)==1 && n)
    {
        clear();
        for(i=1;i<=n;i++)
        {
            int tmp=i,pos=0;
            while(tmp>1)
            {
                pos++;
                while(tmp%prime[pos]==0) {cnt[pos]++; tmp/=prime[pos];}
            }
        }
        for(i=1;i<=k;i++)
            if(cnt[i])
            {
                cnt[i]=cnt[i]*2+1;
                for(j=1;j<=len;j++) ans[j]*=cnt[i];
                for(j=1;j<=len;j++)
                {
                    ans[j+1]+=ans[j]/10000;
                    ans[j]%=10000;
                }
                while(ans[len+1]!=0)
                {
                    len++;
                    ans[len+1]+=ans[len]/10000;
                    ans[len]%=10000;
                }
            }
        cout<<ans[len]; for(i=len-1;i>=1;i--) cout<<setw(4)<<setfill('0')<<ans[i]; puts("");
******************/
```
### 错题记录
没错过
***
