# Solution
```
/******************
  开始编辑时间：  6-16 18:56
  结束编辑时间：  

    VJudge链接：  https://cn.vjudge.net/contest/167828
CodeForces链接：  http://codeforces.com/contest/379

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
      空间限制：  262144 kB
      主要算法：  暴力
******************/
```
### 题意
小学奥数题。
一根蜡烛能烧一小时，b根烧过的蜡烛能变成一根正常的蜡烛，一共有a根蜡烛，求最多能烧多少小时。

***
## #B New Year Present
```
/******************
    VJudge链接：  https://cn.vjudge.net/contest/167828#problem/B
CodeForces链接：  http://codeforces.com/contest/379/problem/B

      时间限制：  1s
      空间限制：  262144 kB
      主要算法：  贪心
******************/
```
### 题意
控制一个机器人走路。它在一排钱包前，站在最左边。钱包从左到右编号1~n。每个钱包有一定数量的钱。机器人可以执行3种操作："L"——向左走，"R"——向右走，"P"——从面前的钱包中取出一枚硬币。不能连续执行两个"P"操作，机器人只能在1~n范围内。求把所有钱拿光的一个合法操作序列。
### 题解
在第一个钱包前重复执行"PRL"，在其他钱包前重复执行"PLR"，直到取光当前钱包中的硬币。然后若不在第n个钱包，向右走。

***
## #C New Year Ratings Change
```
/******************
    VJudge链接：  https://cn.vjudge.net/contest/167828#problem/C
CodeForces链接：  http://codeforces.com/contest/379/problem/C

      时间限制：  1s
      空间限制：  262144 kB
      主要算法：  贪心
******************/
```
### 题意
有n个人，每个人想要一些礼物，你要发给其他人一些礼物，使每个人得到的礼物数大于等于每个人想要的礼物数且互不相同。求你需要发的最少礼物数。
### 题解
将每个人想要的礼物数从小到大排序，当前的人发前一个人的礼物数+1和想要的礼物数的最大值。

***
## #D New Year Letter
```
/******************
    VJudge链接：  https://cn.vjudge.net/contest/167828#problem/D
CodeForces链接：  http://codeforces.com/contest/379/problem/D

      时间限制：  1s
      空间限制：  262144 kB
      主要算法：  递推 枚举
******************/
```
### 题意
给你一个字符串列，满足递推式S[i]=S[i-1]+S[i-2]。你需要满足S[k]中一共有x个子串"AC"，且S[1]和S[2]的长度分别为n和m。求S[1]和S[2]的一种可能情况。
### 题解
我们发现第i个字符串对我们有用的数据只有首字母(st)，尾字母(en)和子串"AC"的数量(f)，递推式为st[i]=st[i-2],en[i]=en[i-1],f[i]=f[i-1]+f[i-2]+(en[i-2]=='A'&&st[i-1]=='C')。而首尾字母只有3种情况："A"、"C"、其他字符(可以用"D"代替)。
这样我们就可以枚举S[1]和S[2]的首字母、尾字母和"AC"的数量，进行递推，如果第k个字符串刚好符合条件就输出。

***
## #E New Year Tree Decorations
```
/******************
    VJudge链接：  https://cn.vjudge.net/contest/167828#problem/E
CodeForces链接：  http://codeforces.com/contest/379/problem/E

      时间限制：  1s
      空间限制：  262144 kB
      主要算法：  计算几何
******************/
```
### 题意
给你几条从x轴出发，到x轴结束的折线。第i条折线和x轴围成的区域被称作区域i。前面的区域会覆盖后面的区域。求每个区域没有被覆盖的面积。
### 题解
//TODO

***
## #F New Year Tree
```
/******************
    VJudge链接：  https://cn.vjudge.net/contest/167828#problem/F
CodeForces链接：  http://codeforces.com/contest/379/problem/F

      时间限制：  2s
      空间限制：  262144 kB
      主要算法：  倍增 lca
******************/
```
### 题意
给你一棵初始的树，接下来会执行n个操作：选择一个叶节点，并给它添加2个子节点。求每次操作完后树的直径。
### 题解
维护三个值，当前直径的两个端点和直径长度。每次添加时，其中一个端点是不会变的，于是可以拿一个端点和添加的节点的距离来更新这三个值。求距离需要使用倍增lca，支持随时添加节点。

***
## #G New Year Cactus
```
/******************
    VJudge链接：  https://cn.vjudge.net/contest/167828#problem/G
CodeForces链接：  http://codeforces.com/contest/379/problem/G

      时间限制：  2s
      空间限制：  262144 kB
      主要算法：  dp
******************/
```
### 题意
给你一个仙人掌，每个节点可以染一种颜色（黑色或白色），也可以不染。任意一条边不能连接一个黑色的点和一个白色的点。黑色的点必须要染a个，求白色的点的最大个数。
### 题解
//TODO
