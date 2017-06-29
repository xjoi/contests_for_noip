var
  n,i,j,step,top,p:longint;
  stack:array[0..300005]of longint;
  ch:char;
  s:string;
begin
  readln(n); step:=0;  p:=0;  top:=0;
  for i:=1 to 2*n do
  begin
    s:=''; read(ch); s:=s+ch; read(ch); s:=s+ch; read(ch); s:=s+ch;
    if s='add' then begin inc(top); read(stack[top]);  end
    else
    begin
      inc(p);
     // read(ch); s:=s+ch; read(ch); s:=s+ch; read(ch); s:=s+ch;
      if top=0 then begin readln; continue; end;
      if (stack[top]=p) then begin dec(top); readln; continue; end;
      if (stack[top]<>p) then begin inc(step); top:=0; end;
    end;
    readln;
  end;
  writeln(step);
end.
