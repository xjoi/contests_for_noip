[比赛链接](https://cn.vjudge.net/contest/168929#overview)

# 比赛中解决的问题
## A 
>主要算法：暴力或扩欧
### Problem description
> 求b+xa和d+yc相等的最小整数解

### Data Limit：a,b,c,d<=100  Time Limit: 1s

### Solution
> 直接暴力循环答案，直到符合题目条件

### Code
```cpp
if (d>b) swap(b,d),swap(a,c);
	while (1){
		if ((b-d)%c==0){
			cout<<b; return 0;
		}
		++j; b+=a;
		if (b>10000000) {
			cout<<-1; return 0;
		}
	}
```
*****


## B
>主要算法：暴力
### Problem description
> 如果有一组中没有±x（如3和-3），则输出"NO",否则输出"YES"

### Data Limit：n,m<=1e4  Time Limit: 1s
### Solution
> 暴力搜索

### Code
```p
for i:=1 to m do
begin
   fillchar(a,sizeof(a),0);
   bo:=false;
   read(k);
   for j:=1 to k do
   begin read(b[j]); inc(a[b[j]]); end;
   for j:=1 to k do
       if (a[-b[j]]>0) then bo:=true;
   if (not bo) then begin write('YES'); break; end;
end;
if (bo) then write('NO');
```
*****

# 赛后补题

## C
>主要算法：bfs或DP
### Problem description
> 当怪物在x点时，轮到玩家a操作，他有个操作为前进y步，若前进y步之后刚好到达1号点，则怪物死亡，玩家a胜利。题目要求我们求出所以怪物初始位置和玩家ab各自先手的游戏结果。

### Data Limit：n <= 7000  Time Limit: 4s

### Solution
> 从最后一个状态倒推（0,0）（0,1）

### Code
```cpp
void solve(int idx, int pos)
{
    vis[idx][pos] = 1;
    for(int i=0, nxt;i<k[!idx];i++)
    {
        nxt = (pos + n - s[!idx][i]) % n;
        if(nxt == 0)    continue;
        if(vis[!idx][nxt])  continue;
        if(ans[idx][pos] && ++cnt[!idx][nxt] == k[!idx])
            solve(!idx, nxt);
        else if(ans[idx][pos] == false)
            ans[!idx][nxt] = true,
            solve(!idx, nxt);
    }
}
int main()
{
    scanf("%d",&n);
    for(int i=0;i<2;i++)
    {
        scanf("%d",&k[i]);
        for(int i=0;i<k[i];i++)
            scanf("%d",&s[i][i]);
    }
    solve(0, 0);
    solve(1, 0);
    for(int i=0;i<2;i++)
    {
        for(int i=1;i<n;i++)
            pt(i, i);
        printf("\n");
    }
}
```
*****


## D
### Problem description
> 

### Data Limit：n <= 1e5  Time Limit: 1s
### Solution
> 

### Code
```cpp
```
*****

## E
>主要算法：二分或主席树+二分
### Problem description
> 每个区间最多出现k个不同的数，输出当k=1,2,3..n时的最小区间数

### Data Limit：n <= 1e5  Time Limit: 2s

### Solution
> 二分颜色数k，如果ansl=ansr，那么ans[l]和ans[l+1]..ans[r]均相等

### Code
```cpp
int get(int x){
	int cnt=0,ans=0;
	memset(bo,-1,sizeof(bo));
	for (int i=1;i<=n;++i){
		if (bo[a[i]]==ans) continue;
		else {
			cnt++; bo[a[i]]=ans; 
			if (cnt==x+1) {
				cnt=1; ans++; bo[a[i]]=ans;
			}
		}
	}
	return ans+1;
}
void solve(int l, int r){
	if (l>r) return;
	int cl=get(l),cr=get(r);
	if (cl==cr){
		for (int i=l;i<=r;++i)
			ans[i]=cl;
		return;
	}
	ans[l]=cl; ans[r]=cr;
	int mid=(l+r)>>1;
	solve(l+1,mid);
	solve(mid+1,r-1);
}
int main(){
	scanf("%d",&n);
	for (int i=1;i<=n;++i)
		scanf("%d",&a[i]);
	solve(1,n);
	for (int i=1;i<=n;++i)
		printf("%d ",ans[i]);
}
```
