# Solution of zhuanti of SegTree
普通线段树： 一般包含区间修改，区间查询，单点修改，单点查询，实现较为简单  
区间合并线段树：记录所需区间的左右端点，在适当时进行update，注意区间与区间之间的联系  
线段树求矩形交（or各种交）：扫描线法：见http://blog.csdn.net/lwt36/article/details/48908031     
动态开点线段树：多两个数组lc和rc，在需要调用这个区间时申请空间（cnt++）并建立父子关系，极(tou)其(lan)节(bu)省(li)空(san)间(hua)。
```
/******************
    VJudge链接：  https://cn.vjudge.net/contest/167923
题目按CF顺序排序
******************/
```
# #A 敌兵布阵
```
/******************
     主要算法：  
******************/
```
### 题意
一道平常的线段树模板 包含区间修改和查询（sum）
### 题解
普通线段树

### 核心代码
```
/******************
。。。
******************/
```
### 错题记录
抱歉没错过

***
# #B I Hate It
```
/******************
    主要算法： 
******************/
```
### 题意
一道普通的区间最值题目，支持单点修改和区间查询最大值  
attention：修改：如果**编号**为A的同学成绩**低于数字**B，那么把A的成绩改为B  

### 题解
普通的维护，建议读入不要一个个字符读（会出人命的啊）
### 核心代码
```
/******************
。。。
******************/
```
### 错题记录
首先读错题目WA了一两次，然后没看到多组数据又WA了一两次，然后读入问题又WA了一次。。。悲剧啊~~是不是所有的错误都被我过了一遍~~
***
# #C A Simple Problem with Integers
```
/******************
      主要算法：
******************/
```
### 题意
让你维护一个支持区间查询和修改的线段树（sum）
### 题解
搞个线段树呗
### 核心代码
```
/******************
。。。
******************/
```
### 错题记录
抱歉没错过

***
# #D 	Mayor's posters
```
/******************
      主要算法：
******************/
```
### 题意
给你两个指令，1.将区间x，y之间的值都修改为C  2（只会在最后执行一次）.线段树上颜色的数量
### 题解
更新采取普通的方法，查询时遇到纯色就用used判断，如果没记录过就ans++，标记录，否则跳过，遇到杂色就继续向下
### 核心代码
```
/******************
{（这是比较低级的方法，直接打到叶节点记录，题解中的方法将在下一题使用）
	if(lc[u]==rc[u] && lc[u]==0) {if(!used[v[u]]) {used[v[u]]=1; ans++;} return;}
	pd(u);
	int mid=(l+r)/2;
	if(lc[u]!=0) query(lc[u],l,mid);
	if(rc[u]!=0) query(rc[u],mid+1,r);
}
******************/
```
### 错题记录
抱歉没错过

***
# #E Just a Hook
```
/******************
      主要算法：
******************/
```
### 题意
维护线段树，区间查询+区间修改。有三种值，初始为1，指令可修改区间内的值。  
将在最后查询整个线段树的价值（每个值有其价值）

### 题解
跟上一题几乎一样，不再赘述

### 核心代码
```
/******************
void query(int u)
{
	if(v[u]!=0) {ans+=v[u]*sz; return;}
	pd(u);
	query(u<<1); query(u<<1|1);
}
******************/
```
###错题记录
抱歉没错过

***
# #F Count the Colors
```
/******************
      主要算法：
******************/
```
### 题意


### 题解

### 核心代码
```
/******************

******************/
```
###错题记录


***
# #G Balanced Lineup
```
/******************
      主要算法：
******************/
```
### 题意
让你维护一个线段树，具有区间查询最大值和最小值的功能

### 题解
几乎模板题
### 核心代码
```
/******************
。。。
******************/
```
###错题记录
抱歉没错过

***
# #H Can you answer these queries?
```
/******************
      主要算法：
******************/
```
### 题意
维护一个线段树，具有区间修改（将区间内每个数开方），区间查询的功能

### 题解
其实就跟普通的线段树一样，加个根号处理。但必须加个优化：如果一个数（区间）被开方7次，根据数据最大值，一定变为了1，那么就不用再做它了。
### 核心代码
```
/******************
+void update(int pos,int l,int r)
 +{
 	if(cnt[pos]>=7) return;
 	if(l<=tre[pos].s && tre[pos].e<=r) cnt[pos]++;
     if(tre[pos].s==tre[pos].e) {tre[pos].sum=sqrt(tre[pos].sum); return;}
     int mid=(tre[pos].s+tre[pos].e)/2;
     if(l<=mid) update(pos*2  ,l,r); 
     if(r> mid) update(pos*2+1,l,r);
     tre[pos].sum=tre[pos*2].sum+tre[pos*2+1].sum;
     if(cnt[pos*2]>=7 && cnt[pos*2+1]>=7) cnt[pos]=7;
 }
******************/
```
###错题记录
一道恶心的题，我加了那个优化发现依旧T，结果发现时多组数据输入后没加！=EOF。。。长知识了

***
# #I Tunnel Warfare
```
/******************
      主要算法：区间合并线段树+栈
******************/
```
### 题意
给你三个指令：1：D x 摧毁x节点  
             2：Q x 查询x节点所在连贯区间的长度（被炸了就不连贯了）
             3.R 恢复醉后一个被炸的点

### 题解
区间合并线段树，维护ll和lr表示该区间连贯的1的左右端点。然后R用栈处理
### 核心代码
```
/******************
。。。
******************/
```
###错题记录
虽然没错但很不熟练，程序也借鉴了部分题解

***
# #J Assign the task
```
/******************
      主要算法：树状线段树
******************/
```
### 题意
给你颗数，给指令可修改x节点及其子树的数字，单点查询某点的值（初始为-1）.

### 题解
先按DFS序把二维的树压成一维的线段树，l,r记录每颗树所对的开始和结束节点，然后就可以开（fan）心（ren）的线段树了
### 核心代码
```
/******************
void dfs(int u,int from)//建线段树
{
	l[u]=++cnt;
	for(int i=head[u]; i ; i=nxt[i]) if(to[i]!=from) dfs(to[i],u);
	r[u]=cnt;
}
******************/
```
###错题记录
抱歉没错过

***
# #K Transformation
```
/******************
      主要算法：“裸的”线段树
******************/
```
### 题意
~~嗯这的确是裸的线段树，我还没来的及高兴就快哭了~~  
让你维护区间+ *和修改，查询区间所有点的1/2/3次方和

### 题解
一道简（e）单（xin）的模（shen）板（jing）线段树，其它的实现方法都没有变，主要的精华都集中在了calc中，它能完美解决那一坨东西。。。
### 核心代码
```
/******************
void calc(int u,int tim,int add)
{  
    int len=tre[u].e-tre[u].s+1;  
    tre[u].sum[1]=tre[u].sum[1]*tim%P;
    tre[u].sum[2]=tre[u].sum[2]*tim%P*tim%P;
    tre[u].sum[3]=tre[u].sum[3]*tim%P*tim%P*tim%P;
    tre[u].tim=(tre[u].tim*tim)%P;
    tre[u].add=((tre[u].add*tim)% P+add)%P;
      
    tre[u].sum[3]=(tre[u].sum[3] + 3*add%P*add%P *tre[u].sum[1]%P)%P;  
    tre[u].sum[3]=(tre[u].sum[3] + 3*add%P*tre[u].sum[2]%P)%P ;  
    tre[u].sum[3]=(tre[u].sum[3] + len * add%P *add %P *add%P)%P;  
      
    tre[u].sum[2]=(tre[u].sum[2] + 2*add%P *tre[u].sum[1] %P )%P;  
    tre[u].sum[2]=(tre[u].sum[2] + len*add%P*add%P)%P;  
  
    tre[u].sum[1]=(tre[u].sum[1]+len*add%P)%P;
}  
******************/
```
###错题记录
这种题错一次就会崩溃的。。。

***
# #L Vases and Flowers
```
/******************
      主要算法：一道我也不知道是什么的线段树
******************/
```
### 题意
这是一道神奇的题目  
题目背景是插花之类的。
有两个指令： 1： 从i盆花开始插，如果有插过的就跳过，一直到最后。如果一支都插不进去就输出一个句子，否则输出插花的区间（从插第一朵到插完能插的最后一朵）  
            2： clear掉区间中的所有花并输出clear掉的数量
            
### 题解
反正我就按题意做呗，，讲起来很繁琐，代码比较简单
### 核心代码
```
/******************
void update(int u)//l，r都是全局变量，因为设为函数变量会引发故障，导致一些在某一层修改的东西回到上一层就不见了
{  
	if(C<=0) return;
    if(l<=s[u]&&e[u]<=r && (sum[u]==sz || sum[u]==0))
	{
		if(sum[u]==sz) { r+=sz; if(r>n) r=n+1;}//如果此区间满了就跳过，别忘了更新r
		else 
		{
			sum[u]=sz; C-=sz;
			if(L<0) L=s[u];//第一次插就记录
			R=e[u];//扩大区间
		}
		return;
	}  
    if(!sum[u] || sum[u]==sz) pd(u);
    if(mid>=l) update(lc);
    if(mid< r) update(rc);
    pu(u);
}

******************/
```
###错题记录
一次白痴的输出错误而已。。。

***
# #M 约会安排
```
/******************
      主要算法：区间合并线段树（恶心）
******************/
```
### 题意
给你区间总长度，操作数，有如下操作  
1：DS x -> 从区间按从前往后的顺序选择一段至少长为x的空区间，标记并输出开始位置  
2：NS x -> 跟上一个一样，但如果没有空区间的话可以占掉DS的区间  
3：study l r -> 吧[l,r]变为空区间并输出一句话  
对于每个操作输出其要求的句子  
### 题解
本来区间合并线段树已经够恶心的了，这还搞两个区间。。。  
维护DS区间和NS区间，NS在DS区间中找位置，如果没找到就在NS区间中找位置，并映射下去（说说容易写起来TMD）  
记录区间中最大的可用区间，然后比较，如果有更新就push up上去。
### 核心代码
```
/******************
void pu(int u)
{
    if(tre[u].s==tre[u].e)return;
    tre[u].Lmax=tre[lc].Lmax;
    if(tre[lc].Lmax==tre[lc].e-tre[lc].s+1)tre[u].Lmax+=tre[rc].Lmax;
    tre[u].Rmax=tre[rc].Rmax;
    if(tre[rc].Rmax==tre[rc].e-tre[rc].s+1)tre[u].Rmax+=tre[lc].Rmax;
    tre[u].Max=max(tre[lc].Max,tre[rc].Max);
    tre[u].Max=max(tre[u].Max,max(tre[u].Lmax,tre[u].Rmax));
    tre[u].Max=max(tre[u].Max,tre[lc].Rmax+tre[rc].Lmax);

    tre[u].Lmax1=tre[lc].Lmax1;
    if(tre[lc].Lmax1==tre[lc].e-tre[lc].s+1)tre[u].Lmax1+=tre[rc].Lmax1;
    tre[u].Rmax1=tre[rc].Rmax1;
    if(tre[rc].Rmax1==tre[rc].e-tre[rc].s+1)tre[u].Rmax1+=tre[lc].Rmax1;
    tre[u].Max1=max(tre[lc].Max1,tre[rc].Max1);
    tre[u].Max1=max(tre[u].Max1,max(tre[u].Lmax1,tre[u].Rmax1));
    tre[u].Max1=max(tre[u].Max1,tre[lc].Rmax1+tre[rc].Lmax1);
}
void pd(int u)
{
    if(tre[u].s==tre[u].e)return;
	if(tre[u].Max==0)
        tre[lc].Max=tre[lc].Lmax=tre[lc].Rmax=0,
        tre[rc].Max=tre[rc].Lmax=tre[rc].Rmax=0;
    if(tre[u].Max==tre[u].e-tre[u].s+1)
        tre[lc].Max=tre[lc].Lmax=tre[lc].Rmax=tre[lc].e-tre[lc].s+1,
        tre[rc].Max=tre[rc].Lmax=tre[rc].Rmax=tre[rc].e-tre[rc].s+1;
    if(tre[u].Max1==0)
        tre[lc].Max1=tre[lc].Lmax1=tre[lc].Rmax1=0,
        tre[rc].Max1=tre[rc].Lmax1=tre[rc].Rmax1=0;
    if(tre[u].Max1==tre[u].e-tre[u].s+1)
        tre[lc].Max1=tre[lc].Lmax1=tre[lc].Rmax1=tre[lc].e-tre[lc].s+1,
        tre[rc].Max1=tre[rc].Lmax1=tre[rc].Rmax1=tre[rc].e-tre[rc].s+1;
}
void build_tre(int u,int l,int r)
{
    tre[u].s=l; tre[u].e=r;
    tre[u].Max=tre[u].Lmax=tre[u].Rmax=r-l+1;
    tre[u].Max1=tre[u].Lmax1=tre[u].Rmax1=r-l+1;
    if(l==r)return;
    int mi=(l+r)/2;
    build_tre(lc,l,mi); build_tre(rc,mi+1,r);
}
int query(int u,int x)
{
    if(tre[u].Max<x)return 0;
    if(tre[u].Lmax>=x)return tre[u].s;
    if(tre[lc].Max>=x)return query(lc,x);
    if(tre[lc].Rmax+tre[rc].Lmax>=x)return tre[lc].e-tre[lc].Rmax+1;
    return query(rc,x);
}
int query1(int u,int x)
{
    if(tre[u].Max1<x)return 0;
    if(tre[u].Lmax1>=x)return tre[u].s;
    if(tre[lc].Max1>=x)return query1(lc,x);
    if(tre[lc].Rmax1+tre[rc].Lmax1>=x)return tre[lc].e-tre[lc].Rmax1+1;
    return query1(rc,x);
}
void update(int u,int l,int r)
{
    if(l<=tre[u].s && tre[u].e<=r)
    {
        tre[u].Max=tre[u].Lmax=tre[u].Rmax=tre[u].e-tre[u].s+1;
        tre[u].Max1=tre[u].Lmax1=tre[u].Rmax1=tre[u].e-tre[u].s+1;
        return;
    }
    pd(u);
    if(l<=mid)update(lc,l,r);
    if(r> mid) update(rc,l,r);
    pu(u);
}
void change_DS(int u,int l,int r)
{
    if(l<=tre[u].s && tre[u].e<=r) {tre[u].Max=tre[u].Lmax=tre[u].Rmax=0; return;}
    pd(u);
    if(l<=mid) change_DS(lc,l,r);
    if(r> mid) change_DS(rc,l,r);
    pu(u);
}
void change_NS(int u,int l,int r)
{
    if(l<=tre[u].s && tre[u].e<=r)
    {
        tre[u].Max=tre[u].Lmax=tre[u].Rmax=0;
        tre[u].Max1=tre[u].Lmax1=tre[u].Rmax1=0;
        return;
    }
    pd(u);
    if(l<=mid) change_NS(lc,l,r);
    if(r> mid) change_NS(rc,l,r);
    pu(u);
}
******************/
```
###错题记录
WA了一次，然后到处乱调乱改突然就A了。。。
***
# #N Picture
```
/******************
      主要算法：暴力水
******************/
```
### 题意
给你一坨会黏在一起的矩形，求他们黏在一起后的周长

### 题解
本来这玩意是比较难的矩形周长交线段树，然而就被水过去了。

### 核心代码
```
/******************
 for(i=1;i<=2*n;i++)//猥琐的方法
    {
        if(h[i].flag) for(j=h[i].y1;j<h[i].y2;j++) {if(!X[j+A]) ans++; X[j+A]++;}
        else          for(j=h[i].y1;j<h[i].y2;j++) {X[j+A]--; if(!X[j+A]) ans++;}
        if(z[i].flag) for(j=z[i].y1;j<z[i].y2;j++) {if(!Y[j+A]) ans++; Y[j+A]++;}
        else          for(j=z[i].y1;j<z[i].y2;j++) {Y[j+A]--; if(!Y[j+A]) ans++;}
    }
******************/
```
###错题记录

***
# #O 覆盖的面积
```
/******************
      主要算法：线段树矩形面积交 + 离散化
******************/
```
### 题意
给你一坨矩形，求他们粘在一起后重叠的面积

### 题解
这次不能水了，只能老老实实线段树了。  
采用扫描线法从下往上扫就可以了  
attention： 1.记得在原来的基础上成功的条件是cov[u]>1.   
            2: 要把标记推到底要不然会有故障（虽然比较浪费）。

### 核心代码
```
/******************
void update(int u,int l,int r,int v)
{
	if(s[u]==e[u]) {cov[u]+=v; pu(u); return;}//推到底
	if(mid>=l) update(left,v);
	if(mid< r) update(right,v);
	pu(u);
}
******************/
```
###错题记录
抱歉没错过

***
# #P Atlantis
```
/******************
      主要算法：还是矩形面积交
******************/
```
### 题意
给你一坨矩形，求他们粘在一起后的总面积

### 题解
这题感觉还没上题难，只要普通的扫描线就可以了，不用推到底了
### 核心代码
```
/******************
void pu(int u)
 {
 	if(cov[u]) sum[u]=key[e[u]+1]-key[s[u]];// printf("%lf %d %d\n",sum[u],e[u]+1,s[u]);}
 	else if(s[u]==e[u]) sum[u]=0;
 	else sum[u]=sum[lc]+sum[rc];
 }
void update(int u,int l,int r,int v)
 {
 	if(l<=s[u] && e[u]<=r) {cov[u]+=v; pu(u); return;}
 	if(mid>=l) update(left,v);
 	if(mid< r) update(right,v);
 	pu(u);
 }
******************/
```
###错题记录
额不小心输出格式没看清楚

***
# #Q Get The Treasury
```
/******************
      主要算法：立方体体积交
******************/
```
### 题意
给你若干个立方体，求它们的体积交（要重叠三次及以上才记入答案）
数据范围：T<=30 N<=1000 -1e6<=x,y<=1e6 -500<=z<=500
### 题解
极其暴力的做法，由于z比较小，所以把三维的直接解成若干2维平面，再算面积交并相加  
（然而我这么做大概交了30几次还是没有调出来所以粘了个题解。。。  
以后等我冷静点再写一遍）  

### 核心代码
```
/******************
（由于不是我写的暂时不粘）
******************/
```
###错题记录
莫名其妙RE+MLE
***
