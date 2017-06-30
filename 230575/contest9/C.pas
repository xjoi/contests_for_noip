const inf=1000000007;
var a,b,i,j,ii,jj,k,n,x:longint;
    c:array[-1..100,-1..100]of int64;
    f:array[0..200,0..100,0..100]of int64;
begin
  readln(n,k);
  k:=k div 50;
  for i:=0 to n do
  for j:=0 to i do
  if c[i,j]<>j then c[i,j]:=(c[i-1,j-1]+c[i-1,j]) mod inf else c[i,j]:=1;
  for i:=1 to n do
  begin
    read(x);
    if x=50 then inc(a) else inc(b);
  end;
  f[0,a,b]:=1;
  for x:=0 to n<<2 do
  begin
    for i:=a downto 0 do
    for j:=b downto 0 do
    begin
      if f[x,i,j]=0 then continue;
      for ii:=0 to i do
      for jj:=0 to j do
      begin
        if (ii=0) and (jj=0) then continue;
        if ii+jj*2>k then continue;
        inc(f[x+1,a-i+ii,b-j+jj],f[x,i,j]*c[i,ii] mod inf*c[j,jj] mod inf);
        f[x+1,a-i+ii,b-j+jj]:=f[x+1,a-i+ii,b-j+jj] mod inf;
      end;
    end;
    if (x and 1=0) and (f[x+1,a,b]<>0) then
    begin
      writeln(x+1);
      writeln(f[x+1,a,b]);
      halt;
    end;
  end;
  writeln('-1');
  writeln('0');
end.
