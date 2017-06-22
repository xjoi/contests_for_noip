# Solution
```
/******************
  开始编辑时间：  18:32 21/06/17
  结束编辑时间：  19:40 21/06/17 [paused]

    VJudge链接：  https://cn.vjudge.net/contest/167828
CodeForces链接：  http://codeforces.com/contest/379
  tutorial链接：  http://codeforces.com/blog/entry/10171

题目按CF顺序排序
******************/
```

***

## #A New Year Candles
```
/******************
    VJudge链接：  https://cn.vjudge.net/contest/167828#problem/A
CodeForces链接：  http://codeforces.com/contest/379/problem/A

      时间限制：  1s
      空间限制：  256MB
      主要算法：  模拟
******************/
```
### 题意
有a支蜡烛，用b支蜡烛燃烧剩下的“梗”可以接成一支新蜡烛。问最多能用几支蜡烛。

### 题解
随便模拟呗

***
## #B New Year Present
```
/******************
    VJudge链接：  https://cn.vjudge.net/contest/167828#problem/B
CodeForces链接：  http://codeforces.com/contest/379/problem/B

      时间限制：  1s
      空间限制：  256MB
      主要算法：  还是摸你？
******************/
```
### 题意
有个一排n个礼物盒，需要在第i个盒子里放入ai个礼物。有个小机器人，共有三种操作：
> `L` ：左移一个盒子 <br />
> `R` ：右移一个盒子 <br />
 `P` ：在当前盒子放入一个礼物

其中`P`指令不能连续执行；小机器人不能移出边界。输出任意一个指令数不超过1e6的操作指令序列即可。

### 题解
简单模拟，有礼物要求就RLP（醉后一个LRP）没有就R。

***
## #C New Year Ratings Change
```
/******************
    VJudge链接：  https://cn.vjudge.net/contest/167828#problem/C
CodeForces链接：  http://codeforces.com/contest/379/problem/C

      时间限制：  1s
      空间限制：  256MB
      主要算法：  …………
******************/
```
### 题意
给n个人每人一个数字，要求这个数字大于这个人所给出的要求ai，并且所有数字不重复。
任意合法答案均可。

### 题解
sort之后扫一遍。

***
## #D New Year Letter
```
/******************
    VJudge链接：  https://cn.vjudge.net/contest/167828#problem/D
CodeForces链接：  http://codeforces.com/contest/379/problem/D

      时间限制：  2s
      空间限制：  256MB
      主要算法：  模拟 枚举 暴力 递推
******************/
```
### 题意
求两个分别长为n和m的，均由小写字母组成的字符串，将其按类似斐波那契的方式**(s[n]=s[i-2]+s[i-1])**生成许多字符串，使得第k个字符串包含有刚好x个“AC”

### 题解
首先可知除两端外中间的AC是不受顺序所影响的所以双重循环枚举就可以了。然而端点是需要分类讨论的，可能出现s1s2,s1s1,s2s1,s2s2这几种情况，所以先算出来各个情况可以增加AC的数量（a,b,c,d数组）然后再组合一下就可以了（比如既有s1s2,又有s1s1）。代码中c1[i],c2[i]->i层时s1和s2的个数 s1，s2->分别能塞下的最多AC数。注意if中边界条件和输出
***
## #E New Year Tree Decorations
```
/******************
    VJudge链接：  https://cn.vjudge.net/contest/167828#problem/E
CodeForces链接：  http://codeforces.com/contest/379/problem/E

      时间限制：  1s
      空间限制：  256MB
      主要算法：  “简单的”几何
******************/
```
### 题意
有n个宽为k的多边形叠在坐标系中，每个多边形下底面与x轴重合，，左侧与右侧和x轴垂直，顶面由一串数字y0,y1,y2...yk给出，表示顶面由点(0,y0),(1,y1),(2,y2)...(k,yk)组成……还是看图吧
![](http://codeforces.com/predownloaded/01/af/01af019d1a190491c4dab199d4785c4c9b1f3810.png)

然后要求的是，每个多边形可见的面积。
### 题解
还没A呐稍等。

***
## #F New Year Tree
```
/******************
    VJudge链接：  https://cn.vjudge.net/contest/167828#problem/F
CodeForces链接：  http://codeforces.com/contest/379/problem/F

      时间限制：  2s
      空间限制：  256MB
      主要算法：  LCA 树的直径
******************/
```
### 题意
给出一个根节点标号为1，根下有3个节点（标号2~4）的树，每次挑选一个存在的节点，增加两个子节点，求出每次操作之后**树的直径**。
> 树的直径：树上最长的点对间简单路径。

### 题解
> Mr.wyq: “动态维护树的直径”
记直径的两端点为u，v，则每次新增节点所生成的新的直径必过u，v中一点或两点，
所以只需枚举u/v是否被选中就可以了，剩下的那个点就是新增的两个节点中的一个。

***
## #G New Year Cactus
```
/******************
    VJudge链接：  https://cn.vjudge.net/contest/167828#problem/G
CodeForces链接：  http://codeforces.com/contest/379/problem/G

      时间限制：  2s
      空间限制：  256MB
      主要算法：  dp
******************/
```
### 题意
给你一个树不像树环不像环的东西（就是带有简单不交叉环的树），让你在上面染两种颜色，
两端点的颜色不能相同，问你白色从0到n时黑色的数量分别最多为多少。
### 题解
本来这只是一道简单的树DP，然而加了个恶心的环。。。。
