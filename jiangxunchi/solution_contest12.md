# 比赛记录

[比赛链接](https://cn.vjudge.net/contest/168305)
## A
### Problem description
玄学的数学题
### Solution
玄学的公式
```cpp
scanf("%lld%lld%lld",&a,&b,&c);
printf("%lld",ll(min((c+1.0)*b/a,c)));
```
## D
### Problem description
数学题，有a[i]个人说第i种语言，一个k种语言，总共n个人，求有最少有多少人会说全部k种语言。
### Solution
玄学的贪心
```cpp
sum-=n*(k-1);
printf("%lld",sum<0?0:sum);
```
## G
### Problem description
爆搜题。
### Solution
爆搜即可。
```cpp
void dfs(int x){
	if(x==9){
		int val[10][10]; int stx=0,sty=0;
		for(int i=0;i<9;++i){
			for(int j=0;j<4;++j) for(int k=0;k<4;++k){
				val[stx+j][sty+k]=ans[i].a[j][k];
			}
			sty+=3; if(sty==9){
				stx+=3; sty=0;
			}	
		}
		for(int i=0;i<10;++i){
			for(int j=0;j<10;++j) printf("%d ",val[i][j]);
			printf("\n");
		}
		exit(0);
	}
	for(int i=0;i<9;++i) if(!vis[i]){
		ans[x]=a[i];
		for(int j=0;j<4;++j){
			ans[x].rot();
			bool suc=1;
			if(x%3) for(int k=0;k<4;++k){
				if(ans[x].a[k][0]!=ans[x-1].a[k][3]){
					suc=0; break;
				}
			}
			if(!suc) continue;
			if(x>2)for(int k=0;k<4;++k) if(ans[x].a[0][k]!=ans[x-3].a[3][k]){
				suc=0; break;
			}
			if(!suc) continue;
			vis[i]=1; dfs(x+1);  vis[i]=0;
		}
	}
}
```
***** 
# 赛后补题
## B
### Problem description
数学题。用n个人坐成一圈，规定某几个人必须坐在一起，求方案数。
### Solution
如果有环且不止一个连通块就不行，如果和一个人连着的边的数目大于2也不行。再求出连通块的个数，求一下阶乘，但由于第1个人的位置不能动，阶乘乘到连通块的个数减一就行了。再判断每个连通块的元素个数是否大于2，是的有正反两种排列，乘以2。
```cpp
#include<cstdio>
typedef long long ll;
const ll P=1e9+7;
int fa[101],d[101],sz[101]; bool b[101][101];
int getf(int x){return fa[x]==x?x:fa[x]=getf(fa[x]);}
int main(){
  int n,m; bool cc=0; scanf("%d%d",&n,&m); int val=n;
  if(n==2){
    printf("1"); return 0;
  }
  for(int i=1;i<=n;++i) fa[i]=i,sz[i]=1;
  for(int i=1;i<=m;++i){
    int u,v=i; scanf("%d",&u);
    if(b[u][v]) continue; b[u][v]=b[v][u]=1;
    ++d[u]; ++d[v]; u=getf(u); v=getf(v);
    if(u==v) cc=1; else{
      sz[v]+=sz[u]; fa[u]=v; --val;
    }
  }
  if(val>1&&cc){
    printf("0"); return 0;
  }
  cc=0;
  for(int i=1;i<=n;++i) if(d[i]>2){
      cc=1; break;
  }
  if(cc){
    printf("0"); return 0;
  }
  ll ans=1;
  for(int i=1;i<val;++i) (ans*=i)%=P;
  for(int i=1;i<=n;++i) if(fa[i]==i&&sz[i]>1) (ans*=2)%=P;
  printf("%lld",ans); return 0;
}
```
## C
### Problem description
给你一个四边形，求对称轴的数量乘2
### Solution
枚举对角线和两边的中点的连线，求出答案。
```cpp
#include<cstdio>
#include<complex>
using namespace std;
typedef complex<int> vec;
int sqrdis(const vec &a){
  return real(a)*real(a)+imag(a)*imag(a);
}
bool equaldis(const vec &a,const vec &b,const vec &c,const vec &d){
  return sqrdis(c-a)==sqrdis(d-a)&&sqrdis(c-b)==sqrdis(d-b);
}
int main(){
  vec a[5];
  for(int i=1;i<=4;++i){
    int x,y; scanf("%d%d",&x,&y);
    a[i]=vec(x,y); a[i]*=2;
  }
  int ans=0;
  ans+=2*equaldis(a[1],a[3],a[2],a[4])+2*equaldis(a[2],a[4],a[1],a[3]);
  vec b[5];
  for(int i=1;i<=3;++i) b[i]=(a[i]+a[i+1])/2;
  b[4]=(a[4]+a[1])/2;
  ans+=2*(equaldis(b[1],b[3],a[1],a[2])&&equaldis(b[1],b[3],a[3],a[4]));
  ans+=2*(equaldis(b[2],b[4],a[2],a[3])&&equaldis(b[2],b[4],a[1],a[4]));
  printf("%d\n",ans); return 0;
}
```
## D
### Problem description
将一个序列拆成两个非空的单调序列。
### Solution
如果这两个序列都是上升或都是下降，可以直接贪心，上升的话就接到大的后面，下降的话就接到小的后面。一升一降的情况可以dp，设f[i]，g[i]分别为第i个数在上升序列下降序列末尾数的最大值和第i个数在下降序列上升序列末尾数的最小值，可以很容易写出dp方程。dp时需要记录路径。贪心的时候如果发现一个序列为空，就把另一个序列的末尾元素接到这个序列上。
```cpp
#include<cstdio>
#include<algorithm>
#include<cstdlib>
#include<cstring>
const int N=100000,inf=0x3f3f3f3f;
int n,a[N+1];
void solve1(){
  int f[N+1]={0},g[N+1]={0},cntf=0,cntg=0;
  for(int i=1;i<=n;++i){
	int Max=-1; bool b=0;
	if(a[i]>f[cntf]) Max=f[cntf];
	if(a[i]>g[cntg]&&g[cntg]>Max){
	  Max=g[cntg]; b=1;
	}
	if(Max==-1) return;
	if(b) g[++cntg]=a[i]; else f[++cntf]=a[i];
  }
  if(cntg==0){
	g[++cntg]=f[cntf--];
  }
  printf("%d %d\n",cntf,cntg);
  for(int i=1;i<=cntf;++i) printf("%d ",f[i]);
  printf("\n");
  for(int i=1;i<=cntg;++i) printf("%d ",g[i]);
  exit(0);
}
void solve2(){
  int f[N+1]={inf},g[N+1]={inf},cntf=0,cntg=0;
  for(int i=1;i<=n;++i){
	int Min=inf+1; bool b=0;
	if(a[i]<f[cntf]) Min=f[cntf];
	if(a[i]<g[cntg]&&g[cntg]<Min){
	  Min=g[cntg]; b=1;
	}
	if(Min==inf+1) return;
	if(b) g[++cntg]=a[i]; else f[++cntf]=a[i];
  }
  if(cntg==0) g[++cntg]=f[cntf--];
  printf("%d %d\n",cntf,cntg);
  for(int i=1;i<=cntf;++i) printf("%d ",f[i]);
  printf("\n");
  for(int i=1;i<=cntg;++i) printf("%d ",g[i]);
  exit(0);
}
void solve3(){
  int f[N+1],g[N+1],pref[N+1]={0},preg[N+1]={0}; bool vis[N+1];
  memset(f,0,sizeof f); memset(g,0x3f,sizeof g);
  memset(pref,0,sizeof pref); memset(preg,0,sizeof preg);
  f[1]=inf; g[1]=0;
  for(int i=2;i<=n;++i){
	if(a[i]>a[i-1]){
	  f[i]=f[i-1]; pref[a[i]]=a[i-1];
	}else{
	  g[i]=g[i-1]; preg[a[i]]=a[i-1];
	}
	if(a[i]>g[i-1]&&a[i-1]>f[i]){
	  f[i]=a[i-1]; pref[a[i]]=g[i-1];
	}
	if(a[i]<f[i-1]&&a[i-1]<g[i]){
	  g[i]=a[i-1]; preg[a[i]]=f[i-1];
	}
  }
  if(f[n]==0&&g[n]==inf) return; int ansf[N+1],cntf=0;
  int p; for(p=n;!f[p];--p); memset(vis,0,sizeof vis);
  for(p=a[p];p;p=pref[p]){
	vis[p]=1; ansf[++cntf]=p;
  }
  printf("%d %d\n",cntf,n-cntf);
  for(int i=cntf;i>=1;--i) printf("%d ",ansf[i]); printf("\n");
  for(int i=n;i>=1;--i) if(!vis[i]) printf("%d ",i);
  exit(0);
}
int main(){
  scanf("%d",&n);
  for(int i=1;i<=n;++i) scanf("%d",&a[i]);
  solve1(); solve2(); solve3();
  printf("Fail"); return 0;
}
```
