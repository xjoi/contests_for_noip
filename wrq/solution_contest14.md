[比赛链接](https://cn.vjudge.net/contest/168561)

# 比赛中解决的问题
## A
### Problem description
> 给出单词输入时间，根据题目给定的计算方法，统计最后剩余的单词数

### Solution
> 从头扫一遍，模拟整个过程
> 注意：细节，如果从第二个开始扫，ans初值应为1

### Code
```cpp
int ans=1;
for (int i=2;i<=n;++i){
	if (a[i]-a[i-1]<=c) ans++;
	else ans=1;
}
```
*****


## B
### Problem description
> 给出一个只含问号和大写字母的字符串，用大写字母替换该串中的问号，使得字符串中存在一个包含所有大写字母的子串，输出任意一种方案

### Solution
> 整个字符串长度s<=50000，包含所有大写字母的子串长度为26，因此可以暴力枚举子串的起点，统计该段内每个字母出现次数。
只要有一个字母出现两次，该段就不符合要求【要使得长度为26的串中包含所有26个字母，只能每个字母出现一次】
在子串中，问号部分用没有出现过的字母随机代替，满足要求即可。其余可以随意安排（比如全都是'A'）
>注意：子串为字符串中连续的一段，不连续的是子序列。题目要求输出的是整个满足要求的字符串，而不是子串。

### Code
```cpp
	if (len<26){
		printf("-1"); return 0;
	}//若整个字符串长度不足26，必定不存在长度为26的满足条件的子串，可直接退出
	bool ans=0;
	int loc;
	for (int i=0;i<len-25;i++){
		memset(a,0,sizeof a);
		bool f=1;
		for (int j=1;j<=26;++j){
			if (ss[i+j-1]!='?'){
				a[ss[i+j-1]-'A'+1]++;
				if (a[ss[i+j-1]-'A'+1]==2) f=0;
				if (!f) break;
			}
		}
		if (!f) continue;
		ans=1; loc=i;
		break;
	}
	if (!ans){
		printf("-1"); return 0;
	}
	int j=1;
	for (int i=0;i<loc;++i){
		if (ss[i]!='?') cout << ss[i];
		else cout <<'A';
	}//其余部分
	for (int i=loc;i<=loc+25;++i){
		if (ss[i]!='?') cout << ss[i];
		else{
			while (a[j]!=0) j++;
			a[j]=1;
			char c='A'+j-1; cout << c;
		}
	}//输出满足条件的子串部分
	for (int i=loc+26;i<len;++i){
		if (ss[i]!='?') cout << ss[i];
		else cout <<'A';
	}//其余部分
```
*****

# 赛后补题

## C
### Problem description
> 

### Solution
> 

### Code
```cpp
```
*****


## D
### Problem description
> 给出部分边的长度未知的无向图，输出一个方案使得从点s到t最短路长度为l

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
