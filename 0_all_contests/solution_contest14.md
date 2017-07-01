# Solution of Contest14
[VJudge链接](https://cn.vjudge.net/contest/168561)\
[CodeForces链接](http://codeforces.com/contest/716)
## #A Crazy Computer
### Description & Solution
给出一串数，按顺序处理每个数，用计数器累计个数，当两个数之间的间隔大于一个给定的数c时，计数器清零。求最后计数器记录的个数。
### Code
```Cpp
ans=0;
lst=0;
scanf("%d%d",&n,&c);
for(int i=1,j;i<=n;i++) {
    scanf("%d",&j);
    if(j-lst>c) ans=0;
    ans+=1;
    lst=j;
}
printf("%d\n",ans);
```
***
## #B Complete the Word
### Description
输入一个缺失部分信息的字符串，仅由大写英文字母和代表缺失的`?`号构成，要求填满其中的缺失部分，使其存在一个长度26位的连续子串，其中26个字母刚好各出现一次。
### Solution
字串长度在50000以内，大可以暴力修改。
### Code
```Cpp
void check(int x) { //判断字串中从第x位开始的子串是否满足要求
    int f[30];
    for(int i=0;i<=30;i++) f[i]=0;
    for(int i=x;i<=x+25;i++) {
        if(s[i]!='?') {
            f[s[i]-'A']++;
            if(f[s[i]-'A']>1) return;
        }
    }
    int j=0;
    for(int i=x;i<=x+25;i++) {
        if(s[i]=='?') {
            while(f[j]>0) j++;
            s[i]=(char)(j+'A');
            f[j]++;
        }
    }
    print(); //输出
}
```
***
## #C Plus and Square Root
### Description
一个等级制的小游戏，初始等级为1，有一个初始值为2的数字K。现在有两种操作，一是给数字K加上当前等级数；二是给数字K开方，并使等级上升一级。但操作二有两个要求，一个是当前的K是一个完全平方数，另一个是平方之后得到的数必须是下一等级数的倍数。现在给出一个等级数N，求使其达到N+1级的操作方法。只需输出每个等级中在对K开方之前做加法的次数。
### Solution
一道典型的数论题（结论题），理清楚题意后可以得到两个关系 ```①a[i]+ans[i]*i = a[i+1]^2 ②a[i] mod i = 0```
因为第i个答案为ans[i],因此将第一个式子变形为 ```ans[i] = (a[i+1]^2 - a[i]) / i```
这个式子说明只要能满足```a[i] mod i = 0```和```a[i+1]^2 mod i = 0```的数列a[i]都能用来构造答案数列，我们可以令```a[i] = i * (i-1)```
因此答案```ans[i] = (i+1)^2*i-i+1```, 同时要注意按照这种方式构造的数列ans[1]并不满足，因此特判后进行计算即可
### Code
```Cpp
cout << 2 << endl;
for (long long i=2;i<=n;++i){
  cout << i*(i+1)*(i+1) - i + 1 << endl; 
}
```
***
## #D Complete The Graph
### Description
给出一个无向图，其中一些边的权值被擦除了（初始值为0）。再给出起点S和终点T，要求给所有的被擦除的边赋上大于0的权值，使得S到T的最短路总权值恰好为L。
### Solution
#### ● 方法1（暴力）

先分别将未知边的权值设为1和无穷（分别为未知边取到的最小和最大值），跑一遍最短路（dijkstra或SPFA），得到的最短路长度为l1,l2.
若l1>L,则无论如何增大未知边，所得最短路一定大于L，则无解。同理，若l2<L,也无解。（事实上我没有判无穷的情况，后面的操作可以将它给否了）
（当然，若等于L则为答案）

(将各未知边权值设为1,)接下来枚举每一条未知边，假设它在最短路上，则只需要将它增加L-l1，即现在的权值为1+L-l1。
再跑一遍最短路，若现在的l1=L,则为答案，反之，说明它不在最短路上（或者还有一条比L短的路径），则继续枚举。

最后若全部枚举完毕也无解，说明本身图上就有一条由已知边构成的最短路小于L，即无解。
#### ● 方法2（巧妙解法）

设未知边权值为1，先反向（从终点到起点）跑一遍最短路。设各点得到的最短长度为dis1[1..n]。

接着正向跑最短路，到各点最短长度为dis2[1..n]，在扩展的同时（假设从a点扩展到b点），若扩展到未知边，跟法1相同，设它在最短路上，
若现在不是长度为L的最短路这时需要增加(L-dis1[b]-dis2[a])才能使它的最短路长度为L，即现在的权值为(1+L-dis1[b]-dis2[a])，
但考虑到它之前已经被更新过，已经被更新成了L长度的最短路，所以最终的权值w=max(w,1+L-dis1[b]-dis2[a]).更新完毕后继续跑最短路。

此时所有经过未知边的l都>=L（否则它将会被更新）。

则这时的最短路l1,若l1=L则为答案，否则若l1>L,则所有路径均大于L，无解；若l1<L,则存在只由已知边构成的路径，长度小于L，同样无解。

``` cpp
#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <queue>
#define Clear(s) memset(s,0,sizeof s)
using namespace std;
const int inf=1e9+7;

struct node{
	int E,v,next;
}map[20001];
int head[1001],tail;
bool empty[20001];
void ins(int u,int v,int w){
	map[++tail].E=v;map[tail].v=w?w:1;map[tail].next=head[u];head[u]=tail;
	empty[tail]=!w;
}
int n,m,L,s,t;
int dis[1001];
bool visit[1001];
void min_path(){
	queue <int> Q;
	Q.push(s);
	Clear(visit);
	for (int i=0;i<n;i++) dis[i]=inf;
	dis[s]=0;
	while (!Q.empty()){
		int t=Q.front();Q.pop();
		visit[t]=0;
		for (int i=head[t];i;i=map[i].next){
			int e=map[i].E;
			if (dis[t]+map[i].v<dis[e]){
				dis[e]=dis[t]+map[i].v;
				if (!visit[e]){
					Q.push(e);
					visit[e]=1;
				}
			}
		}
	}	
}
int main(){
	scanf("%d%d%d%d%d",&n,&m,&L,&s,&t);
	for (int i=1;i<=m;i++){
		int u,v,w;
		scanf("%d%d%d",&u,&v,&w);
		ins(u,v,w);
		ins(v,u,w);
	}
	min_path();
	if (dis[t]>L) {
		printf("NO");return 0;
	}
	bool flag=(dis[t]==L?1:0);
	for (int i=1;i<=tail&&!flag;i+=2){
		if (!empty[i]) continue;
		map[i].v=map[i+1].v=map[i].v+L-dis[t];
		min_path();
		if (dis[t]==L){
			flag=1;break;
		}
	}
	if (!flag) {
		printf("NO");return 0;
	}
	printf("YES\n");
	for (int i=1;i<=tail;i+=2){
		printf("%d %d %d\n",map[i+1].E,map[i].E,map[i].v);
	}	
}
```

***
## #E Digit Tree
