type rec=record
       num,id:longint;
     end;
var i,j,n:longint;
    a:array[0..300001]of rec;
function max(x,y:longint):longint;
begin
  if x>y then exit(x) else exit(y);
end;
procedure qsort1(l,r:longint);
  var i,j,mid:longint;
      p:rec;
begin
  i:=l;
  j:=r;
  mid:=a[random(r-l+1)+l].num;
  repeat
    while a[i].num<mid do inc(i);
    while a[j].num>mid do dec(j);
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
  var i,j,mid:longint;
      p:rec;
begin
  i:=l;
  j:=r;
  mid:=a[random(r-l+1)+l].id;
  repeat
    while a[i].id<mid do inc(i);
    while a[j].id>mid do dec(j);
    if i<=j then
    begin
      p:=a[i]; a[i]:=a[j]; a[j]:=p;
      inc(i); dec(j);
    end;
  until i>j;
  if i<r then qsort2(i,r);
  if l<j then qsort2(l,j);
end;
begin
  randomize;
  readln(n);
  for i:=1 to n do
  begin
    read(a[i].num);
    a[i].id:=i;
  end;
  qsort1(1,n);
  j:=0;
  for i:=1 to n do
  begin
    if a[i-1].num<>a[i].num then a[i].num:=max(a[i].num,j+1)
    else a[i].num:=max(a[i-1].num+1,j+1);
    if a[i].num>j then j:=a[i].num;
  end;
  qsort2(1,n);
  for i:=1 to n do
  write(a[i].num,' ');
  writeln;
end.
