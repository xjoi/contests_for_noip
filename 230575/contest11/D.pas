const inf=1000000009;
var i,j,k,n,m,mmin,xx,yy:longint;
    x,y,dis,vis:array[0..10000]of longint;
    b:boolean;
function min(x,y:longint):longint;
begin
  if x<y then exit(x) else exit(y);
end;
begin
  readln(n,m,k);
  b:=false;
  for i:=1 to k do
  begin
    readln(x[i],y[i]);
    dis[i]:=inf;
    if (x[i]=n) and (y[i]=m) then b:=true;
  end;
  if b then
  begin
    inc(k);
    x[k]:=n;
    y[k]:=m;
    dis[k]:=inf;
  end
  else
  begin
    inc(k);
    x[k]:=n+1;
    y[k]:=m+1;
    dis[k]:=inf;
  end;
  x[0]:=1;
  y[0]:=1;
  dis[0]:=0;
  fillchar(vis,sizeof(vis),0);
  for i:=0 to k do
  begin
    mmin:=k;
    for j:=0 to k-1 do
    if (vis[j]=0) and (dis[j]<dis[mmin]) then mmin:=j;
    vis[mmin]:=1;
    for j:=0 to k do
    if vis[j]=0 then
    begin
      xx:=abs(x[j]-x[mmin]);
      yy:=abs(y[j]-y[mmin]);
      if xx+yy<=1 then dis[j]:=dis[mmin]
      else if (xx<=2) or (yy<=2) then dis[j]:=min(dis[j],dis[mmin]+1);
    end;
  end;
  if dis[k]=inf then writeln('-1') else writeln(dis[k]);
end.
