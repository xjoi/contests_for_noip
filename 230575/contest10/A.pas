var i,n,x:longint;
    s:ansistring;
begin
  readln(n);
  readln(s);
  for i:=1 to n do
  if s[i]='0' then inc(x);
  writeln(abs(x*2-n));
end.
