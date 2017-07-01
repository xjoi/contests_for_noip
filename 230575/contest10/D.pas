type rec=record
       num,id,left,right:int64;
     end;
var i,j:longint;
    n,m,x:int64;
    l,r:array[0..200010]of int64;
    a,b:array[0..200010]of rec;
    ans,fa:array[0..200010]of int64;
    f:array[0..200010]of boolean;
procedure qsort1(l,r:longint);
  var i,j:longint;
      mid1,mid2,m:int64;
      p:rec;
begin
  i:=l;
  j:=r;
  m:=random(r-l+1)+l;
  mid1:=a[m].left;
  mid2:=a[m].right;
  repeat
    while(a[i].left<mid1)or((a[i].left=mid1)and(a[i].right<mid2))do inc(i);
    while(a[j].left>mid1)or((a[j].left=mid1)and(a[j].right>mid2))do dec(j);
    if i<=j then
    begin
      p:=a[i]; a[i]:=a[j]; a[j]:=p;
      inc(i); dec(j);
    end;
  until i>j;
  if i<r then qsort1(i,r);
  if l<j then qsort1(l,j);
end;
procedure qsort2(l,r:longint);
  var i,j:longint;
      mid:int64;
      p:rec;
begin
  i:=l;
  j:=r;
  mid:=b[random(r-l+1)+l].num;
  repeat
    while b[i].num<mid do inc(i);
    while b[j].num>mid do dec(j);
    if i<=j then
    begin
      p:=b[i]; b[i]:=b[j]; b[j]:=p;
      inc(i); dec(j);
    end;
  until i>j;
  if i<r then qsort2(i,r);
  if l<j then qsort2(l,j);
end;
function get(x:int64):int64;
begin
  if fa[x]<>x then fa[x]:=get(fa[x]);
  get:=fa[x];
end;
begin
  randomize;
  readln(n,m);
  for i:=1 to n do
  readln(l[i],r[i]);
  for i:=1 to n-1 do
  begin
    a[i].left:=l[i+1]-r[i];
    a[i].right:=r[i+1]-l[i];
    a[i].id:=i;
  end;
  qsort1(1,n-1);
  for i:=1 to m do
  begin
    read(b[i].num);
    b[i].id:=i;
  end;
  qsort2(1,m);
  for i:=1 to m do
  fa[i]:=i;
  for i:=n-1 downto 1 do
  begin
    x:=0;
    for j:=20 downto 0 do
    if (x+1<<j<=m) and (b[x+1<<j].num<=a[i].right) then inc(x,1<<j);
    if f[x] then x:=get(x)-1;
    if (x<1) or (b[x].num<a[i].left) then
    begin
      writeln('No');
      halt;
    end;
    ans[a[i].id]:=b[x].id;
    f[x]:=true;
    if f[x-1] then fa[get(x)]:=get(x-1);
    if f[x+1] then fa[get(x+1)]:=get(x);
  end;
  writeln('Yes');
  for i:=1 to n-1 do
  write(ans[i],' ');
  writeln;
end.
