# Solution
```
    VJudge链接：  (DIV.1)https://cn.vjudge.net/contest/168406
CodeForces链接：  http://codeforces.com/contest/375

题目按CF顺序排序
```
## #A(DIV.2 A) Lever 
```
    VJudge链接：  https://cn.vjudge.net/contest/168406#problem/A
CodeForces链接：  http://codeforces.com/contest/376/problem/A

      时间限制：  1000ms
      空间限制：  256MB
      主要算法：  模拟 物理
      完成时间：  赛时
```
### Description
给出杠杆判断是否平衡。
### Solution
判断力臂L×力L是否等于力臂R×力R
或者，力矩L是否等于力矩R
***
## #B(DIV.2 B) I.O.U. 
```
    VJudge链接：  https://cn.vjudge.net/contest/168406#problem/B
CodeForces链接：  http://codeforces.com/contest/376/problem/B

      时间限制：  1000ms
      空间限制：  256MB
      主要算法：  模拟
      完成时间：  赛时
```
### Description
有N个人，他们之间互相欠钱。求简化之后每个人欠的钱数之和。
（原来题目的意思是I Owe You啊233一开始一直想不懂）
### Solution
模拟即可。
***
## #C(DIV.1 C) Divisible by Seven
```
    VJudge链接：  https://cn.vjudge.net/contest/168406#problem/C
CodeForces链接：  http://codeforces.com/contest/375/problem/A

      时间限制：  1000ms
      空间限制：  256MB
      主要算法：  数学
      完成时间：  赛时
```
### Description
给出一个数，其中一定包含1、6、8、9四个数。要求重新排列之后这个数能被7整除。
### Solution
考虑1、6、8、9，这四个数的排列所组成的数中，除以7余下0~6的数字都存在。那么可以在随意排列出其他数字之后使用这四个数平衡余数使其变为0。而所有余数都能被消去，所以一定有解。
### Code
```Cpp
    for(int i=1;i<=9;i++) {
        for(int j=1;j<=a[i];j++) {  //a[i]记录数字i出现了几次
            printf("%d",i);
            ans=(ans*10+i)%7;
        }
    }  //以上为取余
    ans=(ans*10000)%7;  //因为剩余4个数，所以这个余数ans要空出四位的空间(?)
    //之后用余数为(7-ans)%7的排列数消去余数
    //最后输出所有0（0肯定要放在最后）
```
***
## #D(DIV.1 B) Maximum Submatrix 2
```
    VJudge链接：  https://cn.vjudge.net/contest/168406#problem/D
CodeForces链接：  http://codeforces.com/contest/375/problem/B

      时间限制：  2000ms
      空间限制：  512MB
      主要算法：  ...
      完成时间：  赛时
```
### Description
给出一个01矩阵，可以交换其中的行，求交换之后全为1的子矩阵的最大面积。
### Solution
因为只能交换行，所以可以预处理出每一个1向右最远能延伸的长度。这样我们枚举每一列，在这一列中枚举延伸长度i，那么可行的子矩阵面积为延伸长度大于等于i的位置数量乘以长度i，同时处理出最大值即可。
### Code
```Cpp
    for(int i=1;i<=n;i++) {
        for(int j=m;j>=1;j--) {
            if(j<m&&f[i][j]) f[i][j]+=f[i][j+1];  //f[i][j]保存i,j位置的延伸距离
            g[j][f[i][j]]++;  //g[i][j]保存第i列延伸长度为j的位置数量
        }
    }
    int ans=0,cnt=0;
    for(int i=1;i<=m;i++) {
        cnt=0;  //cnt表示当前可行位置
        for(int j=m;j>0;j--) {  //倒序便于累计
            if(g[i][j]) {
                cnt+=g[i][j];
                ans=max(ans,j*cnt);
            }
        }
    }
```
***

先搁一搁，还有题要写233