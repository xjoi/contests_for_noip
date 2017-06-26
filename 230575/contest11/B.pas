var y:longint;
    x,m,b,t,ans:int64;
begin
  readln(m,b);
  for y:=0 to b do
  begin
    x:=m*b-m*y;
    t:=(x+1)*(y*(y+1) div 2)+(y+1)*(x*(x+1) div 2);
    if t>ans then ans:=t;
  end;
  writeln(ans);
end.
