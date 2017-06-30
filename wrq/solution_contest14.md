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

> 注意：子串为字符串中连续的一段，不连续的是子序列。题目要求输出的是整个满足要求的字符串，而不是子串。

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
> 初始数字x=2，k=1，有加操作每次使得x+=k，开根号操作使得x变为其算数平方根。  
其中，开根号操作只能对于完全平方数进行。在开根号后，k++，此时操作后的x应为k的倍数，否则不能进行该次开根号操作。
求要使得k达到n+1，在每次开根号前应进行几次加操作。

### Solution
> 【数学题】找规律，具体如下

### Code
```cpp
scanf("%lld",&n);
for (long long i=1;i<=n;i++) a[i]=i*(i+1)*(i+1)-i+1;
a[1]-=2;
for (long long i=1;i<=n;++i) printf("%lld\n",a[i]);
```
*****


## D
### Problem description
> 给出部分边的长度未知的无向图，输出一个方案使得从点s到t最短路长度为l

### Solution
> 先将所有长度未知的边赋为inf，若此时最短路长度小于l，则不存在合理方案。反之，将边赋为1，同理。其余情况必定存在可行方案。   
在第二遍将边赋为1计算最短路时，可记录下最短的路径，便于后面修改边长。反复修改和计算直到满足题目要求为止。

### Code
```cpp
//建边
void add(int x,int y,LL z){
	des[++sum]=y, val[sum]=z, nxt[sum]=fst[x], fst[x]=sum, e[sum]=sum+1;
	if (z==0) val[sum]=inf, b[sum]=1;
	des[++sum]=x, val[sum]=z, nxt[sum]=fst[y], fst[y]=sum, e[sum]=sum-1;
	if (z==0) val[sum]=inf, b[sum]=1;
}
//输出
void pr(){
	memset(f,0,sizeof f);
	for (int i=1;i<=sum;++i)
		if (!f[i]){
			printf("%d %d %I64d\n",des[e[i]],des[i],val[i]);
			f[i]=f[e[i]]=1;
		}
}

//主要计算部分
	for (int i=0;i<n;++i) dis[i]=inf;
	queue<int>q;
	q.push(s); dis[s]=0;
	while (!q.empty()){
		int x=q.front(); q.pop();
		for (int i=fst[x];i;i=nxt[i]){
			int y=des[i];
			if (dis[x]+val[i]<dis[y]) dis[y]=dis[x]+val[i], q.push(y);
		}
	}
	if (dis[t]<l){
		printf("NO"); return 0;
	}
	if (dis[t]==l){printf("YES\n"); pr(); return 0;}
	for (int i=1;i<=sum;++i) if (b[i]) val[i]=1;
	for (int i=0;i<n;++i) dis[i]=inf;
	q.push(s); dis[s]=0;
	while (!q.empty()){
		int x=q.front(); q.pop();
		for (int i=fst[x];i;i=nxt[i]){
			int y=des[i];
			if (dis[x]+val[i]<dis[y]){
				dis[y]=dis[x]+val[i], pre[y]=x, pree[y]=i;
				q.push(y);
			}
		}
	}
	if (dis[t]>l){
		printf("NO"); return 0;
	}
	while (dis[t]<l){
		for (int i=t;i!=s;i=pre[i]){
			if (b[pree[i]]){
				val[pree[i]]+=l-dis[t],val[e[pree[i]]]+=l-dis[t];
				break;
			}
		}
		for (int i=0;i<n;++i) dis[i]=inf;
		q.push(s); dis[s]=0;
		while (!q.empty()){
			int x=q.front(); q.pop();
			for (int i=fst[x];i;i=nxt[i]){
				int y=des[i];
				if (dis[x]+val[i]<dis[y]){
					dis[y]=dis[x]+val[i], pre[y]=x, pree[y]=i;
					q.push(y);
				}
			}
		}
	}
	printf("YES\n"); pr();
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
