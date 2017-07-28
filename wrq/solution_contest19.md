[比赛链接](https://cn.vjudge.net/contest/172423)

# 比赛中解决的问题  

## A Adding Digits 
### Problem description
> 给出数字a和b，每次在a后面添加一位数字，重复n次，使得每次产生的数字a都能够被b整除

### Data Limit：1 <= a,b,n <= 10^5  Time Limit: 2s

### Solution
> 因为一旦添加某一位后a不能被b整除，整个操作就不合法，因此可行方案的第一次添加就必须使a被b整除，剩余的n-1次操作只需添加0即可  
如果在第一次添加时找不到可行方案则输出-1

### Code
```cpp
	for (int i=0;i<=9;++i){
		int x=a*10+i;
		if (x%b==0){
			printf("%d",x);
			for (int i=1;i<n;++i) printf("0");
			return 0;
		}
	}
	printf("-1");
```
*****


## D Black and White Tree 
### Problem description
> 有一颗结点为黑白两色的树，每条边都有权值且连接颜色不同的两个点，每个点的权值等于连接该点的边的权值总和  
现在给出n个点的颜色和权值，求边的连接情况

### Data Limit：2 <= n <= 10^5  Time Limit: 1s

### Solution
> 因为每条边都连接颜色不同的点，所以黑点的权值和等于白点的权值和。  
对于一个点，它的权值是周围所有边的权值之和。因此边权<=min(两点的权值)，即决定边权的是权值较小的点。  
因此从权值较小的点逐个连接即可

### Code
```cpp
struct xint{
	int sum,no;
	xint(){}
	xint(int _sum,int _no):sum(_sum),no(_no){}
};
struct cmp{
	bool operator()(xint &a,xint &b){
		return a.sum>b.sum;
	}
};
priority_queue< xint,vector<xint>,cmp > q_black;
priority_queue< xint,vector<xint>,cmp > q_white;


	for (int i=1;i<=n;++i){
		int x,y; scanf("%d%d",&x,&y);
		xint tmp(y,i);
		if (x) q_black.push(tmp),cntb++; else q_white.push(tmp),cntw++;
	}
	for (int i=1;i<n;++i){
		xint a=q_black.top(),b=q_white.top();
		q_black.pop(),cntb--, q_white.pop(),cntw--;
		u[i]=a.no,v[i]=b.no;
		w[i]=min(a.sum,b.sum);
		a.sum-=w[i], b.sum-=w[i];
		if (a.sum==0&&b.sum==0){
			if (cntw==0) q_white.push(b),cntw++;
			else q_black.push(a),cntb++;
		}//注意两个都为0的情况
		if (a.sum>0) q_black.push(a),cntb++;
		if (b.sum>0) q_white.push(b),cntw++;
	}
```
*****

# 赛后补题  

## B Ancient Prophesy
### Problem description
> 给出由数字和‘-’组成的字符串，求在该字符串中出现次数最多的日期。  
日期格式为dd-mm-yyyy，不足的用0补齐，需保证年份在2013-2015之间

### Data Limit：0 < |s| <= 10^5  Time Limit: 1s

### Solution
> 暴力枚举每一位为起点，检查该段是否合法即可

### Code
```cpp
	scanf("%s",s);
	int len=strlen(s);
	for (int i=0;i+9<len;++i){
		bool f=1;
		for (int j=0;j<=9;++j){
			//printf("%c %d %d\n",s[i+j],i,j);
			if (j==2||j==5){
				if (s[i+j]!='-'){f=0; break;}
			}
			else if (s[i+j]<'0'||s[i+j]>'9'){f=0; break;}
		}
		//printf("  orz\n");
		if (!f) continue;
		int d=(s[i]-'0')*10+(s[i+1]-'0');
		int m=(s[i+3]-'0')*10+(s[i+4]-'0'),y=0;
		for (int j=6;j<=9;++j) y*=10, y+=s[i+j]-'0';
	//	printf("%d %d %d\n",d,m,y);
		if (m>12||m<1||y>2015||y<2013||d>month[m]) continue;
		a[y-2013][m][d]++;
	}
	int d=1,m=1,y=0;
	for (int i=0;i<=2;++i)
		for (int j=1;j<=12;++j)
			for (int k=1;k<=month[j];++k){
				if (a[i][j][k]>a[y][m][d]) y=i,m=j,d=k;
			}
	if (d>=10) printf("%d-",d); else printf("0%d-",d);
	if (m>=10) printf("%d-",m); else printf("0%d-",m);
	printf("%d\n",y+2013);
```
*****


## C Balls and Boxes
### Problem description
> 有n个箱子，每个箱子里都有一定数量的球。  
现在取出某个箱子里的所有球，从后面一个位置开始，依次在后面的箱子里放入一个球，放完为止。若到第n个还没放完，返回第一个继续放。
已知放完后所有箱子的状态和结束位置，求初始状态

### Data Limit：n <= 10^5, a[i] <= 10^9, a[i] != 0  Time Limit: 1s

### Solution
> 暴力做法是一个一个往前减，直到访问到的位置为0为止。但这样会超时。  
显然的，最终状态里球数量最少的位置即为初始位置，记为loc。终点记为x，则可以分类讨论：  
1.当loc==x，刚好经过每个位置a[loc]次  
2.当loc>x，说明经过了所有位置a[loc]次，另外，loc+1到n位置1次，1到x位置1次  
3.当loc<x，说明经过所有位置a[loc]次，另外，loc+1到x位置1次

### Code
```cpp
	long long tmp=1e18,loc;
	for (int i=1;i<=n;++i) scanf("%I64d",&a[i]);
	for (int i=x;i>=1;--i) if (a[i]<tmp) tmp=a[i],loc=i;
	for (int i=n;i>x;--i) if (a[i]<tmp) tmp=a[i],loc=i;
	long long sum=0;
	if (loc==x){
		for (int i=1;i<=n;++i) a[i]-=tmp,sum+=tmp;
	}else if (loc>x){
		for (int i=loc+1;i<=n;++i) a[i]--,sum++;
		for (int i=1;i<=x;++i) a[i]--,sum++;
		for (int i=1;i<=n;++i) a[i]-=tmp,sum+=tmp;
	}else{
		for (int i=loc+1;i<=x;++i) a[i]--,sum++;
		for (int i=1;i<=n;++i) a[i]-=tmp,sum+=tmp;
	}
	a[loc]+=sum;
```
*****

## E Dividing Kingdom
### Problem description
> 给定平面上n个点和9个数，求两条平行于x轴的直线和两条平行于y轴的直线，使得被直线分成的9个区域中，
点的数量和给定的9个数对应

### Data Limit：9 <= n <= 10^5, -10^9 <= xi,yi <= 10^9  Time Limit: 2s

### Solution
> dfs枚举9个数在9个区域的排列，分别check  
可用线段树维护纵坐标，每次check时在一定区间内二分横坐标，统计个数  
因为保证点的坐标为整数，所以直线的坐标是点+0.5

### Code
```cpp
struct Point{
	int x,y;
	void read(){
		scanf("%d%d",&x,&y);
	}
	Point(){}
	Point(int _x,int _y):x(_x),y(_y){}
	bool operator < (const Point &a){
		return x<a.x||x==a.x&&y<a.y;
	}
}p[100010];

void build(int l,int r,int k){
	tree[k].clear();
	for (int i=l;i<=r;++i) tree[k].push_back(p[i].y);
	if (l==r) return;
	int mid=(l+r)/2;
	build(l,mid,k*2); build(mid+1,r,k*2+1);
	sort(tree[k].begin(),tree[k].end());
}
int query(int l,int r,int k,int x,int y,int cnt){
	if (x<=l&&r<=y){
		int ll=0,rr=tree[k].size()-1;
		if (tree[k][0]>cnt||ll>rr) return 0;
		int ans=0;
		while (ll<=rr){
			int mid=(ll+rr)/2;
			if (tree[k][mid]<=cnt) ll=mid+1,ans=mid; else rr=mid-1;
		}
	//	printf("%d\n",ans+1);
		return ans+1;
	}
	int mid=(l+r)/2,ans=0;
	if (x<=mid) ans+=query(l,mid,k*2,x,y,cnt);
	if (y>mid) ans+=query(mid+1,r,k*2+1,x,y,cnt);
	return ans;
}
bool check(int x1,int x2,int y1,int y2){
	if (x1+1>=n||x1+x2+1>=n||y1+1>=n||y1+y2+1>=n) return 0;
	if (x[x1]==x[x1+1]||x[x1+x2]==x[x1+x2+1]) return 0;
	if (y[y1]==y[y1+1]||y[y1+y2]==y[y1+y2+1]) return 0;
	int m=query(1,n,1,1,x1,y[y1]); if (m!=num[1]) return 0;
	m=query(1,n,1,1,x1,y[y1+y2]); if (m!=num[1]+num[4]) return 0;
	m=query(1,n,1,x1+1,x1+x2,y[y1]); /*printf("%d %d %d\n",x1+1,x2+x1,m);*/ if (m!=num[2]) return 0;
	m=query(1,n,1,x1+1,x1+x2,y[y1+y2]); if (m!=num[2]+num[5]) return 0;
	return 1;
}
void dfs(int s){
	if (flag) return;
	if (s==9){
		int y1=num[1]+num[2]+num[3],y2=num[4]+num[5]+num[6];
		int x1=num[1]+num[4]+num[7],x2=num[2]+num[5]+num[8];
		if (check(x1,x2,y1,y2)){
			double ansx1,ansx2,ansy1,ansy2;
			printf("%.10f %.10f\n",x[x1]+0.5,x[x1+x2]+0.5);
			printf("%.10f %.10f\n",y[y1]+0.5,y[y1+y2]+0.5);
			flag=1;
		}
		return;
	}
	for (int i=1;i<=9;++i)
		if (!b[i]){
			b[i]=1; num[s+1]=a[i];
			dfs(s+1);
			b[i]=0;
		}
}

	for (int i=1;i<=n;++i) p[i].read();
	for (int i=1;i<=n;++i) x[i]=p[i].x,y[i]=p[i].y;
	for (int i=1;i<=9;++i) scanf("%d",&a[i]);
	sort(p+1,p+1+n);
	sort(x+1,x+1+n);
	sort(y+1,y+1+n);
	build(1,n,1);
	flag=0; dfs(0);
	if (!flag) printf("-1");
```
