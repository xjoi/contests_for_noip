# The Solution
  ```
 Source: Codeforces Round #310 (Div. 2)
     VJudge链接：  https://cn.vjudge.net/contest/168038#problem
 CodeForces链接：  http://codeforces.com/contest/556
  ```
  
  ***
 ## #A Case of the Zeros and Ones
  ```
 Time limit: 1000 ms
  Memory limit: 262144 kB
 Tags: 贪心
  ```
  ### 题意
 给你一个01串，‘01’或‘10’可以消掉，问最少剩余长度。
  ### 题解
 最后因为一定是全0或全1，所以ans=len-min(num0,num1)\*2;
  
  ***
 ## #B Case of Fake Numbers
  ```
 Time limit： 2000 ms
  Memory limit： 262144 kB
 Tags： 暴力
  ```
  ### 题意
 给你n个数，每个数规定在[0,n-1]中循环，每次操作可以使第2\*n个数+1或第2\*n+1个数-1
  ### 题解
 暴力
  
  ***
 ## #C Case of Matryoshkas
  ```
  Time limit： 2000 ms
  Memory limit： 262144 kB
 Tags： 暴力
  ```
  ### 题意
 俄罗斯套娃，规则与现实一样（取套娃和套套娃都算一步），开始给一些初始情况，求全部套一起的最少步数
  ### 题解
 注意只有1-k的初始情况不用拆开，其他都要拆开然后一个一个套
  
  ***
 ## #D Case of Fugitive
  ```
 Time limit: 3000 ms
  Memory limit: 262144 kB
 Tags: STL,贪心
  ```
 ### 题意
 有n个岛，m座桥，如果桥的长度能够满足能架在岛上，并且不超过岛的长度，那么可以，问所有的岛能不能联通起来 
 ### 题解
 每个区间(l,r)，应该尽量找大于等于l，并且小于等于r，跟r相差最小的，那么可以对岛进行排序，然后维护一个set，用来找离r最近的是哪座桥。
  
  ***
 ## #E Case of Chocolate
  ```
  Time limit: 3000 ms
   Memory limit: 262144 kB
  Tags: 线段树，STL
  ```
  ### 题意
 上三角，每次可以从副对角线上选一个点，然后选择向上或者向左走，问每次能连续走多少个格子，走过的不能再走 
  ### 题解
 注意到，对于一个点x向上的操作，我们只需要顺着副对角线往右边找到第一个被操作过的点y，若点y向上，则x能到的高度就是y到的高度，向左就是x轴间隔
 同样的，对向左的操作也有同样的规则，只不过是向左找罢了
 可以用map/set/线段树维护
  
  
