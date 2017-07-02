# 比赛记录

[比赛链接div2](http://codeforces.com/contest/716)

## div2:A
### Problem description
> 给你一串时间和一个整数c，每个时间在黑板上写一个字，每次当下一个时间-上一个时间>c时，把黑板擦干净，问最后有几个字在黑板上
### Solution
暴力
```cpp
none
```

## div 2:B
### Problem description
> 给你一串仅包含大写字母和问号的字符串，问号可以赋值为任何字符，问能否找到一种赋值方案使得有一个长度为26的子串包含A-Z26个字母
### Solution
维护两个指针和指针所指的区间内各字母的情况，当出现字母重复时，移动左指针直到重复消失，否则移动右端点
```cpp
	for(int i=0,j=0;i<l;i++){
		if(s[i]!='?'){
			a[s[i]-'A']++;
	    	while (a[s[i]-'A']>1){
	    		if(s[j]!='?')a[s[j]-'A']--;
	    		j++;
			}
		}
		if(i-j==25){
			for(int k=j,p=0;k<=i;k++)
			if(s[k]=='?'){
				while(a[p])p++;
				s[k]=p+'A';
				a[p]++;
			}
			for(int j=0;j<l;j++)if(s[j]=='?')s[j]='A';
			for(int j=0;j<l;j++)printf("%c",s[j]);
			return 0;
		}
	}
```

## div 2:C
### Problem description
>　　最开始给你一个数字x=2，有两种操作，第一种是‘+’操作，每操作一次可以让x+k，可以操作无数次，k为当前等级，k的等级最开始为1。第二种操作是开方，即把x开方，开方之后，你的等级k就会上升一个等级，即k++；并且这时候你开方得到的数字必须是k+1之后的倍数，要让自己的等级k==n+1，问你每上升一级，要按多少次 +；
### Solution
　　因为每次开方后都是k+1的倍数，不妨按照第三个样例设开方后的x'=k(k+1)，则x=k^2(k+1)^2，于是得到上次一开方后的值y=k(k-1)，又因为从y到x加了ans次k，所以ans=(x-y)/k=k(k+1)^2-k+1，因为一开始x=2，所以不要忘了第一项要特判;
```cpp
	printf("2\n");
	for(ll i=2;i<=n;i++)
	printf("%lld\n",i*(i+1)*(i+1)-i+1);
```

# 赛后补题


## div 2:D
### Problem description
> 给你n个点m条边，有些边的权值被抹去了（用=0表示），你需要找到一种把抹去权值的边重新给予权值的方案，使得从s到t的最短路=L
### Solution
　　由于只需要任意一组解，所以可以将抹去权值的边权限赋为1，然后以t为起点跑最短路，再以s为起点跑最短路，这一次最短路跑的时候，每当遇到一条抹去权值的边
就强制把这个边<u,v>的边权w=max(w,L-dis[s\][u\],dis[t\][v\])，并以更新的w松弛其他点，若最后t的最短路答案不等L则无解，否则直接输出即可。</br>
正确性证明：</br>
　　1、当对于每一个被抹去权值的边在最短路过程中进行如上操作时，因为dis[s\][u\],dis[t\][v\]是最短路，所以必会使得每一条经过此边的s到t的路径的长度>=L且至少有一条=L</br>
　　2、若有一条不经过抹去权值边的路径，其长度为x，若x>=L,则对答案无影响，反之则无解。</br>
　　证毕。</br>

```cpp
	for(int i=1;i<=m;i++){
		sort(f[i]+1,f[i]+1+n);
		mx=0;mi=0x3f3f3f3f;
		for(int j=n;j>=1;j--){
			mi=min(mi,f[i][j]);
			mx=max(mx,mi*(n-j+1));
		}
		ans=max(mx,ans);
	}
```

## div 2:E
### Problem description
> 给你一棵树，树边有边权w，w是0~9的一个数，求有多少个本质不同的点对<u,v>使得u到v的最短路径上的数连成得数是M的倍数，本质不同当且仅当点对两个元素至少有一个不相同，M是10的倍数，点数<=10^5
### Solution
　　我们对这棵树进行点分治，每次分治算经过根节点的满足要求的路径数量，我们设A为从节点到根节点所形成的数，B为根节点到节点所形成的数。于是只需要把A中的每个元素存入map，再对每个B查询A\*10^].len+B%M==0的A的个数，即为查询map[-B/(10^B.len)]，这里可以用乘法逆元来做。注意从根出发形成的数字要特殊处理，因为有可能增加答案所对应的点对的路径不经过根节点，只是从根u的儿子v走到u再回到v，故要减去这种情况，具体细节看代码

```cpp
#include<cstdio>
#include<algorithm>
#include<map>
#include<cstring>
#define N 100100
#define LL long long
using namespace std;
map<LL,LL>mp;
LL a[N*2],c[N*2],fi[N],ne[N*2],la[N],vis[N],size[N],f[N],pow[N],ni[N],tt,tot,root,M,n,x,y,z,ans,mx;
void add(LL x,LL y,LL z){
	a[++tt]=y;c[tt]=z;
	!fi[x]?fi[x]=tt:ne[la[x]]=tt;la[x]=tt;
}
void exgcd(LL a,LL b,LL &d,LL &x,LL &y){
	if(!b){
		d=a;x=1;y=0;return;
	}
	exgcd(b,a%b,d,y,x);
	y-=x*(a/b);
}
void getroot(LL u,LL fa){
	size[u]=1;f[u]=0;
	for(LL i=fi[u];i;i=ne[i]){
		LL v=a[i];
		if(v==fa||vis[v])continue;
		getroot(v,u);
		size[u]+=size[v];
		f[u]=max(f[u],size[v]);
	}
	f[u]=max(f[u],tot-size[u]);
	if(f[u]<mx){mx=f[u],root=u;}
}
void getA(LL u,LL fa,LL dep,LL val){
	mp[val]++;
	for(LL i=fi[u];i;i=ne[i]){
		LL v=a[i],w=c[i];
		if(v==fa||vis[v])continue;
		getA(v,u,dep+1,(w*pow[dep]+val)%M);
	}
}
LL getB(LL u,LL fa,LL dep,LL val){
	LL tmp=mp[(((-val)%M+M)*ni[dep])%M];
	for(LL i=fi[u];i;i=ne[i]){
		LL v=a[i],w=c[i];
		if(v==fa||vis[v])continue;
		tmp+=getB(v,u,dep+1,(val*10+w)%M);
	}
	return tmp;
}
LL calc(LL u,LL dep,LL val){
	mp.clear();
	getA(u,-1,dep,val);
	return getB(u,-1,dep,val);
}
void solve(LL u){
	vis[u]=1;
	ans+=calc(u,0,0);
	for(LL i=fi[u];i;i=ne[i]){
	    LL v=a[i],w=c[i];
		if(vis[v])continue;
		ans-=calc(v,1,w);
		mx=1e18;tot=size[v];
		getroot(v,u);
		solve(root);
	}
}
int main(){
	scanf("%lld%lld",&n,&M);
	for(LL i=1;i<n;i++){
		scanf("%lld%lld%lld",&x,&y,&z);z%=M;
		add(x,y,z);
		add(y,x,z);
	}
	pow[0]=ni[0]=1;
	for(LL i=1;i<=100000;i++){
        pow[i]=pow[i-1]*10%M;
        LL d,x,y;
        exgcd(pow[i],M,d,x,y);
        ni[i]=(x%M+M)%M;
	}tot=n;mx=1e18;
	getroot(0,-1);
	solve(root);
	return printf("%lld",ans-n),0;
}
```

