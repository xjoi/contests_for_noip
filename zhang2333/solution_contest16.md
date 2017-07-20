## 比赛征程
> * Y : solved in the contest
> * A : solved after contest
> * W : solving

  \# |  A  |  B  |  C  |  D  |  E  |
---|---|---|---|---|---|
| contest17 |Y|Y|A|A|A|

[比赛链接](https://cn.vjudge.net/contest/171409#overview)

## A
### Problem description
> 略

### Data Limit：略  Time Limit: 略
### Solution
> 略

### Code
```cpp
#include<cstdio>
#include<iostream>
#define ll long long
using namespace std;
ll l,r,k;
bool f=0;

int main(){
	cin>>l>>r>>k;
	ll p=1;
	while (p<=r){
		if (p>=l){
			cout<<p<<' ';
			f=1;
		}
		p= p>r/k?r+1:p*k;
	}
	if (!f){
		printf("-1");
	}
}
```
*****

## B
### Problem description
> 略

### Data Limit：略  Time Limit: 略
### Solution
> 略

### Code
```cpp
#include<cstdio>
#include<iostream>
#include<cstring>
#include<string>
#define xxx 5202333
using namespace std;
int n,cnt,anl,l,flag=0;
char s[xxx],ans[xxx];

bool yes(){
	if (s[0]!='1') return 0;
	for (int i=1;i<l;i++)
		if (s[i]!='0')
			return 0;
	return 1;
}

void C(){
	l=strlen(s);
	if (l==1&&s[0]=='0'){
		flag=1;
		return;
	}
	if (yes()){
		cnt+=l-1;
	}else{
		anl=l;
		for (int i=0;i<l;i++)
			ans[i]=s[i];
	}
}

int main()
{
	scanf("%d",&n);
	anl=1;ans[0]='1';
	for (int i=1;i<=n;i++){
		scanf("%s",s);
		C();
	}
	if (flag){
		printf("0");
		return 0;
	}
	for (int i=0;i<anl;i++)
		printf("%c",ans[i]);
	for (int i=1;i<=cnt;i++)
		printf("0");
}
```
*****
## C
### Problem description
> 计算几何。。</br>

### Time Limit: 1s
### Solution
> 略。。</br>

### Code
```cpp
#include<cstdio>
#include<iostream>
#include<cmath>
#define xxx 520233
#define db double
#define eps 0.0000000001
using namespace std;
db r1,r2,pi=acos(-1);
int n;

struct P{
	db x,y;
}p[xxx],o;

struct L{
	db a,b,c;
};

db dispp(P p1,P p2){
	return sqrt(pow(p1.x-p2.x,2)+pow(p1.y-p2.y,2));
}

L GL(P p1,P p2){
	return (L){ p1.y-p2.y , p2.x-p1.x , p1.x*p2.y-p2.x*p1.y };
}

db displ(P pp,L ll){
	return abs(( ll.a*pp.x+ll.b*pp.y+ll.c )/sqrt(ll.a*ll.a+ll.b*ll.b));
}

db doit(P p3,P p1,P p2){
	if ( pow(dispp(p1,p3),2)+pow(dispp(p1,p2),2) <= pow(dispp(p2,p3),2)+eps ) return 52023333333333333333333333;
	if ( pow(dispp(p2,p3),2)+pow(dispp(p2,p1),2) <= pow(dispp(p1,p3),2)+eps ) return 52023333333333333333333333;
	//printf("  %.10lf\n",displ(p3,GL(p1,p2)));
	return displ(p3,GL(p1,p2));
}

int main()
{
	scanf("%d%lf%lf",&n,&o.x,&o.y);
	r1=5202333333333333333333;r2=0;
	for (int i=1;i<=n;i++){
		scanf("%lf%lf",&p[i].x,&p[i].y);
		r2=max(r2,dispp(o,p[i]));
		r1=min(r1,dispp(o,p[i]));
		if (i>1){
			r1=min(r1,doit(o,p[i-1],p[i]));
		}
	}
	r1=min(r1,doit(o,p[1],p[n]));
	printf("%.10lf",pi*(r2*r2-r1*r1));
}
```
*****
## D
### Problem description
> 略。。</br>

### Time Limit: 2s
### Solution
> 略。。</br>

### Code
```cpp
#include<cstdio>
#include<iostream>
#include<cmath>
#include<algorithm>
#define xxx 520233
#define ll long long
#define db double
#define xxx 100100
#define eps 0.0000000001
using namespace std;
ll n,top,k1,k2,m,b[xxx],c[xxx],s[xxx],las,p,low,ans=0,an,out[xxx],anlow,ancnt;
struct haha{
	ll v,pos;
}a[xxx];

bool cmp(haha a1,haha a2){
	return a1.v<a2.v;
}

int main()
{
	cin>>n>>top>>k1>>k2>>m;
	for (int i=1;i<=n;i++){
		scanf("%lld",&a[i].v);
		a[i].pos=i;
	}
	//printf("cvoainvsiodv\n");
	sort(a+1,a+n+1,cmp);
	
	b[n+1]=0;
	for (int i=n;i>0;i--)
		b[i]=b[i+1]+top-a[i].v;
	
	s[0]=0;
	for (int i=1;i<=n;i++){
		s[i]=s[i-1]+a[i].v;
		c[i]=a[i].v*i-s[i];
	}
	
	for (int i=0;i<=n;i++){
		las=m-b[n+1-i];
		if (las<0) break;
		if (i==n){
			low=top;
		}else{
			p=lower_bound(c+1,c+(n+1-i),las)-c;
			while (p>n-i||las<c[p]){p--;} 
			low=min(top,a[p].v+(las-c[p])/p);
		}
		an=k1*i+k2*low;
		if (an>ans){
			ans=an;
			anlow=low;
			ancnt=i;
		}
	}
	
	printf("%lld\n",ans);
	for (int i=1;i<=n;i++){
		out[a[i].pos]= i>n-ancnt?top:max(a[i].v,anlow);
	}
	for (int i=1;i<=n;i++)
		printf("%lld ",out[i]);
}
```
*****
## E
### Problem description
> 好题!!!。。</br>
  定义一个字母环的美丽值为切开这个环得到一个回文串的方法数。。</br>
  给出环上每种小写字母的个数(总数<=1e5),要求构造一个字母环,最大化美丽值。。</br>

### Time Limit: 2s
### Solution
> 结论题。。绝大多数情况都是gcd。。有多个奇数除外。。</br>
  
### Code
```cpp
#include<cstdio>
#include<iostream>
#include<cmath>
#include<algorithm>
#include<string>
#include<cstring>
#define xxx 233
#define ll long long
#define db double
using namespace std;
int n,a[xxx],b[xxx],t,tot=0,cnt=0;
string s,ans[2];

int gcd(int x,int y){
	if (!y) return x;
	return gcd(y,x%y);
}

int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		tot+=a[i];
	}
	t=a[1];
	for (int i=2;i<=n;i++){
		t=gcd(t,a[i]);
	}
	for (int i=1;i<=n;i++){
		b[i]=a[i]/t;
	}
	
	if (t%2){
		for (int i=1;i<=n;i++)
			cnt+=b[i]%2;
		if (cnt>1){
			printf("0\n");
			for (int i=1;i<=n;i++){
				for (int j=1;j<=a[i];j++)
					printf("%c",'a'-1+i);
			}
		}else{
			printf("%d\n",t);
			for (int i=1;i<=n;i++){
				for (int j=1;j<=b[i]/2;j++)
					s+=(char)('a'-1+i);
			}
			for (int i=1;i<=n;i++){
				for (int j=1;j<=b[i]%2;j++)
					s+=(char)('a'-1+i);
			}
			for (int i=n;i>0;i--){
				for (int j=1;j<=b[i]/2;j++)
					s+=(char)('a'-1+i);
			}
			for (int i=1;i<=t;i++)
				cout<<s;
		}
	}else{
		printf("%d\n",t);
		s="";
		for (int i=1;i<=n;i++){
			for (int j=1;j<=b[i];j++)
				s+=(char)('a'-1+i);
		}
		ans[1]=s;
		for (int i=s.length()-1;i>=0;i--)
			ans[0]+=s[i];
		for (int i=1;i<=t;i++)
			cout<<ans[i%2];
	}
}
```
*****
