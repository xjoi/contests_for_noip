var m,b,s1,s2,ans,x,y:int64;
function max(a,b:int64):int64;
begin
  if a>b then exit(a) else exit(b);
end;
begin
  readln(m,b);
  ans:=0;
  x:=0;
  while x<=m*b do
  begin
     y:=b-trunc(x/m);
     if x mod m<>0 then dec(y);
     s1:=(x+1)*x div 2;
     s2:=s1*(y+1)+(y+1)*y*(x+1) div 2;
     ans:=max(ans,s2);
     inc(x);
  end;
  writeln(ans);
end.
