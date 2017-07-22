[比赛链接](http://codeforces.com/contest/197)


## A
### Problem description
> 给一张长为a，宽为b的桌子。设有无数张半径为r的圆形纸片。有两个人在桌子上放纸片，之前已放好的纸片不能挪动位置，纸片在放的时候不能相交但可以外切且不能超过桌子的边界，谁放不了谁就输了。问先手者是否可以必胜，若是输出“First”，否则输出“Second”。

### Data Limit:1≤a,b,r≤100  Time Limit:2s

### Solution
> 以对称性考虑问题。若圆的直径2×r>a或2×r>b，则不能放纸片，输出“Second”，否则若可以放下一个纸片，我们可以得出分析：当先手者把第一张纸片的圆心放在桌子的重心上，那么接下来无论后手者将纸片放在什么位置上，先手者都可以找到一个以第一个圆的圆心为对称中心，与后手者放的圆对称的位置。所以若能放纸片，则先手必胜，输出“First”。

### Code
```cpp
int main()
{
    scanf("%d%d%d",&a,&b,&r);
    if (2*r>a||2*r>b) printf("Second\n");
    else printf("First\n");
    return 0;
}
```
*****


## B
### Problem description
> 给出整数n，m，构造两个方程P(x)=a[0]·x^n+a[1]·x^n-1+...+a[n-1]·x+a[n]和Q(x)=b[0]·x^m+b[1]·x^m-1+...+b[m-1]·x+b[m]。求当x的值趋于无穷大时P(x)/Q(x)的值。

### Data Limit:0≤n,m≤100,-100≤ai,bi≤100,a0≠0,b0≠0  Time Limit:2s
### Solution
> 数学分析题。若n<m，则函数值无穷趋近于0，按题目要求输出“0/1”。若n=m，则输出a[0]/b[0]约分后的分数。若n>m，则判断a[0]*b[0]的正负性，若为负先输出负号，再输出“Infinity”即可。

### Code
```cpp
int n,m,a[105],b[105];
int gcd(int x,int y)
{
    if (y==0) return x;
    return gcd(y,x%y);
}
int main()
{
    memset(a,0,sizeof(a));
    memset(b,0,sizeof(b));
    scanf("%d%d",&n,&m);
    for (int i=0;i<=n;++i)
    scanf("%d",&a[i]);
    for (int i=0;i<=m;++i)
    scanf("%d",&b[i]);
    if (n<m)
    {
        printf("0/1\n");
        return 0;
    }
    if (n==m)
    {
        if (a[0]*b[0]<0) printf("-");
        a[0]=abs(a[0]);
        b[0]=abs(b[0]);
        int t=gcd(a[0],b[0]);
        printf("%d/%d\n",a[0]/t,b[0]/t);
    }
    if (n>m)
    {
        if (a[0]*b[0]<0) printf("-");
        printf("Infinity");
    }
    return 0;
}
```
*****



## C
### Problem description
> 给一个字符串，从字符串中找出一个可不连续但是必须按顺序的子串，使得子串的字典序最大。输出该子串。

### Data Limit：|S|<=1e5  Time Limit:2s

### Solution
> 贪心。按字母z到a的顺序搜索字符串。当字母为z时开始从前往后找，若找到z则输出，并将位置标记在此处。这样我们输出所有z后，找y就从标记z的最后一处开始找......以此类推可以得到字典序最大的子串。

### Code
```cpp
char s[100005];
int a[27];
int main()
{
    scanf("%s",s);
    int len=strlen(s);
    memset(a,0,sizeof(a));
    for (int i=25;i>=0;--i)
    {
        for (int j=a[i+1];j<len;++j)
        if (s[j]==i+'a')
        {
            printf("%c",s[j]);
            a[i]=j;
        }
        a[i]=max(a[i],a[i+1]);
    }
    return 0;
}

```
*****


## D
### Problem description
> 给定一个n×m的地图，“#”表示墙，不能走，“S”表示出发起点，“.”表示道路。现在将地图无限复制并贴合在一起，问是否能从一张小地图处的S走到另一张小地图处的S，若可以输出“Yes”，否则输出“No”。

### Data Limit：1≤n,m≤1500  Time Limit:2s
### Solution
> 用vis[x mod n][y mod m][0]和vis[x mod n][y mod m][1]分别记录上次到(x mod n,y mod m)时, 具体是在哪个(x,y)的位置, 若与上次相同, 说明进入走回去了, 否则是在另一个n*m的区域中, 说明能够到达无限远处 mod时应当用(x%n+n)%n, 否则当x为一个很小的负数时会引起RE

### Code
```cpp
bool dfs(int x,int y){
    //printf("%d %d ",x,y);
    int fx=(x%n+n)%n,fy=(y%m+m)%m;
    //printf("%d %d\n",fx,fy);
    if (a[fx][fy]=='#') return false;
    if (vis[fx][fy][0]!=inf) return vis[fx][fy][0]!=x||vis[fx][fy][1]!=y;
    vis[fx][fy][0]=x,vis[fx][fy][1]=y;
    for (int i=1;i<=4;++i) if (dfs(x+dx[i],y+dy[i])) return true;
    return false;
} 
```
*****

## E
### Problem description
> 给出一个n个点的树的连边情况, 并给出平面上的n个点的具体坐标, 要求给出树上的点和平面上的点一一对应的一种方案, 使得将平面上的点按照树的结构连边后, 没有任意两条边相交【保证没有三点共线】

### Data Limit：1 <= n <= 1500 Time Limit: 2s

### Solution
> 先默认一个根节点root, 用dfs求出每颗子树的节点总数, 确定每个点的孩子, 连边（题目没有给出根节点, 给出的连边不能确认两点间的父子关系）
然后从以根节点root为根的整棵树开始, 对于每颗子树, 找出最靠左下方的点s作为当前根节点的对应点, 将所有平面上的点按照与点s间的角度排序。 根据当前根节点的每个孩子所在的子树规模, 将排好序的点分成几块,作为子树的对应点继续递归 注意: 如果随意取点作为标准来排序, 则该点的360°都有点, 将排完序的点分为几块子树后, 不同块之间的边可能会产生影响
如果取左下角(或左上角或右上角或右下角), 将点根据子树分到不同区域后, 连边一定在该区域内, 不会对其他区域产生影响

### Code
```cpp
void tree(int x){
    vis[x]=1; sz[x]=1;
    for (int i=fst[x];i;i=nxt[i])
        if (!vis[des[i]]) tree(des[i]),add2(x,des[i]),sz[x]+=sz[des[i]];
}
bool cmp(Point i,Point j){
    if (i==s) return 1;
    if (j==s) return 0;
    double y=cross(i,j,s);
    if (y<0) return 0;
    return 1;
}
void solve(vector<Point>b,int fa){
    s=b[0];
    for (int i=1;i<b.size();++i) if (b[i]<s) s=b[i];
    sort(b.begin(),b.end(),cmp);
    int l=1; ans[s.num]=fa;
    for (int i=fstc[fa];i;i=nxtc[i]){
        int k=c[i]; vector<Point>m;
        for (int j=1;j<=sz[k];++j) m.push_back(b[l]),l++;
        solve(m,k);
    }
}
```

## F
### Problem decription
>给定n个点，m条边，再给出k个有传送门的点，若一个点已经经过一次且上面有传送门，则传送门可打开。若有两个点上面有传送门且传送门都打开，则可以直接在这两个点上瞬间移动。问遍历所有点至少需要经过多少长度的路径。

### Data Limit：1≤n≤1e5,0≤m≤1e5,1≤k≤n  Time Limit:2s
### Solution
>首先根据传送门的性质，如果所有点都是传送门的话那么结果就是该图的最小生成树。对于只有其中k个结点是传送门的图，只要在原算法的基础上稍作修改即可。具体，对每个点求出P[i]和D[i]（表示距离这个点最近的传送门和其距离）。之后对每条边，再根据D[x]+D[y]+w作为关键字跑最小生成树。以上分别用最短路和稍作修改的克鲁斯卡尔求最小生成树即可。
### Code

```cpp
struct edge{
    int u,v;
    long long c;
}e[maxn];
int n,m,k,u,v,y[maxn],next[maxn],fir[maxn],fa[maxn],p[maxn],tot=1;
long long d[maxn],w[maxn],c,ans;
bool vis[maxn];
priority_queue< pair<long long,int> >Q;
bool cmp(edge a,edge b){
    return a.c<b.c;
}
int find(int x)
{
    return fa[x]==x?x:fa[x]=find(fa[x]);
}
void add(int u,int v,long long c)
{
    y[tot]=v;
    next[tot]=fir[u];
    w[tot]=c;
    fir[u]=tot++;
}
int main()
{
    scanf("%d%d",&n,&m);
    for (int i=1;i<=m;++i)
    {
        scanf("%d%d%I64d",&u,&v,&c);
        e[i]=(edge){u,v,c};
        add(u,v,c);
        add(v,u,c);
    }
    memset(d,50,sizeof(d));
    scanf("%d",&k);
    for (int i=1;i<=k;++i)
    {
        scanf("%d",&u);
        d[u]=0;
        p[u]=u;
        Q.push(make_pair(0,u));
    }
    while (Q.size())
    {
        while (vis[u=Q.top().second]&&Q.size()) Q.pop();
        if (Q.empty()) break;
        vis[u]=1;
        Q.pop();
        for (int i=fir[u];i;i=next[i])
        if (d[u]+w[i]<d[y[i]])
        {
            d[y[i]]=d[u]+w[i];
            p[y[i]]=p[u];
            Q.push(make_pair(-d[y[i]],y[i]));
        }
    }
    for (int i=1;i<=m;++i)
    {
        e[i].c+=d[e[i].u]+d[e[i].v];
        e[i]=(edge){p[e[i].u],p[e[i].v],e[i].c};
    }
    sort(e+1,e+m+1,cmp);
    for (int i=1;i<=n;++i)
    fa[i]=i;
    for (int i=1;i<=m;++i)
    if (find(e[i].u)!=find(e[i].v))
    {
        fa[fa[e[i].u]]=fa[e[i].v];
        ans+=e[i].c;
    }
    printf("%I64d",ans+d[1]);
    return 0;
}
```