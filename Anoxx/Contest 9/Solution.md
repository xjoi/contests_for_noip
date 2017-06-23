# The Solution
```
Source: Codeforces Round #179 (Div. 1)
    VJudge链接：  https://cn.vjudge.net/contest/167920#problem   
CodeForces链接：  http://codeforces.com/problemset/problem/295
```

***
## #A Greg and Array
```
Time limit: 1500 ms
Memory limit: 262144 kB
Tags: 差分，线段树
```
### 题意
给你n个数，m个操作，每个操作包含l、r、d，表示区间[l,r]+d，再给你k个总操作，每个总操作包含x、y，表示做第x到第y个操作，问最后各个数的数值；
### 题解
两次打标记（就是两次差分

***
## #B Greg and Graph
```
Time limit： 3000 ms
Memory limit： 262144 kB
Tags： 最短路，逆向思维
```
### 题意
给你n个点，每两个不同的点间路的距离，n次操作，每次操作删除一个点，求每次操作前所有点对之间的最短路之和。
### 题解
可以把每次操作删除一个点，看做从后面的操作到前面的操作依次加点，然后对于每次加点对其他所有点进行松弛；
然后每次的答案即为已加入各点目前为止间的最短路之和，倒着输出即可；

***
## #C Greg and Friends
```
Time limit： 2000 ms
Memory limit： 262144 kB
Tags： dp，bfs
```
### 题意
有n个人在岸边，每个人不是50kg就是100kg，有一艘船，载重量为k，可以载人过河，但每次必须有人划船，问使所有人都到对岸的最少过河次数和这个次数的方案数。
### 题解
最少过河次数bfs无脑求就行（好像都不用bfs……，设f[i][j][k]表示有i个50kg的人和j个100kg的人在原岸，船在（k==1？原岸：对面）的最少次数的方案数，
显然这可以在bfs的时候通过组合数维护，注意bfs的判重即可；

***
## #D New Year Letter
```
Time limit: 2000 ms
Memory limit: 262144 kB
Tags: dp
```
### 题意
对于一个n行m列的黑白矩阵，存在cave当且仅当：</br>
　　1、存在[l,r]使得第l行到第r行都有且仅有两个黑色格子，其他行没有；</br>
　　2、存在一个行号t，使得：</br>
　　　　1）对于任意存在黑色格子的行，设两个黑色格子的列号为x和y(x<y)，则设集合s(r)=[x,y]；</br>
　　　　2）任意取t及t之上的两个有黑色格子行，令上方的行为u，下方的行为d，则s(u)属于s(d);</br>
　　　　3）任意取t及t之下的两个有黑色格子行，令上方的行为u，下方的行为d，则s(d)属于s(u);</br>
求n行m列的黑白矩阵存在cave的方案数;</br>

### 题解
设f[i][j]表示前i行只让上面的行符合情况，第i行集合长度为j（可以看做两个黑色块一个在1，一个在j）的方案数，则：</br>
　　1、f[i][j]=sigma(f[i-1][k](2<=k<=j))+f[i][j-1];</br>
前面的sigma是显然的，而f[i][j-1]是因为，f[i][j-1]的情况可以整体向右移一位并依然符合f[i][j]的定义；</br>
　　2、ans=sigma((f[i][j]-f[i-1][j])\*f[n-i+1][j]\*(m-j+1))(1<=i<=n,2<=j<=m);</br>
f[i][j]-f[i-1][j]是因为第i-1行长度为j且第i行长度为j的方案可能重复计算，需要避免</br>
f[n-i+1][j]则是f[i][j]只算了上面符合情况的，我们需要和下面符合情况的方案数乘起来</br>
m-j+1则是因为这个区间可以左右移啊</br>

***
## #E Yaroslav and Points
```
 Time limit: 2000 ms
 Memory limit: 262144 kB
 Tags: 动态开点线段树
```
### 题意
给你n个x轴上的坐标，给你两个操作：
　　1、把输入的第j个点的坐标右移d</br>
　　2、给定区间，输出区间内点之间的距离和</br>
### 题解
开一个-1e8到1e8的线段树，对于每一个点，就把含有这个点坐标的区间更新，cnt代表区间内的点数，sum是区间内的点的坐标和，ans就是答案：</br>
　　c.sum=a.sum+b.sum;</br>
　　c.cnt=a.cnt+b.cnt;</br>
　　c.ans=a.ans+b.ans+a.cnt\*b.sum-b.cnt\*a.sum;</br>
（为什么这样？？手动模拟合并两个区间你就知道啦</br>
最后因为空间开不下那么多点，于是动态开点，要用到再标号，就可以啦</br>


