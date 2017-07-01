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

