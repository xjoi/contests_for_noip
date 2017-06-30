 # 比赛记录
 
 [比赛链接](https://cn.vjudge.net/contest/168406)
 
 ## A
 
 ### Problem description
 
 > 判断杠杆平衡
 
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
 
  ## D
 
 ### Problem description
 
 > 横行重排列，问最后的最大1组成的矩形大小
 
 ### Solution
 
 枚举每一列
 
 排列向右最大1的个数
 
 排序
 
 计算矩形大小
 
 ```cpp
  for(int i=1;i<=k;i++){
		for(int j=1;j<=n;j++){
			v[j]=m[j][i];
		}
		memset(count,0,sizeof count);
		for(int j=1;j<=n;j++){
			count[v[j]]++;
		}
		for(int j=1;j<=n;j++){
			count[j]+=count[j-1];
		}
		for(int j=1;j<=n;j++){
			f[count[v[j]]--]=v[j];
		}
		for(int j=1;j<=n;j++){
			MAX=max(f[j]*(n-j+1),MAX);
		}
	}
 ```
 
  ## F*
 
 ### Problem description
 
 > 每个点有颜色，询问一个点子树颜色大于k的颜色个数
 
 ### Solution
 
 就是莫队
 
 ```cpp
  for(int i=1;i<=m;i++){
		while(r<q[i].r)++su[++num[dc[++r]]];
		while(r>q[i].r)--su[num[dc[r--]]--];
		while(l>q[i].l)++su[++num[dc[--l]]];
		while(l<q[i].l)--su[num[dc[l++]]--];
		ans[q[i].id]=su[q[i].v];
	}
 ```
