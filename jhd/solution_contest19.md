

[Contest 19-比赛链接](https://cn.vjudge.net/contest/172423)

# 比赛中解决的问题
## A - Adding Digits
### Problem description
> 给出两个数字a,b.要求进行n次操作,每次操作在a的末尾添加一个一位数,使得其能被b整除.输出n次操作后,a的一种可能形式,如果无解,输出-1.

### Data Limit：1 ≤ a, b, n ≤ 10^5  Time Limit: 2s
### Solution
> 每次枚举0..9的数字加到末尾,看是否能被b整除,如果都不行,输出-1.
> 
> (其实第二次之后就只需要输出同一个数就行了.)

### Code
```cpp
int q[100001];
int main(){
	int a,b,n;
	scanf("%d%d%d",&a,&b,&n);
	int k=a%b;
	for (int i=1;i<=n;i++){
		bool flag=0;
		for (int j=0;j<=9;j++){
			if ((k*10+j)%b==0){
				k=0;
				q[i]=j;
				flag=1;
				break;
			}
		}
		if (!flag){
			printf("-1");
			return 0;
		}
	}
	printf("%d",a);
	for (int i=1;i<=n;i++){
		printf("%d",q[i]);
	}
}
```
*****


## B - Ancient Prophesy 
### Problem description
> 给出一个由数字和`-`组成的字符串,在其中找出出现次数最多的合法的日期(日期格式dd-mm-yyyy,**年份在2013~2015之间**),并按照**dd-mm-yyyy的格式(存在前导0)**输出.

### Data Limit：len <= 1e5  Time Limit: 1s
### Solution
> 扫描一遍字符串,记录所有合法的字符串(**注意年份限制**)出现次数,选择最大的输出(**注意输出格式**)即可.
> 
> 另:有人说`isdigit()`会wa,不知道什么原因,但是我的可以过.
### Code
```cpp
const int days[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
int t[41][13][5];
char s[100001];
int main(){
	scanf("%s",s);
	int len=strlen(s);
	for (int i=0;i+9<len;i++){
		if (isdigit(s[i])&&isdigit(s[i+1])&&isdigit(s[i+3])&&isdigit(s[i+4])
	      &&isdigit(s[i+6])&&isdigit(s[i+7])&&isdigit(s[i+8])&&isdigit(s[i+9])
		  &&s[i+2]=='-'&&s[i+5]=='-'){
		  	int year=(s[i+6]-'0')*1000+(s[i+7]-'0')*100+(s[i+8]-'0')*10+s[i+9]-'0';
		  	int month=(s[i+3]-'0')*10+(s[i+4]-'0');
		  	int day=(s[i]-'0')*10+s[i+1]-'0';
		  	if (year>=2013&&year<=2015&&month>=1&&month<=12&&day>=1&&day<=days[month]){
		  		t[day][month][year-2013]++;
			}
		}
	}
	int maxy=0,maxm=0,maxd=0,maxx=0;
	for (int i=0;i<=2;i++){
		for (int j=1;j<=12;j++){
			for (int k=1;k<=days[j];k++){
				if (t[k][j][i]>maxx){
					maxx=t[k][j][i];
					maxy=i+2013;
					maxm=j;
					maxd=k;
				}
			}
		}
	}
	printf("%02d-%02d-%d",maxd,maxm,maxy);
}
```
*****

## C - Balls and Boxes 
### Problem description
> 给出n个箱子,每个箱子有若干个球,可以选择一个箱子i,取出所有k个球,然后按i+1,i+2,..,n,1,2,..,n,1,2,..的顺序向各个箱子加1个球,直至k个球放完为止.

> 现在已知操作完毕后各个箱子的球的数量a[i]和最后一次放球的位置x,求出一开始各个箱子球的数量.

### Data Limit：2 ≤ n ≤ 10^5, 1 ≤ x ≤ n   ,0 ≤ ai ≤ 10^9, ax ≠ 0  Time Limit: 1s

### Solution
> 首先考虑最直接的算法,倒推操作,每次倒序取出一个球,直至有一个箱子球为0,将取出的球放回去.但是复杂度是O(n*min(a[i]))的...必TLE无疑.

> 然后我们注意到一开始的min(a[i])轮仅仅是将所有的n个数-1,所以可以统一操作,然后最后一轮再暴力模拟,复杂度O(n).

### Code
```cpp
LL B[100001];
int main(){
	int n,x;
	scanf("%d%d",&n,&x);
	for (int i=1;i<=n;i++) scanf("%I64d",&B[i]);
	LL tmp=0,minn=1e9+1;int k=x;
	for (int i=1;i<=n;i++) minn=min(minn,B[i]);
	while(1){
		B[k--]-=minn,tmp+=minn;
		if (k==0) k=n;
		if (k==x) break;
	}
	while(1){
		if (B[k]==0) {
			B[k]=tmp;
			break;
		}
		B[k--]--,tmp++;
		if (k==0) k=n;
	}
	for (int i=1;i<=n;i++) printf("%I64d ",B[i]);
}
```
*****


## D - Black and White Tree
### Problem description
> 有一棵树,每个节点为黑(c=1)/白(c=0)两种颜色的一种,且每一条边都连着一个黑节点和一个白节点,且有一个权值.

> 现在给出每一个节点的颜色c和它所连边的权值和s,求一种建树的方案.

### Data Limit：2 ≤ n ≤ 10^5 ,0 ≤ ci ≤ 1, 0 ≤ si ≤ 10^9 Time Limit: 1s
### Solution
> 将所有节点分成黑白两组,用两个指针扫描一遍.每次将两侧的点连一条权值为min(两边点的权值)的边,并将点权变为0的这一侧(如果两边都为0,只改一边)的指针+1.

### Code
```cpp
struct node{
	int s,c,id;
}P[100001];
bool cmp(node x,node y){
	return x.c<y.c;
}
int main(){
	int n;
	scanf("%d",&n);
	for (int i=1;i<=n;i++){
		scanf("%d%d",&P[i].c,&P[i].s); P[i].id=i;
	}
	sort(P+1,P+n+1,cmp);
	int bp,wp=1;
	for (int i=1;i<=n;i++) if (P[i].c==1) {bp=i;break;}
	for (int i=1;i<n;i++){
		int w=min(P[bp].s,P[wp].s);
		printf("%d %d %d\n",P[bp].id,P[wp].id,w);
		P[bp].s-=w;P[wp].s-=w;
		if (bp<n&&P[bp].s==0) bp++;else wp++;
	}
	
}

```
*****

# 赛后补题
## E - Dividing Kingdom
### Problem description
> 在平面上有n个点,求4条直线,其中2条平行于x轴,2条平行于y轴,使得将平面分成的9部分中的点数分别与给出的a[i]相同(不要求按照一定的顺序).

### Data Limit：9 ≤ n ≤ 10^5 , - 10^9 ≤ xi, yi ≤ 10^9 , 1<=ai<=1e5,∑ai=n  Limit: 2s

### Solution
> 可以枚举所有各个区块所包括的点数的情况,然后一一排除.如果暴力判断,时间复杂度是O(9!n),会超时.

> 考虑优化判断的时间复杂度.分别对所有点按x,y坐标排序后,每次枚举就可以用O(1)时间求出4条直线.

> 同时,对按x坐标排序的数列建线段树,每个节点上用vector记录在该区间内所有点的y坐标,并排序(推荐使用归并).

> 每次枚举时,在已知4条直线的情况下,就可以用O((log*n*)^2)的时间求出一定x区间内纵坐标低于某个值的点的数量(对每个访问到的线段树节点跑一遍二分),就可以通过判断区间前缀和是否吻合来判断方案是否合法了.

> 复杂度O(9!log*n*^2)

> P.S. 使用主席树维护区间前缀和可以优化到O(9!log*n*) 

### Code
(线段树+vector)
```cpp
struct Node{
	int ls,rs;
	vector<int> v;
	Node(){v.clear();}
}T[400001];
int n,tail=0,a[10];
struct point{
	int x,y;
}P[100001],P2[100001];
void build(int &node,int l,int r){
	node=++tail;
	if (l==r) T[node].v.push_back(P[l].y);
	else{
		int mid=(l+r)>>1;
		build(T[node].ls,l,mid);
		build(T[node].rs,mid+1,r);
		T[node].v.resize(T[T[node].ls].v.size()+T[T[node].rs].v.size()); //without this the program will report RE.
		merge(T[T[node].ls].v.begin(),T[T[node].ls].v.end(),T[T[node].rs].v.begin(),T[T[node].rs].v.end(),T[node].v.begin());
	}
}
int query(int node,int l,int r,int lx,int rx,int y){
	Node &tmp=T[node];
	if (l==lx&&r==rx){
		if (tmp.v[0]>y) return 0;
		if (tmp.v[tmp.v.size()-1]<=y) return tmp.v.size();
		return (upper_bound(tmp.v.begin(),tmp.v.end(),y)-tmp.v.begin());
	}
	int ans=0,mid=(l+r)>>1;
	if (lx<=mid) ans+=query(tmp.ls,l,mid,lx,min(rx,mid),y);
	if (rx>mid)  ans+=query(tmp.rs,mid+1,r,max(mid+1,lx),rx,y);
	return ans; 
}
inline bool cmpx(point a,point b){return a.x<b.x;}
inline bool cmpy(point a,point b){return a.y<b.y;}
int main(){
	scanf("%d",&n);
	for (int i=1;i<=n;i++){
		scanf("%d%d",&P[i].x,&P[i].y);
		P2[i]=P[i];
	}
	
	sort(P+1,P+n+1,cmpx);
	sort(P2+1,P2+n+1,cmpy);
	int root;
	build(root,1,n);
	
	for (int i=1;i<=9;i++) scanf("%d",&a[i]);
	sort(a+1,a+9+1);
	do{
		//a[1..9]对应的区间:
		//369
		//258
		//147
		int A1=a[1]+a[2]+a[3],A2=a[4]+a[5]+a[6],
		    B1=a[1]+a[4]+a[7],B2=a[2]+a[5]+a[8];
		    
		int y1=P2[B1].y,  y2=P2[B2+B1].y;
		       
		if (P[A1+1].x==P[A1].x||P[A2+A1].x==P[A2+A1+1].x||P2[B1].y==P2[B1+1].y||P2[B1+B2].y==P2[B1+B2+1].y) continue;
		if (query(root,1,n,1,A1,y1)!=a[1]||query(root,1,n,A1+1,A2+A1,y1)!=a[4]||query(root,1,n,A1+A2+1,n,y1)!=a[7]||
		    query(root,1,n,1,A1,y2)!=a[1]+a[2]||query(root,1,n,A1+1,A2+A1,y2)!=a[4]+a[5]||query(root,1,n,A1+A2+1,n,y2)!=a[7]+a[8]) continue;
		printf("%.8lf %.8lf\n%.8lf %.8lf",(P[A1].x+P[A1+1].x)/2.0,(P[A1+A2].x+P[A1+A2+1].x)/2.0,(P2[B1].y+P2[B1+1].y)/2.0,(P2[B1+B2].y+P2[B1+B2+1].y)/2.0);
		return 0;
	}while(next_permutation(a+1,a+9+1));
	printf("-1");
}
```

(主席树)

```cpp
struct Node{
	int ls,rs,cnt;
}T[2000001];
int n,tail=0,a[10],root[100001];
struct point{
	int x,y,id;
}P[100001],P2[100001];
void build(int &node,int l,int r){
	node=++tail;
	if (l==r) return;
	int mid=(l+r)>>1;
	build(T[node].ls,l,mid);
	build(T[node].rs,mid+1,r);
}
void insert(int &node,int pre,int l,int r,int k){
	node=++tail;
	T[node]=T[pre];
	T[node].cnt++;
	if (l==r) return;
	int mid=(l+r)>>1;
	if (k<=mid) insert(T[node].ls,T[pre].ls,l,mid,k);
	else insert(T[node].rs,T[pre].rs,mid+1,r,k);
}
int query(int node,int l,int r,int k){
	Node &tmp=T[node];
	if (l==r) return l;
	int t=T[tmp.ls].cnt,mid=(l+r)>>1;
	if (t>=k) return query(tmp.ls,l,mid,k);	
	else return query(tmp.rs,mid+1,r,k-t);
}
inline bool cmpx(point a,point b){return a.x<b.x;}
inline bool cmpy(point a,point b){return a.y<b.y;}
int main(){
	scanf("%d",&n);
	for (int i=1;i<=n;i++){
		scanf("%d%d",&P[i].x,&P[i].y);
	}
	
	sort(P+1,P+n+1,cmpy);
	for (int i=1;i<=n;i++) P[i].id=(i>1&&P[i].y==P[i-1].y)?P[i-1].id:i,P2[i]=P[i]; 
	sort(P+1,P+n+1,cmpx);
	build(root[0],1,n);
	for (int i=1;i<=n;i++) insert(root[i],root[i-1],1,n,P[i].id);
	
	for (int i=1;i<=9;i++) scanf("%d",&a[i]);
	sort(a+1,a+9+1);
	do{
		int A1=a[1]+a[2]+a[3],A2=a[4]+a[5]+a[6],
		    B1=a[1]+a[4]+a[7],B2=a[2]+a[5]+a[8];
		    
		int y1=P2[B1].id,  y2=P2[B2+B1].id,
		    y3=P2[B1+1].id,y4=P2[B2+B1+1].id;
		       
		if (P[A1+1].x==P[A1].x||P[A2+A1].x==P[A2+A1+1].x||P2[B1].y==P2[B1+1].y||P2[B1+B2].y==P2[B1+B2+1].y) continue;
		if (query(root[A1],1,n,a[1])>y1                  ||query(root[A1],1,n,a[1]+1)<y3||
		    query(root[A1+A2],1,n,a[1]+a[4])>y1          ||query(root[A1+A2],1,n,a[1]+a[4]+1)<y3||
		    query(root[n],1,n,B1)>y1                     ||query(root[n],1,n,B1+1)<y3||
		    query(root[A1],1,n,a[1]+a[2])>y2             ||query(root[A1],1,n,a[1]+a[2]+1)<y4||
		    query(root[A1+A2],1,n,a[1]+a[2]+a[4]+a[5])>y2||query(root[A1+A2],1,n,a[1]+a[2]+a[4]+a[5]+1)<y4||
		    query(root[n],1,n,B1+B2)>y2                  ||query(root[n],1,n,B1+B2+1)<y4) continue;
		printf("%.8lf %.8lf\n%.8lf %.8lf",(P[A1].x+P[A1+1].x)/2.0,(P[A1+A2].x+P[A1+A2+1].x)/2.0,(P2[B1].y+P2[B1+1].y)/2.0,(P2[B1+B2].y+P2[B1+B2+1].y)/2.0);
		return 0;	
	}while(next_permutation(a+1,a+9+1));
	printf("-1");
}

```
