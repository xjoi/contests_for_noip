var a,b,cnt:longint;
begin
  readln(a,b);
  cnt:=a;
  while a>=b do
  begin
    cnt:=cnt+a div b;
    a:=a div b+a mod b;
  end;
  writeln(cnt);
end.
