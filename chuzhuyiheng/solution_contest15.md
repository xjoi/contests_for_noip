
[比赛链接](https://www.codeforces.com)

# 比赛中解决的问题
## A
### Problem description
> 有两串数b,b+a,b+2a....和d,d+c,d+2c.....
若两串数中会出现相同的数，则输出一个最小的相同的数，否则输出0

### Data Limit：a,b,c,d <= 100  Time Limit: 1s

### Solution
> 易得xa+b=yc+d=那个相同的数(x,y为自然数)
所以x=(yc+d-b)/a 
又因为x为自然数，所以yc+d-b为a的倍数，即（yc+d-b）mod a为0
因为a小于100，所以余数的情况只有100种。那么y从0开始枚举，直到x成为整数。如果100次内x还无法成为整数，则打出-1.
再仔细想想，x和y都不会超过100，那两个for搞定。
### Code
```pas
var
  a,b,c,d,i,l,t,ans,j:longint;
  function min(a,b:longint):longint;
  begin
    if a<b then exit(a) else exit(b);
end;
begin
  read(a,b);
  read(c,d);   ans:=maxlongint;
  for i:=0 to 100 do
    for j:=0 to 100 do
    if i*a+b=c*j+d then ans:=min(ans,i*a+b);
  if ans<maxlongint then writeln(ans) else writeln(-1);
end.
```
*****


## B
### Problem description
> 给出n,m和m组数若m组数中都有至少一对相反数，就打NO，否则打YES

### Data Limit：n，m <= 10000  Time Limit: 1s
### Solution
> 每组暴力搜一下就好了，有一组不合题意，打出YES，然后halt

### Code
```pas
var
  n,m,i,j,k,hh:longint;
  x:array[1..100000] of longint;
  a:array[1..10000000,1..3] of longint;
  bo:boolean;
procedure jia(x:longint);
var
  i,t:longint;
begin
  t:=abs(x); 
  for i:=1 to hh do if a[i,3]=t then
  begin
    if x>0 then inc(a[i,1]) else inc(a[i,2]);
    if (a[i,1]>0)and(a[i,2]>0) then begin bo:=true;end;
    exit;
  end;
  inc(hh);
  a[hh,3]:=t;
  if x>0 then inc(a[hh,1]) else inc(a[hh,2]);
end;
begin
  read(n,m);   bo:=true;
  for i:=1 to m do
  begin
    if not bo then begin write('YES');halt;end;
    bo:=false;  hh:=0;
    read(k);
    for j:=1 to k do read(x[j]);
    for j:=1 to n do begin a[j,1]:=0;a[j,2]:=0;a[j,3]:=0;end;
    for j:=1 to k do
    begin
      jia(x[j]);

    end;
  end;
  if not bo then writeln('YES') else writeln('NO');
end.


```
*****

# 赛后补题

## C
### Problem description
> 两个人，每人有两组数，每人可以让怪兽前进自己数字的格数，谁先把怪兽移到1号位，就胜利
输出怪兽在每个位置时，两人分别先手时谁能赢

### Data Limit：n <= 7000  Time Limit: 4s

### Solution
> 设状态dp[x,y]表示当前怪物在x点，轮到玩家y操作的游戏结果。所以dp[1,0]和dp[1,1]的结果都是失败，若在dp[x,y]的情况下，玩家的任意操作到达的状态是y’玩家false，则dp[x,y]为true（玩家选择该操作即可胜利），反之，若玩家的所有选择到达的下一个状态都是另一个玩家y’胜利,则dp[x,y]为false.
不过因为会有loop的结果，所以递推不大好实现，我选择了使用逆向bfs的方法，有点像拓扑排序（先初始化所有点的度数为可操作数），先让点[0][0]和[0][1]入队，对于任意当前队列头的点，如果这个点的状态是false，则逆推出能从哪些点到这一点，那些点的状态都是true并且入队；如果这个点的状态是true，则让所有逆推出来的上一步的点的度数减一，如果该点的度数为0，则该点的状态是false并且入队。最后那些始终没有入队过的就是loop的点了。
### Code
```pas
var
  n,i,j,h,t:longint;
  k0,k1:longint;
  a,b:array[1..100000] of longint;
  dp:array[1..100000,0..1] of boolean;
  q:array[1..1000000,1..2] of longint;
  d:array[1..100000,0..1] of longint;
  q3:array[1..1000000] of boolean;
  bo:array[1..1000000,0..1] of boolean;
function s(a,b:longint):Longint;
begin
  if a>b then exit(a-b);
  if a=b then exit(n);
  if a<b then exit(n+a-b);
end;
procedure push(x,y:longint;z:boolean);
begin
  inc(h);
  q[h,1]:=x;q[h,2]:=y;q3[h]:=z;bo[x,y]:=true;
  dp[x,y]:=z;
end;
begin
  read(n);
  read(k0);for i:=1 to k0 do read(a[i]);
  read(k1);for i:=1 to k1 do read(b[i]);
  for i:=1 to n do begin d[i,0]:=k0;d[i,1]:=k1;end;
  push(1,0,false);push(1,1,false);
  repeat
    inc(t);
    if q[t,2]=0 then
      if not q3[t] then
      begin
        for i:=1 to k1 do if(not bo[s(q[t,1],b[i]),1])  then push(s(q[t,1],b[i]),1,true);
      end
      else
      begin
        for i:=1 to k1 do begin
        dec(d[s(q[t,1],b[i]),1]);
        if (d[s(q[t,1],b[i]),1]=0)and(not bo[s(q[t,1],b[i]),1])
        then push(s(q[t,1],b[i]),1,false);end;
      end;
    if q[t,2]=1 then
      if not q3[t] then
      begin
        for i:=1 to k0 do if(not bo[s(q[t,1],a[i]),0]) then push(s(q[t,1],a[i]),0,true);
      end
      else
      begin
        for i:=1 to k0 do begin
        dec(d[s(q[t,1],a[i]),0]);
        if (d[s(q[t,1],a[i]),0]=0)and(not bo[s(q[t,1],a[i]),0])
        then push(s(q[t,1],a[i]),0,false);end;
      end;
  until h<=t;
  for i:=2 to n do
  begin
  if (not bo[i,0]) then write('Loop ') else
  if dp[i,0] then write('Win ') else write('Lose ');
  end;
  writeln;
  for i:=2 to n do
  begin
  if not bo[i,1] then write('Loop ') else
  if dp[i,1] then write('Win ') else write('Lose ');
  end;
end.

```
*****


## D
### Problem description
> 

### Data Limit：n <= 1e5  Time Limit: 1s
### Solution
> 

### Code
```cpp
```
*****

## E
### Problem description
> 

### Data Limit：n <= 1e5  Time Limit: 1s

### Solution
> 

### Code
```cpp
```
