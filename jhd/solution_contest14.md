# 比赛记录

[比赛链接](https://cn.vjudge.net/contest/168561)

## A
### Problem Description
> 有一台电脑，已知它在c秒内不打字的话，之前输入的字符将被清空。给出一个打字的时间序列，求打字完毕后，屏幕上剩余的字符数。

### Solution
根据题意直接模拟即可。

``` cpp
#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
using namespace std;

int t[100001];
int main(){
	int n,c;
	scanf("%d%d",&n,&c);
	int Ans=0;
	for (int i=1;i<=n;i++){
		scanf("%d",&t[i]);
		if (i==1||t[i]-t[i-1]<=c) Ans++;
		else Ans=1;
	}
	printf("%d",Ans);
	
	
}
```

## B
### Problem Description
> 给出一个字符串（大写字母组成），其中有些位置上的字母未知，用“？”表示。将字符串上的“？”用A-Z代替，使得存在一个连续的，长度为26的子串，使得其恰好存在A-Z26个字母。

### Solution
从左向右扫描字符串，维护[i-25..i]范围的出现的字母种类，以及出现的`?`的个数（只需处理边界上的字符，将它们加上或减去即可）。
如果在某个子串中 字母种类数+‘？’的个数 等于（或大于）26，则说明这个子串满足条件，只需要将‘？’依次用未出现过的字母替代即可。

``` cpp
#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
using namespace std;

string s;
int A[128];
int Q,num;
int main(){
	cin>>s;
	bool flag=0;
	int k=0;
	int len=s.length();
	for (int i=0;i<len;i++){
		if (s[i]=='?'){
			Q++;
		}else{
			A[s[i]]++;
			if (A[s[i]]==1) num++;
			
		}
		if (num+Q==26) {
			flag=1;
			k=i;
			break;
		}
		if (i>=25){
			if (s[i-25]=='?') Q--;
			else{
				A[s[i-25]]--;
				if (A[s[i-25]]==0) num--;
			}
		}
	}
	if (flag){
		int tmp='A';
		for (int i=k-25;i<=k;i++){
			while (A[tmp]) tmp++;
			if(s[i]=='?') s[i]=tmp++;
		}
		for (int i=0;i<len;i++){
			if (s[i]=='?') s[i]='A';
		}
		cout<<s;
		return 0;
	}
	cout<<-1;

}
```
***** 
# 赛后补题
## C
### Problem Description
> 有一个计算器，它的初始值为x=2，k=1。
有两种操作，`+`操作可以把x变为x+k，`√`操作可以把x变成√x，同时k++，但前提条件是x为完全平方数，且√x能被（k+1）整除。
> 输入n，给出一种操作方式，使得将k变成n+1，输出每次`√`操作间的`+`操作次数（不得超过10^18）。

### Solution
设当k=k0时的第一次操作（即√操作）时x=x0,则显然k0|x0(k0能整除x0).

因为之后的+操作加的都是k0，所以x始终能被k0整除。

所以当下一次√操作时，x能被k0整除。

又因为此时的√x能被k+1整除，则x也能被k+1整除。

所以x既能被k整除，又能被k+1整除，则它能被k(k+1)整除

因为x为完全平方数，所以x需要被[k(k+1)]^2整除才能保证对任何k成立。

所以最小的x1=k^2\*(k+1)^2

同理可得x0=k(k-1)(x0是开完根号的x值）

则中间的+操作数Ans[k]=(x1-x0)/k=(k^2\*(k+1)^2-k(k-1)/k=k(k+1)^2-(k-1)=k^3+2k^2+1(k>=2).

注意k=1时的特判Ans=2.

``` cpp
#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
using namespace std;

int main(){
	int n;
	scanf("%d",&n);
	cout<<2<<endl;
	for (int i=2;i<=n;i++){
		long long a=1;
		a+=2ll*i*i+1ll*i*i*i;
		cout<<a<<endl;
	}
}
```

## D
### Problem Description
> 有一张无向图，一些边的权值已知（为不超过10^9的正整数），一些边的权值未知（不超过10^18的正整数）。
将未知边的权值补充完整，使得从s点到t点的最短路长度为已知值L。无解输出`NO`、

### Solution
+ 方法1（暴力）

先分别将未知边的权值设为1和无穷（分别为未知边取到的最小和最大值），跑一遍最短路（dijkstra或SPFA），得到的最短路长度为l1,l2.
若l1>L,则无论如何增大未知边，所得最短路一定大于L，则无解。同理，若l2<L,也无解。（事实上我没有判无穷的情况，后面的操作可以将它给否了）
（当然，若等于L则为答案）

(将各未知边权值设为1,)接下来枚举每一条未知边，假设它在最短路上，则只需要将它增加L-l1，即现在的权值为1+L-l1。
再跑一遍最短路，若现在的l1=L,则为答案，反之，说明它不在最短路上（或者还有一条比L短的路径），则继续枚举。

最后若全部枚举完毕也无解，说明本身图上就有一条由已知边构成的最短路小于L，即无解。

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
+ 方法2（巧妙解法）

设未知边权值为1，先反向（从终点到起点）跑一遍最短路。设各点得到的最短长度为dis1[1..n]。

接着正向跑最短路，到各点最短长度为dis2[1..n]，在扩展的同时（假设从a点扩展到b点），若扩展到未知边，跟法1相同，设它在最短路上，
若现在不是长度为L的最短路这时需要增加(L-dis1[b]-dis2[a])才能使它的最短路长度为L，即现在的权值为(1+L-dis1[b]-dis2[a])，
但考虑到它之前已经被更新过，已经被更新成了L长度的最短路，所以最终的权值w=max(w,1+L-dis1[b]-dis2[a]).更新完毕后继续跑最短路。

此时所有经过未知边的l都>=L（否则它将会被更新）。

则这时的最短路l1,若l1=L则为答案，否则若l1>L,则所有路径均大于L，无解；若l1<L,则存在只由已知边构成的路径，长度小于L，同样无解。

## E (not AC yet)
### Problem Description
> 有一棵树，其边权均为1~9的整数，求有多少这样的有序对(u,v),满足从u到v的最短路上的边权**依序**组成的数能被M（与10互质）整除。
### Solution
???(暂无)
