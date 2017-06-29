var
  n,i,j:longint;
  ok:boolean;
  a,b:array[0..1005]of longint;
begin
  readln(n);
  for i:=1 to n do read(a[i]);
  for i:=1 to n do b[i]:=i-1;
  for i:=1 to n+1 do
  begin
    ok:=true;
    for j:=1 to n do
    if j and 1=1 then
    begin inc(a[j]); if a[j]=-1 then a[j]:=n-1; if a[j]=n then a[j]:=0; end 
    else
    begin dec(a[j]); if a[j]=-1 then a[j]:=n-1; if a[j]=n then a[j]:=0; end;
    for j:=1 to n do
    if b[j]<>a[j] then begin ok:=false; break; end;
    if ok then begin writeln('Yes'); halt; end; 
  end;
  writeln('No');

end.
