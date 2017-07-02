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
