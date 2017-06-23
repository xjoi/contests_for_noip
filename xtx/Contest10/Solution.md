# D

贪心。

首先，对于每一段间隔，可以抽象成两个量————最短和最长，就是被允许的桥的长度范围，在这里定义为l[i],r[i],1<=i<n。

然后，问题就发生了一个转化：

每一个l[i],r[i]可以看做一条线段，每座桥就可以看做一个点————那么问题现在就成了，如何分配点，使每条线段上都有其专属的点。

这个就可以贪心了。

将每对l[i],r[i]按照l[i]从小到大排序，将桥的长度b[i]从小到大排序。

对于每一个b[i]，将所有l[i]小于b[i]的加入优先队列，然后从优先队列中取出r[i]最小的那个，给它分配b[i]。当r[i]<b[i]时就输出"No"。

还有一种输出"No"的可能性，就是当所有的b[i]都跑过了后，还有l[i],r[i]没有加入优先队列或者优先队列不为空的话，就输出"No"。

```cpp

#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<queue>
using namespace std;
#define ll long long
#define pii pair<ll,int>
const int MAXN=200000;
struct Node{ll a,b;int id;};
struct cmp{bool operator()(const Node& a,const Node& b){return a.b>b.b;}};
bool CmpForSort(const Node& a,const Node& b){return a.a<b.a;}
int n,m;
priority_queue<Node,vector<Node>,cmp> PQ;
Node o[MAXN+10];
ll l[MAXN+10],r[MAXN+10];
pii b[MAXN+10];
int ans[MAXN+10];
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;++i)scanf("%I64d%I64d",l+i,r+i);
	for(int i=1;i!=n;++i)
	{
		o[i].a=l[i+1]-r[i];o[i].b=r[i+1]-l[i];o[i].id=i;
	}
	sort(o+1,o+n,CmpForSort);
	for(int i=1;i<=m;++i)
	{
		scanf("%I64d",&b[i].first);
		b[i].second=i;
	}
	sort(b+1,b+1+m);
	int pos=1;
	for(int i=1;i<=m;++i)
	{
		while(pos<n&&o[pos].a<=b[i].first)
		{
			PQ.push(o[pos]);++pos;
		}
		if(PQ.empty())continue;
		Node x=PQ.top();PQ.pop();
		if(x.b<b[i].first)return puts("No"),0;
		ans[x.id]=b[i].second;
	}
	if(pos<n||!PQ.empty())return puts("No"),0;
	puts("Yes");
	for(int i=1;i<n;++i)printf("%d ",ans[i]);
	return 0;
}

```

# E

有两种询问操作，现在考虑来了一个ax,ay,'U','L'的时候也一样。

找到前面所有询问中x>=ax中最小的。如果这个询问是'U'，那么它能戳上去的高度也就是我能戳上去的高度，如果是'L'，它就是我戳上去时挡在最前面的那一个。

具体怎么找，用map<int,pair<bool,int> >就好了。

就酱

```cpp
#include<iostream>
#include<cstring>
#include<map>
#include<cstdio>
#include<cmath>
using namespace std;
#define pii pair<bool,int>
#define mit map<int,pii>::iterator
int n,m;
map<int,pii> mp;
int main()
{
	scanf("%d%d",&n,&m);
	mp.insert(make_pair(n+1,make_pair(0,n+1)));
	mp.insert(make_pair(0,make_pair(1,n+1)));
	int x,y;
	bool q;
	char ch[2];
	for(int i=1;i<=m;++i)
	{
		scanf("%d%d%s",&x,&y,ch);
		q=ch[0]=='U';
		int res;
		if(q)
		{
			mit it=mp.lower_bound(x);
			if(it->first==x)res=0;
			else if(it->second.first)res=it->first+it->second.second-x;
			else res=it->first-x;
		}
		else
		{
			mit it=mp.upper_bound(x);--it;
			if(it->first==x)res=0;
			else if(it->second.first)res=x-it->first;
			else res=x-it->first+it->second.second;
		}
		printf("%d\n",res);
		mp.insert(make_pair(x,make_pair(q,res)));
	}
	return 0;
}

```
