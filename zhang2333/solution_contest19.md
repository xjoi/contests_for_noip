## 比赛征程
> * Y : solved in the contest
> * A : solved after contest
> * W : solving

  \# |  A  |  B  |  C  |  D  |  E  |
---|---|---|---|---|---|
| contest17 |Y|A|A|A|Y|

[比赛链接](https://cn.vjudge.net/contest/172423#overview)

## A
### Problem description
> 略

### Data Limit：略  Time Limit: 略
### Solution
> 略

### Code
```cpp
#include<bits/stdc++.h>
using namespace std;
int a,b,n,t,c[233],g=0;
string s;
int main(){
	cin>>a>>b>>n;
	t=a*10%b;
	while (a>0){
		c[++g]=a%10;
		a/=10;
	}
	while (g>0){
		s+=c[g--]+'0';
	}
	for (int nnd=1;nnd<=n;nnd++){
		for (int i=0;i<=10;i++){
			if (i==10){
				printf("-1");
				return 0;
			}
			if ((t+i)%b==0){
				s+=(char)(i+'0');
				t=0;
				break;
			}
		}
	}
	cout<<s;
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
#include<bits/stdc++.h>
using namespace std;
char s[520233];
int l,cnt[33][14][4]={0},fg,mx=0,ana,anb,anc;
int ok[10]={0,0,1,0,0,1,0,0,0,0};
int day[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};

int type(char c){
	if (c=='-') return 1;
	return 0;
}

int main(){
	scanf("%s",s);
	l=strlen(s);
	int a,b,c;
	for (int i=0;i<=l-10;i++){
		fg=0;
		for (int j=0;j<10;j++){
			if (ok[j]!=type(s[i+j])){
				fg=1;
				break;
			}
		}
		if (fg) continue;
		
		a=(s[i]-'0')*10+(s[i+1]-'0');
		b=(s[i+3]-'0')*10+(s[i+4]-'0');
		c=(s[i+6]-'0')*1000+(s[i+7]-'0')*100+(s[i+8]-'0')*10+(s[i+9]-'0');
		if (c>=2013&&c<=2015){
			if (b>=1&&b<=12){
				if (a>=1&&a<=day[b]){
					cnt[a][b][c-2013]++;
					if (cnt[a][b][c-2013]>mx){
						mx=cnt[a][b][c-2013];
						ana=a;
						anb=b;
						anc=c;
					}
				}
			}
		}
	}
	printf("%02d-%02d-%04d",ana,anb,anc);
	return 0;
}
```
*****
## C
### Problem description
> 细节题。。</br>

### Time Limit: 略
### Solution
> 略。。</br>

### Code
```cpp
#include<bits/stdc++.h>
using namespace std;
long long n,a[520233],k,miw,mia=2052023333,b[520233];

int main(){
	scanf("%I64d%I64d",&n,&k);
	for (int i=1;i<=n;i++){
		scanf("%I64d",&a[i]);
	}
	
	for (int i=k;i>0;i--){
		if (a[i]<mia){
			mia=a[i];
			miw=i;
		}
	}
	for (int i=n;i>k;i--){
		if (a[i]<mia){
			mia=a[i];
			miw=i;
		}
	}
	
	for (int i=1;i<=n;i++){
		b[i]= i==miw ? a[miw]*n : a[i]-a[miw];
	}
	if (miw<=k){
		for (int i=miw+1;i<=k;i++){
			b[i]--;
			b[miw]++;
		}
	}else{
		for (int i=miw+1;i<=n;i++){
			b[i]--;
			b[miw]++;
		}
		for (int i=1;i<=k;i++){
			b[i]--;
			b[miw]++;
		}
	}
	
	for (int i=1;i<=n;i++){
		printf("%I64d ",b[i]);
	}
	return 0;
}
```
*****
## D
### Problem description
> (坑爹题目毁我青春..)。。</br>
  原来有一棵n个节点(每个节点非黑即白)的树,树边连结两个异色点且带权。。</br>
  给出每个点的颜色和与之相连的边的边权和,要求还原树(SPJ)。。</br>

### Time Limit: 2s
### Solution
> 注意:可以连边权为0的边!!!因此xjb乱搞就好啦..</br>
> 不同颜色分成两个序列,两个指针先指向序列首,每次把指针指向的元素中小的合并给大的就好了(边界QAQ..)。。</br>

### Code
```cpp
#include<bits/stdc++.h>
using namespace std;
int n,g[2]={0};
int die[520233]={0};
struct XY{
	int v,pos;
}tp,q[2][520233];

int main(){
	int x,y;
	scanf("%d",&n);
	g[0]=g[1]=0;
	for (int i=1;i<=n;i++){
		scanf("%d%d",&x,&y);
		q[x][++g[x]]=(XY){y,i};
	}
	
	int p0=1,p1=1;
	for (int nnd=1;nnd<n;nnd++){
		if (q[0][p0].v<q[1][p1].v||p1==g[1]){
			printf("%d %d %d\n",q[0][p0].pos,q[1][p1].pos,q[0][p0].v);
			q[1][p1].v-=q[0][p0].v;
			p0++;
		}else{
			printf("%d %d %d\n",q[0][p0].pos,q[1][p1].pos,q[1][p1].v);
			q[0][p0].v-=q[1][p1].v;
			p1++;
		}
	}
	for (;clock()<998;);
	return 0;
}
```
*****
## E
### Problem description
> 平面直角坐标系上有n个点。。</br>
  要求横切两刀,竖切两刀(不得切到点..),使得每块区域(共9块)内的点数的集合与集合A相同(就是说顺序可以不同)..</br>

### Time Limit: 2s
### Solution
> 我只会主席树暴力搞。。</br>
  离散化后建主席树,使得能够lg求横坐标区间内的某一段纵坐标区间内的点数,再用树上二分去掉一个lg。。</br>
  
### Code
```cpp
#include<bits/stdc++.h>
using namespace std;

struct LT{
	int lc,rc,siz;
}tr[12333520],nil;
int cnt=0,root[520233];
struct P{
	int x,y;
	int rx,ry;
}p[520233];
int n,a[11],b[11],tox[520233],toy[520233],flag;

int NEW(){
	tr[++cnt]=nil;
	return cnt;
}

void B(int x1,int x2,int l,int r,int v){
	tr[x1].siz=tr[x2].siz+1;
	if (l==r) return;
	int mid=(l+r)>>1;
	if (v<=mid){
		tr[x1].rc=tr[x2].rc;
		tr[x1].lc=NEW();
		B(tr[x1].lc,tr[x2].lc,l,mid,v);
	}else{
		tr[x1].lc=tr[x2].lc;
		tr[x1].rc=NEW();
		B(tr[x1].rc,tr[x2].rc,mid+1,r,v);
	}
}

int C(int x1,int x2,int l,int r,int v){
	if (l==r) return l;
	int t= tr[tr[x2].lc].siz-tr[tr[x1].lc].siz;
	int mid=(l+r)>>1;
	if (v<=t) return C(tr[x1].lc,tr[x2].lc,l,mid,v);
	else return C(tr[x1].rc,tr[x2].rc,mid+1,r,v-t);
}

bool cmp_x(P p1,P p2){
	return p1.x<p2.x;
}
bool cmp_y(P p1,P p2){
	return p1.y<p2.y;
}

int sx[11],pos1,pos2,mxst,mnen,any1,any2;
void doit(){
	sx[0]=0;
	sx[1]=b[1]+b[4]+b[7];
	sx[2]=sx[1]+b[2]+b[5]+b[8];
	sx[3]=n;
	if (tox[sx[1]]==tox[sx[1]+1]) return;
	if (tox[sx[2]]==tox[sx[2]+1]) return;
	
	mxst=-1000000007;mnen=1000000007;
	for (int i=1;i<=3;i++){
		pos1=C(root[sx[i-1]],root[sx[i]],1,n,b[i]);
		pos2=C(root[sx[i-1]],root[sx[i]],1,n,b[i]+1);
		mxst=max(mxst,toy[pos1]);
		mnen=min(mnen,toy[pos2]);
		if (mxst>=mnen) return;
	}
	any1=mxst;
	
	mxst=-1000000007;mnen=1000000007;
	for (int i=1;i<=3;i++){
		pos1=C(root[sx[i-1]],root[sx[i]],1,n,b[i]+b[i+3]);
		pos2=C(root[sx[i-1]],root[sx[i]],1,n,b[i]+b[i+3]+1);
		mxst=max(mxst,toy[pos1]);
		mnen=min(mnen,toy[pos2]);
		if (mxst>=mnen) return;
	}
	any2=mxst;
	
	flag=1;
	printf("%.2lf %.2lf\n",(double)tox[sx[1]]+0.5,(double)tox[sx[2]]+0.5);
	printf("%.2lf %.2lf\n",(double)any1 +0.5,(double)any2 +0.5);
}

int used[11]={0};
void dfs(int x){
	if (flag) return;
	if (x>9){
		//for (int i=1;i<=9;i++){printf(" %d",b[i]);}printf("\n");
		if (!flag){
			doit();
		}
		return;
	}
	for (int i=1;i<=9;i++){
		if (!used[i]){
			used[i]=1;
			b[x]=a[i];
			dfs(x+1);
			used[i]=0;
		}
	}
}

int main(){
	scanf("%d",&n);
	for (int i=1;i<=n;i++){
		scanf("%d%d",&p[i].x,&p[i].y);
	}
	for (int i=1;i<=9;i++){
		scanf("%d",&a[i]);
	}
	sort(p+1,p+n+1,cmp_y);
	for (int i=1;i<=n;i++){
		p[i].ry=i;
		toy[i]=p[i].y;
	}
	sort(p+1,p+n+1,cmp_x);
	for (int i=1;i<=n;i++){
		p[i].rx=i;
		tox[i]=p[i].x;
	}
	
	nil.lc=nil.rc=nil.siz=0;
	tr[0]=nil;
	root[0]=0;
	for (int i=1;i<=n;i++){
		root[i]=NEW();
		B(root[i],root[i-1],1,n,p[i].ry);
	}
	
	dfs(1);
	if (!flag){
		printf("-1");
	}
	
	return 0;
}
```
*****
