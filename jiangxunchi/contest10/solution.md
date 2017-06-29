# Solution
```
/******************

    VJudge链接：  https://cn.vjudge.net/contest/168038
CodeForces链接：  http://codeforces.com/contest/556

题目按CF顺序排序
******************/
```

***
## #A Case of the Zeros and Ones
```
/******************
    VJudge链接：  https://cn.vjudge.net/contest/168038#problem/A
CodeForces链接：  http://codeforces.com/contest/556/problem/A

      时间限制：  1s
      空间限制：  262144 kB
      主要算法：  贪心
******************/
```
### 题意
给你一个01串，如果0和1相邻就把两个都删掉，求最后最少剩下几个
### 题解
如果串中存在0和1，则肯定会有0和1相邻，就可以删掉，最后只会剩下0或1，所以答案救赎abs（0的个数-1的个数）。

***
## #B Case of Fake Numbers
```
/******************
    VJudge链接：  https://cn.vjudge.net/contest/168038#problem/B
CodeForces链接：  http://codeforces.com/contest/556/problem/B

      时间限制：  3s
      空间限制：  262144 kB
      主要算法：  模拟
******************/
```
### 题意
给你n个齿轮，每次可以旋转1个齿轮，而其他齿轮会随着这个齿轮旋转，问能否使第i个齿轮最上面的数字是i。
### 题解
把第1个齿轮转到1，然后看看其他齿轮是否对应就行了。

***
## #C Case of Matryoshkas
```
/******************
    VJudge链接：  https://cn.vjudge.net/contest/168038#problem/C
CodeForces链接：  http://codeforces.com/contest/556/problem/C

      时间限制：  2s
      空间限制：  262144 kB
      主要算法：  贪心
******************/
```
### 题意
给你几个套娃，有一些一开始已经套在一起，求最少要用几次把它们全都套在一起。
### 题解
如果1到k都被套在了一起，那么这些都不用解开，其他都要解开重套。

***
## #D Case of Fugitive
```
/******************
    VJudge链接：  https://cn.vjudge.net/contest/168038#problem/D
CodeForces链接：  http://codeforces.com/contest/556/problem/D

      时间限制：  3s
      空间限制：  262144 kB
      主要算法：  贪心
******************/
```
### 题意
给你几个不相交的区间和几座桥，每座桥能连接两个相邻的区间仅当能使桥的两端分别在这两个区间内，求是否可行和方案。
### 题解
将每两个相邻的区间需要的桥的长度最小值和最大值求出来，然后按最小值排序，对于每座桥，它需要连接在它的范围内切右端点最小的的两个区间，排序+优先队列维护一下就行了。

***
## #E Case of Chocolate
```
/******************
    VJudge链接：  https://cn.vjudge.net/contest/168038#problem/E
CodeForces链接：  http://codeforces.com/contest/556/problem/E

      时间限制：  3s
      空间限制：  262144 kB
      主要算法：  无法形容
******************/
```
### 题意
//TODO
### 题解
//TODO
