[比赛链接](https://cn.vjudge.net/contest/168561)

# 比赛中解决的问题
## A
### Problem description
> 给定一个序列，如果序列的相邻的两个数字的差值大于C那么删除所有之前加入的值

### Solution
> 我们可以从后往前模拟，这样没有后效性

### Code
```cpp
int num=1;
for(int i=n;i>=1;i--)
	{
		if(a[i]-a[i-1]>c||i==1)
			break;
		num++;
	}
```
*****


## C
### Problem description
> 给定一个n，让你执行n次操作，t次你要做的是给一个序列执行k次，让他增加t\*k,并且让他成为${t}^{2}的倍数。求每次的k的值

### Solution
> 我们根据题意，很容易列一个方程

$\sqrt{ni+k(i-1)}=b(i+1)$
解得$n=i^{2}(i-1)-(i-2)$

### Code
```cpp
for(int i=3;i<=n+1;i++)
		printf("%lld\n",(int)(i*i*(i-1)-(i-2)));
```
*****

# 赛后补题

## B
### Problem description
> 就是让你在序列中满足条件，使得一段26个字符满足出现每个大写字母一次
>PS:考场的时候看错了题目，看成了求一段字符都要满足条件，于是wa了无数次，惨痛的经历

### Solution
> 模拟，我们用两个指针cnt1和cnt2分别记录？出现的次数，和每个字母出现的次数，如果满足条件就进行替换就可以了

### Code
```cpp
for(int i=0;i<=len-26&&!flag;i++)
	{
		memset(b,0,sizeof(b));
		int cnt1=0,cnt2=0;
		for(int j=i;j<i+26;j++){
			if(s[j]>='A'&&s[j]<='Z')
				b[s[j]-'A']++;
			else cnt1++;
		}
		for(int j=0;j<26;j++)
			if(b[j]==1) cnt2++;
		if(cnt1+cnt2==26)
		{
			for(int j=i;j<i+26;j++)
			{
				if(s[j]!='?') continue;
				for(int t=0;t<26;t++)
				{
					if(b[t]==0){
						s[j]=t+'A';b[t]=1;
						break;
					}
				}
			}
			flag=1;
		}
	}
```
*****


## D
### Problem description
> 

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
