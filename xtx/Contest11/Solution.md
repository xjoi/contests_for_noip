# B

对于一个整点（x,y），其内的banana一共有几个，这是可以O(1)算出来的：(1+x)*(1+y)*(x+y)/2————等差数列。

然后再观察条直线：y=-x/m+b————x=mb-my

所以我们枚举y，就可以了。

# C

首先想到的贪心肯定是————先按正常的操作，然后，当发现栈顶不是所想要的时候，就将栈内元素重排。

嗯，然后就可以想到，这会超时。怎么办办呢？我们不用真的重排，只要假装有一段有序区间就好了。

具体做法：当需要重排的时候,直接top=0。

```cpp

#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<cmath>
#include<set>
using namespace std;
const int MAXN=300000;
int n;
int stack[MAXN+10],top;
int now=1,cnt;
int main()
{
	scanf("%d",&n);
	char s[10];int a;
	for(int i=n<<1;i;--i)
	{
		scanf("%s",s);
		if(s[0]=='a')
		{
			scanf("%d",&a);
			stack[++top]=a;
		}
		else
		{
			if(top)
			{
				if(stack[top]==now)--top;
				else
				{
					top=0;
					++cnt;
				}
			}
			++now;
		}
	}
	printf("%d",cnt);
	return 0;
}

```

# D

首先可以k^2处理出所有点之间的边权，然后SPFA。

重点在于，这样会MLE。

所以，每行每列都要建立虚拟点，然后建边，然后SPFA。

# E

 由于c很小，所以可以用矩阵快速幂状态转移。
 
 11000
 11100
 01110
 00111
 00011
 
 用来转移的矩阵看起来就像是这样。
 
 注意矩阵乘法的时候可能会爆int，所以要int转ll————当然也可以#define int long long。。。
