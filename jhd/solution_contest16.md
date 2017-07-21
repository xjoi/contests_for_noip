

[Contest 16--比赛链接](https://cn.vjudge.net/contest/171409)

# 比赛中解决的问题
## A - Link/Cut Tree
### Problem description
> 求出在`[l,r]`范围内,有多少个k的若干次幂.

### Data Limit：1 ≤ l ≤ r ≤ 10^18, 2 ≤ k ≤ 10^9  Time Limit: 2s
### Solution
> 暴力枚举k^i.但是**注意数据范围**.(for循环跳出的那一次有可能会爆(unsigned) long long)

### Code
```cpp
int main(){
	LL l,r,k;
	cin>>l>>r>>k;
	bool flag=1;
	for (LL i=1;i<=r;i*=k){
		if (i>=l) cout<<i<<" ",flag=0; 
		if (double(i)*double(k)-double(r)>eps) break;	//使用double估算.另外也可以比较i和r/k
	}
	if (flag) cout<<"-1";
}
```
*****


## B - Gena's Code
### Problem description
> 有n个数.其中至少有(n-1)个数满足各数位上至多有一个1,其余位上为0(称为美丽数). 求出所有n个数的乘积.

### Data Limit：n <= 1e5,各数的数位总和不超过10^5  Time Limit: 0.5s
### Solution
> 审题后会发现答案为*不是美丽数的那个数*后面跟*其余美丽数的0的总和*个0.

> 但是有两个细节(今天的题好多坑!!):
> 
> 1.有可能不存在美丽数,这时要输出1000...0;
> 
> 2.美丽数也包括0.

### Code
```cpp
char s[100001];
char beauty[100001];
int main(){
	int n;
	scanf("%d",&n);
	int Ans=0;
	bool have_b=0;
	for (int i=1;i<=n;i++){
		scanf("%s",s);
		int len=strlen(s);
		bool is_beauty=0;
		if (len==1&&s[0]=='0'){
			printf("0");return 0;	//特判美丽数为0的情况
		}
		if (s[0]!='1') is_beauty=1;
		for (int j=1;j<len;j++){
			if (s[j]!='0') is_beauty=1;	
		}
		if (is_beauty) have_b=1,memcpy(beauty,s,sizeof s);
		else Ans+=len-1;
	}
	if (have_b)printf("%s",beauty); else printf("1");//注意没有美丽数的情况
	while(Ans--) printf("0");
}

```
*****



## C
### Problem description
> 给出一个n边形,将其绕一个给定的中心(不在多边形内)旋转,求出多边形扫过的面积.

### Data Limit：n <= 1e5 , |x|,|y|<=1e6且x,y为整数 Time Limit: 2s

### Solution
> 显然,扫过的面积为圆环,则我们要求出R,r.

> R很显然,为到离圆心最远的点的距离.r则有两种取值:离圆心最近的点,或最近的边(其实就是圆心到各边最短距离的最小值).

### Code
```cpp

struct point{
	double x,y;
	point(double x=0,double y=0):x(x),y(y){}
}P0,P[100001];
struct segment{
	point A,B;
	segment(point A,point B):A(A),B(B){}
};
double dist(point A,point B){
	return sqrt(sqr(A.x-B.x)+sqr(A.y-B.y));
}
double cross(point A,point B,point C){
	return (B.x-A.x)*(C.y-A.y)-(B.y-A.y)*(C.x-A.x);
}
double dist(segment l,point C){
	double cr=cross(C,l.A,l.B);
	return fabs(cr)/dist(l.A,l.B);
}
int n;
int main(){
	int x,y;
	scanf("%d%d%d",&n,&x,&y);
	P0=point(x,y);
	double minR=1e18,maxR=0;
	for (int i=1;i<=n;i++){
		scanf("%d%d",&x,&y);
		double tmp=dist(P0,P[i]=point(x,y));
		minR=min(tmp,minR);
		maxR=max(tmp,maxR);
	}
	for (int i=1;i<=n;i++){
		segment l(P[i],P[i%n+1]);
		double a=dist(l.B,P0),b=dist(l.A,P0),c=dist(l.A,l.B);
		double alpha=(acos((sqr(b)+sqr(c)-sqr(a))/(2*c*b))),
		       beta=acos((sqr(c)+sqr(a)-sqr(b))/(2*a*c));	//使用余弦定理来判锐角,如果想更方便,可以用a^2+b^2<c^2
		if (alpha-pi/2<-eps&&beta-pi/2<-eps){		//判定高是否在线段上
			double tmp=dist(l,P0);
			minR=min(tmp,minR);
			//maxR=max(tmp,maxR);
		}
		
	}
	printf("%.18f",pi*(sqr(maxR)-sqr(minR)));
}

```
*****

# 赛后补题
## D
### Problem description
> 给出n个数a[1..n],每一个数可以加上一个数,但结果不能超过A,且加上的数的总和不得超过m.设最终的数组中有cnt个A,这些数的最小值为min,求(cnt\*cf+min\*cm)(cf,cm已知)的最大值.

### Data Limit：n <= 1e5,A<=1e9,cf,cm<=1000,m<=1e15  Time Limit: 1s
### Solution
> 枚举+适当的二分(也可以不二分).

> 实现方式很多,我的想法:
> 先从大到小排序,枚举有多少个数为A,(显然是从最大的开始加),然后二分算出最大的min.
> 
> 二分的具体过程:先预处理出最后k个数都变成min的最小代价,二分求出最多能让多少个数变成min(这样就可以保证min最大),再求出最大的min.
> 
> 同样是道细节题.注意数据范围(要开int还是long long),特判所有数都为A,二分不能分到前面为A的数上.

### Code
```cpp
struct sy{
	int a,d,id;
	sy(int a=0,int d=0,int id=0):a(a),d(d),id(id){}
}a[100001],best[100001];
LL cost[100001];
int n,A,cf,cm;LL m;
bool cmp(sy x,sy y){
	return x.a>y.a;
}
bool cmp2(sy x,sy y){
	return x.id<y.id;
}
LL findcost(int L,LL price,int &pos,int& mini){
	int l=L,r=n;
	while(l<r){
		int mid=(l+r)>>1;
		if (cost[mid]>price) l=mid+1;else r=mid;
	}
	while(cost[l]<=price&&l>=L) l--;
	pos=++l;mini=min(A,int(a[l].a+(price-cost[l])/(n-l+1)));  //算出min
	return (1ll*mini*cm);
}
int main(){
	scanf("%d%d%d%d%I64d",&n,&A,&cf,&cm,&m);
	int t;
	LL qqq=0;
	for (int i=1;i<=n;i++) scanf("%d",&t),a[i]=sy(t,t,i),qqq+=A-t;
	if (qqq<=m){
		printf("%I64d\n",1ll*cf*n+1ll*cm*A);
		for (int i=1;i<=n;i++) printf("%d ",A);
		return 0;
	}
	sort(a+1,a+n+1,cmp);
	cost[n]=0;
	for (int i=n-1;i>0;i--) cost[i]=cost[i+1]+(a[i].a-a[i+1].a)*(n-i);
	int Ptm=n,mim;LL Ans=findcost(1,m,Ptm,mim),tmp=m;
	int Atm=0;
	for (int i=1;i<=n;i++){
		tmp-=(A-a[i].a);
		if (tmp<0) break;
		int k,q;
		LL b=i*cf+findcost(i+1,tmp,k,q);
		if (b>Ans) Atm=i,Ans=b,Ptm=k,mim=q;
	}
	int Tmp=m;
	for (int i=1;i<=Atm;i++) Tmp-=A-a[i].a,a[i].a=A;
	for (int i=Ptm;i<=n;i++) a[i].a=mim;
	sort(a+1,a+n+1,cmp2);
	printf("%I64d\n",Ans);
	for (int i=1;i<=n;i++) printf("%d ",a[i].a);
	
}
```
*****

## E
### Problem description
> 给出n个字母,每个字母有A[i]个.将它们排成一圈,求从任意一处断开,所能得到的回文串数量和的最大值.

### Data Limit：1 ≤ n ≤ 26, 2 ≤ A[i] ≤100000  Time Limit: 2s

### Solution
> 分类讨论.
> 
> 1. 若A[i]有两个(或以上)值为奇数,则显然不存在.
> 2. 若A[i]只有1个奇数,则回文串数量ans=gcd(A[1],..,A[n])(显然为奇数).因为可以将每一个字母分成ans份.每一份都可以构成一个回文串.将它们并起来自然就可以构成ans个回文串
> 3. 若A[i]全为偶数,答案为ans=gcd(A[1],..,A[n])(显然为偶数).分成ans/2份,将每一份构成回文串,并起来就可以构成ans个回文串

### Code
```cpp
int A[30];
int gcd(int a,int b){
	return b==0?a:gcd(b,a%b);
}
int main(){
	int n;
	scanf("%d",&n);
	int sig=0;
	for (int i=1;i<=n;i++) scanf("%d",&A[i]),sig+=A[i]&1;
	if (n==1) {
		printf("%d\n",A[1]);
		for (int i=1;i<=A[1];i++) printf("a");
		return 0;
	}
	if (sig>1){
		printf("0\n");
		for (int i=1;i<=n;i++){
			for (int j=1;j<=A[i];j++){
				printf("%c",i-1+'a');
			}
		}
	}else if (sig==1){
		int x=0;
		for (int i=1;i<=n;i++){
			x=gcd(x,A[i]);
		}
		printf("%d\n",x);
		for (int ii=1;ii<=x;ii++){	
			int pc=0;
			for (int i=1;i<=n;i++){
				if (A[i]&1) pc=i;
				for (int j=1;j<=A[i]/x/2;j++){
					printf("%c",i-1+'a');
				}
			}
			printf("%c",pc-1+'a');
			for (int i=n;i>=1;i--){
				for (int j=1;j<=A[i]/x/2;j++){
					printf("%c",i-1+'a');
				}
			}
		}
	}else{
		int x=0;
		for (int i=1;i<=n;i++){
			x=gcd(x,A[i]);
		}
		printf("%d\n",x);
		int t=x/2;
		for (int ii=1;ii<=t;ii++){
			for (int i=1;i<=n;i++){
				for (int j=1;j<=A[i]/x;j++){
					printf("%c",i-1+'a');
				}
			}
			for (int i=n;i>=1;i--){
				for (int j=1;j<=A[i]/x;j++){
					printf("%c",i-1+'a');
				}
			}
		}
	}		
}
```