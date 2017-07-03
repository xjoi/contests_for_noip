# Solution of Contest#014
```
    VJudge链接：  https://cn.vjudge.net/contest/168561
CodeForces链接：  http://codeforces.com/contest/716

题目按CF顺序排序
```
## #A Crazy Computer
```
    VJudge链接：  https://cn.vjudge.net/contest/168561#problem/A
CodeForces链接：  http://codeforces.com/contest/716/problem/A

      时间限制：  2000ms
      空间限制：  256MB
      主要算法：  模拟
      完成时间：  赛时
```
### Description & Solution
给出一串数，按顺序处理每个数，用计数器累计个数，当两个数之间的间隔大于一个给定的数c时，计数器清零。求最后计数器记录的个数。
### Code
```Cpp
ans=0;
lst=0;
scanf("%d%d",&n,&c);
for(int i=1,j;i<=n;i++) {
    scanf("%d",&j);
    if(j-lst>c) ans=0;
    ans+=1;
    lst=j;
}
printf("%d\n",ans);
```
***
## #B Complete the Word
```
    VJudge链接：  https://cn.vjudge.net/contest/168561#problem/B
CodeForces链接：  http://codeforces.com/contest/716/problem/B

      时间限制：  2000ms
      空间限制：  256MB
      主要算法：  暴力
      完成时间：  赛时
```
### Description
输入一个缺失部分信息的字符串，仅由大写英文字母和代表缺失的`?`号构成，要求填满其中的缺失部分，使其存在一个长度26位的连续子串，其中26个字母刚好各出现一次。
### Solution
字串长度在50000以内，大可以暴力修改。
### Code
```Cpp
void check(int x) { //判断字串中从第x位开始的子串是否满足要求
    int f[30];
    for(int i=0;i<=30;i++) f[i]=0;
    for(int i=x;i<=x+25;i++) {
        if(s[i]!='?') {
            f[s[i]-'A']++;
            if(f[s[i]-'A']>1) return;
        }
    }
    int j=0;
    for(int i=x;i<=x+25;i++) {
        if(s[i]=='?') {
            while(f[j]>0) j++;
            s[i]=(char)(j+'A');
            f[j]++;
        }
    }
    print(); //输出
}
```
***
## #C Plus and Square Root
```
    VJudge链接：  https://cn.vjudge.net/contest/168561#problem/C
CodeForces链接：  http://codeforces.com/contest/716/problem/C

      时间限制：  2000ms
      空间限制：  256MB
      主要算法：  数论
      完成时间：  赛时
```
### Description
一个等级制的小游戏，初始等级为1，有一个初始值为2的数字K。现在有两种操作，一是给数字K加上当前等级数；二是给数字K开方，并使等级上升一级。但操作二有两个要求，一个是当前的K是一个完全平方数，另一个是平方之后得到的数必须是下一等级数的倍数。现在给出一个等级数N，求使其达到N+1级的操作方法。只需输出每个等级中在对K开方之前做加法的次数。
### Solution
这题方法应该会有很多，下面是我的方法：
假设我们对样例3手模几次，就可以发现一个规律：当第![](http://chart.googleapis.com/chart?cht=tx&chl=i(i>1))个等级的初始数等于![](http://chart.googleapis.com/chart?cht=tx&chl=i\times(i-1))时，总有方法可行。因为这样可以满足![](http://chart.googleapis.com/chart?cht=tx&chl=[i(i-1)]^2)是![](http://chart.googleapis.com/chart?cht=tx&chl=i)的倍数，也是完全平方数，同时平方根是![](http://chart.googleapis.com/chart?cht=tx&chl=j)的倍数。据此简化一下算式再每次计算输出即可。
### Code
```Cpp
for(long long i=1;i<=n;i++) {
    if(i==1) printf("2\n");
    else printf("%lld\n",(long long)(i*(i+1)*(i+1)-(i-1)));
}
```
***
## #D Complete The Graph
```
    VJudge链接：  https://cn.vjudge.net/contest/168561#problem/D
CodeForces链接：  http://codeforces.com/contest/716/problem/D

      时间限制：  4000ms
      空间限制：  256MB
      主要算法：  最短路 图论
      完成时间：  赛后
```
### Description
给出一个无向图，其中一些边的权值被擦除了（初始值为0）。再给出起点S和终点T，要求给所有的被擦除的边赋上大于0的权值，使得S到T的最短路总权值恰好为L。
### Solution
这里给出其中一种解法。

首先对所有权值不为0（即未被擦除）的边跑一遍最短路，如果结果小于L，那么怎么做都不能达到要求，可以直接输出NO；之后对所有被擦除的边一个接一个将权值赋为1，并加入到图中，每次跑一遍最短路，当某一条边加入之后最短路小于等于L，那么将这条边权值赋值为(L-最短路长)，再把剩余的没加入的边权值全部赋为INF(1e18)，这样就可以达到要求。如果全部的边都加入后最短路还是大于L，那么无解。
### Code
```Cpp
ans=dijkstra(s);
bool flag=0;
if(ans<L) {
    puts("NO");
    return 0;
} else if(ans==L) {
    flag=1;
}
for(int i=0;i<Z.size()&&!flag;i++) {
    E[Z[i]].w=E[Z[i]^1].w=1;
    ans=dijkstra(s);
    if(ans<=L) {
        E[Z[i]].w=E[Z[i]^1].w+=L-ans;
        flag=1;
        break;
    }
}
```
***
## #E Digit Tree
```
    VJudge链接：  https://cn.vjudge.net/contest/168561#problem/D
CodeForces链接：  http://codeforces.com/contest/716/problem/D

      时间限制：  3000ms
      空间限制：  256MB
      主要算法：  树分治
      完成时间：  未完成
```
等我学完树分治再说吧。