var i,j,n:longint;
    a:array[1..1000]of longint;
    bo:boolean;
begin
  readln(n);
  for i:=1 to n do
  read(a[i]);
  for i:=1 to n do
  begin
    bo:=false;
    for j:=1 to n do
    begin
      if j mod 2=1 then
      begin
        inc(a[j]);
        if a[j]>=n then a[j]:=a[j]-n;
      end;
      if j mod 2=0 then
      begin
        dec(a[j]);
        if a[j]<0 then a[j]:=a[j]+n;
      end;
    end;
    for j:=1 to n do
    if a[j]<>j-1 then
    begin
      bo:=true;
      break;
    end;
    if bo=false then
    begin
      writeln('Yes');
      halt;
    end;
  end;
  writeln('No');
end.
