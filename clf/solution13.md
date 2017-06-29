# 比赛记录

# # CodeForces - 376A

## Solution

> 杠杆平衡，注意开long long.

```cpp
#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;
char s[1000005];
int main() {
	int p;
	long long l=0,r=0;
	scanf("%s",s);
	int len=strlen(s);
	for(int i=0;i<len;i++) if(s[i]=='^') {p=i;break;}
	for(int i=p-1;i>=0;i--) {
		if(isdigit(s[i])) l+=(long long)(p-i)*(s[i]-'0');
	}
	for(int i=p+1;i<len;i++) {
		if(isdigit(s[i])) r+=(long long)(i-p)*(s[i]-'0');
	}
	if(l>r) puts("left");
	else if(l<r) puts("right");
	else puts("balance");
	return 0;
}
```

# # CodeForces - 376B

## Solution

> 这玩意是能贪心的，统计每个人总共欠的和借被人的，然后贪心地尽量多的抵销即可

```cpp
#include<cstdio>
#include<iostream>
using namespace std;
int n,m,x,y,c,money[105];
int abs(int x) {return x>0?x:-x;}
int main() {
	int ans=0;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++) scanf("%d%d%d",&x,&y,&c),money[x]+=c,money[y]-=c;
	for(int i=1;i<=n;i++) ans+=abs(money[i]);
	printf("%d\n",ans/2);
	return 0;
}
```

# # CodeForces - 375C

## Solution

> 我的是非正解乱搞，正解这么说的：1、6、8、9组成的四位数能够成7的完整的剩余系，然后把非零数全放在前面，1689组合一下，再放0.

```cpp
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
using namespace std;
char s[1000005];
int di[1000000];
bool used[11];
int main() {
	int len,now=0;
	scanf("%s",s);
	len=strlen(s);
	int p=len,cnt=0,tot=0;
	while(cnt<4) {
		p--;
		di[++tot]=s[p]-'0';
		if(!used[s[p]-'0']) used[s[p]-'0']=1,cnt++;
	}
	for(int i=0;i<p;i++) now=(now*10+s[i]-'0')%7;
	sort(di+1,di+tot+1);
	int u=now;
	bool found=0;
	for(int i=1;i<=tot;i++) u=(u*10+di[i])%7;
	if(!u) found=1;
	while(!found&&next_permutation(di+1,di+tot+1)) {
		u=now;
		for(int i=1;i<=tot;i++) u=(u*10+di[i])%7;
		if(!u) found=1;
	}
	for(int i=0;i<p;i++) printf("%c",s[i]);
	for(int i=1;i<=tot;i++) printf("%d",di[i]);
	printf("\n");
	return 0;
}
```

# # CodeForces - 375D

## Solution

> 排个序，贪个心即可.

```cpp
#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;
char s[5015][5015];
int arr[5015],ri[5015][5015],buc[5015];
int n,m;
int main() {
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++) scanf("%s",s[i]+1);
	memset(ri,0,sizeof(ri));
	for(int i=1;i<=n;i++) {
		for(int j=m;j>=1;j--) if(s[i][j]=='1') {
			if(s[i][j+1]=='1') ri[i][j]=ri[i][j+1]+1;
			else ri[i][j]=1;
		}
	}
	int ans=0,cnt;
	for(int j=1;j<=m;j++) {
		memset(buc,0,sizeof(buc));
		for(int i=1;i<=n;i++) buc[ri[i][j]]++;
		cnt=0;
		for(int i=5000;i>0;i--) {
			if(!buc[i]) continue;
			cnt+=buc[i];
			ans=max(ans,cnt*i);
		}
	}
	printf("%d\n",ans);
	return 0;
}
```

# 赛后补题

# # CodeForces - 375E

## Solution

> 类似SCOI的围豆豆，状态压缩数组要开大

```cpp
#include<cstdio>
#include<queue>
#include<cstring>
#include<iostream>
using namespace std;
struct node{int x,y,stat;};
char map[25][25];
int x[20],y[20],w[20],f[50][50][300];
int dx[4]={0,0,1,-1};
int dy[4]={1,-1,0,0};
queue<node> Q;
int main() {
	int n,m,cnt=0,sx,sy;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++) {
		scanf("%s",map[i]+1);
		for(int j=1;j<=m;j++) {
			if(isdigit(map[i][j])) {
				x[map[i][j]-'0']=i;
				y[map[i][j]-'0']=j;
				cnt++;
			}
		}
	}
	int ccf=cnt;
	for(int i=1;i<=cnt;i++) scanf("%d",&w[i]);
	for(int i=1;i<=n;i++) {
		for(int j=1;j<=m;j++) {
			if(map[i][j]=='B') {
				x[++cnt]=i;
				y[cnt]=j;
				w[cnt]=0;
			} else if(map[i][j]=='S') {
				map[i][j]='.';
				sx=i; sy=j;
			}
		}
	}
	memset(f,-0x3f,sizeof(f));
	Q.push((node){sx,sy,0});
	f[sx][sy][0]=0;
	node now;
	int nx,ny,nt,nm;
	int mx,my,mt,mm;
	while(!Q.empty()) {
		now=Q.front();
		Q.pop();
		nx=now.x;
		ny=now.y;
		nt=now.stat;
		nm=f[nx][ny][nt];
		for(int i=0;i<4;i++) {
			mx=nx+dx[i];
			my=ny+dy[i];
			if(map[mx][my]!='.') continue;
			mm=nm-1;
			mt=nt;
			if(dy[i]!=0) {
				for(int j=1;j<=cnt;j++) if(y[j]==max(my,ny)&&x[j]<mx) {
					mt^=(1<<(j-1));
					if(mt&(1<<(j-1))) mm+=w[j];
					else mm-=w[j];
				}
			}
			if(f[mx][my][mt]<-1000000) {
				f[mx][my][mt]=mm;
				Q.push((node){mx,my,mt});
			}
		}
	}
	int ans=0;
	for(int j=0;j<(1<<ccf);j++) ans=max(ans,f[sx][sy][j]);
	printf("%d\n",ans);
	return 0;
}
```

# # CodeForces - 375E

## Solution

> 分块，然后用一下莫队的思想省时间.

```cpp
#include<cstdio>
#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;
const int N=100005;
struct node{int l,r,bound,id;}que[N];
int arr[N],clo=0;
int fir[N],nxt[N*2],v[N*2],ct=0;
int L[N],R[N],blocksize;
int nar[N],cnt[N],suf[N],ans[N];
inline void add(int x,int y) {
	v[++ct]=y;
	nxt[ct]=fir[x];
	fir[x]=ct;
}
inline void dfs(int x,int pa) {
	L[x]=++clo;
	nar[L[x]]=arr[x];
	for(int i=fir[x];i;i=nxt[i]) if(v[i]!=pa) dfs(v[i],x);
	R[x]=clo;
}
inline bool cmp(node a,node b) {
	if(a.r/blocksize==b.r/blocksize) return a.l<b.l;
	return a.r<b.r;
}
int main() {
	int n,m,x,y;
	scanf("%d%d",&n,&m);
	blocksize=(int)sqrt(n);
	for(int i=1;i<=n;i++) scanf("%d",&arr[i]);
	for(int i=1;i<n;i++) {
		scanf("%d%d",&x,&y);
		add(x,y); add(y,x);
	}
	dfs(1,-1);
	for(int i=1;i<=m;i++) {
		scanf("%d%d",&x,&y);
		que[i].l=L[x];
		que[i].r=R[x];
		que[i].id=i;
		que[i].bound=y;
	}
	sort(que+1,que+m+1,cmp);
	int l=1,r=0;
	for(int i=1;i<=m;i++) {
		while(l<que[i].l) {
			suf[cnt[nar[l]]]--;
			cnt[nar[l]]--;
			l++;
		}
		while(l>que[i].l) {
			l--;
			cnt[nar[l]]++;
			suf[cnt[nar[l]]]++;
		}
		while(r>que[i].r) {
			suf[cnt[nar[r]]]--;
			cnt[nar[r]]--;
			r--;
		}
		while(r<que[i].r) {
			r++;
			cnt[nar[r]]++;
			suf[cnt[nar[r]]]++;
		}
		ans[que[i].id]=suf[que[i].bound];
	}
	for(int i=1;i<=m;i++) printf("%d\n",ans[i]);
	return 0;
}
```
