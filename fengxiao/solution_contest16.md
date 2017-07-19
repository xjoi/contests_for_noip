# Solution
```
/******************
    VJudge链接：  https://cn.vjudge.net/contest/171409
CodeForces链接：  http://codeforces.com/contest/614

题目按CF顺序排序
******************/
```
# #A Link/Cut Tree
```
/******************
     主要算法：~~Link/Cut Tree~~ 模拟
     Data limit:l, r and k (1 ≤ l ≤ r ≤ 1018, 2 ≤ k ≤ 109)
******************/
```
### 题意
给你区间[l,r] 给你k，求区间中k的所有幂次。
### 题解
直接扫一遍即可。
**坑：有可能会在乘的时候微微超过long long所以要把乘法移项变为除法做**
### 核心代码
```
/******************
if(l<=1) {printf("1 "); flag=1;}
	for(int i=1; num<=r/k;i++)
	{
		num*=k;
		if(num>=l){ printf("%I64d ",num);flag=1;}
	}
******************/
```
### 错题记录
上面那个特判没加 + 坑点。。。
***
# #B 	Gena's Code
```
/******************
    主要算法： 模拟
     Data limit: n (1 ≤ n ≤ 100 000）数字位数<=100000
******************/
```
### 题意
定义美丽数：十进制下只有一个1，其它都是0且不带前导0的数  
给你n个数，至少n-1个是美丽数，求它们的乘  

### 题解
很容易看出只要对于美丽数统计0的个数，对于非美丽数把它的前面部分输出就行了
**坑：由于可能有0所以要特判同时也不能直接输出非美丽数了**
### 核心代码
```
/******************

	for(i=1;i<=n;i++)
	{
		scanf("%s",tmp);
		int lt=strlen(tmp);
		if(lt==1 && tmp[0]=='0') {puts("0"); return 0;}
		for(j=lt-1;j>=0;j--)
			if(tmp[j]=='0')
				num++;
			else break;
		if(tmp[j]!='1' || j!=0) {for(int k=0;k<=j;k++) pr[k]=tmp[k]; sz=j; flag=1;}
	}
	if(!flag) printf("1"); else for(i=0;i<=sz;i++) printf("%c",pr[i]);
	for(i=1;i<=num;i++) printf("0");
}
******************/
```
### 错题记录
坑点。。
***
# #C 	Peter and Snow Blower
```
/******************
      主要算法：计算几何
     Data limit:n<=100000 num<=1000000
******************/
```
### 题意
给你一个多边形以及它所绕着旋转的点  
求多边形转360后扫过的面积  
### 题解
典型的计算几何，求出最小半径和最大半径而已  
**坑： 最短半径的点可能在线段上，而最大的一定在点上**
### 核心代码
```
/******************
#include<cstdio>  
#include<cstdlib>  
#include<cstring>  
#include<cmath>  
#include<algorithm>
using namespace std;
const double eps=1e-8,pi=acos(-1.0);
struct Poi{double x,y;}p[100010],sta[100010];
inline Poi poi(double x,double y) {Poi tmp; tmp.x=x; tmp.y=y; return tmp;}
struct Seg{Poi a,b;}s[100010];
inline Seg seg(Poi x,Poi y) {Seg tmp; tmp.a=x; tmp.b=y; return tmp;}
inline void swap(double &x,double &y) {double t=x; x=y; y=t;}
int sgn(double x){return x<-eps ? -1 : x>eps;} 
double cj(Poi p1,Poi p2,Poi p3){return (p3.x-p1.x)*(p2.y-p1.y)-(p3.y-p1.y)*(p2.x-p1.x);  }  
double dist(Poi a,Poi b){return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));  }  
bool cmp(Poi a,Poi b)
{  
    int tmp=sgn(cj(p[0],a,b));
    return tmp==0 ? dist(p[0],a)-dist(p[0],b)<=0 : tmp>0;  
}
Poi operator + (Poi a,Poi b) {return poi(a.x+b.x,a.y+b.y);}
Poi operator - (Poi a,Poi b) {return poi(a.x-b.x,a.y-b.y);}
double operator * (Poi a,Poi b) {return a.x*b.y-b.x*a.y;}
Poi operator * (Poi a,double t) {return poi(a.x*t,a.y*t);}
double dot(Poi a,Poi b) {return a.x*b.x+a.y*b.y;}
bool P_on_S(Poi p, Seg l) {return sgn((l.a-p)*(l.b-p)) == 0 && sgn(dot(l.a-p,l.b-p)) <= 0;}
bool intersect(Poi P,Poi v,Poi Q,Poi w,Poi &ret) 
{
    Poi u=P-Q;
    if(sgn(v*w)==0) return false;
    double t=w*u/(v*w);
    ret=P+v*t;
    return true;
}
bool disps(Poi p, Seg l,double &tmp)
{
    Poi vec = l.a - l.b; Poi pp;
    if(!intersect(p,poi(-vec.y,vec.x),l.a,vec,pp)) return false;
    if(!P_on_S(pp,l)) return false;
    tmp=dist(p,pp);
    return true;
}
int main()  
{  
    int T,i,cnt=0,n,r;  
    scanf("%d %lf %lf",&n,&p[0].x,&p[0].y);
    int pos=1;
    for(i=1;i<=n;i++)
	{  
        scanf("%lf %lf",&p[i].x,&p[i].y);
    }  
    for(i=1;i<n;i++) s[i]=seg(p[i],p[i+1]);
    s[n]=seg(p[1],p[n]);
    double midis=100000000.0,madis=0.0;
	for(i=1;i<=n;i++) {double tmp;/* printf("?%d?",disps(p[0],s[i],tmp));*/ if(disps(p[0],s[i],tmp) && tmp<midis) midis=tmp;}
	
	for(i=1;i<=n;i++) {double tmp=dist(p[i],p[0]);if(tmp>madis) madis=tmp; if(tmp<midis) midis=tmp;}//printf("!%lf %lf %lf!\n",midis,madis,tmp);
	//printf("#%lf %lf %lf %lf %lf#",dist(p[3],p[0]),p[0].x,p[0].y,p[3].x,p[3].y);
	double ans=pi*(madis+midis)*(madis-midis);
	printf("%.8lf",ans);
    return 0;  
}  
******************/
```
### 错题记录
mdzz题目看错还多求了个凸包，还好样例就错了
***
# #D Skills
```
/******************
      主要算法：二分+贪心
     Data limit: 1 ≤ n ≤ 100 000, 1 ≤ A ≤ 1e9, 0 ≤ cf, cm ≤ 1000, 0 ≤ m ≤ 1e15
******************/
```
### 题意
n表示数量，A表示上限，cf表示每个到A的可以加的分数，cm表示所有数中最小值可以加的分数：加分方法（数量/最小值）*cf/cm  ，m：有的钱数  
每个钱能让a【i】+1，求最大的加分值  

### 题解
讲a数组处理为A-原a[i]然后从小到大排序，根据贪心可得如果要填满一定要先把代价最小的填满  
如果要补最小的一定要从最小的补起  
于是可以枚举搞到几个A，然后处理能把最小值弄到多大，后面的过程需要两次二分  
### 核心代码
```
/******************
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#define int long long
#define N 100010
using namespace std;
int n,m,A,cf,cm;
struct P {int v,pos;} a[N];
int sum[N],sum1[N];
int ans,p,Num;
bool cmp(P a,P b) {return a.v<b.v;}
bool cmp1(P a,P b) {return a.pos<b.pos;}
bool judge(int x,int sum,int pos)
{
	int l=pos,r=n+1,mid;
	while(l<r)
	{
		mid=(l+r)>>1;
		if(a[mid].v>x) r=mid;
		else l=mid+1;
	}
	if(l==pos) l++;
	if(sum-(sum1[l]-(n-l+1)*x)>=0) return true;
	return false;
}
int calc(int x,int pos)
{
	int l=0,r=A+1;
	while(l<r)
	{
		int mid=(l+r)>>1;
		if(judge(mid,x,pos)) r=mid;
		else l=mid+1;
	}
	return l;
}
main()
{
	int i,j;
	//freopen("data.in","r",stdin);
	scanf("%I64d %I64d %I64d %I64d %I64d",&n,&A,&cf,&cm,&m);
	for(i=1;i<=n;i++) {scanf("%I64d",&a[i].v); a[i].v=A-a[i].v; a[i].pos=i;};
	sort(a+1,a+n+1,cmp);
	for(i=1;i<=n;i++) sum[i]=sum[i-1]+a[i].v;
	for(i=n;i>=1;i--) sum1[i]=sum1[i+1]+a[i].v;
	for(i=0;i<=n;i++)
		if(sum[i]<=m)
		{
			int num=calc(m-sum[i],i);
			int res=i*cf+(A-num)*cm;
			if(res>=ans){ans=res; p=i; Num=num; }
		}
		else break;
	printf("%I64d\n",ans);
	for(i=1;i<=p;i++) a[i].v=0;
	for(i=n;i>=1;i--) if(a[i].v>Num) {a[i].v=Num; } else break;
	sort(a+1,a+n+1,cmp1);
	for(i=1;i<=n;i++) printf("%I64d ",A-a[i].v);
	return 0;
}
******************/
```
### 错题记录
一秒出正解,二分害一生。。。

***
# #E 	Necklace
```
/******************
      主要算法：脑洞
     Data limit:  n (1 ≤ n ≤ 26) num<100000
******************/
```
### 题意
给你n，表示颜色种类
下面表示每种颜色的数量，将这一堆球串成项链，从任意处剖分，若串为回文，则ans++  
球如何排列ans的最大，输出ans及方案

### 题解
经过严（luan）密（gao）的证（fang）明（fa），可以归纳出：如果一个数列只有一个奇数，那么方案一定是1，于是可以求所有颜色的gcd，然后都除以它  
剩下的情况有如下几种1：剩下的就是上面所讲的情况，ans=1*gcd(all);  
                  2：剩下的不满足上述情况但gcd>1 ans=gcd(all)/2;  
                  3: 剩下的不满足上述情况且gcd=1 ans=0；  
                  
### 核心代码
```
/******************
scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	t=a[1]; for(int i=2;i<=n;i++) t=gcd(a[i],t);
	for(int i=1;i<=n;i++) {a[i]/=t; sum+=a[i]; if(a[i]&1) cnt++,tmp=i;}
	if(cnt!=1) 
	{
		if(t&1){puts("0");for(int i=1;i<=n;i++) for(int j=1;j<=a[i]*t;j++) printf("%c",i-1+'a'); return 0;}
		printf("%d\n",t); t/=2;for(int i=1;i<=26;i++) a[i]<<=1; sum<<=1;
	}
	if(sum&1)printf("%d\n",t);
	for(int i=1,j=sum,k=1;i<j;i++,j--) {while(a[k]<2) k++; b[i]=b[j]=k,a[k]-=2;}
	if(sum&1) b[sum/2+1]=tmp;
	for(int i=1;i<=t;i++)
		for(int j=1;j<=sum;j++)
		{
			char ch=b[j]+'a'-1;
			printf("%c",ch);
		}
******************/
```
###错题记录
上述的结果使用宝贵的正确率换的。。。
***
