# 比赛记录
 
 [比赛链接](https://cn.vjudge.net/contest/168406)
 
 ## A
 
 ### Problem description
 
 > 判断杠杆平衡
 
 ### data limit 1 ≤ n ≤ 100 000, 1 ≤ c ≤ 109 +2s
 
 ### Solution
 
~~仔细分析一下，这个题可以用一个printf语句解决~~

sb的模拟就是了
 
 ```cpp
  for(int i=k-1;i>=0;i--){
		v++;
		if(c[i]!='='){
			le+=v*(c[i]-'0');
		}
	}
	int ri=0;
	v=0;
	for(int i=k+1;i<n;i++){
		v++;
		if(c[i]!='='){
			ri+=v*(c[i]-'0');
		}
	}
 ```
 
 ## B
 
 ### Problem description
 
 > 简化借钱的帐
 
 ### data limit 1 ≤ |s| ≤ 50 000 +2s
 
 ### Solution
 
 直接算每个人的进出
 
 ```cpp
  for(int i=1;i<=m;i++){
		scanf("%d%d%d",&a,&b,&c);
		x[a]+=c;
		x[b]-=c;
	}
 ```
 
  ## C *
 
 ### Problem description
 
 > 一个包含数位1698的数，判断如何重组成7的倍数
 
 ### data limit 1 ≤ n ≤ 100 000 +2s
 
 ### Solution
 
一开始题没看懂

1689各取一个

其他原样输出

最后靠1689补余数

```cpp
  while((v=getchar())&&v<='9'&&v>='0'){
		int f=v-'0';
		if(f==1&&!vis1){
			vis1=1;
		}else if(f==6&&!vis6){
			vis6=1;
		}else if(f==8&&!vis8){
			vis8=1;
		}else if(f==9&&!vis9){
			vis9=1;
		}else if(f==0){
			z++;
		}else{
			ans=ans*10+f;
			ans%=7;
			putchar(v);
		}
	}
//	cout<<endl<<ans<<endl;
//	for(int i=1;i<=z;i++){
//		ans=ans*10;
//		ans%=7;
//	}
	ans=ans*10000%7;
			switch(ans){
			case 0:{
				printf("1869");
				break;
			}
			case 5:{
				printf("1689");
				break;
			}
			case 6:{
				printf("1968");
				break;
			}
			case 4:{
				printf("6198");
				break;
			}
			case 1:{
				printf("1896");
				break;
			}
			case 2:{
				printf("1986");
				break;
			}
			case 3:{
				printf("1698");
				break;
			}
		}
 ```

## D *
 
 ### Problem description
 
 >给出一个无向图，一些边是可修改边权的， 求一种修改方案，使s到t最短路为L。
 
 ### data limit 2 ≤ n ≤ 1000,  1 ≤ m ≤ 10 000,  1 ≤ L ≤ 109,  0 ≤ s, t ≤ n - 1,  s ≠ t,0 ≤ ui, vi ≤ n - 1,  ui ≠ vi,  0 ≤ wi ≤ 109 +4s
 
 ### Solution
 
 两遍spfa。
 
 第一遍求t到每个点的最短路。
 
 第二遍求s到每个点的最短路，当遇到可修改边xy就修改为L-dt[y]-ds[x]。
 
 这样保证了最短路大于等于L。
 
 最后如果最短路大于L无解。
 
 ```cpp
 void spfat(){
	memset(dt,0x3f,sizeof dt);
	queue<int> Q;
	Q.push(t);
	inq[t]=1;
	dt[t]=0;
	while(!Q.empty()){
		int x=Q.front();Q.pop();inq[x]=0;
		for(int i=0;i<G[x].size();i++){
			Edge& e=edges[G[x][i]];
//			cerr<<e.u<<' '<<e.len<<' '<<e.v<<' '<<dt[e.v]<<' '<<dt[x]<<endl;
			if(dt[e.v]>dt[x]+e.len){
				dt[e.v]=dt[x]+e.len;
				if(!inq[e.v]){
					inq[e.v]=1;
					Q.push(e.v);
				}
			}
		}
	}
}
void spfas(){
	memset(ds,0x3f,sizeof ds);
	queue<int> Q;
	memset(inq,0,sizeof inq);
	Q.push(s);
	inq[s]=1;
	ds[s]=0;
	while(!Q.empty()){
		int x=Q.front();Q.pop();inq[x]=0;
		for(int i=0;i<G[x].size();i++){
			Edge& e=edges[G[x][i]];
			if(e.k==1){
				e.len=max(e.len,L-ds[x]-dt[e.v]);
				edges[G[x][i]^1].len=e.len;
			}
			if(ds[e.v]>ds[x]+e.len){
				ds[e.v]=ds[x]+e.len;
				if(!inq[e.v]){
					inq[e.v]=1;
					Q.push(e.v);
				}
			}
		}
	}
}
```
 
