[比赛链接](https://vjudge.net/contest/171409)
[Codeforces](http://codeforces.com/contest/614)

## A
### Problem description
> 给定整数l，r，k，求出闭区间[l,r]内k的幂次方的个数。

### Data Limit:1≤l≤r≤1e18,2≤k≤1e9  Time Limit:2s

### Solution
> 简单题要注意数据范围，很明显这里设置了一个容易爆longlong的坑，在乘的过程中可通过移项来合理规避

### Code
```cpp
int main () {
    long long l, r, k;
    cin >> l >> r >> k;
    long long number = 1;
    bool flag = false;
    while (true) {
        if (number >= l && number <= r) {
            flag = true;
            cout << number << " " ;
        }
        if (number > r / k) {
            break;
        }
        number = number * k;
    }
    if (!flag)
    puts("-1");
    return 0;
}
```
*****


## B
### Problem description
> 输入一个数n，再输入n个整数a[i]，数列a[i]满足性质至少有(n-1)个美丽数。美丽数的定义是只含有数字0或1且数字1的个数不超过1个的数。求n个数的积。题目保证每个数不含前导0。

###  Data Limit:1≤n≤1e5,所有数的长度总和不超过1e5  Time Limit:0.5s
### Solution
> 简单的if else题，读清楚题目很重要，比如至少有n-1个 不超过一个1等关键字

### Code
```cpp
char s[100010];
int main () {
    int n;
    scanf("%d", &n);
    string ret = "";
    int number_zero = 0;
    bool flag = false;
    for (int i = 0; i < n; i++) {
        scanf("%s", s);
        if(strcmp (s, "0") == 0) {
            flag = true;
        }
        int cnt = 0;
        bool other = false;
        for (int j = 0; s[j]; j++) {
            if (s[j] == '1') {
                cnt++;
            }
            if (s[j] != '1' && s[j] != '0') {
                other = true;
            }
        }
        if (cnt > 1 || other)  { // 超过一个1 或者 存在其他数字
            ret = s;
        } else {
            number_zero += strlen(s) - 1;
        }
    }
    if (flag) {
        puts("0");
    } else {
        if(ret != "") { 
            cout << ret;
        } else { // 每一个都是美丽数
            cout << "1";
        }
        for(int i = 0; i < number_zero; i++) printf("0");
    }
    return 0;
}
```
*****



## C
### Problem description
> 给定整数n和旋转中心的坐标。再给出n个点的坐标，保证这些点按顺时针或按逆时针排列，且不存在三点共线。这些点则能围成一个凸n边形。将这个凸n边形绕旋转中心旋转一周，求旋转时覆盖到坐标轴上的面积。

### Data Limit:3<=n<=1e5  Time Limit:2s

### Solution
> 计算几何。此题需要计算旋转中心到凸n边形的最远距离Max和最近距离Min，然后根据圆面积公式得覆盖的面积公式为S=pi×(Max×Max-Min×Min)。最远距离显然在凸多边形的某个定点上，最近距离应该为点到线段的最近点（不一定是端点，有可能是垂足）。算点到线段的最近点可以先判断垂足在不在线段上，这个可以利用点积来算，因为点积的值为两边乘积乘以夹角的cos值，可以通过这个值的正负来判断是否构成了一个钝角三角形，如果是钝角三角形，答案就是跟某个端点的距离，如果不是，就用三角形面积除以底边长来算最近距离。

### Code
```cpp
#define pi acos(-1.0)
using namespace std;
struct point{
    double x,y;
}p[100005],t;
int n;
double dis(point a,point b)
{
    return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}
double dot(point a,point b)
{
    return a.x*b.x+a.y*b.y;
}
double len(point a)
{
    return sqrt(dot(a,a));
}
double point_to_segment(point a,point b,point c)
{
    point v1,v2,v3;
    v1.x=c.x-b.x;
    v1.y=c.y-b.y;
    v2.x=a.x-b.x;
    v2.y=a.y-b.y;
    v3.x=a.x-c.x;
    v3.y=a.y-c.y;
    if (dot(v1,v2)<0) return len(v2);
    else if (dot(v1,v3)>0) return len(v3);
    else return fabs((v1.x*v2.y-v2.x*v1.y)/len(v1));
}
int main()
{
    scanf("%d",&n);
    scanf("%lf%lf",&t.x,&t.y);
    for(int i=0;i<n;i++)
    scanf("%lf%lf",&p[i].x,&p[i].y);
    p[n].x=p[0].x;
    p[n].y=p[0].y;
    double Max=0;
    double Min=1000000000.0;
    for(int i=0;i<n;i++)
    {
        Max=max(Max,dis(t,p[i]));
        Min=min(Min,point_to_segment(t,p[i],p[i+1]));
    }
    printf("%0.10f\n",Max*Max*pi-Min*Min*pi);
    return 0;
}
```
*****


## D
### Problem description
> 给定整数n，A，cf，cm，m，再给出n个数a[i]，表示i的等级，等级可升级，但不能超过A，每升一级需要花费1，花费不能超过m，得到的最后数列中我们统计数列的价值，价值的计算公式是value=等级为A的数的个数×cf+最低的等级值×cm。

###  Data Limit:1≤n≤1e5,1≤A≤1e9,0≤cf,cm≤1000,0≤m≤1e15  Time Limit:2s
### Solution
> 将数组排序后，我们可以直接枚举有多少个A，也就是将那些较大的数都补到A，剩下的能量用来提升下限，随着枚举的A的个数的增加，我们会发现，下限会越来越小，因此可以维护一个下标，two-pointer移动一下，假设当前到某个位置，那么我们尝试着将所有小于等于当前数的前缀的数都变成这个数，然后如果还有剩，就每次给整个前缀都+1。具体细节需要想清楚。一次AC不容易。

### Code
```cpp
const int N = 100010;

long long make_perfect[N], sum[N];
int a[N], id[N], answer[N];

long long cost_change_to(int minimum_index) {
    return 1LL * minimum_index * a[id[minimum_index]] - sum[minimum_index];
}

bool checkmax(long long &ret, long long cmp) {
    if (cmp > ret) {
        ret = cmp;
        return true;
    }
    return false;
}

int main() {
    int n, A, coeffient_max, coeffient_min;
    long long total;
    cin >> n >> A >> coeffient_max >> coeffient_min >> total;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        id[i] = i;
    }
    sort (id, id + n, [](int i, int j) {return a[i] < a[j];});
    for (int i = 0; i < n; i++) {
        sum[i + 1] = sum[i] + a[id[i]];
    }
    long long cost = 0;
    for (int i = n - 1; i >= 0; i--) {// 预处理得到若干个A的最小代价
        cost += A - a[id[i]];
        make_perfect[n - i] = cost;
    }

    int minimum_index = n - 1, perfect_number = -1;
    long long ret = 0, minimum = -1;
    if (cost <= total) {
        ret = 1LL * n * coeffient_max + 1LL * A * coeffient_min;
        perfect_number = n;
        minimum = A;
    } else {
        for (int perfect = 0; perfect <= n; perfect++) { // 枚举A的个数
            long long remain_unit = total - make_perfect[perfect];
            if (remain_unit < 0) {
                break;
            }

            while (minimum_index >= 0 && cost_change_to(minimum_index) > remain_unit) {
                minimum_index --;
            }
            while (minimum_index >= n - perfect) {
                minimum_index--;
            }
    #ifndef ONLINE_JUDGE
        //printf("minimum_index=%d\n", minimum_index);
    #endif
            long long remain_unit_to_make_larger = remain_unit - cost_change_to(minimum_index);

            long long add = remain_unit_to_make_larger / (minimum_index + 1);//剩下的用来给每个数+1
            long long minimum_value = a[id[minimum_index]] + add;
            minimum_value = min(minimum_value, 1LL * A);
            if(checkmax(ret, 1LL * minimum_value * coeffient_min + 1LL * coeffient_max * perfect)) {
                perfect_number = perfect;
                minimum = minimum_value;
            }
        }
    }
    for (int i = n - perfect_number; i < n; i++) {
        answer[id[i]] = A;
    }
    for (int i = 0; i < n - perfect_number; i++) {
        answer[id[i]] = a[id[i]] < minimum ? minimum : a[id[i]];
    }
    cout << ret << endl;
    for (int i = 0; i < n; i++) {
        printf("%d ", answer[i]);
    }
    return 0;
}
```
*****

## E
### Problem description
> 给出一个整数n，再给出n个整数a[i]，分别表示颜色为i的珠子有a[i]个。求构造一串项链，使项链从某处剖开后对称，并使能剖开处的位置最多。输出时，先输出一个整数表示可剖开处的个数，然后输出项链。相应的数字用对应的字母表示，如第一种颜色对a，第二种颜色对b...。

### Data Limit:1≤n≤26  Time Limit:2s

### Solution
> 想象在一个环上有两个位置切开后都满足对称性，那么根据对称的传递，环被分割成一段段相等而且回文的序列，每种字符在每一份里面的数量是一样的，每种字符都被分成了相同的份数，这个是他们的公约数，所以最大公约数就是答案，第i种字符在每一份里面的数量是a[i]/gcd,如果有两个或以上奇数（无法构成回文），强行乘以2(这个时候gcd肯定是个偶数，份数变成了gcd/2)，然后每次就首尾各放一个字符来构造这一份字符串，最后输出gcd份或者gcd/2(看有没有乘2来定) 份同样的字符串就好了

### Code
```cpp
#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b) {
    while(a && b) {
        if (a < b)  {
            swap(a, b);
        }
        a -= b;
    }
    return b;
}

int s[100010];
int main () {
    int n, a[26];
    scanf("%d", &n);
    int odd = 0; 
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        if (a[i] & 1) {
            odd++;
        }
    }
    if (odd > 1) {
        puts("0");
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < a[i]; j++) {
                printf("%c", 'a' + i);
            }
        }
        puts("");
        return 0;
    }
    int _gcd = a[0];
    for (int i = 1; i < n; i++) {
        _gcd = gcd(_gcd, a[i]);
    }

    int cnt = 0;
    int id = -1;
    for (int i = 0; i < n; i++) {
        a[i] /= _gcd;
        if (a[i] & 1) {
            id = i;
            cnt++;
        }
    }
    int parts = _gcd;
    if (cnt > 1) {
        for (int i = 0; i < n; i++) {
            a[i] *= 2;
        }
        parts /= 2;
    }
    memset(s, 0, sizeof(s));
    int l = 0, r = accumulate(a, a + n, 0) - 1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < a[i] / 2; j++) {
            s[l++] = s[r--] = 'a' + i;
        }
    }
    if (cnt == 1) {
        s[l] = 'a' + id;
    }
    printf ("%d\n", _gcd);
    for (int i = 0; i < parts; i++) {
        for (int j = 0; s[j]; j++) {
            printf("%c", s[j]);
        }
    }
    return 0;
}

```
