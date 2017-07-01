var i,n:longint;
    a:array[1..300]of longint;
    s:ansistring;
begin
  readln(n);
  for i:=1 to n do
  read(a[i]);
  s:=' ';
  i:=1;
  while i<=n do
  begin
    if (i=1) and (a[i]<>0) and (s[length(s)]<>'P') then
    begin
      s:=s+'P';
      dec(a[i]);
    end;
    if (i=1) and (a[i]<>0) and (s[length(s)]='P') then s:=s+'RL';
    if (i>1) and (a[i]<>0) and (s[length(s)]<>'P') then
    begin
      s:=s+'P';
      dec(a[i]);
    end;
    if (i>1) and (a[i]<>0) and (s[length(s)]='P') then s:=s+'LR';
    if (a[i]=0) and (i<n) then
    begin
      s:=s+'R';
      inc(i);
    end;
    if (a[i]=0) and (i=n) then inc(i);
  end;
  delete(s,1,1);
  writeln(s);
end.
