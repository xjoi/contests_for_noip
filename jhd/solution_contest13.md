# 比赛记录

[比赛链接](https://cn.vjudge.net/contest/168406)
## A
### Problem description
> 读入一个表示杠杆的字符串，`^`表示支点，`=`表示杆子，`1-9`表示重物，输出杠杆向哪一侧倾斜
### Solution
读入后记录每个重物的位置，并计算力臂（左侧用负数，右侧正数），根据平衡条件计算。
```cpp
#include <cstdio>
#include <cstring>
#include <iostream>
#define ll long long
using namespace std;

struct point{
	ll pos;
	ll weight;
	point (ll a=0,ll b=0){
		this->pos=a;
		this->weight=b;
	}
}A[1000001];
int cnt=0;
ll ctr;
int main(){
	string s;
	cin>>s;
	for (int i=0;i<s.length();i++){
		if (s[i]=='^'){
			ctr=i;
		}
		if (s[i]>='0'&&s[i]<='9'){
			A[++cnt]=point(i,s[i]-'0');
		}
	}
	ll Ans=0;
	for (int i=1;i<=cnt;i++){
		Ans+=(A[i].pos-ctr)*A[i].weight;
	}
	if (Ans<0){
		printf("left");
	}else if (Ans==0){
		printf("balance");
	}else if (Ans>0){
		printf("right");
	}
	
}
```

## B
### Problem description
> 在n个人中，某些人欠另一些人钱，但有些可以合并，输出最后每个人的欠款的总和。
### Solution
记欠别人钱为负，得到别人的钱为正，则每个人需要给别人的钱（或收到的钱）总和为所有欠款和收款的总和。

则总欠款（等于总收款）=所有人（如果欠款）的欠款总和。

```cpp
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;

int map[105][105];
int main(){
	int n,m;
	scanf("%d%d",&n,&m);
	for (int i=1;i<=m;i++){
		int a,b,c;
		scanf("%d%d%d",&a,&b,&c);
		map[a][b]=c;
		map[b][a]=-c;
	}
	int Ans=0; 
	for (int i=1;i<=n;i++){
		int Tmp=0;
		for (int j=1;j<=n;j++){
			Tmp+=map[i][j];
		}
		Ans+=abs(Tmp);
	}
	printf("%d",Ans/2);
}
```
## C
### Problem description
> 有一个n位数，其中包含1,6,8,9.将它重新排列，使其成为7的倍数。
### Solution
 多解题。我的构造方法是：因为六个连续数字一定能被7整除（即7|111111n），那么就把它们放在最后，然后枚举前面的数字，使它们也能被7整除。
 ``` cpp
 #include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
using namespace std;

int A[10];
int S[1000001];
string s;

int main(){
	cin>>s;
	int Len=s.length(),len=Len;
	for (int i=0;i<s.length();i++){
		S[i]=s[i]-'0';
		A[S[i]]++;
	}
	for (int i=0;i<=9;i++){
		while (A[i]>=6){
			for (int iii=1;iii<=6;iii++){
				S[len-1]=i;len--;
			}
			A[i]-=6;
		}
	}
	for (int i=0,j=0;i<len;i++){
		while (A[j]==0) j++;
		S[i]=j;
		A[j]--; 
	}
	int k=0;
	while (S[k]==0) k++;
	swap(S[0],S[k]);
	do{
		if (S[0]!=0){
			int Ans=0;
			for (int i=len-1;i>=0;i-=6) Ans+=S[i],Ans%=7;
			for (int i=len-2;i>=0;i-=6) Ans+=S[i]*10,Ans%=7;
			for (int i=len-3;i>=0;i-=6) Ans+=S[i]*100,Ans%=7;
			for (int i=len-4;i>=0;i-=6) Ans-=S[i]*1,Ans%=7;
			for (int i=len-5;i>=0;i-=6) Ans-=S[i]*10,Ans%=7;
			for (int i=len-6;i>=0;i-=6) Ans-=S[i]*100,Ans%=7;
			if (Ans==0){
				for (int i=0;i<Len;i++){
					printf("%d",S[i]);
				}
				return 0;
			}
		}
	}while (next_permutation(S,S+len));
	printf("0");
}
```
另外，还有一种算法（应该是标算）是可以用1,6,8,9构造7个四位数b，使其%7有0~6的不同的余数，设前面的（l-4）位%7余数为x，1000x%7+b能被7整除，那么就可以求出b。

## D
### Problem description
给出一个0,1矩阵，其中行的顺序可以随意更换，求出一个最大的全1子矩阵。
### Solution
计算[i,j]之后的1的个数，在每一列中枚举宽度，计算出>=这个宽度的行数，相乘即得面积，计算出最大面积。
``` cpp
#include <iostream>
#include <cstring>
#include <algorithm>
#include <cstdio>
#include <vector>
using namespace std;

bool matrix[5005][5005];
int next[5005][5005];
int box[5005][5005];
int maxi[5005];
char s[5005];
int main(){
	int m,n;
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++){
		scanf("%s",s);
		for (int j=m;j>=1;j--){
			matrix[i][j]=s[j-1]-'0';
			if (matrix[i][j]) next[i][j]=next[i][j+1]+1;
		}
	}
	for (int j=1;j<=m;j++){
		for (int i=1;i<=n;i++){
			box[j][next[i][j]]++;
			maxi[j]=max(next[i][j],maxi[j]);
		}
	}
	int Ans=0;
	for (int i=1;i<=m;i++){
		int cnt=0;
		for (int j=maxi[i];j>=1;j--){
			cnt+=box[i][j];
			Ans=max(Ans,cnt*j);
		}
	}
	printf("%d",Ans);
}
```
***** 
# 赛后补题

## E
### Problem description
> 给出一个地图，其中有价值不同的宝藏，炸弹和障碍物。在地图上画出一条闭合路径（不得经过宝藏、炸弹或障碍物），在不包围炸弹的前提下，最大化（宝藏价值总和-路径长度）
### Solution
主要算法：根据坐标以及已经“包围”的宝藏进行BFS，之后枚举各种包围情况下的`宝藏价值总和-路径长度`，求出最大值。

细节

+ 判断宝藏是否“包围”（其实题干中就有）： 假设一条射线，则路径每穿过一次这一条射线其是否被包围的状态就会改变一次。只要判断路径是否穿过射线即可。
+ 对炸弹的处理：1.在最后枚举所有包围情况时去掉包围炸弹的情况。2.将炸弹的权设为负无穷大。
+ 记录数组要开大。

``` cpp
#include <cstdio>
#include <cstring>
#include <queue>
#include <algorithm>
using namespace std;

const int inf=10000000;
int map[25][25]; //0=clear(including start point),-1=bomb,-2=obstacle,1-8=treasure;
int price[10];
int m,n,start_r,start_l;
int pos_r[10],pos_l[10];
char s[25];
struct node{
	int i,j,status,steps;
	node (int x,int y,int z,int a){
		this->i=x;this->j=y;this->status=z;this->steps=a;
	}
};

int visit[25][25][600];
queue <node> Q;
int main(){
	scanf("%d%d",&n,&m);
	int cnt_trea=0;
	for (int i=1;i<=n;i++){
		scanf("%s",s);
		for (int j=1;j<=m;j++){
			if (s[j-1]=='.') map[i][j]=0;
			else if (s[j-1]=='B') map[i][j]=-1;
			else if (s[j-1]=='#') map[i][j]=-2;
			else if (s[j-1]=='S') map[i][j]=0,start_r=i,start_l=j;
			else cnt_trea=max(cnt_trea,map[i][j]=s[j-1]-'0'),pos_r[map[i][j]]=i,pos_l[map[i][j]]=j;
		}
	}
	for (int i=1;i<=cnt_trea;i++){
		scanf("%d",&price[i]);
	}
	for (int i=1;i<=n;i++){
		for (int j=1;j<=m;j++){
			if (map[i][j]==-1){
				pos_r[++cnt_trea]=i;
				pos_l[cnt_trea]=j;
				price[cnt_trea]=-inf;
			}
		}
	}
	memset(visit,-1,sizeof visit);
	Q.push(node(start_r,start_l,0,0));
	while(!Q.empty()){
		node a=Q.front();Q.pop();
		if (visit[a.i][a.j][a.status]!=-1) continue;
		visit[a.i][a.j][a.status]=a.steps;
		for (int offi=-1;offi<=1;offi++){
			for (int offj=-1;offj<=1;offj++){
				if (offi&&offj||!(offi||offj)) continue;
				int Pi=a.i,Pj=a.j,Sta=a.status;
				Pi+=offi;Pj+=offj;
				if (!map[Pi][Pj]&&Pi>0&&Pi<=n&&Pj>0&&Pj<=m){
					for (int icnt=1;icnt<=cnt_trea;icnt++){
						if ((pos_r[icnt]==a.i&&offi==1||(pos_r[icnt]==Pi&&offi==-1))&&pos_l[icnt]<Pj){
 							Sta^=(1<<icnt);
						}
					}
					Q.push(node(Pi,Pj,Sta,a.steps+1));
				}
			}
		}	
	}
	int Ans=0;
	for (int i=1;i<=(1<<(cnt_trea+1))-1;i++){
		if (visit[start_r][start_l][i]!=-1){
			int Tmp=0;
			for (int j=1,k=(i>>1);j<=cnt_trea;j++,k>>=1){
				Tmp+=(k&1)*price[j];
			}
			Ans=max(Ans,Tmp-visit[start_r][start_l][i]);
		}
	}
	printf("%d",Ans);
}
```

## F (Not AC Yet)
### Problem Description
给出一个有根树，每个顶点有一种颜色。有若干请求，对于每个请求，输出对应子树中某种颜色的顶点数大于k的颜色数。
### Solution
先用DFS序转区间，然后对请求分块，按照块的顺序统计每个请求。（大意）
