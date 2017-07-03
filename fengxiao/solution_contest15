# Solution
```
/******************
    VJudge链接：  https://cn.vjudge.net/contest/168929
CodeForces链接：  http://codeforces.com/contest/787

题目按CF顺序排序
******************/
```
# #A The Monster
```
/******************
     主要算法：  exgcd or baoli
     data limit : 0<a,b,c,d<=100
******************/
```
### 题意
给你a,b,c,d，求是否有x，y使b+ax=d+cy，有则输出等式左边的值，否则输出-1
### 题解
本来这应该是一道exgcd，然而我并不会  
于是开始暴力，找出1~100000所有可能，如果有重复就输出，否则输出-1
### 核心代码
```
/******************
//exgcd的后面补
    while(c!=a and a<100000)  a<c?a+=b:c+=d;
    if(a>=100000) puts("-1");
******************/
```
### 错题记录
刚开始上界开太大T了

***
# #B Not Afraid
```
/******************
    主要算法： 模拟
    Data limit：1 ≤ n, m , k≤ 1e4
******************/
```
### 题意
给你n个人，m个组，判断每个组中是否含有一对相反数，如果任意一组中一个都没有就输出YES，否则输出NO
### 题解
搞个set存一下数字就可以了，注意不能半途break，因为这会导致输入未完成
### 核心代码
```
/******************

	for (i=1;i<=m;i++)
	{
		S.clear();
		int flag=0;
		cin>>k;
		for (j=1;j<=k;j++)
		{
			cin>>tmp;
			S.insert(tmp);
			if (S.find(-tmp)!=S.end()) flag=1;//不能break
		}
		if(!flag){puts("YES"); return 0;}
	}
	puts("NO");
******************/
```
### 错题记录
就是加了个break，调了一个小时。。。

***
# #C Berzerk
```
/******************
      主要算法：博弈论 记忆化搜索
      Data limit：2 ≤ n ≤ 7000
******************/
```
### 题意
给你n个点所组成的圈，第0个点为目标点，  
有两个人AB，他们各自有一个数集合，分别记为S1，S2，可以将物体移动S1中的一个数格，B可以移动S2中一个数格。在最优情况下，谁将物品先推到0谁胜利。
输出有两行，第一行表示A先手，第二行表示B先手  
其中的第i个数字表示当起始点在i时胜利情况  
有
### 题解
一道博弈论的题目，多了个Loop的死循环判断  
思路就是只对绝对胜利/失败的点进行记录，剩下的就是Loop了
### 核心代码
```
/******************

void dfs(int u,int t)
{
	int i,j;
	if (f[u][t]) return;
	f[u][t]=2;
	if(!u) return;
	for(i=1;i<=l[!t];i++) 
	{
		cnt[(u-v[i][!t]+n)%n][!t]++;
		if (cnt[(u-v[i][!t]+n)%n][!t]==l[!t])
	    {
	    	f[(u-v[i][!t]+n)%n][!t]=1;
	    	for(j=1;j<=l[t];j++) dfs( (u-v[i][!t]+n-v[j][t]+n)%n,t );
		}
	}
}

	for(j=0;j<2;j++) 
			for(i=1;i<=l[j];i++) dfs(n-v[i][j],j);

******************/
```
### 错题记录
刚开始在Loop那里绕啊绕，WA啊WA。。。
***
# #D Legacy 
```
/******************
      主要算法：线段树+最短路
      Data limit：1 ≤ n, q ≤ 105, 1 ≤ s ≤ n
******************/
```
### 题意
给你一个图，以及三种类型的边  
1：普通的u->v;
2: u->range[l,r]中任意一点都可以
3.range[l,r]->u
求出s到每个点的最短路
### 题解
看到区间第一反应就是线段树  
建两个线段树，一个区间看作一个点，两棵树叶节点都相同，在其上建边，一棵树父节点可以到子节点，另一颗相反。并且连接两棵树的叶节点  
那么第一棵树中的点用来连接1，2操作，第二棵树连接3操作  
然后再在两棵线段树上跑SPFA，就OK了
为什么要见两棵树：如果只建了第一棵，那么由于没有pushdown操作导致点本来应该有包含它的区间的信息，却无法下传导致无效（用样例2画个图就知道了）  
4 3 1  
3 4 1 3 12  
2 2 3 4 10  
1 2 4 16  
### 核心代码
```
/******************
void build_tre(int u,int l,int r,int t)
{
    s[u]=l; e[u]=r;
    if(s[u]==e[u]) {if(t) key[s[u]]=u; else adde(u,u-K,0),adde(u-K,u,0); return;}
	lc[u]=++cnt; rc[u]=++cnt;
    if(t) adde(u,lc[u],0),adde(u,rc[u],0);  else adde(lc[u],u,0),adde(rc[u],u,0);
    build_tre(lc[u],l,mid,t); build_tre(rc[u],mid+1,r,t);
}
void update(int u,int l,int r,int v,int c,int t)
{
    if(l<=s[u] && e[u]<=r) { t ? adde(v,u,c) : adde(u+K,v,c); return;}
    if(mid>=l) update(left,v,c,t);
    if(mid< r) update(right,v,c,t);
}
void SPFA()
{
    queue<int> que; memset(dis,63,sizeof(dis));
    que.push(key[S]); used[key[S]]=1; dis[key[S]]=0;
    while(!que.empty())
    {
        int p=que.front(); que.pop();
        for(int i=head[p];i;i=nxt[i])
        {
        //printf("?%d?",p);
            if(dis[to[i]]>dis[p]+v[i])
            {
                dis[to[i]]=dis[p]+v[i];
                if(!used[to[i]]) {used[to[i]]=1; que.push(to[i]);}
            }
        }
        used[p]=0;
    }
}
******************/
```
### 错题记录
前几次不信邪只建了一棵线段树。。。然后后面各种错细节。

***
# #E Till I Collapse 
```
/******************
      主要算法：主席树 or 暴力二分
      Data limit：1 ≤ n ≤ 1e5
******************/
```
### 题意
给你一串数字，问你如何分组使每组中不同值的个数少于k并组数最少  
k的取值范围为1~n  
对于每个K输出最小组数  

### 题解
主席树目前还不会  
暴力二分的方法就是二分两端点l，r，如果ans[l]==ans[r]那么说明其中间的组数一定等于它们，所以就可以愉快地赋值了  
事实证明这样做不会T
### 核心代码
```
/******************
int calc(int x)
{
	memset(ha,0,sizeof(ha));
	int cnt=0,sum=1;
	for(int i=1;i<=n;i++)
		if(ha[a[i]]!=sum)
		{
			cnt++; ha[a[i]]=sum;
			if(cnt>x) {sum++,cnt=1;ha[a[i]]=sum;}
		}
	return sum;
}
void bsearch(int l,int r)
{
	if(l>r) return;
	ans[l]=calc(l); ans[r]=calc(r);
	if(ans[l]==ans[r])
	{
		for(int i=l+1;i<r;i++) ans[i]=ans[l];
		return;
	}
	int mid=(l+r)/2;
	bsearch(l+1,mid); bsearch(mid+1,r-1);
}
******************/
```
###错题记录
抱歉没错过
***
