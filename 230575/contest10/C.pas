var i,j,n,num,sum,k:longint;
    a,m:array[0..100000]of longint;
begin
  readln(n,k);
  for i:=1 to k do
  begin
    read(m[i]);
    for j:=1 to m[i] do
    read(a[j]);
    if a[1]=1 then
    begin
      num:=1;
      for j:=2 to m[i] do
      if a[j]=a[1]+j-1 then inc(num);
    end;
    sum:=n-k-num+1;
  end;
  sum:=sum+n-num;
  writeln(sum);
end.
