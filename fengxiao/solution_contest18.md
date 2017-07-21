# Solution
```
/******************
    VJudge链接：  https://cn.vjudge.net/contest/172100
CodeForces链接：  http://codeforces.com/contest/197
题目按CF顺序排序
******************/
```
# #A Plate Game 
```
/******************
     主要算法：乱搞？ 数论
     Data limit: a, b, r (1 ≤ a, b, r ≤ 100)
******************/
```
### 题意
给你一个a*b的桌子，在上面可以放半径为r盘子，不能移动已有的盘子，盘子的任意部分不能超过边缘  
两个人博弈，谁不能在桌子上放盘子谁就输
### 题解
博弈论：直接暴力枚举每个人所有可以放的格子，进行判断输赢 复杂度：n5 BOOM！！
乱搞：算出每行/列最多能放多少盘子，然后每行/列就最少可以放最多的-1个  
      然后讨论4种情况：最多*最多，最多*最少，最少*最多，最少*最少，然后根据数量奇偶性判断胜负
正解（数学）：First现在正中间放一个，然后Second可以在任意处放，此时First只需与Second走对称的步便必胜了。
             但如果一个都不能放First就GG了
### 核心代码
```
/******************
乱搞：a/=2*r; b/=2*r;
	int ans=a*b;
	if(ans&1) {puts("First"); return 0;}
	ans=max(0,(a-1))*b;
	if(ans&1) {puts("First"); return 0;}
	ans=a*max(0,(b-1));
	if(ans&1) {puts("First"); return 0;}
	ans=max(0,(a-1))*max(0,(b-1));
	if(ans&1) {puts("First"); return 0;}
	puts("Second");
正解：a/=2*r;b/=2*r;
    if(a!=0 || b!=0) puts("First"); else puts("Second");
******************/
```
### 错题记录
乱搞的时候讨论没全面+一次博弈论的GG
***
# #B Limit 
```
/******************
    主要算法： 乱搞
     Data limit:n and m (0 ≤ n, m ≤ 100) all numbers between -100 and 100 a0!=0 b0!=0
******************/
```
### 题意
给你两个函数的定义：P(x)=a0*x（n-1）+a1*x(n-2)...+an Q(x)=b0*x(m-1)+b1*(m-2)...+bm  
x可以到无限大，求lim(x->oo)P(x)/Q(x)  
若为正无穷输出“Infinity” 负无穷“-Infinity”，0输出->0/1  否则输出价值x/y  

### 题解
嗯这题就是乱搞  
通过观察样例解析发现有如下情况  
(1).n>m +-infinity （正负性由a[0]/b[0]决定）  
(2).n<m ->0  
(3).n==m a0/b0  
### 核心代码
```
/******************
由于没看到a0和b0不等于0，所以代码比较挫
for(i=1;i<=n+1;i++) scanf("%d",&a[i]);
	for(i=1;i<=m+1;i++) scanf("%d",&b[i]);
	while(a[ca]==0) ca++; while(b[cb]==0) cb++;
	if(n-ca+1<m-cb+1) {puts("0/1"); return 0;}
	if(n-ca+1>m-cb+1)
	{
		if(a[ca] * b[cb]>0) puts("Infinity");
		else puts("-Infinity");
		return 0;
	}
	int t=gcd(abs(a[ca]),abs(b[cb])); a[ca]/=t; b[cb]/=t;
	if(a[ca]*b[cb]>0) printf("%d/%d",abs(a[ca]),abs(b[cb]));
	else printf("-%d/%d",abs(a[ca]),abs(b[cb]));
******************/
```
### 错题记录
1A
***
# #C  Lexicographically Maximum Subsequence
```
/******************
      主要算法：字符串处理+贪心+模拟
     Data limit:The string's length doesn't exceed 105
******************/
```
### 题意
给你一串字母，求其中的最大子序列  
两序列的比较方法如下  
1.从前往后存在第一个r使ar>br,则A>B  
2.所有元素相同的情况下长度大的大  
### 题解
sort一遍，第一关键字value，第二关键字pos  
维护now，然后从前往后扫一遍，如果a[i].pos>now 就加入ans，否则路过  
### 核心代码
```
/******************
	scanf("%s",s); int n=strlen(s);
	for(int i=0;i<n;i++) a[i+1].v=s[i]-'a',a[i+1].pos=i+1;
	sort(a+1,a+n+1,cmp);
	int now=-1;
	for(int i=1;i<=n;i++)
	{
		if(a[i].pos>now) ans[++lst]=a[i].v+'a',now=a[i].pos;
	}
	for(int i=1;i<=lst;i++) printf("%c",ans[i]);
******************/
```
### 错题记录
这场比赛最好做的一题，1A
***
# #D Infinite Maze 
```
/******************
      主要算法：DFS
     Data limit:n and m (1 ≤ n, m ≤ 1500)
******************/
```
### 题意
给你一个map，可以无限复制与延伸，问你是否可以走到无限远处
### 题解
第一次：将整个map看作个点，普通dfs，状态定义为(x,y,d,a,b) 表示当前走到(x,y),从d方向来,对于map点的坐标(a,b),然而发现标记used却需[N][N][N][N][5]
第二次：f表示现在的nx，ny从x,y来，然后用第一次的DFS便可
### 核心代码
```
/******************
struct P {int x,y;} f[N][N];
bool dfs(int x, int y)
{
    int nx=(x%n+n)%n,ny=(y%m+m)%m;
    if(map[nx][ny]=='#') return false;
    if(f[nx][ny].x!=f[N-1][N-1].x) return f[nx][ny].x!=x||f[nx][ny].y!=y;
    f[nx][ny].x=x,f[nx][ny].y=y;
    for(int i=1;i<=4;i++) if(dfs(x+dx[i],y+dy[i])) return true;
    return false;
}
int main()
{
    scanf("%d %d",&n,&m);
    bool flag=1;
    for(int i=0;i<n;i++) scanf("%s",map[i]);
    memset(f,63,sizeof(f));
    for(int i=0;flag&&i<n;i++)
        for(int j=0;j<m;j++)
            if(map[i][j]=='S')
            {
                if(dfs(i,j)) puts("Yes");
                else puts("No");
                flag=0; break;
        	}
}
******************/
```
### 错题记录
卡死在第一次无数次，最后依旧只能不舍得放弃它。。。

***
# #E Paint Tree 
```
/******************
      主要算法：计算几何
     Data limit: n (1 ≤ n ≤ 1500)  xi and yi ( - 109 ≤ xi, yi ≤ 109)
******************/
```
### 题意
给你棵树，给你平面上的与树的节点的数量相同的点，让平面上每个点对应树上的每个点，边也如此，要求边两两不想交。  
输出方案  
### 题解
按左下角为原点极角排序，那么便不会相交，然后再选两个点作为孩子，再递归处理每颗子树便可
### 核心代码
```
/******************
bool cmp(P a,P b) {int tmp=cj(a,b); return tmp==0 ?  : tmp>0;}
void build_tre(int u,int f)
{
    sz[u]=1;
    for(int i=head[u];i;i=nxt[i]) if(to[i]!=f) {build_tre(to[i],u); sz[u]+=sz[to[i]];}
}
void dfs(int u,int f,int l,int r)
{
    if(l>r) return;
    int pos=l;
    for(int i=l+1;i<=r;i++) if(p[i].y<p[pos].y || (p[i].y==p[pos].y && p[i].x<p[pos].x)) pos=i;
	swap(p[pos],p[l]);
    ans[p[l].pos]=u;
    if(l==r) return;
    for(int i=l+1;i<=r;i++)
    {
        p[i].x-=p[l].x;
        p[i].y-=p[l].y;
    }
    sort(p+l+1,p+r+1,cmp);
    int now=l+1;
    for(int i=head[u];i;i=nxt[i])
	    if(to[i]!=f)
	    {
	        dfs(to[i],u,now,now+sz[to[i]]-1);
	        now+=sz[to[i]];
	    }
}
main()
{
    int i,x,y;
    scanf("%I64d",&n);
    for(i=1;i<n;i++) {scanf("%I64d %I64d",&x,&y); adde(x,y),adde(y,x);}
    for(i=1;i<=n;i++){scanf("%I64d %I64d",&p[i].x,&p[i].y); p[i].pos=i;}
    build_tre(1,0);
    dfs(1,0,1,n);
    for(i=1;i<=n;i++) printf("%I64d ",ans[i]);
    return 0;
}
******************/
```
###错题记录
刚开始爆int了。。
***
