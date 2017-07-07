[比赛链接](http://210.33.19.101/contest/753)

# 比赛中解决的问题
## A
### Problem description
> 在一个无限大的平面上，有n条直线和m个交点，求平面被分成了多少块  
（没有三条及以上的直线交于同一点）

### Data Limit： 0<=n,m<=10^10000 Time Limit: 1s
### Solution
> 找规律后可以发现，平面数=直线数+交点数+1，高精度计算

### Code
```cpp
	int lena=s1.length();
    int lenb=s2.length();
    for (int i=0;i<lena;++i) a[lena-i]=s1[i]-'0';
    for (int i=0;i<lenb;++i) b[lenb-i]=s2[i]-'0';
    a[1]++;
    int len=lena+lenb;
    for (int i=1;i<=len;++i){
        ans[i]+=a[i]+b[i];
        ans[i+1]+=ans[i]/10;
        ans[i]%=10;
    }
    while (ans[len]==0&&len>1) len--;
    for (int i=len;i>=1;--i) printf("%d",ans[i]);
```
*****


## B
### Problem description
> 一只蒲公英上有n个种子，保证每个种子都能发芽并成长成一样的蒲公英，求m年后，一只蒲公英变为了多少只  
将答案分别mod 19941023和19950814输出

### Data Limit： 0<=n,m<=10^9 Time Limit: 1s
### Solution
> 快速幂，输出n^m

### Code
```cpp
	while (b>0){
        if (b%2==1) ans=(ans*a)%mod;
        b/=2;
        a=(a*a)%mod;
    }
```
*****

# 赛后补题

## C
### Problem description
> 给定一些长短不一的n个小木棍，求所能围成的矩形的最大面积，否则输出无解

### Data Limit： 1<=n<=16,1<=木棍长度<=15 Time Limit: 1s
### Solution
> dfs+剪枝 or dp  
dp做法：dp[i][j][k]表示到第i个木棍，矩形的水平的两条边之间相差j，竖直的两条边之间相差k，
此时矩形两边的长度分别为dp[i][j][k].x和dp[i][j][k].y  
根据数据规模，所有木棍长度的一半最多为240，因此可行

### Code
```cpp
	for (int i=0;i<=n;i++)
		for (int j=0;j<=120;j++)
			for (int k=0;k<=120;k++)
				dp[i][j][k].x=-10000, dp[i][j][k].y=10000;
	dp[0][0][0].x=0; dp[0][0][0].y=0;//初始化
	for (int i=1;i<=n;i++)
		for (int j=0;j<=120;j++)
			for (int k=0;k<=120;k++){
				xint tmp;
				dp[i][j][k]=dp[i-1][j][k];
				if (j>=l[i]) tmp.x=dp[i-1][j-l[i]][k].x+l[i],tmp.y=dp[i-1][j-l[i]][k].y;
					else tmp.x=dp[i-1][l[i]-j][k].x+j,tmp.y=dp[i-1][l[i]-j][k].y;
				dp[i][j][k]=maxx(dp[i][j][k],tmp);
				if (j+l[i]<=240) tmp.x=dp[i-1][j+l[i]][k].x,tmp.y=dp[i-1][j+l[i]][k].y;
				dp[i][j][k]=maxx(dp[i][j][k],tmp);
				if (k>=l[i]) tmp.x=dp[i-1][j][k-l[i]].x,tmp.y=dp[i-1][j][k-l[i]].y+l[i];
					else tmp.x=dp[i-1][j][l[i]-k].x,tmp.y=dp[i-1][j][l[i]-k].y+k;
				dp[i][j][k]=maxx(dp[i][j][k],tmp);
				if (k+l[i]<=240) tmp.x=dp[i-1][j][k+l[i]].x,tmp.y=dp[i-1][j][k+l[i]].y;
				dp[i][j][k]=maxx(dp[i][j][k],tmp);
			}
	if (dp[n][0][0].x*dp[n][0][0].y<=0) printf("No Solution");
		else printf("%d",dp[n][0][0].x*dp[n][0][0].y);
```
*****
