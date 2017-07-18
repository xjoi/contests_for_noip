
## 数列
### Problem Description
> 给出一个长度为n的数列，求出有多少个区间，使得区间和能被k整除。每个测试点有T组数据
### Data limit:1<=T<=20,1<=N<=50000,1<=K<=1000000,序列的每个数<=1000000000 Time limit: 1s
### Solution
考虑数列前缀和S。区间[i,j]和能被k整除相当于S[j]-S[i-1]能被k整除，即S[j]和S[i-1]模k同余。

所以可以维护一个数组M[i]，记录前缀和%k为i的数量。则只需要在扫描时加上之前的M[i]即可。

###Code
```cpp
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;

int A[100001];
int mod[1000001];
int n,k,T;
int main(){
	scanf("%d",&T);
	while(T--){
		memset(mod,0,sizeof(int)*k);
		mod[0]=1;
		scanf("%d%d",&k,&n);
		int Ans=0,s=0;
		for (int i=1;i<=n;i++) {
			int a;
			scanf("%d",&a);
			a%=k;
			s=(a+s)%k;
			Ans+=mod[s]++;
		}
		printf("%d\n",Ans);
	}
}
```

## 钓鱼
### Problem Description
> 给出直角坐标系，作为池塘。其中有鱼(长度为L)会从D时刻开始从左到右（或从右到左）移动。
从0时刻开始，每一个单位时间，你可以钓鱼（设当前位置为z，将鱼看成一条线段，当线段与直线x=z相交时就认为鱼上钩了），或者向左或向右移动最多Q个单位长度。求在T时间内，最多能抓到多少鱼。

### Data limit:1<=T,time<=10，1<=Ax,Ay,Q,x,y,D,L<=10，1<=N<=14 Time limit :1s

### Solution

直接搜索（事实上，这个数据连记忆化都不需要）。预处理好每秒鱼的位置即可。

### Code
```cpp	
	#include <iostream>
	#include <cstdio>
	#include <cstring>
	#include <cmath>
	#include <algorithm>
	using namespace std;
	
	int n,ans=0,t,maxx,maxy,Ax,Q;;
	struct fish{
		int x,y,d,l,tm;
	}F[20];
	int posi[20][15];
	bool caught[20];
	void dfs(int pos,int tme,int tot_caught){
		if (tme>t){
			ans=max(ans,tot_caught);
			return;
		}
		bool tmp[20];
		memcpy(tmp,caught,sizeof (caught));
		int tmpf=tot_caught;
		for (int i=1;i<=n;i++){
			if (caught[i]) continue;
			//if (posi[i][tme]<0||posi[i][tme]>maxx) continue;		
			if (pos>=min(posi[i][tme],posi[i][tme]+F[i].l)&&pos<=max(posi[i][tme],posi[i][tme]+F[i].l)){
				caught[i]=1;
				tmpf++;
			}
		}
		dfs(pos,tme+1,tmpf);
		memcpy(caught,tmp,sizeof(tmp));
		//moving
		for (int i=-Q;i<=Q;i++){
			if (pos+i<0||pos+i>maxx) continue; 
			dfs(pos+i,tme+1,tot_caught);
		}
		
	}
	int main(){
		scanf("%d%d%d%d%d%d",&t,&maxx,&maxy,&Ax,&Q,&n);
		for (int i=1;i<=n;i++){
			scanf("%d%d%d%d%d",&F[i].x,&F[i].y,&F[i].d,&F[i].l,&F[i].tm);
			if (F[i].x==maxx) F[i].d=-F[i].d;else F[i].l=-F[i].l;
			posi[i][F[i].tm]=F[i].x;
		}
		for (int i=1;i<=n;i++){
			for (int j=0;j<F[i].tm;j++){
				posi[i][j]=-100;
			}
			for (int j=F[i].tm+1;j<=t;j++){
				posi[i][j]=posi[i][j-1]+F[i].d;
			}
		}
		dfs(Ax,0,0);
		printf("%d",ans);
	}
```
## 雪
### Problem Description
> 有n个首尾相连，对称轴在y轴上的等腰三角形组成的树。与x轴的夹角为a的平行光线能照亮多少长度的树。

### Data limit:0<a<pi，每个等腰三角形底边A满足0<A<1000,A为实数，顶角B满足0<B<pi，1<=N<=1000000 Time limit :2s

### Solution
可以用三角函数解决.（或者用解析法）

首先预处理：若a>90°（π/2),说明光线从左侧打来，可以将a变成π-a，使它从右边打来。同时，求出各等腰三角形的高(h)和腰长(L)。

先考虑右半侧:设前面被挡住的光线在x轴上形成的“投影"长度为tx，则由正弦定理求得腰上无法照到的长度l=tx\*sin*a*/sin(90°+b-a)(如图1）。
若l>L说明整个三角形都处在阴影当中，则更新tx=tx-h/tan*a*.(如图2）
反之，则只有部分三角形处于阴影中，则被照到的部分为L-l。则更新tx=底边长/2.（如图3）

考虑左半侧，方法类似（如图4）（注意tx变化时的加减），但唯一和右侧不同的是，有可能l求出来为负的（也就是a+b<90°）的情况，这时，tx需要加上h/tan*a*.（如图5）

![Figure](https://raw.githubusercontent.com/jhdjames37/contests_for_noip/master/jhd/Figure_ProblemC.JPG)

另外，注意精度问题。【%f输出竟然是四舍五入的！】

### Code
``` cpp
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;
const double pi=acos(-1);
const int maxn=1000001;
const double eps=1e-3;

double a;
int n;
double A[maxn],B[maxn],H[maxn],L[maxn];
int main(){
	scanf("%lf",&a);
	scanf("%d",&n);
	if (a>pi/2) a=pi-a;
	double toth=0;
	for (int i=1;i<=n;i++){
		scanf("%lf%lf",&A[i],&B[i]);
		A[i]/=2;B[i]/=2;
		H[i]=A[i]/tan(B[i]);
		L[i]=A[i]/sin(B[i]);
		toth+=H[i];
	}
	double topy=toth,topx=0,ans=0;
	for (int i=1;i<=n;i++){
		double c=pi/2+B[i]-a;
		double l=topx*sin(a)/sin(c);
		if (l>=L[i]){
			topx-=H[i]/tan(a);
			continue;
		}else{
			ans+=L[i]-l;
			topx=A[i];
		}
		
	}
	topx=0;
	for (int i=1;i<=n;i++){
		double c=a+B[i]-pi/2;
		if (c<=0){
			if (abs(c)<1e-10&&abs(topx)<1e-10){
				ans+=L[i];topx=A[i];continue;
			}
			topx+=H[i]*tan(B[i]-c);
		}else{
			double l=topx*sin(pi-a)/sin(c);
			if (l>=L[i]){
				topx+=H[i]/tan(a);
			}else{
				ans+=L[i]-l;
				topx=A[i];
			}
		}
		
		
	}
	printf("%.1lf",ans+eps);
}
```

## 键盘
### Problem Description
> 已知用五只手指按键的疲劳度分别为a,b,c,d,e.更换键盘的按键位置（但按键手指不改变），使得对于一个给定的字符串按键的疲劳度总和最小。

### Data Limit:0<=a,b,c,d,e<=100 1<=N（字符串长度）<=1000000 Time Limit:1s

### Solution
贪心。按字符出现次数排序，次数最多的就安排在疲劳度最少的手指上。注意每只手指管的按键数是有限制的。

### Code
``` cpp

#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;

int freq[256];
int n;
struct keys{
	int q,k;
}A[6];
bool cmp2(keys a,keys b){
	return a.q<b.q;
}
string s;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	for (int i=1;i<=5;i++){
		scanf("%d",&A[i].q);
	}
	A[1].k=1;A[2].k=16;A[3].k=8;A[4].k=8;A[5].k=15;
	scanf("%d",&n);
	getline(cin,s);
	getline(cin,s);
	for (int i=0;i<n;i++){
		freq[s[i]]++;
	}
	sort(freq,freq+256,cmp);
	sort(A+1,A+6,cmp2);
	int used=0,cur=1,ans=0;
	for (int i=0;freq[i];i++){
		if (used==A[cur].k){
			used=1;cur++;ans+=A[cur].q*freq[i];
		}else{
			used++;ans+=A[cur].q*freq[i];
		}
	}
	printf("%d",ans);
}
```


