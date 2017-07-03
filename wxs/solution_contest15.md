[比赛链接](https://cn.vjudge.net/contest/168561)

# 赛后补题

## A
### Problem description

> 已知a，b，c，d，找到一个s，使s=n\*a+b&&s=m\*c+d(n,m为整数)

# Data Limit：1 ≤ a, b ≤ 100  +1s

### Solution

>第一反应是exgcd， 

# 但我不会啊！！！

>于是石乐志了，卡了好久，好久……

>最后终于发现暴力就够了……

>但最后来不及了，赶紧打了就去切下题，结果没发现自己其实wa掉了……

### Code
```cpp
s=b;
	for(int i=0;i<c;i++){
		if((s-d)/c*c==s-d){
			printf("%lld",s);
			return 0;
		}
		s+=a;
	}
```
*****


## B
### Problem description

> 寻找每一行（m行）有没有一对相反的数（最大n）。

### Data Limit：1 ≤ n, m ≤ 104  +2s

### Solution

> 明显水题

>但我当时石乐志了，最后10秒时其实交了，但是有点小错误……

### Code
```cpp
for(int j=1;j<=v;j++){
			int k;
			scanf("%d",&k);
			if(k<0){
				if(fx[-k]){
					F=1;
				}
				fy[-k]=
				1;
			}else{
				if(fy[k]){
					F=1;
				}
				fx[k]=1;
			}
		}
		if(!F){
			puts("YES");
			return 0;
		}
```
*****

## C
### Problem description

> 在一个环上博弈，每人有个集合，每次可以顺移集合里的数，移到1获胜，问起始在每个位置，每个人先手的获胜情况。

### Data Limit：1 ≤ ki （集合内数量）≤ n - 1 and 1 ≤ si, 1, si, 2, ..., si, ki ≤ n - 1 for 1 ≤ i ≤ 2  +4s

### Solution

> BFS

>每次搜下去

>重点是要存每个点的入度，如果入度不足则为LOOP（无限）。

### Code
```cpp
while(!Q.empty()){
		Node X=Q.front();Q.pop();
		int ddd=X.f==1?k1:k2;
		for(int i=1;i<=ddd;i++){
			int j=(X.v+(X.f==1?s1[i]:s2[i])-1)%n+1,k=X.f^1;
			if(f[j][k])continue;
			f[j][k]=f[j][k]|(f[X.v][X.f]^1);
			out[j][k]++;
			if(f[j][k]==1||out[j][k]==(k==0?k1:k2)){
				Q.push(Node(j,k));
			}
		}
	}
```
*****

## D
### Problem description

>最短路，最短路，最短路！！！

>可以点连点，点连区间，区间连点。

>求s到每点最短路。

### Data Limit：1 ≤ n, q ≤ 105, 1 ≤ s ≤ n，1 ≤ v ≤ n, 1 ≤ l ≤ r ≤ n, 1 ≤ w ≤ 109  +2s

### Solution

>直接建一颗线段树，然后在线段树上跑图就行了。

>每个点要建两遍，一边往上面连，一边往下连。

### Code
```cpp
void build(int& root,int L,int R){
	tot+=2;
	root=tot;
	t[root].l=t[root-1].l=L;
	t[root].r=t[root-1].r=R;
	if(L==R){
		C[L]=root;
		G[root-1].push_back(Edge(root,0));
		G[root].push_back(Edge(root-1,0));
		return;
	}
	int mid=L+R>>1;
	build(t[root].ls,L,mid);
	build(t[root].rs,mid+1,R);
	G[t[root].ls].push_back(Edge(root,0));
	G[t[root].rs].push_back(Edge(root,0));
	G[root-1].push_back(Edge(t[root].ls-1,0));
	G[root-1].push_back(Edge(t[root].rs-1,0));
}
void fuck1(int a,int b,int c){
	G[C[a]].push_back(Edge(C[b],c));
}
void fuck2(int root,int v,int L,int R,int w){
	if(t[root].l>=L&&t[root].r<=R){
		G[C[v]].push_back(Edge(root-1,w));
		return;
	}
	int mid=t[root].l+t[root].r>>1;
	if(mid>=L)fuck2(t[root].ls,v,L,R,w);
	if(mid<R)fuck2(t[root].rs,v,L,R,w);
}
void fuck3(int root,int v,int L,int R,int w){
	if(t[root].l>=L&&t[root].r<=R){
		G[root].push_back(Edge(C[v],w));
		return;
	}
	int mid=t[root].l+t[root].r>>1;
	if(mid>=L)fuck3(t[root].ls,v,L,R,w);
	if(mid<R)fuck3(t[root].rs,v,L,R,w);
}
```
*****

## E
### Problem description

> 给出线段上每个点的值，问当每区间不能超过k个不同值时，最少要分几个区间。

### Data Limit：1 ≤ n ≤ 105 +2s

### Solution

>暴力二分每个k值，当ans[l]==ans[r]时，说明中间都是这个值。

### Code
```cpp
void solve(int l,int r){
	if(l>r)return;
	ans[l]=get(l);
	ans[r]=get(r);
	if(ans[l]==ans[r]){
		for(int i=l+1;i<r;i++){
			ans[i]=ans[l];
		}
		return;
	}
	int mid=l+r>>1;
	solve(l+1,mid),solve(mid+1,r-1);
}
```
