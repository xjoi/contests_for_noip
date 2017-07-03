[比赛链接](http://codeforces.com/contest/787/)

# 比赛中解决的问题
## A
### Problem description
> 给你四个整数a,b,c,d,有两个数列，第一个数列为b,b+a,b+2a......,第二个数列为d,d+c,d+2*c,......。
  现要你求出两数列第一次相等时的值，并输出这个值，如果这两个数列的数永远不会相等，就输出-1.

### Data Limit：1<=A,B,C,D<=100 Time Limit: 1s

### Solution
>   法一：暴力枚举，用一个布尔数组记录一下就好了。</P>
    法二：由题意，得：ax+b=cy+d ---> ax-cy = d-b。</P>
          ax-cy=d-b形似ax+by=c。 根据扩展欧几里得算法，易知当c% gcd(a,b) 时不定方程有解，当不定方程有解时，通解为x=x0+(a/gcd)*t,y=y0-(b/gcd)*t</p>
          那么我们就可以做这题了。 先做一遍扩展欧几里得算法，因为求出的x和y不一定是正数，也不一定是最小值，所以还要我们利用通解搞一搞，没了。</P>
### Code
```cpp
方法一：
#include<iostream>
#include<cstdio>
using namespace std;
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
#include<bits/stdc++.h>
using namespace std;
int extgcd(int a,int b,int &x,int &y)
{
	if (b==0)
	{
		x=1; y=0; return a;
	}
	int ans = extgcd(b,a%b,x,y);
	int temp = x;
	x = y;
	y = temp-a/b*y;
	return ans;
}
int main()
{
	int a,b,c,d,x,y;
	scanf("%d%d%d%d",&a,&b,&c,&d);
	int g = extgcd(a,-c,x,y);
	if ((d-b)%g!=0)
	{
		puts("-1");
	}
	else
	{
		x*=(d-b)/g; y*=(d-b)/g;
		int flag = g <0? -1 : 1;
		while (x<0||y<0) 
		{
			x -= flag *(-c/g);
			y += flag *(a/g);
		}
		while (x+flag*(-c/g)>=0&&y-flag*(a/g)>=0)
		{
			x+=flag*(-c/g); y-=flag*(a/g);
		}
		printf("%d\n",x*a+b);
	}
	return 0;
}
```
*****


## B
### Problem description
> 给你M组数，如果每组数中都有至少一对相反数，那么就输出NO，否则输出YES。数据保证每个数的绝对值都会小于N</P>

### Data Limit：fabs(n），fabs(m) <= 1e4  Time Limit: 2s
### Solution
> 我一直很好奇这道题为什么要开2秒时限。我是这样做的，开一个map数组，对于一个数，我们把map【fabs(这个数）】置为cnt（cnt代表第几组数据）。</P>
  如果我们在将map[fabs(这个数)]置为cnt 之前这个位置就已经被标记过了，那么就直接输出NO。如果一直没输出NO就输出YES。</P>
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
> 有n个位置1,2,3……n，围成1个圈，某个物体最开始的位置不在1，两个人轮流操作，每个人操作时可以让这个物体顺时针运动一些位置，使物体最终到达1号位置的人胜。</P>
   求：物体初始在每个位置（不包括1），两个人分别先手的胜负情况。</P>
### Data Limit：n <=7000 Time Limit: 4s

### Solution
> 每个人每个状态无非就是三种情况：必胜（Win），必败（Lose），无法到达（Loop）。这其实是博弈论。</P>
  由于必败状态必定由所有必胜状态可推得，必胜状态只要1个必败状态就可以推出，那我们可以通过BFS/DFS的方式实现。</P>
  设状态(x,y)表示当前是编号为y的人操作，物体位置在x。那么(1,0)和(1,1)必然是必败状态。</P>
  我们可以先由着必败状态（1,0）和（1,1）来推出第一波必胜状态，开始DFS。</P>
  考虑一个状态（X,Y），如果这个状态可以转移到的所有状态对于1-Y都是必胜状态，那么很明显，这个状态（x,y）对于y来说是没有活路的，是必败的</P>
  因为必胜状态的推出要依赖于必败状态，所以我们有必要找到高效地从必胜状态转移出必败状态的方法。</P>
  由上面我们考虑过的必败状态的得出方法有点慢，所以我们要换个方向看。</P>
  对于一个必胜的状态，我们可以把所有可以一步到这个必胜状态的状态的计数器+1，当一个状态的计数器到达了tot【y】时（tot[y]表示Y这个人的集合里的数字数目）</P>
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
//	printf("YES");
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
> 简单点来说就是构造一个图，构造的方法有 </P>
       1、u → v </P>
       2、u → [l,r] </P>
       3、[l,r] → u </P>
  这三种情况，每种情况都会可以构成权值为c的边 </P>
  一共会输入M次建边操作，点的个数为N。</P>
  然后问ss到所有点的最短路是多少</P>
### Data Limit：n <= 1e5 ， ss <=1e5 ， M<=1E5  Time Limit: 2s
### Solution
> 如果我们暴力建边，显然不可做，那么我们应该怎么做呢？</P>
  发现题目保证了2,3操作是一段连续的区间建边，所以我们可以利用线段树来构造用来指代线段的虚拟节点。</P>
  于是我们就愉快地构建起了线段树，每个线段树的节点都是代表了一段线段，我们连边时就不需要一条一条地把边连到单个节点了，只要连到虚拟节点就可以啦。</P>
  最后来一个堆优化的迪杰斯特拉算法，没了。。。。</P>
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
