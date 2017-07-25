[比赛链接]https://vjudge.net/contest/168929#problem)

## 比赛征程
> * Y : solved in the contest
> * A : solved after contest
> * SY : solving


  \# |  A  |  B  |  C  |  D  |  E  |
---|---|---|---|---|---|
|contest0|Y|  A  |A| A | A |



# 比赛中解决的问题
## A
### Problem description
> 略

### Data Limit：n,p<=300  Time Limit: 1s

### Solution
> 略
### Code
```cpp
	int a,b,n;
	cin>>a>>b>>n;
	a*=10;
	int aa=(a%b);
	aa=((b-aa)%b+b)%b;
	if(aa<=9) {
		a+=aa;
		cout<<a;
		for(int i=1;i<=n-1;i++) putchar('0');
	}
	else cout<<-1<<endl;
```
*****


# 赛后补题

## B
### Problem description
> 略

### Data Limit：n <= 1e4  Time Limit: 2s
### Solution
> 输日期要补前位0.

### Code
```cpp
	mon[1]=31;mon[2]=28;mon[3] = 31;mon[4] = 30;mon[5] = 31;mon[6] = 30;mon[7] = 31;
	mon[8]=31;mon[9]=30;mon[10]=31;mon[11]=30;mon[12] = 31;
	scanf("%s",xx);
	int l=strlen(xx);
	for(int i = 0; i <= l-8 ; i++ ) {
		if(xx[i + 2] != '-'&&xx[i + 5] != '-' ) continue;
		bool flag=0;
		for(int j = 0; j <= 9 ; j ++ ) {
			if(j == 2 || j == 5) continue ;
			if(!isdigit(xx[i + j])) flag=1; 
		} 
		if(flag) continue;
		int d1 = (xx[i] - '0' ) * 10 +xx[i + 1] - '0', d2 = (xx[i + 3] - '0' ) * 10 +xx[i + 4] - '0';
		int d3 = (xx[i + 6] - '0') * 1000 +(xx[i + 7] - '0') * 100 +(xx[i + 8] - '0' ) * 10 + xx[i + 9] - '0';
///		cout<< d1 << ' ' << d2 << ' ' <<d3 <<endl;
		if(d2 <=0 || d2 > 12) continue;
		if(d1 <= 0 ||d1 > mon[d2]) continue;
		if(d3 < 2013 || d3> 2015 ) continue;
		M[d3 - 2012 ][ d1 ][ d2 ]++; 
	}
	int no1 = -1,no2 = -1,no3 = -1,ans=0;
	for(int i = 1;i <= 3 ;i ++ ) 
	for(int j = 1;j <= 100 ;j++ ) {
		for(it = M[i][j].begin() ; it != M[i][j].end() ; it ++ ) {
			int d3=it -> first ,cnt =it -> second;
			if(cnt > ans ) {
				no1 = i , no2 = j,no3 = d3;
				ans=cnt;
			}
		}
	}
	
	if(no2<10) putchar('0');
	cout<< no2 ; 
	cout<< "-" ;
	if(no3<10) putchar('0');
	cout<< no3 << "-" << no1 + 2012<<endl; 
```
*****
## C
### Problem description

> 给你一个环状盒子序列，做一次操作将某个盒子里的球拿出，然后按环逆时针每次放一个球，放完为止，给你结束序列和结束位置，求开始序列


### Data Limit：n <= 1e5  Time Limit: 4s

### Solution
>贪心即是。我们考虑到被拿走的那个数操作完后一定最小，而且根据操作的性质，如果在x前有就去最后一个，否则取整个序列里的最后一个最小值即可</br>
### Code
```cpp
	int minl=1e18,no=-1,cnt = 0;
	for(int i = 1; i <= n; i ++ ) {
		if(a[i]<minl) {
			minl = a[i];no = i;
		}
	}
	no=-1;
	for( int i = 1 ;i <= x; i ++ ) {
		if(a[i] == minl ) no = i;
	}
	if(no==-1)
	for( int i = x+1 ;i <= n; i++) {
		if(a[i] == minl) no=i;
	}
	if( x == no )   minl  --  ;
	for(int i = 1 ;i <= n ; i ++ ) a[i] -= minl;
	int i = no + 1 ;if(i == n+1) i = 1 ;
	cnt += n * minl ; 
	a[i] -- ;cnt ++ ;
	while(i != x) {
		i ++ ; if(i == n+1 ) i = 1;
		a[i] -- ;cnt ++ ; 
	}
	a[no]=cnt;	
```
*****


## D
### Problem description
> 一个二分图，这个图同时是一棵树，每个点有一个权值，告诉你这个树上每个点的所到点的权值和，要你随机恢复这棵树输出。
### Data Limit：k<= 1e5n,m<=1000  Time Limit: 2s
### Solution
> 贪心即可，因为这是一棵二分图，你直接按顺序连，能连则连，然后得到很多连通块，然后用0的边连起来就可以了。
### Code
```cpp
	int p = 1;
	for(int i = 1; i <= c0 ;i ++ ) {
		while( x1[p].w < x0[i].w ) {
			x0[i].w -= x1[p].w;
			u[++cnt] = x0[i].id;v[cnt] = x1[p].id; w[cnt] = x1[p].w;
			p++;
		}
		x1[p].w -= x0[i].w ; u[ ++ cnt ] =x0[i].id; v[cnt] = x1[p].id; w[cnt] =x0[i].w;
	}
	while( p < c1) {
		p++; u[ ++ cnt] = x1[p].id; v[cnt] =  x0[ rand()%c0 +1 ].id;w[ cnt ] = 0;
	}
```
*****

## E
### Problem description
> 给你许多点，要你切横两刀竖两刀分成九个区域，区域内的点个数恰好与给定数组形成一一映射。

### Data Limit：n <= 1e5  Time Limit: 2s

### Solution
> 这类一一映射题先用一个全排列码住。然后本题就转化为<=x,<=y的求点问题，这个排个序用线段树或直接离散化即可，考试时懵逼。</br>
还有一种转离线+树状数组？是的
# ##Code
```
void gethash() {
	sort(asd+1,asd+n+1,cx);
	hx[++chx]=asd[1].x;
	P[asd[1].id].x=1;Sx[1]=1;
	for(int i = 2;i <= n;i ++) {
		if(asd[i].x != asd[i-1].x) {
			hx[++chx]=asd[i].x;Sx[chx]=Sx[chx-1]+1;
		}
		else Sx[chx]++;
		P[asd[i].id].x = chx;
	}
	sort(asd+1,asd+n+1,cy);
	hy[++chy]=asd[1].y;
	P[asd[1].id].y=1;
	Sy[chy]=1;
	for(int i = 2;i <= n;i ++) {
		if(asd[i].y!=asd[i-1].y) {
			hy[++chy]=asd[i].y;Sy[chy]=Sy[chy-1]+1;
		} else Sy[chy]++;
		P[asd[i].id].y = chy ;
	}
}
```

Segment Tree
```
void build(int no,int l,int r) {
	L[no]=l;R[no]=r;
	getmid;
	for(int i=l;i<=r;i++) {
		pg[no].pb(P[i]);
	}
	sort(pg[no].begin(),pg[no].end(),cmp2);
	if(l==r) return;
	build(lc,l,mid);build(rc,mid+1,r);
}
int query(int no,int l,int r,int k) {
//	cout<<no<<" "<<l<<" "<<r<<" "<<k<<" "<<L[no]<<" "<<R[no]<<endl;
	if(L[no]==l&&R[no]==r) {
		int ll=0,rr=pg[no].size()-1,ans=-1;
		while(ll<=rr) {
			int mid=(ll+rr)>>1;
			if(pg[no][mid].y<=k) {
				ans=mid;ll=mid+1;
			}
			else rr=mid-1;
		}
		return ans+1;
	}
	getmid;
	if(l>mid) return query(rc,l,r,k);
	if(r<=mid) return query(lc,l,r,k);
	return query(lc,l,mid,k)+query(rc,mid+1,r,k);
}
```
bool ok(void)
```
bool ok() {
	int a1=per[1]+per[2]+per[3],a2=per[4]+per[5]+per[6]+a1;
	
	int x1=P[a1].x,x2=P[a2].x;
	
	if(P[a1+1].x==x1||P[a2+1].x==x2) return 0;
	
	int b1=per[1]+per[4]+per[7],b2=b1+per[2]+per[5]+per[8];
	
	int y1=P1[b1].y,y2=P1[b2].y;
	
	if(P1[b2+1].y==y2||P1[b1+1].y==y1) return 0;
	
	if(query(1,1,a1,y1)!=per[1]) return 0;
	
	if(query(1,1,a1,y2)!=per[1]+per[2]) return 0;
	
	if(query(1,1,a2,y2)!=per[1]+per[2]+per[4]+per[5]) return 0;
	
	if(query(1,1,a2,y1)!=per[1]+per[4]) return 0;
	
	printf("%.7lf %.7lf\n%.7lf %.7lf\n",hx[x1]+0.5,hx[x2]+0.5,hy[y1]+0.5,hy[y2]+0.5);
	return 1;
}
```
