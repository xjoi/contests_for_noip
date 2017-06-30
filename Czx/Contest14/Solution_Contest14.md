
[比赛链接](https://vjudge.net/contest/168561)

# 比赛中解决的问题
## A
### Problem description
> 给出一个数列和一个数c，当两数之间差大于c时之前所有数字消失，求最后剩余的数字

### Solution
> 直接暴力向后扫，用cnt统计答案就可以了

### Code
```cpp
#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <cstdio>
using namespace std;

int s[100010],dp[100010]; 

int main(){
	int n,c;
	scanf("%d%d",&n,&c);
	for (int i=1;i<=n;++i)
		scanf("%d",&s[i]);
	dp[1] = 1;
	for (int i=2;i<=n;++i)
		if (s[i] - s[i-1] <= c)
			dp[i] = dp[i-1] + 1;
		else dp[i] = 1;
	cout << dp[n] << endl;
}
```
*****


## B
### Problem description
> 给定一个字符串，通过修改？处的字符，使得存在一个长为26的连续子串含有每一个大写字母且互不重复

### Solution
> 我的方法是枚举每一个子串，用桶记录每一个字母是否出现，记录完成后将未出现的放入？处，其余？用任意字母填充，输出答案

### Code
```cpp
#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <cstdio>
using namespace std;

int main(){
	int n;
	long long now = 2;
	scanf("%d",&n);
	cout << 2 << endl;
	for (long long i=2;i<=n;++i){
		cout << i*(i+1)*(i+1) - i + 1 << endl; 
	}
	return 0;
}
```
*****


## C
### Problem description
> 有加法和开根号两种操作，其中开根号操作要求满足原数是完全平方数，且得到的数要是当前等级的倍数

### Solution
> 一道典型的数论题（结论题），理清楚题意后可以得到两个关系 ```①a[i]+ans[i]*i = a[i+1]^2 ②a[i] mod i = 0```
因为第i个答案为ans[i],因此将第一个式子变形为 ```ans[i] = (a[i+1]^2 - a[i]) / i```
这个式子说明只要能满足```a[i] mod i = 0```和```a[i+1]^2 mod i = 0```的数列a[i]都能用来构造答案数列，我们可以令```a[i] = i * (i-1)```
因此答案```ans[i] = (i+1)^2*i-i+1```, 同时要注意按照这种方式构造的数列ans[1]并不满足，因此特判后进行计算即可

### code
```cpp
#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <cstdio>
using namespace std;

int main(){
	int n;
	long long now = 2;
	scanf("%d",&n);
	cout << 2 << endl;
	for (long long i=2;i<=n;++i){
		cout << i*(i+1)*(i+1) - i + 1 << endl; 
	}
	return 0;
}
```


## D
### Problem description
> 给出一张无向图，其中有些边权未知，用0表示，要求对这些边进行赋值，使得指定的起点s和终点t之间的最短路刚好为L

### Solution
> 考场上写的时候读错题意，以为可以修改任意一条边的权值，导致一直wa
> 理解题意后想到较为暴力的做法，先将边权为0的边赋为1和0x3f3f3f3f，跑完s到t的最短路后判断是否存在一种情况使得要求满足>
> 当存在的情况下，将所有课修改的边权值赋为1，使用多遍s到t的最短路（SPFA或dijkstra），每一遍最短路记录路径，如果最短路小于L，可证明路径中一定存在一条可修改的边，将该边的权值增加L-dis使得当前s到t的路径的长度为L，进行多次操作直至得到的最短路等于L，输出当前各点间的情况

### code
```cpp
考场中未写出
```
