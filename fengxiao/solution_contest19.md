# Solution of contest19
```
/******************
    VJudge链接：  https://cn.vjudge.net/contest/172423
CodeForces链接：  http://codeforces.com/contest/260

题目按CF顺序排序
******************/
```
这场比赛我仿佛失了智。。。
# #A Adding Digits 
```
/******************
     主要算法：模拟
     Data limit: a, b, n (1 ≤ a, b, n ≤ 105).
******************/
```
### 题意
给你三个数a,b,n，让你执行n次操作：  
将a=a*10+x(0<=x<=9) ,使a能被b整除，如此进行n次
### 题解
简单分析后可以发现如果 x%y==0 -> 10x%y==0  
那么就只要判断第一遍操作是否可以即可，后面都输出0就可以了
### 核心代码
```
/******************
	scanf("%d %d %d",&a,&b,&n);
	for(int i=0;i<=9;i++)
		if((a*10+i)%b==0)
		{
			a=a*10+i;
			//printf("%d",a);
			flag=1; break;
		}
	if(!flag) {puts("-1"); return 0;}
	printf("%d",a);
	for(int i=1;i<n;i++) printf("0");
******************/
```
### 错题记录
1A
***
# #B Ancient Prophesy
```
/******************
    主要算法：字符串处理+模拟
     Data limit: ls<=1e6
******************/
```
### 题意
给你一串字符串，由数字和'-'组成  
形如xx-xx-xxxx的序列可以表示一个日期  
求在s中出现最多次的日期，保证有解  
坑点：1.题目中很隐蔽的地方说年份只有在2013~2015才是合法的    
      2.注意补齐场宽。。我明明想到了却用空格填充。。。  

### 题解
只需枚举起始点，判断其后的序列是不是合法日期，然后再加入map中记录数量即可  
### 核心代码
```
/******************
我貌似写的有点挫。。。
inline bool ok(int i) {return isd(s[i]) && isd(s[i+1]) && s[i+2]=='-' && isd(s[i+3]) && isd(s[i+4]) && s[i+5]=='-' && 
							  isd(s[i+6]) && isd(s[i+7]) && isd(s[i+8]) && isd(s[i+9]);}
inline bool isok(int x)
{
	int a=x/1000000,b=x/10000-x/1000000*100,c=x%10000;
	if(b>12 || b<1 || a<1 || a>31 || c<2013 || c>2015) return false;
	if(b==2 && a>28) return false;
	else if(b<=7)
	{
		if(b&1 && a>31) return false;
		else if(!(b&1)  && a>30) return false; 
	}
	else if(b>7)
	{
		if(b&1 &&a>30) return false;
		else if(!(b&1) &&a>31) return false;
	}
	return true;
}
inline void print(int x)
{
	int a=x/1000000,b=x/10000-x/1000000*100,c=x%10000;
	printf("%02d-%02d-%4d",a,b,c);
}
int main()
{
	scanf("%s",s);int ls=strlen(s);
	for(int i=0;i<=ls-10;i++)
	{
		if(ok(i))
		{
			int num=0;
			num=(s[i]-'0')*1e7+(s[i+1]-'0')*1e6+(s[i+3]-'0')*1e5+(s[i+4]-'0')*1e4+(s[i+6]-'0')*1e3+(s[i+7]-'0')*1e2+(s[i+8]-'0')*1e1+(s[i+9]-'0')   ;
			if(isok(num))
			{
				key[num]++;
				if(key[num]==1) ap[++cnt]=num;
			}
		}
	}
	int pos=0,maxn=0;
	for(int i=1;i<=cnt;i++)
		if(key[ap[i]]>maxn)
		{
			maxn=key[ap[i]];
			pos=ap[i];
		}
	print(pos);
	return 0;
}
******************/
```
### 错题记录
坑点全中+日期合法判断中的一些逻辑错误
***
# #C Balls and Boxes 
```
/******************
      主要算法：模拟+找规律
     Data limit:n and x (2 ≤ n ≤ 1e5, 1 ≤ x ≤ n)
******************/
```
### 题意
操作定义：将原有序列中某个数ai拿空，然后从它后一格开始向后ai个数都+1，如果超过长度就环状继续  
给你一个数组，表示进行1次操作后的序列，然后给你个x，表示最后一个放数字的地方  
输出初始序列~~若有多组输出一组~~（不存在的）
### 题解
首先脑补一下就知道一定要选序列中最小的那个作为开始点。。（要不然那个最小的就要被别的比它大的抽成负数了。。）  
然后进行模拟加加减减就可以了，小优化就是完全成环的可以统一减掉  
坑点：有可能序列中有多个最小值，那么根据放数的性质应该选最靠近x的点作为出发点  
### 核心代码
```
/******************
inline int dist(int a,int b) {return (b+n-a)%n;}
	scanf("%I64d %I64d",&n,&p); p--;
	for(i=0;i<n;i++) scanf("%I64d",&a[i]);
	int minn=1000000000000000,pos;
	for(i=p;i!=(p+1)%n;i=(i-1+n)%n) if(minn>a[i]) {minn=a[i]; pos=i;} if(minn>a[(p+1)%n]) pos=(p+1)%n;
	int tmp=dist(pos,p)+a[pos]*n,t=a[pos];
	if(pos!=p) for(j=(pos+1)%n;j!=p;j=(j+1)%n) a[j]--; a[p]--; 
	for(j=0;j<n;j++) a[j]-=t; a[pos]=tmp;
	for(j=0;j<n;j++) printf("%I64d ",a[j]);
******************/
```
### 错题记录
死在坑点。。。
***
# #D Black and White Tree 
```
/******************
      主要算法：贪心
     Data limit: n (2 ≤ n ≤ 105)  ci, si (0 ≤ ci ≤ 1, 0 ≤ si ≤ 109)
******************/
```
### 题意
给你一堆节点，每个节点有两个值：c->颜色，v->所有和它相关的边的权值总和  
让你构建出一棵树，满足任意一条边两端的点颜色不同，且边权之和等于v  
输出树的所有边（u,v,value），顺序不管  
### 题解
刚开始采取随便取两个点进行merge，并且用并查集维护联通快的方法，结果T了  
然后经过一些分析可以发现每次取最小的两个点merge就可以保证合法了。。。  
merge：两个结点每个的权值减去两个结点的最小值:t=min(Vu,Vv),Vu-=t,Vv-=t; print(u,v,t)  
### 核心代码
```
/******************
	for(i=1;i<=n;i++) {scanf("%d %d",&c,&v); a[c][++a[c][0].F]=mp(v,i);}
	sort(a[0]+1,a[0]+a[0][0].F+1); sort(a[1]+1,a[1]+a[1][0].F+1);
	i=j=1;
	for(int t=1;t<n;t++)
	{
		int tmp=min(a[0][i].F,a[1][j].F);
		printf("%d %d %d\n",a[0][i].S,a[1][j].S,tmp);
		a[0][i].F-=tmp,a[1][j].F-=tmp;
		if(a[0][i].F) j++;
		else if(a[1][j].F) i++;
		else if(i<a[0][0].F) i++;
		else j++;
	}
	return 0;
}
******************/
```
### 错题记录
用了第一个方法但没用并查集->WA  
加了并查集->TLE  

***
# #E Dividing Kingdom 
```
/******************
      主要算法：线段树
     Data limit: n (9 ≤ n ≤ 105)
******************/
```
### 题意
给你平面上若干个点，然后用两条竖线两条横线将平面分成9块   
并给你一个数组a，使这9块中每块点的个数刚好对应a中每个元素  
### 题解
套路：先排序搞定x轴，以x轴建立线段树，节点内记录在区间中的点的y坐标并排序以便于横线的查询  
暴力枚举每个块所对应a数组的值
然后由于x，y轴分别有序则可以直接计算竖线和横线   
再用线段树判断情况是否合法便可  
### 核心代码
```
/******************
void bulid_tre(int u,int l,int r)
{  
    tre[u].s=l;tre[u].e=r;
    for(int i=l;i<=r;i++) tre[u].v.pb(p[i].y);  
    sort(tre[u].v.begin(),tre[u].v.end());  
    if(l==r) return;
    bulid_tre(lc,l,mid); bulid_tre(rc,mid+1,r);  
}  
int query(int u,int l,int r,int v)
{  
    if(l<=tre[u].s&&tre[u].e<=r)
	{  
        if(tre[u].v.size()==0 || tre[u].v[0]>v) return 0;
        if(tre[u].v.back()<=v) return tre[u].v.size();  
        return upper_bound(tre[u].v.begin(),tre[u].v.end(),v)-tre[u].v.begin();  
    }
    int ans=0;
    if(l<=mid) ans+=query(left,v); 
    if(r> mid) ans+=query(right,v);  
    return ans;
}  
bool ok()
{  
    int x1=a[0]+a[1]+a[2]-1;  
    int x2=x1+a[3]+a[4]+a[5];  
    int y1=a[0]+a[3]+a[6]-1;
    int y2=y1+a[1]+a[4]+a[7];
    if(x1+1>=n||x[x1]==x[x1+1]) return false;  
    if(x2+1>=n||x[x2]==x[x2+1]) return false;  
    if(y1+1>=n||y[y1]==y[y1+1]) return false;  
    if(y2+1>=n||y[y2]==y[y2+1]) return false;  
    if(query(1,0,x1,y[y1])!=a[0]) return false; 
    if(query(1,0,x1,y[y2])!=a[0]+a[1]) return false; 
    if(query(1,x1+1,x2,y[y1])!=a[3]) return false;  
    if(query(1,x1+1,x2,y[y2])!=a[3]+a[4]) return false;  
    printf("%.10lf %.10lf\n%.10lf %.10lf\n",x[x1]+0.5,x[x2]+0.5,y[y1]+0.5,y[y2]+0.5);
    return true;   
}  
int main()
{  
    scanf("%d",&n); 
    for(int i=0;i<n;i++){scanf("%d %d",&p[i].x,&p[i].y); x[i]=p[i].x;y[i]=p[i].y;}  
    sort(p,p+n,cmp); sort(x,x+n); sort(y,y+n);  
    bulid_tre(1,0,n-1);  
    for(int i=0;i<9;i++) scanf("%d",&a[i]); sort(a,a+9);
    do if(ok()) return 0; while(next_permutation(a,a+9));
    puts("-1");
    return 0;  
}
******************/
```
###错题记录
1A
***
