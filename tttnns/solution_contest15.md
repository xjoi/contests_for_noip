[Content Link](https://vjudge.net/contest/168929)

# A

## Problem Desc

对于

F k = b + ka

G t = d + tc

求满足F k = G t时, F k的最小值

1 <= a, b, c, d <= 100

## Solution

### Accepted Solution

暴枚, 根据某证明不会TLE

```
For Int i In (b If a > c Else d)..(a If a > c Else c)..MagicNumber:
    If (i - b) % a = 0 And (i - d) % c = 0:
        Write i
        Stop
```

### Better Solution

exgcd

当F k = G t时

b + ka = d + tc

ka - tc = d - b

这是一个妙妙的方程, 可以用exgcd求解

```
Int g = Gcd a -c
If (d - b) % g <> 0:
    Write -1
    Stop
Int x y = Exgcd a/g -c/g
x *= (d - b) / g
y *= (d - b) / g
x y = MakeBothMinPositive x y
Write x * a + b
```

# B

## Problem Desc

给你m个组, 求是否每个组都包含至少一对相反数

1 <= m <= 10^4

## Solution

暴力扫一遍

```
Vector<Vector<Int> > groups = Read
For group In groups:
    For item In group:
        If -item In group:
            group Is Valid
If All Is Valid:
    Write "No"
Else:
    Write "Yes"
```

# C

## Problem Desc

对于环1..n, 1为终点, 将任意非1作为起点, 两人中任意一人先手

给定人1的可移动步数集合s1, 人2的可移动步数集合s2 (顺时针移动)

求对于上述每种情况的胜负

2 <= n <= 7000

## Solution

BoyFriend Search

```
Queue<Status> q
For Status:
    At Location 1
    At Turn 0 Or 1
    Set To Vis
    Set To Lose
    Push To q
For All Status:
    Set cOutEdge To Size s{1, 2} <- turn
While Not Empty q:
    Status sts = Pop q
    For move In s{1, 2} <- Not turn Of sts:
        Status newsts = MakeNewStatus From sts By Forward move
        If newsts Is Not Vis:
            If sts Is Lose:
                Set newsts To Win
                Set newsts To Vis
                Push newsts To q
            Else:
                Reduce cOutEdge Of newsts
                If it = 0:
                    Set newsts To Lose
                    Set newsts To Vis
                    Push newsts To q
Write All Status
```

# D

## Problem Desc

有三种路径

1. u -> v
2. u -> [l, r]
3. [l, r] -> v

求从s开始的单源最短路

结点数n <= 10^5

## Solution

结点太多, 直接连边要GG, 那么可以建线段树, 用树上的结点代替区间, 然后直接跑最短路

需要建两棵, 一棵向上连边, 另一棵向下, 边权值为0

```
SegmentTree t1 t2
t1 -> UpToDown
t2 -> DownToUp
For Each Edge:
    u -> v:
        AddEdge u v w
    u -> [l, r]:
        AddEdge u GetNodesByRange l r From t1 w
    [l, r] -> v:
        AddEdge GetNodesByRange l r From t2 v w
Write ShortestPath From s
```

# E

## Problem Desc

对于长度为n的序列a划分, 每段不同元素不能超过1..n, 求最小划分段数

n <= 10^5

## Solution

大暴力对于1..n计算, 这样肯定GG

我们发现, 对于答案序列, 是单调的

所以可以二分, 对于一个区间, 若首尾值相同, 则区间值均相同

玄学AC

```
Def get_ans Int k:
    Int ans = 0
    Dup a Local
    For Int x In a:
        If Size Unique items Before = k:
            Clear Before
            Inc ans
    If a Is Not Empty:
        Inc ans
    Return ans
Write BinaryEval get_ans 1..=n
```
