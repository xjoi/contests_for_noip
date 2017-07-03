# 比赛记录

[比赛链接div2](http://codeforces.com/contest/787)

## div2:A
### Problem description
> Rick和Morty在逃亡，Rick在b+ka(k为自然数)秒尖叫，Morty在d+kc(k为自然数)秒尖叫，输出两人同时尖叫的第一个时刻或-1表示永远不可能同时尖叫
(1 ≤ a, b ,c,d≤ 100)
### Solution
由题意可知：我们要求的是满足b+ia==d+jc的最小非负整数i所对应的b+ia，又显然可知i<max(a,b,c,d)，所以枚举i判断j是否为非负整数即可。
```cpp
none
```

## div 2:B
### Problem description
> 有n个星球，每个星球i有两个代表-i和i，其中一个是忠诚的一个叛徒，但不知道谁是。给你m个分组，每个代表可以在每组出现多次也可以出现在不同组，若有一个分组里面有可能全部都是叛徒，那么就输出YES反之NO(1 ≤ n, m ≤ 10^4,各组的人数和不超过10^4)
### Solution
当一个组内同时出现-x和x的时候显然这个组不可能都是叛徒，所以map判断即可
```cpp
	for(int i=0;i<m;i++){
		scanf("%d",&tot);
		for(int j=0;j<tot;j++)
		mp.clear();int o=1;
		for(int j=0;j<tot;j++){
		    scanf("%d",&x);
			if(mp.count(-x)==1)o=0;else mp[x]=1;
		}
		if(o)jud=1;
	}
	jud?printf("YES"):printf("NO");
```

## div 2:C
### Problem description
> 有一个n个节点的环每个节点编号为1-n，节点1是黑洞。开始怪物在y位置，Rick和Morty各有一个移动指令集合，对于一个移动指令x，可以使怪物顺时针走x个步。两人轮流发出指令，使怪物停在黑洞的那个人获胜，求对于y=[2,n]Rick先手和Morty先手的胜负情况，若先手必胜则输出WIN，必负则输出LOSE，若可以一直循环，则输出LOOP(2 ≤ n ≤ 7000,其余个数据均为正整数且小于n) 
### Solution
我们设f[x][u](0<=u<=1)表示怪物在x位置时u这个人先手的胜负情况。然后进行bfs更新，</br>
　　当f[x][u]为必输，显然f[x-s[i][u^1]][u^1]为必胜；</br>
　　当f[x][u]为必胜时，就将f[x-s[i][u^1]][u^1]的度-1，当f[x-s[i][u^1]][u^1]度为0时，f[x-s[i][u^1]][u^1]为必输；</br>
　　若没有进过队，则是loop；</br>
PS：对于f[x][u]的度定义为怪物在x时u能发出的指令数，即怪物能到的位置数(集合中元素各不相同嗷)，初始化时f[0][0]=f[0][1]=必输。
```cpp
  for(int i=0;i<n;i++)du[i][0]=k[0],du[i][1]=k[1];
	push(0,0,2);push(0,1,2);
	while(h<t){
		int x=q[++h][0],y=q[h][1],z=q[h][2];
		for(int i=0;i<k[y^1];i++){
			if(z==2)push((x-s[i][y^1]+n)%n,y^1,1);
			if(z==1){
				du[(x-s[i][y^1]+n)%n][y^1]--;
				if(!du[(x-s[i][y^1]+n)%n][y^1])push((x-s[i][y^1]+n)%n,y^1,2);
			}
		}
	}
```

# 赛后补题


## div 2:D
### Problem description
> 给你n个点q个操作，每个操作有三种类型：</br>
　　1、可以花费w从u到v(1 ≤ v, u ≤ n, 1 ≤ w ≤ 10^9)</br>
　　2、可以花费w从u到区间[l,r]任意一个点(1 ≤ v ≤ n, 1 ≤ l ≤ r ≤ n, 1 ≤ w ≤ 10^9)</br>
　　3、可以花费w从区间[l,r]到u任意一个点(1 ≤ v ≤ n, 1 ≤ l ≤ r ≤ n, 1 ≤ w ≤ 10^9)</br>
求从s到每个点的最少花费(1 ≤ n, q ≤ 10^5, 1 ≤ s ≤ n)
### Solution
可以建两颗线段树，一颗线段树tr1从上往下连单向边花费为0，另一颗tr2从下往上连单向边花费为0，两颗线段树的底层都是n个点</br>
　　而后对于第一个操作，直接连底层的点即可</br>
　　对于第二个操作，从底层对应u的点到代表区间的tr1上的点连一条花费为w的边</br>
　　对于第三个操作，从代表区间的tr2上的点到底层对应u的点连一条花费为w的边</br>
然后跑最短路即可
```cpp
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<queue>
#define inf 1e18
#define M 2000100
using namespace std;
long long f[M];
int a[M*2],c[M*2],fi[M],ne[M*2],la[M],b[M],u,l,r,x,y,typ,v,tot,w,n,q,s,m,pp;
void add(int x,int y,int z){
	if(x==y)return;
	a[++tot]=y;c[tot]=z;
	!fi[x]?fi[x]=tot:ne[la[x]]=tot;la[x]=tot;
}
void doit(int x,int y,int l,int r,int rt){
	//printf("%d %d %d %d %d %d\n",x,y,l,r,rt,typ);
	if(x<=l&&r<=y){
		typ==2?add(u,rt,w):add(rt>=m?rt:rt+2*m-1,u,w);return;
	}
	int mid=(l+r)>>1;
	if(x<=mid)doit(x,y,l,mid,rt<<1);
	if(y>mid)doit(x,y,mid+1,r,rt<<1|1);
}
void spfa(){
	for(int i=1;i<=3*m-2;i++)f[i]=inf;
	f[s]=0;b[s]=1;queue<int>q;q.push(s);
	while(!q.empty()){
		int x=q.front();q.pop();
		for(int i=fi[x];i;i=ne[i])if(f[a[i]]>f[x]+c[i]){
			f[a[i]]=f[x]+c[i];
			if(!b[a[i]]){q.push(a[i]);b[a[i]]=1;}
		}
		b[x]=0;
	}
}
int main(){
	scanf("%d%d%d",&n,&q,&s);m=1;
	while(m<n)m*=2;s+=m-1;
	for(int i=1;i<m;i++){
		int ls=i<<1,rs=i<<1|1;
		add(i,ls,0),add(i,rs,0);
		add(ls>=m?ls:ls+m*2-1,i+m*2-1,0);add(rs>=m?rs:rs+m*2-1,i+m*2-1,0);
	}
	for(int i=1;i<=q;i++){
		scanf("%d",&typ);
		if(typ==1){
			scanf("%d%d%d",&u,&v,&w);
			u+=m-1;v+=m-1;
			add(u,v,w);
		}
		else{
			scanf("%d%d%d%d",&u,&l,&r,&w);
			u+=m-1;
			doit(l,r,1,m,1);
		}
	}
	spfa();
	for(int i=m;i<n+m;i++)printf("%lld ",f[i]==inf?-1:f[i]);
}
```

## div 2:E
### Problem description
> 给你n个数，求对于k=1~n，求最少的区间数，每个区间必须包含不多于k个的数字种类，且所有区间不重叠又刚好长度和为n。(1 ≤ n ≤ 10^5,1 ≤ ai ≤ n)
### Solution
SOL1：玄学二分</br>
　　对于k1和k2(k1<k2)如果ans[k1]==ans[k2]，那么显然在k1和k2之间的k的ans[i]=ans[k1]，然后暴力二分求解即可，注意细节</br>
SOL2：

```cpp
#include<cstdio>
#include<cstring>
using namespace std;
int n,b[100100],f[100100],a[100100];
int query(int x){
	if(f[x])return f[x];
	int i=1,j=1;
	while(i<=n){
		int tot=0;
		while(tot<=x&&i<=n){
			if(!b[a[i]])tot++;
			b[a[i++]]=1;
		}
		f[x]++;//printf("%d %d\n",j,i);
		for(;j<i;j++)b[a[j]]=0;i--;j--;
		if(tot<=x)break;
	}
	return f[x];
}
void doit(int l,int r){
	int x=query(l),y=query(r);
	if(x==y){
		for(int i=l+1;i<r;i++)f[i]=x;
		return;
	}
	int m=(l+r)>>1;
	doit(l,m);
	doit(m+1,r);
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	doit(1,n);
	for(int i=1;i<=n;i++)printf("%d ",f[i]);
}
```
