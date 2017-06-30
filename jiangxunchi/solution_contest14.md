# 比赛记录

[比赛链接](https://cn.vjudge.net/contest/168561)
## A
### Problem description
打字，如果打的相邻的两个字的时间差大于c就把前面的字都删掉，求最后剩下多少个字。
### Solution
暴力模拟即可。
```cpp
#include<cstdio>
int main(){
	int n,c,pre=-1e9,ans=0;
	scanf("%d%d",&n,&c);
	for(int i=1;i<=n;++i){
		int x; scanf("%d",&x);
		if(x-pre>c) ans=1; else ++ans;
		pre=x;
	}
	printf("%d",ans); return 0;
}
```
## B
### Problem description
给你一个由大写字母和问号组成的字符串，问号可以变成任意大写字母，求变化后是否可以使原字符串的一个子串中所有大写字母都恰好出现了一遍。
### Solution
枚举所有长为26的子串，每次删掉左端，加入右端，然后如果没有一个字母出现次数大于等于2就可行。
```cpp
Select Code
#include<cstdio>
#include<cstring>
int val[26],err_cnt=0;
void insert(char c){
	if(c=='?') return;
	if(++val[c-'A']==2) ++err_cnt;
}
void erase(char c){
	if(c=='?') return;
	if(--val[c-'A']==1) --err_cnt;
}
int main(){
	char c[500001]; scanf("%s",c+1);
	int l=strlen(c+1); if(l<26){
		printf("-1"); return 0;
	}
	for(int i=1;i<=26;++i) insert(c[i]);
	for(int ll=1,rr=26;rr<=l;++rr){
		if(err_cnt==0){
			int p=0;
			for(int i=1;i<=l;++i) if(c[i]!='?')
				printf("%c",c[i]);
			else if(i<ll||i>rr) printf("A");
			else{
				for(;p<26&&val[p];++p);
				printf("%c",p+'A'); ++p;
			}
			return 0;
		}
		erase(c[ll++]); if(rr<l) insert(c[rr+1]); 
	}
	printf("-1"); return 0;
}
```
## C
### Problem description
有一个数一开始为2，级数一开始为1，每次可以执行2个操作，一个是将这个数加上级数，另一个是如果这个数是完全平方数就开平方并将级数加1。任意时刻这个数必须能被级数整除。求操作方案。
### Solution
数学方法乱搞就行了，最后会推出一个很玄学的结论。
```cpp
#include<cstdio>
int main(){
	int n; scanf("%d",&n);
	printf("2\n");
	for(long long i=1;i<n;++i)
		printf("%lld\n",(i+2)*(i+2)*(i+1)-i);
	return 0;
}
```
***** 
# 赛后补题
## D
### Problem description
给你一副无向图，你可以修改一部分边的权值为一个正整数且使s到t的最短路径长度为L。求一种可行方案。
### Solution
现将可修改的边全部修改为inf跑一遍最短路，如果距离小于L就不可行。再讲所有可修改的边全部修改为1跑一遍最短路，如果距离大于L就不可行。其他情况都可行。求方案的方法是每次跑一遍最短路，把最短路上任意一条可修改的边增加使这条路径的的长度为L。然后一直重复直到跑出来的最短路长度为L。
```cpp
#include<cstdio>
#include<queue>
#include<cstring>
#include<cstdlib>
using namespace std;
const int N=1000,M=10000;
typedef long long ll;
const ll inf=1e15;
struct edge{int to,rev; ll len; bool b;};
vector<edge> G[N+1];
ll dis[N+1]; int pre[N+1][2];
bool counted[N+1][N+1];
int cnt,s,t;
void error(){
	printf("NO"); exit(0);
}
struct oedge{int st,en,stpos,enpos;}a[M+1];
void spfa(){
	bool vis[N+1]; memset(vis,0,sizeof vis);
	memset(pre,-1,sizeof pre);
	memset(dis,0x3f,sizeof dis); dis[s]=0; queue<int> Q;
	for(Q.push(s);!Q.empty();Q.pop()){
		int x=Q.front(); vis[x]=0;
		for(int i=0;i<G[x].size();++i){
			edge e=G[x][i];
			if(dis[x]+e.len<dis[e.to]){
				dis[e.to]=dis[x]+e.len; pre[e.to][0]=x; pre[e.to][1]=i;
				if(!vis[e.to]){
					vis[e.to]=1; Q.push(e.to);
				}
			}
		}
	}
}
int main(){
	int n,m; ll l; scanf("%d%d%lld%d%d",&n,&m,&l,&s,&t); ++s; ++t;
	for(int i=1;i<=m;++i){
		int u,v; ll w; scanf("%d%d%lld",&u,&v,&w); ++u; ++v;
		G[u].push_back({v,G[v].size(),w,w==0});
		G[v].push_back({u,G[u].size()-1,w,w==0});
		if(!w){
			a[++cnt].st=u; a[cnt].en=v;
			a[cnt].stpos=G[u].size()-1; a[cnt].enpos=G[v].size()-1;
		}
	}
	for(int i=1;i<=cnt;++i){
		G[a[i].st][a[i].stpos].len=G[a[i].en][a[i].enpos].len=inf;
	}
	spfa(); if(dis[t]<l) error();
	for(int i=1;i<=cnt;++i)
		G[a[i].st][a[i].stpos].len=G[a[i].en][a[i].enpos].len=1;
	spfa(); if(dis[t]>l) error();
	for(;;){
		spfa();
		if(dis[t]==l){
			printf("YES\n");
			for(int i=1;i<=n;++i) for(int j=0;j<G[i].size();++j){
				edge e=G[i][j];
				if(!counted[i][e.to]){
					printf("%d %d %lld\n",i-1,e.to-1,e.len);
					counted[i][e.to]=counted[e.to][i]=1;
				}
			}
			return 0;
		}
		int v=l-dis[t]; bool b=1;
		for(int i=t;pre[i][0]!=-1;i=pre[i][0])
			if(G[pre[i][0]][pre[i][1]].b){
				G[pre[i][0]][pre[i][1]].len+=v;
				G[i][G[pre[i][0]][pre[i][1]].rev].len+=v;
				b=0; break;
			}
		if(b) error();
	}
	return 0;
}
```
