const inf=1000000007;
var n,m:longint;
    res,s:int64;
    f,g,h:array[0..2010,0..2010]of int64;
    i,j,u,v:longint;
begin
  read(n,m);
  for i:=1 to n do
  for j:=2 to m do
  begin
    f[i][j]:=(h[i-1][j]*j-g[i-1][j]+1) mod inf;
    if f[i][j]<0 then f[i][j]:=f[i][j]+inf;
    h[i][j]:=(h[i][j-1]+f[i][j]) mod inf;
    g[i][j]:=(g[i][j-1]+f[i][j]*(j-1)) mod inf;
  end;
  for i:=1 to n do
  for j:=2 to m do
  begin
    s:=(f[i][j]-f[i-1][j])*f[n-i+1][j];
    s:=s mod inf;
    if s<0 then s:=s+inf;
    s:=s*(m-j+1) mod inf;
    res:=(res+s) mod inf;
  end;
  writeln(res);
end.
