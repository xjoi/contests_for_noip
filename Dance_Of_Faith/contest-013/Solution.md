# 比赛记录

[codeforces #221](https://www.codeforces.com)

[vjudge](https://cn.vjudge.net/contest/168406)

## A -Lever
### Problem description
> 输出我要虐题

### Solution


```cpp
#include<iostream>
#include<cstdio>
#include<cstring>
#define int long long
using namespace std;
char ss[5000000];
main(){
	scanf("%s",ss);
	int dic=0,l=0,r=0,len=strlen(ss);
	for (int i=0;i<len;++i) if (ss[i]=='^'){dic=i;break;}
	for (int i=dic-1;i>=0;--i) if (ss[i]>='0'&&ss[i]<='9') l+=(dic-i)*(ss[i]-'0');
	for (int i=dic+1;i<len;++i) if (ss[i]>='0'&&ss[i]<='9') r+=(i-dic)*(ss[i]-'0');
	if (l==r) puts("balance");
	if (l<r) puts("right");
	if (l>r) puts("left");
	return 0;
}
```

## B -I.O.U.
### Problem description

### Solution

```cpp
#include<iostream>
#include<cmath>
using namespace std;
int d1[100000],d2[100000];
int main(){
	int n,m,ans=0,zz,xx,yy;
	cin >>n>>m;
	for (int i=1;i<=m;++i){
		cin >>xx>>yy>>zz;
		d1[yy]+=zz;d2[xx]+=zz;
	}
	for (int i=1;i<=n;++i) ans+=d2[i]-max(d1[i],d2[i]);
	cout <<abs(ans)<<endl;
	return 0;
}
```

## C -Divisible by Seven
### Problem description

### Solution

```cpp
#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
char ss[2000000];
int b[10]={9681,1896,9861,1698,6891,6981,6819};
int cn[50];
int main(){
	bool f1=0,f2=0,f3=0,f4=0;
	scanf("%s",ss+1);
	int len=strlen(ss+1),d=0;
	for (int i=1;i<=len;++i)
		if (ss[i]=='1'&&!f1) f1=1;else
		if (ss[i]=='6'&&!f2) f2=1;else
		if (ss[i]=='8'&&!f3) f3=1;else
		if (ss[i]=='9'&&!f4) f4=1;else
				++cn[ss[i]-'0'];
	for (int i=1;i<=9;++i)
		for (int j=1;j<=cn[i];++j)
			cout <<i,d=(d*10+i)%7;
	d=d*10000%7;
	cout <<b[d];
	for (int i=1;i<=cn[0];++i) cout <<0;
	return 0;
}
```

## D -Maximum Submatrix 2
### Problem description

### Solution

```cpp
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
char a[5010][5010];
int n,m,ans=0,lef[5010][5010];
bool cmp(int a,int b){return a>b;}
int main(){
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;++i) scanf("%s",a[i]+1);
	for (int i=1;i<=n;++i)
		for (int j=1;j<=m;++j)
			if (a[i][j]=='1') lef[j][i]=lef[j-1][i]+1;
	for (int j=1;j<=m;++j){
		sort(lef[j]+1,lef[j]+1+n,cmp);
		for (int i=1;i<=n&&lef[j][i]!=0;++i)
			ans=max(ans,lef[j][i]*i);
	}
	cout <<ans<<endl;
	return 0;
}
```

------------------------

# 赛后补题

## B
### Problem description
> 输出我要补题
### Solution
仔细分析一下，这个题可以用一个printf语句解决
```cpp
#include <bits/stdc++.h>
using namespace std;
int main () {
    printf("I want buti\n");
}
```
