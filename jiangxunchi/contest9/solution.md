# Solution
```
/******************

    VJudge链接：  https://cn.vjudge.net/contest/167920
CodeForces链接：  http://codeforces.com/contest/295

题目按CF顺序排序
******************/
```

***
## #A Greg and Array
```
/******************
    VJudge链接：  https://cn.vjudge.net/contest/167920#problem/A
CodeForces链接：  http://codeforces.com/contest/295/problem/A

      时间限制：  1s
      空间限制：  262144 kB
      主要算法：  差分
******************/
```
### 题意
给定一个数列和m个操作（这些操作都是给数列的一个区间内加上一个数），每次执行第l个到第r个操作，求最终的数列。
### 题解
用差分将每个操作执行了几次计算出来，然后对于每个操作，加上的数都乘上执行的次数，将这些操作都用差分执行后就可以求出最终的数列了。

***
## #B Greg and Graph
```
/******************
    VJudge链接：  https://cn.vjudge.net/contest/167920#problem/B
CodeForces链接：  http://codeforces.com/contest/295/problem/B

      时间限制：  3s
      空间限制：  262144 kB
      主要算法：  Floyd
******************/
```
### 题意
给你一张图，每次删除一个点，让你求所有点之间的最短路之和。
### 题解
将所有删除的点读进来逆序排列，然后每次加入一个点，按Floyd的方法进行松弛，就可以求出最短路之和了。

***
## #C Greg and Friends
```
/******************
    VJudge链接：  https://cn.vjudge.net/contest/167920#problem/C
CodeForces链接：  http://codeforces.com/contest/295/problem/C

      时间限制：  2s
      空间限制：  262144 kB
      主要算法：  dp bfs
******************/
```
### 题意
有一些重50或100的人在河的一边，有一辆载重为w的船，每次必须有一个人划船，求把所有人都到对面的最少次数和最少次数下的种类数。
### 题解
先bfs求出最少次数，然后dp，如果一个状态能从另一个状态转移来，就加上C（当前重50的人数，船上50的人数）*C（当前重100的人数，船上100的人数）。组合数可以先预处理出来。

***
## #D Greg and Caves
```
/******************
    VJudge链接：  https://cn.vjudge.net/contest/167920#problem/D
CodeForces链接：  http://codeforces.com/contest/295/problem/D

      时间限制：  2s
      空间限制：  262144 kB
      主要算法：  dp
******************/
```
### 题意
//TODO
### 题解
//TODO

***
## #E Yaroslav and Points
```
/******************
    VJudge链接：  https://cn.vjudge.net/contest/167920#problem/E
CodeForces链接：  http://codeforces.com/contest/295/problem/E

      时间限制：  5s
      空间限制：  262144 kB
      主要算法：  线段树
******************/
```
### 题意
//TODO
### 题解
//TODO
