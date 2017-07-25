

[2017 Multi-University Training Contest - Team 1 - 比赛链接](http://acm.hdu.edu.cn/search.php?field=problem&key=2017+Multi-University+Training+Contest+-+Team+1&source=1&searchmode=source)

## Add More Zero
### Problem description
> 给出m,求出最大的k,使10^k<2^m-1.

### Data Limit：m <= 1e5  Time Limit: 1s
### Solution
> 就是求log10(2^m-1)的整数部分,根据对数的性质处理一下就可以了.

### Code
```cpp
int main(){
	int n,kase=0;
	while(scanf("%d",&n)==1){
		printf("Case #%d: %d\n",++kase,int(1.0*n*log(2)/log(10)));
	}
}
```
*****


## Balala Power
### Problem description
> 给出n个由a..z组成的字符串,将它们看成26进制数,求出将a..z与0..25对应的方案(字符串不能出现前导0),使得这些数的和最大,输出最大和%1e9+7.

### Data Limit：1≤n≤100000,1≤|si|≤100000,∑|si|≤106 Time Limit: 1s
### Solution
> 把所有数相加,就可以得到一个形如()\*a+()\*b+()\*c+...+()\*z的式子.其中每个括号代表对应字母的系数.显然,系数大的字母的值也要尽可能大,按照系数排序后,将系数最小的且字母没有在第一位出现过的字母对应0,其它依次对应1..25,求出最大值.

### Code
```cpp
LL ex[100010];
struct bignum{
	LL A[100010];
	int size;
	int id;
	bool isfirst;
	void init(int x){memset(A,0,sizeof(LL)*(size+1));size=0;id=x;isfirst=0;}
	bool operator <(const bignum &x){
		if (size!=x.size) return size<x.size;
		for (int i=size;i>=0;i--){
			if (A[i]!=x.A[i]) return A[i]<x.A[i];
		}
		return 0;
	}
}k[30];	//为了方便加法,用26进制维护系数.
int main(){
	int n,kase=0;
	ex[0]=1;
	for (int i=1;i<=100000;i++) ex[i]=(ex[i-1]*26)%mod;
	while(scanf("%d",&n)==1){
		for (int i=0;i<30;i++) k[i].init(i);
		for (int i=1;i<=n;i++){
			scanf("%s",buff);
			int len=strlen(buff);
			for (int j=len-1,p=0;j>=0;j--,p++){
				int pos=buff[j]-'a';
				k[pos].A[p]++;
				int pp=p;
				while (k[pos].A[pp]>25){
					k[pos].A[pp++]-=26;
					k[pos].A[pp]++;
				}
				k[pos].size=max(k[pos].size,pp);
				if (j==0) k[pos].isfirst=1;
			}
		}
		sort(k,k+26);
		int tmp=0;
		while(tmp<25&&k[tmp].isfirst) tmp++;
		for (int i=tmp;i>0;i--) swap(k[i],k[i-1]);
		LL ans=0;
		for (int i=0;i<26;i++){
			for (int j=0;j<=k[i].size;j++){
				ans=(ans+k[i].A[j]*i*ex[j])%mod;
			}
		}
		printf("Case #%d: %lld\n",++kase,ans);
	}
}
```
*****

## Function 
### Problem description
> 给出[0..n-1]和[0..m-1]的排列a[],b[],求出有多少种映射f(i)(i∈[0..n-1],f(i)∈[0..m-1]),满足对所有i都有f(i)=b[f(a[i])].

### Data Limit：1≤n≤100000,1≤m≤100000  Time Limit: 2s
### Solution
> 考虑这样一种情况:
> 
> f(i)=b[f(a[i])]=b[b[f(a[a[i]])]]=...=b[b[b[..b[f(i)]]..]].则显然`i`,`a[i]`,`a[a[i]]`,..,`a[a[..a[i]..]]=i`构成了一个环,且(设f(i)=j) `b[j]`,`b[b[j]]`,..`b[b[..b[j]..]]=j` 构成了一个环.且后者的长度为前者的约数.
> 
> 则只要求出a,b中所有的环,并记录每种a环长能与几个b环对应,利用乘法原理即可求出答案.

### Code
```cpp
#define MS(x) memset(x,0,sizeof x);
const int mod=1e9+7;
bool visit[100001],used[100001];
int Next[100001],a_circle[100001],circle_size[100001];
void dfs(int u,int& size){
	if (visit[u]) return;
	visit[u]=1;
	size++;
	dfs(Next[u],size);
}
int main(){
	int n,m,kase=0;
	while(scanf("%d%d",&n,&m)==2){
		MS(used);MS(a_circle);MS(circle_size);
		int cnt=0;MS(visit);
		for (int i=0;i<n;i++)scanf("%d",&Next[i]);
		for (int i=0;i<n;i++)if (!visit[i]) dfs(i,a_circle[++cnt]);
		MS(visit);
		for (int i=0;i<m;i++)scanf("%d",&Next[i]);
		int q=0;
		for (int i=0;i<m;i++){
			if (!visit[i]){
				int circ=0;
				dfs(i,circ);
				if (circ==1) q++;	//防止添加次数过多TLE
				else for (int j=circ;j<=n;j+=circ) circle_size[j]+=circ;
			}	
		}
		for (int i=1;i<=cnt;i++) 
			if (!used[a_circle[i]]) circle_size[a_circle[i]]+=q,used[a_circle[i]]=1;
		LL ans=1;
		for (int i=1;i<=cnt;i++)
			ans=(ans*circle_size[a_circle[i]])%mod;
		printf("Case #%d: %lld\n",++kase,ans);
	}
}
```
*****

## KazaQ's Socks
### Problem description
> 某人有编号为1..n的n双袜子,每天他会取出编号一双袜子穿,穿完后会堆在一起.当有(n-1)双袜子待洗时,他会一起清洗,在第二天结束时放回衣柜.求他第k天穿哪一双袜子.

### Data Limit：2≤n≤10^9,1≤k≤10^18  Time Limit: 1s

### Solution
> 暴力模拟之后会发现他的穿袜子序列为1,2,3,..,n-1,n;1,2,3,...,n-2,n-1;1,2,3,..,n-2,n;... 在第一轮1到n之后,以1,2,3,...,n-2,n-1;1,2,3,..,n-2,n为一个循环节.分类判断即可.

### Code
```cpp
int main(){
	long long n,k;
	int kase=0;
	while(scanf("%lld%lld",&n,&k)==2){
		printf("Case #%d: ",++kase);
		if (k<=n) {
			printf("%lld\n",k);
			continue;
		}
		k-=n;
		LL p=k%(n-1),t=k/(n-1);
		if (p!=0) printf("%lld\n",p);
		else printf("%lld\n",t&1?n-1:n);
	}
}

```
*****
