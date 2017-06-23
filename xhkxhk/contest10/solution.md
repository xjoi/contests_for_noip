### A
这是一道贪心，顺序什么的并不重要。因此本着贪到贪无可贪的原则，我们只需输出所有的0和1的个数再减一减就可以A掉了
```pas
var
s:array[1..200005] of char;
i,j,n,k,m1,m2:longint;
begin
readln(n);
for i:=1 to n do
begin
read(s[i]);
if s[i]='1' then inc(m1);
if s[i]='0' then inc(m2);
end;
writeln(abs(m1-m2));
end.
```
### B
此题有o(n)的标程(http://paste.ubuntu.com/11788578/)
不过作为一只
#蒟蒻，本渣只打出了n^2程序
思路大致如下
