## A-L/C T
>Time limit
    2000 ms
Memory limit
    262144 kB
Tags
   > brute force
  
  ### 题意 给定$ l,r,t$ 求在$ l<=x<=r $ 的范围之内，t的幂是多少。
  ### 题解 我们写一个高精度，模拟即可
  还可以判断位数，或者放缩而不采用高精度来做
```cpp
cin>>l>>r>>k;
		bign  num=1;
		for(int i=1;;i++)
		{
			if(num>r) break;
			if(l<=num&&num<=r)cout<<num,cout<<" ",ok=1;
			num=num*k;
		}
	if(!ok){cout<<"-1\n";} 
```
## B- Gena's Code
>Time limit
    500 ms
Memory limit
    262144 kB
Source
    Codeforces Round #339 (Div. 2)
>Tags
   > implementation
### 题意：给定若干个串，定义x为完美当且仅当只有一个1出现，求不完美的串的作为前导输出以及完美的0输出
### 题解：根据题意模拟，判断几个特殊情况 数字是0，全部是完美
```cpp
cin>>n;
	for(int i=1;i<=n;i++)
	{
		int num=0;
		scanf("%s",str);
		int len=strlen(str);
		if(str[0]=='0'){cout<<"0\n";return 0;}
		if(str[0]!='1') num=1;
		for(int j=1;j<len;j++)
			if(str[j]!='0') num=1;
		if(num) 
		{
			for(int j=0;j<len;j++)
				{s[j]=str[j];}
			
		}
		else ans+=len-1;
		str[len]=0;
	}
	
	if(strlen(s)==0) printf("1");
	else printf("%s",s);for(int i=1;i<=ans;i++) printf("0");
```
## C-  Peter and Snow Blower 
>Time limit
    2000 ms
Memory limit
    262144 kB
>Tags
   > math and BF

  ### 给定一个多边形，求多边形绕定点扫过的面积。
  ### 首先我们可以知道$ S=(R^{2}-r^{2})*\pi $然后问题就是求出$R$ 和$r$ $R$就是最远的距离，而$r$ 是有两种情况，在顶点上，或者在边上，都进行讨论就可以了。这个点非常的坑

 ```cpp
  #pragma GCC optimize("O2")
#include<bits/stdc++.h>
using namespace std;
const double eps=1e-9,pi=4*atan(1);
struct Point
{
    double x,y;
    Point(){}
    Point(double _x,double _y){x=_x,y=_y;}
};
typedef Point Vector ;
Vector operator - (Point a,Point b){return Point(a.x-b.x,a.y-b.y);}
int dcmp(double x){if(fabs(x)<eps) return 0;else return x>0?1:-1;}
double Cross(Vector a,Vector b){return a.x*b.y-a.y*b.x;}
double Dot(Vector a,Vector b){return a.x*b.x+a.y*b.y;}
double dist(Point a,Point b){return sqrt(Dot(a-b,a-b));}
double Length(Vector a){return sqrt(Dot(a,a));}
double dis2(Point p,Point a,Point b)
{
	if(dcmp(a.x-b.x)==0&&dcmp(a.y-b.y)==0) return Length(p-a);
	Point v1=b-a,v2=p-a,v3=p-b;
	if(dcmp(Dot(v1,v2))<0) return Length(v2);
	else if(dcmp(Dot(v1,v3)>0)) return Length(v3);
	else return fabs(Cross(v1,v2))/Length(v1);
}
Point p[200000],s;
int n;double Min=1e15,Max=0;
int main()
{
    scanf("%d%lf%lf",&n,&s.x,&s.y);
    for(int i=1;i<=n;i++)
    	scanf("%lf%lf",&p[i].x,&p[i].y),Max=max(Max,dist(s,p[i]));
    Min=Max;
    for(int i=2;i<=n;i++)
		Min=min(Min,dis2(s,p[i-1],p[i]));
	Min=min(Min,dis2(s,p[1],p[n]));
	printf("%.8f\n",(Max*Max-Min*Min)*pi);
    return 0;
}

```
## D-   Skills 
>Time limit
    2000 ms
Memory limit
    262144 kB
>Tags
   > binary search and BF
### 题意，给定一串数字，评分有两类，一是满等级有分，二是以最小的等级来求，最大化评分
### 题解，我们对数字先进行排序，然后枚举满的等级出现的位置，二分最大的满足要求的最小等级，二分最小等级出现的位置，判断是否满足题意就行了
```cpp
#include<bits/stdc++.h>
#define XY 100100
#define ll long long
using namespace std;
struct P{int id,w;};
P a[XY];
int b[XY],q[XY];
ll sum[XY],n,A,w1,w2,res,ans=-1,pl,py;
bool cmp1(P a,P b){return a.w<b.w;}

main()
{
	cin>>n>>A>>w1>>w2>>res;
	for(int i=1;i<=n;i++) scanf("%d",&a[i].w),a[i].id=i,q[i]=a[i].w;
	sort(a+1,a+n+1,cmp1);
	for(int i=1;i<=n;i++) b[i]=a[i].w,sum[i]=sum[i-1]+a[i].w;
	for(int i=n;i>=0;i--)
	{
		ll lef=res-(A*(n-i)-(sum[n]-sum[i]));
		if(lef<0) break;
		ll l=0,r=A;
		while(l<r)
		{
			ll mid=(r+l+1)/2;
			int x=lower_bound(b+1,b+i+1,mid)-b-1;
			if(mid*x-sum[x]<=lef) l=mid;
			else r=mid-1;
		}
		if(l*w2+w1*(n-i)>ans)
			ans=l*w2+w1*(n-i),pl=l,py=i;
	}
	cout<<ans<<"\n";
	for(int i=1;i<=n;i++) if(q[i]<pl) q[i]=pl;
	for(int i=n;i>py;i--) q[a[i].id]=A;
	for(int i=1;i<=n;i++)
		printf("%d ",q[i]);
	return 0;
}
```

## E-  Necklace 
>Time limit
    2000 ms
Memory limit
    262144 kB
>Tags
   > structure
### 题意：给定每个字母的出现顺序，求一个满足要求的串，使得在环形的串上切割生成回文串的方案数最多
### 题解:我们发现，构造出来的串有如下中情况
>1.有多于1个奇数次数的字母出现，显然是无解
>2.有恰好1个奇数字数的字母出现，我们将这个字母放在中间，其他进行回文串的排列就可以了
>3.没有奇数次数的字母出现，那就正反反正的排序就可以了
### 我们还需要要求出有多少这样的序列，我们取gcd所有的值就是答案了
```cpp
#include<bits/stdc++.h>
using namespace std;
int n;
int s[200],t,odd,ans=0;
int gcd(int a,int b){return b==0?a:gcd(b,a%b);}
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>s[i];
		if(s[i]&1) t=i,odd++;
	}
	if(odd>1)
	{
		printf("0\n");
		for(int i=1;i<=n;i++)
			for(int j=1;j<=s[i];j++)
				printf("%c",i+'a'-1);
		
	}
	else if(odd==1)
	{
		for(int i=1;i<=n;i++)
			ans= (i==t)?gcd(s[i],ans):gcd(s[i]/2,ans);
		printf("%d\n",ans);
		for(int k=1;k<=ans;k++)
		{
			for(int i=1;i<=n;i++)
				for(int j=1;j<=s[i]/ans/2;j++)
					printf("%c",i+'a'-1);
			printf("%c",t+'a'-1);
			for(int i=n;i>=1;i--)
				for(int j=1;j<=s[i]/ans/2;j++)
					printf("%c",i+'a'-1);
		}
	}
	else
	{
		for(int i=1;i<=n;i++)
			ans= gcd(s[i],ans);
		printf("%d\n",ans);
		for(int k=1;k<=ans/2;k++)
		{
			for(int i=1;i<=n;i++)
				for(int j=1;j<=s[i]/ans;j++)
					printf("%c",i+'a'-1);
			for(int i=n;i>=1;i--)
				for(int j=1;j<=s[i]/ans;j++)
					printf("%c",i+'a'-1);
		}
	}
}
```
