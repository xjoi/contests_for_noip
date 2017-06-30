# Solution
```
/******************
  开始编辑时间：  18:46 06/23/17
  结束编辑时间：  19:22 06/23/17

    VJudge链接：  https://cn.vjudge.net/contest/168038
CodeForces链接：  http://codeforces.com/contest/556

题目按CF顺序排序
******************/
```
# #A Case of the Zeros and Ones
```
/******************
    VJudge链接：  https://cn.vjudge.net/contest/168038#problem/A
CodeForces链接：  http://codeforces.com/contest/556/problem/A

      时间限制：  1s
      空间限制：  256MB
      主要算法：  贪心
******************/
```
### 题意
在一个01串中不断删除相邻的0和1，直到不能操作为止，问剩下串的长度。
### 题解
略。

***
# #B Case of Fake Numbers
```
/******************
    VJudge链接：  https://cn.vjudge.net/contest/168038#problem/B
CodeForces链接：  http://codeforces.com/contest/556/problem/B

      时间限制：  2s
      空间限制：  256MB
      主要算法：  模拟
******************/
```
### 题意
有N个齿轮，每个齿轮有N个齿，逆时针标号为0~N-1。每次可以将第一个齿轮顺时针旋转1个齿，那么之后第奇数个齿轮顺时针旋转1个齿，第偶数个齿轮逆时针旋转1个齿。每个齿轮有一个active tooth。给出起初每个齿轮active tooth的编号，求几次操作之后所有齿轮满足第i个齿轮的active tooth编号为i-1。
### 题解
强模拟。略。

***
# #C Case of Матрешках
```
/******************
    VJudge链接：  https://cn.vjudge.net/contest/168038#problem/C
CodeForces链接：  http://codeforces.com/contest/556/problem/C

      时间限制：  2s
      空间限制：  256MB
      主要算法：  模拟
******************/
```
### 题意
有N个俄罗斯套娃，按1~N编号，编号越小的套娃体积越小，开始时按某种情况几个几个套在一起。有两种操作，一是拆开一层套娃，一种是套进一层套娃，每个操作都要符合现实情况。问最少几次操作可以使所有套娃按序套在一起？
### 题解
在开始的情况下，和1号套娃**连续地**套在一起的套娃不需要被拆开，其他的全部都要拆开重组。这样就很好算了。

***
# #D Case of Fugitive
```
/******************
    VJudge链接：  https://cn.vjudge.net/contest/168038#problem/D
CodeForces链接：  http://codeforces.com/contest/556/problem/D

      时间限制：  3s
      空间限制：  256MB
      主要算法：  贪心
******************/
```
### 题意
有N条同一直线上的不相交线段，以及M个“桥”。桥能被用来连接**相连的**两条线段，当且仅当桥的长度能满足其两端点分别在两条线段的覆盖范围内。每个桥之能够使用一次，问是否有方案在所有相邻线段间搭上桥。有的话输出任意方案。
### 题解
考虑两条相邻线段[l1, r1]，[l2, r2]，能搭的桥的长度必须在区间[l2-r1, r2-l1]内。那么就可以处理出全部的这样的区间。接下去就要给这些区间分配桥。我们考虑两个区间[x1, y1]，[x2, y2]，如果两个区间交叉，那么我们要给靠左的区间分配长度尽量短的桥；如果两个区间出现覆盖，那么我们要给被覆盖的区间分配尽量短的桥。于是我们可以把这些区间按右端点从小到大排序，右端点相同的按左端点从大到小排序，给每个区间分配尽量小的桥即可。

***
# #E Case of Chocolate
```
/******************
    VJudge链接：  https://cn.vjudge.net/contest/168038#problem/E
CodeForces链接：  http://codeforces.com/contest/556/problem/E

      时间限制：  3s
      空间限制：  256MB
      主要算法：  可以是线段树
******************/
```
### 题意
唔不还是很想写题面了……
### 题解
标算是线段树，可以[戳这里](http://codeforces.com/blog/entry/18919)
其实每次操作的个数只取决于和此次操作位置最相近的前后两个位置的方向及个数。

看图说话 

![](http://codeforces.com/predownloaded/3d/06/3d06b9693038301f56c306e0c1ec006dbe2c6a5c.png)

以右侧图为例，其中第6次操作，与其最相近的是第9列（第4次操作）以及第2列（第1次操作）。由于此次操作为U操作，所以只和位于右侧的第4次操作有关（反过来L操作只与左侧有关）。可以看到，如果4操作是L操作，那么6操作的答案即为两操作位置间的高度差；如果4操作是U操作，那么4操作能达到的位置，6操作也能达到，答案即为两操作间位置高度差加上4操作的答案。所以维护一下处理过的操作的答案及其位置就可以了。

***
# Vocabulary Building
1. clockwise  -  `顺时针`
2. counter-clockwise  -  `逆时针`
3. eshibit  -  `展览品`
4. matryoshka  -  `俄罗斯套娃`
5. archipelago  -  `群岛`
6. diagonal  -  `主对角线`
7. anti-diagonal  -  `副对角线`