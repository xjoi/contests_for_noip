type node=record
       l,r,v:int64;
     end;
var i:longint;
    n,m,k,s,t:int64;
    a:array[0..100010]of int64;
    tree:array[0..100010]of int64;
    b:array[0..100010]of node;
    sum:array[0..100010]of int64;
function lowbit(x:int64):int64;
begin
  exit(x and (-x));
end;
procedure add(x,y:int64);
begin
  while x<=n do
  begin
    inc(tree[x],y);
    inc(x,lowbit(x));
  end;
end;
procedure addd(x,y:int64);
begin
  while x<=m do
  begin
    inc(sum[x],y);
    inc(x,lowbit(x));
  end;
end;
function query(x:int64):int64;
  var y:int64;
begin
  y:=0;
  while x>0 do
  begin
    inc(y,tree[x]);
    dec(x,lowbit(x));
  end;
  exit(y);
end;
function queryd(x:int64):int64;
  var y:int64;
begin
  y:=0;
  while x>0 do
  begin
    inc(y,sum[x]);
    dec(x,lowbit(x));
  end;
  exit(y);
end;
begin
  readln(n,m,k);
  for i:=1 to n do
  read(a[i]);
  for i:=1 to n do
  add(i,a[i]-a[i-1]);
  for i:=1 to m do
  readln(b[i].l,b[i].r,b[i].v);
  for i:=1 to k do
  begin
    readln(s,t);
    addd(s,1);
    addd(t+1,-1);
  end;
  for i:=1 to m do
  begin
    add(b[i].l,queryd(i)*b[i].v);
    add(b[i].r+1,-queryd(i)*b[i].v);
  end;
  for i:=1 to n do
  write(query(i),' ');
  writeln;
end.
