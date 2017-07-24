[比赛链接]（http://codeforces.com/contest/260）

# 比赛中解决的问题
## A
### Problem description
> 给定a,b,n,求是否能在a后进行n次操作（在原数最后添加一位数字，使得新数能被b整除）

### Data Limit：a,b,n <= 1e5  Time Limit: 2s
### Solution
> 先枚举第一次添加的情况，如果没有符合的则输出-1，否则输出找到的符合的数

> 之后输出（n-1）个0，因为如果a整除b，则a*10整除b

### Code
```cpp
using namespace std;
int main(){
	int a,b,n; cin.tie(0);
	cin>>a>>b>>n; 
	bool bo=0;
	int i;
	for (i=0;i<=9;++i)
		if ((a*10+i)%b==0) {
			bo=1; break;
		}
	if (!bo){
		cout<<-1; return 0;
	} 
	cout<<a<<i;
	for (int i=2;i<=n;++i){
		cout<<0;
	}
}
```
*****


## B
### Problem description
> 判断一个字符串中，出现次数最多的日期，形式为"dd-mm-yyyy"

### Data Limit：str.length() <= 1e5  Time Limit: 1s
### Solution
> 循环每一位，往后找10位，判断此串是否符合题目形式。如果符合，则储存下它所代表的日期

### Code
```cpp
#include<bits/stdc++.h>
using namespace std;
const int d[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
string ans[1000010];
int a[40000000],b[1000000];
int main(){
	string str;
	int ma=0,tot=0,t=0,an=0;
	cin.tie(0); cin>>str;
	for (int i=2;i<str.length()-6;++i)
		if (str[i]=='-'&&str[i+3]=='-'&&str[i-1]!='-'&&str[i+1]!='-'&&str[i+7]!='-'&&str[i+2]!='-'&&str[i-2]!='-'){
			tot++;
			for (int j=i-2;j<=i+7;++j)
				ans[tot]+=str[j];
		}
	for (int i=1;i<=tot;++i){
		int sum1,sum2,sum3;
		sum1=(ans[i][0]-'0')*10+(ans[i][1]-'0');
		sum2=(ans[i][3]-'0')*10+(ans[i][4]-'0');
		sum3=(ans[i][6]-'0')*1000+(ans[i][7]-'0')*100+(ans[i][8]-'0')*10+(ans[i][9]-'0');
		if (sum1>d[sum2]) continue;
		if (sum3<2013||sum3>2015) continue;
		if (sum1<=0) continue;
		a[sum3*10000+sum2*100+sum1]++;
		b[++t]=sum3*10000+sum2*100+sum1;
	}
	for (int i=1;i<=t;++i){
		if (a[b[i]]>ma) ma=a[b[i]],an=b[i];
	}
	if (an%100<10) cout<<0<<an%100<<'-'; else cout<<an%100<<'-';
	if (an/100%100<10) cout<<0<<an/100%100<<'-'; else cout<<an/100%100<<'-';
	cout<<an/10000;
}
```
*****

## C
### Problem description
> n个盒子，取其中一个盒子i，把i的球全拿出来，从i+1开始循环给后面一个盒子一个球，直到给完为止。给你给完后的序列和最后一个球放的位置，求原序列

### Data Limit：n <= 1e5 && x <= 1e9  Time Limit: 1s

### Solution
> 找到最小值，然后模拟放球的过程，倒推答案

### Code
```cpp
using namespace std;
long long int n, x, a[100007], mini=1e9+1, u;
int main(){
   cin >> n >> x; x--;
   for(int i = 0; i<n; i++) cin >> a[i], mini = min(mini, a[i]);
   for(int i = 0; i<n; i++) a[i]-=mini;
   while (a[x]) {
     u++; a[x]--; x--;
     if(x<0)x=n-1;
   }
   a[x]+=n*mini+u;
   for(int i = 0; i<n; i++) cout << a[i] << " ";
}
```
*****


## D
### Problem description
> 已知有一棵树，给定每一个点的颜色（黑，白）和所有边权和，求树上的边和边权（边两端点颜色要求不同）

### Data Limit：n <= 1e5 && s[i] <= 1e9   Time Limit: 1s
### Solution
> 贪心：按颜色分成两个数组，然后根据边权和排序，然后从小到大依次取出两个点，并为一条边

### Code
```cpp
struct xint{
	int x,num;
}a[100010],b[100010];
bool cmp(xint x,xint y){
	return x.x<y.x;
}
bool bo[100010];
int t1=0,t2=0;
int main(){
	int n; cin.tie(0);
	cin>>n;
	for (int i=1;i<=n;++i){
		int x,y; cin>>x>>y;
		if (x==0) a[++t1].x=y,a[t1].num=i; 
			else b[++t2].x=y,b[t2].num=i;
	}
	sort(a+1,a+t1+1,cmp);
	sort(b+1,b+t2+1,cmp);
	int i=1,j=1;
	while (i<=t1&&j<=t2){
		cout<<a[i].num<<" "<<b[j].num<<" "<<min(a[i].x,b[j].x)<<endl;
		int x=min(a[i].x,b[j].x);
		a[i].x-=x;b[j].x-=x;
		if (a[i].x) j++; 
			else if (b[j].x) i++;
				else {if (i<t1) i++; else j++;}
	}
}
```
*****


# 赛后补题

## E
### Problem description
> 

### Data Limit：n <= 1e5  Time Limit: 1s

### Solution
> 

### Code
```cpp
```
