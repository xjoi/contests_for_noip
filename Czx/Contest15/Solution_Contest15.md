
[比赛链接](https://vjudge.net/contest/168929)

# 比赛中解决的问题
## A
### Problem description
> 可以抽象地看做数轴上有两个点，坐标为a,c，每个点一次可以向右移动b,d，问两点最快在哪个坐标能重叠，若不能则输出-1（a,b,c,d <= 100）

### Solution
> 作为一道A题，是一道裸暴力题，因为数据范围很小，所以可以暴力解决。
> 当然也要想一下，当数据范围变大时，应该如何解决，现在能想出来的方法是用扩展欧几里得来实现，应该可以过100000以内的数据，若更大就不知道应该如何更优地解决了

### Code
```cpp
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int main(){
	int a,b,c,d,e,f;
	cin >> a >> b >> c >> d;
	for (int i=1;i<=100000;++i){
		if (b < d)	b += a;
		else if (b > d)	d += c;
		else{
			cout << b << endl;
			return 0;
		}
	}
	cout << -1 << endl;
	return 0;
}
```
*****


## B
### Problem description
> 给出一个数列，求这个数列中是否存在两个数互为相反数，每个数据中有两个数列，只要有一个满足即输出Yes，否则输出No，数列长度 <= 10000

### Solution
> 先讲数列按照每个数的绝对值排序，这时就可以很好的利用STL中可自定义比较函数的特性，排序完后将相邻两数相加，若为0则存在两个数互为相反数

### Code
```cpp
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;

int s[10010];

bool cmp(int a,int b){
	return abs(a) < abs(b);
}

int main(){
	int n,m;
	scanf("%d%d",&n,&m);
	for (int k=1;k<=m;++k){
		int p;
		bool bo = 1;
		cin >> p;
		for (int i=1;i<=p;++i)
			cin >> s[i];
		sort(s+1,s+p+1,cmp);
		for (int i=2;i<=p;++i)
			if (s[i] + s[i-1] == 0){
				bo = 0; 
			}
		if (bo){
			for (int i=k+1;i<=m;++i){
				cin >> p;
				for (int i=1;i<=p;++i)
					cin >> s[i];
			}
			cout << "YES" << endl;
			return 0;
		}
	} 
	cout << "NO" << endl;
	return 0;
}
```
*****


## C
### Problem description
> 一个数列，假设某处有一个物品，使用集合中的数将物品向右移动一定的格数，移到第一个格子的胜，问是必赢还是必输，若无限循环则输出“loop”。（物品数量n <= 7000）

### Solution
> 刚看时以为是一道博弈论题，但因为数据范围比较小，而且因为这题的转移数很少，所以可以考虑使用dp的方法，dp[n][0],dp[n][1]，分别表示到第n个位置是必输还是必败。考虑到这题正着dp难度很大，考虑从结果出发，倒着dp，采用BFS的方式，就可以解决这个问题了

### code
```cpp
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;

bool flag[7010][2],dp[7010][2];
int w[7010][2],cnt[7010][2],n,k[2];

void calc(int x,int num){
	flag[x][num] = 1;
	for (int i=0;i<k[!num];++i){
		int tmp = (x+n-w[i][!num]) % n;
		if (tmp == 0)	continue;
		if (flag[tmp][!num])	continue;
		if (dp[x][num] && ++cnt[tmp][!num] == k[!num])
			calc(tmp,!num);
		else if (!dp[x][num])
			dp[tmp][!num] = 1,
			calc(tmp,!num);
	}
} 

int main(){
	memset(flag,0,sizeof flag);
	memset(dp,0,sizeof dp);
	scanf("%d",&n);
	scanf("%d",&k[0]);
	for (int i=0;i<k[0];++i)
		scanf("%d",&w[i][0]);
	scanf("%d",&k[1]);
	for (int i=0;i<k[1];++i)
		scanf("%d",&w[i][1]);
	calc(0,0);
	calc(0,1);
	for (int i=0;i<=1;++i){
		for (int j=1;j<n;++j)
			if (!flag[j][i])	cout << "Loop ";
			else if (dp[j][i])	cout << "Win ";
			else cout << "Lose ";
		cout << endl;
	}
}
```
*********

#比赛后解决的问题

## D
### Problem description
> 对于一张图，已知三种操作，分别为①将两点相连，边权为val[i]，②将一个点和一个区间内的点相连，边权为val[i]，③将一个区间内的点相连，边权为val[i]，求连完后以s为起点到个点的最小消耗
> 点数 操作数 <= 100000

### Solution
> 因为②③两种操作涉及区间操作，所以不能将区间中每个点都展开，连边所以考虑使用线段树来维护，建两棵线段树，一棵用来记录第②种操作，另一颗用来记录第③中操作,先预先建好单向边长度为0，在添加操作时连接底边和区间的点，连接单向边，长度为边权值。建完图后跑一个dijkstra，可以得出s到各点的距离

### code
```cpp
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <queue>
#include <vector>
#define int long long
const long long Inf = 1400000;
using namespace std;

long long tot = 0,dist[3000010],fst[3000010],nxt[3000010],lst[3000010],des[3000010],dis[3000010],n,u,val;
bool flag[3000010],bo[3000010];

struct xint{
	long long x,y;
}s1[3000010],s2[3000010];

struct cmp{bool operator()(xint &a,xint &b){
	return a.y > b.y;
}};

void addedge(long long a,long long b,long long val){
	if (!fst[a])	fst[a] = ++tot;
	else nxt[lst[a]] = ++ tot;
	lst[a] = tot,des[tot] = b,dis[tot] = val;
	//cout << a << " " << b << " " << val << " ! " << endl;
}

void maketree(long long l,long long r,long long cnt){ 
	s1[cnt].x = l,s1[cnt].y = r;
	s2[cnt].x = l,s2[cnt].y = r;
	if (l == r){
		addedge(cnt+n,l,0),addedge(l,cnt+n,0),addedge(l,cnt+n+Inf,0),addedge(cnt+n+Inf,l,0);
		return ;
	}
	addedge(cnt+n,cnt*2+n,0),addedge(cnt+n,cnt*2+n+1,0),addedge(cnt*2+n+Inf,cnt+n+Inf,0),addedge(cnt*2+1+n+Inf,cnt+n+Inf,0);
	maketree(l,(l+r)/2,cnt*2),maketree((l+r)/2+1,r,cnt*2+1);
}

void calc1(int l,int r,int cnt){
	if (s1[cnt].x == l && s1[cnt].y == r){
		addedge(u,cnt+n,val);
		return ;
	}
	int mid = (s1[cnt].x+s1[cnt].y) / 2;
	if (mid >= r)	calc1(l,r,cnt*2);
	else if (mid < l)	calc1(l,r,cnt*2+1);
	else calc1(l,mid,cnt*2),calc1(mid+1,r,cnt*2+1);
}

void calc2(int l,int r,int cnt){
	if (s2[cnt].x == l && s2[cnt].y == r){
		addedge(cnt+n+Inf,u,val);
		return ;
	}
	int mid = (s2[cnt].x+s2[cnt].y) / 2;
	if (mid >= r)	calc2(l,r,cnt*2);
	else if (mid < l)	calc2(l,r,cnt*2+1);
	else calc2(l,mid,cnt*2),calc2(mid+1,r,cnt*2+1);
}

priority_queue < xint,vector<xint>,cmp > sq;

main(){
	int q,s,k,lx,ry;
	scanf("%lld%lld%lld",&n,&q,&s);
	maketree(1,n,1);
	for (int i=1;i<=q;++i){
		scanf("%lld",&k);
		if (k == 1){
			scanf("%lld%lld%lld",&lx,&ry,&val);
			addedge(lx,ry,val);
		}
		if (k == 2){
			scanf("%lld%lld%lld%lld",&u,&lx,&ry,&val);
			calc1(lx,ry,1);
		}
		if (k == 3){
			scanf("%lld%lld%lld%lld",&u,&lx,&ry,&val);
			calc2(lx,ry,1);
		}
	}
	for (int i=0;i<=3000009;++i)
		dist[i] = 1e15,flag[i] = 1;
	dist[s] = 0;
	sq.push((xint){s,0});
	while (!sq.empty()){
		int t = sq.top().x,temp = fst[t];
		sq.pop();
		if (!flag[t])	continue;
		flag[t] = 0;
		while (temp){
			if (flag[des[temp]] && (dis[temp]+dist[t] < dist[des[temp]])){
				dist[des[temp]] = dis[temp] + dist[t];
				sq.push((xint){des[temp],dist[des[temp]]});
			}
			temp = nxt[temp];
		}
		//cout << t << " " << dist[t] << endl;
	}
	for (int i=1;i<=n;++i)
		if (dist[i] > 1e14)	cout << -1 << " ";
		else cout << dist[i] << " ";
	return 0;
}
```

## E
### Problem description
> 给出一个序列，要求序列中的数不同的个数不超过k，求最小分组数，其中k为1
> 到n，对于每种情况分别输出一个答案，序列长度 <= 100000

### Solution
> 考虑二分的方式，对于l和r，令l<r，如果ans[l]=ans[r]，ans[l,r]答案相同，然后暴力二分求解即可，时间复杂度O(玄学)（看数据）

### code
```cpp
	#include<bits/stdc++.h>
using namespace std;
int s[100007],vis[100007],ans[100007],n;
int get_cnt(int k){
    int res = 0,cnt = 0;
    memset(vis,-1,sizeof vis);
    for (int i=1;i<=n;++i){
        if (vis[s[i]] == res) continue;
        vis[s[i]] = res;
        ++ cnt;
        if (cnt > k){
            ++ res;
            cnt = 1;
            vis[s[i]] = res;
        }
    }
    return res+1;
}

void solve(int l,int r){
    if (l > r) return ;
    int cntl = get_cnt(l),cntr = get_cnt(r);
    if (cntl == cntr){
        for (int i=l;i<=r;++i)
            ans[i] = cntl;
        return ;
    }
    ans[l] = cntl,ans[r] = cntr;
    int mid = (l+r) / 2;
    solve(l+1,mid),solve(mid+1,r-1);
}
int main()
{
    scanf("%d",&n);
    for (int i=1;i<=n;++i)
        scanf("%d",&s[i]);
    solve(1,n);
    for (int i=1;i<=n;++i)
        cout << ans[i] << ' '; 
    return 0;
}
```
