var i,j,k,n,x:longint;
    g:array[0..501,0..501]of int64;
    d,ans:array[0..501]of int64;
    mark:array[0..501]of boolean;
function min(x,y:int64):int64;
begin
  if x<y then exit(x) else exit(y);
end;
begin
  readln(n);
  for i:=1 to n do
  begin
    for j:=1 to n do
    read(g[i,j]);
    readln;
  end;
  for i:=1 to n do
  read(d[i]);
  for k:=n downto 1 do
  begin
    mark[d[k]]:=true;
    for i:=1 to n do
    for j:=1 to n do
    g[i,j]:=min(g[i,d[k]]+g[d[k],j],g[i,j]);
    for i:=1 to n do
    for j:=1 to n do
    if (mark[i]) and (mark[j]) then inc(ans[k],g[i,j]);
  end;
  for i:=1 to n do
  write(ans[i],' ');
  writeln;
end.
