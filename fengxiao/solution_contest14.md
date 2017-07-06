# Solution of contest 14
GG的一场
```
/******************
    VJudge链接：  https://cn.vjudge.net/contest/
CodeForces链接：  http://codeforces.com/contest/

题目按CF顺序排序
******************/
```
# #A Crazy Computer
```
/******************
     主要算法：模拟
******************/
```
### 题意
给你一串数字，如果两数字之间间隔超过c，那么答案清零，否则答案累加

### 题解
预处理tmp数组表示两数字之差，然后根据题意扫一遍便可。
小优化： 从后往前扫，遇到一个不符合的就break
### 核心代码
```
/******************
	for(i=1;i<=n;i++) {scanf("%d",&a[i]); tmp[i]=a[i]-a[i-1];}
	for(i=1;i<=n;i++)
	{
		if(tmp[i]>c) cnt=1;
		else cnt++;
	}
******************/
```
### 错误记录
虽然没在评测时WA，但看错了题，浪费了刚开始的宝贵时间，出师不利

***
# #B Complete the Word
```
/******************
    主要算法： 字符串模拟
******************/
```
### 题意
给你一个字符串，要求存在连续的26个字符使每个字母都出现1次，其中'?'可替代任何字符

### 题解
枚举起点采用队列从前向后扫，cnt数组统计数量，flag数组表示是否满足要求（我肯定做烦了）。然后输出要输出全串。。。
### 核心代码
```
/******************
while(t<ls-1)//丑到爆炸QAQ
	{//printf("%d ",t);
		cnt[a[h++]]--;
		if(cnt[a[h-1]]==1) flag[a[h-1]]=1; else flag[a[h-1]]=0;
		cnt[a[++t]]++;
		if(cnt[a[t]]==1) flag[a[t]]=1; else flag[a[t]]=0;
		count=0;
		//printf("%d %d\n",cnt[0], flag[0]);
		for(i=0;i<26;i++)
			if(flag[i]) count++;
		if(count+cnt[28]==26) {print();return 0;}
	}
******************/
```
### 错误记录
首先cnt和flag傻傻分不清，然后刚开始偷懒把‘？’-‘A’与字符同等处理，结果发现这玩意是-2，后来到处加if，莫名WA，然后改数字数组存，终于A了。。。

***
# 赛后补题
~QAQ这次考好差啊，各种智障错误~

# #C Plus and Square Root
```
/******************
      主要算法：数论
******************/
```
### 题意
给定+和sqrt操作 ，以及初始数m=2，初始level 1   
+：任何时候都可以用，无限制，可以使m+=level
sqrt：只有当m是完全平方数且平方根能被level+1整除才能使用，使用后m变为其平方根，level++  
给你个n，让你输出使level到n+1的步数（每次sqrt（）之前使用多少次+）  
### 题解
纯粹的数学题，考试的时候看错题，以为+操作也有限制。。  
首先策略是一可以sqrt就做  
分析sqrt操作~~其实我是一个个列下去的~~，可知只有当能被level方与level+1整除时才可以sqrt  
那么由于level 与 level+1 互质，于是算式就出来了：  
ans=(i+1)*(i+1)*i-(i-1)[这是原来剩下的]  
于是为了美观略微化成了如下代码
### 核心代码
```
/******************
	printf("2\n");
	for(long long i=1;i<n;++i)
		printf("%I64d\n",(i+2)*(i+2)*(i+1)-i);
******************/
```
### 错误记录
虽然也没有WA，但读题读错太伤了，以为每次+操作也要被整除。。。虽然其实分析一下这就算有也没什么关系，但当时被吓到了，pass了一道水题


***
# #D Complete The Graph
```
/******************
      主要算法：最短路
******************/
```
### 题意
给你一个图，其中有定值边和可修改边，让你更改可修改边（权值只能大于0），使s->t的最短路长度刚好为L  
### 题解
方法有多种：   
1.最暴力的  
先两遍Dij，第一次把可变边赋为INF，若dis[t]<L则无解（管你可变边是什么，关它何事），dis[t]==L 输出  
第二次将可变边赋为1，如果dis[t]>l 则无解，等于就输出  
于是就保证解一定存在了，然后就疯狂地Dij，每次搜最短路，将路径上的可变边任意挑一条增加L-dis[t]，如果diis[t]等于L了就输出  
但我不知道为什么WA在了第13个点，至今未调好
2.巧妙的方法  
只需两遍最短路（由于数据关系，Dij跑得比较快，但SPFA打习惯了）  
第一遍以t为起点，记录dis
第二遍以s为起点，记录dis，如果发现更新时用到可变边，那么将可变边赋值为L-dis[from t to y]-dis[from s to x] (xy为可变边两端点)，  
      这样便可以保证只要经过这条边那么长度就一定大于等于L（想想就知道了，最短路==L嘛）  
然后对答案的判断，如果s->t的最短路不等于L，那么输出NO （如果小于的话那么就是暴力的第一遍情况，大于则是暴力第二遍情况），如果等于就输出啦
    
### 核心代码
```
/******************
void spfa(int s,int type)
{
	int i,h=0,t=1;
	for(i=0;i<n;i++) dis[i][type]=INF; dis[s][type]=0; que[1]=s;
	while(h<=t)
	{
		used[que[++h]]=0;
		for(i=head[que[h]] ; i ; i=nxt[i])
		{
			if(type && flag[i]) v[i]=v[i^1]=max(v[i],L-dis[to[i]][0]-dis[que[h]][1]);
			if(dis[to[i]][type]>dis[que[h]][type]+v[i])
			{
				dis[to[i]][type]=dis[que[h]][type]+v[i];
				if(!used[to[i]]) que[++t]=to[i],used[to[i]]=1;
			}
		}
	}
}
******************/
```
### 错误记录
没看题解前的思路是两遍SPFA，刚开始可包含权值为0的边，后面一次不行，取其差值进行赋值，结果发现可能原来一条非最短路变成了最短路。。。  
然后开始暴力做法，改了N次莫名WA在13个点，至今不明，然后高级做法倒是对了  

***
# #E Digit Tree
```
/******************
      主要算法：树分治（点分治）
******************/
```
### 题意
变量意义：n个点，P为模数，边权小于10  
给你一颗有边权的树，问有多少个点对满足i->j之间的路径之间的由边权组成的数字（每个边权占一位）能被P整除  
### 题解
正解为树分治（点分治）。先找到重心u，处理出属于u的不同子树的所有点对并计算，然后递归处理。  
同时注意细节： 记i->u的距离为d1,u->j距离为d2，则要求满足(d1*10^dep+d2)%P=0 -> d1=d2/10^dep  用逆元处理  
### 核心代码
```
/******************

inline void exgcd(int a,int b,int &x,int &y){if(b==0) x=1,y=0 ; else exgcd(b,a%b,y,x),y-=a/b*x; return;}
void get_sz(int u,int from)
{
	sz[u]=1;
	for(int i=head[u];i;i=nxt[i]) if(to[i]&&to[i]!=from) {get_sz(to[i],u); sz[u]+=sz[to[i]];}
}
void get_root(int u,int from,int siz)
{
	int maxn=siz-sz[u];
	for(int i=head[u];i;i=nxt[i]) if(to[i]&&to[i]!=from) {get_root(to[i],u,siz); maxn=max(maxn,sz[to[i]]);}
	if(maxn<Maxn) {Maxn=maxn;root=u;}
}
void get_d1(int u,int from,int num,int tim)
{
	key[num]++;
	for(int i=head[u];i;i=nxt[i])
		if(to[i]&&to[i]!=from)
			get_d1(to[i],u,(v[i]*tim+num)%P,tim*10%P);
}
int get_d2(int u,int from,int num,int dep)
{
	int sum=key[(-num*inv[dep]%P+P)%P];//逆元
	for(int i=head[u];i;i=nxt[i]) 
		if(to[i]&&to[i]!=from) 
			sum+=get_d2(to[i],u,(num*10+v[i])%P,dep+1);
	return sum;
}
int calc(int x,int v)
{
	key.clear();
	get_d1(x,0,v%P,v?10:1);
	return get_d2(x,0,v%P,v?2:1)-(v==0);
}
void dfs(int u)
{
	get_sz(u,0); Maxn=1e9;
	get_root(u,0,sz[u]);
	ans+=calc(root,0);
	for(int i=head[root];i;i=nxt[i]) 
		if(to[i]) 
		{
			to[i^1]=0;
			ans-=calc(to[i],v[i]);
			dfs(to[i]);
		}
}
	exgcd(10,P,iv,tmp);
	inv[1]=1;
	for(i=2;i<=n;i++) inv[i]=(inv[i-1]*iv)%P;
******************/
```
### 错题记录
如果这玩意错了我就不想调了。。
***
