   var
   n,i,c,x:longint;
   s:ansistring;
   begin
    readln(n);
    readln(s);
    for i:=1 to length(s) do
    if s[i]='0' then inc(x);
    (abs(2*x-n));
  *end.
 
