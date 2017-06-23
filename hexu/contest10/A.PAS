   var
   n,i,c,x:longint;
   s:ansistring;
   begin
    readln(n);
    readln(s);
    for i:=1 to length(s) do
    if s[i]='0' then inc(x);//统计0的个数
    writeln(abs(2*x-n));//输出答案
  *end.
 
