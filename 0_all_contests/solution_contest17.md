[比赛链接](https://vjudge.net/contest/171671)
[CF链接](http://codeforces.com/contest/447)

## A
### Problem description
> 给出整数p，n，再给出n个数a[i]，建立一个哈希表，哈希函数为(a[i]%p)，问哈希表在哪个数上出现了冲突，输出该数所在位置。若整个哈希表未发生冲突，则输出-1。

### Data Limit:2≤p,n≤300  Time Limit:1s

### Solution
> 按题意模拟。建立一个数组记录(a[i]%p)出现的次数，若次数大于1则出现冲突，输出数所在的位置。若整个过程中未出现冲突，则输出-1。

### Code
```cpp
int main()
{
    int a[305],p,n,x;
    scanf("%d%d",&p,&n);
    memset(a,0,sizeof(a));
    for (int i=1;i<=n;++i)
    {
        scanf("%d",&x);
        if (a[x%p]>0)
        {
            printf("%d\n",i);
            return 0;
        }
        if (a[x%p]==0) ++a[x%p];
    }
    printf("-1\n");
    return 0;
}
```
*****


## B
### Problem description
> 先给出一个字符串，然后可在这个字符串后添k个字符，26个字母都有相应的价值。问怎样添加字符可使所有字符权值和最大。单个字符的权值计算方式为该字符位置i×该字符的价值a[i]。

### Data Limit:字符串长度1≤|s|≤1000,0≤k≤1000  Time Limit:1s
### Solution
> 按题意模拟。先算原字符串所有字符的权值和，然后将价值最大的字符添在原字符串后面，计算权值即可。


### Code
```cpp
char s[1005];
int k,a[26],t,ans=0;
int main()
{
    scanf("%s",s);
    scanf("%d",&k);
    for (int i=0;i<26;++i)
    {
        scanf("%d",&a[i]);
        if (a[i]>t) t=a[i];
    }
    int len=strlen(s);
    for (int i=0;i<len;++i)
    ans+=a[s[i]-'a']*(i+1);
    for (int i=len;i<len+k;++i)
    ans+=t*(i+1);
    printf("%d\n",ans);
    return 0;
}
```
*****


## C
### Problem description
> 给出整数n，再给出n个整数，我们可以最多改变一个整数的值。求数列中连续严格递增的子序列的长度。

### Data Limit：n <= 1e5  Time Limit: 1s

### Solution
> DP。先正向搜出每个数所在位置已经构成了最长严格递增子序列的长度，再反向搜出每个数所在位置相对后面的数已经构成了最长严格递减子序列的长度，然后枚举每一个数的前后位置，若a[i-1] < a[i+1]-1，则ans=max(ans,正向长度b[i-1]+反向长度c[i+1]+1)，别忘了再将ans与原本已经存在的最长子序列长度+1比较即可。


### Code
```cpp
const int N = 222222;

int a[N];
int forward[N], backward[N];
int main()
{
        int n;
        cin >> n;
        int ret =  1;
        for(int i = 1; i <= n; i++) {
                cin >> a[i];
                forward[i] = a[i - 1] < a[i] ? (forward[i - 1] + 1) : 1;
                if(i < n)
                ret = std::max(ret, forward[i] + 1);
        }
        for(int i = n; i >= 1; i--) {
                backward[i] = a[i] < a[i + 1] ? (backward[i + 1] + 1) : 1;
                if(i > 1)
                ret = std::max(ret, backward[i] + 1);
        }
        for(int i = 2; i < n; i++) {
                if(a[i - 1] + 1 < a[i + 1] && forward[i - 1] + backward[i + 1] + 1 > ret) {
                        ret = forward[i - 1] + backward[i + 1] + 1;
                }
        }
        cout << ret << endl;
        return 0;
}
```
*****


## D
### Problem description
> 给你一个n*m的矩阵,你可以进行k次操作，操作1是把一行的每个元素都减去p,你可以获得该行所有元素和(操作之前)的pleasure，操作2是把一列的每个元素都减去p,你可以获得该列所有元素和(操作之前)的pleasure，问你最大可以获得的pleasure是多少。

### Data Limit:1≤n,m≤1000;1≤k≤1e6;1≤p≤100  Time Limit:2s
### Solution
> 可以发现,如果确定了选几次行,几次列,那么选哪几行对选择哪几列是没有影响的,反之亦然.所以我们可以贪心的选出最大的0~k个行或列,最后枚举选几行并取大值即可

### Code
```cpp
long long n,m,k,p,ans,a[1005][1005];
long long c[1000005],r[1000005],cc[1000005],rr[1000005];
int main()
{
    scanf("%lld%lld%lld%lld",&n,&m,&k,&p);
    for (int i=1;i<=n;++i)
    for (int j=1;j<=m;++j)
    {
        scanf("%lld",&a[i][j]);
        cc[i]+=a[i][j];
        rr[j]+=a[i][j];
    }
    priority_queue<long long>Q;
    for (int i=1;i<=n;++i)
    Q.push(cc[i]);
    for (int i=1;i<=k;++i)
    {
        int now=Q.top();
        Q.pop();
        c[i]=c[i-1]+now;
        now-=m*p;
        Q.push(now);
    }
    while (!Q.empty()) Q.pop();
    for (int i=1;i<=m;++i)
    Q.push(rr[i]);
    for (int i=1;i<=k;++i)
    {
        int now=Q.top();
        Q.pop();
        r[i]=r[i-1]+now;
        now-=n*p;
        Q.push(now);
    }
    ans=-(long long)1<<60;
    for (int i=0;i<=k;++i)
    ans=max(ans,c[i]+r[k-i]-i*(k-i)*p);
    printf("%lld\n",ans);
    return 0;
}
```
*****

## E
### Problem description
> 定义斐波那契数列前两项F[1]=1，F[2]=1。给出整数n，m，再给出n个数和m项操作。每个操作包含三个数op，l，r，若op=1，就在[l,r]的区间相应加上F[1,r-l+1]斐波那契数列，若op=2，就将[l,r]中所有数统计和并输出。

### Data Limit:1≤n,m≤300000  Time Limit:4s

### Solution
> 线段树。两个斐波那契的定理，用数学归纳法很容易证明：1.定义F[1]=a,F[2]=b,F[n]=F[n-1]+F[n-2]（n≥3）。有F[n]=b*fib[n-1]+a*fib[n-2]（n≥3），其中fib[i]为斐波那契数列的第i项。2.定义F[1]=a,F[2]=b,F[n]=F[n-1]+F[n-2]（n≥3）。有F[1]+F[2]+……+F[n]=F[n+2]-b。这题还有一个事实，就是两个上述定义的数列，相加，仍然符合F[n]=F[n-1]+F[n-2]的递推公式。利用这两个定理，用线段树维护序列，线段树的每个结点记录这一段的前两项是什么，预处理好斐波那契数列，便能计算出每一个结点中间的数是多少、每一个结点的和。
> 也可以利用分块来做，维护的方法跟线段树类似，都是把L R区间的修改变成一段段的来维护。

### Code
```cpp
int n,m,f1[maxn*4],f2[maxn*4],sum[maxn*4],a[maxn],fib[maxn];
void init()
{
    fib[1]=fib[2]=1;
    for (int i=3;i<=n+2;++i)
    {
        fib[i]=fib[i-1]+fib[i-2];
        if (fib[i]>=mod) fib[i]-=mod;
    }
}
int get_fib(int a,int b,int n)
{
    if (n==1) return a;
    if (n==2) return b;
    return ((long long)b*fib[n-1]+(long long)a*fib[n-2])%mod;
}
int get_sum(int a,int b,int n)
{
    return (get_fib(a,b,n+2)-b+mod)%mod;
}
void add_fib(int x,int l,int r,int a,int b)
{
    (f1[x]+=a)%=mod;
    (f2[x]+=b)%=mod;
    (sum[x]+=get_sum(a,b,r-l+1))%=mod;
}
void pushdown(int x,int l,int r)
{
    int mid=(l+r)>>1;
    add_fib(x<<1,l,mid,f1[x],f2[x]);
    add_fib((x<<1)|1,mid+1,r,get_fib(f1[x],f2[x],mid+1-l+1),get_fib(f1[x],f2[x],mid+2-l+1));
    f1[x]=f2[x]=0;
}
void maintain(int x)
{
    sum[x]=(sum[x<<1]+sum[(x<<1)|1])%mod;
}
void build(int x,int l,int r)
{
    int mid=(l+r)>>1;
    if (l==r) sum[x]=a[l];
    else
    {
        build(x<<1,l,mid);
        build((x<<1)|1,mid+1,r);
        maintain(x);
    }
}
void update(int x,int l,int r,int a,int b)
{
    if (a<=l&&r<=b) add_fib(x,l,r,fib[l-a+1],fib[l+1-a+1]);
    else
    {
        pushdown(x,l,r);
        int mid=(l+r)>>1;
        if (a<=mid) update(x<<1,l,mid,a,b);
        if (mid<b) update((x<<1)|1,mid+1,r,a,b);
        maintain(x);
    }
}
int query(int x,int l,int r,int a,int b)
{
    if (a<=l&&r<=b) return sum[x];
    else
    {
        int ret=0,mid=(l+r)>>1;
        pushdown(x,l,r);
        if (a<=mid) (ret+=query(x<<1,l,mid,a,b))%=mod;
        if (mid<b) (ret+=query((x<<1)|1,mid+1,r,a,b))%=mod;
        return ret;
    }
}
int main()
{
    scanf("%d%d",&n,&m);
    for (int i=1;i<=n;++i)
    scanf("%d",&a[i]);
    init();
    build(1,1,n);
    int op,l,r;
    for (int i=1;i<=m;++i)
    {
        scanf("%d%d%d",&op,&l,&r);
        if (op==1) update(1,1,n,l,r);
        if (op==2) printf("%d\n",query(1,1,n,l,r));
    }
    return 0;
}
```

```
```