var i,j,n,t,s,x,cnt,mx,p,q:longint;
    f:array[0..1000010,0..20]of longint;
    de:array[0..1000010]of longint;
procedure swap(var a,b:longint);
  var t:longint;
begin
  t:=a;
  a:=b;
  b:=t;
end;
function lca(x,y:longint):longint;
  var i:longint;
begin
  if de[x]<de[y] then swap(x,y);
  for i:=20 downto 0 do
  if de[f[x,i]]>=de[y] then x:=f[x,i];
  if x=y then exit(x);
  for i:=20 downto 0 do
  if f[x,i]<>f[y,i] then
  begin
    x:=f[x,i];
    y:=f[y,i];
  end;
  exit(f[x,0]);
end;
begin
  readln(n);
  mx:=2; cnt:=4; p:=2; q:=3;
  f[2,0]:=1; f[3,0]:=1; f[4,0]:=1;
  de[1]:=1; de[2]:=2; de[3]:=2; de[4]:=2;
  for j:=1 to n do
  begin
    readln(x);
    inc(cnt);
    f[cnt,0]:=x;
    de[cnt]:=de[x]+1;
    for i:=1 to 20 do
    f[cnt,i]:=f[f[cnt,i-1],i-1];
    inc(cnt);
    f[cnt,0]:=x;
    de[cnt]:=de[x]+1;
    for i:=1 to 20 do
    f[cnt,i]:=f[f[cnt,i-1],i-1];
    t:=lca(p,cnt);
    s:=de[p]+de[cnt]-de[t]*2;
    if s>mx then
    begin
      q:=cnt;
      mx:=s;
    end;
    t:=lca(q,cnt);
    s:=de[q]+de[cnt]-de[t]*2;
    if s>mx then
    begin
      p:=cnt;
      mx:=s;
    end;
    writeln(mx);
  end;
end.
