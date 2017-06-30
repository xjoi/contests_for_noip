# Solution Of Contest13


[比赛链接 VJ](https://vjudge.net/contest/168406)

[Origin](http://codeforces.com/contest/375)

------------------------------

## A -Crazy Computer
### Problem Description
> 小明在屏幕上隔一定时间打一个字符，而如果打两个字符时间隔大于C时会将屏幕上的字符清空，给定他打字符的时间，求最后屏幕上会剩下几个字符。

### Solution
> 暴力模拟。扫一遍，如果相邻两个差>C就清零。

### Code

```cpp
int main(){
	int n,c;cin >>n>>c;int cnt=0;
	for (int i=1;i<=n;++i) scanf("%d",&a[i]);
	for (int i=2;i<=n;++i) if (a[i]-a[i-1]>c) cnt=0;else ++cnt;
	cout <<cnt+1<<endl;return 0;
}
```

-----------------------

## B -Complete the Word
### Problem Description
> 给定一个字符串（‘？’可表示任意一个字符），问是否存在一个长度为26的子串使其恰好包含26个字母（所以字符都是大写字母），如存在输出将‘？’转化后的字符串。

### Solution
> 模拟一遍。用f[]记录每个字母出现的次数。想象一个长度为26的字串在总串中滑动，每次向右移的时候只需判断首尾的字符更新即可。每次判断，如果有每个字母（已有的）出现次数都小于1的话，把‘？’替换成没出现过的，其余的只要随便填一个就可以了。

### Code
```cpp
bool can(){ //判断当前是否可行
	for (int i=0;i<26;++i) if (f[i]>1) return false;return true;
}


void print(int k){ //打印
	for (int i=k;i<k+26;++i)
		if (s[i]=='?'){
			for (int j=0;j<26;++j) 
				if (f[j]==0) {f[j]=1;s[i]=(char)(j+'A');break;}
		}
	for (int i=0;i<len;++i) if (s[i]=='?') cout <<'A';else cout <<s[i];
}


int main(){
	scanf("%s",s);
	len=strlen(s);
	if (len<26) {puts("-1");return 0;}
	for (int i=0;i<26;++i) if (s[i]=='?') ++cnt;else ++f[s[i]-'A'];
	for (int i=0;i<=len-26;++i)
		if (can()) {print(i);return 0;}
		else {
			if (s[i]=='?') --cnt;else --f[s[i]-'A'];
			if (i+26<len) {if (s[i+26]=='?') ++cnt;else ++f[s[i+26]-'A'];}
		}
	puts("-1");return 0;
}
```

*****

## C -Plus and Square Root
### Problem Description
> 你有一个等级k，初始等级为1。你有一个数x，初始数为2。定义两个操作sqrt（x）和plus（x）：sqrt（x）表示将x开根当且仅当x是一个完全平方数。plus（x）表示x+=k。k会加1当且仅当进行一次sqrt（）操作，而执行sqrt（）操作的前提是操作后的数x2为k2的倍数（k2=k+1）。求每次在sqrt（）操作之前需要几次plus（）操作。（只要输出一种可行解即可）

### Solution
> 我们先做一个假设：X为上一次的数，而X2为经过sqrt（）操作后的数；K为上一等级，而K2为K+1等级。可以发现X2一定是K2的倍数，X是K的倍数（废话），而X2=sqrt（X），所以X也应该是K2^2的倍数。所以一定存在一种可行的X=K2·K2·K·K（因为要保证能开方）。而要输出的却是plus（）的操作数，故还要定义一个XL表示执行plus（）之前的数，由推论得：XL=K·（K-1），X-XL=K2·K2·K·K-K·（K-1）=K·（K2·K2·K-（K-1）），故操作次数为K2·K2·K-（K-1）。另对于初始情况K=1，XL=2，可以直接输出2，得K2=2，X=4，X2=2，可以证明此时仍符合上述假设（除了XL=K·（K-1），因为初始的XL并不会影响什么，因为已经输出2了），故算法正确性得知。

### Code
```cpp
main(){
	int n,t=2;cin >>n;
	cout <<2<<endl;
	for(int i=2;i<=n;i++){t=(i+1)*(i+1)*i;t-=i-1;cout <<t<<endl;}
	return 0;
}
```

-------------------

## D -Complete The Graph
### Problem Description
> 给定一个图，N个点M条边，给定起点S和终点T和距离L。在此图中给出的某些边的权值为0，设定该种边为可变边，该种边的权值可以被重新定义。问是否存在一种修改可变边使得S到T的最短路恰好为L。如存在，输出修改过的图，否则”NO“。

### Solution
> 先来分析NO的情况：
> 1. 当存在S到T的最短路不经过任何一条可变边，且最短路长度小于L，那不会有某种修改还会使其最短路变长。
> 2. 假定所有可变边长度都为1（已经最小啦），此时的最短路如果大于L，那也不会再使其再短了。
> 
> 如果没有上述情况的，那一定会有解存在。首先要明白一个道理，即一条最短路径上的可变边的权值之和不变，那最短路的长度就不会变，所以具体在那条边上多一点是无所谓的。用check（x）表示所有可变边权值之和为x时是否有解。而在分配权值时遵循以下规则：val=1+min(sum,1e9)；sum表示剩余的权值，（1是因为权值不能为0），那么每当x逐个递增时会不断增加第一条权值不为满的边（即小于1e9），如果在加解所在的边的时候，总会在某一个时候加为合适的值（L<=1e9），故合理。显然，当check（x）>L时，需要减掉一些权值使其接近正解；当check（x）<L时，需要加更多的权值，故可以用二分来实现。

### Code
```cpp
#include<iostream>
#include<cstdio>
#include<queue>
#include<vector>
#include<cstring>
#define int long long
using namespace std;
const int INF=1e15,MAX=1e9,N=1e3+9;
struct Edge{int to,fr,pre,w;}e[N*N];
struct XY{int dis,id;}d[N];
struct cmp1{bool operator ()(XY &a,XY &b){return a.dis>b.dis;}};
vector<int> EmpEdge;
int sz=1,n,m,L,ss,tt,xx,yy,zz;
int las[N];


void add(int a,int b,int c){
	e[++sz].to=b;e[sz].fr=a;e[sz].w=c;e[sz].pre=las[a];las[a]=sz;
}


int dijkstra(){
	bool vis[N];memset(vis,0,sizeof(vis));
	priority_queue<XY,vector<XY>,cmp1> Q;
	for (int i=0;i<=n;++i) d[i].dis=MAX+9,d[i].id=i;
	d[ss].dis=0;Q.push(d[ss]);
	
	while (!Q.empty()){
		XY u=Q.top();Q.pop();
		if (vis[u.id]) continue;
		vis[u.id]=1;
		for (int i=las[u.id];i;i=e[i].pre)
			if (d[e[i].to].dis>d[u.id].dis+e[i].w)
				d[e[i].to].dis=d[u.id].dis+e[i].w,Q.push(d[e[i].to]);
	}
	return d[tt].dis;
}


int check(int sum){
	for (int i=0;i<EmpEdge.size();++i){
		e[EmpEdge[i]].w=e[EmpEdge[i]^1].w=1+min(sum,MAX);
		sum-=e[EmpEdge[i]].w-1;
	}return dijkstra();
}


main(){
	scanf("%lld%lld%lld%lld%lld",&n,&m,&L,&ss,&tt);
	for (int i=0;i<m;++i){
		scanf("%lld%lld%lld",&xx,&yy,&zz);
		add(xx,yy,zz);add(yy,xx,zz);
		if (!zz) EmpEdge.push_back(sz);
	}
	int l=0,r=EmpEdge.size()*MAX;
	if (check(l)>L||check(r)<L) return 0*puts("NO");
	
	while (l<=r){
		int mid=(l+r)>>1,tmp=check(mid);
		if (tmp>L) r=mid-1;else if (tmp<L) l=mid+1;else break;
	}
	puts("YES");
	for (int i=2;i<=m*2+1;i+=2) printf("%lld %lld %lld\n",e[i].fr,e[i].to,e[i].w);
	return 0;
}
```

-------------------------

## E -Digit Tree
### Problem Description
> Please Wait！

### Solution
> 

### Code
```cpp

```

*****
