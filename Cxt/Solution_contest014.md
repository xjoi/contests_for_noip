# Contest14 solution


[比赛链接](https://cn.vjudge.net/contest/168561)

## A
### Problem description
> 给出一串递增的数和c，只有当相邻两数相差<=c时才能归为一块，问最后一个数所在块有几个数。

### Solution
> 暴力从前往后扫，一旦相差超过c就把tot清为1，否则++tot。最终输出tot即可。

### Code

```cpp
#include<iostream>
#include<cstdio>
using namespace std;
int n,m,c,tot,x,lx=-1e9;
int main(){
    scanf("%d%d",&n,&c);
    for (int i=1;i<=n;++i){
		scanf("%d",&x);
		if (x-lx<=c) ++tot;else tot=1;
		lx=x;
	}
	printf("%d",tot);
}
```

***** 

## B
### Problem description
> 给出一个仅包含大写字母和通配符‘？’的字符串，询问是否有某子串包含了26个大写字母，如果是，同时输出不带通配符的最终串。

### Solution
> 用两个指针维护一个闭区间[l,r]表示当左指针指向l时，右指针最多可以指向r，使得该区间没有重复字母。处理中不用维护通配符的个数，只要当区间大小在某一时刻等于26即可输出答案。

> 然而需要注意的是，首先子串要求连续，然后多余的通配符需要都输出A。然后就可以AC了。

### Code
```cpp
#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int n,m,ti[27],tp;
char s[60100];
int main(){
    scanf("%s",s);
	int n=strlen(s),l=0,r=-1;
	while (r<n){
		while (++r,r<n&&r-l<26&&(s[r]=='?'||!ti[s[r]-'A'])) ++ti[s[r]-'A'];
		if (r-l==26){
			for (int i=0;i<l;++i) putchar(s[i]=='?'?'A':s[i]);
			for (int i=l;i<min(l+26,r);++i)
				if (s[i]=='?'){
					int pos=0;
					while (ti[pos]&&pos<'Z') ++pos;
					ti[pos]=1;putchar(pos+'A');
				}else putchar(s[i]);
				for (int i=min(l+26,r);s[i];++i) putchar(s[i]=='?'?'A':s[i]);
			return 0;
		}
		if (r==n) break;
		++ti[s[r]-'A'];
		while (ti[s[r]-'A']>1) s[l]!='?'?--ti[s[l]-'A']:0,++l;
	}
	puts("-1");
}

```
*****
## C
### Problem description
> 最开始，你在level 1，屏幕上有一个数2。你有两种操作：把屏幕上的数加上你的level。把屏幕上的数开根，同时你level++。

> 但你需要保持这样的性质：屏幕上的数是你的level的倍数，操作二时该数必须为完全平方数。

> 问升到n+1级过程中每次升级前执行操作1的次数。

### Solution
> 吐槽一下代码居然比B题还短。

> 容易发现执行操作1对性质1不会造成影响，所以我们仅考虑操作2。

> 设当前level=k，则设开根的时候屏幕上为x*k，则开根后屏幕上为sqrt（x*k），由于性质1、2，可知x*k为完全平方数且（k+1）|sqrt（x*k）。当x=（k+1）*（k+1）*k时满足这两个条件，故由此直接计算出解。

### Code
```cpp
#include<iostream>
#include<cstdio>
using namespace std;
#define int long long
int n,m;
main(){
    scanf("%lld",&n);
	for (int x=2,le=1;le<=n;++le){
		printf("%lld\n",(le+1)*(le+1)*le-x/le);
		x=(le+1)*le;
	}
	return 0;
}
```
*****
### 以下考后补题
