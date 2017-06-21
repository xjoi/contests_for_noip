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
      主要算法：  摸你
******************/
```
### 题意
有a支蜡烛，用b支蜡烛燃烧剩下的“梗”可以接成一支新蜡烛。问最多能用几支蜡烛。

### 题解
暴力摸你即可。WA了一发就只有我了吧…

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
任意一个的话……那我就从最左走到最右，每次可以放礼物那就放一个2333，这样最多有n*max{ai}条指令，可以满足要求。

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
唔，sort之后扫一遍嘛。

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
求两个分别长为n和m的，均由小写字母组成的字符串，将其按类似斐波那契的方式**(s[n]=s[i-2]+s[i-1])**生成许多字符串，使得第k个字符串包含有x个“AC”~（想AC想疯了）~

### 题解
字符串在拼接的时候可能有前一个字符串的末尾与后一个字符串的开头组合成一个“AC”，而中间的字符都不大要紧，所以只需要枚举初始字符串中的AC数，开头字母以及末尾字,母。AC数最多为长度/2，开头末尾字符只有A、C或其他字母三种情况。特判比较多，详见代码。然后递推出第k个字符串，满足要求的话就按枚举出的信息生成字符串即可。
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

倍增LCA，新增节点时处理出新节点的深度和倍增祖先。
因为每次操作只加了一层节点，所以树的直径每次最多增加1。只要维护最深的节点，如果新节点的深度比原先最深节点多1，那么ans++；否则只要求出新节点到原先最深节点的路径长度，如果大于ans，那么就更新，不然ans不变。
X和Y两节点之间的路径等于：X的深度 + Y的深度 - 2*（X和Y的LCA）

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
不会，任性
