***
## #A New Year Candles
```
/******************
    VJudge链接：  https://cn.vjudge.net/contest/167828#problem/A
CodeForces链接：  http://codeforces.com/problemset/problem/379/A

Time limit: 1000 ms
Memory limit: 262144 kB
Source: Good Bye 2013
Tag: 暴力
******************/
```
### 题意
给你a个蜡烛，一个蜡烛烧一小时，b个蜡烛换一个新蜡烛，求最多可以烧几小时；
### 题解
水题；

***
## #B New Year Present
```
/******************
    VJudge链接：  https://cn.vjudge.net/contest/167828#problem/B
CodeForces链接：  http://codeforces.com/problemset/problem/379/B

Time limit： 1000 ms
Memory limit： 262144 kB
Source： Good Bye 2013
Tags： 暴力
******************/
```
### 题意
L，R，P表示左走，右走，放金币，不能走出边界，不能连续两次放金币，求任一长度在1e6里面的顺序使每个袋子的金币符合要求；
### 题解
水题，注意cout会TLE；

***
## #C New Year Ratings Change
```
/******************
    VJudge链接：  https://cn.vjudge.net/contest/167828#problem/C
CodeForces链接：  http://codeforces.com/problemset/problem/379/C

Time limit： 1000 ms
Memory limit： 262144 kB
Source： Good Bye 2013
Tags： 暴力
******************/
```
### 题意
给每一个人一个不同的评分使其不小于他们的要求的最小解，输出每个人的评分；
### 题解
水题；

***
## #D New Year Letter
```
/******************
    VJudge链接：  https://cn.vjudge.net/contest/167828#problem/D
CodeForces链接：  http://codeforces.com/problemset/problem/379/D

Time limit: 1000 ms
Memory limit: 262144 kB
Source: Good Bye 2013
Tags: 递推，dp
******************/
```
### 题意
给你s[1]&&s[2]的长度n和m，s[n]=s[n-1]+s[n-2],求是否存在s[1]&&s[2]使得s[n]中的AC串个数等于x，若存在输出初始的两串，任意解都可；
### 题解
设s[i]的AC串个数为f[i]，则f[i]=f[i-1]+f[i-2]+z（当s[i-2]的最后一个字符为A且s[i-1]的第一个字符为C时z=1，反之为0）；
设s[i-2]&&s[i-1]的头尾字符分别为a、b、c、d，可以发现当且仅当i=3时z取决于b和c，i>3时则取决于i%2==0？d&&a：d&&c;
于是枚举s[1]&&s[2]的AC串数量和首尾字母，而后用f值转移验证即可；

***
## #E New Year Tree Decorations
```
/******************
    VJudge链接：  https://cn.vjudge.net/contest/167828#problem/E
CodeForces链接：  http://codeforces.com/problemset/problem/379/E

 Time limit: 1000 ms
 Memory limit: 262144 kB
 Source: Good Bye 2013
 Tags: 计算几何，凸包，微积分
******************/
```
### 题意
给你n个轮廓，每个轮廓在[k,k+1]中有单调性，后放入的轮廓会被前面的挡住，求每个轮廓可见的面积；
### 题解
SOL1：维护左右端点在[k,k+1]之中的y最高的区间，保持它的单调性，并对于新加入的轮廓扫描所有区间，算出多出的面积和为答案。并把新的轮廓加入，并维护单调性。
SOL2：因为精度要求1e-4，因此把每个点分成2000*2000个点，然后对于每个新轮廓数新被包进的点即可。
SOL3：对于每个区间[k,k+1]，必然是一个向下的凸壳，对于每个新轮廓，直接维护改变的面积即可


***
## #F New Year Tree
```
/******************
    VJudge链接：  https://cn.vjudge.net/contest/167828#problem/F
CodeForces链接：  http://codeforces.com/problemset/problem/379/F

Time limit: 2000 ms
Memory limit: 262144 kB
Source: Good Bye 2013
Tags: LCA
******************/
```
### 题意
一开始有一个含四个节点的三叉树，以后q次，每次把给定的x多加两个儿子，求每次加完后的树的直径
### 题解
注意到对于新加入的两个点，他们在这个树中最远的点必然是未加入时直径的两个端点，于是每次比较最远的点的距离并更新直径即可

***
## #G New Year Cactus
```
/******************
    VJudge链接：  https://cn.vjudge.net/contest/167828#problem/G
CodeForces链接：  http://codeforces.com/problemset/problem/379/G

Time limit: 2000 ms
Memory limit: 262144 kB
Source: Good Bye 2013
Tags: dp,仙人掌图
******************/
```
### 题意
给定一个仙人掌图，小a和小b在上面的结点挂玩具，规定不能有小a和小b的玩具在图中相连，问对于小a放玩具所有可能的数量，小b的最大可放数量
### 题解
还不会

