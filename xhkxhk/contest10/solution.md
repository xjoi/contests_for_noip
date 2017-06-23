# A

```pas
var
a,b:array[1..100000] of longint;
t,i,j,k,m,n,o:longint;
begin
readln(m,n);
o:=1;
for i:=1 to n do
begin
read(k);
for j:=1 to k do
begin
a[j]:=0;
read(a[j]);
end;
while a[o]=o do inc(o);
readln;
end;
dec(o);
writeln(m-n+m+1-o*2);
end.

```
