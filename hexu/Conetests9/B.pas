var
  n,m,i,j,k,ii,ope:longint;
  map,DIS:array[0..505,0..505]of int64;
  p,ans,path:array[0..505]of int64;
  vis:array[0..505]of boolean;
function min(a,b:longint):longint;
begin
  if a>b then exit(b) else exit(a);
end;
begin
  readln(n);
  for i:=1 to n do
  begin
    for j:=1 to n do read(dis[i,j]);
    //dis[i,i]:=maxlongint div 3;
    readln;
  end;
  fillchar(vis,sizeof(vis),false);
  for i:=1 to n do read(p[i]);
  for ii:=n downto 1 do
  begin
    ope:=p[ii]; vis[ope]:=true;
    for i:=1 to n do
      for j:=1 to n do
      dis[i,j]:=min(dis[i,j],dis[i,ope]+dis[ope,j]);
    ans[ii]:=0;
    for i:=1 to n do
      if vis[i] then
      for j:=1 to n do
        if vis[j] then ans[ii]:=ans[ii]+dis[i,j];
  end;
  for i:=1 to n do write(ans[i],' ');

end.
