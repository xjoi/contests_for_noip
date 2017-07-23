# 比赛记录

[比赛链接div2](http://codeforces.com/contest/477)

## div2:A
### Problem description
> 给你n个数和一个,求在%p意义下第一次重复的位置(n,p<=300,a[i]<=10^9)
### Solution
暴力扫一遍就好了
```cpp
#include<cstdio>
#include<algorithm>
using namespace std;
int p,n,x,b[10000];
int main(){
	scanf("%d%d",&p,&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&x);
		if(b[x%p])return printf("%d",i),0;
		b[x%p]=1;
	}
	return printf("-1"),0;
}
```

## div 2:B
### Problem description
> 给你一个只包含小写字母的字符串和操作数k,以及26个字母的分数,求加入k个小写字母的最大得分,字符串s的得分=sigma((i+1)*w[s[i]])(0<=i<|s|,k,w[i]<=10^3)
### Solution
由于越后面的字母对得分贡献越大,直接在后面加k个分数最大的字母就行了

```cpp
#include<cstdio>
#include<string>
#include<cstring>
#include<algorithm>
using namespace std;
char s[20000];
int k,a[20000],ans,mx;
int main(){
	scanf("%s",s);
	scanf("%d",&k);
	for(int i=0;i<=25;i++){
		scanf("%d",&a[i]);mx=max(mx,a[i]);
	}
	int l=strlen(s);
	for(int i=0;i<l;i++)ans+=(i+1)*a[s[i]-'a'];
	for(int i=1;i<=k;i++)ans+=(l+i)*mx;
	return printf("%d",ans),0;
}
```

## div 2:C
### Problem description
> 给你n个数字,求更改一个数字后的最长上升子串(n<=10^5,a[i]<=10^9)
### Solution
设f[i]为以i结尾的最长上升子串长度,c[i]为以i开始的最长上升子串长度,然后枚举改第j位,与f[i-1]和c[i+1]判断即可
```cpp
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int n,a[100100],f[100100],c[100100],ans;
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	for(int i=1;i<=n;i++)
	    if(a[i]>a[i-1])f[i]=f[i-1]+1;
	    else{
	    	f[i]=1;
	    	for(int j=1;j<=f[i-1];j++)c[i-j]=j;
		}
	for(int j=1;j<=f[n];j++)c[n+1-j]=j;
	for(int i=1;i<=n;i++){
		//printf("%d %d\n",f[i],c[i]);
		ans=max(ans,f[i]);
		if(a[i-1]>=a[i])ans=max(ans,f[i-1]+1);
		if(a[i+1]<=a[i])ans=max(ans,c[i+1]+1);
		if(a[i+1]-a[i-1]>1)ans=max(ans,f[i-1]+c[i+1]+1);
	}
	printf("%d\n",ans);
	return 0;
}
```


## div 2:D
### Problem description
> 给你一个n*m的矩阵,k此操作,每次可以使一行或一列的所有数字-p并得到这行或这列数字操作之前的数字和为分数,求最大分数和(n,m<=1000,k<=10^6;p<=100)
### Solution
可以发现,如果确定了选几次行,几次列,那么选哪几行对选择哪几列是没有影响的,反之亦然.所以我们可以贪心的选出最大的0~k个行或列,最后枚举选几行并取大值即可
```cpp
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<queue>
#define ll long long
using namespace std;
priority_queue<ll>qcol,qrow;
ll n,m,k,p,x,row[10001],col[10001],rowjudge,coljudge,ans,anscol[1000100],ansrow[1000100];
int main(){
	scanf("%lld%lld%lld%lld",&n,&m,&k,&p);
	for(int i=1;i<=n;i++)
	for(int j=1;j<=m;j++){
		scanf("%lld",&x);
		row[i]+=x;
		col[j]+=x;
	}
	for(int i=1;i<=n;i++)qrow.push(row[i]);
	for(int j=1;j<=m;j++)qcol.push(col[j]);
	for(int i=1;i<=k;i++){
		ll now=qrow.top();qrow.pop();
		ansrow[i]=ansrow[i-1]+now;
		qrow.push(now-p*m);
		now=qcol.top();qcol.pop();
		anscol[i]=anscol[i-1]+now;
		qcol.push(now-p*n);
	//	printf("%lld %lld\n",ansrow[i],anscol[i]);
	}
	ans=-0x7f7f7f7f7f7f7f7f;
	for(ll i=0;i<=k;i++)
	ans=max(ans,ansrow[i]+anscol[k-i]-i*(k-i)*p);
	return printf("%lld\n",ans),0;
}
```
# 赛后补题

## div 2:E
### Problem description
>给你n个数,有m次操作,操作分为两种:</br>
&emsp;&emsp;1.将l到r之间的数字分别加上前r-l+1项fibonacci数列</br>
&emsp;&emsp;2.将l到r的数字和输出%1e9+9</br>
(n,m<=3*10^5,0<=l<=r<=n,a[i]<=10^9)
### Solution
SOL1:线段树/分块</br>
&emsp;&emsp;由于是区间修改区间查询,很容易就可以想到用线段树维护,但是由于区间修改并不是统一的值,难以直接维护</br>
这时候我们就需要主要到fibonacci数列的性质:任意位置任意长度的两个数列相加,所得的新数列依旧拥有fibonacci数列的性质,而设此时的前两项是a和b,则:</br>
&emsp;&emsp;1.now[n]=a\*f[n-2]+b\*f[n-1]</br>
&emsp;&emsp;2.sigma(now[i])=now[n+2]-b</br>
于是我们就可以只记录一段区间的和,a和b了,依旧可以在O(1)时间内求出其中任意前缀和和任意一项,于是问题就解决啦/////分块也是一个原理
---------------</br>
SOL2:二次剩余(数论)
&emsp;&emsp;不会,这个月是不可能会的,下个月都不可能会的(理直气壮//理不直气也壮)

```cpp
#include<cstdio>
#include<algorithm>
#include<cstring>
#define MOD 1000000009
#define ll long long
#define root 1,n,1
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
using namespace std;
struct tree{
	int f1,f2,sum;
}t[1200100];
int f[300010],sumf[300010],a[300010],n,m,l,r,type;
void build(int l,int r,int rt){
    t[rt].f1=t[rt].f2=0;
	if(l==r){
		t[rt].sum=a[l];
		return;
	}
	int m=(l+r)>>1;
	build(lson);
	build(rson);
	t[rt].sum=(t[rt<<1].sum+t[rt<<1|1].sum)%MOD;
}
int getf(int f1,int f2,int len){
	if(len==1)return f1;
	if(len==2)return f2;
	return (1ll*f1*f[len-2]+1ll*f2*f[len-1])%MOD;
}
int getsum(int f1,int f2,int len){
	return (getf(f1,f2,len+2)-f2+MOD)%MOD;
}
void pushdown(int l,int r,int rt){
	if(t[rt].f1){
		int ls=rt<<1,rs=rt<<1|1,m=(l+r)>>1;
		t[ls].f1=(t[ls].f1+t[rt].f1)%MOD;
		t[ls].f2=(t[ls].f2+t[rt].f2)%MOD;
		int x=getf(t[rt].f1,t[rt].f2,m-l+2),y=getf(t[rt].f1,t[rt].f2,m-l+3);
		t[rs].f1=(t[rs].f1+x)%MOD;
		t[rs].f2=(t[rs].f2+y)%MOD;
		t[ls].sum=(t[ls].sum+getsum(t[rt].f1,t[rt].f2,m-l+1))%MOD;
		t[rs].sum=(t[rs].sum+getsum(x,y,r-m))%MOD;
		t[rt].f1=t[rt].f2=0;
	}
}
void update(int l,int r,int rt,int x,int y){
	//printf("%d %d %d\n",l,r,rt);
	if(x<=l&&r<=y){
		t[rt].f1=(t[rt].f1+f[l-x+1])%MOD;
		t[rt].f2=(t[rt].f2+f[l-x+2])%MOD;
		t[rt].sum=(t[rt].sum+getsum(f[l-x+1],f[l-x+2],r-l+1))%MOD;
		return;
	}
	pushdown(l,r,rt);
	int m=(l+r)>>1;
	if(x<=m)update(l,m,rt<<1,x,y);
	if(y>m)update(m+1,r,rt<<1|1,x,y);
	t[rt].sum=(t[rt<<1].sum+t[rt<<1|1].sum)%MOD;
}
int query(int l,int r,int rt,int x,int y){
	if(x<=l&&r<=y){
		return t[rt].sum;
	}
	pushdown(l,r,rt);
	int m=(l+r)>>1,res=0;
	if(x<=m)res+=query(l,m,rt<<1,x,y);
	if(m<y)res+=query(m+1,r,rt<<1|1,x,y);
	return res%MOD;
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	f[1]=f[2]=1;
	for(int i=3;i<=n+10;i++)f[i]=(f[i-1]+f[i-2])%MOD;
	build(root);
	for(int i=1;i<=m;i++){
		scanf("%d%d%d",&type,&l,&r);
		if(type==1){
			update(root,l,r);
		}else{
			printf("%d\n",query(root,l,r));
		}
	}
	return 0;
}
```
