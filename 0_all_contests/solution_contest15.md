[比赛链接](http://codeforces.com/contest/787/)

# 比赛中解决的问题
## A
### Problem description
给出两个数列：b, b + a, b + 2a, b + 3a, ...和d, d + c, d + 2c, d + 3c, ....。要求求出他们的最小公共项。
### Data Limit：1<=A,B,C,D<=100 Time Limit: 1s
### Solution
题意即是求b+xa=d+yc的最小碰撞正整数.我们将问题转化为ax-cy=d-b=k\*gcd(a,c) k为正整数，否则无解。

根据gcd可知，`|x|<=K*max(|a|,|c|)`,而这题a,b,c,d的范围都很小所以可以用暴力法.

+ 法一：暴力枚举，用一个布尔数组记录一下就好了。
+ 法二：**exgcd**\
已知方程ax+by=1,若gcd(a,b)=1,则原方程可写成\
 *ax+by=gcd(a,b)*.\
 而 gcd(a,b)=gcd(b,a mod b)\
 所以 ax+by=gcd(a,b)=gcd(b,a mod b)=bx'+(a mod b)y'\
 即 ax+by=bx'+(a mod b)y'=bx'+(a-[a/b]\*b)y'\
 移项得 ax+by=ay'+b(x'-[a/b]\*b)\
 根据恒等定理有 x=y',y=x'-[a/b]\*b\
 由于欧几里德算法最后一步为gcd(d,0)=d,此时对应的等式的解为x=1,y=0,因此只要如上述代码,从gcd(d,0)往前处理,在进行欧几里德算法的递归的时候根据相邻两次调用间x,y和x’,y’的关系计算即可求出ax+by=gcd(a,b)的解.\
 **回到原题**\
 本题相当于求 *ax+b=cy+d* x,y的自然数解。\
 即*ax+(-c)y=d-b*.\
 设gcd(a,-c)=g\
 所以可以求出ax-cy=g的解，再扩大(d-b)/g倍（若(d-b)/g不为整数，则无解），再调整解，使其为最小整数解。 \
 实际上在之前的计算和证明中我们得到的只是不定方程的一组解,那么怎样得到所有解呢?\
 对于一般形式ax+by=c有通解x′=x+kb,y′=y−ka(k为任意整数).(证明略,只要代入一下就知道为什么通解是这个了)
### Code
```cpp
方法一：
bool map[500000];
int main()
{
	int a,b,c,d,t1,t2;
	scanf("%d%d",&a,&b);
	scanf("%d%d",&c,&d);
	for (int i=0; i<=1000; i++) map[b+i*a] = true;
	for (int i=0; i<=1000; i++) if (map[d+c*i]) {printf("%d",d+c*i); return 0;}
	printf("-1");
	return 0;
}

方法二：
int exgcd(int a,int b,int &x,int &y){
	int d=a;
	if (b!=0){
		d=exgcd(b,a%b,x,y);
		x-=(int(a/b))*y;
		swap(x,y);
	}else{
		x=a*1;y=0;
	}
	return d;
}
int gcd(int a,int b){
	return b==0?a:gcd(b,a%b);
}
int main(){
	int a,b,c,d;
	scanf("%d%d%d%d",&a,&b,&c,&d);
	int x,y;
	if (b==d) {
		printf("%d",b);
		return 0;
	}
	int k=gcd(a,c);
	int g=d-b;
	int A=a,C=c;
	if (g%k==0){
		A/=k;C/=k;g/=k;
	}
	if ((abs(exgcd(A,-C,x,y)))==1){
		//printf("%d  %d  ",x,y);
		x*=g;y*=g;
		while (x<0||y<0){
			x+=C;y+=A;
		}
		while (x-C>=0&&y-A>=0){
			x-=C;y-=A;
		}
		//printf("%d  %d  ",x,y);
		printf("%d",b+a*x);
	}else printf("-1");  
}
```
*****

## B
### Problem description
给你n个人，m个组，判断每个组中是否含有一对相反数，如果任意一组中一个都没有就输出YES，否则输出NO

### Data Limit：fabs(n），fabs(m) <= 1e4  Time Limit: 2s
### Solution
只需要扫描每个序列，用set/map/bool数组 记录每一个数的出现情况，读入一个数时判断它的相反数是否存在即可。

但是，在扫描到存在相反数时，不能够直接break，否则会将没读进的数误认为是下一个序列的数。（注意把没用的数据从输入流里读取掉）
### Code
```cpp
#include<map>
#include<iostream>
#include<map>
using namespace std;
int q,w,l,e,o=1,c=1;
map<int, int> mt;
int main()
{
    for(cin>>q>>w; c<=w && o; c++)
        for(o=0,cin>>l; l--; o|=(mt[-e]==c),mt[e]=c) cin>>e;
    cout<<(o?"NO":"YES");
}
```
*****

## C
### Problem description
有n个位置1,2,3……n，围成1个圈，某个物体最开始的位置不在1，两个人轮流操作，每个人操作时可以让这个物体顺时针运动一些位置，使物体最终到达1号位置的人胜。

求：物体初始在每个位置（不包括1），两个人分别先手的胜负情况。
### Data Limit：n <=7000 Time Limit: 4s

### Solution
> 每个人每个状态无非就是三种情况：必胜（Win），必败（Lose），无法到达（Loop）。这其实是博弈论。</P>
  由于必败状态必定由所有必胜状态可推得，必胜状态只要1个必败状态就可以推出，那我们可以通过BFS/DFS的方式实现。</P>
  设状态(x,y)表示当前是编号为y的人操作，物体位置在x。那么(1,0)和(1,1)必然是必败状态。</P>
  我们可以先由着必败状态（1,0）和（1,1）来推出第一波必胜状态，开始DFS。</P>
  考虑一个状态（X,Y），如果这个状态可以转移到的所有状态对于!Y都是必胜状态，那么很明显，这个状态（x,y）对于y来说是没有活路的，是必败的</P>
  因为必胜状态的推出要依赖于必败状态，所以我们有必要找到高效地从必胜状态转移出必败状态的方法。</P>
  由上面我们考虑过的必败状态的得出方法有点慢，所以我们要换个方向看。</P>
  对于一个必胜的状态，我们可以把所有可以一步到这个必胜状态的状态的计数器+1，当一个状态的计数器到达了tot[y]时（tot[y]表示Y这个人的集合里的数字数目）</P>
  就说明这个状态可以到达的所有状态都是对手必胜，那么我们就知道这个状态是必败状态了。把这个状态可以到达的必胜状态进行新的一轮DFS就可以了。</P>
### Code
```cpp
#include<bits/stdc++.h>
using namespace std;
int n,k[2],v[2][7003];
int dp[2][7003],cnt[2][7005];
void f(int x,int j)
{
	if (dp[j][x]) return;
	dp[j][x] = 2;
	if (!x) return;
	for (int i=0; i<k[!j]; i++) 
	{
		cnt[!j][(x-v[!j][i]+n)%n]++; 
		if (cnt[!j][(x-v[!j][i]+n)% n]==k[!j]) 
		{
			dp[!j][(x-v[!j][i]+n)%n] = 1;
			int s=(x-v[!j][i]+n)%n;
			for (int l=0; l<k[j]; l++)  f((s-v[j][l]+n)%n,j);
		}
	}
}
int main()
{
	scanf("%d",&n);
	scanf("%d",&k[0]); for (int i=0; i<k[0]; i++) scanf("%d",&v[0][i]);
	scanf("%d",&k[1]); for (int i=0; i<k[1]; i++) scanf("%d",&v[1][i]);
	for (int j=0; j<2; j++) 
			for (int i=0; i<k[j]; i++) f(n-v[j][i],j);
	for (int j=0; j<2; j++)
	{
			for (int i=1; i<n; i++) 
			printf("%s ",dp[j][i]==2?"Win":dp[j][i]==1?"Lose":"Loop");
			printf("\n");
	}
 } 
```
*****

## D
### Problem description
给你一个图，以及三种类型的边
1. 普通的u->v;   
2. u->range[l,r]中任意一点都可以
3. range[l,r]->u 

求出s到每个点的最短路
### Data Limit：n <= 1e5 ， s <=1e5 ， M<=1E5  Time Limit: 2s
### Solution
如果我们暴力建边，那么建边的过程中可能就超时了.

发现题目保证了2,3操作是一段连续的区间建边，所以我们可以利用线段树来构造用来指代线段的虚拟节点。

于是我们就愉快地构建起了线段树，每个线段树的节点都是代表了一段线段，我们连边时就不需要一条一条地把边连到单个节点了，只要连到虚拟节点就可以啦。

最后来一个堆优化的迪杰斯特拉算法
### Code
```cpp
#include<bits/stdc++.h>
using namespace std;
const int maxn=2e6+7;
int tme,n,q,ss;
vector<pair<int,int> >v[maxn];
long long dist[maxn],ver[2][maxn];
int build(int y,int l,int r,int x)//X=0表示这是正着的线段树，X=1表示这是下面的倒着的线段树 
{
	if (l==r) return ver[x][y] = l;
	ver[x][y] = ++tme; //ver[x][y]表示id为x的线段树的第y个节点代表的虚拟节点的编号 
	int mid = (l+r)/2;
	int cl = build(y*2,l,mid,x);
	int cr = build(y*2+1,mid+1,r,x);
	if  (x==0) //分树的正反来操作 
	{
		v[ver[x][y]].push_back(make_pair(cl,0));//向当前的这个节点加权值为0的出边 
		v[ver[x][y]].push_back(make_pair(cr,0)); 		
	} 
	 else
	 {
	 	v[cl].push_back(make_pair(ver[x][y],0));
	 	v[cr].push_back(make_pair(ver[x][y],0));	//加权值为0的入边 	
	 }
	return ver[x][y];	
}
void update(int x,int l,int r,int ll,int rr,int xx,int w,int z)
{
	if (ll>r||rr<l) return;
	if (l>=ll&r<=rr)
	{
		if (z==0) v[xx].push_back(make_pair(ver[z][x],w));
		else v[ver[z][x]].push_back(make_pair(xx,w));
		return;
	 } 
	 int mid =(l+r) /2;
	 update(x*2,l,mid,ll,rr,xx,w,z);
	 update(x*2+1,mid+1,r,ll,rr,xx,w,z);
}
int main()
{ 
	scanf("%d%d%d",&n,&q,&ss);
	tme = n;
	build(1,1,n,0);
	build(1,1,n,1);
	for (int i=0; i<q; i++)
	{
		int id,a,b,c,d;
		scanf("%d%d%d%d",&id,&a,&b,&c);
		if (id==1) v[a].push_back(make_pair(b,c));
		else  {scanf("%d",&d);	update(1,1,n,b,c,a,d,id-2);	}
	 } 
	memset(dist,-1,sizeof(dist));
	priority_queue<pair<long long,int> >Q;
	dist[ss] = 0; Q.push(make_pair(0,ss));
	while (!Q.empty())
	{
		int now=Q.top().second; Q.pop();
		for (int i=0; i<v[now].size(); i++) 
		{
			int ve = v[now][i].first;
			int le = v[now][i].second;
			if (dist[ve]==-1||dist[now]+le<dist[ve]) 
		    {
		    	dist[ve] = dist[now] + le;
		    	Q.push(make_pair(-dist[ve],ve));
			 } 
		} 
	}
	for (int i=1; i<=n; i++) printf("%lld ",dist[i]);
	return 0;
}
```
*****



# 赛后补题


## E
### Problem description
> 给你n个数，问最少能把这n个数分成连续的几段，且每段中不同的个数小于等于k个，输出k从1到n的答案。</P>

### Data Limit：n <= 1e5  Time Limit: 2s

### Solution
> 考虑K=L和K=R的情况（r>=l），如果ans（L）==ans（R），那么显然ans[L..R]答案都是一样的，没了。。。。</P>
  要相信CF的机子快！这是信仰的分数！</P>

### Code
```cpp
#include<bits/stdc++.h>
using namespace std;
int c[100007],vis[100007],ans[100007];
int n;
int get_cnt(int k)
{
	int res = 0, cnt = 0;
	memset(vis,-1,sizeof(vis));
	for (int i=1; i<=n; i++)
	{
		if (vis[c[i]]==res) continue;
		vis[c[i]] = res;
		cnt ++ ;
		if (cnt>k) { res++; cnt = 1; vis[c[i]]= res;}
	}
	return res+1;
}
void solve(int l,int r)
{
	if (l>r) return ;
	int cntl=get_cnt(l); int cntr=get_cnt(r);
	if (cntl==cntr)
	{
		for (int i=l; i<=r; i++) ans[i]=cntl;
		return;
	}
	ans[l] = cntl; ans[r] = cntr;
	int mid=(l+r) >> 1;
	solve(l+1,mid);
	solve(mid+1,r-1);
}
int main()
{
	scanf("%d",&n);
	for (int i=1; i<=n; i++) scanf("%d",&c[i]);
	solve(1,n);
	for (int i=1; i<=n; i++) printf("%d ",ans[i]);
	return 0;
}

```
