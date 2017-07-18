# Solution
```
/******************
    VJudge链接：  https://cn.vjudge.net/contest/
CodeForces链接：  http://codeforces.com/contest/

题目按CF顺序排序
******************/
```
# #A Cantonese Dialect
```
/******************
     主要算法：  诡异的模拟
******************/
```
### 题意
给你n，m，N，让你算M，满足n/m=N/M
### 题解
本来很简单，但却莫名诡异，要把N+1带入算式后才对。。。
### 核心代码
```
/******************
 while(scanf("%I64d %I64d %I64d",&n,&m,&N)!=EOF)  
    {  
        M=(N+1)*m/n;
        if(M>N) M=N;
        printf("%I64d\n",M);
    }
******************/
```
### 错题记录
就是N没+1，然后一直WA

***
# #D Chinese Dialects
```
/******************
      主要算法：数论
******************/
```
### 题意
给你几个人会说第几种话，并告诉你人的总数，问你**至少**有多少人会说所有的话
### 题解
一道关于容斥原理的题，但其实只要拿a[1]去和所有别的“合并”，就可以了，合并的意义就是找出同时说前i种语言的人有多少个
### 核心代码
```
/******************

	for(int i=2;i<=k;i++) a[1]=max(0,a[1]+a[i]-n);
	printf("%I64d",a[1]);
******************/
```
### 错题记录
只是刚开始想容斥想到脑残。。。

# 赛后补题

***
# #B  In Chinese Restaurant
```
/******************
    主要算法： 分块思想 ~~DP~~（不存在的）
******************/
```
### 题意
给你一堆关系，表示第i个人想坐在a[i]旁边，求满足他们需求的方案数

### 题解
一眼看去就是DP啊，然后就被坑死了
实际上只要用并查集把他们的关系分成一块一块的，然后每块排列组合一下根据乘法原理乘起来就可以了  
注意一些细节： 1.如果一个人被三个人要求，那就是不可能的
              2.如果有一组出现了环，那么就只能有这一组坐圆桌了，如果还有别的就挂了  

### 核心代码
```
/******************
	for(i=1;i<=m;i++)
	{
		scanf("%d",&tmp);
		if(used[tmp][i]) continue;
		used[tmp][i]=used[i][tmp]=1;
		in[i]+=1; in[tmp]+=1;
		int fx=father(tmp),fy=father(i);
		if(fx!=fy)
		{
			fat[fx]=fy; 
			sz[fy]+=sz[fx]; sz[fx]=0;
			gro--;
		}
		else is_cir=1;
	}
	for(i=1;i<=n;i++) if(in[i]>2) {flag=1; break;}
	if(flag || (is_cir&&gro>1)) {puts("0"); return 0;}
	long long ans=1;
	for(i=1;i<gro;i++) ans=(ans*i)%P;
	for(i=1;i<=n;i++) if(sz[i]>1) ans=(ans<<1)%P;
******************/
```
### 错题记录
刚开始忘了注意点2

***
# #C Kite
```
/******************
      主要算法：数论
******************/
```
### 题意
给你个四边形（不可退化为三角形），让你求它有几个对称轴并*2
### 题解
枚举节点和各边中点，反正就那8条线嘛。。。
利用中垂线的原理判断垂直与相等，都符合则对称轴数++
最后莫忘*2

### 核心代码
```
/******************
double get_dis(pdd a,pdd b) {return sqrt((a.F-b.F)*(a.F-b.F)+(a.S-b.S)*(a.S-b.S));}
bool eq(double a,double b) {return fabs(a-b)<0.000001;}
pdd zd(pdd a,pdd b) {return mp((a.F+b.F)/2,(a.S+b.S)/2);}
bool cz(pdd a,pdd b,pdd c,pdd d)
{  
    if(!eq(a.F,b.F) && !eq(c.F,d.F))  return eq(((a.S-b.S)*(c.S-d.S))/((a.F-b.F)*(c.F-d.F)),-1);  
    if(eq(a.F,b.F)) return eq(c.S,d.S);
    if(eq(c.F,d.F)) return eq(a.S,b.S);
}
	if(cz(a,c,b,d))
	{
		if(eq(get_dis(a,b),get_dis(a,d)) && eq(get_dis(c,b),get_dis(c,d))) ans++;
		if(eq(get_dis(b,a),get_dis(b,c)) && eq(get_dis(d,a),get_dis(d,c))) ans++;
	}
	if(cz(e,g,a,b) && cz(e,g,c,d)) ans++;
	if(cz(f,h,b,c) && cz(f,h,a,d)) ans++;
******************/
```
### 错题记录
刚开始利用~~网上拉下来的~~叉积法判断结果莫名WA，气死了。

***
# #E Pear Trees（****）
```
/******************
      主要算法：变态DP
******************/
```
### 题意
给你一个序列，它只能有两个同性质序列构成，两个序列中任意一个不是上升就是下降  
让你输出这两个子序列的长度及元素

### 题解
一道很训练DP能力的题目，借鉴了老师的视频才想出来  
定义状态: f[i][j] 表示第i个元素放在第j个序列（0 or 1），j^1的序列的最优值
那么便可以很容易的推出方程了（应该不用讲吧，看下面的核心代码就秒懂了）  
顺便记录下路径就可以了  
其中也有很巧妙的异或操作，有效地减少了代码长度
### 核心代码
```
/******************
bool judge(int t1,int t2)
{
	int i,len1=0,len2=0;
	clear();
	f[1][0]= (t2) ? 0 : n+1; f[1][1]= (t1) ? 0 :n+1;
	for(i=2;i<=n;i++) 
	{
        if(f[i-1][0]!=-1) 
		{
            if((a[i]<a[i-1]) ^ t1)  
				{pa[i][0]=0; f[i][0]=f[i-1][0];}
            if((a[i]<f[i-1][0]) ^ t2) 
				{pa[i][1]=0; f[i][1]=a[i-1];}
        }
        if(f[i-1][1]!=-1) 
		{
            if((a[i]<f[i-1][1]) ^ t1) 
                if(f[i][0]==-1 || ((a[i-1]>f[i][0]) ^ t2)) 
					{pa[i][0]=1;f[i][0]=a[i-1];}
            if((a[i]<a[i-1]) ^ t2) 
                if(f[i][1]==-1 || ((f[i-1][1]>f[i][1])^t1)) 
					{pa[i][1]=1;f[i][1]=f[i-1][1];}
        }
    }
    if(f[n][0]!=-1 || f[n][1]!=-1)
    {
		if(f[n][0]!=-1) for(int i=n,pos=0;i>=1;i--) {p[i]=pos; pos=pa[i][pos];}
		else if(f[n][1]!=-1) for(int i=n,pos=1;i>=1;i--) {p[i]=pos; pos=pa[i][pos];}
		for(i=1;i<=n;i++)
			{if(p[i]) path1[++len1]=a[i]; else path2[++len2]=a[i];}
		if(len1==0) {path1[++len1]=path2[len2--];}
		if(len2==0) {path2[++len2]=path1[len1--];}
		printf("%d %d\n",len1,len2);
		for(i=1;i<=len1;i++) printf("%d ",path1[i]); puts("");
		for(i=1;i<=len2;i++) printf("%d ",path2[i]); 
		return true;
	}
	return false;
******************/
```
###错题记录
木有错过
***
# #F 
```
/******************
      主要算法：并查集+几何计算
******************/
```
### 题意
给你若干点和一些以这些点为端点的边，并且如果边相交了那么四个点都可以连在一起。  
求最后是否所有点都连在一起

### 题解
首先考虑边不相交该怎么做：直接用并查集。。  
然后再加上交点的判断，此处可以用叉积法  
**注意如果边经过了点那么那个点也将被联通**

### 核心代码
```
/******************
自己的不知道为什么错 暂时不贴
******************/
```
###错题记录
莫名其妙就错了，估计卡在了精度或者一些神奇的东西上
***
# #G 皇后像廣場
```
/******************
      主要算法：DFS
******************/
```
### 题意
给你9个4*4的正方形，让你拼成一个10*10的正方形，其中每两个有边相邻的小正方形相邻的边要删掉一条  
要注意的是顺序可以随便取并且正方形可以旋转  
若有多组合法的输出一组即可

### 题解
rotate函数预处理出每个正方形旋转后的所有样子
judge判断邻边是否完全一样
dfs就是暴力搜索，不需要任何剪枝  
这道题最锻炼人的就是对mod的操作熟练度
### 核心代码
```
/******************
inline void rotate(int x)
{
	for(int i=0;i<4;i++)
		for(int j=0;j<4;j++)
		{
			map[x+1][j][3-i]=map[x][i][j];
			map[x+2][3-i][3-j]=map[x][i][j];
			map[x+3][3-j][i]=map[x][i][j];
		}
}
inline bool cmp1(int x,int y) //  |
{
	for(int i=0;i<4;i++) if(map[x][i][3]!=map[y][i][0]) return false;
	return true;
}
inline bool cmp2(int x,int y)// --
{
	for(int i=0;i<4;i++) if(map[x][3][i]!=map[y][0][i]) return false;
	return true;
}
bool judge(int p,int x)
{
	if(p%3!=0 && !cmp1(ord[p-1],x)) return false;
	if(p>=3 && !cmp2(ord[p-3],x)) return false;
	return true;
}
void print()
{
	int i,j;
	for(i=0;i<12;i++)
		for(j=0;j<12;j++)
			G[i][j]=map[ord[i/4*3+j/4]][i-i/4*4][j-j/4*4];
	for(i=0;i<12;i++)
	{
		for(j=0;j<12;j++)
			if(i!=4 && i!=8 && j!=4 && j!=8)
				printf("%d ",G[i][j]);
		if(i!=4 && i!=8) printf("\n");
	}
}
void dfs(int step)
{
	if(step==9) {print(); flag=1; return;}
	for(int i=0;i<9;i++)
		if(!used[i])
		{
			for(int j=0;j<4;j++)
				if(judge(step,i*4+j))
				{
					used[i]=1; ord[step]=i*4+j;
					dfs(step+1); if(flag) return;
					used[i]=0; ord[step]=0;
				}
		}
}
******************/
```
###错题记录
各种mod错误。。
***
