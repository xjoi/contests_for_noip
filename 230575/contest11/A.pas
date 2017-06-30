var i,j,k,l,n:longint;
    a:array[0..51,0..51]of longint;
    bo:boolean;
begin
  readln(n);
  for i:=1 to n do
  begin
    for j:=1 to n do
    read(a[i,j]);
    readln;
  end;
  for i:=1 to n do
  for j:=1 to n do
  if a[i,j]<>1 then
  begin
    bo:=false;
    for k:=1 to n do
    begin
      for l:=1 to n do
      if a[i,k]+a[l,j]=a[i,j] then
      begin
        bo:=true;
        break;
      end;
      if bo then break;
    end;
    if not bo then
    begin
      writeln('No');
      halt;
    end;
  end;
  writeln('Yes');
end.
