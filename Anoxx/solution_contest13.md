# 比赛记录

[比赛链接div1](http://codeforces.com/contest/375)</br>
[比赛链接div2](http://codeforces.com/contest/376)

## div 2:A
### Problem description
> 给你一个天平判断天平平衡状态
### Solution
暴力
```cpp
none
```

## div 2:B
### Problem description
> 懒得描述总之水题
### Solution
暴力
```cpp
none
```

## div 1:A(div 2:C)
### Problem description
> 给你10^6长的数字，保证包含1、6、8、9，你可以任意排列这些数字，求能被7整除的排列
### Solution
注意到1、6、8、9的24中排列%7包含了0~6，所以只需要把一组1、6、8、9扔最后，暴力对其他数取%后暴力找排列即可。
```cpp
none
```

## div 1:B(div 2:D)
### Problem description
> 给你一个01矩阵，行与行之间可以互换，求最大1子矩阵
### Solution
可以预处理出i行以j结尾的的连续的1的个数f[i,j]，然后对每一列j将f[i,j]排序，然后从大到小取矩阵大小最值即可
```cpp
	for(int i=1;i<=m;i++){
		sort(f[i]+1,f[i]+1+n);
		mx=0;mi=0x3f3f3f3f;
		for(int j=n;j>=1;j--){
			mi=min(mi,f[i][j]);
			mx=max(mx,mi*(n-j+1));
		}
		ans=max(mx,ans);
	}
```

## div 1:C(div 2:E)
### Problem description
> 给你一个n\*m的矩阵，矩阵包含空格，起点，炸弹，宝藏和障碍，每个宝藏有它的价值，获得宝藏的唯一途径是走出一条围住它的封闭路径
> 你只能从起点出发走空格并回到起点，每走一步花费1，炸弹不能围进去，求最大获利，宝藏和炸弹数量和不超过8
### Solution
注意到对于每一个宝藏或炸弹作出一条射线，若射线交路径奇数次则宝藏或炸弹必然会被路径围住，又因为数量和不超过8，所以可以用状压去做，bfs遍历即可
```cpp
void add(int x,int y,int s,int k,int w){
	v[x][y][s]=1;f[x][y][s]=w;kf[x][y][s]=k;
	//printf("%d %d %d %d %d\n",x,y,s,k,w);
	q.push(node(x,y,s,k));
}
void bfs(int x,int y){
	memset(f,-0x3f,sizeof(f));
	add(x,y,0,0,0);
	while(!q.empty()){
		node now=q.front();q.pop();
		for(int i=0;i<4;i++){
			int nx=now.x+dx[i],ny=now.y+dy[i];
			if(a[nx][ny]==1){
				int nw=f[now.x][now.y][now.s],ns=now.s,nk=now.k+1;
				if(abs(dx[i])==1){
					int u=min(now.x,nx);
					for(int j=1;j<=trm;j++)
					if(px[j]==u&&py[j]<ny){
					  ns^=(1<<(j-1));
						if(ns&(1<<(j-1)))nw+=val[j];else nw-=val[j];
					}
					for(int j=1;j<=bm;j++)
					if(bx[j]==u&&by[j]<ny){//printf("%d\n",by[j]);
						ns^=1<<(j+trm-1);
					}
				}
				if(!v[nx][ny][ns])add(nx,ny,ns,nk,nw);
			}
		}
	}
	for(int i=0;i<(1<<(trm));i++)
	ans=max(ans,f[x][y][i]-kf[x][y][i]);
}
```

***** 
# 赛后补题

## div 1:D
### Problem description
> 给你一颗n个节点有根树，每个节点有自己的颜色，m次询问，每次询问x，k表示求x的子树中数量不小于k的颜色种类，所有数据都不超过10^5
### Solution
首先可以先取dfs序将点变成区间，于是转化为求区间数量不小于k的颜色种类，可以用莫队+分块搞定
```cpp
  int l=1,r=0;//cp[i]为dfs序中第i个遍历的点的颜色
  for(int i=1;i<=m;i++){
		while (r<q[i].r) ++su[++num[cp[++r]]];
		while (l<q[i].l) --su[num[cp[l++]]--];
		while (l>q[i].l) ++su[++num[cp[--l]]];
		while (r>q[i].r) --su[num[cp[r--]]--];
		ans[q[i].id]=su[q[i].k];
	}
```

## div 1:E
### Problem description
> 给你一颗n个节点带权树，每个节点有颜色红或黑，每个点必须且尽可以被距离小于等于D的黑点控制，你可以进行一个红点和一个黑点的交换，求使所有点都被控制的最小交换次数
### Solution
首先以每个点为根遍历树，求出两点间的路径长度。而后进行树上dp，对于每一个节点，我们设：</br>
　　f[i][j][k]为第i号点被k控制且以i为根的子树有j个黑点的最小交换次数</br>
　　tmp[i][j]为对于一个点的儿子i，i与i之前的兄弟各自的子树全部被控制且这些子树和兄弟中共j个黑点的最小交换次数</br>
　　best[i][j]为i及i的子树被控制且i及i子树拥有j个黑点的最小交换次数</br>
于是对于每个点i都有两种情况：</br>
　　1、i的儿子p也被who控制：tmp[p+1][j+k]=min(tmp[p+1][j+k],tmp[p][j]+f[child[i][p]][k][who]);</br>
　　2、i的儿子p不被who控制：tmp[p+1][j+k]=min(tmp[p+1][j+k],tmp[p][j]+best[child[i][p]][k]);（其中k为p子树有的黑点数</br>
显然f[i][j][who]=tmp[sz][j];（sz为x的儿子个数</br>
相应的，best[i][j+1]=min(best[i][j+1],f[i][j][who]+(col[who]==0))</br>
答案即为best[1][totblack]</br>
```cpp
        son[x]=1;
	for(int i=fi[x];i;i=ne[i])if(a[i]!=fa){
		dfs(a[i],x);
		son[x]+=son[a[i]];
		child[x].pb(a[i]);
	}
	int sz=child[x].size();
	for(int who=1;who<=n;who++)
	if(dis[x][who]<=D){
		for(int i=0;i<=sz;i++)for(int j=0;j<=son[x];j++)tmp[i][j]=inf;//printf("%d %d\n",x,fa);
		tmp[0][0]=tmp[0][1]=0;
		int tott=1;
		for(int i=0;i<sz;i++){
			for(int j=0;j<=tott&&j<=totblack;j++)
			for(int k=0;k<=son[child[x][i]]&&k+j<=totblack;k++)
			if(tmp[i][j]!=inf){
				if(f[child[x][i]][k][who]!=inf)tmp[i+1][j+k]=min(tmp[i+1][j+k]==inf?0x3f3f3f3f:tmp[i+1][j+k],tmp[i][j]+f[child[x][i]][k][who]);
				if(best[child[x][i]][k]!=inf)tmp[i+1][j+k]=min(tmp[i+1][j+k]==inf?0x3f3f3f3f:tmp[i+1][j+k],tmp[i][j]+best[child[x][i]][k]);
			}
			tott+=son[child[x][i]];
		}
        for(int i=0;i<=son[x];i++)f[x][i][who]=tmp[sz][i];
	}	
	for(int i=0;i<=son[x]&&i<totblack;i++){
		best[x][i+1]=inf;
		for(int who=1;who<=n;who++)if(f[x][i][who]!=inf){
			best[x][i+1]=min(best[x][i+1]==inf?0x3f3f3f3f:best[x][i+1],f[x][i][who]+(col[who]==0));
		}
	}
```
