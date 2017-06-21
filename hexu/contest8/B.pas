var
  n,i,j:longint;
  a:array[0..400]of longint;
begin
  readln(n);
  for i:=1 to n do read(a[i]);
  for i:=1 to n do
  begin
    while a[i]>0 do
    begin
      if i=1 then begin write('P'); dec(a[i]); if a[i]>0 then write('RL'); end
      else begin write('P'); dec(a[i]);if a[i]>0 then write('LR'); end;
    end;
    if i<>n then write('R');
  end;
end.
