type rec=array[0..20,0..20]of int64;
const inf=1000000007;
var x,y,h:array[0..110]of int64;
    a,b:rec;
    i,j,n,len:longint;
    k,t:int64;
function quick(a,b:rec):rec;
  var i,j,k:longint;
      c:rec;
begin
  fillchar(c,sizeof(c),0);
  for i:=1 to len do
  for j:=1 to len do
  for k:=1 to len do
  c[i,j]:=(c[i,j]+a[i,k]*b[k,j]) mod 1000000007;
  exit(c);
end;
begin
  readln(n,k);
  for i:=1 to n do
  begin
    readln(x[i],y[i],h[i]);
    inc(h[i]);
  end;
  a[1,1]:=1;
  for j:=1 to n do
  begin
    fillchar(b,sizeof(b),0);
    b[1,1]:=1;
    b[1,2]:=1;
    for i:=2 to h[j]-1 do
    begin
      b[i,i-1]:=1;
      b[i,i]:=1;
      b[i,i+1]:=1;
    end;
    len:=h[j];
    b[len,len-1]:=1;
    b[len,len]:=1;
    if (k>=x[j]) and (k<=y[j]) then t:=k-x[j] else t:=y[j]-x[j];
    while t>0 do
    begin
      if t and 1=1 then a:=quick(a,b);
      b:=quick(b,b);
      t:=t>>1;
    end;
  end;
  writeln(a[1,1]);
end.
