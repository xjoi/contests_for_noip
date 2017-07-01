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
> 给定一个包含若干条不确定的边的图，求从s到t是否存在最短路恰好等于L的路径，并输出各个边的权值

### Solution
解法非常多啦，我就把每一个解法简单提及以下   
### NO的判断方法   
>如果把所有边的权值设为1仍然大于L或者所有边都为INF仍然小于L，那就是不存在的，道理细细琢磨  
### 判断YES的办法   
#### 1.最暴力的方法。   
>我们可以对所有不确定的边的权值都进行更改，每一次都加1，更新完之后都跑一边最短路，看是否满足条件，复杂度大概是nmlogn   
#### 2.比较巧妙的办法  
>初始未确定的边的权值为1.     
我们先跑一次从终点到各个顶点的最短路，求出终点到各个点的距离，设为d[x,t]  
然后再从出发点跑一边最短路，过程中更新权值，设这边的两个端点为x/y,让他等于L-d[s,x]-d[y,t]    
于是我们在增大边权的时候，就构造了一条权值始终大于等于L的路。于是输出等于L的时候的每一条边的边权就可以了。
>还有特殊情况，就是如果这个最短路是不经过未确定的边的，那就输出NO，也就是说不用判断上面的情况了
#### 3.更为巧妙的二分
>显然将所有边值都设为1若最短路大于L则无解，所有边值设为INF最短路小于L则无解。
其他情况一定是有解的。可以想象成将所有的边一次加一，如此循环操作，最短路必定会慢慢加一必定能够到达L；
那么假设总共有x条权值不确定的边，假设先对第一条边操作，将其不断加一，每加一次跑一遍最短路，始终不能到达L则说明经过第一条边的路必定始终大于L，同理对接>下来的边也如此操作。当然这样直接写会很复杂，可以用二分来模拟这个过程，具体就是代码中的cek()函数
注：参考网络
我实现了第3种，粘个代码看看吧。

### Dij
>注意book的位置
```cpp
int dij()
{
	bool book[maxn];
	memset(book,0,sizeof(book));
	for(int i=0;i<=n;i++) dis[i].dis=inf+9,dis[i].id=i;
	priority_queue<Node> q;
	dis[s].dis=0;
	q.push(dis[s]);
	while(!q.empty())
	{
		Node x=q.top();q.pop();
		if (book[x.id]) continue;
		book[x.id]=1;
		for(int i=head[x.id];i;i=e[i].next)
			if(dis[e[i].to].dis>dis[x.id].dis+e[i].w)
			{
				dis[e[i].to].dis=dis[x.id].dis+e[i].w;
					q.push(dis[e[i].to]);
			}
	}
	return dis[t].dis;
}
```
### 二分以及判断
```cpp
int ok(int sum)
{
	for(int i=0;i<p.size();i++)
	{
		e[p[i]].w=e[p[i]^1].w=1+min(sum,inf);
		sum-=e[p[i]].w-1;
	}
	return dij();
}
while(l<=r)
	{
		int mid=(l+r)>>1;
		int now=ok(mid);
		if(now>L) r=mid-1;
		else if(now<L) l=mid+1;
		else break;
	}
````
*****

## E
### Problem description
> 不会写

### Solution
> 真的不会写

### Code
```cpp
printf("我是蒟蒻真的不会写啦，以后会再补上\n");
```
