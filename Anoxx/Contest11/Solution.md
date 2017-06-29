# The Solution
  ```
 Source: Codeforces Round #420 (Div. 2)
     VJudge链接：  https://cn.vjudge.net/contest/168242#problem
 CodeForces链接：  http://codeforces.com/contest/821
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
 ## #B Okabe and Banana Trees
  ```
 Time limit： 2000 ms
 Memory limit： 262144 kB
 Tags： 暴力
  ```
 ### 题意
 给以一条直线y=-x/m+b，求在这个直线和坐标系围成的三角形中的最大分数矩阵，(x,y)的分数=x+y
 ### 题解
 暴力
  
  ***
 ## #C Okabe and Boxes
 ```
 Time limit： 2000 ms
 Memory limit： 262144 kB
 Tags： 栈，暴力
 ```
 ### 题意
 给你2n个操作，n个是把x进栈，n个是把栈顶出栈，你可以在每次操作前把栈中元素随意排列，问你需要在操作之间做几次随意排列能使出栈序列=1..n
 ### 题解
 注意到，假如你要做一次调换，必然是使栈中变成升序（从栈顶开始）所以并不用真正取调换，直接清空栈就行了，当再次栈中有元素的时候再判断是否要调换即可
  
  ***
 ## #D Okabe and City
  ```
 Time limit: 4000 ms
 Memory limit: 262144 kB
 Tags: bfs，最短路
  ```
 ### 题意
 　　有一张n*m的图，初始有k个地方是灯亮着的，你可以在初始亮灯的地方花费一金币使得任意一行或一列的灯全部点亮，但当你要再次点亮的时候，需要站在原来亮的点
 把上次点亮的那行或列点暗（初始亮的也会暗），求能从左上角到右下角只走亮的点的最小花费
 ### 题解
 SOL1：bfs，对于一个点(x,y)，显然他可以到相邻的点花费0，也可以花费1到相邻行列和其所在行列的点，dfs记录最小值即可。</br>
 SOL2：最短路，对于每一行每一列都建一个虚拟点，对于每个初始点亮的点，将它与相邻的点连一个边权为0的双向边，与所在行列和相邻行列的虚拟点连一条1的有向边，再
 连回来一条0的有向边，注意要对终点特判断以保证连通，然后最短路即可。
 
  ***
 ## #E Okabe and El Psy Kongroo
  ```
  Time limit: 2000 ms
   Memory limit: 262144 kB
  Tags: 矩阵乘法快速幂
  ```
  ### 题意
 给你一个n条平行于x轴的线段，终点坐标(k,0)，满足l[i]=r[i-1],k∈[l[n],r[n]],每次可以向右下，右，右上移动且在任何时刻都不能超过包含x坐标的线段的y值
 ，注意对于每个交界点其实是被两条线段覆盖的，求从(0,0)到(k,0)的方案数。
 ### 题解
 矩阵乘法快速幂，具体看代码，很好理解。
  
  
