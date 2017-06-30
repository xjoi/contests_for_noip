[比赛链接](https://cn.vjudge.net/contest/168561#overview)

# 比赛中解决的问题
## A
### Problem description
>给你一个N和一个C（1<=N<=100000,1<=K<=10^9），接下来再给你N个数字t1,t2,t3...tn(1<=T1<t2<t3<...<tn<=10^9)。</P>
找到一个序列L,R，使得tl到tR这R-L+1的数字都满足本数字减去前一个数字的差都小于等于K。输出R-L+1的值。

### Solution
> 我们从头到尾扫一遍，如果当前数t(i)-t(i-1)的差大于K，那么就把L指针移至i这个位置。最后输出R-L+1；

### Code
```cpp
#include<iostream>
#include<cstdio>
#define MAXN 100005
using namespace std;
int a[MAXN],k,n;
int main()
{
	scanf("%d%d",&n,&k);
	for (int i=0; i<n; i++) scanf("%d",&a[i]) ;
	int p=1;
	for (int i=1; i<n; i++) 
	if ((a[i]-a[i-1])<=k) p++;
	else p=1;
	printf("%d",p);
	return 0;	
}
```
*****


## B
### Problem description
> 给出字符串，如果字符串中有长度为26的子串，且子串中的‘？’经过替换可以刚刚好包含26个字母，就输出整个替换后的字符串

### Solution
> 首先如果字符串的长度小于26的直接输出-1，然后我们依次截取26长度的字符串进行测试。</P>
  如果这26个字符中的？可以替换成功，则说明我们已经成功地找到了解。</P>
  输出时将另外的‘？’一并改成A（反正有一个子串已经满足要求了），然后输出整个字符串。

### Code
```cpp
#include <cstdio>  
#include <stack>  
#include <queue>  
#include <cmath>  
#include <vector>  
#include <cstring>  
#include <algorithm>  
using namespace std;  
#define INF 0x3f3f3f3f  
char str[100011];  
int l;  
int ant[30];  
bool flag;  
int main()  
{  
    scanf ("%s",str);  
    l = strlen(str);  
    if (l < 26)  
    {  
        printf ("-1\n");  
        return 0;  
    }  
    bool ans = false;  
    for (int i = 0 ; i < l-25 ; i++)  
    {  
        memset(ant,0,sizeof(ant)) ;
        flag = true;  
        for (int j = i ; j < i + 26 ; j++)  
        {  
            if (str[j] == '?')    continue;  
            ant[str[j]-'A']++;  
            if (ant[str[j]-'A'] >= 2)  
            {  
                flag = false;  
                break;  
            }  
        }  
        if (flag)  
        {  
            ans = true;  
            for (int j = i ; j < i + 26 ; j++)  
            {  
                if (str[j] == '?')  
                {  
                    for (int k = 0 ; k < 26 ; k++)  
                    {  
                        if (ant[k] == 0)  
                        {  
                            ant[k] = 1;  
                            str[j] = 'A' + k;  
                            break;  
                        }  
                    }  
                }  
            }  
            if (ans)   break;  
        }  
    }  
    if (ans)  
    {  
        for (int i = 0 ; i < l ; i++)  
            if (str[i] == '?')     str[i] = 'A';  
        printf ("%s\n",str);  
    }  
    else  
        puts("-1");  
    return 0;  
}  

```
*****

## C
### Problem description
>：最开始给你一个数字x = 2，有两种操作：</P>
    1. 第一种是 + 操作， 每操作一次可以让x + k，可以操作无数次，k为当前等级，k的等级最开始为1。</p>
    2. 第二种操作是开方，即把x开方，开方成功之后，你的等级k就会上升一个等级，即k++；想要成功开方你开方后得到的数字必须是k+1的倍数。</P>
    问要让自己的等级k成为 n + 1，问你每上升一级，要按多少次 +；

### Solution
> 仔细分析一下，我们可以整理得下列式子：</P>
  1. a(i)+ans(i)xi = a(i+1)^2;</P>
  2. a(i) mod i = 0;</P>
  因为第i个答案为ans(i), 因此把第一个式子变形得：</P>
  3. ans(i) = (a(i+1)^2 - a(i) )/i;</P>
  这个式子说明只要满足a(i) mod i=0和a(i+1)^2 mod i=0的都可以拿来构造答案序列，我们让a(i)=ix(i-1),就得到ans(i)=ix(i+1)^2-i+1。</P>

### Code
```cpp
#include<iostream>
#include<cstring>
#include<cmath>
#include<cstdio>
#define ll long long
using namespace std;
int main()
{
     int n;
     scanf("%d",&n);
     cout<<"2"<<endl;
    for(ll i=2; i<=n; i++)
     {
         printf("%I64d\n",(i+1)*(i+1)*i-i+1);
     }
    return 0;
 }
```
*****


# 赛后补题

## D
### Problem description
> 有N个点m条边组成了一张图（1<=N<=1000，1<=M<=10000），有些相连的边的权值未知（输入时权值是0就代表这条边是未知的）。</p>
  给你起点s、终点t以及起点和终点之间的期望最短路的长度L，问给这些权值未知的点赋值之后st之间的最短路能否等于L。</P>
  如果等于就输出赋值方案，否则就输出NO

### Solution
> 

### Code
```cpp
```
*****


## E
### Problem description
> 

### Solution
> 

### Code
```cpp
```
