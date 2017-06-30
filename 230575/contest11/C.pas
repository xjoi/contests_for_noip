var i,n,x,ans,top,sum:longint;
    s:string;
    a:array[0..300001]of longint;
begin
  readln(n);
  sum:=0;
  for i:=1 to 2*n do
  begin
    readln(s);
    if s='remove' then
    begin
      inc(sum);
      if top=0 then continue
      else if a[top]=sum then dec(top)
      else
      begin
        inc(ans);
        top:=0;
      end;
    end
    else
    begin
      delete(s,1,4);
      val(s,x);
      inc(top);
      a[top]:=x;
    end;
  end;
  writeln(ans);
end.
