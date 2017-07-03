[比赛链接](https://cn.vjudge.net/contest/167220)

# 比赛中解决的问题
## #B Chewbaсca and Number
### Problem description
> 给一个数，求每位按（9-该位数）反过来后最大的数。

### Data Limit: n<=1e18  Time Limit: 1s

### Solution
> 直接遍历数字的每一位，取原数与（9-原数）的最大值，最后输出即可。

### Code
```cpp
for(int i=0;i<strlen(a);i++)
	if('9'-a[i]<a[i]-'0')
		a[i]='9'-a[i]+'0';
```
*****


## #C R2D2 and Droid Army
### Problem description
> 一个军队中有n个机器人，每个机器人有m个数值。你一共可以射击k次，每次可以将一段机器人的某一个值减1，若机器人的m个值均为0后，这个机器人就被破坏了。问在k次射击之内，最长可以破坏的机器人的队列的长度。

### Data Limit: n<=1e5, m<=5, k<=1e9  Time Limit: 2s

### Solution
> 用线段树保存m个数值的区间最大值。线段树查询区间最大值，二分死亡的机器人个数，枚举区间起点，区间m个值的最大值的和如果小于等于k则满足条件。

### Code
```cpp
int l=1,r=n;
while(l<=r)
{
    bool flag=0;
	int mid=(l+r)>>1;
	for(int i=1;i+mid-1<=n;i++)
	{
        memset(tmx,0,sizeof(tmx));
		query(i,i+mid-1,1);
		int sum=0;
		for(int i=0;i<m;i++)
			sum+=tmx[i];
		if(sum<=k)
		{
			flag=1;
			if(knum<mid||(knum==mid&&snum>sum))
			{
				knum=mid;
				snum=sum;
				for(int i=0;i<m;i++)
					ans[i]=tmx[i];
			}
		}
	}
	if(flag)
		l=mid+1;
	else
		r=mid-1;
}
```
*****


## #D Han Solo and Lazer Gun
### Problem description
> 给你枪的坐标，再给你几个要打的物品的坐标，问要几枪可以全部打完？

### Data Limit: n<=1000  Time Limit: 1s

### Solution
> 遍历所有点，用set存每个点与枪坐标点的k值，再输出set的size就行了。

> P.S. 注意当物品点和枪坐标点相同时加特判。

### Code
```cpp
for(int i=1;i<=n;i++)
{
	cin>>xx>>yy;
	if(xx!=x&&yy!=y)
		k=(yy-y)/(xx-x);
	if(xx==x&&yy!=y)
		k=INF;
	if(yy==y&&xx!=x)
		k=-INF;
	s.insert(k);
}
```
*****


## #E Watto and Mechanism
### Problem description
> 给出n个字符串，存在Mechanism的内存里，接下来给出m个字符串，问可不可以改变每个字符串的某一个字母来与内存中的字符串相等，可以输出“YES”，否则输出“NO”。

### Data Limit: n<=3e5  Time Limit: 3s

### Solution
> 可以发现我们可以将前n个字符串先进行哈希存入set，再将后m个字符串哈希，在遍历改变某个字符时对哈希值进行改变，若set中存在这个哈希值，就是“YES”，若遍历完还是找不到对应的哈希值，就输出“NO”。

### Note
> 这题有坑点。对于哈希的mod，要取得巧妙一些，否则容易使哈希值重复导致WA。

> P.S. 我取的mod值为1000000000000000007。

### Code
```cpp
bool check()
{
	ll sum=hash();
	for(int i=0;i<strlen(c);i++)
	{
		int num=geti(c[i]);
		for(int j=1;j<=3;j++)
			if(j!=num)
			{
				ll ans=(sum-(num*mul[i]%mo)+(j*mul[i]%mo)+mo)%mo;
				if(s.count(ans))
					return true;
			}
	}
	return false;
}
```
*****

# 赛后补题

## #A Darth Vader and Tree
### Problem Description
> 给定n个边的数值d[i]，求x分解成子树（每条边为权值为d[i]）的总个数。
### Solution
> 首先我们可以得到dp方程dp[x] = dp[n-d[1]] + dp[n-d[2]]+...+dp[n-d[i]] + 1;但是x最大值有10e9,所以直接dp是不可行的。

> 但是这样还不够,以为i的范围很大,不能用单纯的for循环来求解,这时候应该想到利用矩阵来做矩阵快速幂. 

> 构造一个矩阵K使得[f[1],f[2],f[3],...,f[100]]*K=[f[2],f[3],f[4],...,f[101]].要能够快速幂K肯定是个正方形矩阵.所以可以大致得到上面的矩阵公式.然后下面就是构造K矩阵的问题了.由

> f[2]=f[1]*c[1]+1

> f[3]=f[1]*c[2]+f[2]*c[1]+1
  
> .....
  
> f[101]=f[1]*c[100]+f[2]*c[99]+…+f[100]*c[1]+1
  
> 易知K的初步构造如下: 
  
> c1  c2  c3  ... c100

>  0  c1  c2  ... c99
 
>  0   0  c1  ... c98
 
> ... ... ... ... ...

>  0   0   0   0  c1
 
> 显然这样还不够,因为缺少了公式最后的”+1”,假设原矩阵是A*K=B的话,令A多一列变为[A,1],令K多一行一列,则K应该变为: 

> c1  c2  c3  ... c100 0

>  0  c1  c2  ... c99  0
 
>  0   0  c1  ... c98  0
 
> ... ... ... ... ...  0

>  0   0   0   0  c1   0
 
>  1   1   1   1   1   1

> 然后A*K=B的矩阵就构造完成了[f[1],f[2],f[3],...,f[100],1]*K=[f[2],f[3],f[4],...,f[101],1].要求Fn,则计算A∗Kn−100即可.

### Code
```cpp
if(m<=100)
    printf("%lld\n",presum+1);
else
{
    memset(A.mat,0,sizeof(A.mat));
    memset(tmp.mat,0,sizeof(tmp.mat));
    for(ll i=0;i<100;i++)
		tmp.mat[i][0]=dp[i+1];
    tmp.mat[100][0]=presum+1;
    for(ll i=0;i<99;i++)
        A.mat[i][i+1]=1;
    for(ll i=0;i<100;i++)
		A.mat[99][i]=len[100-i];
    for(ll i=0;i<100;i++)
	    A.mat[100][i]=len[100-i];
    A.mat[100][100]=1;
    B=matrix_quick_power(A,m-100);
    B=matrix_mul(B,tmp);
    printf("%lld\n",(B.mat[100][0]+mod)%mod);
}
```
