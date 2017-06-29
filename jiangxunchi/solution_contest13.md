# 比赛记录

[比赛链接](https://cn.vjudge.net/contest/168406)
## A
### Problem description
杠杆？？
### Solution
~简单的几何学~ 先求出支点，在算一下就好了。
```cpp
for(int i=1;i<=len;++i) if(c[i]>='0'&&c[i]<='9')
	w+=(c[i]-'0')*(i-pos);
```
## B
### Problem description
给你几个a欠b总共c元钱的关系，求抵消掉之后欠钱的总额。
### Solution
求出每个人总共还欠多少(负数)或还借出去多少(正数)，再求出总额就好了。
```cpp
for(int i=1;i<=m;++i){
	int a,b,c; scanf("%d%d%d",&a,&b,&c);
	val[a]-=c; val[b]+=c;
}
int ans=0;
for(int i=1;i<=n;++i)if(val[i]>0){
	ans+=val[i];
}
```
## C
### Problem description
给你含1,6,8,9的一个数，让你重新排列数位使这个数能被7整除。
### Solution
可以发现1689这4个数的全排列除以7的余数0到6都有，那就把其他数位上的数提出来，放前面，再把1个1689排列一下放后面使能被7整除，再把所有0提出来放最后。
```cpp
int l=strlen(c+1),p=10000%7,val=0;
	for(int i=1;i<=l;++i){
		if(c[i]=='1'||c[i]=='6'||c[i]=='8'||c[i]=='9')
			if(!vis[c[i]-'0']){
				vis[c[i]-'0']=1; continue;
			}
		if(c[i]=='0'){
			++onum; continue;
		}
		printf("%c",c[i]); val=(val*10+p*(c[i]-'0'))%7;
	}
printf("%d",div[(7-val)%7]); for(int i=1;i<=onum;++i) printf("0");
```
## D
### Problem description
给你一个01矩阵，让你求重新排列行之后最大的全1子矩阵面积。
### Solution
先预处理出r[i][j]为（i,j）往右有多少个一，再枚举子矩阵左端点，之后枚举长度，通过桶排得到以枚举的左端点为开端，长度大于等于枚举的长度的行有几个，然后更新最大值。
```cpp
for(int l=1;l<=m;++l){
		memset(cnt,0,sizeof cnt);
		for(int j=1;j<=n;++j) ++cnt[r[j][l]];
		for(int j=m-1;j>=0;--j) cnt[j]+=cnt[j+1];
		for(int j=0;j<=m;++j){
			int val=j*cnt[j];
			if(val>ans) ans=val;
		}
}
```
***** 
# 赛后补题
## E
### Problem description
给你一副图，让你求不包含所有的炸弹而包含一部分宝藏的最后价值的最大值。
### Solution
将炸弹也视为宝藏，并将价值设为-inf。对于每个宝藏向右引一条射线，用一个01串表示对于每一个宝藏穿过次数的奇偶性，然后将01串转化为数字保存。如果穿过一个宝藏奇数次就说明包含它。最后bfs就行了。
```cpp
#include<cstdio>
#include<cctype>
#include<queue>
#include<cstring>
using namespace std;
const int inf=0x3f3f3f3f;
const int dir[4][2]={0,1,1,0,0,-1,-1,0};
int dis[21][21][256],n,m,stx,sty;
int xx[9],yy[9],val[9],elnum=0,trnum=0,vval[9];
bool a[21][21];
struct data{int x,y,val;}; queue<data> Q; 
int changebit(int val,int bit){
	return val+((val&(1<<bit-1))?-1:1)*(1<<bit-1);
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;++i) for(int j=1;j<=m;++j){
		char c;
		for(c=getchar();!isgraph(c);c=getchar());
		if(c=='B'){
			xx[++elnum]=i; yy[elnum]=j; val[elnum]=-1e7; a[i][j]=1;
		}else if(isdigit(c)){
			xx[++elnum]=i; yy[elnum]=j; val[elnum]=c-'0'; a[i][j]=1; ++trnum;
		}else if(c=='S'){
			stx=i; sty=j;
		}else if(c=='#') a[i][j]=1;
	}
	for(int i=1;i<=trnum;++i) scanf("%d",&vval[i]);
	for(int i=1;i<=elnum;++i) if(val[i]!=-1e7) val[i]=vval[val[i]];
	memset(dis,0x3f,sizeof dis); dis[stx][sty][0]=0;
	Q.push({stx,sty,0});
	for(;!Q.empty();Q.pop()){
		data x=Q.front();
		for(int i=0;i<4;++i){
			data e={x.x+dir[i][0],x.y+dir[i][1],x.val};
			if(e.x<=0||e.x>n||e.y<=0||e.y>m||a[e.x][e.y]) continue;
			for(int j=1;j<=elnum;++j)
				if((i==1&&e.x==xx[j]&&e.y<yy[j])||(i==3&&e.x==xx[j]-1&&e.y<yy[j]))
					e.val=changebit(e.val,j);
			if(dis[e.x][e.y][e.val]==inf){
				dis[e.x][e.y][e.val]=dis[x.x][x.y][x.val]+1;
				Q.push(e);
			}
		}
	}
	int ans=0;
	for(int i=0;i<(1<<elnum);++i){
		int sum=0;
		for(int j=0;j<elnum;++j) if(i&(1<<j)) sum+=val[j+1];
		sum-=dis[stx][sty][i]; if(sum>ans) ans=sum;
	}
	printf("%d",ans); return 0;
}
```
## F
### Problem description
给你一棵树，每个节点有一个颜色，再给你几个询问，求以v为根的子树中有多少种颜色出现次数大于等于k。
### Solution
通过dfs序将每个询问转化为区间询问，再用莫队，维护每个颜色的出现次数和出现次数大于等于k的颜色种类数。
```cpp
void insert(int x){
	++val[++color_cnt[dfs_co[x]]];
}
void erase(int x){
	--val[color_cnt[dfs_co[x]]--];
}
for(int i=1;i<=m;++i){
		for(;R<a[i].r;insert(++R));
		for(;L>a[i].l;insert(--L));
		for(;R>a[i].r;erase(R--));
		for(;L<a[i].l;erase(L++));
		ans[a[i].id]=val[a[i].k];
}
```
