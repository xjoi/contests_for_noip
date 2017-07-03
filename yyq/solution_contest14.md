[比赛链接](https://cn.vjudge.net/contest/168561)

# 比赛中解决的问题
## #A Crazy Computer
### Problem description
> 给出一串数，按顺序处理每个数，用计数器累计个数，当两个数之间的间隔大于一个给定的数c时，计数器清零。求最后计数器记录的个数。

### Data Limit: n<=1e5  Time Limit: 2s

### Solution
> 直接模拟，当相邻两个数中间相隔大于c时，便清零。

### Code
```cpp
cin>>n>>c;
cin>>num;
x=num;
tot++;
n--;
while(n--)
{
	cin>>num;
	if(num-x<=c)
		tot++;
	else
		tot=1;
	x=num;
}
cout<<tot<<endl;
```
*****


## #B Complete the Word
### Problem description
> 给你一串字符串，其中包括小写字母与问号，问号可以代替任何字母，问你有没有一个长度为26的字串，其中'a'~'z'26个小写字母全部出现了一遍，若不存在，则输出-1，若存在，则将问号代替后输出整个原字符串。

### Data Limit: len<=5e4  Time Limit: 2s

### Solution
> 首先我们知道，当字符串长度小于26时是显然不行的，直接输出-1。然后暴力遍历整个字符串，取长度为26的字串，用两个变量cnt1和cnt2分别记录不同小写字母出现个数和问号个数。遍历时，将每个小写字母有无出现过记录下来，若是第一次出现，则cnt1++，若是问号，则cnt2++。在遍历了26个字符后，若cnt1+cnt2==26，则有解，将该字串内的问号填充后，其他无关紧要的问号随意填就行了。

### Code
```cpp
for(int i=0;i<=len-26&&flag==true;i++)
{
	memset(b,0,sizeof(b));
	int cnt1=0,cnt2=0;
	for(int j=i;j<i+26;j++)
	{
		if(s[j]>='A'&&s[j]<='Z')
		{
		   b[s[j]-'A']++;
		}
		else
			cnt2++;
	}
	for(int j=0;j<26;j++)
		if(b[j]==1)
			cnt1++;
	if(cnt2+cnt1==26)
	{
		int t=0;
		for(int j=i;j<i+26;j++)
		{
			if(s[j]=='?')
			{
				for(;t<26;t++)
				{
					if(b[t]==0)
					{
						s[j]='A'+t;
						t++;
						break;
					}
				}
			}
		}
		flag=false;
	}
}
```
*****


## #C Plus and Square Root
### Problem description
> 一个等级制的小游戏，初始等级为1，有一个初始值为2的数字K。现在有两种操作，一是给数字K加上当前等级数；二是给数字K开方，并使等级上升一级。但操作二有两个要求，一个是当前的K是一个完全平方数，另一个是平方之后得到的数必须是下一等级数的倍数。现在给出一个等级数N，求使其达到N+1级的操作方法。只需输出每个等级中在对K开方之前做加法的次数。

### Data Limit: n<=1e5  Time Limit: 2s

### Solution
> 一道典型的数论题（结论题），理清楚题意后可以得到两个关系 ```①a[i]+ans[i]*i = a[i+1]^2 ②a[i] mod i = 0```
因为第```i```个答案为```ans[i]```,因此将第一个式子变形为 ```ans[i] = (a[i+1]^2 - a[i]) / i```
这个式子说明只要能满足```a[i] mod i = 0```和```a[i+1]^2 mod i = 0```的数列a[i]都能用来构造答案数列，我们可以令```a[i] = i * (i-1)```
因此答案```ans[i] = (i+1)^2*i-i+1```, 同时要注意按照这种方式构造的数列```ans[1]```并不满足，因此特判后进行计算即可

### Code
```cpp
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
	{
        if(i==1)
            printf("2\n");
        else
            cout<<(ll)(i+1)*(i+1)*i-(i-1)<<endl;
    }
    return 0;
}
```
*****

# 赛后补题

## #D Complete The Graph
### Problem description
> 给定一个有n个点，m条边，起点为s，终点为t的一个无向图。图中边权为0的边表示表示边权可以进行修改，现在要求改变所有这些边的边权（必须为正值），使得s到t最短路为L。

### Data Limit: n<=1000, m<=10000  Time Limit: 4s

### Solution
> 首先把边权为0的边用vector存起来，其他按原来方法，然后跑一遍dijkstra，如果最短路小于L，那么其他的0边无论怎么变化，最短路都不会变化，这时可以直接输出NO，如果等于L，则直接输出这个图，vector里面的0边搞成INF（1e9）输出就行了。最短路大于L的情况，这时就需要添加0边来看是否能找到最短路等于L的方案。具体的实现方法是把vector存的边一条一条的添加进原图中，添加的时候边权设为1。添加一条跑一次dij，如果添加到某条边使得最短路小于等于L，把最后添加进的这条边的权值加上```L-dis[t]```，然后记录下这条边在vector的位置，输出这个图，剩余的0边权值改为INF（1e9）输出即可。如果添加了所有边进去还是找不到最短路小于等于L的方案，那么就不存在方案，输出NO。

### Code
```cpp
dij();
if(dis[t]<L)
{
	puts("NO");
	return 0;
}
else if(dis[t]==L)
{
	puts("YES");
	for(int i=0;i<top;i+=2)
		printf("%d %d %I64d\n",E[i].u,E[i].v,E[i].w);
	for(int i=0;i<V.size();i++)
		printf("%d %d %I64d\n",V[i].u,V[i].v,INF);
	return 0;
}
int pos=-1;
for(int i=0;i<V.size();i++)
{
	add(V[i].u,V[i].v,1);
	add(V[i].v,V[i].u,1);
	dij();
	if(dis[t]<=L)
	{
		E[top-2].w+=L-dis[t];
		E[top-1].w+=L-dis[t];
		pos=i;
		break;
	}
}
```
*****

## #E Digit Tree
### Problem description
> 暂无

### Data Limit: n<=1e5  Time Limit: 3s

### Solution
> 暂无

### Code
> 暂无
*****
