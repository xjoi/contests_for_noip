# Solution
```
/******************

    VJudge链接：  https://cn.vjudge.net/contest/168242
CodeForces链接：  http://codeforces.com/contest/821

题目按CF顺序排序
******************/
```

***
## #A Okabe and Future Gadget Laboratory
```
/******************
    VJudge链接：  https://cn.vjudge.net/contest/168242#problem/A
CodeForces链接：  http://codeforces.com/contest/821/problem/A

      时间限制：  2s
      空间限制：  262144 kB
      主要算法：  暴力
******************/
```
### 题意
给你一个矩阵，求是否对于矩阵所有不等于1的元素a[x,y]存在s,t使得a[x,y]=a[x,s]+a[t,y]。
### 题解
暴力判断即可。

***
## #B Okabe and Banana Trees
```
/******************
    VJudge链接：  https://cn.vjudge.net/contest/168242#problem/B
CodeForces链接：  http://codeforces.com/contest/821/problem/B

      时间限制：  2s
      空间限制：  262144 kB
      主要算法：  暴力
******************/
```
### 题意
给你一个一次函数，对于函数上的点（x,y），值为在第一象限且（i,j）（i<=x且j<=y）的（i+j）之和，求最大值。
### 题解
枚举函数上的点（x,y），用等差数列公式求和，再求最大值即可。

***
## #C Okabe and Boxes
```
/******************
    VJudge链接：  https://cn.vjudge.net/contest/168242#problem/C
CodeForces链接：  http://codeforces.com/contest/821/problem/C

      时间限制：  3s
      空间限制：  262144 kB
      主要算法：  贪心
******************/
```
### 题意
给你一个初始为空的栈和即可push，pop操作，每次操作完你可以重新排列栈内的元素，求最少重新排列几次是出栈顺序为1到n。
### 题解
每次出栈时判断是否符合顺序，不符合就重构栈内的所有元素。

***
## #D Okabe and City
```
/******************
    VJudge链接：  https://cn.vjudge.net/contest/168242#problem/D
CodeForces链接：  http://codeforces.com/contest/821/problem/D

      时间限制：  4s
      空间限制：  262144 kB
      主要算法：  bfs
******************/
```
### 题意
给你一个矩阵，让你从（1,1）走到（n,n），你只能走被点亮的格子。初始时有一些被点亮的格子，你也可以花费1的费用点亮一行或一列，但是你只能在初始点亮的格子更改点亮的或列。求最少费用。
### 题解
直接bfs，每次选费用最少的一个点，扩展时如果相邻直接走过去，如果行之差相差2以内或列之差相差2以内可以花1的费用走过去。

***
## #E Okabe and El Psy Kongroo
```
/******************
    VJudge链接：  https://cn.vjudge.net/contest/168242#problem/E
CodeForces链接：  http://codeforces.com/contest/821/problem/E

      时间限制：  2s
      空间限制：  262144 kB
      主要算法：  dp 矩阵优化
******************/
```
### 题意
从（0,0）走到（0,k），给你几条平行于x轴且横坐标范围不相交的线段，每次只能走在这条线段下面，求方案数。
### 题解
创建两个矩阵，一个16x1且（1,1）为1，一个16x16且（i,i+1）（i,i）（i,i-1）为1，每次读取一条线段将两个矩阵的大小设为纵坐标+1，再将第一个矩阵乘上第二个矩阵的线段的长度减一次方。最后第一个矩阵的（1,1）就是答案。
